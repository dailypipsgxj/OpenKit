#ifndef __QUANTKIT_BARSERIES_H__
#define __QUANTKIT_BARSERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/IDataSeries.h>
#include <QuantKit/ISeries.h>
#include <QuantKit/IndexOption.h>
#include <QuantKit/BarData.h>
#include <QuantKit/SearchOption.h>

namespace QuantKit {

class BarSeriesPrivate;

class Indicator;
class Bar;
class DataObject;

class QUANTKIT_EXPORT BarSeries : public IDataSeries , public ISeries
{
public:
	explicit BarSeries(int maxLength);
	BarSeries(const QString& name = "", const QString& description = "", int maxLength = -1);
	~BarSeries();

	BarSeries(const BarSeries &other);
	BarSeries& operator=(const BarSeries &other);
	bool operator==(const BarSeries &other) const;
	inline bool operator!=(const BarSeries &other) const { return !(this->operator==(other));  }
public:
	QString name() const;
	QString description() const;
	int count() const;
	int maxLength() const;
	void setMaxLength(int value);
	QList<Indicator> indicators() const;
	QDateTime firstDateTime() const;
	QDateTime lastDateTime() const;
	Bar first() const;
	Bar last() const;
	Bar item(int index) const;
	Bar item(const QDateTime& dateTime, IndexOption option = IndexOption::Null) const;
	double item(int index, BarData barData) const;
	void add(const Bar& bar);
	Bar ago(int n);
	void clear();
	BarSeries compress(long barSize);
	bool contains(const QDateTime& dateTime);
	QDateTime getDateTime(int index);
	int getIndex(const QDateTime& datetime, IndexOption option = IndexOption::Null);
	Bar getMax();
	double getMax(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMax(int index1, int index2, BarData barData);
	Bar getMin();
	double getMin(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMin(int index1, int index2, BarData barData);
	double highestHigh(int index1, int index2);
	double highestHigh(int nBars);
	double highestHigh(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double highestHigh();
	Bar highestHighBar(int index1, int index2);
	Bar highestHighBar(int nBars);
	Bar highestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Bar highestHighBar();
	double highestLow(int index1, int index2);
	double highestLow(int nBars);
	double highestLow(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Bar highestLowBar(int index1, int index2);
	Bar highestLowBar(int nBars);
	Bar highestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double lowestHigh(int index1, int index2);
	double lowestHigh(int nBars);
	double lowestHigh(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Bar lowestHighBar(int index1, int index2);
	Bar lowestHighBar(int nBars);
	Bar lowestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double lowestLow(int index1, int index2);
	double lowestLow(int nBars);
	double lowestLow(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double lowestLow();
	Bar lowestLowBar(int index1, int index2);
	Bar lowestLowBar(int nBars);
	Bar lowestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Bar lowestLowBar();

private:
	QSharedDataPointer<BarSeriesPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const BarSeries& barseries);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BarSeries& barseries);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarSeries)

#endif // __QUANTKIT_BARSERIES_H__
