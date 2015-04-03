#include <QuantKit/Event/News.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class NewsPrivate : public DataObjectPrivate
{
public:
	int int_0;
	int int_1;
	unsigned char byte_0;
	QString string_0;
	QString string_1;
	QString string_2;

public:
	NewsPrivate();
	NewsPrivate(const QDateTime& dateTime, int providerId, int instrumentId, unsigned char urgency, const QString& url, const QString& headline, const QString& text);
	virtual ~NewsPrivate();

public:
	int getInt_0() const;
	void setInt_0(int value);

	int getInt_1() const;
	void setInt_1(int value);

	unsigned char getByte_0() const;
	void setByte_0(unsigned char value);

	QString getString_0() const;
	void setString_0(QString value);

	QString getString_1() const;
	void setString_1(QString value);

	QString getString_2() const;
	void setString_2(QString value);
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::News; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "News"; }
	virtual NewsPrivate* clone() Q_DECL_OVERRIDE { return new NewsPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

NewsPrivate::NewsPrivate()
{
}

NewsPrivate::NewsPrivate(const QDateTime& dateTime, int providerId, int instrumentId, unsigned char urgency, const QString& url, const QString& headline, const QString& text)
	: DataObjectPrivate (dateTime)
	, int_0(providerId)
	, int_1(instrumentId)
	, byte_0(urgency)
	, string_0(url)
	, string_1(headline)
	, string_2(text)
{
}

NewsPrivate::~NewsPrivate ()
{
}

int getInt_0() const
{
	return 0;
}
void setInt_0(int value)
{
}

int getInt_1() const
{
	return 0;
}
void setInt_1(int value)
{
}

unsigned char getByte_0() const
{
	return 0;
}
void setByte_0(unsigned char value)
{
}

QString getString_0() const
{
	return null;
}
void setString_0(QString value)
{
}

QString getString_1() const
{
	return null;
}
void setString_1(QString value)
{
}

QString getString_2() const
{
	return null;
}
void setString_2(QString value)
{
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(News)

News::News()
	: DataObject(*new NewsPrivate)
{
}

News::News(const QDateTime& dateTime, int providerId, int instrumentId, unsigned char urgency, const QString& url, const QString& headline, const QString& text)
	: DataObject(*new NewsPrivate(dateTime, providerId, instrumentId, urgency, url, headline, text))
{
}

News::~News()
{
}

int int_0() const
{
	return d_ptr->
	setInt_0()
}

void setInt_0(int value)
{
	d_ptr->int_0(value);
}

int int_1() const
{
	return d_ptr->
	setInt_1()
}

void setInt_1(int value)
{
	d_ptr->int_1(value);
}

unsigned char byte_0() const
{
	return d_ptr->
	setByte_0()
}

void setByte_0(unsigned char value)
{
	d_ptr->byte_0(value);
}

QString string_0() const
{
	return d_ptr->
	setString_0()
}

void setString_0(QString value)
{
	d_ptr->string_0(value);
}

QString string_1() const
{
	return d_ptr->
	setString_1()
}

void setString_1(QString value)
{
	d_ptr->string_1(value);
}

QString string_2() const
{
	return d_ptr->
	setString_2()
}

void setString_2(QString value)
{
	d_ptr->string_2(value);
}


