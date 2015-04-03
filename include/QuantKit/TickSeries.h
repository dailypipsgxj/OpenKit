#ifndef __QUANTKIT_TICKSERIES_H__
#define __QUANTKIT_TICKSERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/IDataSeries.h>
#include <QuantKit/SearchOption.h>
#include <QuantKit/IndexOption.h>
#include <QuantKit/BarType.h>

namespace QuantKit {

class TickSeriesPrivate;

class Tick;
class DataObject;
class BarSeries;

class QUANTKIT_EXPORT TickSeries : public IDataSeries
{
public:
	explicit TickSeries(const QString& name = "");
	~TickSeries();

	TickSeries(const TickSeries &other);
	TickSeries& operator=(const TickSeries &other);
	bool operator==(const TickSeries &other) const;
	inline bool operator!=(const TickSeries &other) const { return !(this->operator==(other));  }
public:
	QString name() const;
	QString description() const;
	int count() const;
	QDateTime firstDateTime() const;
	QDateTime lastDateTime() const;
	Tick item(int index) const;
	void add(const Tick& tick);
	void clear();
	BarSeries compress(BarType barType, long barSize);
	bool contains(const QDateTime& dateTime);
	int getIndex(const QDateTime& datetime, IndexOption option);
	Tick getMax();
	Tick getMax(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Tick getMin();
	Tick getMin(const QDateTime& dateTime1, const QDateTime& dateTime2);

private:
	QSharedDataPointer<TickSeriesPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const TickSeries& tickseries);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const TickSeries& tickseries);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TickSeries)

#endif // __QUANTKIT_TICKSERIES_H__
