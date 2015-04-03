#include <QuantKit/Event/Level2Snapshot.h>

#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class Level2SnapshotPrivate : public DataObjectPrivate
{
public:
	unsigned char byte_0;
	int int_0;
	Bid m_bids;
	Ask m_asks;

public:
	Level2SnapshotPrivate();
	Level2SnapshotPrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, const Bid& bids, const Ask& asks);
	virtual ~Level2SnapshotPrivate();

public:
	unsigned char getByte_0() const;
	void setByte_0(unsigned char value);

	int getInt_0() const;
	void setInt_0(int value);
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::Level2Snapshot;
	}

	Bid bids() const { return m_bids; }
	Ask asks() const { return m_asks; }
	virtual Level2SnapshotPrivate* clone() Q_DECL_OVERRIDE { return new Level2SnapshotPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

Level2SnapshotPrivate::Level2SnapshotPrivate()
{
}

Level2SnapshotPrivate::Level2SnapshotPrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, Bid bids, Ask asks)
	: DataObjectPrivate (dateTime)
	, byte_0(providerId)
	, int_0(instrumentId)
	, m_bids(bids)
	, m_asks(asks)
{
}

Level2SnapshotPrivate::~Level2SnapshotPrivate ()
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

QK_IMPLEMENTATION_PRIVATE(Level2Snapshot)

Level2Snapshot::Level2Snapshot()
	: DataObject(*new Level2SnapshotPrivate)
{
}

Level2Snapshot::Level2Snapshot(const QDateTime& dateTime, unsigned char providerId, int instrumentId, Bid bids, Ask asks)
	: DataObject(*new Level2SnapshotPrivate(dateTime, providerId, instrumentId, bids, asks))
{
}

Level2Snapshot::~Level2Snapshot()
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

Bid Level2Snapshot::bids() const
{
	Q_D(const Level2Snapshot);
	return d->bids();
}

Ask Level2Snapshot::asks() const
{
	Q_D(const Level2Snapshot);
	return d->asks();
}


