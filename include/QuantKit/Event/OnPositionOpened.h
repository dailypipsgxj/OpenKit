#ifndef __QUANTKIT_ONPOSITIONOPENED_H__
#define __QUANTKIT_ONPOSITIONOPENED_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnPositionOpenedPrivate;

class Portfolio;
class Position;

class QUANTKIT_EXPORT OnPositionOpened Q_DECL_FINAL : public Event
{
public:
	OnPositionOpened(const Portfolio& portfolio, const Position& position);
	~OnPositionOpened();

public:
	Portfolio portfolio() const;

	Position position() const;

private:
	QK_DECLARE_PRIVATE(OnPositionOpened)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnPositionOpened)

#endif // __QUANTKIT_ONPOSITIONOPENED_H__
