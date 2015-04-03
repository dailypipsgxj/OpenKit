#include <QuantKit/PortfolioManager.h>

#include <QuantKit/Pricer.h>
#include <QuantKit/PortfolioList.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Portfolio.h>
#include <QuantKit/Event/ExecutionReport.h>

namespace QuantKit {

class PortfolioManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	PortfolioList m_item;
	Pricer m_pricer;
	int int_0;

public:
	explicit PortfolioManagerPrivate(const Framework& framework);
	virtual ~PortfolioManagerPrivate();

public:
	Pricer pricer() const { return m_pricer; }
	void setPricer(const Pricer& value) { m_pricer = value; }
	PortfolioList portfolios() const { return m_item; }
	Portfolio item(const QString& name) const { return m_item[name]; }
	void add(const Portfolio& portfolio) { method_0(portfolio, true); }
	void clear();
	Portfolio getById(int id) { return m_item.GetById(id); }
	void remove(const QString& name);
	void remove(int id);
	void remove(const Portfolio& portfolio);
	virtual PortfolioManagerPrivate* clone() Q_DECL_OVERRIDE { return new PortfolioManagerPrivate(*this); }
//private:
	void method_0(const Portfolio& portfolio, bool bool);
};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioManagerPrivate::PortfolioManagerPrivate(const Framework& framework)
	: m_framework(framework)
	, m_item(new PortfolioList())
	, m_pricer(new Pricer(framework))
{
}

PortfolioManagerPrivate::~PortfolioManagerPrivate ()
{
}

void PortfolioManagerPrivate::clear()
{
	foreach (Portfolio current in m_item)
	{
		m_framework.eventServer().OnPortfolioDeleted(current);
	}
	m_item.Clear();
	int_0 = 0;
}

void PortfolioManagerPrivate::remove(const QString& name)
{
	Portfolio portfolio = this[name];
	if (portfolio != null)
	{
		Remove(portfolio);
		m_framework.eventServer().OnPortfolioDeleted(portfolio);
	}
}

void PortfolioManagerPrivate::remove(int id)
{
	Portfolio byId = GetById(id);
	if (byId != null)
	{
		Remove(byId);
	}
}

void PortfolioManagerPrivate::remove(const Portfolio& portfolio)
{
	m_item.method_0(portfolio);
	m_framework.eventServer().OnPortfolioDeleted(portfolio);
}

void PortfolioManagerPrivate::method_0(const Portfolio& portfolio, bool bool)
{
	int id = int_0++;
	portfolio.setId() = id;
	m_item.Add(portfolio);
	if (@bool)
	{
		m_framework.eventServer().OnPortfolioAdded(portfolio);
	}
}


// Pubic API 

PortfolioManager::PortfolioManager(const Framework& framework)
	: d_ptr(new PortfolioManagerPrivate(framework))
{
}

PortfolioManager::~PortfolioManager()
{
}

PortfolioManager::PortfolioManager (const PortfolioManager &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioManager& PortfolioManager::operator=(const PortfolioManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioManager::operator==(const PortfolioManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Pricer PortfolioManager::pricer() const
{
	return d_ptr->pricer();
}

void PortfolioManager::setPricer(const Pricer& value)
{
	d_ptr->setPricer(value);
}

PortfolioList PortfolioManager::portfolios() const
{
	return d_ptr->portfolios();
}

Portfolio PortfolioManager::item(const QString& name) const
{
	return d_ptr->item(name);
}

void PortfolioManager::add(const Portfolio& portfolio)
{
	d_ptr->add(portfolio);
}

void PortfolioManager::clear()
{
	d_ptr->clear();
}

Portfolio PortfolioManager::getById(int id)
{
	return d_ptr->getById(id);
}

void PortfolioManager::remove(const QString& name)
{
	d_ptr->remove(name);
}

void PortfolioManager::remove(int id)
{
	d_ptr->remove(id);
}

void PortfolioManager::remove(const Portfolio& portfolio)
{
	d_ptr->remove(portfolio);
}

QDebug operator<<(QDebug dbg, const PortfolioManager& portfoliomanager)
{
	return dbg << portfoliomanager.toString();
}

