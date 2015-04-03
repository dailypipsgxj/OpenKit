#include <QuantKit/Strategy.h>

#include <QuantKit/LinkedList.h>
#include <QuantKit/Portfolio.h>
#include <QuantKit/InstrumentList.h>
#include <QuantKit/BarSeries.h>
#include "TimeSeries_p.h"
#include <QuantKit/TickSeries.h>
#include <QuantKit/Clock.h>
#include <QuantKit/InstrumentManager.h>
#include <QuantKit/DataManager.h>
#include <QuantKit/ProviderManager.h>
#include <QuantKit/OrderManager.h>
#include <QuantKit/BarFactory.h>
#include <QuantKit/StrategyManager.h>
#include <QuantKit/EventManager.h>
#include <QuantKit/GroupManager.h>
#include <QuantKit/AccountDataManager.h>
#include <QuantKit/Global.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Event/ParameterList.h>
#include <QuantKit/Instrument.h>
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
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/Order.h>
#include <QuantKit/Event/OnFill.h>
#include <QuantKit/Event/OnTransaction.h>
#include <QuantKit/Position.h>
#include <QuantKit/Stop.h>
#include <QuantKit/Parameter.h>
#include <QuantKit/Event/Fill.h>
#include <QuantKit/Transaction.h>
#include "Event_p.h"
#include <QuantKit/Event/Group.h>
#include "DataObject_p.h"
#include <QuantKit/IdArray.h>
#include "Strategy_p.h"

using namespace QuantKit;

StrategyPrivate::~StrategyPrivate ()
{
}

bool getRaiseEvents() const
{
	return false;
}
void setRaiseEvents(bool value)
{
}

bool getBool_1() const
{
	return false;
}
void setBool_1(bool value)
{
}

IdArray<LinkedList<Strategy>> getIdArray() const
{
	return null;
}
void StrategyPrivate::setDataProvider(const IDataProvider& value)
{
	m_dataProvider = value;
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.setDataProvider() = m_dataProvider;
	}
}

void StrategyPrivate::setExecutionProvider(const IExecutionProvider& value)
{
	m_executionProvider = value;
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.setExecutionProvider() = m_executionProvider;
	}
}

void StrategyPrivate::setFundamentalProvider(const INewsProvider& value)
{
	m_fundamentalProvider = value;
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.setFundamentalProvider() = m_fundamentalProvider;
	}
}

void StrategyPrivate::addInstrument(const QString& symbol)
{
	Instrument instrument = m_global.instrumentManager().Get(symbol);
	if (instrument == null)
	{
		Console.WriteLine("Strategy::AddInstrument instrument with symbol " + symbol + " doesn't exist in the framework");
		return;
	}
	AddInstrument(instrument);
}

void StrategyPrivate::addInstrument(int id)
{
	Instrument byId = m_global.instrumentManager().GetById(id);
	if (byId == null)
	{
		Console.WriteLine("Strategy::AddInstrument instrument with Id " + id + " doesn't exist in the framework");
		return;
	}
	AddInstrument(byId);
}

void StrategyPrivate::addInstrument(const Instrument& instrument)
{
	if (m_instruments.Contains(instrument))
	{
		Console.WriteLine("Strategy::AddInstrument " + instrument + " is already added");
		return;
	}
	m_instruments.Add(instrument);
	m_position.method_0(instrument);
	if (m_status == StrategyStatus.Running)
	{
		method_2(instrument);
	}
	vmethod_2(instrument);
}

void StrategyPrivate::addInstruments(QString symbols)
{
	for (int i = 0; i < symbols.Length; i++)
	{
		string symbol = symbols[i];
		AddInstrument(m_global.instrumentManager().Get(symbol));
	}
}

void StrategyPrivate::addInstruments(const InstrumentList& instruments)
{
	foreach (Instrument current in instruments)
	{
		AddInstrument(current);
	}
}

void StrategyPrivate::addStop(const Stop& stop)
{
	list_0.Add(stop);
	if (idArray_3[stop.instrument().id()] == null)
	{
		idArray_3[stop.instrument().id()] = new List<Stop>();
	}
	idArray_3[stop.instrument().id()].Add(stop);
}

void StrategyPrivate::addStrategy(const Strategy& strategy, bool callOnStrategyStart)
{
	strategy.setId() = m_global.strategyManager().GetNextId();
	strategy.setParent() = this;
	m_strategies.Add(strategy);
	strategy.setStatus() = m_status;
	if (m_status == StrategyStatus.Running)
	{
		method_3(strategy, strategy.instruments(), (int)strategy.id());
		if (callOnStrategyStart)
		{
			strategy.vmethod_0();
		}
	}
}

Order StrategyPrivate::buy(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.Market, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::buyLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.Limit, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setPrice() = price;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::buyLimitOrder(const Instrument& instrument, double qty, double price, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.Limit, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setPrice() = price;
	m_global.orderManager().Register(order);
	return order;
}

Order StrategyPrivate::buyOrder(const Instrument& instrument, double qty, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.Market, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	m_global.orderManager().Register(order);
	return order;
}

Order StrategyPrivate::buyStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.Stop, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::buyStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.StopLimit, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	order.setPrice() = price;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::buyStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.StopLimit, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	order.setPrice() = price;
	m_global.orderManager().Register(order);
	return order;
}

Order StrategyPrivate::buyStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.Stop, OrderSide.Buy, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	m_global.orderManager().Register(order);
	return order;
}

void StrategyPrivate::cancelAll()
{
	List<Order> list = new List<Order>();
	foreach (Order current in m_global.orderManager().orders())
	{
		if (current.strategyId() == (int)m_id && !current.isDone())
		{
			list.Add(current);
		}
	}
	foreach (Order current2 in list)
	{
		Cancel(current2);
	}
}

