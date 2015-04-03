#include <QuantKit/PortfolioList.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/IdArray.h>

namespace QuantKit {

class PortfolioListPrivate : public QSharedData
{
public:
	QList<Portfolio> m_count;
	IdArray<Portfolio> m_idArray;
	Dictionary<QString,Portfolio> m_dictionary;

public:
	PortfolioListPrivate();
	virtual ~PortfolioListPrivate();

public:
	int count() const { return m_count.Count; }
	Portfolio item(const QString& name) const { return GetByName(name); }
	void add(const Portfolio& portfolio);
	void clear();
	Portfolio getById(int id) { return m_idArray[id]; }
	Portfolio getByIndex(int index) { return m_count[index]; }
	Portfolio getByName(const QString& name);
	virtual PortfolioListPrivate* clone() Q_DECL_OVERRIDE { return new PortfolioListPrivate(*this); }
//private:
	IEnumerator<Portfolio> system.Collections.Generic.IEnumerable<SmartQuant.Portfolio>.GetEnumerator()
	{
		return m_count.GetEnumerator();
	}

	IEnumerator system.Collections.IEnumerable.GetEnumerator()
	{
		return m_count.GetEnumerator();
	}

};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioListPrivate::PortfolioListPrivate()
	: m_count(new QList<Portfolio>())
	, m_idArray(new IdArray<Portfolio>(1000))
	, m_dictionary(new Dictionary<string, Portfolio>())
{
}

PortfolioListPrivate::~PortfolioListPrivate ()
{
}

void PortfolioListPrivate::add(const Portfolio& portfolio)
{
	m_count.Add(portfolio);
	m_idArray[portfolio.id()] = portfolio;
	m_dictionary[portfolio.name()] = portfolio;
}

void PortfolioListPrivate::clear()
{
	m_count.Clear();
	m_idArray.Clear();
	m_dictionary.Clear();
}

Portfolio PortfolioListPrivate::getByName(const QString& name)
{
	Portfolio result = null;
	m_dictionary.TryGetValue(name, out result);
	return result;
}


// Pubic API 

PortfolioList::PortfolioList()
	: d_ptr(new PortfolioListPrivate)
{
}

PortfolioList::~PortfolioList()
{
}

PortfolioList::PortfolioList (const PortfolioList &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioList& PortfolioList::operator=(const PortfolioList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioList::operator==(const PortfolioList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int PortfolioList::count() const
{
	return d_ptr->count();
}

Portfolio PortfolioList::item(const QString& name) const
{
	return d_ptr->item(name);
}

void PortfolioList::add(const Portfolio& portfolio)
{
	d_ptr->add(portfolio);
}

void PortfolioList::clear()
{
	d_ptr->clear();
}

Portfolio PortfolioList::getById(int id)
{
	return d_ptr->getById(id);
}

Portfolio PortfolioList::getByIndex(int index)
{
	return d_ptr->getByIndex(index);
}

Portfolio PortfolioList::getByName(const QString& name)
{
	return d_ptr->getByName(name);
}

QDebug operator<<(QDebug dbg, const PortfolioList& portfoliolist)
{
	return dbg << portfoliolist.toString();
}

