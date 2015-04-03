#include <QuantKit/QuoteSeries.h>

#include <QuantKit/Event/Quote.h>
#include "DataObject_p.h"

namespace QuantKit {

class QuoteSeriesPrivate : public QSharedData
{
public:
	QString m_name;
	QString m_description;
	QList<Quote> m_smartQuant.IDataSeries.Item;

public:
	explicit QuoteSeriesPrivate(const QString& name);
	virtual ~QuoteSeriesPrivate();

public:
	QString name() const { return m_name; }
	QString description() const { return m_description; }
	int count() const
	{
		return m_smartQuant.IDataSeries.Item.Count;
	}

	QDateTime firstDateTime() const;
	QDateTime lastDateTime() const;
	Quote item(int index) const
	{
		return m_smartQuant.IDataSeries.Item[index];
	}

	void add(const Quote& quote)
	{
		m_smartQuant.IDataSeries.Item.Add(quote);
	}

	void clear()
	{
		m_smartQuant.IDataSeries.Item.Clear();
	}

	bool contains(const QDateTime& dateTime)
	{
		return GetIndex(dateTime, IndexOption.Null) != -1;
	}

	int getIndex(const QDateTime& datetime, IndexOption option);
	virtual QuoteSeriesPrivate* clone() Q_DECL_OVERRIDE { return new QuoteSeriesPrivate(*this); }
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

	void smartQuant.IDataSeries.Add(const DataObject& obj) { Add((Quote)obj); }
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

QuoteSeriesPrivate::QuoteSeriesPrivate(const QString& name)
	: m_name(name)
	, m_smartQuant.IDataSeries.Item(new QList<Quote>())
{
}

QuoteSeriesPrivate::~QuoteSeriesPrivate ()
{
}

QDateTime QuoteSeriesPrivate::firstDateTime() const
{
	if (m_smartQuant.IDataSeries.Item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_smartQuant.IDataSeries.Item[0].dateTime();
}

QDateTime QuoteSeriesPrivate::lastDateTime() const
{
	if (m_smartQuant.IDataSeries.Item <= 0)
	{
		throw new ApplicationException("Array has no elements");
	}
	return m_smartQuant.IDataSeries.Item[m_smartQuant.IDataSeries.Item - 1].dateTime();
}

int QuoteSeriesPrivate::getIndex(const QDateTime& datetime, IndexOption option)
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

long QuoteSeriesPrivate::smartQuant.IDataSeries.GetIndex(const QDateTime& dateTime, SearchOption option)
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

QuoteSeries::QuoteSeries(const QString& name)
	: d_ptr(new QuoteSeriesPrivate(name))
{
}

QuoteSeries::~QuoteSeries()
{
}

QuoteSeries::QuoteSeries (const QuoteSeries &other)
	: d_ptr(other.d_ptr)
{
}

QuoteSeries& QuoteSeries::operator=(const QuoteSeries &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool QuoteSeries::operator==(const QuoteSeries &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString QuoteSeries::name() const
{
	return d_ptr->name();
}

QString QuoteSeries::description() const
{
	return d_ptr->description();
}

int QuoteSeries::count() const
{
	return d_ptr->count();
}

QDateTime QuoteSeries::firstDateTime() const
{
	return d_ptr->firstDateTime();
}

QDateTime QuoteSeries::lastDateTime() const
{
	return d_ptr->lastDateTime();
}

Quote QuoteSeries::item(int index) const
{
	return d_ptr->item(index);
}

void QuoteSeries::add(const Quote& quote)
{
	d_ptr->add(quote);
}

void QuoteSeries::clear()
{
	d_ptr->clear();
}

bool QuoteSeries::contains(const QDateTime& dateTime)
{
	return d_ptr->contains(dateTime);
}

int QuoteSeries::getIndex(const QDateTime& datetime, IndexOption option)
{
	return d_ptr->getIndex(datetime, option);
}

QDebug operator<<(QDebug dbg, const QuoteSeries& quoteseries)
{
	return dbg << quoteseries.toString();
}

