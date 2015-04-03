#ifndef __QUANTKIT_SCENARIO_PRIVATE_H__
#define __QUANTKIT_SCENARIO_PRIVATE_H__

#include <QuantKit/Scenario.h>

#include <QSharedData>

#include "Clock_p.h"
#include "InstrumentManager_p.h"
#include "DataManager_p.h"
#include "ProviderManager_p.h"
#include "OrderManager_p.h"
#include "BarFactory_p.h"
#include "EventManager_p.h"
#include "StrategyManager_p.h"
#include "StatisticsManager_p.h"
#include "GroupManager_p.h"
#include "AccountDataManager_p.h"
#include "DataFileManager_p.h"
#include "Framework_p.h"
#include "Strategy_p.h"

namespace QuantKit {

class ScenarioPrivate : public QSharedData
{
public:
	Framework m_dataFileManager;
	Strategy strategy;
	QString Name;

public:
	explicit ScenarioPrivate(const Framework& framework)
	{
		framework.groupManager().Clear();
	}

	virtual ~ScenarioPrivate();

public:
	Strategy getStrategy() const;
	void setStrategy(Strategy value);
	Clock clock() const
	{
		return m_dataFileManager.clock();
	}

	InstrumentManager instrumentManager() const
	{
		return m_dataFileManager.instrumentManager();
	}

	DataManager dataManager() const
	{
		return m_dataFileManager.dataManager();
	}

	ProviderManager providerManager() const
	{
		return m_dataFileManager.providerManager();
	}

	OrderManager orderManager() const
	{
		return m_dataFileManager.orderManager();
	}

	IDataSimulator dataSimulator() const
	{
		return m_dataFileManager.providerManager().dataSimulator();
	}

	IExecutionSimulator executionSimulator() const
	{
		return m_dataFileManager.providerManager().executionSimulator();
	}

	BarFactory barFactory() const
	{
		return m_dataFileManager.eventManager().barFactory();
	}

	EventManager eventManager() const
	{
		return m_dataFileManager.eventManager();
	}

	StrategyManager strategyManager() const
	{
		return m_dataFileManager.strategyManager();
	}

	StatisticsManager statisticsManager() const
	{
		return m_dataFileManager.statisticsManager();
	}

	GroupManager groupManager() const
	{
		return m_dataFileManager.groupManager();
	}

	AccountDataManager accountDataManager() const
	{
		return m_dataFileManager.accountDataManager();
	}

	DataFileManager dataFileManager() const
	{
		return m_dataFileManager.dataFileManager();
	}

	virtual void run() Q_DECL_OVERRIDE;
	void runWithLogger(const QString& SolutionName);
	void start();
	void startBacktest()
	{
		StartStrategy(StrategyMode.Backtest);
	}

	void startLive()
	{
		StartStrategy(StrategyMode.Live);
	}

	void startPaper()
	{
		StartStrategy(StrategyMode.Paper);
	}

	void startStrategy(StrategyMode mode);
	void startStrategy();
	void startStrategy(const Strategy& strategy);
//private:
	void method_0();
	void method_1();
};

} // namepsace QuantKit

#endif // __QUANTKIT_SCENARIO_PRIVATE_H__
