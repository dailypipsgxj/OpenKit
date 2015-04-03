#ifndef __QUANTKIT_STRATEGY_PRIVATE_H__
#define __QUANTKIT_STRATEGY_PRIVATE_H__

#include <QuantKit/Strategy.h>

#include <QSharedData>

#include "LinkedList_p.h"
#include "Portfolio_p.h"
#include "InstrumentList_p.h"
#include "BarSeries_p.h"
#include "TimeSeries_p.h"
#include "TickSeries_p.h"
#include "Clock_p.h"
#include "InstrumentManager_p.h"
#include "DataManager_p.h"
#include "ProviderManager_p.h"
#include "OrderManager_p.h"
#include "BarFactory_p.h"
#include "StrategyManager_p.h"
#include "EventManager_p.h"
#include "GroupManager_p.h"
#include "AccountDataManager_p.h"
#include "Global_p.h"
#include "Framework_p.h"
#include "ParameterList_p.h"
#include "Instrument_p.h"
#include "Provider_p.h"
#include "ProviderError_p.h"
#include "Bid_p.h"
#include "Ask_p.h"
#include "Trade_p.h"
#include "Level2Snapshot_p.h"
#include "Level2Update_p.h"
#include "Bar_p.h"
#include "BarSlice_p.h"
#include "News_p.h"
#include "Fundamental_p.h"
#include "ExecutionReport_p.h"
#include "Order_p.h"
#include "OnFill_p.h"
#include "OnTransaction_p.h"
#include "Position_p.h"
#include "Stop_p.h"
#include "Parameter_p.h"
#include "Fill_p.h"
#include "Transaction_p.h"
#include "Event_p.h"
#include "Group_p.h"
#include "DataObject_p.h"
#include "IdArray_p.h"

namespace QuantKit {

class StrategyPrivate : public QSharedData
{
public:
	IdArray<LinkedList<Strategy>> m_idArray;
	IdArray<Strategy> idArray_1;
	IdArray<int> idArray_2;
	bool raiseEvents;
	Framework m_global;
	unsigned char m_id;
	QString m_name;
	bool m_enabled;
	bool bool_1;
	StrategyStatus m_status;
	Portfolio m_position;
	InstrumentList m_instruments;
	IDataProvider m_dataProvider;
	IExecutionProvider m_executionProvider;
	INewsProvider m_fundamentalProvider;
	LinkedList<Strategy> m_strategies;
	Strategy m_parent;
	TickSeries m_bids;
	TickSeries m_asks;
	TickSeries tickSeries_2;
	BarSeries m_bars;
	TimeSeries m_equity;
	QList<Stop> list_0;
	IdArray<QList<Stop>> idArray_3;

public:
	StrategyPrivate(const Framework& framework, const QString& name)
	{
		framework.portfolioManager().Add(m_position);
	}

	virtual ~StrategyPrivate();

public:
	bool getRaiseEvents() const;
	void setRaiseEvents(bool value);

	bool getBool_1() const;
	void setBool_1(bool value);
	IdArray<LinkedList<Strategy>> getIdArray() const;
	unsigned char id() const { return m_id; }
	QString name() const { return m_name; }
	bool enabled() const { return m_enabled; }
	void setEnabled(bool value) { m_enabled = value; }
	StrategyMode mode() const
	{
		return m_global.strategyManager().mode();
	}

	StrategyStatus status() const { return m_status; }
	Strategy parent() const { return m_parent; }
	LinkedList<Strategy> strategies() const { return m_strategies; }
	Portfolio portfolio() const { return m_position; }
	InstrumentList instruments() const { return m_instruments; }
	BarSeries bars() const { return m_bars; }
	TimeSeries equity() const { return m_equity; }
	TickSeries bids() const { return m_bids; }
	TickSeries asks() const { return m_asks; }
	virtual IDataProvider dataProvider() const Q_DECL_OVERRIDE { return method_7(this, null); }
	virtual void setDataProvider(const IDataProvider& value) Q_DECL_OVERRIDE;
	virtual IExecutionProvider executionProvider() const Q_DECL_OVERRIDE { return method_6(null); }
	virtual void setExecutionProvider(const IExecutionProvider& value) Q_DECL_OVERRIDE;
	virtual INewsProvider fundamentalProvider() const Q_DECL_OVERRIDE { return method_5(null); }
	virtual void setFundamentalProvider(const INewsProvider& value) Q_DECL_OVERRIDE;
	Clock clock() const { return m_global.clock(); }
	InstrumentManager instrumentManager() const
	{
		return m_global.instrumentManager();
	}

