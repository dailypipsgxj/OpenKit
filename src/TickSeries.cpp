#include <QuantKit/TickSeries.h>

#include "Tick_p.h"
#include "DataObject_p.h"
#include <QuantKit/BarSeries.h>

namespace QuantKit {

class TickSeriesPrivate : public QSharedData
{
public:
	QString m_name;
	QString m_description;
	QList<Tick> m_smartQuant.IDataSeries.Item;
	Tick tick_0;
	Tick tick_1;

public:
	explicit TickSeriesPrivate(const QString& name);
	virtual ~TickSeriesPrivate();

public:
	QString name() const { return m_name; }
	QString description() const { return m_description; }
	int count() const
	{
		return m_smartQuant.IDataSeries.Item.Count;
	}

	QDateTime firstDateTime() const;
	QDateTime lastDateTime() const;
	Tick item(int index) const
	{
		return m_smartQuant.IDataSeries.Item[index];
	}

	void add(const Tick& tick);
	void clear();
	BarSeries compress(BarType barType, long barSize);
	bool contains(const QDateTime& dateTime)
	{
		return GetIndex(dateTime, IndexOption.Null) != -1;
	}

	int getIndex(const QDateTime& datetime, IndexOption option);
	Tick getMax() { return tick_1; }
	Tick getMax(const QDateTime& dateTime1, const QDateTime& dateTime2);
	Tick getMin() { return tick_0; }
	Tick getMin(const QDateTime& dateTime1, const QDateTime& dateTime2);
	virtual TickSeriesPrivate* clone() Q_DECL_OVERRIDE { return new TickSeriesPrivate(*this); }
//private:
	long tQuant.IDataSeries.get_Count() const
	{
		return (long)m_smartQuant.IDataSeries.Item.Count;
	}

	QDateTime tQuant.IDataSeries.get_DateTime1() const { return firstDateTime(); }
	QDateTime tQuant.IDataSeries.get_DateTime2() const { return lastDateTime(); }
	DataObject tQuant.IDataSeries.get_Item(long index) const
	{
		return m_smartQuant.IDataSeries.Item[(int)index];
	}

	void smartQuant.IDataSeries.Add(const DataObject& obj) { Add((Tick)obj); }
	long smartQuant.IDataSeries.GetIndex(const QDateTime& dateTime, SearchOption option);
	void smartQuant.IDataSeries.Remove(long index)
	{
		m_smartQuant.IDataSeries.Item.RemoveAt((int)index);
	}

	IEnumerator system.Collections.IEnumerable.GetEnumerator()
	{
		return m_smartQuant.IDataSeries.Item.GetEnumerator();
	}

};

} // namepsace QuantKit


using namespace QuantKit;

TickSeriesPrivate::TickSeriesPrivate(const QString& name)
	: m_name(name)
	, m_smartQuant.IDataSeries.Item(new QList<Tick>())
	, tick_0(null)
	, tick_1(null)
{
}

TickSeriesPrivate::~TickSeriesPrivate ()
{
}