void StrategyPrivate::cancelAll(const Instrument& instrument)
{
	List<Order> list = new List<Order>();
	foreach (Order current in m_global.orderManager().orders())
	{
		if (current.strategyId() == (int)m_id && current.instrument() == instrument && !current.isDone())
		{
			list.Add(current);
		}
	}
	foreach (Order current2 in list)
	{
		Cancel(current2);
	}
}

bool StrategyPrivate::executeMethod(const QString& methodName)
{
	bool result = false;
	MethodInfo[] methods = base.GetType().GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public);
	MethodInfo[] array = methods;
	for (int i = 0; i < array.Length; i++)
	{
		MethodInfo methodInfo = array[i];
		if (methodInfo.GetCustomAttributes(typeof(StrategyMethodAttribute), true).Length > 0 && methodInfo.GetParameters().Length == 0 && methodInfo.Name == methodName)
		{
			methodInfo.Invoke(this, null);
			result = true;
			return result;
		}
	}
	return result;
}

QString StrategyPrivate::getModeAsString()
{
	switch (m_strategyManager)
	{
		case StrategyMode.Backtest:
			return "Backtest";
		case StrategyMode.Paper:
			return "Paper";
		case StrategyMode.Live:
			return "Live";
		default:
			return "Undefined";
	}
}

