#ifndef __QUANTKIT_PERFORMANCESTRATEGY_H__
#define __QUANTKIT_PERFORMANCESTRATEGY_H__

#include <QuantKit/quantkit_global.h>
#include <QTimer>

#include <QuantKit/InstrumentStrategy.h>

namespace QuantKit {

class PerformanceStrategyPrivate;

class Framework;
class Instrument;
class Trade;

class QUANTKIT_EXPORT PerformanceStrategy Q_DECL_FINAL : public InstrumentStrategy
{
public:
	explicit PerformanceStrategy(const Framework& framework);
	~PerformanceStrategy();


private:
	QK_DECLARE_PRIVATE(PerformanceStrategy)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PerformanceStrategy)

#endif // __QUANTKIT_PERFORMANCESTRATEGY_H__
