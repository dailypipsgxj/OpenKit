#include <QuantKit/Streamer/DateTimeStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class DateTimeStreamerPrivate : public ObjectStreamerPrivate
{
public:
	DateTimeStreamerPrivate();
	virtual ~DateTimeStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE
	{
		return new DateTime(reader.ReadInt64());
	}

	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write(((DateTime)obj).Ticks);
	}

	virtual DateTimeStreamerPrivate* clone() Q_DECL_OVERRIDE { return new DateTimeStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DateTimeStreamerPrivate::DateTimeStreamerPrivate()
{
		m_typeId = 153;
		m_type = typeof(DateTime);
}

DateTimeStreamerPrivate::~DateTimeStreamerPrivate ()
{
}


// Pubic API 

DateTimeStreamer::DateTimeStreamer()
	: ObjectStreamer(*new DateTimeStreamerPrivate)
{
}

DateTimeStreamer::~DateTimeStreamer()
{
}