QVariant StrategyPrivate::getParameter(const QString& name)
{
	FieldInfo field = base.GetType().GetField(name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
	PropertyInfo property = base.GetType().GetProperty(name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
	if (field == null && property == null)
	{
		return null;
	}
	if (field != null && field.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
	{
		return field.GetValue(this);
	}
	if (property != null && property.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
	{
		return property.GetValue(this);
	}
	return null;
}

ParameterList StrategyPrivate::getParameters()
{
	ParameterList parameterList = new ParameterList();
	parameterList.setStrategyName() = m_name;
	PropertyInfo[] properties = base.GetType().GetProperties(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
	PropertyInfo[] array = properties;
	for (int i = 0; i < array.Length; i++)
	{
		PropertyInfo propertyInfo = array[i];
		if (propertyInfo.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
		{
			List<Attribute> list = new List<Attribute>();
			foreach (Attribute current in propertyInfo.GetCustomAttributes())
			{
				if (current.GetType().FullName.Contains("ComponentModel") && current.GetType().Name != "PropertyTabAttribute" && current.GetType().Name != "ToolboxItemAttribute")
				{
					list.Add(current);
				}
			}
			parameterList.Add(new Parameter(propertyInfo.Name, propertyInfo.GetValue(this), list.ToArray()));
		}
	}
	FieldInfo[] fields = base.GetType().GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
	FieldInfo[] array2 = fields;
	for (int j = 0; j < array2.Length; j++)
	{
		FieldInfo fieldInfo = array2[j];
		if (fieldInfo.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
		{
			List<Attribute> list2 = new List<Attribute>();
			foreach (Attribute current2 in fieldInfo.GetCustomAttributes())
			{
				if (current2.GetType().FullName.Contains("ComponentModel") && current2.GetType().Name != "PropertyTabAttribute" && current2.GetType().Name != "ToolboxItemAttribute")
				{
					list2.Add(current2);
				}
			}
			parameterList.Add(new Parameter(fieldInfo.Name, fieldInfo.GetValue(this), list2.ToArray()));
		}
	}
	MethodInfo[] methods = base.GetType().GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public);
	MethodInfo[] array3 = methods;
	for (int k = 0; k < array3.Length; k++)
	{
		MethodInfo methodInfo = array3[k];
		if (methodInfo.GetCustomAttributes(typeof(StrategyMethodAttribute), true).Length > 0 && methodInfo.GetParameters().Length == 0)
		{
			parameterList.methods().Add(methodInfo.Name);
		}
	}
	return parameterList;
}

QString StrategyPrivate::getStatusAsString()
{
	switch (m_status)
	{
		case StrategyStatus.Running:
			return "Running";
		case StrategyStatus.Stopped:
			return "Stopped";
		default:
			return "Undefined";
	}
}

Strategy StrategyPrivate::getStrategy(const QString& name)
{
	string[] array = name.Split(new char[]
	{
		'\\',
		'/'
	});
	Strategy strategy = this;
	string[] array2 = array;
	for (int i = 0; i < array2.Length; i++)
	{
		string string_ = array2[i];
		strategy = strategy.method_1(string_);
		if (strategy == null)
		{
			return null;
		}
	}
	return strategy;
}

void StrategyPrivate::init()
{
	if (!bool_1)
	{
		OnStrategyInit();
		for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.Init();
		}
		bool_1 = true;
	}
}

Order StrategyPrivate::order(const Instrument& instrument, OrderType type, OrderSide side, double qty, double stopPx, double price, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, type, side, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	order.setPrice() = price;
	m_global.orderManager().Register(order);
	return order;
}

void StrategyPrivate::removeInstrument(const QString& symbol)
{
	Instrument instrument = m_global.instrumentManager().Get(symbol);
	if (instrument == null)
	{
		Console.WriteLine("Strategy::RemoveInstrument instrument with symbol " + symbol + " doesn't exist in the framework");
		return;
	}
	RemoveInstrument(instrument);
}

void StrategyPrivate::removeInstrument(int id)
{
	Instrument byId = m_global.instrumentManager().GetById(id);
	if (byId == null)
	{
		Console.WriteLine("Strategy::RemoveInstrument instrument with Id " + id + " doesn't exist in the framework");
		return;
	}
	RemoveInstrument(byId);
}

void StrategyPrivate::removeInstrument(const Instrument& instrument)
{
	if (!m_instruments.Contains(instrument))
	{
		Console.WriteLine("Strategy::RemoveInstrument " + instrument + " doesn't exist in the strategy instrument list");
		return;
	}
	m_instruments.Remove(instrument);
	InstrumentList instrumentList = new InstrumentList();
	instrumentList.Add(instrument);
	m_global.strategyManager().method_0(method_7(this, instrument), instrumentList);
	if (m_parent != null)
	{
		m_parent.method_4(this, instrumentList, (int)m_id);
	}
	vmethod_3(instrument);
}

void StrategyPrivate::removeStrategy(const Strategy& strategy)
{
}

void StrategyPrivate::respond(const DataObject& data, int commandId)
{
}

Order StrategyPrivate::sell(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.Market, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::sellLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.Limit, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setPrice() = price;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::sellLimitOrder(const Instrument& instrument, double qty, double price, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.Limit, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setPrice() = price;
	m_global.orderManager().Register(order);
	return order;
}

Order StrategyPrivate::sellOrder(const Instrument& instrument, double qty, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.Market, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	m_global.orderManager().Register(order);
	return order;
}

Order StrategyPrivate::sellStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.Stop, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::sellStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	Order order = new Order(provider, m_position, instrument, OrderType.StopLimit, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	order.setPrice() = price;
	m_global.orderManager().Send(order);
	return order;
}

Order StrategyPrivate::sellStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.StopLimit, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	order.setPrice() = price;
	m_global.orderManager().Register(order);
	return order;
}

Order StrategyPrivate::sellStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	Order order = new Order(method_6(instrument), m_position, instrument, OrderType.Stop, OrderSide.Sell, qty, 0.0, 0.0, TimeInForce.Day, 0, "");
	order.setStrategyId() = (int)m_id;
	order.setText() = text;
	order.setStopPx() = stopPx;
	m_global.orderManager().Register(order);
	return order;
}

void StrategyPrivate::setParameter(const QString& name, const QVariant& value)
{
	FieldInfo field = base.GetType().GetField(name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
	PropertyInfo property = base.GetType().GetProperty(name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
	if (field == null && property == null)
	{
		return;
	}
	if (field != null && field.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
	{
		field.SetValue(this, value);
		return;
	}
	if (property != null && property.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
	{
		property.SetValue(this, value);
	}
}

//protected
void StrategyPrivate::method_3(const Strategy& strategy_1, const InstrumentList& instrumentList_1, int int)
{
	strategy_1.position().setParent() = m_position;
	foreach (Instrument current in instrumentList_1)
	{
		LinkedList<Strategy> linkedList;
		if (m_idArray[current.id()] == null)
		{
			linkedList = new LinkedList<Strategy>();
			m_idArray[current.id()] = linkedList;
		}
		else
		{
			linkedList = m_idArray[current.id()];
		}
		linkedList.Add(strategy_1);
		IdArray<int> idArray;
		int id;
		(idArray = idArray_2)[id = current.id()] = idArray[id] + 1;
	}
	Dictionary<IDataProvider, InstrumentList> dictionary = new Dictionary<IDataProvider, InstrumentList>();
	foreach (Instrument current2 in instrumentList_1)
	{
		InstrumentList instrumentList = null;
		IDataProvider dataProvider = method_7(strategy_1, current2);
		IExecutionProvider executionProvider = strategy_1.method_6(current2);
		if (dataProvider.status() == ProviderStatus.Disconnected)
		{
			dataProvider.Connect();
		}
		if (executionProvider.status() == ProviderStatus.Disconnected)
		{
			executionProvider.Connect();
		}
		if (!dictionary.TryGetValue(dataProvider, out instrumentList))
		{
			instrumentList = new InstrumentList();
			dictionary[dataProvider] = instrumentList;
		}
		instrumentList.Add(current2);
	}
	foreach (KeyValuePair<IDataProvider, InstrumentList> current3 in dictionary)
	{
		m_global.strategyManager().RegisterMarketDataRequest(current3.Key, current3.Value);
	}
	idArray_1[@int] = strategy_1;
	if (m_parent != null)
	{
		m_parent.method_3(this, instrumentList_1, @int);
	}
}

void StrategyPrivate::method_4(const Strategy& strategy_1, const InstrumentList& instrumentList_1, int int)
{
	strategy_1.position().setParent() = m_position;
	foreach (Instrument current in instrumentList_1)
	{
		LinkedList<Strategy> linkedList = m_idArray[current.id()];
		if (linkedList != null)
		{
			linkedList.Remove(strategy_1);
		}
		linkedList.Add(strategy_1);
		IdArray<int> idArray;
		int id;
		(idArray = idArray_2)[id = current.id()] = idArray[id] - 1;
		if (idArray_2[current.id()] == 0)
		{
			m_instruments.Remove(current);
		}
	}
	Dictionary<IDataProvider, InstrumentList> dictionary = new Dictionary<IDataProvider, InstrumentList>();
	foreach (Instrument current2 in instrumentList_1)
	{
		InstrumentList instrumentList = null;
		IDataProvider key = method_7(strategy_1, current2);
		if (!dictionary.TryGetValue(key, out instrumentList))
		{
			instrumentList = new InstrumentList();
			dictionary[key] = instrumentList;
		}
		instrumentList.Add(current2);
	}
	foreach (KeyValuePair<IDataProvider, InstrumentList> current3 in dictionary)
	{
		m_global.strategyManager().method_0(current3.Key, current3.Value);
	}
	idArray_1[@int] = null;
	if (m_parent != null)
	{
		m_parent.method_4(this, instrumentList_1, @int);
	}
}

INewsProvider StrategyPrivate::method_5(Instrument instrument)
{
	if (m_global.mode() == FrameworkMode.Simulation)
	{
		return null;
	}
	return m_fundamentalProvider;
}

IExecutionProvider StrategyPrivate::method_6(Instrument instrument)
{
	IExecutionProvider executionProvider = null;
	if (instrument != null && instrument.executionProvider() != null)
	{
		executionProvider = instrument.executionProvider();
	}
	if (executionProvider == null && m_executionProvider != null)
	{
		executionProvider = m_executionProvider;
	}
	if (m_strategyManager != StrategyMode.Live)
	{
		if (executionProvider != null && executionProvider is SellSideStrategy)
		{
			return executionProvider;
		}
		return m_global.providerManager().executionSimulator();
	}
	else
	{
		if (executionProvider != null)
		{
			return executionProvider;
		}
		return m_global.executionProvider();
	}
}

IDataProvider StrategyPrivate::method_7(const Strategy& strategy_1, Instrument instrument)
{
	IDataProvider dataProvider = null;
	if (instrument != null && instrument.dataProvider() != null)
	{
		dataProvider = instrument.dataProvider();
	}
	if (dataProvider == null && strategy_1 != null && strategy_1.dataProvider() != null)
	{
		dataProvider = strategy_1.dataProvider();
	}
	if (m_global.mode() == FrameworkMode.Simulation)
	{
		if (dataProvider != null && dataProvider is SellSideStrategy)
		{
			return dataProvider;
		}
		return m_global.providerManager().dataSimulator();
	}
	else
	{
		if (dataProvider != null)
		{
			return dataProvider;
		}
		return m_global.dataProvider();
	}
}

void StrategyPrivate::onAsk(const Instrument& instrument, const Ask& ask)
{
}

void StrategyPrivate::onBar(const Instrument& instrument, const Bar& bar)
{
}

void StrategyPrivate::onBarOpen(const Instrument& instrument, const Bar& bar)
{
}

void StrategyPrivate::onBarSlice(const BarSlice& slice)
{
}

void StrategyPrivate::onBid(const Instrument& instrument, const Bid& bid)
{
}

void StrategyPrivate::onExchangeReminder(const QDateTime& dateTime, const QVariant& data)
{
}

void StrategyPrivate::onExecutionReport(const ExecutionReport& report)
{
}

void StrategyPrivate::onFill(const Fill& fill)
{
}

void StrategyPrivate::onFundamental(const Instrument& instrument, const Fundamental& fundamental)
{
}

void StrategyPrivate::onInstrumentAdded(const Instrument& instrument)
{
}

void StrategyPrivate::onInstrumentRemoved(const Instrument& instrument)
{
}

void StrategyPrivate::onLevel2(const Instrument& instrument, const Level2Snapshot& snapshot)
{
}

void StrategyPrivate::onLevel2(const Instrument& instrument, const Level2Update& update)
{
}

void StrategyPrivate::onNewOrder(const Order& order)
{
}

void StrategyPrivate::onNews(const Instrument& instrument, const News& news)
{
}

void StrategyPrivate::onOrderCancelled(const Order& order)
{
}

void StrategyPrivate::onOrderDone(const Order& order)
{
}

void StrategyPrivate::onOrderFilled(const Order& order)
{
}

void StrategyPrivate::onOrderPartiallyFilled(const Order& order)
{
}

void StrategyPrivate::onOrderRejected(const Order& order)
{
}

void StrategyPrivate::onOrderReplaced(const Order& order)
{
}

void StrategyPrivate::onOrderReplaceRejected(const Order& order)
{
}

void StrategyPrivate::onOrderStatusChanged(const Order& order)
{
}

void StrategyPrivate::onParameterChanged(const Parameter& oldParameter, const Parameter& newParameter)
{
}

void StrategyPrivate::onPendingNewOrder(const Order& order)
{
}

void StrategyPrivate::onPositionChanged(const Position& position)
{
}

void StrategyPrivate::onPositionClosed(const Position& position)
{
}

void StrategyPrivate::onPositionOpened(const Position& position)
{
}

void StrategyPrivate::onProviderConnected(const Provider& provider)
{
}

void StrategyPrivate::onProviderDisconnected(const Provider& provider)
{
}

void StrategyPrivate::onProviderError(const ProviderError& error)
{
}

void StrategyPrivate::onReminder(const QDateTime& dateTime, const QVariant& data)
{
}

void StrategyPrivate::onSendOrder(const Order& order)
{
}

void StrategyPrivate::onStopCancelled(const Stop& stop)
{
}

void StrategyPrivate::onStopExecuted(const Stop& stop)
{
}

void StrategyPrivate::onStopStatusChanged(const Stop& stop)
{
}

void StrategyPrivate::onStopStatusChanged_(const Stop& stop)
{
	if (raiseEvents)
	{
		switch (stop.status())
		{
			case StopStatus.Executed:
				OnStopExecuted(stop);
				break;
			case StopStatus.Canceled:
				OnStopCancelled(stop);
				break;
		}
		OnStopStatusChanged(stop);
		list_0.Remove(stop);
		idArray_3[stop.instrument().id()].Remove(stop);
	}
}

void StrategyPrivate::onStrategyEvent(const QVariant& data)
{
}

void StrategyPrivate::onStrategyInit()
{
}

void StrategyPrivate::onStrategyStart()
{
}

void StrategyPrivate::onStrategyStop()
{
}

void StrategyPrivate::onTrade(const Instrument& instrument, const Trade& trade)
{
}

void StrategyPrivate::onTransaction(const Transaction& transaction)
{
}

void StrategyPrivate::onUserCommand(const QString& command)
{
}

void StrategyPrivate::vmethod_0()
{
	m_status = StrategyStatus.Running;
	foreach (Instrument current in m_instruments)
	{
		method_2(current);
	}
	if (raiseEvents)
	{
		OnStrategyStart();
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		method_3(linkedListNode.Data, linkedListNode.Data.instruments(), (int)linkedListNode.Data.id());
		linkedListNode.Data.vmethod_0();
	}
}

void StrategyPrivate::vmethod_1()
{
	m_status = StrategyStatus.Stopped;
	if (raiseEvents)
	{
		OnStrategyStop();
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_1();
	}
}

void StrategyPrivate::vmethod_10(const Ask& ask)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents && m_instruments.Contains(ask.instrumentId()))
	{
		OnAsk(m_global.instrumentManager().GetById(ask.instrumentId()), ask);
	}
	List<Stop> list = idArray_3[ask.instrumentId()];
	if (list != null)
	{
		for (int i = 0; i < list.Count; i++)
		{
			Stop stop = list[i];
			if (stop.connected())
			{
				stop.method_6(ask);
			}
		}
	}
	LinkedList<Strategy> linkedList = m_idArray[ask.instrumentId()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_10(ask);
		}
	}
}

void StrategyPrivate::vmethod_11(const Trade& trade)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents && m_instruments.Contains(trade.instrumentId()))
	{
		OnTrade(m_global.instrumentManager().GetById(trade.instrumentId()), trade);
	}
	List<Stop> list = idArray_3[trade.instrumentId()];
	if (list != null)
	{
		for (int i = 0; i < list.Count; i++)
		{
			Stop stop = list[i];
			if (stop.connected())
			{
				stop.method_4(trade);
			}
		}
	}
	LinkedList<Strategy> linkedList = m_idArray[trade.instrumentId()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_11(trade);
		}
	}
}

void StrategyPrivate::vmethod_12(const Level2Snapshot& snapshot)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents && m_instruments.Contains(snapshot.int_0()))
	{
		OnLevel2(m_global.instrumentManager().GetById(snapshot.int_0()), snapshot);
	}
	LinkedList<Strategy> linkedList = m_idArray[snapshot.int_0()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_12(snapshot);
		}
	}
}

