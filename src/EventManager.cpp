#include <QuantKit/EventManager.h>

#include <QuantKit/EventFilter.h>
#include "EventLogger_p.h"
#include <QuantKit/BarFactory.h>
#include <QuantKit/BarSliceFactory.h>
#include <QuantKit/EventDispatcher.h>
#include <QuantKit/Framework.h>
#include <QuantKit/EventBus.h>
#include "Event_p.h"
#include <QuantKit/IdArray.h>

namespace QuantKit {

class EventManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	EventBus eventBus_0;
	EventFilter m_filter;
	EventLogger m_logger;
	EventDispatcher m_dispatcher;
	BarFactory m_barFactory;
	BarSliceFactory m_barSliceFactory;
	EventManagerStatus m_status;
	Thread m_thread;
	bool bool_0;
	Stopwatch stopwatch_0;
	long m_eventCount;
	long m_dataEventCount;
	bool bool_1;
	unsigned char m_eventTypeId;
	IdArray<Delegate6> m_idArray;

public:
	EventManagerPrivate(const Framework& framework, const EventBus& bus);
	virtual ~EventManagerPrivate();

public:
	EventManagerStatus status() const { return m_status; }
	EventFilter filter() const { return m_filter; }
	void setFilter(const EventFilter& value) { m_filter = value; }
	EventLogger logger() const { return m_logger; }
	void setLogger(const EventLogger& value) { m_logger = value; }
	BarFactory barFactory() const { return m_barFactory; }
	void setBarFactory(const BarFactory& value) { m_barFactory = value; }
	BarSliceFactory barSliceFactory() const { return m_barSliceFactory; }
	void setBarSliceFactory(const BarSliceFactory& value) { m_barSliceFactory = value; }
	EventDispatcher dispatcher() const { return m_dispatcher; }
	void setDispatcher(const EventDispatcher& value) { m_dispatcher = value; }
	long eventCount() const { return m_eventCount; }
	long dataEventCount() const { return m_dataEventCount; }
	void clear();
	void dispose();
	void onEvent(const Event& e);
	void pause();
	void pause(const QDateTime& dateTime)
	{
		m_framework.clock().AddReminder(new ReminderCallback(method_0()), dateTime, null);
	}

	void resume();
	void start();
	void step(unsigned char typeId);
	void stop();
	virtual EventManagerPrivate* clone() Q_DECL_OVERRIDE { return new EventManagerPrivate(*this); }
//private:
	void ajyJyjUxGJ(const Event& event);
	void ceYtsUmCsS(const Event& event)
	{
		m_framework.groupManager().method_0((Group)@event);
	}

	void method_0(const QDateTime& dateTime, const QVariant& object) { Pause(); }
	void method_1();
	void method_10(const Event& event);
	void method_11(const Event& event);
	void method_12(const Event& event);
	void method_13(const Event& event);
	void method_14(const Event& event);
	void method_15(const Event& event);
	void method_16(const Event& event);
	void method_17(const Event& event);
	void method_18(const Event& event);
	void method_19(const Event& event)
	{
		m_framework.strategyManager().method_15(((OnSendOrder)@event).order());
	}

	void method_2(const Event& event);
	void method_20(const Event& event)
	{
		m_framework.strategyManager().method_16(((OnPendingNewOrder)@event).order());
	}

	void method_21(const Event& event)
	{
		m_framework.strategyManager().AyZegZnQqw(((OnNewOrder)@event).order());
	}

	void method_22(const Event& event)
	{
		m_framework.strategyManager().method_17(((OnOrderStatusChanged)@event).order());
	}

	void method_23(const Event& event)
	{
		m_framework.strategyManager().method_19(((OnOrderPartiallyFilled)@event).order());
	}

	void method_24(const Event& event)
	{
		m_framework.strategyManager().method_18(((OnOrderFilled)@event).order());
	}

	void method_25(const Event& event)
	{
		m_framework.strategyManager().method_21(((OnOrderReplaced)@event).order());
	}

	void method_26(const Event& event)
	{
		m_framework.strategyManager().method_20(((OnOrderCancelled)@event).order());
	}

	void method_27(const Event& event)
	{
		m_framework.strategyManager().method_22(((OnOrderRejected)@event).order_0());
	}

	void method_28(const Event& event)
	{
		m_framework.strategyManager().method_23(((OnOrderReplaceRejected)@event).order_0());
	}

	void method_29(const Event& event)
	{
		m_framework.strategyManager().method_24(((OnOrderDone)@event).order());
	}

