#include <QuantKit/Streamer/OnProviderDisconnectedStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class OnProviderDisconnectedStreamerPrivate : public ObjectStreamerPrivate
{
public:
	OnProviderDisconnectedStreamerPrivate();
	virtual ~OnProviderDisconnectedStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual OnProviderDisconnectedStreamerPrivate* clone() Q_DECL_OVERRIDE { return new OnProviderDisconnectedStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnProviderDisconnectedStreamerPrivate::OnProviderDisconnectedStreamerPrivate()
{
		m_typeId = 226;
		m_type = typeof(OnProviderDisconnected);
}

OnProviderDisconnectedStreamerPrivate::~OnProviderDisconnectedStreamerPrivate ()
{
}

QVariant OnProviderDisconnectedStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	byte providerId = reader.ReadByte();
	return new OnProviderDisconnected(dateTime, providerId);
}

void OnProviderDisconnectedStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	OnProviderDisconnected onProviderDisconnected = (OnProviderDisconnected)obj;
	writer.Write(onProviderDisconnected.entryDate().Ticks);
	writer.Write(onProviderDisconnected.providerId());
}


// Pubic API 

OnProviderDisconnectedStreamer::OnProviderDisconnectedStreamer()
	: ObjectStreamer(*new OnProviderDisconnectedStreamerPrivate)
{
}

OnProviderDisconnectedStreamer::~OnProviderDisconnectedStreamer()
{
}


