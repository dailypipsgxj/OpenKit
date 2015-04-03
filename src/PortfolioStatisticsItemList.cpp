#include <QuantKit/PortfolioStatisticsItemList.h>

#include "PortfolioStatisticsItem_p.h"
#include <QuantKit/IdArray.h>

namespace QuantKit {

class PortfolioStatisticsItemListPrivate : public QSharedData
{
public:
	IdArray<PortfolioStatisticsItem> m_idArray;
	QList<PortfolioStatisticsItem> m_item;

public:
	PortfolioStatisticsItemListPrivate();
	virtual ~PortfolioStatisticsItemListPrivate();

public:
	int count() const { return m_item.Count; }
	PortfolioStatisticsItem item(int index) const { return m_item[index]; }
	void add(const PortfolioStatisticsItem& item);
	void clear();
	bool contains(int type)
	{
		return m_idArray[type] != null;
	}

	PortfolioStatisticsItem getByIndex(int index) { return m_item[index]; }
	PortfolioStatisticsItem getByType(int type) { return m_idArray[type]; }
	void remove(int type);
	virtual PortfolioStatisticsItemListPrivate* clone() Q_DECL_OVERRIDE { return new PortfolioStatisticsItemListPrivate(*this); }
//private:
	IEnumerator system.Collections.IEnumerable.GetEnumerator() { return m_item.GetEnumerator(); }
};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioStatisticsItemListPrivate::PortfolioStatisticsItemListPrivate()
	: m_idArray(new IdArray<PortfolioStatisticsItem>(1024))
	, m_item(new QList<PortfolioStatisticsItem>())
{
}

PortfolioStatisticsItemListPrivate::~PortfolioStatisticsItemListPrivate ()
{
}

void PortfolioStatisticsItemListPrivate::add(const PortfolioStatisticsItem& item)
{
	if (m_idArray[item.type()] != null)
	{
		Remove(item.type());
	}
	m_item.Add(item);
	m_idArray.Add(item.type(), item);
}

void PortfolioStatisticsItemListPrivate::clear()
{
	m_item.Clear();
	m_idArray.Clear();
}

void PortfolioStatisticsItemListPrivate::remove(int type)
{
	if (Contains(type))
	{
		m_item.Remove(m_idArray[type]);
		m_idArray.Remove(type);
	}
}


// Pubic API 

PortfolioStatisticsItemList::PortfolioStatisticsItemList()
	: d_ptr(new PortfolioStatisticsItemListPrivate)
{
}

PortfolioStatisticsItemList::~PortfolioStatisticsItemList()
{
}

PortfolioStatisticsItemList::PortfolioStatisticsItemList (const PortfolioStatisticsItemList &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioStatisticsItemList& PortfolioStatisticsItemList::operator=(const PortfolioStatisticsItemList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioStatisticsItemList::operator==(const PortfolioStatisticsItemList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int PortfolioStatisticsItemList::count() const
{
	return d_ptr->count();
}

PortfolioStatisticsItem PortfolioStatisticsItemList::item(int index) const
{
	return d_ptr->item(index);
}

void PortfolioStatisticsItemList::add(const PortfolioStatisticsItem& item)
{
	d_ptr->add(item);
}

void PortfolioStatisticsItemList::clear()
{
	d_ptr->clear();
}

bool PortfolioStatisticsItemList::contains(int type)
{
	return d_ptr->contains(type);
}

PortfolioStatisticsItem PortfolioStatisticsItemList::getByIndex(int index)
{
	return d_ptr->getByIndex(index);
}

PortfolioStatisticsItem PortfolioStatisticsItemList::getByType(int type)
{
	return d_ptr->getByType(type);
}

void PortfolioStatisticsItemList::remove(int type)
{
	d_ptr->remove(type);
}

QDebug operator<<(QDebug dbg, const PortfolioStatisticsItemList& portfoliostatisticsitemlist)
{
	return dbg << portfoliostatisticsitemlist.toString();
}

