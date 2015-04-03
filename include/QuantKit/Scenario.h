#ifndef __QUANTKIT_SCENARIO_H__
#define __QUANTKIT_SCENARIO_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/IDataSimulator.h>
#include <QuantKit/IExecutionSimulator.h>
#include <QuantKit/StrategyMode.h>

namespace QuantKit {

class ScenarioPrivate;

class Clock;
class InstrumentManager;
class DataManager;
class ProviderManager;
class OrderManager;
class BarFactory;
class EventManager;
class StrategyManager;
class StatisticsManager;
class GroupManager;
class AccountDataManager;
class DataFileManager;
class Framework;
class Strategy;

class QUANTKIT_EXPORT Scenario
{
public:
	explicit Scenario(const Framework& framework);
	~Scenario();

	Scenario(const Scenario &other);
	Scenario& operator=(const Scenario &other);
	bool operator==(const Scenario &other) const;
	inline bool operator!=(const Scenario &other) const { return !(this->operator==(other));  }
public:
	Strategy strategy() const;
	void setStrategy(Strategy value);
	Clock clock() const;
	InstrumentManager instrumentManager() const;
	DataManager dataManager() const;
	ProviderManager providerManager() const;
	OrderManager orderManager() const;
	IDataSimulator dataSimulator() const;
	IExecutionSimulator executionSimulator() const;
	BarFactory barFactory() const;
	EventManager eventManager() const;
	StrategyManager strategyManager() const;
	StatisticsManager statisticsManager() const;
	GroupManager groupManager() const;
	AccountDataManager accountDataManager() const;
	DataFileManager dataFileManager() const;
	void run();
	void runWithLogger(const QString& SolutionName);
	void start();
	void startBacktest();
	void startLive();
	void startPaper();
	void startStrategy(StrategyMode mode);
	void startStrategy();
	void startStrategy(const Strategy& strategy);

protected:
	Scenario(ScenarioPrivate& dd);
	QSharedDataPointer<ScenarioPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const Scenario& scenario);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Scenario& scenario);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Scenario)

#endif // __QUANTKIT_SCENARIO_H__
