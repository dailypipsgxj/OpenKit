#include <QuantKit/Streamer/DataSeriesStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class DataSeriesStreamerPrivate : public ObjectStreamerPrivate
{
public:
	DataSeriesStreamerPrivate();
	virtual ~DataSeriesStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual DataSeriesStreamerPrivate* clone() Q_DECL_OVERRIDE { return new DataSeriesStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataSeriesStreamerPrivate::DataSeriesStreamerPrivate()
{
		m_typeId = 101;
		m_type = typeof(DataSeries);
}

DataSeriesStreamerPrivate::~DataSeriesStreamerPrivate ()
{
}

QVariant DataSeriesStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	return new DataSeries
	{
		m_count = reader.ReadInt64(),
		int_0 = reader.ReadInt32(),
		long_3 = reader.ReadInt64(),
		m_dateTime2 = new DateTime(reader.ReadInt64()),
		m_dateTime1 = new DateTime(reader.ReadInt64()),
		long_1 = reader.ReadInt64(),
		long_2 = reader.ReadInt64(),
		m_name = reader.ReadString()
	};
}

void DataSeriesStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	DataSeries dataSeries = obj as DataSeries;
	writer.Write(dataSeries.count());
	writer.Write(dataSeries.int_0());
	writer.Write(dataSeries.long_3());
	writer.Write(dataSeries.dateTime2().Ticks);
	writer.Write(dataSeries.dateTime1().Ticks);
	writer.Write(dataSeries.long_1());
	writer.Write(dataSeries.long_2());
	writer.Write(dataSeries.name());
}


// Pubic API 

DataSeriesStreamer::DataSeriesStreamer()
	: ObjectStreamer(*new DataSeriesStreamerPrivate)
{
}

DataSeriesStreamer::~DataSeriesStreamer()
{
}