	DataManager dataManager() const { return m_global.dataManager(); }
	IDataSimulator dataSimulator() const
	{
		return m_global.providerManager().dataSimulator();
	}

	IExecutionSimulator executionSimulator() const
	{
		return m_global.providerManager().executionSimulator();
	}

	ProviderManager providerManager() const
	{
		return m_global.providerManager();
	}

	OrderManager orderManager() const
	{
		return m_global.orderManager();
	}

	BarFactory barFactory() const
	{
		return m_global.eventManager().barFactory();
	}

	StrategyManager strategyManager() const
	{
		return m_global.strategyManager();
	}

	EventManager eventManager() const
	{
		return m_global.eventManager();
	}

	GroupManager groupManager() const
	{
		return m_global.groupManager();
	}

	AccountDataManager accountDataManager() const
	{
		return m_global.accountDataManager();
	}

	Global global() const
	{
		return m_global.strategyManager().global();
	}

	void addExchangeReminder(const QDateTime& dateTime, const QVariant& data)
	{
		m_global.exchangeClock().AddReminder(new ReminderCallback(vmethod_5()), dateTime, data);
	}

	void addInstrument(const QString& symbol);
	void addInstrument(int id);
	virtual void addInstrument(const Instrument& instrument) Q_DECL_OVERRIDE;
	void addInstruments(const QString& symbols);
	void addInstruments(const InstrumentList& instruments);
	void addReminder(const QDateTime& dateTime, const QVariant& data)
	{
		m_global.clock().AddReminder(new ReminderCallback(vmethod_4()), dateTime, data);
	}

	void addStop(const Stop& stop);
	void addStrategy(const Strategy& strategy) { AddStrategy(strategy, true); }
	void addStrategy(const Strategy& strategy, bool callOnStrategyStart);
	Order buy(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text);
	Order buy(short providerId, const Instrument& instrument, double qty, const QString& text)
	{
		return Buy(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, text);
	}

	Order buy(const Instrument& instrument, double qty, const QString& text)
	{
		return Buy(method_6(instrument), instrument, qty, text);
	}

	Order buyLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text);
	Order buyLimit(short providerId, const Instrument& instrument, double qty, double price, const QString& text)
	{
		return BuyLimit(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, price, text);
	}

	Order buyLimit(const Instrument& instrument, double qty, double price, const QString& text)
	{
		return BuyLimit(method_6(instrument), instrument, qty, price, text);
	}

