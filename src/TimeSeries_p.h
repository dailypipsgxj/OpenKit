#ifndef __QUANTKIT_TIMESERIES_PRIVATE_H__
#define __QUANTKIT_TIMESERIES_PRIVATE_H__

#include <QuantKit/TimeSeries.h>

#include <QSharedData>

#include "Indicator_p.h"
#include "TimeSeriesItem_p.h"

namespace QuantKit {

class TimeSeriesPrivate : public QSharedData
{
public:
	IDataSeries m_item;
	QString m_name;
	QString m_description;
	TimeSeriesItem timeSeriesItem_0;
	TimeSeriesItem timeSeriesItem_1;
	bool bool_0;
	double double_0;
	double double_1;
	double double_2;
	double double_3;
	QList<Indicator> m_indicators;

public:
	TimeSeriesPrivate();
	explicit TimeSeriesPrivate(const IDataSeries& series);
	TimeSeriesPrivate(const QString& name, const QString& description);
	virtual ~TimeSeriesPrivate();

public:
	QString name() const { return m_name; }
	QString description() const { return m_description; }
	virtual int count() const Q_DECL_OVERRIDE { return (int)m_item.count(); }
	QList<Indicator> indicators() const { return m_indicators; }
	virtual double first() const Q_DECL_OVERRIDE
	{
		return ((TimeSeriesItem)m_item[0L]).value();
	}

	virtual double last() const Q_DECL_OVERRIDE
	{
		return ((TimeSeriesItem)m_item[m_item.count() - 1L]).value();
	}

	virtual QDateTime firstDateTime() const Q_DECL_OVERRIDE;
	virtual QDateTime lastDateTime() const Q_DECL_OVERRIDE;
	virtual double item(int index) const Q_DECL_OVERRIDE
	{
		return ((TimeSeriesItem)m_item[(long)index]).value();
	}

	virtual double item(int index, BarData barData) const Q_DECL_OVERRIDE { return this[index]; }
	double item(int index, int row) const
	{
		return ((TimeSeriesItem)m_item[(long)index]).value();
	}

	double item(const QDateTime& dateTime, SearchOption option) const
	{
		return GetByDateTime(dateTime, option).value();
	}

	void setItem(const QDateTime& dateTime, SearchOption option, double value) { Add(dateTime, value); }
	double item(const QDateTime& dateTime, int row, SearchOption option) const
	{
		return GetByDateTime(dateTime, option).value();
	}

	void add(const QDateTime& dateTime, double value);
	double ago(int n);
	void clear();
	bool contains(const QDateTime& dateTime)
	{
		return IndexOf(dateTime, SearchOption.ExactFirst) != -1;
	}

	Cross crosses(double level, int index);
	Cross crosses(const TimeSeries& series, const QDateTime& dateTime);
	TimeSeries exp();
	double getAsymmetry(int index1, int index2, int row);
	double getAutoCorrelation(int Lag)
	{
		return GetAutoCovariance(Lag) / GetVariance();
	}

	virtual double getAutoCovariance(int Lag) Q_DECL_OVERRIDE;
	TimeSeriesItem getByDateTime(const QDateTime& dateTime, SearchOption option);
	double getCorrelation(int row1, int row2, int index1, int index2)
	{
		return GetCovariance(row1, row2, index1, index2) / (GetStdDev(index1, index2, row1) * GetStdDev(index1, index2, row2));
	}

	double getCorrelation(const TimeSeries& series)
	{
		return GetCovariance(series) / (GetStdDev() * series.GetStdDev());
	}

	double getCovariance(int row1, int row2, int index1, int index2);
	double getCovariance(const TimeSeries& series);
	virtual QDateTime getDateTime(int index) Q_DECL_OVERRIDE
	{
		return ((TimeSeriesItem)m_item[(long)index]).entryDate();
	}

	double getExcess(int index1, int index2, int row);
	virtual int getIndex(const QDateTime& datetime, IndexOption option) Q_DECL_OVERRIDE;
	TimeSeriesItem getItem(int index)
	{
		return (TimeSeriesItem)m_item[(long)index];
	}

