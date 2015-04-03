#include <QuantKit/Event/ProviderError.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class ProviderErrorPrivate : public DataObjectPrivate
{
public:
	ProviderErrorType m_type;
	unsigned char m_providerId;
	int m_id;
	int m_code;
	QString m_text;

public:
	ProviderErrorPrivate();
	ProviderErrorPrivate(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, const QString& text);
	ProviderErrorPrivate(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, int id, int code, const QString& text);
	virtual ~ProviderErrorPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::ProviderError;
	}

	ProviderErrorType type() const { return m_type; }
	void setType(ProviderErrorType value) { m_type = value; }
	unsigned char providerId() const { return m_providerId; }
	void setProviderId(unsigned char value) { m_providerId = value; }
	int id() const { return m_id; }
	void setId(int value) { m_id = value; }
	int code() const { return m_code; }
	void setCode(int value) { m_code = value; }
	QString text() const { return m_text; }
	void setText(const QString& value) { m_text = value; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "ProviderError"; }
	virtual ProviderErrorPrivate* clone() Q_DECL_OVERRIDE { return new ProviderErrorPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderErrorPrivate::ProviderErrorPrivate()
{
}

ProviderErrorPrivate::ProviderErrorPrivate(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, const QString& text)
{
		Class81.pxBq5K7zXLUvm();
		.ctor(dateTime, type, providerId, -1, -1, text);
}

ProviderErrorPrivate::ProviderErrorPrivate(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, int id, int code, const QString& text)
	: DataObjectPrivate (dateTime)
	, m_type(type)
	, m_providerId(providerId)
	, m_id(id)
	, m_code(code)
	, m_text(text)
{
}

ProviderErrorPrivate::~ProviderErrorPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(ProviderError)

ProviderError::ProviderError()
	: DataObject(*new ProviderErrorPrivate)
{
}

ProviderError::ProviderError(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, const QString& text)
	: DataObject(*new ProviderErrorPrivate(dateTime, type, providerId, text))
{
}

ProviderError::ProviderError(const QDateTime& dateTime, ProviderErrorType type, unsigned char providerId, int id, int code, const QString& text)
	: DataObject(*new ProviderErrorPrivate(dateTime, type, providerId, id, code, text))
{
}

ProviderError::~ProviderError()
{
}

ProviderErrorType ProviderError::type() const
{
	Q_D(const ProviderError);
	return d->type();
}

void ProviderError::setType(ProviderErrorType value)
{
	Q_D(ProviderError);
	d->setType(value);
}

unsigned char ProviderError::providerId() const
{
	Q_D(const ProviderError);
	return d->providerId();
}

void ProviderError::setProviderId(unsigned char value)
{
	Q_D(ProviderError);
	d->setProviderId(value);
}

int ProviderError::id() const
{
	Q_D(const ProviderError);
	return d->id();
}

void ProviderError::setId(int value)
{
	Q_D(ProviderError);
	d->setId(value);
}

int ProviderError::code() const
{
	Q_D(const ProviderError);
	return d->code();
}

void ProviderError::setCode(int value)
{
	Q_D(ProviderError);
	d->setCode(value);
}

QString ProviderError::text() const
{
	Q_D(const ProviderError);
	return d->text();
}

void ProviderError::setText(const QString& value)
{
	Q_D(ProviderError);
	d->setText(value);
}


