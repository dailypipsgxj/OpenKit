#ifndef __QUANTKIT_DATASERIESEVENTLOGGER_H__
#define __QUANTKIT_DATASERIESEVENTLOGGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/EventLogger.h>

namespace QuantKit {

class DataSeriesEventLoggerPrivate;

class Framework;
class DataSeries;
class Event;
class IdArray;

class QUANTKIT_EXPORT DataSeriesEventLogger Q_DECL_FINAL : public EventLogger
{
public:
	explicit DataSeriesEventLogger(const DataSeries& series);
	DataSeriesEventLogger(const Framework& framework, const DataSeries& series);
	~DataSeriesEventLogger();

public:
	void disable(unsigned char typeId);
	void enable(unsigned char typeId);

private:
	QK_DECLARE_PRIVATE(DataSeriesEventLogger)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataSeriesEventLogger)

#endif // __QUANTKIT_DATASERIESEVENTLOGGER_H__
