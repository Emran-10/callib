#include "heading_search.h"
#include <QDebug>

namespace features::heading_search {

QStringList HeadingSearch::searchHeadings(const QString &document, const QString &query) {
    qDebug() << "[HeadingSearch] Searching for:" << query;
    return QStringList();
}

} // namespace features::heading_search
