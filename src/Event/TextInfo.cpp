#include <QuantKit/Event/TextInfo.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class TextInfoPrivate : public DataObjectPrivate
{
public:
	QString m_content;

public:
	TextInfoPrivate(const QDateTime& dateTime, const QString& content);
	TextInfoPrivate(const QDateTime& dateTime, const QVariant& data);
	virtual ~TextInfoPrivate();

public:
	QString content() const { return m_content; }
	void setContent(const QString& value) { m_content = value; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::TextInfo; }
	virtual TextInfoPrivate* clone() Q_DECL_OVERRIDE { return new TextInfoPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TextInfoPrivate::TextInfoPrivate(const QDateTime& dateTime, const QString& content)
	: DataObjectPrivate (dateTime)
	, m_content(content)
{
}

TextInfoPrivate::TextInfoPrivate(const QDateTime& dateTime, const QVariant& data)
{
		Class81.pxBq5K7zXLUvm();
		.ctor(dateTime, data.ToString());
}

TextInfoPrivate::~TextInfoPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(TextInfo)

TextInfo::TextInfo(const QDateTime& dateTime, const QString& content)
	: DataObject(*new TextInfoPrivate(dateTime, content))
{
}

TextInfo::TextInfo(const QDateTime& dateTime, const QVariant& data)
	: DataObject(*new TextInfoPrivate(dateTime, data))
{
}

TextInfo::~TextInfo()
{
}

QString TextInfo::content() const
{
	Q_D(const TextInfo);
	return d->content();
}

void TextInfo::setContent(const QString& value)
{
	Q_D(TextInfo);
	d->setContent(value);
}


