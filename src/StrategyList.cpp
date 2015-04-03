#include <QuantKit/StrategyList.h>

#include "Strategy_p.h"
#include <QuantKit/IdArray.h>

namespace QuantKit {

class StrategyListPrivate : public QSharedData
{
public:
	IdArray<Strategy> m_idArray;
	QList<Strategy> m_item;

public:
	StrategyListPrivate();
	virtual ~StrategyListPrivate();

public:
	int count() const { return m_item.Count; }
	Strategy item(int index) const { return m_item[index]; }
	void setItem(int index, const Strategy& value) { m_item[index] = value; }
	void add(const Strategy& strategy);
	void clear();
	bool contains(const Strategy& strategy)
	{
		return m_idArray[(int)strategy.id()] != null;
	}

	bool contains(int id) { return m_idArray[id] == null; }
	Strategy getById(int id) { return m_idArray[id]; }
	Strategy getByIndex(int index) { return m_item[index]; }
	void remove(const Strategy& strategy);
	virtual StrategyListPrivate* clone() Q_DECL_OVERRIDE { return new StrategyListPrivate(*this); }
//private:
	IEnumerator system.Collections.IEnumerable.GetEnumerator() { return m_item.GetEnumerator(); }
};

} // namepsace QuantKit


using namespace QuantKit;

StrategyListPrivate::StrategyListPrivate()
	: m_idArray(new IdArray<Strategy>(1000))
	, m_item(new QList<Strategy>())
{
}

StrategyListPrivate::~StrategyListPrivate ()
{
}

void StrategyListPrivate::add(const Strategy& strategy)
{
	if (m_idArray[(int)strategy.id()] == null)
	{
		m_item.Add(strategy);
		m_idArray.Add((int)strategy.id(), strategy);
		return;
	}
	Console.WriteLine(string.Concat(new object[]
	{
		"StrategyList::Add strategy ",
		strategy.name(),
		" with Id = ",
		strategy.id(),
		" is already in the list"
	}));
}

void StrategyListPrivate::clear()
{
	m_item.Clear();
	m_idArray.Clear();
}

void StrategyListPrivate::remove(const Strategy& strategy)
{
	m_item.Remove(strategy);
	m_idArray.Remove((int)strategy.id());
}


// Pubic API 

StrategyList::StrategyList()
	: d_ptr(new StrategyListPrivate)
{
}

StrategyList::~StrategyList()
{
}

StrategyList::StrategyList (const StrategyList &other)
	: d_ptr(other.d_ptr)
{
}

StrategyList& StrategyList::operator=(const StrategyList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool StrategyList::operator==(const StrategyList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int StrategyList::count() const
{
	return d_ptr->count();
}

Strategy StrategyList::item(int index) const
{
	return d_ptr->item(index);
}

void StrategyList::setItem(int index, const Strategy& value)
{
	d_ptr->setItem(index, value);
}

void StrategyList::add(const Strategy& strategy)
{
	d_ptr->add(strategy);
}

void StrategyList::clear()
{
	d_ptr->clear();
}

bool StrategyList::contains(const Strategy& strategy)
{
	return d_ptr->contains(strategy);
}

bool StrategyList::contains(int id)
{
	return d_ptr->contains(id);
}

Strategy StrategyList::getById(int id)
{
	return d_ptr->getById(id);
}

Strategy StrategyList::getByIndex(int index)
{
	return d_ptr->getByIndex(index);
}

void StrategyList::remove(const Strategy& strategy)
{
	d_ptr->remove(strategy);
}

QDebug operator<<(QDebug dbg, const StrategyList& strategylist)
{
	return dbg << strategylist.toString();
}

