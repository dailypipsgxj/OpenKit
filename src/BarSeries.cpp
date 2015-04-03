#include <QuantKit/BarSeries.h>

#include "Indicator_p.h"
#include <QuantKit/Event/Bar.h>
#include "DataObject_p.h"

namespace QuantKit {

class BarSeriesPrivate : public QSharedData
{
public:
	QString m_name;
	QString m_description;
	QList<Bar> m_item;
	QList<Indicator> m_indicators;
	Bar bar_0;
	Bar bar_1;
	int m_maxLength;

public:
	explicit BarSeriesPrivate(int maxLength);
	BarSeriesPrivate(const QString& name, const QString& description, int maxLength);
	virtual ~BarSeriesPrivate();

public:
	QString name() const { return m_name; }
	QString description() const { return m_description; }
	int count() const { return m_item.Count; }
	int maxLength() const { return m_maxLength; }
	void setMaxLength(int value);
	QList<Indicator> indicators() const { return m_indicators; }
	QDateTime firstDateTime() const;
	QDateTime lastDateTime() const;
	Bar first() const;
	Bar last() const;
	Bar item(int index) const { return m_item[index]; }
	Bar item(const QDateTime& dateTime, IndexOption option) const
	{
		return m_item[GetIndex(dateTime, option)];
	}

	double item(int index, BarData barData) const;
	void add(const Bar& bar);
	Bar ago(int n);
	void clear();
	BarSeries compress(long barSize);
	bool contains(const QDateTime& dateTime)
	{
		return GetIndex(dateTime, IndexOption.Null) != -1;
	}

	QDateTime getDateTime(int index)
	{
		return m_item[index].entryDate();
	}

	int getIndex(const QDateTime& datetime, IndexOption option);
	Bar getMax() { return bar_1; }
	double getMax(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMax(int index1, int index2, BarData barData);
	Bar getMin() { return bar_0; }
	double getMin(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double getMin(int index1, int index2, BarData barData);
	double highestHigh(int index1, int index2)
	{
		return HighestHighBar(index1, index2).high();
	}

	double highestHigh(int nBars)
	{
		return HighestHighBar(nBars).high();
	}

	double highestHigh(const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return HighestHighBar(dateTime1, dateTime2).high();
	}

	double highestHigh() { return bar_1.high(); }
	Bar highestHighBar(int index1, int index2);
	Bar highestHighBar(int nBars)
	{
		return HighestHighBar(m_item - nBars, m_item - 1);
	}

	Bar highestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Bar highestHighBar() { return bar_1; }
	double highestLow(int index1, int index2)
	{
		return HighestLowBar(index1, index2).low();
	}

	double highestLow(int nBars)
	{
		return HighestLowBar(nBars).low();
	}

	double highestLow(const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return HighestLowBar(dateTime1, dateTime2).low();
	}

	Bar highestLowBar(int index1, int index2);
	Bar highestLowBar(int nBars)
	{
		return HighestLowBar(m_item - nBars, m_item - 1);
	}

	Bar highestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double lowestHigh(int index1, int index2)
	{
		return LowestHighBar(index1, index2).high();
	}

	double lowestHigh(int nBars)
	{
		return LowestHighBar(nBars).high();
	}

	double lowestHigh(const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return LowestHighBar(dateTime1, dateTime2).high();
	}

	Bar lowestHighBar(int index1, int index2);
	Bar lowestHighBar(int nBars)
	{
		return LowestHighBar(m_item - nBars, m_item - 1);
	}

	Bar lowestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	double lowestLow(int index1, int index2)
	{
		return LowestLowBar(index1, index2).low();
	}

	double lowestLow(int nBars)
	{
		return LowestLowBar(nBars).low();
	}

	double lowestLow(const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return LowestLowBar(dateTime1, dateTime2).low();
	}

	double lowestLow() { return bar_0.low(); }
	Bar lowestLowBar(int index1, int index2);
	Bar lowestLowBar(int nBars)
	{
		return LowestLowBar(m_item - nBars, m_item - 1);
	}

	Bar lowestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Bar lowestLowBar() { return bar_0; }
	virtual BarSeriesPrivate* clone() Q_DECL_OVERRIDE { return new BarSeriesPrivate(*this); }
//private:
	long tQuant.IDataSeries.get_Count() const { return (long)m_item.Count; }
	QDateTime tQuant.IDataSeries.get_DateTime1() const { return firstDateTime(); }
	QDateTime tQuant.IDataSeries.get_DateTime2() const { return lastDateTime(); }
	double tQuant.ISeries.get_First() const { return first().close(); }
	double tQuant.ISeries.get_Last() const { return last().close(); }
	DataObject tQuant.IDataSeries.get_Item(long index) const { return this[(int)index]; }
	double tQuant.ISeries.get_Item(int index) const
	{
		return this[index, BarData.Close];
	}

	void method_0();
	void smartQuant.IDataSeries.Add(const DataObject& obj) { Add((Bar)obj); }
	long smartQuant.IDataSeries.GetIndex(const QDateTime& dateTime, SearchOption option);
	void smartQuant.IDataSeries.Remove(long index) { m_item.RemoveAt((int)index); }
};

} // namepsace QuantKit


using namespace QuantKit;

BarSeriesPrivate::BarSeriesPrivate(int maxLength)
	: m_item(new QList<Bar>())
	, m_indicators(new QList<Indicator>())
	, m_maxLength(-1)
	, m_maxLength(maxLength)
{
}

BarSeriesPrivate::BarSeriesPrivate(const QString& name, const QString& description, int maxLength)
	: m_name(name)
	, m_description(description)
	, m_item(new QList<Bar>())
	, m_indicators(new QList<Indicator>())
	, m_maxLength(-1)
	, m_maxLength(maxLength)
{
}

BarSeriesPrivate::~BarSeriesPrivate ()
{
}

void BarSeriesPrivate::setMaxLength(int value)
{
	m_maxLength = value;
	if (m_maxLength != -1)
	{
		while (m_item > m_maxLength)
		{
			method_0();
		}
	}
}

QDateTime BarSeriesPrivate::firstDateTime() const
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_item[0].dateTime();
}

QDateTime BarSeriesPrivate::lastDateTime() const
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_item[m_item - 1].dateTime();
}