void StrategyPrivate::vmethod_13(const Level2Update& update)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents)
	{
		OnLevel2(m_global.instrumentManager().GetById(update.int_0()), update);
	}
	LinkedList<Strategy> linkedList = m_idArray[update.int_0()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_13(update);
		}
	}
}

void StrategyPrivate::vmethod_14(const Bar& bar)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents && m_instruments.Contains(bar.instrumentId()))
	{
		OnBarOpen(m_global.instrumentManager().GetById(bar.instrumentId()), bar);
		List<Stop> list = idArray_3[bar.instrumentId()];
		if (list != null)
		{
			for (int i = 0; i < list.Count; i++)
			{
				Stop stop = list[i];
				if (stop.connected())
				{
					stop.method_3(bar);
				}
			}
		}
	}
	LinkedList<Strategy> linkedList = m_idArray[bar.instrumentId()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_14(bar);
		}
	}
}

void StrategyPrivate::vmethod_15(const Bar& bar)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents && m_instruments.Contains(bar.instrumentId()))
	{
		OnBar(m_global.instrumentManager().GetById(bar.instrumentId()), bar);
		List<Stop> list = idArray_3[bar.instrumentId()];
		if (list != null)
		{
			for (int i = 0; i < list.Count; i++)
			{
				Stop stop = list[i];
				if (stop.connected())
				{
					stop.method_2(bar);
				}
			}
		}
	}
	LinkedList<Strategy> linkedList = m_idArray[bar.instrumentId()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_15(bar);
		}
	}
}

