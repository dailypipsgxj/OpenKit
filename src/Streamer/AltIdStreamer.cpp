#include <QuantKit/Streamer/AltIdStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class AltIdStreamerPrivate : public ObjectStreamerPrivate
{
public:
	AltIdStreamerPrivate();
	virtual ~AltIdStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual AltIdStreamerPrivate* clone() Q_DECL_OVERRIDE { return new AltIdStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AltIdStreamerPrivate::AltIdStreamerPrivate()
{
		m_typeId = 107;
		m_type = typeof(AltId);
}

AltIdStreamerPrivate::~AltIdStreamerPrivate ()
{
}

QVariant AltIdStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new AltId
	{
		m_providerId = reader.ReadByte(),
		m_symbol = reader.ReadString(),
		m_exchange = reader.ReadString()
	};
}

void AltIdStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	AltId altId = (AltId)obj;
	writer.Write(altId.providerId());
	writer.Write(altId.symbol());
	writer.Write(altId.exchange());
}


// Pubic API 

AltIdStreamer::AltIdStreamer()
	: ObjectStreamer(*new AltIdStreamerPrivate)
{
}

AltIdStreamer::~AltIdStreamer()
{
}


