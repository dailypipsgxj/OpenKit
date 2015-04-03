#include <QuantKit/Scenario.h>

#include <QuantKit/Clock.h>
#include <QuantKit/InstrumentManager.h>
#include <QuantKit/DataManager.h>
#include <QuantKit/ProviderManager.h>
#include <QuantKit/OrderManager.h>
#include <QuantKit/BarFactory.h>
#include <QuantKit/EventManager.h>
#include <QuantKit/StrategyManager.h>
#include <QuantKit/StatisticsManager.h>
#include <QuantKit/GroupManager.h>
#include <QuantKit/AccountDataManager.h>
#include <QuantKit/DataFileManager.h>
#include <QuantKit/Framework.h>
#include "Strategy_p.h"
#include "Scenario_p.h"

using namespace QuantKit;

ScenarioPrivate::~ScenarioPrivate ()
{
}

Strategy getStrategy() const
{
	return null;
}
void setStrategy(Strategy value)
{
}
void ScenarioPrivate::run()
{
}

void ScenarioPrivate::runWithLogger(const QString& SolutionName)
{
	m_dataFileManager.Clear();
	Name = SolutionName;
	EventLogger logger = m_dataFileManager.eventLoggerManager().GetLogger("QuantController");
	if (logger != null)
	{
		m_dataFileManager.eventManager().setLogger() = logger;
	}
	else
	{
		QuantControllerLogger quantControllerLogger = new QuantControllerLogger(m_dataFileManager);
		m_dataFileManager.eventManager().setLogger() = quantControllerLogger;
		quantControllerLogger.Connect();
	}
	method_0();
	Run();
	method_1();
}

void ScenarioPrivate::start()
{
	m_dataFileManager.Clear();
	EventLogger logger = m_dataFileManager.eventLoggerManager().GetLogger("QuantController");
	if (logger != null)
	{
		m_dataFileManager.eventManager().setLogger() = logger;
	}
	method_0();
	Run();
	method_1();
}

void ScenarioPrivate::startStrategy(StrategyMode mode)
{
	Console.WriteLine(DateTime.Now + " Scenario::StartStrategy " + mode);
	m_dataFileManager.strategyManager().StartStrategy(strategy, mode);
	while (strategy.status() != StrategyStatus.Stopped)
	{
		Thread.Sleep(10);
	}
	Console.WriteLine(DateTime.Now + " Scenario::StartStrategy Done");
}

void ScenarioPrivate::startStrategy()
{
	Console.WriteLine(DateTime.Now + " Scenario::StartStrategy " + m_dataFileManager.strategyManager().mode());
	m_dataFileManager.strategyManager().StartStrategy(strategy, m_dataFileManager.strategyManager().mode());
	while (strategy.status() != StrategyStatus.Stopped)
	{
		Thread.Sleep(10);
	}
	Console.WriteLine(DateTime.Now + " Scenario::StartStrategy Done");
}

void ScenarioPrivate::startStrategy(const Strategy& strategy)
{
	Console.WriteLine(DateTime.Now + " Scenario::StartStrategy " + m_dataFileManager.strategyManager().mode());
	m_dataFileManager.strategyManager().StartStrategy(strategy);
	while (strategy.status() != StrategyStatus.Stopped)
	{
		Thread.Sleep(10);
	}
	Console.WriteLine(DateTime.Now + " Scenario::StartStrategy Done");
}

void ScenarioPrivate::method_0()
{
	SolutionStatusInfo solutionStatusInfo = new SolutionStatusInfo(m_dataFileManager.clock().dateTime(), SolutionStatusType.Started);
	solutionStatusInfo.setSolution() = ((Name == null) ? "SolutionName" : Name);
	solutionStatusInfo.setMode() = "SolutionMode";
	m_dataFileManager.eventServer().OnLog(new GroupEvent(solutionStatusInfo, null));
}

void ScenarioPrivate::method_1()
{
	SolutionStatusInfo solutionStatusInfo = new SolutionStatusInfo(m_dataFileManager.clock().dateTime(), SolutionStatusType.Stopped);
	solutionStatusInfo.setSolution() = ((Name == null) ? "SolutionName" : Name);
	solutionStatusInfo.setMode() = "SolutionMode";
	m_dataFileManager.eventServer().OnLog(new GroupEvent(solutionStatusInfo, null));
}


// Pubic API 

Scenario::Scenario(const Framework& framework)
	: d_ptr(new ScenarioPrivate(framework))
{
}

Scenario::~Scenario()
{
}

Scenario::Scenario (ScenarioPrivate &dd)
	: d_ptr(&dd)
{
}

Scenario::Scenario (const Scenario &other)
	: d_ptr(other.d_ptr)
{
}

Scenario& Scenario::operator=(const Scenario &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Scenario::operator==(const Scenario &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Strategy strategy() const
{
	return d_ptr->
	setStrategy()
}

void setStrategy(Strategy value)
{
	d_ptr->strategy(value);
}

Clock Scenario::clock() const
{
	return d_ptr->clock();
}

InstrumentManager Scenario::instrumentManager() const
{
	return d_ptr->instrumentManager();
}

DataManager Scenario::dataManager() const
{
	return d_ptr->dataManager();
}

ProviderManager Scenario::providerManager() const
{
	return d_ptr->providerManager();
}

OrderManager Scenario::orderManager() const
{
	return d_ptr->orderManager();
}

IDataSimulator Scenario::dataSimulator() const
{
	return d_ptr->dataSimulator();
}

IExecutionSimulator Scenario::executionSimulator() const
{
	return d_ptr->executionSimulator();
}

BarFactory Scenario::barFactory() const
{
	return d_ptr->barFactory();
}

EventManager Scenario::eventManager() const
{
	return d_ptr->eventManager();
}

StrategyManager Scenario::strategyManager() const
{
	return d_ptr->strategyManager();
}

StatisticsManager Scenario::statisticsManager() const
{
	return d_ptr->statisticsManager();
}

GroupManager Scenario::groupManager() const
{
	return d_ptr->groupManager();
}

AccountDataManager Scenario::accountDataManager() const
{
	return d_ptr->accountDataManager();
}

DataFileManager Scenario::dataFileManager() const
{
	return d_ptr->dataFileManager();
}

void Scenario::run()
{
	d_ptr->run();
}

void Scenario::runWithLogger(const QString& SolutionName)
{
	d_ptr->runWithLogger(SolutionName);
}

void Scenario::start()
{
	d_ptr->start();
}

void Scenario::startBacktest()
{
	d_ptr->startBacktest();
}

void Scenario::startLive()
{
	d_ptr->startLive();
}

void Scenario::startPaper()
{
	d_ptr->startPaper();
}

void Scenario::startStrategy(StrategyMode mode)
{
	d_ptr->startStrategy(mode);
}

void Scenario::startStrategy()
{
	d_ptr->startStrategy();
}

void Scenario::startStrategy(const Strategy& strategy)
{
	d_ptr->startStrategy(strategy);
}

QDebug operator<<(QDebug dbg, const Scenario& scenario)
{
	return dbg << scenario.toString();
}