void StrategyPrivate::vmethod_16(const BarSlice& slice)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents)
	{
		OnBarSlice(slice);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_16(slice);
	}
}

void StrategyPrivate::vmethod_17(const News& news)
{
	if (raiseEvents && m_instruments.Contains(news.int_1()))
	{
		OnNews(m_global.instrumentManager().GetById(news.int_1()), news);
	}
	LinkedList<Strategy> linkedList = m_idArray[news.int_1()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_17(news);
		}
	}
}

void StrategyPrivate::vmethod_18(const Fundamental& fundamental)
{
	if (!m_enabled)
	{
		return;
	}
	if (fundamental.int_1() == -1)
	{
		if (raiseEvents)
		{
			OnFundamental(null, fundamental);
		}
		for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_18(fundamental);
		}
		return;
	}
	if (raiseEvents && m_instruments.Contains(fundamental.int_1()))
	{
		OnFundamental(m_global.instrumentManager().GetById(fundamental.int_1()), fundamental);
	}
	LinkedList<Strategy> linkedList = m_idArray[fundamental.int_1()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode2 = linkedList.First; linkedListNode2 != null; linkedListNode2 = linkedListNode2.Next)
		{
			linkedListNode2.Data.vmethod_18(fundamental);
		}
	}
}

void StrategyPrivate::vmethod_19(const ExecutionReport& report)
{
	if (raiseEvents)
	{
		OnExecutionReport(report);
	}
	Strategy strategy = idArray_1[report.order().strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_19(report);
	}
}