	void method_3(const Event& event);
	void method_30(const Event& event)
	{
		m_framework.strategyManager().method_26((OnFill)@event);
	}

	void method_31(const Event& event)
	{
		m_framework.strategyManager().method_27((OnTransaction)@event);
	}

	void method_32(const Event& event);
	void method_33(const Event& event);
	void method_34(const Event& event);
	void method_35(const Event& event);
	void method_36(const Event& event)
	{
		m_framework.groupManager().method_1((GroupEvent)@event);
	}

	void method_37(const Event& event)
	{
		m_framework.dataManager().method_9((HistoricalData)@event);
	}

	void method_38(const Event& event)
	{
		m_framework.dataManager().method_10((HistoricalDataEnd)@event);
	}

	void method_39(const Event& event)
	{
		m_framework.strategyManager().method_31(((OnUserCommand)@event).string_0());
	}

	void method_4(const Event& event)
	{
		m_framework.strategyManager().method_5((ProviderError)@event);
	}

	void method_40(const Event& event)
	{
		m_framework.strategyManager().method_36(((OnStrategyEvent)@event).object_0());
	}

	void method_41(bool bool_2);
	void method_5(const Event& event);
	void method_6(const Event& event);
	void method_7(const Event& event);
	void method_8(const Event& event);
	void method_9(const Event& event);
};

} // namepsace QuantKit


using namespace QuantKit;

EventManagerPrivate::EventManagerPrivate(const Framework& framework, const EventBus& bus)
	: m_framework(framework)
	, eventBus_0(bus)
	, m_dispatcher(new EventDispatcher(framework))
	, m_barFactory(new BarFactory(framework))
	, m_barSliceFactory(new BarSliceFactory(framework))
	, m_status(EventManagerStatus.Stopped)
	, m_thread(new Thread(new ThreadStart(method_1())))
	, stopwatch_0(new Stopwatch())
	, m_eventTypeId(6)
	, m_idArray(new IdArray<EventManager.Delegate6>(1000))
{
		m_idArray[225] = new EventManager.Delegate6(method_2());
		m_idArray[226] = new EventManager.Delegate6(method_3());
		m_idArray[21] = new EventManager.Delegate6(method_4());
		m_idArray[228] = new EventManager.Delegate6(method_5());
		m_idArray[229] = new EventManager.Delegate6(ajyJyjUxGJ());
		m_idArray[230] = new EventManager.Delegate6(method_6());
		m_idArray[2] = new EventManager.Delegate6(method_7());
		m_idArray[3] = new EventManager.Delegate6(method_8());
		m_idArray[4] = new EventManager.Delegate6(method_9());
		m_idArray[5] = new EventManager.Delegate6(method_10());
		m_idArray[6] = new EventManager.Delegate6(method_11());
		m_idArray[138] = new EventManager.Delegate6(method_12());
		m_idArray[8] = new EventManager.Delegate6(method_13());
		m_idArray[9] = new EventManager.Delegate6(method_14());
		m_idArray[23] = new EventManager.Delegate6(method_16());
		m_idArray[22] = new EventManager.Delegate6(method_15());
		m_idArray[13] = new EventManager.Delegate6(method_17());
		m_idArray[117] = new EventManager.Delegate6(method_19());
		m_idArray[118] = new EventManager.Delegate6(method_20());
		m_idArray[119] = new EventManager.Delegate6(method_21());
		m_idArray[120] = new EventManager.Delegate6(method_22());
		m_idArray[121] = new EventManager.Delegate6(method_23());
		m_idArray[122] = new EventManager.Delegate6(method_24());
		m_idArray[123] = new EventManager.Delegate6(method_25());
		m_idArray[124] = new EventManager.Delegate6(method_26());
		m_idArray[125] = new EventManager.Delegate6(method_27());
		m_idArray[126] = new EventManager.Delegate6(method_28());
		m_idArray[127] = new EventManager.Delegate6(method_29());
		m_idArray[113] = new EventManager.Delegate6(method_30());
		m_idArray[114] = new EventManager.Delegate6(method_31());
		m_idArray[110] = new EventManager.Delegate6(method_32());
		m_idArray[111] = new EventManager.Delegate6(method_33());
		m_idArray[112] = new EventManager.Delegate6(method_34());
		m_idArray[15] = new EventManager.Delegate6(method_35());
		m_idArray[50] = new EventManager.Delegate6(ceYtsUmCsS());
		m_idArray[52] = new EventManager.Delegate6(method_36());
		m_idArray[136] = new EventManager.Delegate6(method_37());
		m_idArray[137] = new EventManager.Delegate6(method_38());
		m_idArray[140] = new EventManager.Delegate6(method_18());
		m_idArray[212] = new EventManager.Delegate6(method_39());
		m_idArray[139] = new EventManager.Delegate6(method_40());
		if (bus != null)
		{
			m_thread.Name = "Event Manager Thread";
			m_thread.IsBackground = true;
			m_thread.Start();
		}
}

