#include <QuantKit/TimeSeries.h>

#include "Indicator_p.h"
#include <QuantKit/Event/TimeSeriesItem.h>
#include "TimeSeries_p.h"

using namespace QuantKit;

TimeSeriesPrivate::TimeSeriesPrivate()
	: m_item(new MemorySeries())
	, bool_0(true)
	, m_indicators(new QList<Indicator>())
{
}

TimeSeriesPrivate::TimeSeriesPrivate(const IDataSeries& series)
	: m_item(series)
	, m_name(series.name())
	, m_description(series.description())
	, bool_0(true)
	, m_indicators(new QList<Indicator>())
{
}

TimeSeriesPrivate::TimeSeriesPrivate(const QString& name, const QString& description)
	: m_item(new MemorySeries(name, description))
	, m_name(name)
	, m_description(description)
	, bool_0(true)
	, m_indicators(new QList<Indicator>())
{
}

TimeSeriesPrivate::~TimeSeriesPrivate ()
{
}

QDateTime TimeSeriesPrivate::firstDateTime() const
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_item[0L].dateTime();
}

QDateTime TimeSeriesPrivate::lastDateTime() const
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_item[(long)(m_item - 1)].dateTime();
}

void TimeSeriesPrivate::add(const QDateTime& dateTime, double value)
{
	TimeSeriesItem timeSeriesItem = new TimeSeriesItem(dateTime, value);
	if (timeSeriesItem_0 == null)
	{
		timeSeriesItem_0 = timeSeriesItem;
	}
	else
	{
		if (timeSeriesItem.value() < timeSeriesItem_0.value())
		{
			timeSeriesItem_0 = timeSeriesItem;
		}
	}
	if (timeSeriesItem_1 == null)
	{
		timeSeriesItem_1 = timeSeriesItem;
	}
	else
	{
		if (timeSeriesItem.value() > timeSeriesItem_1.value())
		{
			timeSeriesItem_1 = timeSeriesItem;
		}
	}
	m_item.Add(timeSeriesItem);
	int @int = (int)m_item.count() - 1;
	for (int i = 0; i < m_indicators.Count; i++)
	{
		if (m_indicators[i].autoUpdate())
		{
			m_indicators[i].method_0(@int);
		}
	}
}

double TimeSeriesPrivate::ago(int n)
{
	int num = m_item - 1 - n;
	if (num < 0)
	{
		throw new ArgumentException("Can not return an entry " + n + " entries ago: time series is too short.");
	}
	return this[num];
}

void TimeSeriesPrivate::clear()
{
	m_item.Clear();
	timeSeriesItem_0 = null;
	timeSeriesItem_1 = null;
	bool_0 = true;
}

Cross TimeSeriesPrivate::crosses(double level, int index)
{
	if (index <= 0 || (long)index > m_item.count() - 1L)
	{
		return Cross.None;
	}
	if (((TimeSeriesItem)m_item[(long)(index - 1)]).value() <= level && ((TimeSeriesItem)m_item[(long)index]).value() > level)
	{
		return Cross.Above;
	}
	if (((TimeSeriesItem)m_item[(long)(index - 1)]).value() >= level && ((TimeSeriesItem)m_item[(long)index]).value() < level)
	{
		return Cross.Below;
	}
	return Cross.None;
}

Cross TimeSeriesPrivate::crosses(const TimeSeries& series, const QDateTime& dateTime)
{
	int num = IndexOf(dateTime, SearchOption.ExactFirst);
	int num2 = series.IndexOf(dateTime, SearchOption.ExactFirst);
	if (num <= 0 || (long)num >= m_item.count())
	{
		return Cross.None;
	}
	if (num2 > 0 && num2 < series.count())
	{
		DateTime dateTime2 = GetDateTime(num - 1);
		DateTime dateTime3 = series.GetDateTime(num2 - 1);
		if (dateTime2 == dateTime3)
		{
			if (GetValue(num - 1) <= series.GetValue(num2 - 1) && GetValue(num) > series.GetValue(num2))
			{
				return Cross.Above;
			}
			if (GetValue(num - 1) >= series.GetValue(num2 - 1) && GetValue(num) < series.GetValue(num2))
			{
				return Cross.Below;
			}
		}
		else
		{
			double value;
			double value2;
			if (dateTime2 < dateTime3)
			{
				DateTime dateTime4 = GetDateTime(num - 1);
				value = GetValue(num - 1);
				if (series.IndexOf(dateTime4, SearchOption.Next) != num2)
				{
					value2 = series.GetValue(series.IndexOf(dateTime4, SearchOption.Next));
				}
				else
				{
					value2 = series.GetValue(series.IndexOf(dateTime4, SearchOption.Prev));
				}
			}
			else
			{
				DateTime dateTime5 = series.GetDateTime(num2 - 1);
				value2 = series.GetValue(num2 - 1);
				if (IndexOf(dateTime5, SearchOption.Prev) != num)
				{
					value = GetValue(IndexOf(dateTime5, SearchOption.Next));
				}
				else
				{
					value = GetValue(IndexOf(dateTime5, SearchOption.Prev));
				}
			}
			if (value <= value2 && GetValue(num) > series.GetValue(num2))
			{
				return Cross.Above;
			}
			if (value >= value2 && GetValue(num) < series.GetValue(num2))
			{
				return Cross.Below;
			}
		}
		return Cross.None;
	}
	return Cross.None;
}

TimeSeries TimeSeriesPrivate::exp()
{
	TimeSeries timeSeries = base.GetType().GetConstructor(new Type[0]).Invoke(new object[0]) as TimeSeries;
	timeSeries.setName() = "Exp(" + m_name + ")";
	timeSeries.setDescription() = m_description;
	for (int i = 0; i < m_item; i++)
	{
		timeSeries.Add(GetDateTime(i), Math.Exp(this[i, 0]));
	}
	return timeSeries;
}

