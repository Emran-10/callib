#pragma once
#include <QString>
#include <QList>

namespace features::notes {

struct NoteItem {
    QString title;
    QString slug;
    QString type; // "heading" or "subheading"
    QString section;
    QString parentSlug;
    QString content;
    QString createdAt;
    QString modifiedAt;
};

class INoteManager {
public:
    virtual ~INoteManager() = default;
    virtual void addNote(const NoteItem &note) = 0;
    virtual void updateNote(const NoteItem &note) = 0;
    virtual void deleteNote(const QString &slug) = 0;
    virtual NoteItem getNote(const QString &slug) const = 0;
    virtual QList<NoteItem> getAllNotes() const = 0;
    virtual QList<NoteItem> getHeadingsBySection(const QString &section) const = 0;
};

} // namespace features::notes
