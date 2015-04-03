#ifndef __QUANTKIT_TIMESERIES_H__
#define __QUANTKIT_TIMESERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QDateTime>
#include <QSharedDataPointer>

#include <QuantKit/ISeries.h>
#include <QuantKit/IDataSeries.h>
#include <QuantKit/BarData.h>
#include <QuantKit/SearchOption.h>
#include <QuantKit/Cross.h>
#include <QuantKit/IndexOption.h>

namespace QuantKit {

class TimeSeriesPrivate;

class Indicator;
class TimeSeriesItem;

class QUANTKIT_EXPORT TimeSeries : public ISeries
{
public:
	TimeSeries();
	explicit TimeSeries(const IDataSeries& series);
	TimeSeries(const QString& name, const QString& description = "");
	~TimeSeries();

	TimeSeries(const TimeSeries &other);
	TimeSeries& operator=(const TimeSeries &other);
	bool operator==(const TimeSeries &other) const;
	inline bool operator!=(const TimeSeries &other) const { return !(this->operator==(other));  }
public:
	QString name() const;
	QString description() const;
	int count() const;
	QList<Indicator> indicators() const;
	double first() const;
	double last() const;
	QDateTime firstDateTime() const;
	QDateTime lastDateTime() const;
	double item(int index) const;
	double item(int index, BarData barData) const;
	double item(int index, int row) const;
	double item(const QDateTime& dateTime, SearchOption option = SearchOption::ExactFirst) const;
	void setItem(const QDateTime& dateTime, SearchOption option = SearchOption::ExactFirst, double value);
	double item(const QDateTime& dateTime, int row, SearchOption option = SearchOption::ExactFirst) const;
	void add(const QDateTime& dateTime, double value);
	double ago(int n);
	void clear();
	bool contains(const QDateTime& dateTime);
	Cross crosses(double level, int index);
	Cross crosses(const TimeSeries& series, const QDateTime& dateTime);
	TimeSeries exp();
	double getAsymmetry(int index1, int index2, int row);
	double getAutoCorrelation(int Lag);
	double getAutoCovariance(int Lag);
	TimeSeriesItem getByDateTime(const QDateTime& dateTime, SearchOption option = SearchOption::ExactFirst);
	double getCorrelation(int row1, int row2, int index1, int index2);
	double getCorrelation(const TimeSeries& series);
	double getCovariance(int row1, int row2, int index1, int index2);
	double getCovariance(const TimeSeries& series);
	QDateTime getDateTime(int index);
	double getExcess(int index1, int index2, int row);
	int getIndex(const QDateTime& datetime, IndexOption option = IndexOption::Null);
	TimeSeriesItem getItem(int index);
	double getMax();
	double getMax(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMax(int index1, int index2, BarData barData);
	double getMax(int index1, int index2);
	TimeSeriesItem getMaxItem();
	double getMean();
	double getMean(int index1, int index2);
	double getMean(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMean(int row);
	double getMean(int index1, int index2, int row);
	double getMean(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	double getMedian(int index1, int index2);
	double getMedian(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMedian(int row);
	double getMedian();
	double getMedian(int index1, int index2, int row);
	double getMedian(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	double getMin();
	double getMin(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMin(int index1, int index2, BarData barData);
	double getMin(int index1, int index2);
	TimeSeriesItem getMinItem();
	double getMoment(int k, int index1, int index2, int row);
	TimeSeries getNegativeSeries();
	double getNegativeStdDev();
	double getNegativeStdDev(int index1, int index2);
	double getNegativeStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getNegativeStdDev(int row);
	double getNegativeStdDev(int index1, int index2, int row);
	double getNegativeStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	double getNegativeVariance();
	double getNegativeVariance(int index1, int index2);
	double getNegativeVariance(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getNegativeVariance(int row);
	double getNegativeVariance(int index1, int index2, int row);
	double getNegativeVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	TimeSeries getPercentReturnSeries();
	TimeSeries getPositiveSeries();
	double getPositiveStdDev();
	double getPositiveStdDev(int index1, int index2);
	double getPositiveStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getPositiveStdDev(int row);
	double getPositiveStdDev(int index1, int index2, int row);
	double getPositiveStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	double getPositiveVariance();
	double getPositiveVariance(int index1, int index2, int row);
	double getPositiveVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	double getPositiveVariance(int index1, int index2);
	double getPositiveVariance(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getPositiveVariance(int row);
	TimeSeries getReturnSeries();
	double getStdDev();
	double getStdDev(int index1, int index2);
	double getStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getStdDev(int row);
	double getStdDev(int index1, int index2, int row);
	double getStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	double getSum();
	double getSum(int index1, int index2, int row);
	double getValue(int index);
	double getVariance();
	double getVariance(int index1, int index2);
	double getVariance(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getVariance(int row);
	double getVariance(int index1, int index2, int row);
	double getVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	int indexOf(const QDateTime& dateTime, SearchOption option = SearchOption::ExactFirst);
	TimeSeries log();
	TimeSeries log10();
	TimeSeries op_Addition(const TimeSeries& series1, const TimeSeries& series2);
	TimeSeries op_Addition(const TimeSeries& series, double Value);
	TimeSeries op_Addition(double Value, const TimeSeries& series);
	TimeSeries op_Division(const TimeSeries& series1, const TimeSeries& series2);
	TimeSeries op_Division(const TimeSeries& series, double Value);
	TimeSeries op_Division(double Value, const TimeSeries& series);
	TimeSeries op_Multiply(const TimeSeries& series1, const TimeSeries& series2);
	TimeSeries op_Multiply(const TimeSeries& series, double Value);
	TimeSeries op_Multiply(double Value, const TimeSeries& series);
	TimeSeries op_Subtraction(const TimeSeries& series1, const TimeSeries& series2);
	TimeSeries op_Subtraction(const TimeSeries& series, double Value);
	TimeSeries op_Subtraction(double Value, const TimeSeries& series);
	TimeSeries pow(double Pow);
	void remove(int index);
	TimeSeries shift(int offset);
	TimeSeries sqrt();

protected:
	TimeSeries(TimeSeriesPrivate& dd);
	QSharedDataPointer<TimeSeriesPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const TimeSeries& timeseries);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const TimeSeries& timeseries);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TimeSeries)

#endif // __QUANTKIT_TIMESERIES_H__