	Order buyLimitOrder(const Instrument& instrument, double qty, double price, const QString& text);
	Order buyOrder(const Instrument& instrument, double qty, const QString& text);
	Order buyStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text);
	Order buyStop(short providerId, const Instrument& instrument, double qty, double stopPx, const QString& text)
	{
		return BuyStop(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, stopPx, text);
	}

	Order buyStop(const Instrument& instrument, double qty, double stopPx, const QString& text)
	{
		return BuyStop(method_6(instrument), instrument, qty, stopPx, text);
	}

	Order buyStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text);
	Order buyStopLimit(short providerId, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
	{
		return BuyStopLimit(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, stopPx, price, text);
	}

	Order buyStopLimit(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
	{
		return BuyStopLimit(method_6(instrument), instrument, qty, stopPx, price, text);
	}

	Order buyStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text);
	Order buyStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text);
	void cancel(const Order& order)
	{
		m_global.orderManager().Cancel(order);
	}

	void cancelAll();
	void cancelAll(const Instrument& instrument);
	void deposit(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
		m_position.account().Deposit(dateTime, value, currencyId, text, updateParent);
	}

	void deposit(double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
		m_position.account().Deposit(value, currencyId, text, updateParent);
	}

	bool executeMethod(const QString& methodName);
	QString getModeAsString();
	QVariant getParameter(const QString& name);
	ParameterList getParameters();
	QString getStatusAsString();
	Strategy getStrategy(const QString& name);
	bool hasLongPosition(const Instrument& instrument)
	{
		return m_position.HasLongPosition(instrument);
	}

	bool hasLongPosition(const Instrument& instrument, double qty)
	{
		return m_position.HasLongPosition(instrument, qty);
	}

	bool hasPosition(const Instrument& instrument)
	{
		return m_position.HasPosition(instrument);
	}

	bool hasPosition(const Instrument& instrument, PositionSide side, double qty)
	{
		return m_position.HasPosition(instrument, side, qty);
	}

	bool hasShortPosition(const Instrument& instrument)
	{
		return m_position.HasShortPosition(instrument);
	}

	bool hasShortPosition(const Instrument& instrument, double qty)
	{
		return m_position.HasShortPosition(instrument, qty);
	}

	virtual void init() Q_DECL_OVERRIDE;
	void log(const Event& e, const Group& group)
	{
		m_global.eventServer().OnLog(new GroupEvent(e, group));
	}

	void log(const Event& e, int groupId)
	{
		m_global.eventServer().OnLog(new GroupEvent(e, m_global.groupManager().groups()[groupId]));
	}

	void log(const DataObject& data, const Group& group)
	{
		m_global.eventServer().OnLog(new GroupEvent(data, group));
	}

	void log(const DataObject& data, int groupId)
	{
		m_global.eventServer().OnLog(new GroupEvent(data, m_global.groupManager().groups()[groupId]));
	}

	void log(const QDateTime& dateTime, double value, const Group& group)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TimeSeriesItem(dateTime, value), group));
	}

	void log(const QDateTime& dateTime, double value, int groupId)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TimeSeriesItem(dateTime, value), groupId));
	}

	void log(const QDateTime& dateTime, const QString& text, const Group& group)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TextInfo(dateTime, text), group));
	}

	void log(const QDateTime& dateTime, const QString& text, int groupId)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TextInfo(dateTime, text), groupId));
	}

	void log(double value, const Group& group)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TimeSeriesItem(m_global.clock().dateTime(), value), group));
	}

	void log(double value, int groupId)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TimeSeriesItem(m_global.clock().dateTime(), value), groupId));
	}

	void log(const QString& text, const Group& group)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TextInfo(m_global.clock().dateTime(), text), group));
	}

	void log(const QString& text, int groupId)
	{
		m_global.eventServer().OnLog(new GroupEvent(new TextInfo(m_global.clock().dateTime(), text), groupId));
	}

	virtual double objective() Q_DECL_OVERRIDE { return m_position.value(); }
	Order order(const Instrument& instrument, OrderType type, OrderSide side, double qty, double stopPx, double price, const QString& text);
	void reject(const Order& order)
	{
		m_global.orderManager().Reject(order);
	}

	void removeInstrument(const QString& symbol);
	void removeInstrument(int id);
	virtual void removeInstrument(const Instrument& instrument) Q_DECL_OVERRIDE;
	void removeStrategy(const Strategy& strategy);
	void replace(const Order& order, double price)
	{
		m_global.orderManager().Replace(order, price);
	}

	void replace(const Order& order, double price, double stopPx, double qty)
	{
		m_global.orderManager().Replace(order, price, stopPx, qty);
	}

	void respond(const DataObject& data, int commandId);
	void respond(const DataObject& data) { Respond(data, -1); }
	Order sell(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text);
	Order sell(short providerId, const Instrument& instrument, double qty, const QString& text)
	{
		return Sell(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, text);
	}

	Order sell(const Instrument& instrument, double qty, const QString& text)
	{
		return Sell(method_6(instrument), instrument, qty, text);
	}

	Order sellLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text);
	Order sellLimit(short providerId, const Instrument& instrument, double qty, double price, const QString& text)
	{
		return SellLimit(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, price, text);
	}

	Order sellLimit(const Instrument& instrument, double qty, double price, const QString& text)
	{
		return SellLimit(method_6(instrument), instrument, qty, price, text);
	}

	Order sellLimitOrder(const Instrument& instrument, double qty, double price, const QString& text);
	Order sellOrder(const Instrument& instrument, double qty, const QString& text);
	Order sellStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text);
	Order sellStop(short providerId, const Instrument& instrument, double qty, double stopPx, const QString& text)
	{
		return SellStop(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, stopPx, text);
	}

	Order sellStop(const Instrument& instrument, double qty, double stopPx, const QString& text)
	{
		return SellStop(method_6(instrument), instrument, qty, stopPx, text);
	}

	Order sellStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text);
	Order sellStopLimit(short providerId, const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
	{
		return SellStopLimit(m_global.providerManager().GetExecutionProvider((int)providerId), instrument, qty, stopPx, price, text);
	}

	Order sellStopLimit(const Instrument& instrument, double qty, double stopPx, double price, const QString& text)
	{
		return SellStopLimit(method_6(instrument), instrument, qty, stopPx, price, text);
	}

	Order sellStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text);
	Order sellStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text);
	void send(const Order& order)
	{
		m_global.orderManager().Send(order);
	}

	void sendStrategyEvent(const QVariant& data)
	{
		m_global.eventServer().OnEvent(new OnStrategyEvent(data));
	}

	void setParameter(const QString& name, const QVariant& value);
	void withdraw(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
		m_position.account().Withdraw(dateTime, value, currencyId, text, updateParent);
	}

	void withdraw(double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
		m_position.account().Withdraw(value, currencyId, text, updateParent);
	}