	double getMax();
	virtual double getMax(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE;
	virtual double getMax(int index1, int index2, BarData barData) Q_DECL_OVERRIDE { return GetMax(index1, index2); }
	double getMax(int index1, int index2);
	TimeSeriesItem getMaxItem() { return timeSeriesItem_1; }
	double getMean();
	virtual double getMean(int index1, int index2) Q_DECL_OVERRIDE
	{
		return GetMean(index1, index2, 0);
	}

	virtual double getMean(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE
	{
		return GetMean(dateTime1, dateTime2, 0);
	}

	virtual double getMean(int row) Q_DECL_OVERRIDE
	{
		return GetMean(0, m_item - 1, row);
	}

	double getMean(int index1, int index2, int row);
	double getMean(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	virtual double getMedian(int index1, int index2) Q_DECL_OVERRIDE
	{
		return GetMedian(index1, index2, 0);
	}

	virtual double getMedian(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE
	{
		return GetMedian(dateTime1, dateTime2, 0);
	}

	virtual double getMedian(int row) Q_DECL_OVERRIDE
	{
		return GetMedian(0, m_item - 1, row);
	}

	double getMedian();
	double getMedian(int index1, int index2, int row);
	double getMedian(const QDateTime& dateTime1, const QDateTime& dateTime2, int row);
	double getMin();
	virtual double getMin(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE;
	virtual double getMin(int index1, int index2, BarData barData) Q_DECL_OVERRIDE { return GetMin(index1, index2); }
	double getMin(int index1, int index2);
	TimeSeriesItem getMinItem() { return timeSeriesItem_0; }
	double getMoment(int k, int index1, int index2, int row);
	virtual TimeSeries getNegativeSeries() Q_DECL_OVERRIDE;
	double getNegativeStdDev()
	{
		return Math.Sqrt(GetNegativeVariance());
	}

	double getNegativeStdDev(int index1, int index2)
	{
		return Math.Sqrt(GetNegativeVariance(index1, index2));
	}

	double getNegativeStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return Math.Sqrt(GetNegativeVariance(dateTime1, dateTime2));
	}

	double getNegativeStdDev(int row)
	{
		return Math.Sqrt(GetNegativeVariance(row));
	}

	double getNegativeStdDev(int index1, int index2, int row)
	{
		return Math.Sqrt(GetNegativeVariance(index1, index2, row));
	}

	double getNegativeStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
	{
		return Math.Sqrt(GetNegativeVariance(dateTime1, dateTime2, row));
	}

	virtual double getNegativeVariance() Q_DECL_OVERRIDE { return GetNegativeVariance(0); }
	virtual double getNegativeVariance(int index1, int index2) Q_DECL_OVERRIDE
	{
		return GetNegativeVariance(index1, index2, 0);
	}

	virtual double getNegativeVariance(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE
	{
		return GetNegativeVariance(dateTime1, dateTime2, 0);
	}

	virtual double getNegativeVariance(int row) Q_DECL_OVERRIDE
	{
		return GetNegativeVariance(0, m_item - 1, row);
	}

	double getNegativeVariance(int index1, int index2, int row);
	virtual double getNegativeVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row) Q_DECL_OVERRIDE;
	virtual TimeSeries getPercentReturnSeries() Q_DECL_OVERRIDE;
	virtual TimeSeries getPositiveSeries() Q_DECL_OVERRIDE;
	double getPositiveStdDev()
	{
		return Math.Sqrt(GetPositiveVariance());
	}

	double getPositiveStdDev(int index1, int index2)
	{
		return Math.Sqrt(GetPositiveVariance(index1, index2));
	}

	double getPositiveStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return Math.Sqrt(GetPositiveVariance(dateTime1, dateTime2));
	}

	double getPositiveStdDev(int row)
	{
		return Math.Sqrt(GetPositiveVariance(row));
	}

	double getPositiveStdDev(int index1, int index2, int row)
	{
		return Math.Sqrt(GetPositiveVariance(index1, index2, row));
	}

	double getPositiveStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
	{
		return Math.Sqrt(GetPositiveVariance(dateTime1, dateTime2, row));
	}

	virtual double getPositiveVariance() Q_DECL_OVERRIDE { return GetPositiveVariance(0); }
	double getPositiveVariance(int index1, int index2, int row);
	virtual double getPositiveVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row) Q_DECL_OVERRIDE;
	virtual double getPositiveVariance(int index1, int index2) Q_DECL_OVERRIDE
	{
		return GetPositiveVariance(index1, index2, 0);
	}

	virtual double getPositiveVariance(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE
	{
		return GetPositiveVariance(dateTime1, dateTime2, 0);
	}

	virtual double getPositiveVariance(int row) Q_DECL_OVERRIDE
	{
		return GetPositiveVariance(0, m_item - 1, row);
	}

	virtual TimeSeries getReturnSeries() Q_DECL_OVERRIDE;
	double getStdDev()
	{
		return Math.Sqrt(GetVariance());
	}

	double getStdDev(int index1, int index2)
	{
		return Math.Sqrt(GetVariance(index1, index2));
	}

	double getStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return Math.Sqrt(GetVariance(dateTime1, dateTime2));
	}

	double getStdDev(int row)
	{
		return Math.Sqrt(GetVariance(row));
	}

	double getStdDev(int index1, int index2, int row)
	{
		return Math.Sqrt(GetVariance(index1, index2, row));
	}

	double getStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
	{
		return Math.Sqrt(GetVariance(dateTime1, dateTime2, row));
	}

	double getSum();
	double getSum(int index1, int index2, int row);
	double getValue(int index)
	{
		return ((TimeSeriesItem)m_item[(long)index]).value();
	}

	double getVariance();
	virtual double getVariance(int index1, int index2) Q_DECL_OVERRIDE
	{
		return GetVariance(index1, index2, 0);
	}

	virtual double getVariance(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE
	{
		return GetVariance(dateTime1, dateTime2, 0);
	}

	virtual double getVariance(int row) Q_DECL_OVERRIDE
	{
		return GetVariance(0, m_item - 1, row);
	}

	double getVariance(int index1, int index2, int row);
	virtual double getVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row) Q_DECL_OVERRIDE;
	int indexOf(const QDateTime& dateTime, SearchOption option);
	virtual TimeSeries log() Q_DECL_OVERRIDE;
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
	void remove(int index) { m_item.Remove((long)index); }
	TimeSeries shift(int offset);
	TimeSeries sqrt();
};

} // namepsace QuantKit

#endif // __QUANTKIT_TIMESERIES_PRIVATE_H__
