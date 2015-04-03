#include <QuantKit/Event/Fundamental.h>

#include <QuantKit/ObjectTable.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class FundamentalPrivate : public DataObjectPrivate
{
public:
	int int_0;
	int int_1;
	ObjectTable m_item;
	Class50 m_item;

public:
	FundamentalPrivate();
	FundamentalPrivate(const QDateTime& dateTime, int providerId, int instrumentId);
	virtual ~FundamentalPrivate();

public:
	int getInt_0() const;
	void setInt_0(int value);

	int getInt_1() const;
	void setInt_1(int value);
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Fundamental; }
	QVariant item(unsigned char index) const { return m_item[(int)index]; }
	void setItem(unsigned char index, const QVariant& value) { m_item[(int)index] = value; }
	QVariant item(const QString& name) const
	{
		return m_item[(int)Fundamental.item()[name]];
	}

	void setItem(const QString& name, const QVariant& value)
	{
		this[Fundamental.item()[name]] = value;
	}

	void addField(const QString& name, unsigned char index)
	{
		Fundamental.item().Add(name, index);
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "Fundamental"; }
	virtual FundamentalPrivate* clone() Q_DECL_OVERRIDE { return new FundamentalPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FundamentalPrivate::FundamentalPrivate()
	: m_item(new ObjectTable())
{
}

FundamentalPrivate::FundamentalPrivate(const QDateTime& dateTime, int providerId, int instrumentId)
	: DataObjectPrivate (dateTime)
	, int_0(providerId)
	, int_1(instrumentId)
	, m_item(new ObjectTable())
{
}

FundamentalPrivate::~FundamentalPrivate ()
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

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Fundamental)

Fundamental::Fundamental()
	: DataObject(*new FundamentalPrivate)
{
}

Fundamental::Fundamental(const QDateTime& dateTime, int providerId, int instrumentId)
	: DataObject(*new FundamentalPrivate(dateTime, providerId, instrumentId))
{
}

Fundamental::~Fundamental()
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

QVariant Fundamental::item(unsigned char index) const
{
	Q_D(const Fundamental);
	return d->item(index);
}

void Fundamental::setItem(unsigned char index, const QVariant& value)
{
	Q_D(Fundamental);
	d->setItem(index, value);
}

QVariant Fundamental::item(const QString& name) const
{
	Q_D(const Fundamental);
	return d->item(name);
}

void Fundamental::setItem(const QString& name, const QVariant& value)
{
	Q_D(Fundamental);
	d->setItem(name, value);
}

void Fundamental::addField(const QString& name, unsigned char index)
{
	Q_D(Fundamental);
	d->addField(name, index);
}


