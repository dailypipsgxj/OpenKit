#include <QuantKit/Streamer/BidStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class BidStreamerPrivate : public ObjectStreamerPrivate
{
public:
	BidStreamerPrivate();
	virtual ~BidStreamerPrivate();

public:
	virtual unsigned char getVersion(const QVariant& obj) Q_DECL_OVERRIDE;
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual BidStreamerPrivate* clone() Q_DECL_OVERRIDE { return new BidStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BidStreamerPrivate::BidStreamerPrivate()
{
		m_typeId = 2;
		m_type = typeof(Bid);
}

BidStreamerPrivate::~BidStreamerPrivate ()
{
}

unsigned char BidStreamerPrivate::getVersion(const QVariant& obj)
{
	Bid bid = (Bid)obj;
	if (bid.exchangeDateTime().Ticks != 0L)
	{
		return 1;
	}
	return 0;
}

QVariant BidStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	if (version == 0)
	{
		return new Bid(new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
	}
	return new Bid(new DateTime(reader.ReadInt64()), new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
}

void BidStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Bid bid = (Bid)obj;
	writer.Write(bid.entryDate().Ticks);
	if (bid.exchangeDateTime().Ticks != 0L)
	{
		writer.Write(bid.exchangeDateTime().Ticks);
	}
	writer.Write(bid.providerId());
	writer.Write(bid.instrumentId());
	writer.Write(bid.price());
	writer.Write(bid.size());
}


// Pubic API 

BidStreamer::BidStreamer()
	: ObjectStreamer(*new BidStreamerPrivate)
{
}

BidStreamer::~BidStreamer()
{
}


