#ifndef __QUANTKIT_PORTFOLIOLIST_H__
#define __QUANTKIT_PORTFOLIOLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioListPrivate;

class Portfolio;
class IdArray;

class QUANTKIT_EXPORT PortfolioList
{
public:
	PortfolioList();
	~PortfolioList();

	PortfolioList(const PortfolioList &other);
	PortfolioList& operator=(const PortfolioList &other);
	bool operator==(const PortfolioList &other) const;
	inline bool operator!=(const PortfolioList &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	Portfolio item(const QString& name) const;
	void add(const Portfolio& portfolio);
	void clear();
	Portfolio getById(int id);
	Portfolio getByIndex(int index);
	Portfolio getByName(const QString& name);

private:
	QSharedDataPointer<PortfolioListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioList& portfoliolist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioList& portfoliolist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioList)

#endif // __QUANTKIT_PORTFOLIOLIST_H__
