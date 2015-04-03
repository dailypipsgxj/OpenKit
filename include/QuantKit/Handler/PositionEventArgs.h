#ifndef __QUANTKIT_POSITIONEVENTARGS_H__
#define __QUANTKIT_POSITIONEVENTARGS_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/PortfolioEventArgs.h>

namespace QuantKit {

class PositionEventArgsPrivate;

class Portfolio;
class Position;

class QUANTKIT_EXPORT PositionEventArgs Q_DECL_FINAL : public PortfolioEventArgs
{
public:
	PositionEventArgs(const Portfolio& portfolio, const Position& position);
	~PositionEventArgs();

public:
	Position position() const;

private:
	QK_DECLARE_PRIVATE(PositionEventArgs)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PositionEventArgs)

#endif // __QUANTKIT_POSITIONEVENTARGS_H__
