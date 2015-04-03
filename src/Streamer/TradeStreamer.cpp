#include <QuantKit/Streamer/TradeStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class TradeStreamerPrivate : public ObjectStreamerPrivate
{
public:
	TradeStreamerPrivate();
	virtual ~TradeStreamerPrivate();

public:
	virtual unsigned char getVersion(const QVariant& obj) Q_DECL_OVERRIDE;
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual TradeStreamerPrivate* clone() Q_DECL_OVERRIDE { return new TradeStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TradeStreamerPrivate::TradeStreamerPrivate()
{
		m_typeId = 4;
		m_type = typeof(Trade);
}

TradeStreamerPrivate::~TradeStreamerPrivate ()
{
}

unsigned char TradeStreamerPrivate::getVersion(const QVariant& obj)
{
	Trade trade = (Trade)obj;
	if (trade.exchangeDateTime().Ticks != 0L)
	{
		return 1;
	}
	return 0;
}

QVariant TradeStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	if (version == 0)
	{
		return new Trade(new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
	}
	return new Trade(new DateTime(reader.ReadInt64()), new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
}

void TradeStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Trade trade = (Trade)obj;
	writer.Write(trade.entryDate().Ticks);
	if (trade.exchangeDateTime().Ticks != 0L)
	{
		writer.Write(trade.exchangeDateTime().Ticks);
	}
	writer.Write(trade.providerId());
	writer.Write(trade.instrumentId());
	writer.Write(trade.price());
	writer.Write(trade.size());
}


// Pubic API 

TradeStreamer::TradeStreamer()
	: ObjectStreamer(*new TradeStreamerPrivate)
{
}

TradeStreamer::~TradeStreamer()
{
}


