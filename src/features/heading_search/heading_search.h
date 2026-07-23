#pragma once
#include <QString>
#include <QStringList>

namespace features::heading_search {

class HeadingSearch {
public:
    QStringList searchHeadings(const QString &document, const QString &query);
};

} // namespace features::heading_search
