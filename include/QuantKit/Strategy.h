#ifndef __QUANTKIT_STRATEGY_H__
#define __QUANTKIT_STRATEGY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/StrategyMode.h>
#include <QuantKit/StrategyStatus.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/INewsProvider.h>
#include <QuantKit/IDataSimulator.h>
#include <QuantKit/IExecutionSimulator.h>
#include <QuantKit/PositionSide.h>
#include <QuantKit/CurrencyId.h>
#include <QuantKit/OrderType.h>
#include <QuantKit/OrderSide.h>

namespace QuantKit {

class StrategyPrivate;

class LinkedList;
class Portfolio;
class InstrumentList;
class BarSeries;
class TimeSeries;
class TickSeries;
class Clock;
class InstrumentManager;
class DataManager;
class ProviderManager;
class OrderManager;
class BarFactory;
class StrategyManager;
class EventManager;
class GroupManager;
class AccountDataManager;
class Global;
class Framework;
class ParameterList;
class Instrument;
class Provider;
class ProviderError;
class Bid;
class Ask;
class Trade;
class Level2Snapshot;
class Level2Update;
class Bar;
class BarSlice;
class News;
class Fundamental;
class ExecutionReport;
class Order;
class OnFill;
class OnTransaction;
class Position;
class Stop;
class Parameter;
class Fill;
class Transaction;
class Event;
class Group;
class DataObject;
class IdArray;

class QUANTKIT_EXPORT Strategy
{
public:
	Strategy(const Framework& framework, const QString& name);
	~Strategy();

	Strategy(const Strategy &other);
	Strategy& operator=(const Strategy &other);
	bool operator==(const Strategy &other) const;
	inline bool operator!=(const Strategy &other) const { return !(this->operator==(other));  }
public:
	bool raiseEvents() const;
	void setRaiseEvents(bool value);

