#ifndef __QUANTKIT_ONPOSITIONCHANGED_H__
#define __QUANTKIT_ONPOSITIONCHANGED_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnPositionChangedPrivate;

class Portfolio;
class Position;

class QUANTKIT_EXPORT OnPositionChanged Q_DECL_FINAL : public Event
{
public:
	OnPositionChanged(const Portfolio& portfolio, const Position& position);
	~OnPositionChanged();

public:
	Portfolio portfolio() const;

	Position position() const;

private:
	QK_DECLARE_PRIVATE(OnPositionChanged)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnPositionChanged)

#endif // __QUANTKIT_ONPOSITIONCHANGED_H__