EventManagerPrivate::~EventManagerPrivate ()
{
}

void EventManagerPrivate::clear()
{
	m_eventCount = 0L;
	m_dataEventCount = 0L;
	m_barFactory.method_1();
	m_barSliceFactory.method_2();
}

void EventManagerPrivate::dispose()
{
	method_41(true);
	GC.SuppressFinalize(this);
}

void EventManagerPrivate::onEvent(const Event& e)
{
	if (m_status == EventManagerStatus.Paused && bool_1 && (m_eventTypeId == 0 || m_eventTypeId == e.typeId()))
	{
		Console.WriteLine(DateTime.Now + " Event : " + e);
		bool_1 = false;
	}
	m_eventCount += 1L;
	if (m_filter != null && m_filter.Filter(e) == null)
	{
		return;
	}
	if (m_idArray[(int)e.typeId()] != null)
	{
		m_idArray[(int)e.typeId()](e);
	}
	if (m_dispatcher != null)
	{
		m_dispatcher.OnEvent(e);
	}
	if (m_logger != null)
	{
		m_logger.OnEvent(e);
	}
}

void EventManagerPrivate::pause()
{
	if (m_status != EventManagerStatus.Paused)
	{
		Console.WriteLine(DateTime.Now + " Event manager paused at " + m_framework.clock().dateTime());
		m_status = EventManagerStatus.Paused;
		OnEvent(new OnEventManagerPaused());
	}
}

void EventManagerPrivate::resume()
{
	if (m_status != EventManagerStatus.Running)
	{
		Console.WriteLine(DateTime.Now + " Event manager resumed at " + m_framework.clock().dateTime());
		m_status = EventManagerStatus.Running;
		OnEvent(new OnEventManagerResumed());
	}
}

void EventManagerPrivate::start()
{
	if (m_status != EventManagerStatus.Running)
	{
		Console.WriteLine(DateTime.Now + " Event manager started at " + m_framework.clock().dateTime());
		m_status = EventManagerStatus.Running;
		OnEvent(new OnEventManagerStarted());
	}
}

void EventManagerPrivate::step(unsigned char typeId)
{
	bool_1 = true;
	m_eventTypeId = typeId;
	OnEvent(new OnEventManagerStep());
}

void EventManagerPrivate::stop()
{
	if (m_status != EventManagerStatus.Stopped)
	{
		Console.WriteLine(DateTime.Now + " Event manager stopping at " + m_framework.clock().dateTime());
		m_status = EventManagerStatus.Stopping;
		if (m_framework.mode() == FrameworkMode.Simulation)
		{
			OnEvent(new OnSimulatorStop());
		}
		m_status = EventManagerStatus.Stopped;
		m_framework.eventBus().Clear();
		OnEvent(new OnEventManagerStopped());
		Console.WriteLine(DateTime.Now + " Event manager stopped at " + m_framework.clock().dateTime());
	}
}

void EventManagerPrivate::ajyJyjUxGJ(const Event& event)
{
	m_framework.strategyManager().Stop();
	stopwatch_0.Stop();
	long elapsedMilliseconds = stopwatch_0.ElapsedMilliseconds;
	if (elapsedMilliseconds != 0L)
	{
		Console.WriteLine(string.Concat(new object[]
		{
			DateTime.Now,
			" Data run done, count = ",
			m_dataEventCount,
			" ms = ",
			stopwatch_0.ElapsedMilliseconds,
			" event/sec = ",
			m_dataEventCount / elapsedMilliseconds * 1000L
		}));
		return;
	}
	Console.WriteLine(string.Concat(new object[]
	{
		DateTime.Now,
		" Data run done, count = ",
		m_dataEventCount,
		" ms = 0"
	}));
}

