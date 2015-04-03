#include <QuantKit/StrategyManager.h>

#include <QuantKit/Global.h>
#include <QuantKit/Framework.h>
#include <QuantKit/InstrumentList.h>
#include "Strategy_p.h"
#include <QuantKit/Event/Group.h>
#include "Provider_p.h"
#include <QuantKit/Event/ProviderError.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Level2Snapshot.h>
#include <QuantKit/Event/Level2Update.h>
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Event/BarSlice.h>
#include <QuantKit/Event/News.h>
#include <QuantKit/Event/Fundamental.h>
#include <QuantKit/Event/Order.h>
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/OnFill.h>
#include <QuantKit/Event/OnTransaction.h>
#include <QuantKit/Portfolio.h>
#include <QuantKit/Position.h>

namespace QuantKit {

class StrategyManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	StrategyMode m_mode;
	StrategyStatus strategyStatus_0;
	Dictionary<IDataProvider,InstrumentList> m_dictionary;
	unsigned char byte_0;
	Strategy strategy_0;
	Global m_global;

public:
	explicit StrategyManagerPrivate(const Framework& framework) { Clear(); }
	virtual ~StrategyManagerPrivate();

public:
	Global global() const { return m_global; }
	StrategyMode mode() const { return m_mode; }
	void setMode(StrategyMode value);
	void clear();
	unsigned char getNextId();
	void registerMarketDataRequest(const IDataProvider& dataProvider, const InstrumentList& instrumentList);
	void startStrategy(const Strategy& strategy)
	{
		StartStrategy(strategy, m_mode);
	}

	void startStrategy(const Strategy& strategy, StrategyMode mode);
	void stop();
	virtual StrategyManagerPrivate* clone() Q_DECL_OVERRIDE { return new StrategyManagerPrivate(*this); }
//private:
	void method_1();
	void method_2();
	void method_32(const Strategy& strategy_1, const QString& string, const QVariant& object);
	void method_33(const Strategy& strategy_1, const QString& string);
	Strategy method_34(const Strategy& strategy_1, const QString& string_0, const QString& string_1);
	Group method_35(const QString& string);
	void xMgbWueRno(const Strategy& strategy_1, const QString& string, const Group& group);
};

} // namepsace QuantKit


using namespace QuantKit;

StrategyManagerPrivate::~StrategyManagerPrivate ()
{
}

void StrategyManagerPrivate::setMode(StrategyMode value)
{
	if (m_mode != value)
	{
		m_mode = value;
		switch (m_mode)
		{
			case StrategyMode.Backtest:
				m_framework.setMode() = FrameworkMode.Simulation;
				return;
			case StrategyMode.Paper:
				m_framework.setMode() = FrameworkMode.Realtime;
				return;
			case StrategyMode.Live:
				m_framework.setMode() = FrameworkMode.Realtime;
				break;
			default:
				return;
		}
	}
}

void StrategyManagerPrivate::clear()
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		byte_0 = 101;
		m_dictionary.Clear();
		m_global.Clear();
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

