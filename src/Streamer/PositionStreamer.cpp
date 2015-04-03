#include <QuantKit/Streamer/PositionStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class PositionStreamerPrivate : public ObjectStreamerPrivate
{
public:
	PositionStreamerPrivate();
	virtual ~PositionStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual PositionStreamerPrivate* clone() Q_DECL_OVERRIDE { return new PositionStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PositionStreamerPrivate::PositionStreamerPrivate()
{
		m_typeId = 25;
		m_type = typeof(Position);
		version = 1;
}

PositionStreamerPrivate::~PositionStreamerPrivate ()
{
}

QVariant PositionStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	Position position = new Position();
	if (version >= 1)
	{
		position.setPortfolioId() = reader.ReadInt32();
		position.setInstrumentId() = reader.ReadInt32();
		position.setQty() = reader.ReadDouble();
		position.setQtyBought() = reader.ReadDouble();
		position.setQtySold() = reader.ReadDouble();
	}
	return position;
}

void PositionStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Position position = (Position)obj;
	if (version >= 1)
	{
		writer.Write(position.portfolioId());
		writer.Write(position.instrumentId());
		writer.Write(position.qty());
		writer.Write(position.qtyBought());
		writer.Write(position.qtySold());
	}
}


// Pubic API 

PositionStreamer::PositionStreamer()
	: ObjectStreamer(*new PositionStreamerPrivate)
{
}

PositionStreamer::~PositionStreamer()
{
}


