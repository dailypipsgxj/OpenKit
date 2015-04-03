#ifndef __QUANTKIT_PORTFOLIOMANAGER_H__
#define __QUANTKIT_PORTFOLIOMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioManagerPrivate;

class Pricer;
class PortfolioList;
class Framework;
class Portfolio;
class ExecutionReport;

class QUANTKIT_EXPORT PortfolioManager
{
public:
	explicit PortfolioManager(const Framework& framework);
	~PortfolioManager();

	PortfolioManager(const PortfolioManager &other);
	PortfolioManager& operator=(const PortfolioManager &other);
	bool operator==(const PortfolioManager &other) const;
	inline bool operator!=(const PortfolioManager &other) const { return !(this->operator==(other));  }
public:
	Pricer pricer() const;
	void setPricer(const Pricer& value);
	PortfolioList portfolios() const;
	Portfolio item(const QString& name) const;
	void add(const Portfolio& portfolio);
	void clear();
	Portfolio getById(int id);
	void remove(const QString& name);
	void remove(int id);
	void remove(const Portfolio& portfolio);

private:
	QSharedDataPointer<PortfolioManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioManager& portfoliomanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioManager& portfoliomanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioManager)

#endif // __QUANTKIT_PORTFOLIOMANAGER_H__
