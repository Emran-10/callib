#include "main_window.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QInputDialog>
#include <QDebug>

namespace features::ui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalLib - Document Manager");
    setGeometry(100, 100, 1000, 800);
    setStyleSheet("background-color: #2b2b2b; color: #ffffff; font-family: Ubuntu; font-size: 10pt;");

    // Get service references
    m_subjectManager = core::ServiceLocator::get<core::interfaces::ISubjectManager>();
    m_imageCapturer = core::ServiceLocator::get<core::interfaces::IImageCapturer>();
    m_tocGenerator = core::ServiceLocator::get<core::interfaces::ITocGenerator>();
    m_settingsManager = core::ServiceLocator::get<core::interfaces::ISettingsManager>();

    setupUI();
    connectSignals();
    loadSubjects();
    qDebug() << "[UI] Main Window fully initialized";
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUI() {
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(15, 15, 15, 15);

    // Title
    auto *titleLabel = new QLabel("অবুঝা: বক | লক্ষ্য: নিবর্চিত নয়");
    titleLabel->setStyleSheet("font-size: 14pt; font-weight: bold; color: #4CAF50;");
    mainLayout->addWidget(titleLabel);

    // Subject Selection Section
    createSubjectSection();
    mainLayout->addWidget(m_subjectCombo->parentWidget());

    // Capture Configuration Section
    createCaptureConfigSection();
    mainLayout->addWidget(m_captureFormatCombo->parentWidget()->parentWidget());

    // Image Capture Section
    createImageCaptureSection();
    mainLayout->addWidget(m_btnAddImage->parentWidget());

    // Heading Control Section
    createHeadingControlSection();
    mainLayout->addWidget(m_headingInput->parentWidget()->parentWidget());

    // Control Buttons Section
    createControlButtonsSection();
    mainLayout->addWidget(m_btnStart->parentWidget());

    // Status Area
    m_statusArea = new QTextEdit();
    m_statusArea->setReadOnly(true);
    m_statusArea->setMaximumHeight(150);
    m_statusArea->setStyleSheet("background-color: #1e1e1e; color: #00ff00; border: 1px solid #444;");
    m_statusArea->setText("[System] CalLib initialized\n[System] Ready to capture documents");
    mainLayout->addWidget(m_statusArea);

    mainLayout->addStretch();
    setCentralWidget(centralWidget);
}

void MainWindow::createSubjectSection() {
    auto *groupBox = new QGroupBox("বিষয় নির্বাচন (Subject Selection):");
    groupBox->setStyleSheet("QGroupBox { color: #ffffff; border: 1px solid #444; border-radius: 5px; margin-top: 10px; padding-top: 10px; }");
    auto *layout = new QHBoxLayout(groupBox);

    m_subjectCombo = new QComboBox();
    m_subjectCombo->setStyleSheet("background-color: #333; color: #ffffff; border: 1px solid #555; padding: 5px; border-radius: 3px;");

    m_btnNewSubject = new QPushButton("বিষয় পরিবর্ত");
    m_btnNewSubject->setStyleSheet("background-color: #9C27B0; color: white; border: none; padding: 8px 15px; border-radius: 4px; font-weight: bold;");

    m_btnSelectSubject = new QPushButton("নতুন বিষয়");
    m_btnSelectSubject->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 8px 15px; border-radius: 4px; font-weight: bold;");

    auto *btnEditSubject = new QPushButton("নতুন ফোকাস");
    btnEditSubject->setStyleSheet("background-color: #FF9800; color: white; border: none; padding: 8px 15px; border-radius: 4px; font-weight: bold;");

    auto *btnOtherSubject = new QPushButton("নোট খুলুন");
    btnOtherSubject->setStyleSheet("background-color: #2196F3; color: white; border: none; padding: 8px 15px; border-radius: 4px; font-weight: bold;");

    layout->addWidget(m_subjectCombo);
    layout->addWidget(m_btnNewSubject);
    layout->addWidget(m_btnSelectSubject);
    layout->addWidget(btnEditSubject);
    layout->addWidget(btnOtherSubject);

    groupBox->setLayout(layout);
}

