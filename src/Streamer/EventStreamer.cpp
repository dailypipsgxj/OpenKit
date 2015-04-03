#include <QuantKit/Streamer/EventStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class EventStreamerPrivate : public ObjectStreamerPrivate
{
public:
	EventStreamerPrivate();
	virtual ~EventStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write((obj as Event).entryDate().Ticks);
	}

	virtual EventStreamerPrivate* clone() Q_DECL_OVERRIDE { return new EventStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

EventStreamerPrivate::EventStreamerPrivate()
{
		m_typeId = 0;
		m_type = typeof(Event);
}

EventStreamerPrivate::~EventStreamerPrivate ()
{
}

QVariant EventStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	return new Event(dateTime);
}


// Pubic API 

EventStreamer::EventStreamer()
	: ObjectStreamer(*new EventStreamerPrivate)
{
}

EventStreamer::~EventStreamer()
{
}


