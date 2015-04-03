#include <QuantKit/Streamer/OnHeartbeatStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class OnHeartbeatStreamerPrivate : public ObjectStreamerPrivate
{
public:
	OnHeartbeatStreamerPrivate();
	virtual ~OnHeartbeatStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write((obj as OnHeartbeat).entryDate().ToBinary());
	}

	virtual OnHeartbeatStreamerPrivate* clone() Q_DECL_OVERRIDE { return new OnHeartbeatStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnHeartbeatStreamerPrivate::OnHeartbeatStreamerPrivate()
{
		m_typeId = 220;
		m_type = typeof(OnHeartbeat);
}

OnHeartbeatStreamerPrivate::~OnHeartbeatStreamerPrivate ()
{
}

QVariant OnHeartbeatStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = DateTime.FromBinary(reader.ReadInt64());
	return new OnHeartbeat(dateTime);
}


// Pubic API 

OnHeartbeatStreamer::OnHeartbeatStreamer()
	: ObjectStreamer(*new OnHeartbeatStreamerPrivate)
{
}

OnHeartbeatStreamer::~OnHeartbeatStreamer()
{
}