void MainWindow::createCaptureConfigSection() {
    auto *groupBox = new QGroupBox("ক্যাপচার ও ইনপুট কনফিগারেশন (Capture Configuration):");
    groupBox->setStyleSheet("QGroupBox { color: #ffffff; border: 1px solid #444; border-radius: 5px; margin-top: 10px; padding-top: 10px; }");
    auto *mainLayout = new QVBoxLayout(groupBox);

    // Format and Hotkey Row
    auto *formatLayout = new QHBoxLayout();

    auto *formatLabel = new QLabel("ফরম্যাট:");
    formatLabel->setStyleSheet("color: #4CAF50; font-weight: bold;");
    m_captureFormatCombo = new QComboBox();
    m_captureFormatCombo->addItems({"পুলেট পয়েন্ট (Point)", "রেকট্যাঙ্গেল (Rectangle)", "উইন্ডো (Window)"});
    m_captureFormatCombo->setStyleSheet("background-color: #333; color: #ffffff; border: 1px solid #555; padding: 5px; border-radius: 3px; min-width: 200px;");

    auto *hotkeyLabel = new QLabel("মোড: কপি মোড (Ctrl+C)");
    hotkeyLabel->setStyleSheet("color: #4CAF50; font-weight: bold;");
    m_hotkeyInput = new QLineEdit();
    m_hotkeyInput->setText("Ctrl+C");
    m_hotkeyInput->setReadOnly(true);
    m_hotkeyInput->setStyleSheet("background-color: #333; color: #ffffff; border: 1px solid #555; padding: 5px; border-radius: 3px; min-width: 150px;");

    formatLayout->addWidget(formatLabel);
    formatLayout->addWidget(m_captureFormatCombo);
    formatLayout->addWidget(hotkeyLabel);
    formatLayout->addWidget(m_hotkeyInput);
    formatLayout->addStretch();
    mainLayout->addLayout(formatLayout);

    // Section Row
    auto *sectionLayout = new QHBoxLayout();

    auto *sectionLabel = new QLabel("বিভাগ (Section):");
    sectionLabel->setStyleSheet("color: #4CAF50; font-weight: bold;");
    m_sectionCombo = new QComboBox();
    m_sectionCombo->addItems({"অন্যান্য (Others)", "ভূমিকা (Introduction)", "মূল বিষয়বস্তু (Main Content)", "উপসংহার (Conclusion)"});
    m_sectionCombo->setStyleSheet("background-color: #333; color: #ffffff; border: 1px solid #555; padding: 5px; border-radius: 3px; min-width: 200px;");

    m_btnAddSection = new QPushButton("নতুন বিভাগ");
    m_btnAddSection->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 8px 15px; border-radius: 4px; font-weight: bold;");

    sectionLayout->addWidget(sectionLabel);
    sectionLayout->addWidget(m_sectionCombo);
    sectionLayout->addWidget(m_btnAddSection);
    sectionLayout->addStretch();
    mainLayout->addLayout(sectionLayout);

    groupBox->setLayout(mainLayout);
}

void MainWindow::createImageCaptureSection() {
    auto *groupBox = new QGroupBox();
    auto *layout = new QHBoxLayout(groupBox);

    m_btnAddImage = new QPushButton("ছবি যোগ করুন (Add Image)");
    m_btnAddImage->setStyleSheet("background-color: #2196F3; color: white; border: none; padding: 15px; border-radius: 4px; font-weight: bold; font-size: 12pt;");
    m_btnAddImage->setMinimumHeight(50);

    layout->addWidget(m_btnAddImage);
    groupBox->setLayout(layout);
}

void MainWindow::createHeadingControlSection() {
    auto *groupBox = new QGroupBox("টার্গেট শিরোনাম নিয়ন্ত্রণ (Target Heading Control):");
    groupBox->setStyleSheet("QGroupBox { color: #ffffff; border: 1px solid #444; border-radius: 5px; margin-top: 10px; padding-top: 10px; }");
    auto *mainLayout = new QVBoxLayout(groupBox);

    // Heading Input
    auto *headingLabel = new QLabel("শিরোনাম (Heading):");
    headingLabel->setStyleSheet("color: #4CAF50; font-weight: bold;");
    m_headingInput = new QLineEdit();
    m_headingInput->setPlaceholderText("(নতুন করে যোগ করুন / Append to End)");
    m_headingInput->setStyleSheet("background-color: #333; color: #ffffff; border: 1px solid #555; padding: 8px; border-radius: 3px;");

    mainLayout->addWidget(headingLabel);
    mainLayout->addWidget(m_headingInput);

    // Heading Buttons
    auto *buttonLayout = new QHBoxLayout();

    m_btnAppendHeading = new QPushButton("যোগ করুন");
    m_btnAppendHeading->setStyleSheet("background-color: #FF9800; color: white; border: none; padding: 10px 20px; border-radius: 4px; font-weight: bold;");

    m_btnInsertHeading = new QPushButton("সন্নিবেশ করুন");
    m_btnInsertHeading->setStyleSheet("background-color: #9C27B0; color: white; border: none; padding: 10px 20px; border-radius: 4px; font-weight: bold;");

    m_btnUpdateHeading = new QPushButton("আপডেট করুন");
    m_btnUpdateHeading->setStyleSheet("background-color: #2196F3; color: white; border: none; padding: 10px 20px; border-radius: 4px; font-weight: bold;");

    m_btnDeleteHeading = new QPushButton("মুছে ফেলুন");
    m_btnDeleteHeading->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 10px 20px; border-radius: 4px; font-weight: bold;");

    buttonLayout->addWidget(m_btnAppendHeading);
    buttonLayout->addWidget(m_btnInsertHeading);
    buttonLayout->addWidget(m_btnUpdateHeading);
    buttonLayout->addWidget(m_btnDeleteHeading);
    buttonLayout->addStretch();

    mainLayout->addLayout(buttonLayout);
    groupBox->setLayout(mainLayout);
}

