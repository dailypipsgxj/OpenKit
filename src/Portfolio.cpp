#include <QuantKit/Portfolio.h>

#include <QuantKit/Pricer.h>
#include <QuantKit/PortfolioPerformance.h>
#include <QuantKit/PortfolioStatistics.h>
#include <QuantKit/Position.h>
#include <QuantKit/FillSeries.h>
#include <QuantKit/Transaction.h>
#include <QuantKit/Account.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/Fill.h>
#include <QuantKit/IdArray.h>

namespace QuantKit {

class PortfolioPrivate : public QSharedData
{
public:
	Framework m_clock;
	int m_id;
	QString m_name;
	Account m_account;
	FillSeries m_fills;
	QList<Transaction> m_transactions;
	IdArray<Transaction> m_idArray;
	QList<Position> m_positions;
	IdArray<Position> idArray_1;
	Pricer m_pricer;
	PortfolioPerformance m_performance;
	PortfolioStatistics m_statistics;
	Portfolio m_parent;
	QList<Portfolio> m_children;

public:
	PortfolioPrivate(const Framework& framework, const QString& name);
	virtual ~PortfolioPrivate();

public:
	int id() const { return m_id; }
	QString name() const { return m_name; }
	Portfolio parent() const { return m_parent; }
	void setParent(const Portfolio& value);
	QList<Portfolio> children() const { return m_children; }
	Pricer pricer() const { return m_pricer; }
	void setPricer(const Pricer& value) { m_pricer = value; }
	PortfolioPerformance performance() const { return m_performance; }
	PortfolioStatistics statistics() const { return m_statistics; }
	double accountValue() const { return m_account.value(); }
	double positionValue() const;
	QList<Position> positions() const { return m_positions; }
	FillSeries fills() const { return m_fills; }
	QList<Transaction> transactions() const { return m_transactions; }
	Account account() const { return m_account; }
	double value() const
	{
		return m_account + positionValue();
	}

	void add(const ExecutionReport& report) { method_1(report, false); }
	void add(const Fill& fill) { method_2(fill, false); }
	Position getPosition(const Instrument& instrument)
	{
		return idArray_1[instrument.id()];
	}