unsigned char StrategyManagerPrivate::getNextId()
{
	bool flag = false;
	byte result;
	try
	{
		Monitor.Enter(this, ref flag);
		byte b;
		byte_0 = (b = byte_0) + 1;
		result = b;
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
	return result;
}

void StrategyManagerPrivate::registerMarketDataRequest(const IDataProvider& dataProvider, const InstrumentList& instrumentList)
{
	InstrumentList instrumentList2 = new InstrumentList();
	InstrumentList instrumentList3 = null;
	if (!m_dictionary.TryGetValue(dataProvider, out instrumentList3))
	{
		instrumentList3 = new InstrumentList();
		m_dictionary[dataProvider] = instrumentList3;
	}
	foreach (Instrument current in instrumentList)
	{
		if (!instrumentList3.Contains(current.id()))
		{
			instrumentList3.Add(current);
			instrumentList2.Add(current);
		}
	}
	if (strategyStatus_0 == StrategyStatus.Running && instrumentList2.count() > 0 && m_framework.subscriptionManager() != null)
	{
		m_framework.subscriptionManager().Subscribe(dataProvider, instrumentList2);
	}
}

void StrategyManagerPrivate::startStrategy(const Strategy& strategy, StrategyMode mode)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		m_dictionary.Clear();
		strategy_0 = strategy;
		m_mode = mode;
		if (m_framework.mode() == FrameworkMode.Simulation)
		{
			m_framework.clock().setMode() = m_framework.providerManager().dataSimulator().dateTime1();
			m_framework.exchangeClock().setMode() = DateTime.MinValue;
		}
		if (m_framework.eventManager().status() != EventManagerStatus.Running)
		{
			m_framework.eventManager().Start();
		}
		StrategyStatusInfo strategyStatusInfo = new StrategyStatusInfo(m_framework.clock().dateTime(), StrategyStatusType.Started);
		strategyStatusInfo.setSolution() = ((strategy.name() == null) ? "Solution" : strategy.name());
		strategyStatusInfo.setMode() = mode.ToString();
		m_framework.eventServer().OnLog(new GroupEvent(strategyStatusInfo, null));
		strategy.Init();
		strategy.vmethod_0();
		if (!m_framework.isExternalDataQueue())
		{
			Dictionary<IDataProvider, InstrumentList> dictionary = new Dictionary<IDataProvider, InstrumentList>();
			while (m_dictionary.Count != 0)
			{
				Dictionary<IDataProvider, InstrumentList> dictionary2 = new Dictionary<IDataProvider, InstrumentList>(m_dictionary);
				m_dictionary.Clear();
				foreach (KeyValuePair<IDataProvider, InstrumentList> current in new Dictionary<IDataProvider, InstrumentList>(dictionary2))
				{
					InstrumentList instrumentList = null;
					if (!dictionary.TryGetValue(current.Key, out instrumentList))
					{
						instrumentList = new InstrumentList();
						dictionary[current.Key] = instrumentList;
					}
					InstrumentList instrumentList2 = new InstrumentList();
					foreach (Instrument current2 in current.Value)
					{
						if (!instrumentList.Contains(current2))
						{
							instrumentList.Add(current2);
							instrumentList2.Add(current2);
						}
					}
					if (current.Key is SellSideStrategy && m_framework.subscriptionManager() != null)
					{
						m_framework.subscriptionManager().Subscribe(current.Key, instrumentList2);
					}
				}
			}
			method_1();
			strategyStatus_0 = StrategyStatus.Running;
			m_dictionary = dictionary;
			if (m_dictionary.Count == 0 && mode == StrategyMode.Backtest)
			{
				Console.WriteLine(string.Concat(new object[]
				{
					DateTime.Now,
					" StrategyManager::StartStrategy ",
					strategy.name(),
					" has no data requests in backtest mode, stopping..."
				}));
				method_2();
			}
			else
			{
				foreach (KeyValuePair<IDataProvider, InstrumentList> current3 in m_dictionary)
				{
					if (!(current3.Key is SellSideStrategy) && m_framework.subscriptionManager() != null)
					{
						m_framework.subscriptionManager().Subscribe(current3.Key, current3.Value);
					}
				}
				if (mode != StrategyMode.Backtest && strategy.fundamentalProvider() != null)
				{
					strategy.fundamentalProvider().Connect();
				}
			}
		}
		else
		{
			method_1();
			strategyStatus_0 = StrategyStatus.Running;
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void StrategyManagerPrivate::stop()
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		if (strategyStatus_0 != StrategyStatus.Stopped)
		{
			strategyStatus_0 = StrategyStatus.Stopped;
			method_2();
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void StrategyManagerPrivate::method_1()
{
	Group group = method_35("StrategyParameters");
	if (group == null)
	{
		group = new Group("StrategyParameters");
		m_framework.groupManager().Add(group);
	}
	else
	{
		m_framework.eventServer().OnLog(group);
	}
	xMgbWueRno(strategy_0, "", group);
}

void StrategyManagerPrivate::method_2()
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		Console.WriteLine(DateTime.Now + " StrategyManager::StopStrategy " + strategy_0.name());
		StrategyStatusInfo strategyStatusInfo = new StrategyStatusInfo(m_framework.clock().dateTime(), StrategyStatusType.Stopped);
		strategyStatusInfo.setSolution() = ((strategy_0.name() == null) ? "Solution" : strategy_0.name());
		strategyStatusInfo.setMode() = m_mode.ToString();
		m_framework.eventServer().OnLog(new GroupEvent(strategyStatusInfo, null));
		if (!m_framework.isExternalDataQueue())
		{
			foreach (KeyValuePair<IDataProvider, InstrumentList> current in new Dictionary<IDataProvider, InstrumentList>(m_dictionary))
			{
				if (m_framework.subscriptionManager() != null)
				{
					m_framework.subscriptionManager().Unsubscribe(current.Key, current.Value);
				}
			}
		}
		if (strategy_0.status() == StrategyStatus.Stopped)
		{
			Console.WriteLine("StrategyManager::Stop Error: Can not stop stopped strategy ( " + strategy_0.name() + ")");
		}
		else
		{
			strategy_0.vmethod_1();
			if (m_framework.mode() == FrameworkMode.Simulation)
			{
				m_framework.providerManager().dataSimulator().Disconnect();
				m_framework.providerManager().executionSimulator().Disconnect();
			}
			if (strategy_0.dataProvider() != null)
			{
				strategy_0.dataProvider().Disconnect();
			}
			if (strategy_0.executionProvider() != null)
			{
				strategy_0.executionProvider().Disconnect();
			}
			if (strategy_0.fundamentalProvider() != null)
			{
				strategy_0.fundamentalProvider().Disconnect();
			}
			strategyStatus_0 = StrategyStatus.Stopped;
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void StrategyManagerPrivate::method_32(const Strategy& strategy_1, const QString& string, const QVariant& object)
{
	object parameter = strategy_1.GetParameter(@string);
	if (parameter != null && !parameter.Equals(@object))
	{
		strategy_1.SetParameter(@string, @object);
		Parameter oldParameter = new Parameter(@string, parameter);
		Parameter newParameter = new Parameter(@string, @object);
		strategy_1.vmethod_36(oldParameter, newParameter);
		Console.WriteLine(string.Concat(new object[]
		{
			"OnUserCommand: Parameter[",
			@string,
			"] changed from ",
			parameter,
			" to ",
			@object,
			" at ",
			strategy_1.name()
		}));
	}
	foreach (Strategy current in strategy_1.strategies())
	{
		if (strategy_1.GetType() == current.GetType())
		{
			method_32(current, @string, @object);
		}
	}
}

void StrategyManagerPrivate::method_33(const Strategy& strategy_1, const QString& string)
{
	if (!strategy_1.ExecuteMethod(@string))
	{
		Console.WriteLine("OnUserCommand: Method: " + @string + " not found");
		return;
	}
	Console.WriteLine("OnUserCommand: Method[" + @string + "] executed at " + strategy_1.name());
	foreach (Strategy current in strategy_1.strategies())
	{
		if (strategy_1.GetType() == current.GetType())
		{
			method_33(current, @string);
		}
	}
}

Strategy StrategyManagerPrivate::method_34(const Strategy& strategy_1, const QString& string_0, const QString& string_1)
{
	Strategy strategy = null;
	string_0 += ((string_0 == "") ? strategy_1.name() : ("\\" + strategy_1.name()));
	if (string_0 == string_1)
	{
		return strategy_1;
	}
	foreach (Strategy current in strategy_1.strategies())
	{
		strategy = method_34(current, string_0, string_1);
		if (strategy != null)
		{
			break;
		}
	}
	return strategy;
}

Group StrategyManagerPrivate::method_35(const QString& string)
{
	foreach (Group current in m_framework.groupManager().groupList())
	{
		if (current.name() == @string)
		{
			return current;
		}
	}
	return null;
}

void StrategyManagerPrivate::xMgbWueRno(const Strategy& strategy_1, const QString& string, const Group& group)
{
	@string += ((@string == "") ? strategy_1.name() : ("\\" + strategy_1.name()));
	ParameterList parameters = strategy_1.GetParameters();
	parameters.setStrategyName() = @string;
	m_framework.eventServer().OnLog(new GroupEvent(parameters, group));
	foreach (Strategy current in strategy_1.strategies())
	{
		xMgbWueRno(current, @string, group);
	}
}


// Pubic API 

StrategyManager::StrategyManager(const Framework& framework)
	: d_ptr(new StrategyManagerPrivate(framework))
{
}

StrategyManager::~StrategyManager()
{
}

StrategyManager::StrategyManager (const StrategyManager &other)
	: d_ptr(other.d_ptr)
{
}

StrategyManager& StrategyManager::operator=(const StrategyManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool StrategyManager::operator==(const StrategyManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Global StrategyManager::global() const
{
	return d_ptr->global();
}

StrategyMode StrategyManager::mode() const
{
	return d_ptr->mode();
}

void StrategyManager::setMode(StrategyMode value)
{
	d_ptr->setMode(value);
}

void StrategyManager::clear()
{
	d_ptr->clear();
}

unsigned char StrategyManager::getNextId()
{
	return d_ptr->getNextId();
}

void StrategyManager::registerMarketDataRequest(const IDataProvider& dataProvider, const InstrumentList& instrumentList)
{
	d_ptr->registerMarketDataRequest(dataProvider, instrumentList);
}

void StrategyManager::startStrategy(const Strategy& strategy)
{
	d_ptr->startStrategy(strategy);
}

void StrategyManager::startStrategy(const Strategy& strategy, StrategyMode mode)
{
	d_ptr->startStrategy(strategy, mode);
}

void StrategyManager::stop()
{
	d_ptr->stop();
}

QDebug operator<<(QDebug dbg, const StrategyManager& strategymanager)
{
	return dbg << strategymanager.toString();
}

