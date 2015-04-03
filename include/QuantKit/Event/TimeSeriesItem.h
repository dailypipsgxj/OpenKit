#ifndef __QUANTKIT_TIMESERIESITEM_H__
#define __QUANTKIT_TIMESERIESITEM_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class TimeSeriesItemPrivate;


class QUANTKIT_EXPORT TimeSeriesItem Q_DECL_FINAL : public DataObject
{
public:
	TimeSeriesItem();
	TimeSeriesItem(const QDateTime& dateTime, double value);
	~TimeSeriesItem();

public:
	double value() const;

private:
	QK_DECLARE_PRIVATE(TimeSeriesItem)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TimeSeriesItem)

#endif // __QUANTKIT_TIMESERIESITEM_H__
