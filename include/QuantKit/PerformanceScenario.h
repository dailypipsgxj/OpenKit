#ifndef __QUANTKIT_PERFORMANCESCENARIO_H__
#define __QUANTKIT_PERFORMANCESCENARIO_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Scenario.h>

namespace QuantKit {

class PerformanceScenarioPrivate;

class Framework;

class QUANTKIT_EXPORT PerformanceScenario Q_DECL_FINAL : public Scenario
{
public:
	explicit PerformanceScenario(const Framework& framework);
	~PerformanceScenario();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PerformanceScenario)

#endif // __QUANTKIT_PERFORMANCESCENARIO_H__