double TimeSeriesPrivate::getAsymmetry(int index1, int index2, int row)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate asymmetry. Series " + m_name + " is empty.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 < 0 || index2 > m_item - 1)
	{
		throw new ApplicationException("index2 is out of range");
	}
	double stdDev = GetStdDev(index1, index2, row);
	if (stdDev == 0.0)
	{
		return 0.0;
	}
	return GetMoment(3, index1, index2, row) / Math.Pow(stdDev, 3.0);
}

double TimeSeriesPrivate::getAutoCovariance(int Lag)
{
	if (Lag >= m_item)
	{
		throw new ApplicationException("Not enough data points in the series to calculate autocovariance");
	}
	double mean = GetMean();
	double num = 0.0;
	for (int i = Lag; i < m_item; i++)
	{
		num += (this[i, 0] - mean) * (this[i - Lag, 0] - mean);
	}
	return num / (double)(m_item - Lag);
}

TimeSeriesItem TimeSeriesPrivate::getByDateTime(const QDateTime& dateTime, SearchOption option)
{
	int num = IndexOf(dateTime, option);
	if (num != -1)
	{
		return (TimeSeriesItem)m_item[(long)num];
	}
	return null;
}

double TimeSeriesPrivate::getCovariance(int row1, int row2, int index1, int index2)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate covariance. Array is empty.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 < 0 || index2 > m_item - 1)
	{
		throw new ApplicationException("index2 is out of range");
	}
	double mean = GetMean(index1, index2, row1);
	double mean2 = GetMean(index1, index2, row2);
	double num = 0.0;
	double num2 = 0.0;
	for (int i = index1; i <= index2; i++)
	{
		num2 += (this[i, row1] - mean) * (this[i, row2] - mean2);
		num += 1.0;
	}
	if (num <= 1.0)
	{
		return 0.0;
	}
	return num2 / (num - 1.0);
}

double TimeSeriesPrivate::getCovariance(const TimeSeries& series)
{
	if (series == null)
	{
		throw new ArgumentException("Argument series should be of TimeSeries type");
	}
	double mean = GetMean();
	double mean2 = series.GetMean();
	double num = 0.0;
	double num2 = 0.0;
	for (int i = 0; i < m_item; i++)
	{
		DateTime dateTime = GetDateTime(i);
		if (series.Contains(dateTime))
		{
			num2 += (this[i] - mean) * (series[dateTime, SearchOption.ExactFirst] - mean2);
			num += 1.0;
		}
	}
	if (num <= 1.0)
	{
		return 0.0;
	}
	return num2 / (num - 1.0);
}

double TimeSeriesPrivate::getExcess(int index1, int index2, int row)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate excess. Series " + m_name + " is empty.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 < 0 || index2 > m_item - 1)
	{
		throw new ApplicationException("index2 is out of range");
	}
	double stdDev = GetStdDev(index1, index2, row);
	if (stdDev == 0.0)
	{
		return 0.0;
	}
	return GetMoment(4, index1, index2, row) / Math.Pow(stdDev, 4.0);
}

int TimeSeriesPrivate::getIndex(const QDateTime& datetime, IndexOption option)
{
	int num = 0;
	int num2 = 0;
	int num3 = (int)m_item.count() - 1;
	bool flag = true;
	while (flag)
	{
		if (num3 < num2)
		{
			return -1;
		}
		num = (num2 + num3) / 2;
		switch (option)
		{
			case IndexOption.Null:
				if (m_item[(long)num].entryDate() == datetime)
				{
					flag = false;
				}
				else
				{
					if (m_item[(long)num].entryDate() > datetime)
					{
						num3 = num - 1;
					}
					else
					{
						if (m_item[(long)num].entryDate() < datetime)
						{
							num2 = num + 1;
						}
					}
				}
				break;
			case IndexOption.Next:
				if (m_item[(long)num].entryDate() >= datetime && (num == 0 || m_item[(long)(num - 1)].entryDate() < datetime))
				{
					flag = false;
				}
				else
				{
					if (m_item[(long)num].entryDate() < datetime)
					{
						num2 = num + 1;
					}
					else
					{
						num3 = num - 1;
					}
				}
				break;
			case IndexOption.Prev:
				if (m_item[(long)num].entryDate() <= datetime && ((long)num == m_item.count() - 1L || m_item[(long)(num + 1)].entryDate() > datetime))
				{
					flag = false;
				}
				else
				{
					if (m_item[(long)num].entryDate() > datetime)
					{
						num3 = num - 1;
					}
					else
					{
						num2 = num + 1;
					}
				}
				break;
		}
	}
	return num;
}

double TimeSeriesPrivate::getMax()
{
	if (timeSeriesItem_1 == null)
	{
		return double.NaN;
	}
	return timeSeriesItem_1.value();
}

double TimeSeriesPrivate::getMax(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	TimeSeriesItem timeSeriesItem = null;
	int num = 0;
	while ((long)num < m_item.count())
	{
		TimeSeriesItem timeSeriesItem2 = (TimeSeriesItem)m_item[(long)num];
		if (!(timeSeriesItem2.dateTime() < dateTime1))
		{
			if (!(timeSeriesItem2.dateTime() > dateTime2))
			{
				if (timeSeriesItem == null)
				{
					timeSeriesItem = timeSeriesItem2;
				}
				else
				{
					if (timeSeriesItem2.value() > timeSeriesItem.value())
					{
						timeSeriesItem = timeSeriesItem2;
					}
				}
			}
			else
			{
				if (timeSeriesItem != null)
				{
					return timeSeriesItem.value();
				}
				return double.NaN;
			}
		}
		num++;
	}
	if (timeSeriesItem != null)
	{
		return timeSeriesItem.value();
	}
	return double.NaN;
}