void StrategyPrivate::vmethod_20(const Order& order)
{
	if (raiseEvents)
	{
		OnSendOrder(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_20(order);
	}
}

void StrategyPrivate::vmethod_21(const Order& order)
{
	if (raiseEvents)
	{
		OnPendingNewOrder(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_21(order);
	}
}

void StrategyPrivate::vmethod_22(const Order& order)
{
	if (raiseEvents)
	{
		OnNewOrder(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_22(order);
	}
}

void StrategyPrivate::vmethod_23(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderStatusChanged(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_23(order);
	}
}

void StrategyPrivate::vmethod_24(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderFilled(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_24(order);
	}
}

void StrategyPrivate::vmethod_25(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderPartiallyFilled(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_25(order);
	}
}

void StrategyPrivate::vmethod_26(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderCancelled(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_26(order);
	}
}

void StrategyPrivate::vmethod_27(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderReplaced(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_27(order);
	}
}

void StrategyPrivate::vmethod_28(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderRejected(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_28(order);
	}
}

void StrategyPrivate::vmethod_29(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderReplaceRejected(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_29(order);
	}
}

void StrategyPrivate::vmethod_30(const Order& order)
{
	if (raiseEvents)
	{
		OnOrderDone(order);
	}
	Strategy strategy = idArray_1[order.strategyId()];
	if (strategy != null)
	{
		strategy.vmethod_30(order);
	}
}

void StrategyPrivate::vmethod_31(const OnFill& fill)
{
	if (raiseEvents && fill.portfolio() == m_position)
	{
		OnFill(fill.fill());
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_31(fill);
	}
}

void StrategyPrivate::vmethod_32(const OnTransaction& transaction)
{
	if (raiseEvents && transaction.portfolio() == m_position)
	{
		OnTransaction(transaction.transaction());
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_32(transaction);
	}
}

void StrategyPrivate::vmethod_33(const Position& position)
{
	if (raiseEvents && position.value() == m_position)
	{
		OnPositionOpened(position);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_33(position);
	}
}

void StrategyPrivate::vmethod_34(const Position& position)
{
	if (raiseEvents && position.value() == m_position)
	{
		OnPositionClosed(position);
		List<Stop> list = idArray_3[position.instrument().id()];
		if (list != null)
		{
			for (int i = 0; i < list.Count; i++)
			{
				if (list[i].position() == position)
				{
					list[i].Cancel();
				}
			}
		}
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_34(position);
	}
}

void StrategyPrivate::vmethod_35(const Position& position)
{
	if (raiseEvents && position.value() == m_position)
	{
		OnPositionChanged(position);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_35(position);
	}
}

void StrategyPrivate::vmethod_36(const Parameter& oldParameter, const Parameter& newParameter)
{
	if (raiseEvents)
	{
		OnParameterChanged(oldParameter, newParameter);
	}
}

void StrategyPrivate::vmethod_37(const QVariant& data)
{
	if (raiseEvents)
	{
		OnStrategyEvent(data);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_37(data);
	}
}

void StrategyPrivate::vmethod_6(const Provider& provider)
{
	if (raiseEvents)
	{
		OnProviderConnected(provider);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_6(provider);
	}
}

void StrategyPrivate::vmethod_7(const Provider& provider)
{
	if (raiseEvents)
	{
		OnProviderDisconnected(provider);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_7(provider);
	}
}

void StrategyPrivate::vmethod_8(const ProviderError& error)
{
	if (raiseEvents)
	{
		OnProviderError(error);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.vmethod_8(error);
	}
}

void StrategyPrivate::vmethod_9(const Bid& bid)
{
	if (!m_enabled)
	{
		return;
	}
	if (raiseEvents && m_instruments.Contains(bid.instrumentId()))
	{
		OnBid(m_global.instrumentManager().GetById(bid.instrumentId()), bid);
		List<Stop> list = idArray_3[bid.instrumentId()];
		if (list != null)
		{
			for (int i = 0; i < list.Count; i++)
			{
				Stop stop = list[i];
				if (stop.connected())
				{
					stop.method_5(bid);
				}
			}
		}
	}
	LinkedList<Strategy> linkedList = m_idArray[bid.instrumentId()];
	if (linkedList != null)
	{
		for (LinkedListNode<Strategy> linkedListNode = linkedList.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
		{
			linkedListNode.Data.vmethod_9(bid);
		}
	}
}

void StrategyPrivate::yamOgfniBd(const QString& command)
{
	if (raiseEvents)
	{
		OnUserCommand(command);
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.yamOgfniBd(command);
	}
}

Strategy StrategyPrivate::method_1(const QString& string_1)
{
	foreach (Strategy current in m_strategies)
	{
		if (current.name() == string_1)
		{
			return current;
		}
	}
	return null;
}

void StrategyPrivate::method_2(const Instrument& instrument)
{
	InstrumentList instrumentList = new InstrumentList();
	instrumentList.Add(instrument);
	IDataProvider dataProvider = method_7(this, instrument);
	IExecutionProvider executionProvider = method_6(instrument);
	if (dataProvider != null && dataProvider.status() == ProviderStatus.Disconnected)
	{
		dataProvider.Connect();
	}
	if (executionProvider != null && executionProvider.status() == ProviderStatus.Disconnected)
	{
		executionProvider.Connect();
	}
	m_global.strategyManager().RegisterMarketDataRequest(dataProvider, instrumentList);
	if (m_parent != null)
	{
		m_parent.method_3(this, instrumentList, (int)m_id);
	}
}


// Pubic API 

Strategy::Strategy(const Framework& framework, const QString& name)
	: d_ptr(new StrategyPrivate(framework, name))
{
}

Strategy::~Strategy()
{
}

Strategy::Strategy (StrategyPrivate &dd)
	: d_ptr(&dd)
{
}

Strategy::Strategy (const Strategy &other)
	: d_ptr(other.d_ptr)
{
}

Strategy& Strategy::operator=(const Strategy &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Strategy::operator==(const Strategy &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

bool raiseEvents() const
{
	return d_ptr->
	setRaiseEvents()
}

void setRaiseEvents(bool value)
{
	d_ptr->raiseEvents(value);
}

bool bool_1() const
{
	return d_ptr->
	setBool_1()
}

void setBool_1(bool value)
{
	d_ptr->bool_1(value);
}

IdArray<LinkedList<Strategy>> idArray() const
{
	return d_ptr->
	setIdArray()
}

unsigned char Strategy::id() const
{
	return d_ptr->id();
}

QString Strategy::name() const
{
	return d_ptr->name();
}

bool Strategy::enabled() const
{
	return d_ptr->enabled();
}

void Strategy::setEnabled(bool value)
{
	d_ptr->setEnabled(value);
}

StrategyMode Strategy::mode() const
{
	return d_ptr->mode();
}

StrategyStatus Strategy::status() const
{
	return d_ptr->status();
}

Strategy Strategy::parent() const
{
	return d_ptr->parent();
}

LinkedList<Strategy> Strategy::strategies() const
{
	return d_ptr->strategies();
}

Portfolio Strategy::portfolio() const
{
	return d_ptr->portfolio();
}

InstrumentList Strategy::instruments() const
{
	return d_ptr->instruments();
}

BarSeries Strategy::bars() const
{
	return d_ptr->bars();
}

TimeSeries Strategy::equity() const
{
	return d_ptr->equity();
}

TickSeries Strategy::bids() const
{
	return d_ptr->bids();
}

TickSeries Strategy::asks() const
{
	return d_ptr->asks();
}

IDataProvider Strategy::dataProvider() const
{
	return d_ptr->dataProvider();
}

void Strategy::setDataProvider(const IDataProvider& value)
{
	d_ptr->setDataProvider(value);
}

IExecutionProvider Strategy::executionProvider() const
{
	return d_ptr->executionProvider();
}

void Strategy::setExecutionProvider(const IExecutionProvider& value)
{
	d_ptr->setExecutionProvider(value);
}

INewsProvider Strategy::fundamentalProvider() const
{
	return d_ptr->fundamentalProvider();
}

void Strategy::setFundamentalProvider(const INewsProvider& value)
{
	d_ptr->setFundamentalProvider(value);
}

Clock Strategy::clock() const
{
	return d_ptr->clock();
}

InstrumentManager Strategy::instrumentManager() const
{
	return d_ptr->instrumentManager();
}

DataManager Strategy::dataManager() const
{
	return d_ptr->dataManager();
}

IDataSimulator Strategy::dataSimulator() const
{
	return d_ptr->dataSimulator();
}

IExecutionSimulator Strategy::executionSimulator() const
{
	return d_ptr->executionSimulator();
}

ProviderManager Strategy::providerManager() const
{
	return d_ptr->providerManager();
}

OrderManager Strategy::orderManager() const
{
	return d_ptr->orderManager();
}

BarFactory Strategy::barFactory() const
{
	return d_ptr->barFactory();
}

StrategyManager Strategy::strategyManager() const
{
	return d_ptr->strategyManager();
}

EventManager Strategy::eventManager() const
{
	return d_ptr->eventManager();
}

GroupManager Strategy::groupManager() const
{
	return d_ptr->groupManager();
}

AccountDataManager Strategy::accountDataManager() const
{
	return d_ptr->accountDataManager();
}

Global Strategy::global() const
{
	return d_ptr->global();
}

void Strategy::addExchangeReminder(const QDateTime& dateTime, QVariant data)
{
	d_ptr->addExchangeReminder(dateTime, data);
}

void Strategy::addInstrument(const QString& symbol)
{
	d_ptr->addInstrument(symbol);
}

void Strategy::addInstrument(int id)
{
	d_ptr->addInstrument(id);
}

void Strategy::addInstrument(const Instrument& instrument)
{
	d_ptr->addInstrument(instrument);
}

void Strategy::addInstruments(QString symbols)
{
	d_ptr->addInstruments(symbols);
}

void Strategy::addInstruments(const InstrumentList& instruments)
{
	d_ptr->addInstruments(instruments);
}

void Strategy::addReminder(const QDateTime& dateTime, QVariant data)
{
	d_ptr->addReminder(dateTime, data);
}

void Strategy::addStop(const Stop& stop)
{
	d_ptr->addStop(stop);
}

void Strategy::addStrategy(const Strategy& strategy)
{
	d_ptr->addStrategy(strategy);
}

void Strategy::addStrategy(const Strategy& strategy, bool callOnStrategyStart)
{
	d_ptr->addStrategy(strategy, callOnStrategyStart);
}

Order Strategy::buy(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->buy(provider, instrument, qty, text);
}

Order Strategy::buy(short providerId, const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->buy(providerId, instrument, qty, text);
}

Order Strategy::buy(const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->buy(instrument, qty, text);
}

Order Strategy::buyLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->buyLimit(provider, instrument, qty, price, text);
}

Order Strategy::buyLimit(short providerId, const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->buyLimit(providerId, instrument, qty, price, text);
}

Order Strategy::buyLimit(const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->buyLimit(instrument, qty, price, text);
}

Order Strategy::buyLimitOrder(const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->buyLimitOrder(instrument, qty, price, text);
}

Order Strategy::buyOrder(const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->buyOrder(instrument, qty, text);
}

Order Strategy::buyStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->buyStop(provider, instrument, qty, stopPx, text);
}

Order Strategy::buyStop(short providerId, const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->buyStop(providerId, instrument, qty, stopPx, text);
}

Order Strategy::buyStop(const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->buyStop(instrument, qty, stopPx, text);
}

Order Strategy::buyStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->buyStopLimit(provider, instrument, qty, stopPx, price, text);
}

Order Strategy::buyStopLimit(short providerId, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->buyStopLimit(providerId, instrument, qty, stopPx, price, text);
}

Order Strategy::buyStopLimit(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->buyStopLimit(instrument, qty, stopPx, price, text);
}

Order Strategy::buyStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->buyStopLimitOrder(instrument, qty, stopPx, price, text);
}

Order Strategy::buyStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->buyStopOrder(instrument, qty, stopPx, text);
}

void Strategy::cancel(const Order& order)
{
	d_ptr->cancel(order);
}

void Strategy::cancelAll()
{
	d_ptr->cancelAll();
}

void Strategy::cancelAll(const Instrument& instrument)
{
	d_ptr->cancelAll(instrument);
}

void Strategy::deposit(const QDateTime& dateTime, double value, unsigned char currencyId, QString text, bool updateParent)
{
	d_ptr->deposit(dateTime, value, currencyId, text, updateParent);
}

void Strategy::deposit(double value, unsigned char currencyId, QString text, bool updateParent)
{
	d_ptr->deposit(value, currencyId, text, updateParent);
}

bool Strategy::executeMethod(const QString& methodName)
{
	return d_ptr->executeMethod(methodName);
}

QString Strategy::getModeAsString()
{
	return d_ptr->getModeAsString();
}

QVariant Strategy::getParameter(const QString& name)
{
	return d_ptr->getParameter(name);
}

ParameterList Strategy::getParameters()
{
	return d_ptr->getParameters();
}

QString Strategy::getStatusAsString()
{
	return d_ptr->getStatusAsString();
}

Strategy Strategy::getStrategy(const QString& name)
{
	return d_ptr->getStrategy(name);
}

bool Strategy::hasLongPosition(const Instrument& instrument)
{
	return d_ptr->hasLongPosition(instrument);
}

bool Strategy::hasLongPosition(const Instrument& instrument, double qty)
{
	return d_ptr->hasLongPosition(instrument, qty);
}

bool Strategy::hasPosition(const Instrument& instrument)
{
	return d_ptr->hasPosition(instrument);
}

bool Strategy::hasPosition(const Instrument& instrument, PositionSide side, double qty)
{
	return d_ptr->hasPosition(instrument, side, qty);
}

bool Strategy::hasShortPosition(const Instrument& instrument)
{
	return d_ptr->hasShortPosition(instrument);
}

bool Strategy::hasShortPosition(const Instrument& instrument, double qty)
{
	return d_ptr->hasShortPosition(instrument, qty);
}

void Strategy::init()
{
	d_ptr->init();
}

void Strategy::log(const Event& e, const Group& group)
{
	d_ptr->log(e, group);
}

void Strategy::log(const Event& e, int groupId)
{
	d_ptr->log(e, groupId);
}

void Strategy::log(const DataObject& data, const Group& group)
{
	d_ptr->log(data, group);
}

void Strategy::log(const DataObject& data, int groupId)
{
	d_ptr->log(data, groupId);
}

void Strategy::log(const QDateTime& dateTime, double value, const Group& group)
{
	d_ptr->log(dateTime, value, group);
}

void Strategy::log(const QDateTime& dateTime, double value, int groupId)
{
	d_ptr->log(dateTime, value, groupId);
}

void Strategy::log(const QDateTime& dateTime, const QString& text, const Group& group)
{
	d_ptr->log(dateTime, text, group);
}

void Strategy::log(const QDateTime& dateTime, const QString& text, int groupId)
{
	d_ptr->log(dateTime, text, groupId);
}

void Strategy::log(double value, const Group& group)
{
	d_ptr->log(value, group);
}

void Strategy::log(double value, int groupId)
{
	d_ptr->log(value, groupId);
}

void Strategy::log(const QString& text, const Group& group)
{
	d_ptr->log(text, group);
}

void Strategy::log(const QString& text, int groupId)
{
	d_ptr->log(text, groupId);
}

double Strategy::objective()
{
	return d_ptr->objective();
}

Order Strategy::order(const Instrument& instrument, OrderType type, OrderSide side, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->order(instrument, type, side, qty, stopPx, price, text);
}

void Strategy::reject(const Order& order)
{
	d_ptr->reject(order);
}

void Strategy::removeInstrument(const QString& symbol)
{
	d_ptr->removeInstrument(symbol);
}

void Strategy::removeInstrument(int id)
{
	d_ptr->removeInstrument(id);
}

void Strategy::removeInstrument(const Instrument& instrument)
{
	d_ptr->removeInstrument(instrument);
}

void Strategy::removeStrategy(const Strategy& strategy)
{
	d_ptr->removeStrategy(strategy);
}

void Strategy::replace(const Order& order, double price)
{
	d_ptr->replace(order, price);
}

void Strategy::replace(const Order& order, double price, double stopPx, double qty)
{
	d_ptr->replace(order, price, stopPx, qty);
}

void Strategy::respond(const DataObject& data, int commandId)
{
	d_ptr->respond(data, commandId);
}

void Strategy::respond(const DataObject& data)
{
	d_ptr->respond(data);
}

Order Strategy::sell(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->sell(provider, instrument, qty, text);
}

Order Strategy::sell(short providerId, const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->sell(providerId, instrument, qty, text);
}

Order Strategy::sell(const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->sell(instrument, qty, text);
}

Order Strategy::sellLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->sellLimit(provider, instrument, qty, price, text);
}