void EventManagerPrivate::method_1()
{
	Console.WriteLine(string.Concat(new object[]
	{
		DateTime.Now,
		" Event manager thread started: Framework = ",
		m_framework.name(),
		" Clock = ",
		m_framework.clock().GetModeAsString()
	}));
	m_status = EventManagerStatus.Running;
	while (!bool_0)
	{
		if (m_status != EventManagerStatus.Running && (m_status != EventManagerStatus.Paused || !bool_1))
		{
			Thread.Sleep(1);
		}
		else
		{
			Event e = eventBus_0.Dequeue();
			OnEvent(e);
		}
	}
	Console.WriteLine(string.Concat(new object[]
	{
		DateTime.Now,
		" Event manager thread stopped: Framework = ",
		m_framework.name(),
		" Clock = ",
		m_framework.clock().GetModeAsString()
	}));
}

void EventManagerPrivate::method_10(const Event& event)
{
	Quote quote = (Quote)@event;
	if (quote.bid() != null && quote.bid().price() != 0.0)
	{
		Bid bid = m_framework.dataManager().GetBid(quote.bid().instrumentId());
		if (bid == null || quote.bid().price() != bid.price() || quote.bid().size() != bid.size())
		{
			method_7(quote.bid());
		}
	}
	if (quote.ask() != null && quote.ask().price() != 0.0)
	{
		Ask ask = m_framework.dataManager().GetAsk(quote.ask().instrumentId());
		if (ask == null || quote.ask().price() != ask.price() || quote.ask().size() != ask.size())
		{
			method_8(quote.ask());
		}
	}
}

void EventManagerPrivate::method_11(const Event& event)
{
	m_dataEventCount += 1L;
	Bar bar = (Bar)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = bar.entryDate();
	}
	if (bar.status() != BarStatus.Open)
	{
		m_framework.dataManager().method_4(bar);
		m_framework.instrumentManager().GetById(bar.instrumentId()).setBar() = bar;
		m_framework.providerManager().executionSimulator().OnBar(bar);
		m_framework.strategyManager().method_12(bar);
		if (bar.type() == BarType.Time || bar.type() == BarType.Session)
		{
			m_barSliceFactory.method_1(bar);
		}
		return;
	}
	if ((bar.type() == BarType.Time || bar.type() == BarType.Session) && !m_barSliceFactory.method_0(bar))
	{
		return;
	}
	m_framework.providerManager().executionSimulator().OnBarOpen(bar);
	m_framework.strategyManager().method_11(bar);
}

void EventManagerPrivate::method_12(const Event& event)
{
	BarSlice barSlice = (BarSlice)@event;
	barSlice.setEntryDate() = m_framework.clock().dateTime();
	m_framework.strategyManager().XtgeHyTafa(barSlice);
}

void EventManagerPrivate::method_13(const Event& event)
{
	m_dataEventCount += 1L;
	Level2Snapshot level2Snapshot = (Level2Snapshot)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = level2Snapshot.entryDate();
	}
	else
	{
		level2Snapshot.setEntryDate() = m_framework.clock().dateTime();
	}
	m_framework.dataManager().method_5(level2Snapshot);
	m_framework.providerManager().executionSimulator().OnLevel2(level2Snapshot);
	m_framework.strategyManager().method_9(level2Snapshot);
}

void EventManagerPrivate::method_14(const Event& event)
{
	m_dataEventCount += 1L;
	Level2Update level2Update = (Level2Update)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = level2Update.entryDate();
	}
	else
	{
		level2Update.setEntryDate() = m_framework.clock().dateTime();
	}
	m_framework.dataManager().method_6(level2Update);
	m_framework.providerManager().executionSimulator().OnLevel2(level2Update);
	m_framework.strategyManager().method_10(level2Update);
}

void EventManagerPrivate::method_15(const Event& event)
{
	m_dataEventCount += 1L;
	Fundamental fundamental = (Fundamental)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = fundamental.entryDate();
	}
	else
	{
		fundamental.setEntryDate() = m_framework.clock().dateTime();
	}
	m_framework.dataManager().method_8(fundamental);
	m_framework.strategyManager().method_14(fundamental);
}

void EventManagerPrivate::method_16(const Event& event)
{
	m_dataEventCount += 1L;
	News news = (News)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = news.entryDate();
	}
	else
	{
		news.setEntryDate() = m_framework.clock().dateTime();
	}
	m_framework.dataManager().method_7(news);
	m_framework.strategyManager().method_13(news);
}