void MainWindow::createControlButtonsSection() {
    auto *groupBox = new QGroupBox();
    auto *layout = new QHBoxLayout(groupBox);

    m_btnStart = new QPushButton("শুরু (Start)");
    m_btnStart->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 12px 30px; border-radius: 4px; font-weight: bold; font-size: 11pt;");
    m_btnStart->setMinimumHeight(40);

    m_btnStop = new QPushButton("থামুন (Stop)");
    m_btnStop->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 12px 30px; border-radius: 4px; font-weight: bold; font-size: 11pt;");
    m_btnStop->setMinimumHeight(40);
    m_btnStop->setEnabled(false);

    m_btnExit = new QPushButton("বেরিয়ে যান");
    m_btnExit->setStyleSheet("background-color: #757575; color: white; border: none; padding: 12px 30px; border-radius: 4px; font-weight: bold; font-size: 11pt;");
    m_btnExit->setMinimumHeight(40);

    layout->addWidget(m_btnStart);
    layout->addWidget(m_btnStop);
    layout->addStretch();
    layout->addWidget(m_btnExit);

    groupBox->setLayout(layout);
}

void MainWindow::connectSignals() {
    connect(m_btnNewSubject, &QPushButton::clicked, this, &MainWindow::onAddNewSubject);
    connect(m_btnSelectSubject, &QPushButton::clicked, this, &MainWindow::onSelectExistingSubject);
    connect(m_btnAddImage, &QPushButton::clicked, this, &MainWindow::onAddImage);
    connect(m_btnStart, &QPushButton::clicked, this, &MainWindow::onStartCapture);
    connect(m_btnStop, &QPushButton::clicked, this, &MainWindow::onStopCapture);
    connect(m_btnAppendHeading, &QPushButton::clicked, this, &MainWindow::onAppendHeading);
    connect(m_btnInsertHeading, &QPushButton::clicked, this, &MainWindow::onInsertHeading);
    connect(m_btnUpdateHeading, &QPushButton::clicked, this, &MainWindow::onUpdateHeading);
    connect(m_btnDeleteHeading, &QPushButton::clicked, this, &MainWindow::onDeleteHeading);
    connect(m_btnExit, &QPushButton::clicked, this, &QWidget::close);
}

void MainWindow::loadSubjects() {
    if (!m_subjectManager) return;
    auto subjects = m_subjectManager->getSubjects();
    for (const auto &subject : subjects) {
        m_subjectCombo->addItem(subject);
    }
}

void MainWindow::onAddNewSubject() {
    bool ok;
    QString subject = QInputDialog::getText(this, "নতুন বিষয় যোগ করুন", "বিষয়ের নাম:", QLineEdit::Normal, "", &ok);
    if (ok && !subject.isEmpty() && m_subjectManager) {
        m_subjectManager->addSubject(subject);
        m_subjectCombo->addItem(subject);
        m_statusArea->append("[Subject] Added new subject: " + subject);
        qDebug() << "[UI] Added subject:" << subject;
    }
}

void MainWindow::onSelectExistingSubject() {
    m_statusArea->append("[Selection] Subject selected: " + m_subjectCombo->currentText());
    qDebug() << "[UI] Selected subject:" << m_subjectCombo->currentText();
}

void MainWindow::onAddImage() {
    if (!m_imageCapturer) return;
    m_imageCapturer->captureRegion();
    QString imagePath = m_imageCapturer->getCapturedImagePath();
    m_statusArea->append("[Image] Image captured and added: " + imagePath);
    qDebug() << "[UI] Image added from:" << imagePath;
}

void MainWindow::onStartCapture() {
    m_isCapturing = true;
    m_btnStart->setEnabled(false);
    m_btnStop->setEnabled(true);
    m_statusArea->append("[Capture] Document capture STARTED");
    qDebug() << "[UI] Capture started";
}

void MainWindow::onStopCapture() {
    m_isCapturing = false;
    m_btnStart->setEnabled(true);
    m_btnStop->setEnabled(false);
    m_statusArea->append("[Capture] Document capture STOPPED");
    qDebug() << "[UI] Capture stopped";
}

void MainWindow::onAppendHeading() {
    QString heading = m_headingInput->text();
    if (!heading.isEmpty()) {
        if (m_tocGenerator) {
            m_tocGenerator->generateToc(heading);
        }
        m_statusArea->append("[Heading] Appended heading: " + heading);
        m_headingInput->clear();
        qDebug() << "[UI] Heading appended:" << heading;
    }
}

void MainWindow::onInsertHeading() {
    QString heading = m_headingInput->text();
    if (!heading.isEmpty()) {
        m_statusArea->append("[Heading] Inserted heading: " + heading);
        m_headingInput->clear();
        qDebug() << "[UI] Heading inserted:" << heading;
    }
}

void MainWindow::onUpdateHeading() {
    QString heading = m_headingInput->text();
    if (!heading.isEmpty()) {
        m_statusArea->append("[Heading] Updated heading: " + heading);
        m_headingInput->clear();
        qDebug() << "[UI] Heading updated:" << heading;
    }
}

void MainWindow::onDeleteHeading() {
    m_statusArea->append("[Heading] Heading deleted");
    qDebug() << "[UI] Heading deleted";
}

} // namespace features::ui
