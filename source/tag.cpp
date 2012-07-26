#include <QStringList>
#include "tag.h"



Tag::Tag(QString text, QString type, int count) : m_text(text), m_type(type), m_count(count)
{
    if (text.endsWith("(artist)") && type == "unknown")
    { m_type = "artist"; }
}
Tag::~Tag()
{ }

QString Tag::stylished(QStringList favs)
{
    if (favs.contains(m_text))
    { return "<span style=\"color:pink\">"+m_text+"</span>"; }
    return m_text;
}

void Tag::setText(QString text)	{ m_text = text;	}
void Tag::setType(QString type)	{ m_type = type;	}
void Tag::setCount(int count)	{ m_count = count;	}

QString	Tag::text()		{ return m_text;	}
QString	Tag::type()		{ return m_type;	}
int		Tag::count()	{ return m_count;	}

bool sortByFrequency(Tag s1, Tag s2)
{ return s1.count() > s2.count(); }
