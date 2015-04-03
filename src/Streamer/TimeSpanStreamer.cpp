#include <QuantKit/Streamer/TimeSpanStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class TimeSpanStreamerPrivate : public ObjectStreamerPrivate
{
public:
	TimeSpanStreamerPrivate();
	virtual ~TimeSpanStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE
	{
		return new TimeSpan(reader.ReadInt64());
	}

	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write(((TimeSpan)obj).Ticks);
	}

	virtual TimeSpanStreamerPrivate* clone() Q_DECL_OVERRIDE { return new TimeSpanStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TimeSpanStreamerPrivate::TimeSpanStreamerPrivate()
{
		m_typeId = 253;
		m_type = typeof(TimeSpan);
}

TimeSpanStreamerPrivate::~TimeSpanStreamerPrivate ()
{
}


// Pubic API 

TimeSpanStreamer::TimeSpanStreamer()
	: ObjectStreamer(*new TimeSpanStreamerPrivate)
{
}

TimeSpanStreamer::~TimeSpanStreamer()
{
}


