#ifndef __QUANTKIT_ONPOSITIONCLOSED_H__
#define __QUANTKIT_ONPOSITIONCLOSED_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnPositionClosedPrivate;

class Portfolio;
class Position;

class QUANTKIT_EXPORT OnPositionClosed Q_DECL_FINAL : public Event
{
public:
	OnPositionClosed(const Portfolio& portfolio, const Position& position);
	~OnPositionClosed();

public:
	Portfolio portfolio() const;

	Position position() const;

private:
	QK_DECLARE_PRIVATE(OnPositionClosed)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnPositionClosed)

#endif // __QUANTKIT_ONPOSITIONCLOSED_H__