Order Strategy::sellLimit(short providerId, const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->sellLimit(providerId, instrument, qty, price, text);
}

Order Strategy::sellLimit(const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->sellLimit(instrument, qty, price, text);
}

Order Strategy::sellLimitOrder(const Instrument& instrument, double qty, double price, const QString& text)
{
	return d_ptr->sellLimitOrder(instrument, qty, price, text);
}

Order Strategy::sellOrder(const Instrument& instrument, double qty, const QString& text)
{
	return d_ptr->sellOrder(instrument, qty, text);
}

Order Strategy::sellStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->sellStop(provider, instrument, qty, stopPx, text);
}

Order Strategy::sellStop(short providerId, const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->sellStop(providerId, instrument, qty, stopPx, text);
}

Order Strategy::sellStop(const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->sellStop(instrument, qty, stopPx, text);
}

Order Strategy::sellStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->sellStopLimit(provider, instrument, qty, stopPx, price, text);
}

Order Strategy::sellStopLimit(short providerId, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->sellStopLimit(providerId, instrument, qty, stopPx, price, text);
}

Order Strategy::sellStopLimit(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->sellStopLimit(instrument, qty, stopPx, price, text);
}

Order Strategy::sellStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
{
	return d_ptr->sellStopLimitOrder(instrument, qty, stopPx, price, text);
}

Order Strategy::sellStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text)
{
	return d_ptr->sellStopOrder(instrument, qty, stopPx, text);
}

void Strategy::send(const Order& order)
{
	d_ptr->send(order);
}

void Strategy::sendStrategyEvent(const QVariant& data)
{
	d_ptr->sendStrategyEvent(data);
}

void Strategy::setParameter(const QString& name, const QVariant& value)
{
	d_ptr->setParameter(name, value);
}

void Strategy::withdraw(const QDateTime& dateTime, double value, unsigned char currencyId, QString text, bool updateParent)
{
	d_ptr->withdraw(dateTime, value, currencyId, text, updateParent);
}

void Strategy::withdraw(double value, unsigned char currencyId, QString text, bool updateParent)
{
	d_ptr->withdraw(value, currencyId, text, updateParent);
}

QDebug operator<<(QDebug dbg, const Strategy& strategy)
{
	return dbg << strategy.toString();
}