Bar BarSeriesPrivate::first() const
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return this[0];
}

Bar BarSeriesPrivate::last() const
{
	if (m_item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return this[m_item - 1];
}

double BarSeriesPrivate::item(int index, BarData barData) const
{
	switch (barData)
	{
		case BarData.Close:
			return m_item[index].close();
		case BarData.Open:
			return m_item[index].open();
		case BarData.High:
			return m_item[index].high();
		case BarData.Low:
			return m_item[index].low();
		case BarData.Median:
			return m_item[index].median();
		case BarData.Typical:
			return m_item[index].typical();
		case BarData.Weighted:
			return m_item[index].weighted();
		case BarData.Average:
			return m_item[index].average();
		case BarData.Volume:
			return (double)m_item[index].volume();
		case BarData.OpenInt:
			return (double)m_item[index].openInt();
		case BarData.Range:
			return m_item[index].range();
		case BarData.Mean:
			return m_item[index].mean();
		case BarData.Variance:
			return m_item[index].variance();
		case BarData.StdDev:
			return m_item[index].stdDev();
		default:
			throw new ArgumentException("Unknown BarData value " + barData);
	}
}

void BarSeriesPrivate::add(const Bar& bar)
{
	if (bar_0 == null)
	{
		bar_0 = bar;
	}
	else
	{
		if (bar.high() < bar_0.low())
		{
			bar_0 = bar;
		}
	}
	if (bar_1 == null)
	{
		bar_1 = bar;
	}
	else
	{
		if (bar.high() > bar_1.high())
		{
			bar_1 = bar;
		}
	}
	m_item.Add(bar);
	int @int = m_item.Count - 1;
	for (int i = 0; i < m_indicators.Count; i++)
	{
		m_indicators[i].method_0(@int);
	}
	if (m_maxLength != -1 && m_item > m_maxLength)
	{
		method_0();
	}
}

Bar BarSeriesPrivate::ago(int n)
{
	int num = m_item - 1 - n;
	if (num < 0)
	{
		throw new ArgumentException(string.Concat(new object[]
		{
			"BarSeries::Ago Can not return bar ",
			n,
			" bars ago: bar series is too short, count = ",
			m_item
		}));
	}
	return this[num];
}

void BarSeriesPrivate::clear()
{
	m_item.Clear();
	bar_0 = null;
	bar_1 = null;
	for (int i = 0; i < m_indicators.Count; i++)
	{
		m_indicators[i].Clear();
	}
	m_indicators.Clear();
}

BarSeries BarSeriesPrivate::compress(long barSize)
{
	if (m_item == 0)
	{
		return new BarSeries("", "", -1);
	}
	Bar bar = this[0];
	Class33 @class = Class33.smethod_0(bar.instrumentId(), bar.type(), bar.size(), barSize);
	return @class.method_3(new Class38(this));
}

int BarSeriesPrivate::getIndex(const QDateTime& datetime, IndexOption option)
{
	int num = 0;
	int num2 = 0;
	int num3 = m_item.Count - 1;
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
				if (m_item[num].entryDate() == datetime)
				{
					flag = false;
				}
				else
				{
					if (m_item[num].entryDate() > datetime)
					{
						num3 = num - 1;
					}
					else
					{
						if (m_item[num].entryDate() < datetime)
						{
							num2 = num + 1;
						}
					}
				}
				break;
			case IndexOption.Next:
				if (m_item[num].entryDate() >= datetime && (num == 0 || m_item[num - 1].entryDate() < datetime))
				{
					flag = false;
				}
				else
				{
					if (m_item[num].entryDate() < datetime)
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
				if (m_item[num].entryDate() <= datetime && (num == m_item.Count - 1 || m_item[num + 1].entryDate() > datetime))
				{
					flag = false;
				}
				else
				{
					if (m_item[num].entryDate() > datetime)
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

double BarSeriesPrivate::getMax(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	int index = GetIndex(dateTime1, IndexOption.Next);
	int index2 = GetIndex(dateTime2, IndexOption.Prev);
	if (index <= index2 && index != -1 && index2 != -1)
	{
		double num = -1.7976931348623157E+308;
		for (int i = index; i <= index2; i++)
		{
			Bar bar = m_item[i];
			if (num < bar.high())
			{
				num = bar.high();
			}
		}
		return num;
	}
	return double.NaN;
}

double BarSeriesPrivate::getMax(int index1, int index2, BarData barData)
{
	if (index1 <= index2 && index1 != -1 && index2 != -1)
	{
		double num = -1.7976931348623157E+308;
		for (int i = index1; i <= index2; i++)
		{
			double num2 = this[i, barData];
			if (num < num2)
			{
				num = num2;
			}
		}
		return num;
	}
	return double.NaN;
}

double BarSeriesPrivate::getMin(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	int index = GetIndex(dateTime1, IndexOption.Next);
	int index2 = GetIndex(dateTime2, IndexOption.Prev);
	if (index <= index2 && index != -1 && index2 != -1)
	{
		double num = 1.7976931348623157E+308;
		for (int i = index; i <= index2; i++)
		{
			Bar bar = m_item[i];
			if (num > bar.low())
			{
				num = bar.low();
			}
		}
		return num;
	}
	return double.NaN;
}

double BarSeriesPrivate::getMin(int index1, int index2, BarData barData)
{
	if (index1 <= index2 && index1 != -1 && index2 != -1)
	{
		double num = 1.7976931348623157E+308;
		for (int i = index1; i <= index2; i++)
		{
			double num2 = this[i, barData];
			if (num > num2)
			{
				num = num2;
			}
		}
		return num;
	}
	return double.NaN;
}

Bar BarSeriesPrivate::highestHighBar(int index1, int index2)
{
	if (m_item == 0)
	{
		return null;
	}
	if (index1 > index2)
	{
		return null;
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		return null;
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		Bar bar = m_item[index1];
		for (int i = index1 + 1; i <= index2; i++)
		{
			if (m_item[i].high() > bar.high())
			{
				bar = m_item[i];
			}
		}
		return bar;
	}
	return null;
}

Bar BarSeriesPrivate::highestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	int index = GetIndex(dateTime1, IndexOption.Next);
	int index2 = GetIndex(dateTime2, IndexOption.Prev);
	return HighestHighBar(index, index2);
}

Bar BarSeriesPrivate::highestLowBar(int index1, int index2)
{
	if (m_item == 0)
	{
		return null;
	}
	if (index1 > index2)
	{
		return null;
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		return null;
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		Bar bar = m_item[index1];
		for (int i = index1 + 1; i <= index2; i++)
		{
			if (m_item[i].low() > bar.low())
			{
				bar = m_item[i];
			}
		}
		return bar;
	}
	return null;
}

Bar BarSeriesPrivate::highestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	int index = GetIndex(dateTime1, IndexOption.Next);
	int index2 = GetIndex(dateTime2, IndexOption.Prev);
	return HighestLowBar(index, index2);
}

Bar BarSeriesPrivate::lowestHighBar(int index1, int index2)
{
	if (m_item == 0)
	{
		return null;
	}
	if (index1 > index2)
	{
		return null;
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		return null;
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		Bar bar = m_item[index1];
		for (int i = index1 + 1; i <= index2; i++)
		{
			if (m_item[i].high() < bar.high())
			{
				bar = m_item[i];
			}
		}
		return bar;
	}
	return null;
}

Bar BarSeriesPrivate::lowestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	int index = GetIndex(dateTime1, IndexOption.Next);
	int index2 = GetIndex(dateTime2, IndexOption.Prev);
	return LowestHighBar(index, index2);
}

Bar BarSeriesPrivate::lowestLowBar(int index1, int index2)
{
	if (m_item == 0)
	{
		return null;
	}
	if (index1 > index2)
	{
		return null;
	}
	if (index1 < 0 || index1 > m_item - 1)
	{
		return null;
	}
	if (index2 >= 0 && index2 <= m_item - 1)
	{
		Bar bar = m_item[index1];
		for (int i = index1 + 1; i <= index2; i++)
		{
			if (m_item[i].low() < bar.low())
			{
				bar = m_item[i];
			}
		}
		return bar;
	}
	return null;
}

Bar BarSeriesPrivate::lowestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	int index = GetIndex(dateTime1, IndexOption.Next);
	int index2 = GetIndex(dateTime2, IndexOption.Prev);
	return LowestLowBar(index, index2);
}

