#include <QuantKit/Streamer/TickStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class TickStreamerPrivate : public ObjectStreamerPrivate
{
public:
	TickStreamerPrivate();
	virtual ~TickStreamerPrivate();

public:
	virtual unsigned char getVersion(const QVariant& obj) Q_DECL_OVERRIDE;
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual TickStreamerPrivate* clone() Q_DECL_OVERRIDE { return new TickStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TickStreamerPrivate::TickStreamerPrivate()
{
		m_typeId = 1;
		m_type = typeof(Tick);
}

TickStreamerPrivate::~TickStreamerPrivate ()
{
}

unsigned char TickStreamerPrivate::getVersion(const QVariant& obj)
{
	Tick tick = (Tick)obj;
	if (tick.exchangeDateTime().Ticks != 0L)
	{
		return 1;
	}
	return 0;
}

QVariant TickStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	if (version == 0)
	{
		return new Tick(new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
	}
	return new Tick(new DateTime(reader.ReadInt64()), new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
}

void TickStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Tick tick = (Tick)obj;
	writer.Write(tick.entryDate().Ticks);
	if (tick.exchangeDateTime().Ticks != 0L)
	{
		writer.Write(tick.exchangeDateTime().Ticks);
	}
	writer.Write(tick.providerId());
	writer.Write(tick.instrumentId());
	writer.Write(tick.price());
	writer.Write(tick.size());
}


// Pubic API 

TickStreamer::TickStreamer()
	: ObjectStreamer(*new TickStreamerPrivate)
{
}

TickStreamer::~TickStreamer()
{
}


