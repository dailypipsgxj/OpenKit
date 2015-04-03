#include <QuantKit/Streamer/OnProviderConnectedStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class OnProviderConnectedStreamerPrivate : public ObjectStreamerPrivate
{
public:
	OnProviderConnectedStreamerPrivate();
	virtual ~OnProviderConnectedStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual OnProviderConnectedStreamerPrivate* clone() Q_DECL_OVERRIDE { return new OnProviderConnectedStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnProviderConnectedStreamerPrivate::OnProviderConnectedStreamerPrivate()
{
		m_typeId = 225;
		m_type = typeof(OnProviderConnected);
}

OnProviderConnectedStreamerPrivate::~OnProviderConnectedStreamerPrivate ()
{
}

QVariant OnProviderConnectedStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	byte providerId = reader.ReadByte();
	return new OnProviderConnected(dateTime, providerId);
}

void OnProviderConnectedStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	OnProviderConnected onProviderConnected = (OnProviderConnected)obj;
	writer.Write(onProviderConnected.entryDate().Ticks);
	writer.Write(onProviderConnected.providerId());
}


// Pubic API 

OnProviderConnectedStreamer::OnProviderConnectedStreamer()
	: ObjectStreamer(*new OnProviderConnectedStreamerPrivate)
{
}

OnProviderConnectedStreamer::~OnProviderConnectedStreamer()
{
}


