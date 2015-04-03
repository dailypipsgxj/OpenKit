#include <QuantKit/Streamer/TimeSeriesItemStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class TimeSeriesItemStreamerPrivate : public ObjectStreamerPrivate
{
public:
	TimeSeriesItemStreamerPrivate();
	virtual ~TimeSeriesItemStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual TimeSeriesItemStreamerPrivate* clone() Q_DECL_OVERRIDE { return new TimeSeriesItemStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TimeSeriesItemStreamerPrivate::TimeSeriesItemStreamerPrivate()
{
		m_typeId = 11;
		m_type = typeof(TimeSeriesItem);
}

TimeSeriesItemStreamerPrivate::~TimeSeriesItemStreamerPrivate ()
{
}

QVariant TimeSeriesItemStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new TimeSeriesItem
	{
		m_entryDate = DateTime.FromBinary(reader.ReadInt64()),
		m_value = reader.ReadDouble()
	};
}

void TimeSeriesItemStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	TimeSeriesItem timeSeriesItem = (TimeSeriesItem)obj;
	writer.Write(timeSeriesItem.entryDate().ToBinary());
	writer.Write(timeSeriesItem.value());
}


// Pubic API 

TimeSeriesItemStreamer::TimeSeriesItemStreamer()
	: ObjectStreamer(*new TimeSeriesItemStreamerPrivate)
{
}

TimeSeriesItemStreamer::~TimeSeriesItemStreamer()
{
}