void BarSeriesPrivate::method_0()
{
	m_item.RemoveAt(0);
	for (int i = 0; i < m_indicators.Count; i++)
	{
		if (m_indicators[i].count() > 0)
		{
			m_indicators[i].Remove(0);
		}
	}
}

long BarSeriesPrivate::smartQuant.IDataSeries.GetIndex(const QDateTime& dateTime, SearchOption option)
{
	switch (option)
	{
		case SearchOption.Next:
			return (long)GetIndex(dateTime, IndexOption.Next);
		case SearchOption.Prev:
			return (long)GetIndex(dateTime, IndexOption.Prev);
		default:
			throw new ApplicationException("Unsupported search option");
	}
}


// Pubic API 

BarSeries::BarSeries(int maxLength)
	: d_ptr(new BarSeriesPrivate(maxLength))
{
}

BarSeries::BarSeries(const QString& name, const QString& description, int maxLength)
	: d_ptr(new BarSeriesPrivate(name, description, maxLength))
{
}

BarSeries::~BarSeries()
{
}

BarSeries::BarSeries (const BarSeries &other)
	: d_ptr(other.d_ptr)
{
}

BarSeries& BarSeries::operator=(const BarSeries &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BarSeries::operator==(const BarSeries &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString BarSeries::name() const
{
	return d_ptr->name();
}

QString BarSeries::description() const
{
	return d_ptr->description();
}

int BarSeries::count() const
{
	return d_ptr->count();
}

int BarSeries::maxLength() const
{
	return d_ptr->maxLength();
}

void BarSeries::setMaxLength(int value)
{
	d_ptr->setMaxLength(value);
}

QList<Indicator> BarSeries::indicators() const
{
	return d_ptr->indicators();
}

QDateTime BarSeries::firstDateTime() const
{
	return d_ptr->firstDateTime();
}

QDateTime BarSeries::lastDateTime() const
{
	return d_ptr->lastDateTime();
}

Bar BarSeries::first() const
{
	return d_ptr->first();
}

Bar BarSeries::last() const
{
	return d_ptr->last();
}

Bar BarSeries::item(int index) const
{
	return d_ptr->item(index);
}

Bar BarSeries::item(const QDateTime& dateTime, IndexOption option) const
{
	return d_ptr->item(dateTime, option);
}

double BarSeries::item(int index, BarData barData) const
{
	return d_ptr->item(index, barData);
}

void BarSeries::add(const Bar& bar)
{
	d_ptr->add(bar);
}

Bar BarSeries::ago(int n)
{
	return d_ptr->ago(n);
}

void BarSeries::clear()
{
	d_ptr->clear();
}

BarSeries BarSeries::compress(long barSize)
{
	return d_ptr->compress(barSize);
}

bool BarSeries::contains(const QDateTime& dateTime)
{
	return d_ptr->contains(dateTime);
}

QDateTime BarSeries::getDateTime(int index)
{
	return d_ptr->getDateTime(index);
}

int BarSeries::getIndex(const QDateTime& datetime, IndexOption option)
{
	return d_ptr->getIndex(datetime, option);
}

Bar BarSeries::getMax()
{
	return d_ptr->getMax();
}

double BarSeries::getMax(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMax(dateTime1, dateTime2);
}

double BarSeries::getMax(int index1, int index2, BarData barData)
{
	return d_ptr->getMax(index1, index2, barData);
}

Bar BarSeries::getMin()
{
	return d_ptr->getMin();
}

double BarSeries::getMin(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMin(dateTime1, dateTime2);
}

double BarSeries::getMin(int index1, int index2, BarData barData)
{
	return d_ptr->getMin(index1, index2, barData);
}

double BarSeries::highestHigh(int index1, int index2)
{
	return d_ptr->highestHigh(index1, index2);
}

double BarSeries::highestHigh(int nBars)
{
	return d_ptr->highestHigh(nBars);
}

double BarSeries::highestHigh(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->highestHigh(dateTime1, dateTime2);
}

double BarSeries::highestHigh()
{
	return d_ptr->highestHigh();
}

Bar BarSeries::highestHighBar(int index1, int index2)
{
	return d_ptr->highestHighBar(index1, index2);
}

Bar BarSeries::highestHighBar(int nBars)
{
	return d_ptr->highestHighBar(nBars);
}

Bar BarSeries::highestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->highestHighBar(dateTime1, dateTime2);
}

Bar BarSeries::highestHighBar()
{
	return d_ptr->highestHighBar();
}

double BarSeries::highestLow(int index1, int index2)
{
	return d_ptr->highestLow(index1, index2);
}

double BarSeries::highestLow(int nBars)
{
	return d_ptr->highestLow(nBars);
}

double BarSeries::highestLow(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->highestLow(dateTime1, dateTime2);
}

Bar BarSeries::highestLowBar(int index1, int index2)
{
	return d_ptr->highestLowBar(index1, index2);
}

Bar BarSeries::highestLowBar(int nBars)
{
	return d_ptr->highestLowBar(nBars);
}

Bar BarSeries::highestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->highestLowBar(dateTime1, dateTime2);
}

