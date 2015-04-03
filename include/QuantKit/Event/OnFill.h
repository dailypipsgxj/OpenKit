#ifndef __QUANTKIT_ONFILL_H__
#define __QUANTKIT_ONFILL_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnFillPrivate;

class Fill;
class Portfolio;

class QUANTKIT_EXPORT OnFill Q_DECL_FINAL : public Event
{
public:
	OnFill(const Portfolio& portfolio, const Fill& fill);
	~OnFill();

public:
	Fill fill() const;
	Portfolio portfolio() const;

private:
	QK_DECLARE_PRIVATE(OnFill)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnFill)

#endif // __QUANTKIT_ONFILL_H__
