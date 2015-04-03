#ifndef __QUANTKIT_PORTFOLIO_H__
#define __QUANTKIT_PORTFOLIO_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/PositionSide.h>

namespace QuantKit {

class PortfolioPrivate;

class Pricer;
class PortfolioPerformance;
class PortfolioStatistics;
class Position;
class FillSeries;
class Transaction;
class Account;
class Framework;
class Instrument;
class ExecutionReport;
class Fill;
class IdArray;

class QUANTKIT_EXPORT Portfolio
{
public:
	Portfolio(const Framework& framework, const QString& name = "");
	~Portfolio();

	Portfolio(const Portfolio &other);
	Portfolio& operator=(const Portfolio &other);
	bool operator==(const Portfolio &other) const;
	inline bool operator!=(const Portfolio &other) const { return !(this->operator==(other));  }
public:
	int id() const;
	QString name() const;
	Portfolio parent() const;
	void setParent(const Portfolio& value);
	QList<Portfolio> children() const;
	Pricer pricer() const;
	void setPricer(const Pricer& value);
	PortfolioPerformance performance() const;
	PortfolioStatistics statistics() const;
	double accountValue() const;
	double positionValue() const;
	QList<Position> positions() const;
	FillSeries fills() const;
	QList<Transaction> transactions() const;
	Account account() const;
	double value() const;
	void add(const ExecutionReport& report);
	void add(const Fill& fill);
	Position getPosition(const Instrument& instrument);
	bool hasLongPosition(const Instrument& instrument);
	bool hasLongPosition(const Instrument& instrument, double qty);
	bool hasPosition(const Instrument& instrument);
	bool hasPosition(const Instrument& instrument, PositionSide side, double qty);
	bool hasShortPosition(const Instrument& instrument);
	bool hasShortPosition(const Instrument& instrument, double qty);

private:
	QSharedDataPointer<PortfolioPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Portfolio& portfolio);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Portfolio& portfolio);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Portfolio)

#endif // __QUANTKIT_PORTFOLIO_H__
