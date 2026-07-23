#pragma once
#include <QString>
#include <QList>
#include <QMap>
#include "i_note_manager.h"

namespace features::notes {

class NoteManager : public INoteManager {
public:
    NoteManager();
    ~NoteManager();

    void addNote(const NoteItem &note) override;
    void updateNote(const NoteItem &note) override;
    void deleteNote(const QString &slug) override;
    NoteItem getNote(const QString &slug) const override;
    QList<NoteItem> getAllNotes() const override;
    QList<NoteItem> getHeadingsBySection(const QString &section) const override;

private:
    QMap<QString, NoteItem> m_notes;
    QString generateSlug(const QString &title);
};

} // namespace features::notes