void EventManagerPrivate::method_17(const Event& event)
{
	ExecutionReport executionReport = (ExecutionReport)@event;
	if (m_framework.clock().mode() == ClockMode.Realtime)
	{
		executionReport.setEntryDate() = m_framework.clock().dateTime();
	}
	m_framework.orderManager().method_0(executionReport);
	m_framework.portfolioManager().method_1(executionReport);
	m_framework.strategyManager().method_25(executionReport);
	m_framework.eventServer().EmitQueued();
}

void EventManagerPrivate::method_18(const Event& event)
{
	AccountData accountData = (AccountData)@event;
	m_framework.accountDataManager().method_1(accountData);
}

void EventManagerPrivate::method_2(const Event& event)
{
	Provider provider = ((OnProviderConnected)@event).provider();
	if (provider is IDataProvider)
	{
		m_framework.subscriptionManager().method_0((IDataProvider)provider);
	}
	m_framework.strategyManager().method_3(provider);
}

void EventManagerPrivate::method_3(const Event& event)
{
	Provider provider = ((OnProviderDisconnected)@event).provider();
	if (provider is IDataProvider)
	{
		m_framework.subscriptionManager().method_1((IDataProvider)provider);
	}
	m_framework.strategyManager().method_4(provider);
}

void EventManagerPrivate::method_32(const Event& event)
{
	OnPositionOpened onPositionOpened = (OnPositionOpened)@event;
	m_framework.strategyManager().method_28(onPositionOpened.portfolio(), onPositionOpened.position());
}

void EventManagerPrivate::method_33(const Event& event)
{
	OnPositionClosed onPositionClosed = (OnPositionClosed)@event;
	m_framework.strategyManager().method_29(onPositionClosed.portfolio(), onPositionClosed.position());
}

void EventManagerPrivate::method_34(const Event& event)
{
	OnPositionChanged onPositionChanged = (OnPositionChanged)@event;
	m_framework.strategyManager().method_30(onPositionChanged.portfolio(), onPositionChanged.position());
}

void EventManagerPrivate::method_35(const Event& event)
{
	Reminder reminder = (Reminder)@event;
	if ((reminder.clock().clockType_0() == ClockType.Local && reminder.clock().mode() == ClockMode.Simulation) || reminder.clock().clockType_0() == ClockType.Exchange)
	{
		reminder.clock().setDateTime() = @event.entryDate();
	}
	((Reminder)@event).method_0();
}

void EventManagerPrivate::method_41(bool bool_2)
{
	if (bool_2)
	{
		bool_0 = true;
		m_thread.Abort();
	}
}

void EventManagerPrivate::method_5(const Event& event)
{
	OnSimulatorStart onSimulatorStart = (OnSimulatorStart)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = onSimulatorStart.ymlVcTtugA();
	}
	if (eventBus_0 != null)
	{
		eventBus_0.ResetCounts();
	}
	m_eventCount = 0L;
	m_dataEventCount = 0L;
	stopwatch_0.Reset();
	stopwatch_0.Start();
}

void EventManagerPrivate::method_6(const Event& event)
{
}

void EventManagerPrivate::method_7(const Event& event)
{
	m_dataEventCount += 1L;
	Bid bid = (Bid)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = bid.entryDate();
	}
	else
	{
		bid.setEntryDate() = m_framework.clock().dateTime();
	}
	if (bid.exchangeDateTime() > m_framework.exchangeClock().dateTime())
	{
		m_framework.exchangeClock().setDateTime() = bid.exchangeDateTime();
	}
	else
	{
		if (bid.exchangeDateTime() > m_framework.exchangeClock().dateTime())
		{
			Console.WriteLine(string.Concat(new object[]
			{
				"EventManager::OnBid Exchange datetime is out of synch : bid datetime = ",
				bid.exchangeDateTime(),
				" clock datetime = ",
				m_framework.exchangeClock().mode()
			}));
		}
	}
	m_barFactory.method_0(bid);
	m_framework.dataManager().method_1(bid);
	m_framework.instrumentManager().GetById(bid.instrumentId()).setBid() = bid;
	m_framework.providerManager().executionSimulator().OnBid(bid);
	m_framework.strategyManager().method_6(bid);
}

