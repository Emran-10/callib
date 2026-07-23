#pragma once
#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <memory>
#include "core/service_locator.h"
#include "core/interfaces/i_subject_manager.h"
#include "core/interfaces/i_image_capturer.h"
#include "core/interfaces/i_toc_generator.h"
#include "core/interfaces/i_settings_manager.h"

namespace features::ui {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddNewSubject();
    void onSelectExistingSubject();
    void onAddImage();
    void onStartCapture();
    void onStopCapture();
    void onAppendHeading();
    void onInsertHeading();
    void onUpdateHeading();
    void onDeleteHeading();

private:
    void setupUI();
    void connectSignals();
    void loadSubjects();
    void createSubjectSection();
    void createCaptureConfigSection();
    void createImageCaptureSection();
    void createHeadingControlSection();
    void createControlButtonsSection();

    // Subject Selection
    QComboBox *m_subjectCombo;
    QPushButton *m_btnNewSubject;
    QPushButton *m_btnSelectSubject;
    QLineEdit *m_newSubjectInput;

    // Capture Configuration
    QComboBox *m_captureFormatCombo;
    QComboBox *m_modifierCombo;
    QLineEdit *m_hotkeyInput;
    QComboBox *m_sectionCombo;
    QPushButton *m_btnAddSection;

    // Image Capture
    QPushButton *m_btnAddImage;
    QLabel *m_imageStatusLabel;

    // Heading Control
    QLineEdit *m_headingInput;
    QPushButton *m_btnAppendHeading;
    QPushButton *m_btnInsertHeading;
    QPushButton *m_btnUpdateHeading;
    QPushButton *m_btnDeleteHeading;

    // Control Buttons
    QPushButton *m_btnStart;
    QPushButton *m_btnStop;
    QPushButton *m_btnExit;

    // Status area
    QTextEdit *m_statusArea;

    // Service references
    std::shared_ptr<core::interfaces::ISubjectManager> m_subjectManager;
    std::shared_ptr<core::interfaces::IImageCapturer> m_imageCapturer;
    std::shared_ptr<core::interfaces::ITocGenerator> m_tocGenerator;
    std::shared_ptr<core::interfaces::ISettingsManager> m_settingsManager;

    bool m_isCapturing = false;
};

} // namespace features::ui
