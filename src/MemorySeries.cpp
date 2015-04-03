#include <QuantKit/MemorySeries.h>

#include "DataObject_p.h"

namespace QuantKit {

class MemorySeriesPrivate : public QSharedData
{
public:
	QString m_name;
	QString m_description;
	QList<DataObject> m_item;

public:
	MemorySeriesPrivate();
	MemorySeriesPrivate(const QString& name, const QString& description);
	virtual ~MemorySeriesPrivate();

public:
	long count() const { return (long)m_item.Count; }
	QString name() const { return m_name; }
	QString description() const { return m_description; }
	QDateTime dateTime1() const { return m_item[0].entryDate(); }
	QDateTime dateTime2() const
	{
		return m_item[m_item.Count - 1].entryDate();
	}

	DataObject item(long index) const { return m_item[(int)index]; }
	void add(const DataObject& obj) { m_item.Add(obj); }
	void clear() { m_item.Clear(); }
	bool contains(const QDateTime& dateTime)
	{
		return GetIndex(dateTime, SearchOption.ExactFirst) != -1L;
	}

	long getIndex(const QDateTime& dateTime, SearchOption option);
	void remove(long index) { m_item.RemoveAt((int)index); }
	virtual MemorySeriesPrivate* clone() Q_DECL_OVERRIDE { return new MemorySeriesPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

MemorySeriesPrivate::MemorySeriesPrivate()
	: m_item(new QList<DataObject>())
{
}

MemorySeriesPrivate::MemorySeriesPrivate(const QString& name, const QString& description)
	: m_name(name)
	, m_description(description)
	, m_item(new QList<DataObject>())
{
}

MemorySeriesPrivate::~MemorySeriesPrivate ()
{
}

long MemorySeriesPrivate::getIndex(const QDateTime& dateTime, SearchOption option)
{
	int num = m_item.Count - 1;
	if (dateTime == m_item[num].entryDate())
	{
		return (long)num;
	}
	num = 0;
	int num2 = 0;
	int num3 = m_item.Count - 1;
	bool flag = true;
	while (flag)
	{
		if (num3 < num2)
		{
			return -1L;
		}
		num = (num2 + num3) / 2;
		switch (option)
		{
			case SearchOption.Next:
				if (m_item[num].entryDate() >= dateTime && (num == 0 || m_item[num - 1].entryDate() < dateTime))
				{
					flag = false;
				}
				else
				{
					if (m_item[num].entryDate() < dateTime)
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
				if (m_item[num].entryDate() <= dateTime && (num == m_item.Count - 1 || m_item[num + 1].entryDate() > dateTime))
				{
					flag = false;
				}
				else
				{
					if (m_item[num].entryDate() > dateTime)
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
				if (m_item[num].entryDate() == dateTime)
				{
					flag = false;
				}
				else
				{
					if (m_item[num].entryDate() > dateTime)
					{
						num3 = num - 1;
					}
					else
					{
						if (m_item[num].entryDate() < dateTime)
						{
							num2 = num + 1;
						}
					}
				}
				break;
		}
	}
	return (long)num;
}


// Pubic API 

MemorySeries::MemorySeries()
	: d_ptr(new MemorySeriesPrivate)
{
}

MemorySeries::MemorySeries(const QString& name, const QString& description)
	: d_ptr(new MemorySeriesPrivate(name, description))
{
}

MemorySeries::~MemorySeries()
{
}

MemorySeries::MemorySeries (const MemorySeries &other)
	: d_ptr(other.d_ptr)
{
}

MemorySeries& MemorySeries::operator=(const MemorySeries &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool MemorySeries::operator==(const MemorySeries &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

long MemorySeries::count() const
{
	return d_ptr->count();
}

QString MemorySeries::name() const
{
	return d_ptr->name();
}

QString MemorySeries::description() const
{
	return d_ptr->description();
}

QDateTime MemorySeries::dateTime1() const
{
	return d_ptr->dateTime1();
}

QDateTime MemorySeries::dateTime2() const
{
	return d_ptr->dateTime2();
}

DataObject MemorySeries::item(long index) const
{
	return d_ptr->item(index);
}

void MemorySeries::add(const DataObject& obj)
{
	d_ptr->add(obj);
}

void MemorySeries::clear()
{
	d_ptr->clear();
}

bool MemorySeries::contains(const QDateTime& dateTime)
{
	return d_ptr->contains(dateTime);
}

long MemorySeries::getIndex(const QDateTime& dateTime, SearchOption option)
{
	return d_ptr->getIndex(dateTime, option);
}

void MemorySeries::remove(long index)
{
	d_ptr->remove(index);
}

QDebug operator<<(QDebug dbg, const MemorySeries& memoryseries)
{
	return dbg << memoryseries.toString();
}

