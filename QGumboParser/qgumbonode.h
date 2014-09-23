#ifndef QGUMBONODE_H
#define QGUMBONODE_H

#include <vector>
#include <functional>
#include "gumbo-parser/src/gumbo.h"
#include "HtmlTag.h"

class QString;
class QGumboNode;
class QGumboAttribute;
class tst_QGumboDocument;
class QStringList;

typedef std::vector<QGumboNode> 		QGumboNodes;
typedef std::vector<QGumboAttribute> 	QGumboAttributes;

class QGumboNode
{
public:
    QGumboNode(const QGumboNode&) = default;
    QGumboNode(QGumboNode&&) noexcept = default;
    QGumboNode& operator=(const QGumboNode&) = default;

    QString tagName() const;
    QString id() const;
    QStringList classList() const;

    QGumboNodes getElementById(const QString&) const;
    QGumboNodes getElementsByTagName(HtmlTag) const;

    QGumboNodes getElementsByClassName(const QString&) const;

    bool isElement() const;
    bool hasAttribute(const QString&) const;

    QString innerText() const;
    QString getAttribute(const QString&) const;

    QGumboAttributes allAttributes() const;

    void forEach(std::function<void(const QGumboNode&)>) const;

private:
    QGumboNode();
    QGumboNode(GumboNode* node);


    GumboNode* findId(const char* id, GumboNode* node) const;

    friend class tst_QGumboDocument;
private:
    GumboNode* ptr_;
};

#endif // QGUMBONODE_H