QDateTime TickSeriesPrivate::firstDateTime() const
{
	if (m_smartQuant.IDataSeries.Item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_smartQuant.IDataSeries.Item[0].dateTime();
}

QDateTime TickSeriesPrivate::lastDateTime() const
{
	if (m_smartQuant.IDataSeries.Item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_smartQuant.IDataSeries.Item[m_smartQuant.IDataSeries.Item - 1].dateTime();
}

void TickSeriesPrivate::add(const Tick& tick)
{
	if (tick_0 == null)
	{
		tick_0 = tick;
	}
	else
	{
		if (tick.price() < tick_0.price())
		{
			tick_0 = tick;
		}
	}
	if (tick_1 == null)
	{
		tick_1 = tick;
	}
	else
	{
		if (tick.price() > tick_1.price())
		{
			tick_1 = tick;
		}
	}
	m_smartQuant.IDataSeries.Item.Add(tick);
}

void TickSeriesPrivate::clear()
{
	m_smartQuant.IDataSeries.Item.Clear();
	tick_0 = null;
	tick_1 = null;
}

BarSeries TickSeriesPrivate::compress(BarType barType, long barSize)
{
	if (m_smartQuant.IDataSeries.Item == 0)
	{
		return new BarSeries("", "", -1);
	}
	Tick tick = this[0];
	Class33 @class = Class33.smethod_0(tick.instrumentId(), barType, 1L, barSize);
	return @class.method_3(new Class39(this));
}

int TickSeriesPrivate::getIndex(const QDateTime& datetime, IndexOption option)
{
	int num = 0;
	int num2 = 0;
	int num3 = m_smartQuant.IDataSeries.Item.Count - 1;
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
				if (m_smartQuant.IDataSeries.Item[num].entryDate() == datetime)
				{
					flag = false;
				}
				else
				{
					if (m_smartQuant.IDataSeries.Item[num].entryDate() > datetime)
					{
						num3 = num - 1;
					}
					else
					{
						if (m_smartQuant.IDataSeries.Item[num].entryDate() < datetime)
						{
							num2 = num + 1;
						}
					}
				}
				break;
			case IndexOption.Next:
				if (m_smartQuant.IDataSeries.Item[num].entryDate() >= datetime && (num == 0 || m_smartQuant.IDataSeries.Item[num - 1].entryDate() < datetime))
				{
					flag = false;
				}
				else
				{
					if (m_smartQuant.IDataSeries.Item[num].entryDate() < datetime)
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
				if (m_smartQuant.IDataSeries.Item[num].entryDate() <= datetime && (num == m_smartQuant.IDataSeries.Item.Count - 1 || m_smartQuant.IDataSeries.Item[num + 1].entryDate() > datetime))
				{
					flag = false;
				}
				else
				{
					if (m_smartQuant.IDataSeries.Item[num].entryDate() > datetime)
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

Tick TickSeriesPrivate::getMax(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	Tick tick = null;
	for (int i = 0; i < m_smartQuant.IDataSeries.Item.Count; i++)
	{
		Tick tick2 = m_smartQuant.IDataSeries.Item[i];
		if (!(tick2.entryDate() < dateTime1))
		{
			if (tick2.entryDate() > dateTime2)
			{
				return tick;
			}
			if (tick == null)
			{
				tick = tick2;
			}
			else
			{
				if (tick2.price() > tick.price())
				{
					tick = tick2;
				}
			}
		}
	}
	return tick;
}

Tick TickSeriesPrivate::getMin(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	Tick tick = null;
	for (int i = 0; i < m_smartQuant.IDataSeries.Item.Count; i++)
	{
		Tick tick2 = m_smartQuant.IDataSeries.Item[i];
		if (!(tick2.entryDate() < dateTime1))
		{
			if (tick2.entryDate() > dateTime2)
			{
				return tick;
			}
			if (tick == null)
			{
				tick = tick2;
			}
			else
			{
				if (tick2.price() < tick.price())
				{
					tick = tick2;
				}
			}
		}
	}
	return tick;
}

long TickSeriesPrivate::smartQuant.IDataSeries.GetIndex(const QDateTime& dateTime, SearchOption option)
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

TickSeries::TickSeries(const QString& name)
	: d_ptr(new TickSeriesPrivate(name))
{
}

TickSeries::~TickSeries()
{
}

TickSeries::TickSeries (const TickSeries &other)
	: d_ptr(other.d_ptr)
{
}

TickSeries& TickSeries::operator=(const TickSeries &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool TickSeries::operator==(const TickSeries &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString TickSeries::name() const
{
	return d_ptr->name();
}

QString TickSeries::description() const
{
	return d_ptr->description();
}

int TickSeries::count() const
{
	return d_ptr->count();
}

QDateTime TickSeries::firstDateTime() const
{
	return d_ptr->firstDateTime();
}

QDateTime TickSeries::lastDateTime() const
{
	return d_ptr->lastDateTime();
}

Tick TickSeries::item(int index) const
{
	return d_ptr->item(index);
}

void TickSeries::add(const Tick& tick)
{
	d_ptr->add(tick);
}

void TickSeries::clear()
{
	d_ptr->clear();
}

BarSeries TickSeries::compress(BarType barType, long barSize)
{
	return d_ptr->compress(barType, barSize);
}

bool TickSeries::contains(const QDateTime& dateTime)
{
	return d_ptr->contains(dateTime);
}

int TickSeries::getIndex(const QDateTime& datetime, IndexOption option)
{
	return d_ptr->getIndex(datetime, option);
}

Tick TickSeries::getMax()
{
	return d_ptr->getMax();
}

Tick TickSeries::getMax(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMax(dateTime1, dateTime2);
}

Tick TickSeries::getMin()
{
	return d_ptr->getMin();
}

Tick TickSeries::getMin(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getMin(dateTime1, dateTime2);
}

QDebug operator<<(QDebug dbg, const TickSeries& tickseries)
{
	return dbg << tickseries.toString();
}

