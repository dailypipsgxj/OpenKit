#include <QuantKit/Streamer/OnLoginStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class OnLoginStreamerPrivate : public ObjectStreamerPrivate
{
public:
	OnLoginStreamerPrivate();
	virtual ~OnLoginStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write((obj as Event).entryDate().Ticks);
	}

	virtual OnLoginStreamerPrivate* clone() Q_DECL_OVERRIDE { return new OnLoginStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnLoginStreamerPrivate::OnLoginStreamerPrivate()
{
		m_typeId = 215;
		m_type = typeof(OnLogin);
}

OnLoginStreamerPrivate::~OnLoginStreamerPrivate ()
{
}

QVariant OnLoginStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	return new OnLogin(dateTime);
}


// Pubic API 

OnLoginStreamer::OnLoginStreamer()
	: ObjectStreamer(*new OnLoginStreamerPrivate)
{
}

OnLoginStreamer::~OnLoginStreamer()
{
}


