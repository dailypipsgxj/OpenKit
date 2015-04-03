#include <QuantKit/FillSeries.h>

#include <QuantKit/Event/Fill.h>

namespace QuantKit {

class FillSeriesPrivate : public QSharedData
{
public:
	QString nqouargXjn;
	QList<Fill> m_item;
	Fill m_min;
	Fill m_max;

public:
	explicit FillSeriesPrivate(const QString& name);
	virtual ~FillSeriesPrivate();

public:
	int count() const { return m_item.Count; }
	Fill min() const { return m_min; }
	Fill max() const { return m_max; }
	Fill item(int index) const { return m_item[index]; }
	void add(const Fill& fill);
	void clear();
	int getIndex(const QDateTime& datetime, IndexOption option);
	virtual FillSeriesPrivate* clone() Q_DECL_OVERRIDE { return new FillSeriesPrivate(*this); }
//private:
	IEnumerator system.Collections.IEnumerable.GetEnumerator() { return m_item.GetEnumerator(); }
};

} // namepsace QuantKit


using namespace QuantKit;

FillSeriesPrivate::FillSeriesPrivate(const QString& name)
	: nqouargXjn(name)
	, m_item(new QList<Fill>())
	, m_min(null)
	, m_max(null)
{
}

FillSeriesPrivate::~FillSeriesPrivate ()
{
}

void FillSeriesPrivate::add(const Fill& fill)
{
	if (m_min == null)
	{
		m_min = fill;
	}
	else
	{
		if (fill.entryPrice() < m_min.entryPrice())
		{
			m_min = fill;
		}
	}
	if (m_max == null)
	{
		m_max = fill;
	}
	else
	{
		if (fill.entryPrice() > m_max.entryPrice())
		{
			m_max = fill;
		}
	}
	if (m_item.Count != 0 && fill.entryDate() < m_item[m_item.Count - 1].entryDate())
	{
		Console.WriteLine(string.Concat(new object[]
		{
			"FillSeries::Add (",
			nqouargXjn,
			" + incorrect fill order : ",
			fill
		}));
	}
	m_item.Add(fill);
}

void FillSeriesPrivate::clear()
{
	m_item.Clear();
	m_min = null;
	m_max = null;
}

int FillSeriesPrivate::getIndex(const QDateTime& datetime, IndexOption option)
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


// Pubic API 

FillSeries::FillSeries(const QString& name)
	: d_ptr(new FillSeriesPrivate(name))
{
}

FillSeries::~FillSeries()
{
}

FillSeries::FillSeries (const FillSeries &other)
	: d_ptr(other.d_ptr)
{
}

FillSeries& FillSeries::operator=(const FillSeries &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool FillSeries::operator==(const FillSeries &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int FillSeries::count() const
{
	return d_ptr->count();
}

Fill FillSeries::min() const
{
	return d_ptr->min();
}

Fill FillSeries::max() const
{
	return d_ptr->max();
}

Fill FillSeries::item(int index) const
{
	return d_ptr->item(index);
}

void FillSeries::add(const Fill& fill)
{
	d_ptr->add(fill);
}

void FillSeries::clear()
{
	d_ptr->clear();
}

int FillSeries::getIndex(const QDateTime& datetime, IndexOption option)
{
	return d_ptr->getIndex(datetime, option);
}

QDebug operator<<(QDebug dbg, const FillSeries& fillseries)
{
	return dbg << fillseries.toString();
}

