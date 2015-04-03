#include <QuantKit/BarFilterItem.h>


namespace QuantKit {

class BarFilterItemPrivate : public QSharedData
{
public:
	BarType m_barType;
	long m_barSize;

public:
	BarFilterItemPrivate(BarType barType, long barSize);
	virtual ~BarFilterItemPrivate();

public:
	BarType barType() const { return m_barType; }
	void setBarType(BarType value) { m_barType = value; }
	long barSize() const { return m_barSize; }
	void setBarSize(long value) { m_barSize = value; }
	virtual BarFilterItemPrivate* clone() Q_DECL_OVERRIDE { return new BarFilterItemPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BarFilterItemPrivate::BarFilterItemPrivate(BarType barType, long barSize)
	: m_barType(barType)
	, m_barSize(barSize)
{
}

BarFilterItemPrivate::~BarFilterItemPrivate ()
{
}


// Pubic API 

BarFilterItem::BarFilterItem(BarType barType, long barSize)
	: d_ptr(new BarFilterItemPrivate(barType, barSize))
{
}

BarFilterItem::~BarFilterItem()
{
}

BarFilterItem::BarFilterItem (const BarFilterItem &other)
	: d_ptr(other.d_ptr)
{
}

BarFilterItem& BarFilterItem::operator=(const BarFilterItem &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BarFilterItem::operator==(const BarFilterItem &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

BarType BarFilterItem::barType() const
{
	return d_ptr->barType();
}

void BarFilterItem::setBarType(BarType value)
{
	d_ptr->setBarType(value);
}

long BarFilterItem::barSize() const
{
	return d_ptr->barSize();
}

void BarFilterItem::setBarSize(long value)
{
	d_ptr->setBarSize(value);
}

QDebug operator<<(QDebug dbg, const BarFilterItem& barfilteritem)
{
	return dbg << barfilteritem.toString();
}