void EventManagerPrivate::method_8(const Event& event)
{
	m_dataEventCount += 1L;
	Ask ask = (Ask)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = ask.dateTime();
	}
	else
	{
		ask.setEntryDate() = m_framework.clock().dateTime();
	}
	if (ask.exchangeDateTime() > m_framework.exchangeClock().dateTime())
	{
		m_framework.exchangeClock().setDateTime() = ask.exchangeDateTime();
	}
	else
	{
		if (ask.exchangeDateTime() > m_framework.exchangeClock().dateTime())
		{
			Console.WriteLine(string.Concat(new object[]
			{
				"EventManager::OnAsk Exchange datetime is out of synch : ask datetime = ",
				ask.exchangeDateTime(),
				" clock datetime = ",
				m_framework.exchangeClock().mode()
			}));
		}
	}
	m_barFactory.method_0(ask);
	m_framework.dataManager().method_2(ask);
	m_framework.instrumentManager().GetById(ask.instrumentId()).setAsk() = ask;
	m_framework.providerManager().executionSimulator().OnAsk(ask);
	m_framework.strategyManager().method_7(ask);
}

void EventManagerPrivate::method_9(const Event& event)
{
	m_dataEventCount += 1L;
	Trade trade = (Trade)@event;
	if (m_framework.clock().mode() == ClockMode.Simulation)
	{
		m_framework.clock().setDateTime() = trade.entryDate();
	}
	else
	{
		trade.setEntryDate() = m_framework.clock().dateTime();
	}
	if (trade.exchangeDateTime() > m_framework.exchangeClock().dateTime())
	{
		m_framework.exchangeClock().setDateTime() = trade.exchangeDateTime();
	}
	else
	{
		if (trade.exchangeDateTime() > m_framework.exchangeClock().dateTime())
		{
			Console.WriteLine(string.Concat(new object[]
			{
				"EventManager::OnTrade Exchange datetime is out of synch : trade datetime = ",
				trade.exchangeDateTime(),
				" clock datetime = ",
				m_framework.exchangeClock().mode()
			}));
		}
	}
	m_barFactory.method_0(trade);
	m_framework.dataManager().method_3(trade);
	m_framework.instrumentManager().GetById(trade.instrumentId()).setTrade() = trade;
	m_framework.providerManager().executionSimulator().OnTrade(trade);
	m_framework.strategyManager().method_8(trade);
}


// Pubic API 

EventManager::EventManager(const Framework& framework, const EventBus& bus)
	: d_ptr(new EventManagerPrivate(framework, bus))
{
}

EventManager::~EventManager()
{
}

EventManager::EventManager (const EventManager &other)
	: d_ptr(other.d_ptr)
{
}

EventManager& EventManager::operator=(const EventManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventManager::operator==(const EventManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

EventManagerStatus EventManager::status() const
{
	return d_ptr->status();
}

EventFilter EventManager::filter() const
{
	return d_ptr->filter();
}

void EventManager::setFilter(const EventFilter& value)
{
	d_ptr->setFilter(value);
}

EventLogger EventManager::logger() const
{
	return d_ptr->logger();
}

void EventManager::setLogger(const EventLogger& value)
{
	d_ptr->setLogger(value);
}

BarFactory EventManager::barFactory() const
{
	return d_ptr->barFactory();
}

void EventManager::setBarFactory(const BarFactory& value)
{
	d_ptr->setBarFactory(value);
}

BarSliceFactory EventManager::barSliceFactory() const
{
	return d_ptr->barSliceFactory();
}

void EventManager::setBarSliceFactory(const BarSliceFactory& value)
{
	d_ptr->setBarSliceFactory(value);
}

EventDispatcher EventManager::dispatcher() const
{
	return d_ptr->dispatcher();
}

void EventManager::setDispatcher(const EventDispatcher& value)
{
	d_ptr->setDispatcher(value);
}

long EventManager::eventCount() const
{
	return d_ptr->eventCount();
}

long EventManager::dataEventCount() const
{
	return d_ptr->dataEventCount();
}

void EventManager::clear()
{
	d_ptr->clear();
}

void EventManager::dispose()
{
	d_ptr->dispose();
}

void EventManager::onEvent(const Event& e)
{
	d_ptr->onEvent(e);
}

void EventManager::pause()
{
	d_ptr->pause();
}

void EventManager::pause(const QDateTime& dateTime)
{
	d_ptr->pause(dateTime);
}

void EventManager::resume()
{
	d_ptr->resume();
}

void EventManager::start()
{
	d_ptr->start();
}

void EventManager::step(unsigned char typeId)
{
	d_ptr->step(typeId);
}

void EventManager::stop()
{
	d_ptr->stop();
}

QDebug operator<<(QDebug dbg, const EventManager& eventmanager)
{
	return dbg << eventmanager.toString();
}

