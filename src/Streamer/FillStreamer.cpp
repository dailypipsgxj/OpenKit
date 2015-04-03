#include <QuantKit/Streamer/FillStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class FillStreamerPrivate : public ObjectStreamerPrivate
{
public:
	FillStreamerPrivate();
	virtual ~FillStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual FillStreamerPrivate* clone() Q_DECL_OVERRIDE { return new FillStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FillStreamerPrivate::FillStreamerPrivate()
{
		m_typeId = 10;
		m_type = typeof(Fill);
}

FillStreamerPrivate::~FillStreamerPrivate ()
{
}

QVariant FillStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new Fill
	{
		m_entryDate = new DateTime(reader.ReadInt64()),
		int_0 = reader.ReadInt32(),
		m_currencyId = reader.ReadByte(),
		m_side = (OrderSide)Enum.Parse(typeof(OrderSide), reader.ReadString()),
		m_entryQty = reader.ReadDouble(),
		m_entryPrice = reader.ReadDouble(),
		m_text = reader.ReadString()
	};
}

void FillStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Fill fill = obj as Fill;
	writer.Write(fill.entryDate().Ticks);
	writer.Write(fill.int_0());
	writer.Write(fill.currencyId());
	writer.Write(fill.side().ToString());
	writer.Write(fill.entryQty());
	writer.Write(fill.entryPrice());
	writer.Write(fill.text());
}


// Pubic API 

FillStreamer::FillStreamer()
	: ObjectStreamer(*new FillStreamerPrivate)
{
}

FillStreamer::~FillStreamer()
{
}


