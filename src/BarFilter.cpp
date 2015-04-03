#include <QuantKit/BarFilter.h>

#include <QuantKit/BarFilterItem.h>

namespace QuantKit {

class BarFilterPrivate : public QSharedData
{
public:
	QList<BarFilterItem> m_count;

public:
	BarFilterPrivate();
	virtual ~BarFilterPrivate();

public:
	QList<BarFilterItem> items() const { return m_count; }
	int count() const { return m_count.Count; }
	void add(BarType barType, long barSize);
	void clear() { m_count.Clear(); }
	bool contains(BarType barType, long barSize);
	virtual BarFilterPrivate* clone() Q_DECL_OVERRIDE { return new BarFilterPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BarFilterPrivate::BarFilterPrivate()
	: m_count(new QList<BarFilterItem>())
{
}

BarFilterPrivate::~BarFilterPrivate ()
{
}

void BarFilterPrivate::add(BarType barType, long barSize)
{
	if (!Contains(barType, barSize))
	{
		m_count.Add(new BarFilterItem(barType, barSize));
	}
}

bool BarFilterPrivate::contains(BarType barType, long barSize)
{
	foreach (BarFilterItem current in m_count)
	{
		if (current.barType() == barType && current.barSize() == barSize)
		{
			return true;
		}
	}
	return false;
}


// Pubic API 

BarFilter::BarFilter()
	: d_ptr(new BarFilterPrivate)
{
}

BarFilter::~BarFilter()
{
}

BarFilter::BarFilter (const BarFilter &other)
	: d_ptr(other.d_ptr)
{
}

BarFilter& BarFilter::operator=(const BarFilter &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BarFilter::operator==(const BarFilter &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QList<BarFilterItem> BarFilter::items() const
{
	return d_ptr->items();
}

int BarFilter::count() const
{
	return d_ptr->count();
}

void BarFilter::add(BarType barType, long barSize)
{
	d_ptr->add(barType, barSize);
}

void BarFilter::clear()
{
	d_ptr->clear();
}

bool BarFilter::contains(BarType barType, long barSize)
{
	return d_ptr->contains(barType, barSize);
}

QDebug operator<<(QDebug dbg, const BarFilter& barfilter)
{
	return dbg << barfilter.toString();
}

