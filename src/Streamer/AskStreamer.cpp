#include <QuantKit/Streamer/AskStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class AskStreamerPrivate : public ObjectStreamerPrivate
{
public:
	AskStreamerPrivate();
	virtual ~AskStreamerPrivate();

public:
	virtual unsigned char getVersion(const QVariant& obj) Q_DECL_OVERRIDE;
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual AskStreamerPrivate* clone() Q_DECL_OVERRIDE { return new AskStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AskStreamerPrivate::AskStreamerPrivate()
{
		m_typeId = 3;
		m_type = typeof(Ask);
}

AskStreamerPrivate::~AskStreamerPrivate ()
{
}

unsigned char AskStreamerPrivate::getVersion(const QVariant& obj)
{
	Ask ask = (Ask)obj;
	if (ask.exchangeDateTime().Ticks != 0L)
	{
		return 1;
	}
	return 0;
}

QVariant AskStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	if (version == 0)
	{
		return new Ask(new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
	}
	return new Ask(new DateTime(reader.ReadInt64()), new DateTime(reader.ReadInt64()), reader.ReadByte(), reader.ReadInt32(), reader.ReadDouble(), reader.ReadInt32());
}

void AskStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Ask ask = (Ask)obj;
	writer.Write(ask.entryDate().Ticks);
	if (ask.exchangeDateTime().Ticks != 0L)
	{
		writer.Write(ask.exchangeDateTime().Ticks);
	}
	writer.Write(ask.providerId());
	writer.Write(ask.instrumentId());
	writer.Write(ask.price());
	writer.Write(ask.size());
}


// Pubic API 

AskStreamer::AskStreamer()
	: ObjectStreamer(*new AskStreamerPrivate)
{
}

AskStreamer::~AskStreamer()
{
}


