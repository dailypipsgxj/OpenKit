#include <QuantKit/Streamer/BarStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class BarStreamerPrivate : public ObjectStreamerPrivate
{
public:
	BarStreamerPrivate();
	virtual ~BarStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual BarStreamerPrivate* clone() Q_DECL_OVERRIDE { return new BarStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BarStreamerPrivate::BarStreamerPrivate()
{
		m_typeId = 6;
		m_type = typeof(Bar);
		version = 1;
}

BarStreamerPrivate::~BarStreamerPrivate ()
{
}

QVariant BarStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	Bar bar = new Bar();
	bar.setEntryDate() = new DateTime(reader.ReadInt64());
	bar.setOpenDateTime() = new DateTime(reader.ReadInt64());
	bar.setInstrumentId() = reader.ReadInt32();
	bar.setSize() = reader.ReadInt64();
	bar.setHigh() = reader.ReadDouble();
	bar.setLow() = reader.ReadDouble();
	bar.setOpen() = reader.ReadDouble();
	bar.setClose() = reader.ReadDouble();
	bar.setVolume() = reader.ReadInt64();
	bar.setOpenInt() = reader.ReadInt64();
	bar.setStatus() = (BarStatus)reader.ReadByte();
	if (version >= 1)
	{
		bar.setType() = (BarType)reader.ReadByte();
	}
	int num = reader.ReadInt32();
	if (num != 0)
	{
		bar.setItem() = new IdArray<double>(num);
		for (int i = 0; i < num; i++)
		{
			bar.item()[i] = reader.ReadDouble();
		}
	}
	return bar;
}

void BarStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Bar bar = (Bar)obj;
	writer.Write(bar.entryDate().Ticks);
	writer.Write(bar.openDateTime().Ticks);
	writer.Write(bar.instrumentId());
	writer.Write(bar.size());
	writer.Write(bar.high());
	writer.Write(bar.low());
	writer.Write(bar.open());
	writer.Write(bar.close());
	writer.Write(bar.volume());
	writer.Write(bar.openInt());
	writer.Write((byte)bar.status());
	if (version >= 1)
	{
		writer.Write((byte)bar.type());
	}
	if (bar.item() != null)
	{
		writer.Write(bar.item().Size);
		for (int i = 0; i < bar.item().Size; i++)
		{
			writer.Write(bar.item()[i]);
		}
		return;
	}
	writer.Write(0);
}


// Pubic API 

BarStreamer::BarStreamer()
	: ObjectStreamer(*new BarStreamerPrivate)
{
}

BarStreamer::~BarStreamer()
{
}