	bool hasLongPosition(const Instrument& instrument);
	bool hasLongPosition(const Instrument& instrument, double qty);
	bool hasPosition(const Instrument& instrument);
	bool hasPosition(const Instrument& instrument, PositionSide side, double qty);
	bool hasShortPosition(const Instrument& instrument);
	bool hasShortPosition(const Instrument& instrument, double qty);
	virtual PortfolioPrivate* clone() Q_DECL_OVERRIDE { return new PortfolioPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioPrivate::PortfolioPrivate(const Framework& framework, const QString& name)
	: m_clock(framework)
	, m_name(name)
	, m_account(new Account(framework))
	, m_fills(new FillSeries(name))
	, m_transactions(new QList<Transaction>())
	, m_idArray(new IdArray<Transaction>(100000))
	, m_positions(new QList<Position>())
	, idArray_1(new IdArray<Position>(10000))
	, m_pricer(framework.portfolioManager().pricer())
	, m_performance(new PortfolioPerformance(this))
	, m_statistics(new PortfolioStatistics(this))
	, m_children(new QList<Portfolio>())
{
}

PortfolioPrivate::~PortfolioPrivate ()
{
}

void PortfolioPrivate::setParent(const Portfolio& value)
{
	if (m_parent != value)
	{
		if (m_parent != null)
		{
			m_parent.children().Remove(this);
		}
		m_parent = value;
		if (m_parent != null)
		{
			m_account.setParent() = m_parent.account();
			m_parent.children().Add(this);
		}
		else
		{
			m_account.setParent() = null;
		}
		m_clock.eventServer().method_6(this, true);
	}
}

double PortfolioPrivate::positionValue() const
{
	double num = 0.0;
	for (int i = 0; i < m_positions.Count; i++)
	{
		num += m_clock.currencyConverter().Convert(m_positions[i].value(), m_positions[i].instrument().currencyId(), m_account.currencyId());
	}
	return num;
}

bool PortfolioPrivate::hasLongPosition(const Instrument& instrument)
{
	Position position = idArray_1[instrument.id()];
	return position != null && position.side() == PositionSide.Long && position.qty() != 0.0;
}

bool PortfolioPrivate::hasLongPosition(const Instrument& instrument, double qty)
{
	Position position = idArray_1[instrument.id()];
	return position != null && position.side() == PositionSide.Long && position.qty() == qty;
}

bool PortfolioPrivate::hasPosition(const Instrument& instrument)
{
	Position position = idArray_1[instrument.id()];
	return position != null && position.qty() != 0.0;
}

bool PortfolioPrivate::hasPosition(const Instrument& instrument, PositionSide side, double qty)
{
	Position position = idArray_1[instrument.id()];
	return position != null && position.side() == side && position.qty() == qty;
}

bool PortfolioPrivate::hasShortPosition(const Instrument& instrument)
{
	Position position = idArray_1[instrument.id()];
	return position != null && position.side() == PositionSide.Short && position.qty() != 0.0;
}

bool PortfolioPrivate::hasShortPosition(const Instrument& instrument, double qty)
{
	Position position = idArray_1[instrument.id()];
	return position != null && position.side() == PositionSide.Short && position.qty() == qty;
}


// Pubic API 

Portfolio::Portfolio(const Framework& framework, const QString& name)
	: d_ptr(new PortfolioPrivate(framework, name))
{
}

Portfolio::~Portfolio()
{
}

Portfolio::Portfolio (const Portfolio &other)
	: d_ptr(other.d_ptr)
{
}

Portfolio& Portfolio::operator=(const Portfolio &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Portfolio::operator==(const Portfolio &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int Portfolio::id() const
{
	return d_ptr->id();
}

QString Portfolio::name() const
{
	return d_ptr->name();
}

Portfolio Portfolio::parent() const
{
	return d_ptr->parent();
}

void Portfolio::setParent(const Portfolio& value)
{
	d_ptr->setParent(value);
}

QList<Portfolio> Portfolio::children() const
{
	return d_ptr->children();
}

Pricer Portfolio::pricer() const
{
	return d_ptr->pricer();
}

void Portfolio::setPricer(const Pricer& value)
{
	d_ptr->setPricer(value);
}

PortfolioPerformance Portfolio::performance() const
{
	return d_ptr->performance();
}

PortfolioStatistics Portfolio::statistics() const
{
	return d_ptr->statistics();
}

double Portfolio::accountValue() const
{
	return d_ptr->accountValue();
}

double Portfolio::positionValue() const
{
	return d_ptr->positionValue();
}

QList<Position> Portfolio::positions() const
{
	return d_ptr->positions();
}

FillSeries Portfolio::fills() const
{
	return d_ptr->fills();
}

QList<Transaction> Portfolio::transactions() const
{
	return d_ptr->transactions();
}

Account Portfolio::account() const
{
	return d_ptr->account();
}

double Portfolio::value() const
{
	return d_ptr->value();
}

void Portfolio::add(const ExecutionReport& report)
{
	d_ptr->add(report);
}

void Portfolio::add(const Fill& fill)
{
	d_ptr->add(fill);
}

Position Portfolio::getPosition(const Instrument& instrument)
{
	return d_ptr->getPosition(instrument);
}

bool Portfolio::hasLongPosition(const Instrument& instrument)
{
	return d_ptr->hasLongPosition(instrument);
}

bool Portfolio::hasLongPosition(const Instrument& instrument, double qty)
{
	return d_ptr->hasLongPosition(instrument, qty);
}

bool Portfolio::hasPosition(const Instrument& instrument)
{
	return d_ptr->hasPosition(instrument);
}

bool Portfolio::hasPosition(const Instrument& instrument, PositionSide side, double qty)
{
	return d_ptr->hasPosition(instrument, side, qty);
}

bool Portfolio::hasShortPosition(const Instrument& instrument)
{
	return d_ptr->hasShortPosition(instrument);
}

bool Portfolio::hasShortPosition(const Instrument& instrument, double qty)
{
	return d_ptr->hasShortPosition(instrument, qty);
}

QDebug operator<<(QDebug dbg, const Portfolio& portfolio)
{
	return dbg << portfolio.toString();
}

