#ifndef __QUANTKIT_ONPORTFOLIOADDED_H__
#define __QUANTKIT_ONPORTFOLIOADDED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnPortfolioAddedPrivate;

class Portfolio;

class QUANTKIT_EXPORT OnPortfolioAdded Q_DECL_FINAL : public Event
{
public:
	explicit OnPortfolioAdded(const Portfolio& portfolio);
	~OnPortfolioAdded();

public:
	Portfolio portfolio() const;

private:
	QK_DECLARE_PRIVATE(OnPortfolioAdded)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnPortfolioAdded)

#endif // __QUANTKIT_ONPORTFOLIOADDED_H__