double TimeSeriesPrivate::getMax(int index1, int index2)
{
	TimeSeriesItem timeSeriesItem = null;
	for (int i = index1; i <= index2; i++)
	{
		TimeSeriesItem timeSeriesItem2 = (TimeSeriesItem)m_item[(long)i];
		if (timeSeriesItem == null)
		{
			timeSeriesItem = timeSeriesItem2;
		}
		else
		{
			if (timeSeriesItem2.value() > timeSeriesItem.value())
			{
				timeSeriesItem = timeSeriesItem2;
			}
		}
	}
	if (timeSeriesItem != null)
	{
		return timeSeriesItem.value();
	}
	return double.NaN;
}

double TimeSeriesPrivate::getMean()
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate mean. Array is empty.");
	}
	if (bool_0)
	{
		double_0 = GetMean(0, m_item - 1);
	}
	return double_0;
}

double TimeSeriesPrivate::getMean(int index1, int index2, int row)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate mean. Array is empty.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		double num = 0.0;
		for (int i = index1; i <= index2; i++)
		{
			num += this[i, row];
		}
		return num / (double)(index2 - index1 + 1);
	}
	throw new ApplicationException("index2 is out of range");
}

double TimeSeriesPrivate::getMean(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate mean. Array is empty.");
	}
	if (dateTime1 >= dateTime2)
	{
		throw new ApplicationException("dateTime1 must be smaller than dateTime2");
	}
	int index = GetIndex(dateTime1, IndexOption.Null);
	int index2 = GetIndex(dateTime2, IndexOption.Null);
	if (index == -1)
	{
		throw new ApplicationException("dateTime1 is out of range");
	}
	if (index2 == -1)
	{
		throw new ApplicationException("dateTime2 is out of range");
	}
	return GetMean(index, index2, row);
}

double TimeSeriesPrivate::getMedian()
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate median. Array is empty.");
	}
	if (bool_0)
	{
		double_3 = GetMedian(0, m_item - 1);
	}
	return double_3;
}

double TimeSeriesPrivate::getMedian(int index1, int index2, int row)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate mean. Array is empty.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		ArrayList arrayList = new ArrayList();
		for (int i = index1; i <= index2; i++)
		{
			arrayList.Add(this[i, row]);
		}
		arrayList.Sort();
		return (double)arrayList[arrayList.Count / 2];
	}
	throw new ApplicationException("index2 is out of range");
}

double TimeSeriesPrivate::getMedian(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate mean. Array is empty.");
	}
	if (dateTime1 >= dateTime2)
	{
		throw new ApplicationException("dateTime1 must be smaller than dateTime2");
	}
	int index = GetIndex(dateTime1, IndexOption.Null);
	int index2 = GetIndex(dateTime2, IndexOption.Null);
	if (index == -1)
	{
		throw new ApplicationException("dateTime1 is out of range");
	}
	if (index2 == -1)
	{
		throw new ApplicationException("dateTime2 is out of range");
	}
	return GetMedian(index, index2, row);
}

double TimeSeriesPrivate::getMin()
{
	if (timeSeriesItem_0 == null)
	{
		return double.NaN;
	}
	return timeSeriesItem_0.value();
}

double TimeSeriesPrivate::getMin(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	TimeSeriesItem timeSeriesItem = null;
	int num = 0;
	while ((long)num < m_item.count())
	{
		TimeSeriesItem timeSeriesItem2 = (TimeSeriesItem)m_item[(long)num];
		if (!(timeSeriesItem2.dateTime() < dateTime1))
		{
			if (!(timeSeriesItem2.dateTime() > dateTime2))
			{
				if (timeSeriesItem == null)
				{
					timeSeriesItem = timeSeriesItem2;
				}
				else
				{
					if (timeSeriesItem2.value() < timeSeriesItem.value())
					{
						timeSeriesItem = timeSeriesItem2;
					}
				}
			}
			else
			{
				if (timeSeriesItem != null)
				{
					return timeSeriesItem.value();
				}
				return double.NaN;
			}
		}
		num++;
	}
	if (timeSeriesItem != null)
	{
		return timeSeriesItem.value();
	}
	return double.NaN;
}

double TimeSeriesPrivate::getMin(int index1, int index2)
{
	TimeSeriesItem timeSeriesItem = null;
	for (int i = index1; i <= index2; i++)
	{
		TimeSeriesItem timeSeriesItem2 = (TimeSeriesItem)m_item[(long)i];
		if (timeSeriesItem == null)
		{
			timeSeriesItem = timeSeriesItem2;
		}
		else
		{
			if (timeSeriesItem2.value() < timeSeriesItem.value())
			{
				timeSeriesItem = timeSeriesItem2;
			}
		}
	}
	if (timeSeriesItem != null)
	{
		return timeSeriesItem.value();
	}
	return double.NaN;
}

double TimeSeriesPrivate::getMoment(int k, int index1, int index2, int row)
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Can not calculate momentum. Series " + m_name + " is empty.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 < 0 || index2 > m_item - 1)
	{
		throw new ApplicationException("index2 is out of range");
	}
	double num;
	if (k == 1)
	{
		num = 0.0;
	}
	else
	{
		num = GetMean(index1, index2, row);
	}
	int num2 = 0;
	double num3 = 0.0;
	for (int i = index1; i <= index2; i++)
	{
		num3 += Math.Pow(this[i, row] - num, (double)k);
		num2++;
	}
	if (num2 == 0)
	{
		return 0.0;
	}
	return num3 / (double)num2;
}

TimeSeries TimeSeriesPrivate::getNegativeSeries()
{
	TimeSeries timeSeries = new TimeSeries();
	for (int i = 0; i < m_item; i++)
	{
		if (this[i] < 0.0)
		{
			timeSeries.Add(GetDateTime(i), this[i]);
		}
	}
	return timeSeries;
}

