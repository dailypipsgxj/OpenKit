#include <QuantKit/DataSeriesEventLogger.h>

#include <QuantKit/Framework.h>
#include "DataSeries_p.h"
#include "Event_p.h"
#include <QuantKit/IdArray.h>
#include "EventLogger_p.h"

namespace QuantKit {

class DataSeriesEventLoggerPrivate : public EventLoggerPrivate
{
public:
	DataSeries m_dataSeries;
	QDateTime m_dateTime;
	IdArray<bool> idArray_0;

public:
	explicit DataSeriesEventLoggerPrivate(const DataSeries& series);
	DataSeriesEventLoggerPrivate(const Framework& framework, const DataSeries& series);
	virtual ~DataSeriesEventLoggerPrivate();

public:
	void disable(unsigned char typeId) { idArray_0[(int)typeId] = true; }
	void enable(unsigned char typeId) { idArray_0[(int)typeId] = true; }
	virtual void onEvent(const Event& e) Q_DECL_OVERRIDE;
	virtual DataSeriesEventLoggerPrivate* clone() Q_DECL_OVERRIDE { return new DataSeriesEventLoggerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataSeriesEventLoggerPrivate::DataSeriesEventLoggerPrivate(const DataSeries& series)
	: m_dataSeries(series)
	, idArray_0(new IdArray<bool>(256))
{
}

DataSeriesEventLoggerPrivate::DataSeriesEventLoggerPrivate(const Framework& framework, const DataSeries& series)
	: EventLoggerPrivate (framework, "DataSeriesEventLogger")
	, m_dataSeries(series)
	, idArray_0(new IdArray<bool>(256))
{
}

DataSeriesEventLoggerPrivate::~DataSeriesEventLoggerPrivate ()
{
}

void DataSeriesEventLoggerPrivate::onEvent(const Event& e)
{
	if (idArray_0[(int)e.typeId()])
	{
		if (e.entryDate() < m_dateTime)
		{
			Console.WriteLine(string.Concat(new object[]
			{
				"!",
				e,
				" = ",
				e.entryDate(),
				" <> ",
				m_dateTime
			}));
			return;
		}
		m_dateTime = e.entryDate();
		m_dataSeries.Add((DataObject)e);
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(DataSeriesEventLogger)

DataSeriesEventLogger::DataSeriesEventLogger(const DataSeries& series)
	: EventLogger(*new DataSeriesEventLoggerPrivate(series))
{
}

DataSeriesEventLogger::DataSeriesEventLogger(const Framework& framework, const DataSeries& series)
	: EventLogger(*new DataSeriesEventLoggerPrivate(framework, series))
{
}

DataSeriesEventLogger::~DataSeriesEventLogger()
{
}

void DataSeriesEventLogger::disable(unsigned char typeId)
{
	Q_D(DataSeriesEventLogger);
	d->disable(typeId);
}

void DataSeriesEventLogger::enable(unsigned char typeId)
{
	Q_D(DataSeriesEventLogger);
	d->enable(typeId);
}


