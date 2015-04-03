#ifndef __QUANTKIT_ISERIES_H__
#define __QUANTKIT_ISERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QDateTime>

#include <QuantKit/BarData.h>
#include <QuantKit/IndexOption.h>

namespace QuantKit {

class Indicator;

class QUANTKIT_EXPORT ISeries
{
public:
	virtual QString name() const = 0;
	virtual QString description() const = 0;
	virtual int count() const = 0;
	virtual QList<Indicator> indicators() const = 0;
	virtual double first() const = 0;
	virtual double last() const = 0;
	virtual QDateTime firstDateTime() const = 0;
	virtual QDateTime lastDateTime() const = 0;
	virtual double item(int index) const = 0;
	virtual double item(int index, BarData barData) const = 0;
	virtual QDateTime getDateTime(int index) = 0;
	virtual int getIndex(const QDateTime& dateTime, IndexOption option = IndexOption::Null) = 0;
	virtual double getMax(const QDateTime& dateTime1, const QDateTime& dateTime2) = 0;
	virtual double getMax(int index1, int index2, BarData barData) = 0;
	virtual double getMin(const QDateTime& dateTime1, const QDateTime& dateTime2) = 0;
	virtual double getMin(int index1, int index2, BarData barData) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_ISERIES_H__