double TimeSeriesPrivate::getNegativeVariance(int index1, int index2, int row)
{
	if (m_item <= 1)
	{
		throw new ApplicationException("Can not calculate variance. Insufficient number of elements in the array.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		int num = 0;
		double num2 = 0.0;
		for (int i = index1; i <= index2; i++)
		{
			if (this[i, row] < 0.0)
			{
				num2 += this[i, row];
				num++;
			}
		}
		num2 /= (double)num;
		double num3 = 0.0;
		for (int j = index1; j <= index2; j++)
		{
			if (this[j, row] < 0.0)
			{
				num3 += (num2 - this[j, row]) * (num2 - this[j, row]);
			}
		}
		return num3 / (double)num;
	}
	throw new ApplicationException("index2 is out of range");
}

double TimeSeriesPrivate::getNegativeVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	if (m_item <= 1)
	{
		throw new ApplicationException("Can not calculate variance. Insufficient number of elements in the array.");
	}
	if (dateTime1 >= dateTime2)
	{
		throw new ApplicationException("dateTime1 must be smaller than dateTime2");
	}
	int index = GetIndex(dateTime1, IndexOption.Null);
	int index2 = GetIndex(dateTime2, IndexOption.Null);
	if (index == -1)
	{
		throw new ApplicationException("dateTime1 is out of range");
	}
	if (index2 == -1)
	{
		throw new ApplicationException("dateTime2 is out of range");
	}
	return GetNegativeVariance(index, index2, row);
}

