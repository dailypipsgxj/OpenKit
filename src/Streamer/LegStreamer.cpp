#include <QuantKit/Streamer/LegStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class LegStreamerPrivate : public ObjectStreamerPrivate
{
public:
	LegStreamerPrivate();
	virtual ~LegStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char streamer) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual LegStreamerPrivate* clone() Q_DECL_OVERRIDE { return new LegStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

LegStreamerPrivate::LegStreamerPrivate()
{
		m_typeId = 108;
		m_type = typeof(Leg);
}

LegStreamerPrivate::~LegStreamerPrivate ()
{
}

QVariant LegStreamerPrivate::read(const QByteArray& reader, unsigned char streamer)
{
	return new Leg
	{
		m_symbol = reader.ReadInt32(),
		m_weight = reader.ReadDouble()
	};
}

void LegStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Leg leg = (Leg)obj;
	writer.Write(leg.symbol());
	writer.Write(leg.weight());
}


// Pubic API 

LegStreamer::LegStreamer()
	: ObjectStreamer(*new LegStreamerPrivate)
{
}

LegStreamer::~LegStreamer()
{
}