double BarSeries::lowestHigh(int index1, int index2)
{
	return d_ptr->lowestHigh(index1, index2);
}

double BarSeries::lowestHigh(int nBars)
{
	return d_ptr->lowestHigh(nBars);
}

double BarSeries::lowestHigh(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->lowestHigh(dateTime1, dateTime2);
}

Bar BarSeries::lowestHighBar(int index1, int index2)
{
	return d_ptr->lowestHighBar(index1, index2);
}

Bar BarSeries::lowestHighBar(int nBars)
{
	return d_ptr->lowestHighBar(nBars);
}

Bar BarSeries::lowestHighBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->lowestHighBar(dateTime1, dateTime2);
}

double BarSeries::lowestLow(int index1, int index2)
{
	return d_ptr->lowestLow(index1, index2);
}

double BarSeries::lowestLow(int nBars)
{
	return d_ptr->lowestLow(nBars);
}

double BarSeries::lowestLow(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->lowestLow(dateTime1, dateTime2);
}

double BarSeries::lowestLow()
{
	return d_ptr->lowestLow();
}

Bar BarSeries::lowestLowBar(int index1, int index2)
{
	return d_ptr->lowestLowBar(index1, index2);
}

Bar BarSeries::lowestLowBar(int nBars)
{
	return d_ptr->lowestLowBar(nBars);
}

Bar BarSeries::lowestLowBar(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->lowestLowBar(dateTime1, dateTime2);
}

Bar BarSeries::lowestLowBar()
{
	return d_ptr->lowestLowBar();
}

QDebug operator<<(QDebug dbg, const BarSeries& barseries)
{
	return dbg << barseries.toString();
}