TimeSeries TimeSeriesPrivate::getPercentReturnSeries()
{
	TimeSeries timeSeries = new TimeSeries(m_name, m_description + " (% return)");
	if (m_item > 1)
	{
		double num = this[0];
		for (int i = 0; i < m_item; i++)
		{
			DateTime dateTime = GetDateTime(i);
			double num2 = this[i];
			if (num != 0.0)
			{
				timeSeries.Add(dateTime, (num2 / num - 1.0) * 100.0);
			}
			else
			{
				timeSeries.Add(dateTime, 0.0);
			}
			num = num2;
		}
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::getPositiveSeries()
{
	TimeSeries timeSeries = new TimeSeries();
	for (int i = 0; i < m_item; i++)
	{
		if (this[i] > 0.0)
		{
			timeSeries.Add(GetDateTime(i), this[i]);
		}
	}
	return timeSeries;
}

double TimeSeriesPrivate::getPositiveVariance(int index1, int index2, int row)
{
	if (m_item <= 1)
	{
		throw new ApplicationException("Can not calculate variance. Insufficient number of elements in the array.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		int num = 0;
		double num2 = 0.0;
		for (int i = index1; i <= index2; i++)
		{
			if (this[i, row] > 0.0)
			{
				num2 += this[i, row];
				num++;
			}
		}
		num2 /= (double)num;
		double num3 = 0.0;
		for (int j = index1; j <= index2; j++)
		{
			if (this[j, row] > 0.0)
			{
				num3 += (num2 - this[j, row]) * (num2 - this[j, row]);
			}
		}
		return num3 / (double)num;
	}
	throw new ApplicationException("index2 is out of range");
}

double TimeSeriesPrivate::getPositiveVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	if (m_item <= 1)
	{
		throw new ApplicationException("Can not calculate variance. Insufficient number of elements in the array.");
	}
	if (dateTime1 >= dateTime2)
	{
		throw new ApplicationException("dateTime1 must be smaller than dateTime2");
	}
	int index = GetIndex(dateTime1, IndexOption.Null);
	int index2 = GetIndex(dateTime2, IndexOption.Null);
	if (index == -1)
	{
		throw new ApplicationException("dateTime1 is out of range");
	}
	if (index2 == -1)
	{
		throw new ApplicationException("dateTime2 is out of range");
	}
	return GetPositiveVariance(index, index2, row);
}

TimeSeries TimeSeriesPrivate::getReturnSeries()
{
	TimeSeries timeSeries = new TimeSeries(m_name, m_description + " (return)");
	if (m_item > 1)
	{
		double num = this[0];
		for (int i = 0; i < m_item; i++)
		{
			DateTime dateTime = GetDateTime(i);
			double num2 = this[i];
			if (num != 0.0)
			{
				timeSeries.Add(dateTime, num2 / num);
			}
			else
			{
				timeSeries.Add(dateTime, 0.0);
			}
			num = num2;
		}
	}
	return timeSeries;
}

double TimeSeriesPrivate::getSum()
{
	if (bool_0)
	{
		double_2 = 0.0;
		for (int i = 0; i < m_item; i++)
		{
			double_2 += this[i, 0];
		}
	}
	return double_2;
}

double TimeSeriesPrivate::getSum(int index1, int index2, int row)
{
	if (index1 >= index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		double num = 0.0;
		for (int i = index1; i <= index2; i++)
		{
			num += this[i, row];
		}
		return num;
	}
	throw new ApplicationException("index2 is out of range");
}

double TimeSeriesPrivate::getVariance()
{
	if (m_item <= 1)
	{
		throw new ApplicationException("Can not calculate variance. Insufficient number of elements in the array.");
	}
	if (bool_0)
	{
		double mean = GetMean();
		double_1 = 0.0;
		for (int i = 0; i < m_item; i++)
		{
			double_1 += (mean - this[i, 0]) * (mean - this[i, 0]);
		}
		double_1 /= (double)(m_item - 1);
	}
	return double_1;
}

double TimeSeriesPrivate::getVariance(int index1, int index2, int row)
{
	if (m_item <= 1)
	{
		throw new ApplicationException("Can not calculate variance. Insufficient number of elements in the array.");
	}
	if (index1 > index2)
	{
		throw new ApplicationException("index1 must be smaller than index2");
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		throw new ApplicationException("index1 is out of range");
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		double mean = GetMean(index1, index2, row);
		double num = 0.0;
		for (int i = index1; i <= index2; i++)
		{
			num += (mean - this[i, row]) * (mean - this[i, row]);
		}
		return num / (double)(index2 - index1);
	}
	throw new ApplicationException("index2 is out of range");
}

double TimeSeriesPrivate::getVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	if (m_item <= 1)
	{
		throw new ApplicationException("Can not calculate variance. Insufficient number of elements in the array.");
	}
	if (dateTime1 >= dateTime2)
	{
		throw new ApplicationException("dateTime1 must be smaller than dateTime2");
	}
	int index = GetIndex(dateTime1, IndexOption.Null);
	int index2 = GetIndex(dateTime2, IndexOption.Null);
	if (index == -1)
	{
		throw new ApplicationException("dateTime1 is out of range");
	}
	if (index2 == -1)
	{
		throw new ApplicationException("dateTime2 is out of range");
	}
	return GetVariance(index, index2, row);
}

int TimeSeriesPrivate::indexOf(const QDateTime& dateTime, SearchOption option)
{
	int num = (int)m_item.count() - 1;
	if (dateTime == GetDateTime(num))
	{
		return num;
	}
	num = 0;
	int num2 = 0;
	int num3 = (int)m_item.count() - 1;
	bool flag = true;
	while (flag)
	{
		if (num3 < num2)
		{
			return -1;
		}
		num = (num2 + num3) / 2;
		switch (option)
		{
			case SearchOption.Next:
				if (m_item[(long)num].entryDate() >= dateTime && (num == 0 || m_item[(long)(num - 1)].entryDate() < dateTime))
				{
					flag = false;
				}
				else
				{
					if (m_item[(long)num].entryDate() < dateTime)
					{
						num2 = num + 1;
					}
					else
					{
						num3 = num - 1;
					}
				}
				break;
			case SearchOption.Prev:
				if (m_item[(long)num].entryDate() <= dateTime && ((long)num == m_item.count() - 1L || m_item[(long)(num + 1)].entryDate() > dateTime))
				{
					flag = false;
				}
				else
				{
					if (m_item[(long)num].entryDate() > dateTime)
					{
						num3 = num - 1;
					}
					else
					{
						num2 = num + 1;
					}
				}
				break;
			case SearchOption.ExactFirst:
				if (m_item[(long)num].entryDate() == dateTime)
				{
					flag = false;
				}
				else
				{
					if (m_item[(long)num].entryDate() > dateTime)
					{
						num3 = num - 1;
					}
					else
					{
						if (m_item[(long)num].entryDate() < dateTime)
						{
							num2 = num + 1;
						}
					}
				}
				break;
		}
	}
	return num;
}

TimeSeries TimeSeriesPrivate::log()
{
	TimeSeries timeSeries = base.GetType().GetConstructor(new Type[0]).Invoke(new object[0]) as TimeSeries;
	timeSeries.setName() = "Log(" + m_name + ")";
	timeSeries.setDescription() = m_description;
	for (int i = 0; i < m_item; i++)
	{
		timeSeries.Add(GetDateTime(i), Math.Log(this[i, 0]));
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::log10()
{
	TimeSeries timeSeries = base.GetType().GetConstructor(new Type[0]).Invoke(new object[0]) as TimeSeries;
	timeSeries.setName() = "Log10(" + m_name + ")";
	timeSeries.setDescription() = m_description;
	for (int i = 0; i < m_item; i++)
	{
		timeSeries.Add(GetDateTime(i), Math.Log10(this[i, 0]));
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Addition(const TimeSeries& series1, const TimeSeries& series2)
{
	if (series1 != null && series2 != null)
	{
		TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
		{
			"(",
			series1.name(),
			"+",
			series2.name(),
			")"
		}), "");
		for (int i = 0; i < series1.count(); i++)
		{
			DateTime dateTime = series1.GetDateTime(i);
			if (series2.Contains(dateTime))
			{
				timeSeries.Add(dateTime, series1[dateTime, 0, SearchOption.ExactFirst] + series2[dateTime, 0, SearchOption.ExactFirst]);
			}
		}
		return timeSeries;
	}
	throw new ArgumentException("Operator argument can not be null");
}

TimeSeries TimeSeriesPrivate::op_Addition(const TimeSeries& series, double Value)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		series.name(),
		"+",
		Value.ToString("F2"),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		timeSeries.Add(series.GetDateTime(i), series[i, 0] + Value);
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Addition(double Value, const TimeSeries& series)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		Value.ToString("F2"),
		"+",
		series.name(),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		timeSeries.Add(series.GetDateTime(i), Value + series[i, 0]);
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Division(const TimeSeries& series1, const TimeSeries& series2)
{
	if (series1 != null && series2 != null)
	{
		TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
		{
			"(",
			series1.name(),
			"/",
			series2.name(),
			")"
		}), "");
		for (int i = 0; i < series1.count(); i++)
		{
			DateTime dateTime = series1.GetDateTime(i);
			if (series2.Contains(dateTime) && series2[dateTime, SearchOption.ExactFirst] != 0.0)
			{
				timeSeries.Add(dateTime, series1[dateTime, 0, SearchOption.ExactFirst] / series2[dateTime, 0, SearchOption.ExactFirst]);
			}
		}
		return timeSeries;
	}
	throw new ArgumentException("Operator argument can not be null");
}

TimeSeries TimeSeriesPrivate::op_Division(const TimeSeries& series, double Value)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		series.name(),
		"/",
		Value.ToString("F2"),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		timeSeries.Add(series.GetDateTime(i), series[i, 0] / Value);
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Division(double Value, const TimeSeries& series)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		Value.ToString("F2"),
		"/",
		series.name(),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		if (series[i, 0] != 0.0)
		{
			timeSeries.Add(series.GetDateTime(i), Value / series[i, 0]);
		}
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Multiply(const TimeSeries& series1, const TimeSeries& series2)
{
	if (series1 != null && series2 != null)
	{
		TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
		{
			"(",
			series1.name(),
			"*",
			series2.name(),
			")"
		}), "");
		for (int i = 0; i < series1.count(); i++)
		{
			DateTime dateTime = series1.GetDateTime(i);
			if (series2.Contains(dateTime))
			{
				timeSeries.Add(dateTime, series1[dateTime, 0, SearchOption.ExactFirst] * series2[dateTime, 0, SearchOption.ExactFirst]);
			}
		}
		return timeSeries;
	}
	throw new ArgumentException("Operator argument can not be null");
}

