#ifndef __QUANTKIT_ONPORTFOLIODELETED_H__
#define __QUANTKIT_ONPORTFOLIODELETED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnPortfolioDeletedPrivate;

class Portfolio;

class QUANTKIT_EXPORT OnPortfolioDeleted Q_DECL_FINAL : public Event
{
public:
	explicit OnPortfolioDeleted(const Portfolio& portfolio);
	~OnPortfolioDeleted();

public:
	Portfolio portfolio() const;

private:
	QK_DECLARE_PRIVATE(OnPortfolioDeleted)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnPortfolioDeleted)

#endif // __QUANTKIT_ONPORTFOLIODELETED_H__