	bool bool_1() const;
	void setBool_1(bool value);
	IdArray<LinkedList<Strategy>> idArray() const;
	unsigned char id() const;
	QString name() const;
	bool enabled() const;
	void setEnabled(bool value);
	StrategyMode mode() const;
	StrategyStatus status() const;
	Strategy parent() const;
	LinkedList<Strategy> strategies() const;
	Portfolio portfolio() const;
	InstrumentList instruments() const;
	BarSeries bars() const;
	TimeSeries equity() const;
	TickSeries bids() const;
	TickSeries asks() const;
	IDataProvider dataProvider() const;
	void setDataProvider(const IDataProvider& value);
	IExecutionProvider executionProvider() const;
	void setExecutionProvider(const IExecutionProvider& value);
	INewsProvider fundamentalProvider() const;
	void setFundamentalProvider(const INewsProvider& value);
	Clock clock() const;
	InstrumentManager instrumentManager() const;
	DataManager dataManager() const;
	IDataSimulator dataSimulator() const;
	IExecutionSimulator executionSimulator() const;
	ProviderManager providerManager() const;
	OrderManager orderManager() const;
	BarFactory barFactory() const;
	StrategyManager strategyManager() const;
	EventManager eventManager() const;
	GroupManager groupManager() const;
	AccountDataManager accountDataManager() const;
	Global global() const;
	void addExchangeReminder(const QDateTime& dateTime, const QVariant& data = 0);
	void addInstrument(const QString& symbol);
	void addInstrument(int id);
	void addInstrument(const Instrument& instrument);
	void addInstruments(const QString& symbols);
	void addInstruments(const InstrumentList& instruments);
	void addReminder(const QDateTime& dateTime, const QVariant& data = 0);
	void addStop(const Stop& stop);
	void addStrategy(const Strategy& strategy);
	void addStrategy(const Strategy& strategy, bool callOnStrategyStart);
	Order buy(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text = "");
	Order buy(short providerId, const Instrument& instrument, double qty, const QString& text = "");
	Order buy(const Instrument& instrument, double qty, const QString& text = "");
	Order buyLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text = "");
	Order buyLimit(short providerId, const Instrument& instrument, double qty, double price, const QString& text = "");
	Order buyLimit(const Instrument& instrument, double qty, double price, const QString& text = "");
	Order buyLimitOrder(const Instrument& instrument, double qty, double price, const QString& text = "");
	Order buyOrder(const Instrument& instrument, double qty, const QString& text = "");
	Order buyStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	Order buyStop(short providerId, const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	Order buyStop(const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	Order buyStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order buyStopLimit(short providerId, const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order buyStopLimit(const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order buyStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order buyStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	void cancel(const Order& order);
	void cancelAll();
	void cancelAll(const Instrument& instrument);
	void deposit(const QDateTime& dateTime, double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	void deposit(double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	bool executeMethod(const QString& methodName);
	QString getModeAsString();
	QVariant getParameter(const QString& name);
	ParameterList getParameters();
	QString getStatusAsString();
	Strategy getStrategy(const QString& name);
	bool hasLongPosition(const Instrument& instrument);
	bool hasLongPosition(const Instrument& instrument, double qty);
	bool hasPosition(const Instrument& instrument);
	bool hasPosition(const Instrument& instrument, PositionSide side, double qty);
	bool hasShortPosition(const Instrument& instrument);
	bool hasShortPosition(const Instrument& instrument, double qty);
	void init();
	void log(const Event& e, const Group& group);
	void log(const Event& e, int groupId);
	void log(const DataObject& data, const Group& group);
	void log(const DataObject& data, int groupId);
	void log(const QDateTime& dateTime, double value, const Group& group);
	void log(const QDateTime& dateTime, double value, int groupId);
	void log(const QDateTime& dateTime, const QString& text, const Group& group);
	void log(const QDateTime& dateTime, const QString& text, int groupId);
	void log(double value, const Group& group);
	void log(double value, int groupId);
	void log(const QString& text, const Group& group);
	void log(const QString& text, int groupId);
	double objective();
	Order order(const Instrument& instrument, OrderType type, OrderSide side, double qty, double stopPx, double price, const QString& text = "");
	void reject(const Order& order);
	void removeInstrument(const QString& symbol);
	void removeInstrument(int id);
	void removeInstrument(const Instrument& instrument);
	void removeStrategy(const Strategy& strategy);
	void replace(const Order& order, double price);
	void replace(const Order& order, double price, double stopPx, double qty);
	void respond(const DataObject& data, int commandId);
	void respond(const DataObject& data);
	Order sell(const IExecutionProvider& provider, const Instrument& instrument, double qty, const QString& text = "");
	Order sell(short providerId, const Instrument& instrument, double qty, const QString& text = "");
	Order sell(const Instrument& instrument, double qty, const QString& text = "");
	Order sellLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double price, const QString& text = "");
	Order sellLimit(short providerId, const Instrument& instrument, double qty, double price, const QString& text = "");
	Order sellLimit(const Instrument& instrument, double qty, double price, const QString& text = "");
	Order sellLimitOrder(const Instrument& instrument, double qty, double price, const QString& text = "");
	Order sellOrder(const Instrument& instrument, double qty, const QString& text = "");
	Order sellStop(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	Order sellStop(short providerId, const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	Order sellStop(const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	Order sellStopLimit(const IExecutionProvider& provider, const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order sellStopLimit(short providerId, const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order sellStopLimit(const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order sellStopLimitOrder(const Instrument& instrument, double qty, double stopPx, double price, const QString& text = "");
	Order sellStopOrder(const Instrument& instrument, double qty, double stopPx, const QString& text = "");
	void send(const Order& order);
	void sendStrategyEvent(const QVariant& data);
	void setParameter(const QString& name, const QVariant& value);
	void withdraw(const QDateTime& dateTime, double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	void withdraw(double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);

protected:
	Strategy(StrategyPrivate& dd);
	QSharedDataPointer<StrategyPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const Strategy& strategy);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Strategy& strategy);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Strategy)

#endif // __QUANTKIT_STRATEGY_H__