TimeSeries TimeSeriesPrivate::op_Multiply(const TimeSeries& series, double Value)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		series.name(),
		"*",
		Value.ToString("F2"),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		timeSeries.Add(series.GetDateTime(i), series[i, 0] * Value);
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Multiply(double Value, const TimeSeries& series)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		Value.ToString("F2"),
		"*",
		series.name(),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		timeSeries.Add(series.GetDateTime(i), Value * series[i, 0]);
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Subtraction(const TimeSeries& series1, const TimeSeries& series2)
{
	if (series1 != null && series2 != null)
	{
		TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
		{
			"(",
			series1.name(),
			"-",
			series2.name(),
			")"
		}), "");
		for (int i = 0; i < series1.count(); i++)
		{
			DateTime dateTime = series1.GetDateTime(i);
			if (series2.Contains(dateTime))
			{
				timeSeries.Add(dateTime, series1[dateTime, 0, SearchOption.ExactFirst] - series2[dateTime, 0, SearchOption.ExactFirst]);
			}
		}
		return timeSeries;
	}
	throw new ArgumentException("Operator argument can not be null");
}

TimeSeries TimeSeriesPrivate::op_Subtraction(const TimeSeries& series, double Value)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		series.name(),
		"-",
		Value.ToString("F2"),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		timeSeries.Add(series.GetDateTime(i), series[i, 0] - Value);
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::op_Subtraction(double Value, const TimeSeries& series)
{
	if (series == null)
	{
		throw new ArgumentException("Operator argument can not be null");
	}
	TimeSeries timeSeries = new TimeSeries(string.Concat(new string[]
	{
		"(",
		Value.ToString("F2"),
		"-",
		series.name(),
		")"
	}), "");
	for (int i = 0; i < series.count(); i++)
	{
		timeSeries.Add(series.GetDateTime(i), Value - series[i, 0]);
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::pow(double Pow)
{
	TimeSeries timeSeries = base.GetType().GetConstructor(new Type[0]).Invoke(new object[0]) as TimeSeries;
	timeSeries.setName() = "Pow(" + m_name + ")";
	timeSeries.setDescription() = m_description;
	for (int i = 0; i < m_item; i++)
	{
		timeSeries.Add(GetDateTime(i), Math.Pow(this[i, 0], Pow));
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::shift(int offset)
{
	TimeSeries timeSeries = new TimeSeries(m_name, m_description);
	int num = 0;
	if (offset < 0)
	{
		num += Math.Abs(offset);
	}
	for (int i = num; i < m_item; i++)
	{
		int num2 = i + offset;
		if (num2 >= m_item)
		{
			break;
		}
		DateTime dateTime = GetDateTime(num2);
		double value = this[i];
		timeSeries[dateTime, SearchOption.ExactFirst] = value;
	}
	return timeSeries;
}

TimeSeries TimeSeriesPrivate::sqrt()
{
	TimeSeries timeSeries = base.GetType().GetConstructor(new Type[0]).Invoke(new object[0]) as TimeSeries;
	timeSeries.setName() = "Sqrt(" + m_name + ")";
	timeSeries.setDescription() = m_description;
	for (int i = 0; i < m_item; i++)
	{
		timeSeries.Add(GetDateTime(i), Math.Sqrt(this[i, 0]));
	}
	return timeSeries;
}


// Pubic API 

TimeSeries::TimeSeries()
	: d_ptr(new TimeSeriesPrivate)
{
}

TimeSeries::TimeSeries(const IDataSeries& series)
	: d_ptr(new TimeSeriesPrivate(series))
{
}

TimeSeries::TimeSeries(const QString& name, const QString& description)
	: d_ptr(new TimeSeriesPrivate(name, description))
{
}

TimeSeries::~TimeSeries()
{
}

TimeSeries::TimeSeries (TimeSeriesPrivate &dd)
	: d_ptr(&dd)
{
}

TimeSeries::TimeSeries (const TimeSeries &other)
	: d_ptr(other.d_ptr)
{
}

TimeSeries& TimeSeries::operator=(const TimeSeries &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool TimeSeries::operator==(const TimeSeries &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString TimeSeries::name() const
{
	return d_ptr->name();
}

QString TimeSeries::description() const
{
	return d_ptr->description();
}

int TimeSeries::count() const
{
	return d_ptr->count();
}

QList<Indicator> TimeSeries::indicators() const
{
	return d_ptr->indicators();
}

double TimeSeries::first() const
{
	return d_ptr->first();
}

double TimeSeries::last() const
{
	return d_ptr->last();
}

QDateTime TimeSeries::firstDateTime() const
{
	return d_ptr->firstDateTime();
}

QDateTime TimeSeries::lastDateTime() const
{
	return d_ptr->lastDateTime();
}

double TimeSeries::item(int index) const
{
	return d_ptr->item(index);
}

double TimeSeries::item(int index, BarData barData) const
{
	return d_ptr->item(index, barData);
}

double TimeSeries::item(int index, int row) const
{
	return d_ptr->item(index, row);
}

double TimeSeries::item(const QDateTime& dateTime, SearchOption option) const
{
	return d_ptr->item(dateTime, option);
}

void TimeSeries::setItem(const QDateTime& dateTime, SearchOption option, double value)
{
	d_ptr->setItem(dateTime, option, value);
}

double TimeSeries::item(const QDateTime& dateTime, int row, SearchOption option) const
{
	return d_ptr->item(dateTime, row, option);
}

void TimeSeries::add(const QDateTime& dateTime, double value)
{
	d_ptr->add(dateTime, value);
}

double TimeSeries::ago(int n)
{
	return d_ptr->ago(n);
}

void TimeSeries::clear()
{
	d_ptr->clear();
}

bool TimeSeries::contains(const QDateTime& dateTime)
{
	return d_ptr->contains(dateTime);
}

Cross TimeSeries::crosses(double level, int index)
{
	return d_ptr->crosses(level, index);
}

Cross TimeSeries::crosses(const TimeSeries& series, const QDateTime& dateTime)
{
	return d_ptr->crosses(series, dateTime);
}

TimeSeries TimeSeries::exp()
{
	return d_ptr->exp();
}

double TimeSeries::getAsymmetry(int index1, int index2, int row)
{
	return d_ptr->getAsymmetry(index1, index2, row);
}

double TimeSeries::getAutoCorrelation(int Lag)
{
	return d_ptr->getAutoCorrelation(Lag);
}

double TimeSeries::getAutoCovariance(int Lag)
{
	return d_ptr->getAutoCovariance(Lag);
}

TimeSeriesItem TimeSeries::getByDateTime(const QDateTime& dateTime, SearchOption option)
{
	return d_ptr->getByDateTime(dateTime, option);
}

double TimeSeries::getCorrelation(int row1, int row2, int index1, int index2)
{
	return d_ptr->getCorrelation(row1, row2, index1, index2);
}

double TimeSeries::getCorrelation(const TimeSeries& series)
{
	return d_ptr->getCorrelation(series);
}

double TimeSeries::getCovariance(int row1, int row2, int index1, int index2)
{
	return d_ptr->getCovariance(row1, row2, index1, index2);
}

double TimeSeries::getCovariance(const TimeSeries& series)
{
	return d_ptr->getCovariance(series);
}

QDateTime TimeSeries::getDateTime(int index)
{
	return d_ptr->getDateTime(index);
}

double TimeSeries::getExcess(int index1, int index2, int row)
{
	return d_ptr->getExcess(index1, index2, row);
}

int TimeSeries::getIndex(const QDateTime& datetime, IndexOption option)
{
	return d_ptr->getIndex(datetime, option);
}

TimeSeriesItem TimeSeries::getItem(int index)
{
	return d_ptr->getItem(index);
}

double TimeSeries::getMax()
{
	return d_ptr->getMax();
}

double TimeSeries::getMax(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMax(dateTime1, dateTime2);
}

double TimeSeries::getMax(int index1, int index2, BarData barData)
{
	return d_ptr->getMax(index1, index2, barData);
}

double TimeSeries::getMax(int index1, int index2)
{
	return d_ptr->getMax(index1, index2);
}

TimeSeriesItem TimeSeries::getMaxItem()
{
	return d_ptr->getMaxItem();
}

double TimeSeries::getMean()
{
	return d_ptr->getMean();
}

double TimeSeries::getMean(int index1, int index2)
{
	return d_ptr->getMean(index1, index2);
}

double TimeSeries::getMean(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMean(dateTime1, dateTime2);
}

double TimeSeries::getMean(int row)
{
	return d_ptr->getMean(row);
}

double TimeSeries::getMean(int index1, int index2, int row)
{
	return d_ptr->getMean(index1, index2, row);
}

double TimeSeries::getMean(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getMean(dateTime1, dateTime2, row);
}

double TimeSeries::getMedian(int index1, int index2)
{
	return d_ptr->getMedian(index1, index2);
}

double TimeSeries::getMedian(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMedian(dateTime1, dateTime2);
}

double TimeSeries::getMedian(int row)
{
	return d_ptr->getMedian(row);
}

double TimeSeries::getMedian()
{
	return d_ptr->getMedian();
}

double TimeSeries::getMedian(int index1, int index2, int row)
{
	return d_ptr->getMedian(index1, index2, row);
}

double TimeSeries::getMedian(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getMedian(dateTime1, dateTime2, row);
}

double TimeSeries::getMin()
{
	return d_ptr->getMin();
}

double TimeSeries::getMin(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMin(dateTime1, dateTime2);
}

double TimeSeries::getMin(int index1, int index2, BarData barData)
{
	return d_ptr->getMin(index1, index2, barData);
}

double TimeSeries::getMin(int index1, int index2)
{
	return d_ptr->getMin(index1, index2);
}

TimeSeriesItem TimeSeries::getMinItem()
{
	return d_ptr->getMinItem();
}

double TimeSeries::getMoment(int k, int index1, int index2, int row)
{
	return d_ptr->getMoment(k, index1, index2, row);
}

TimeSeries TimeSeries::getNegativeSeries()
{
	return d_ptr->getNegativeSeries();
}

double TimeSeries::getNegativeStdDev()
{
	return d_ptr->getNegativeStdDev();
}

double TimeSeries::getNegativeStdDev(int index1, int index2)
{
	return d_ptr->getNegativeStdDev(index1, index2);
}

double TimeSeries::getNegativeStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getNegativeStdDev(dateTime1, dateTime2);
}

double TimeSeries::getNegativeStdDev(int row)
{
	return d_ptr->getNegativeStdDev(row);
}

double TimeSeries::getNegativeStdDev(int index1, int index2, int row)
{
	return d_ptr->getNegativeStdDev(index1, index2, row);
}

double TimeSeries::getNegativeStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getNegativeStdDev(dateTime1, dateTime2, row);
}

double TimeSeries::getNegativeVariance()
{
	return d_ptr->getNegativeVariance();
}

double TimeSeries::getNegativeVariance(int index1, int index2)
{
	return d_ptr->getNegativeVariance(index1, index2);
}

double TimeSeries::getNegativeVariance(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getNegativeVariance(dateTime1, dateTime2);
}

double TimeSeries::getNegativeVariance(int row)
{
	return d_ptr->getNegativeVariance(row);
}

double TimeSeries::getNegativeVariance(int index1, int index2, int row)
{
	return d_ptr->getNegativeVariance(index1, index2, row);
}

double TimeSeries::getNegativeVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getNegativeVariance(dateTime1, dateTime2, row);
}

TimeSeries TimeSeries::getPercentReturnSeries()
{
	return d_ptr->getPercentReturnSeries();
}

TimeSeries TimeSeries::getPositiveSeries()
{
	return d_ptr->getPositiveSeries();
}

double TimeSeries::getPositiveStdDev()
{
	return d_ptr->getPositiveStdDev();
}

double TimeSeries::getPositiveStdDev(int index1, int index2)
{
	return d_ptr->getPositiveStdDev(index1, index2);
}

double TimeSeries::getPositiveStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getPositiveStdDev(dateTime1, dateTime2);
}

double TimeSeries::getPositiveStdDev(int row)
{
	return d_ptr->getPositiveStdDev(row);
}

double TimeSeries::getPositiveStdDev(int index1, int index2, int row)
{
	return d_ptr->getPositiveStdDev(index1, index2, row);
}

double TimeSeries::getPositiveStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getPositiveStdDev(dateTime1, dateTime2, row);
}

double TimeSeries::getPositiveVariance()
{
	return d_ptr->getPositiveVariance();
}

double TimeSeries::getPositiveVariance(int index1, int index2, int row)
{
	return d_ptr->getPositiveVariance(index1, index2, row);
}

double TimeSeries::getPositiveVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getPositiveVariance(dateTime1, dateTime2, row);
}

