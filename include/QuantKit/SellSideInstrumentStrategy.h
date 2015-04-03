#ifndef __QUANTKIT_SELLSIDEINSTRUMENTSTRATEGY_H__
#define __QUANTKIT_SELLSIDEINSTRUMENTSTRATEGY_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/SellSideStrategy.h>

namespace QuantKit {

class SellSideInstrumentStrategyPrivate;

class Framework;
class Instrument;
class Strategy;
class InstrumentList;
class ExecutionCommand;

class QUANTKIT_EXPORT SellSideInstrumentStrategy Q_DECL_FINAL : public SellSideStrategy
{
public:
	SellSideInstrumentStrategy(const Framework& framework, const QString& name);
	~SellSideInstrumentStrategy();

public:

private:
	QK_DECLARE_PRIVATE(SellSideInstrumentStrategy)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SellSideInstrumentStrategy)

#endif // __QUANTKIT_SELLSIDEINSTRUMENTSTRATEGY_H__