//protected
	void method_3(const Strategy& strategy_1, const InstrumentList& instrumentList_1, int int);
	void method_4(const Strategy& strategy_1, const InstrumentList& instrumentList_1, int int);
	INewsProvider method_5(const Instrument& instrument);
	IExecutionProvider method_6(const Instrument& instrument);
	IDataProvider method_7(const Strategy& strategy_1, const Instrument& instrument);
	virtual void onAsk(const Instrument& instrument, const Ask& ask) Q_DECL_OVERRIDE;
	virtual void onBar(const Instrument& instrument, const Bar& bar) Q_DECL_OVERRIDE;
	virtual void onBarOpen(const Instrument& instrument, const Bar& bar) Q_DECL_OVERRIDE;
	virtual void onBarSlice(const BarSlice& slice) Q_DECL_OVERRIDE;
	virtual void onBid(const Instrument& instrument, const Bid& bid) Q_DECL_OVERRIDE;
	virtual void onExchangeReminder(const QDateTime& dateTime, const QVariant& data) Q_DECL_OVERRIDE;
	virtual void onExecutionReport(const ExecutionReport& report) Q_DECL_OVERRIDE;
	virtual void onFill(const Fill& fill) Q_DECL_OVERRIDE;
	virtual void onFundamental(const Instrument& instrument, const Fundamental& fundamental) Q_DECL_OVERRIDE;
	virtual void onInstrumentAdded(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void onInstrumentRemoved(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void onLevel2(const Instrument& instrument, const Level2Snapshot& snapshot) Q_DECL_OVERRIDE;
	virtual void onLevel2(const Instrument& instrument, const Level2Update& update) Q_DECL_OVERRIDE;
	virtual void onNewOrder(const Order& order) Q_DECL_OVERRIDE;
	virtual void onNews(const Instrument& instrument, const News& news) Q_DECL_OVERRIDE;
	virtual void onOrderCancelled(const Order& order) Q_DECL_OVERRIDE;
	virtual void onOrderDone(const Order& order) Q_DECL_OVERRIDE;
	virtual void onOrderFilled(const Order& order) Q_DECL_OVERRIDE;
	virtual void onOrderPartiallyFilled(const Order& order) Q_DECL_OVERRIDE;
	virtual void onOrderRejected(const Order& order) Q_DECL_OVERRIDE;
	virtual void onOrderReplaced(const Order& order) Q_DECL_OVERRIDE;
	virtual void onOrderReplaceRejected(const Order& order) Q_DECL_OVERRIDE;
	virtual void onOrderStatusChanged(const Order& order) Q_DECL_OVERRIDE;
	virtual void onParameterChanged(const Parameter& oldParameter, const Parameter& newParameter) Q_DECL_OVERRIDE;
	virtual void onPendingNewOrder(const Order& order) Q_DECL_OVERRIDE;
	virtual void onPositionChanged(const Position& position) Q_DECL_OVERRIDE;
	virtual void onPositionClosed(const Position& position) Q_DECL_OVERRIDE;
	virtual void onPositionOpened(const Position& position) Q_DECL_OVERRIDE;
	virtual void onProviderConnected(const Provider& provider) Q_DECL_OVERRIDE;
	virtual void onProviderDisconnected(const Provider& provider) Q_DECL_OVERRIDE;
	virtual void onProviderError(const ProviderError& error) Q_DECL_OVERRIDE;
	virtual void onReminder(const QDateTime& dateTime, const QVariant& data) Q_DECL_OVERRIDE;
	virtual void onSendOrder(const Order& order) Q_DECL_OVERRIDE;
	virtual void onStopCancelled(const Stop& stop) Q_DECL_OVERRIDE;
	virtual void onStopExecuted(const Stop& stop) Q_DECL_OVERRIDE;
	virtual void onStopStatusChanged(const Stop& stop) Q_DECL_OVERRIDE;
	virtual void onStopStatusChanged_(const Stop& stop) Q_DECL_OVERRIDE;
	virtual void onStrategyEvent(const QVariant& data) Q_DECL_OVERRIDE;
	virtual void onStrategyInit() Q_DECL_OVERRIDE;
	virtual void onStrategyStart() Q_DECL_OVERRIDE;
	virtual void onStrategyStop() Q_DECL_OVERRIDE;
	virtual void onTrade(const Instrument& instrument, const Trade& trade) Q_DECL_OVERRIDE;
	virtual void onTransaction(const Transaction& transaction) Q_DECL_OVERRIDE;
	virtual void onUserCommand(const QString& command) Q_DECL_OVERRIDE;
	virtual void vmethod_0() Q_DECL_OVERRIDE;
	virtual void vmethod_1() Q_DECL_OVERRIDE;
	virtual void vmethod_10(const Ask& ask) Q_DECL_OVERRIDE;
	virtual void vmethod_11(const Trade& trade) Q_DECL_OVERRIDE;
	virtual void vmethod_12(const Level2Snapshot& snapshot) Q_DECL_OVERRIDE;
	virtual void vmethod_13(const Level2Update& update) Q_DECL_OVERRIDE;
	virtual void vmethod_14(const Bar& bar) Q_DECL_OVERRIDE;
	virtual void vmethod_15(const Bar& bar) Q_DECL_OVERRIDE;
	virtual void vmethod_16(const BarSlice& slice) Q_DECL_OVERRIDE;
	virtual void vmethod_17(const News& news) Q_DECL_OVERRIDE;
	virtual void vmethod_18(const Fundamental& fundamental) Q_DECL_OVERRIDE;
	virtual void vmethod_19(const ExecutionReport& report) Q_DECL_OVERRIDE;
	virtual void vmethod_2(const Instrument& instrument) Q_DECL_OVERRIDE { OnInstrumentAdded(instrument); }
	virtual void vmethod_20(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_21(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_22(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_23(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_24(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_25(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_26(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_27(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_28(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_29(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_3(const Instrument& instrument) Q_DECL_OVERRIDE
	{
		OnInstrumentRemoved(instrument);
	}

	virtual void vmethod_30(const Order& order) Q_DECL_OVERRIDE;
	virtual void vmethod_31(const OnFill& fill) Q_DECL_OVERRIDE;
	virtual void vmethod_32(const OnTransaction& transaction) Q_DECL_OVERRIDE;
	virtual void vmethod_33(const Position& position) Q_DECL_OVERRIDE;
	virtual void vmethod_34(const Position& position) Q_DECL_OVERRIDE;
	virtual void vmethod_35(const Position& position) Q_DECL_OVERRIDE;
	virtual void vmethod_36(const Parameter& oldParameter, const Parameter& newParameter) Q_DECL_OVERRIDE;
	virtual void vmethod_37(const QVariant& data) Q_DECL_OVERRIDE;
	virtual void vmethod_4(const QDateTime& dateTime, const QVariant& data) Q_DECL_OVERRIDE { OnReminder(dateTime, data); }
	virtual void vmethod_5(const QDateTime& dateTime, const QVariant& data) Q_DECL_OVERRIDE
	{
		OnExchangeReminder(dateTime, data);
	}

	virtual void vmethod_6(const Provider& provider) Q_DECL_OVERRIDE;
	virtual void vmethod_7(const Provider& provider) Q_DECL_OVERRIDE;
	virtual void vmethod_8(const ProviderError& error) Q_DECL_OVERRIDE;
	virtual void vmethod_9(const Bid& bid) Q_DECL_OVERRIDE;
	virtual void yamOgfniBd(const QString& command) Q_DECL_OVERRIDE;

//private:
	void metod_0(const QString& value) { m_name = value; }
	Strategy method_1(const QString& string_1);
	void method_2(const Instrument& instrument);
};

} // namepsace QuantKit

#endif // __QUANTKIT_STRATEGY_PRIVATE_H__