double TimeSeries::getPositiveVariance(int index1, int index2)
{
	return d_ptr->getPositiveVariance(index1, index2);
}

double TimeSeries::getPositiveVariance(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getPositiveVariance(dateTime1, dateTime2);
}

double TimeSeries::getPositiveVariance(int row)
{
	return d_ptr->getPositiveVariance(row);
}

TimeSeries TimeSeries::getReturnSeries()
{
	return d_ptr->getReturnSeries();
}

double TimeSeries::getStdDev()
{
	return d_ptr->getStdDev();
}

double TimeSeries::getStdDev(int index1, int index2)
{
	return d_ptr->getStdDev(index1, index2);
}

double TimeSeries::getStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getStdDev(dateTime1, dateTime2);
}

double TimeSeries::getStdDev(int row)
{
	return d_ptr->getStdDev(row);
}

double TimeSeries::getStdDev(int index1, int index2, int row)
{
	return d_ptr->getStdDev(index1, index2, row);
}

double TimeSeries::getStdDev(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getStdDev(dateTime1, dateTime2, row);
}

double TimeSeries::getSum()
{
	return d_ptr->getSum();
}

double TimeSeries::getSum(int index1, int index2, int row)
{
	return d_ptr->getSum(index1, index2, row);
}

double TimeSeries::getValue(int index)
{
	return d_ptr->getValue(index);
}

