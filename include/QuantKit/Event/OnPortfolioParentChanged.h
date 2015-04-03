#ifndef __QUANTKIT_ONPORTFOLIOPARENTCHANGED_H__
#define __QUANTKIT_ONPORTFOLIOPARENTCHANGED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnPortfolioParentChangedPrivate;

class Portfolio;

class QUANTKIT_EXPORT OnPortfolioParentChanged Q_DECL_FINAL : public Event
{
public:
	explicit OnPortfolioParentChanged(const Portfolio& portfolio);
	~OnPortfolioParentChanged();

public:
	Portfolio portfolio() const;

private:
	QK_DECLARE_PRIVATE(OnPortfolioParentChanged)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnPortfolioParentChanged)

#endif // __QUANTKIT_ONPORTFOLIOPARENTCHANGED_H__
