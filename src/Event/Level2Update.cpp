#include <QuantKit/Event/Level2Update.h>

#include <QuantKit/Event/Level2.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class Level2UpdatePrivate : public DataObjectPrivate
{
public:
	unsigned char byte_0;
	int int_0;
	Level2 m_entries;

public:
	Level2UpdatePrivate();
	Level2UpdatePrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, const Level2& entries);
	virtual ~Level2UpdatePrivate();

public:
	unsigned char getByte_0() const;
	void setByte_0(unsigned char value);

	int getInt_0() const;
	void setInt_0(int value);
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::Level2Update;
	}

	Level2 entries() const { return m_entries; }
	virtual Level2UpdatePrivate* clone() Q_DECL_OVERRIDE { return new Level2UpdatePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Level2UpdatePrivate::Level2UpdatePrivate()
{
}

Level2UpdatePrivate::Level2UpdatePrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, Level2 entries)
	: DataObjectPrivate (dateTime)
	, byte_0(providerId)
	, int_0(instrumentId)
	, m_entries(entries)
{
}

Level2UpdatePrivate::~Level2UpdatePrivate ()
{
}

unsigned char getByte_0() const
{
	return 0;
}
void setByte_0(unsigned char value)
{
}

int getInt_0() const
{
	return 0;
}
void setInt_0(int value)
{
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Level2Update)

Level2Update::Level2Update()
	: DataObject(*new Level2UpdatePrivate)
{
}

Level2Update::Level2Update(const QDateTime& dateTime, unsigned char providerId, int instrumentId, Level2 entries)
	: DataObject(*new Level2UpdatePrivate(dateTime, providerId, instrumentId, entries))
{
}

Level2Update::~Level2Update()
{
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

int int_0() const
{
	return d_ptr->
	setInt_0()
}

void setInt_0(int value)
{
	d_ptr->int_0(value);
}

Level2 Level2Update::entries() const
{
	Q_D(const Level2Update);
	return d->entries();
}


