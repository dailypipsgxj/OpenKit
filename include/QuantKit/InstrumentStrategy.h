#ifndef __QUANTKIT_INSTRUMENTSTRATEGY_H__
#define __QUANTKIT_INSTRUMENTSTRATEGY_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Strategy.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/PositionSide.h>

namespace QuantKit {

class InstrumentStrategyPrivate;

class Instrument;
class Position;
class Framework;

class QUANTKIT_EXPORT InstrumentStrategy : public Strategy
{
public:
	InstrumentStrategy(const Framework& framework, const QString& name);
	~InstrumentStrategy();

public:
	Instrument instrument() const;
	Position position() const;
	void addInstance(const Instrument& instrument, const InstrumentStrategy& strategy);
	bool hasLongPosition();
	bool hasLongPosition(double qty);
	bool hasPosition();
	bool hasPosition(PositionSide side, double qty);
	bool hasShortPosition();
	bool hasShortPosition(double qty);

protected:
	InstrumentStrategy(InstrumentStrategyPrivate& dd);

private:
	QK_DECLARE_PRIVATE(InstrumentStrategy)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentStrategy)

#endif // __QUANTKIT_INSTRUMENTSTRATEGY_H__
