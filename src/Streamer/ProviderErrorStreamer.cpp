#include <QuantKit/Streamer/ProviderErrorStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ProviderErrorStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ProviderErrorStreamerPrivate();
	virtual ~ProviderErrorStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual ProviderErrorStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ProviderErrorStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderErrorStreamerPrivate::ProviderErrorStreamerPrivate()
{
		m_typeId = 21;
		m_type = typeof(ProviderError);
}

ProviderErrorStreamerPrivate::~ProviderErrorStreamerPrivate ()
{
}

QVariant ProviderErrorStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new ProviderError
	{
		m_entryDate = DateTime.FromBinary(reader.ReadInt64()),
		m_type = (ProviderErrorType)reader.ReadByte(),
		m_providerId = reader.ReadByte(),
		m_id = reader.ReadInt32(),
		m_code = reader.ReadInt32(),
		m_text = reader.ReadString()
	};
}

void ProviderErrorStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	ProviderError providerError = (ProviderError)obj;
	writer.Write(providerError.entryDate().ToBinary());
	writer.Write((byte)providerError.type());
	writer.Write(providerError.providerId());
	writer.Write(providerError.id());
	writer.Write(providerError.code());
	writer.Write(providerError.text());
}


// Pubic API 

ProviderErrorStreamer::ProviderErrorStreamer()
	: ObjectStreamer(*new ProviderErrorStreamerPrivate)
{
}

ProviderErrorStreamer::~ProviderErrorStreamer()
{
}


