#include "note_manager.h"
#include <QDebug>
#include <QDateTime>
#include <QRegularExpression>

namespace features::notes {

NoteManager::NoteManager() {
    qDebug() << "[NoteManager] Initialized";
}

NoteManager::~NoteManager() = default;

string NoteManager::generateSlug(const QString &title) {
    QString slug = title.toLower();
    slug.replace(QRegularExpression("[^a-z0-9]+"), "-");
    slug.remove(QRegularExpression("^-+|-+$"));
    return slug;
}

void NoteManager::addNote(const NoteItem &note) {
    NoteItem newNote = note;
    if (newNote.slug.isEmpty()) {
        newNote.slug = generateSlug(newNote.title);
    }
    newNote.createdAt = QDateTime::currentDateTime().toString(Qt::ISODate);
    newNote.modifiedAt = newNote.createdAt;
    
    m_notes[newNote.slug] = newNote;
    qDebug() << "[NoteManager] Added note:" << newNote.slug << "-" << newNote.title;
}

void NoteManager::updateNote(const NoteItem &note) {
    if (m_notes.contains(note.slug)) {
        NoteItem updatedNote = note;
        updatedNote.modifiedAt = QDateTime::currentDateTime().toString(Qt::ISODate);
        m_notes[note.slug] = updatedNote;
        qDebug() << "[NoteManager] Updated note:" << note.slug;
    }
}

void NoteManager::deleteNote(const QString &slug) {
    m_notes.remove(slug);
    qDebug() << "[NoteManager] Deleted note:" << slug;
}

NoteItem NoteManager::getNote(const QString &slug) const {
    return m_notes.value(slug);
}

QList<NoteItem> NoteManager::getAllNotes() const {
    return m_notes.values();
}

QList<NoteItem> NoteManager::getHeadingsBySection(const QString &section) const {
    QList<NoteItem> result;
    for (const auto &note : m_notes.values()) {
        if (note.section == section && note.type == "heading") {
            result.append(note);
        }
    }
    return result;
}

} // namespace features::notes