double TimeSeries::getVariance()
{
	return d_ptr->getVariance();
}

double TimeSeries::getVariance(int index1, int index2)
{
	return d_ptr->getVariance(index1, index2);
}

double TimeSeries::getVariance(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getVariance(dateTime1, dateTime2);
}

double TimeSeries::getVariance(int row)
{
	return d_ptr->getVariance(row);
}

double TimeSeries::getVariance(int index1, int index2, int row)
{
	return d_ptr->getVariance(index1, index2, row);
}

double TimeSeries::getVariance(const QDateTime& dateTime1, const QDateTime& dateTime2, int row)
{
	return d_ptr->getVariance(dateTime1, dateTime2, row);
}

int TimeSeries::indexOf(const QDateTime& dateTime, SearchOption option)
{
	return d_ptr->indexOf(dateTime, option);
}

TimeSeries TimeSeries::log()
{
	return d_ptr->log();
}

TimeSeries TimeSeries::log10()
{
	return d_ptr->log10();
}

TimeSeries TimeSeries::op_Addition(const TimeSeries& series1, const TimeSeries& series2)
{
	return d_ptr->op_Addition(series1, series2);
}

TimeSeries TimeSeries::op_Addition(const TimeSeries& series, double Value)
{
	return d_ptr->op_Addition(series, Value);
}

TimeSeries TimeSeries::op_Addition(double Value, const TimeSeries& series)
{
	return d_ptr->op_Addition(Value, series);
}

TimeSeries TimeSeries::op_Division(const TimeSeries& series1, const TimeSeries& series2)
{
	return d_ptr->op_Division(series1, series2);
}

TimeSeries TimeSeries::op_Division(const TimeSeries& series, double Value)
{
	return d_ptr->op_Division(series, Value);
}

TimeSeries TimeSeries::op_Division(double Value, const TimeSeries& series)
{
	return d_ptr->op_Division(Value, series);
}

TimeSeries TimeSeries::op_Multiply(const TimeSeries& series1, const TimeSeries& series2)
{
	return d_ptr->op_Multiply(series1, series2);
}

TimeSeries TimeSeries::op_Multiply(const TimeSeries& series, double Value)
{
	return d_ptr->op_Multiply(series, Value);
}

TimeSeries TimeSeries::op_Multiply(double Value, const TimeSeries& series)
{
	return d_ptr->op_Multiply(Value, series);
}

TimeSeries TimeSeries::op_Subtraction(const TimeSeries& series1, const TimeSeries& series2)
{
	return d_ptr->op_Subtraction(series1, series2);
}

TimeSeries TimeSeries::op_Subtraction(const TimeSeries& series, double Value)
{
	return d_ptr->op_Subtraction(series, Value);
}

TimeSeries TimeSeries::op_Subtraction(double Value, const TimeSeries& series)
{
	return d_ptr->op_Subtraction(Value, series);
}

TimeSeries TimeSeries::pow(double Pow)
{
	return d_ptr->pow(Pow);
}

void TimeSeries::remove(int index)
{
	d_ptr->remove(index);
}

TimeSeries TimeSeries::shift(int offset)
{
	return d_ptr->shift(offset);
}

TimeSeries TimeSeries::sqrt()
{
	return d_ptr->sqrt();
}

QDebug operator<<(QDebug dbg, const TimeSeries& timeseries)
{
	return dbg << timeseries.toString();
}

