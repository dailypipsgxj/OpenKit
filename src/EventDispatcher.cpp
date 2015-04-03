#include <QuantKit/EventDispatcher.h>

#include <QuantKit/FrameworkEventHandler.h>
#include <QuantKit/InstrumentEventHandler.h>
#include <QuantKit/InstrumentDefinitionEventHandler.h>
#include <QuantKit/InstrumentDefinitionEndEventHandler.h>
#include <QuantKit/ProviderEventHandler.h>
#include <QuantKit/ExecutionCommandEventHandler.h>
#include <QuantKit/ExecutionReportEventHandler.h>
#include <QuantKit/OrderManagerClearedEventHandler.h>
#include <QuantKit/FillEventHandler.h>
#include <QuantKit/TransactionEventHandler.h>
#include <QuantKit/BarEventHandler.h>
#include <QuantKit/BidEventHandler.h>
#include <QuantKit/AskEventHandler.h>
#include <QuantKit/TradeEventHandler.h>
#include <QuantKit/ProviderErrorEventHandler.h>
#include <QuantKit/HistoricalDataEventHandler.h>
#include <QuantKit/HistoricalDataEndEventHandler.h>
#include <QuantKit/PortfolioEventHandler.h>
#include <QuantKit/PositionEventHandler.h>
#include <QuantKit/GroupEventHandler.h>
#include <QuantKit/GroupEventEventHandler.h>
#include <QuantKit/GroupUpdateEventHandler.h>
#include <QuantKit/SimulatorProgressEventHandler.h>
#include <QuantKit/AccountDataEventHandler.h>
#include <QuantKit/Framework.h>
#include "Event_p.h"
#include <QuantKit/EventQueue.h>

namespace QuantKit {

class EventDispatcherPrivate : public QSharedData
{
public:
	FrameworkEventHandler frameworkEventHandler_0;
	InstrumentEventHandler instrumentEventHandler_0;
	InstrumentEventHandler instrumentEventHandler_1;
	InstrumentDefinitionEventHandler instrumentDefinitionEventHandler_0;
	InstrumentDefinitionEndEventHandler instrumentDefinitionEndEventHandler_0;
	ProviderEventHandler providerEventHandler_0;
	ProviderEventHandler providerEventHandler_1;
	ProviderEventHandler providerEventHandler_2;
	ProviderEventHandler providerEventHandler_3;
	ProviderEventHandler providerEventHandler_4;
	ExecutionCommandEventHandler executionCommandEventHandler_0;
	ExecutionReportEventHandler executionReportEventHandler_0;
	OrderManagerClearedEventHandler orderManagerClearedEventHandler_0;
	FillEventHandler fillEventHandler_0;
	TransactionEventHandler transactionEventHandler_0;
	BarEventHandler barEventHandler_0;
	BidEventHandler bidEventHandler_0;
	AskEventHandler askEventHandler_0;
	TradeEventHandler tradeEventHandler_0;
	ProviderErrorEventHandler providerErrorEventHandler_0;
	HistoricalDataEventHandler historicalDataEventHandler_0;
	HistoricalDataEndEventHandler historicalDataEndEventHandler_0;
	PortfolioEventHandler portfolioEventHandler_0;
	PortfolioEventHandler portfolioEventHandler_1;
	PositionEventHandler positionEventHandler_0;
	PositionEventHandler positionEventHandler_1;
	PositionEventHandler positionEventHandler_2;
	PortfolioEventHandler portfolioEventHandler_2;
	GroupEventHandler groupEventHandler_0;
	GroupEventEventHandler groupEventEventHandler_0;
	GroupUpdateEventHandler groupUpdateEventHandler_0;
	SimulatorProgressEventHandler simulatorProgressEventHandler_0;
	EventHandler eventHandler_0;
	AccountDataEventHandler accountDataEventHandler_0;
	EventHandler eventHandler_1;
	EventHandler eventHandler_2;
	EventHandler eventHandler_3;
	EventHandler eventHandler_4;
	EventHandler eventHandler_5;
	Framework framework;
	EventQueue eventQueue_0;
	Thread m_thread;

public:
	explicit EventDispatcherPrivate(const Framework& framework);
	virtual ~EventDispatcherPrivate();

public:
	void addAccountData(const AccountDataEventHandler& value);
	void addAsk(const AskEventHandler& value);
	void addBar(const BarEventHandler& value);
	void addBid(const BidEventHandler& value);
	void addEventManagerPaused(const EventHandler& value);
	void addEventManagerResumed(const EventHandler& value);
	void addEventManagerStarted(const EventHandler& value);
	void addEventManagerStep(const EventHandler& value);
	void addEventManagerStopped(const EventHandler& value);
	void addExecutionCommand(const ExecutionCommandEventHandler& value);
	void addExecutionReport(const ExecutionReportEventHandler& value);
	void addFill(const FillEventHandler& value);
	void addFrameworkCleared(const FrameworkEventHandler& value);
	void addHistoricalData(const HistoricalDataEventHandler& value);
	void addHistoricalDataEnd(const HistoricalDataEndEventHandler& value);
	void addInstrumentAdded(const InstrumentEventHandler& value);
	void addInstrumentDefinition(const InstrumentDefinitionEventHandler& value);
	void addInstrumentDefinitionEnd(const InstrumentDefinitionEndEventHandler& value);
	void addInstrumentDeleted(const InstrumentEventHandler& value);
	void addNewGroup(const GroupEventHandler& value);
	void addNewGroupEvent(const GroupEventEventHandler& value);
	void addNewGroupUpdate(const GroupUpdateEventHandler& value);
	void addOrderManagerCleared(const OrderManagerClearedEventHandler& value);
	void addPortfolioAdded(const PortfolioEventHandler& value);
	void addPortfolioDeleted(const PortfolioEventHandler& value);
	void addPortfolioParentChanged(const PortfolioEventHandler& value);
	void addPositionChanged(const PositionEventHandler& value);
	void addPositionClosed(const PositionEventHandler& value);
	void addPositionOpened(const PositionEventHandler& value);
	void addProviderAdded(const ProviderEventHandler& value);
	void addProviderConnected(const ProviderEventHandler& value);
	void addProviderDisconnected(const ProviderEventHandler& value);
	void addProviderError(const ProviderErrorEventHandler& value);
	void addProviderRemoved(const ProviderEventHandler& value);
	void addProviderStatusChanged(const ProviderEventHandler& value);
	void addSimulatorProgress(const SimulatorProgressEventHandler& value);
	void addSimulatorStop(const EventHandler& value);
	void addTrade(const TradeEventHandler& value);
	void addTransaction(const TransactionEventHandler& value);
	void onEvent(const Event& e);
	void removeAccountData(const AccountDataEventHandler& value);
	void removeAsk(const AskEventHandler& value);
	void removeBar(const BarEventHandler& value);
	void removeBid(const BidEventHandler& value);
	void removeEventManagerPaused(const EventHandler& value);
	void removeEventManagerResumed(const EventHandler& value);
	void removeEventManagerStarted(const EventHandler& value);
	void removeEventManagerStep(const EventHandler& value);
	void removeEventManagerStopped(const EventHandler& value);
	void removeExecutionCommand(const ExecutionCommandEventHandler& value);
	void removeExecutionReport(const ExecutionReportEventHandler& value);
	void removeFill(const FillEventHandler& value);
	void removeFrameworkCleared(const FrameworkEventHandler& value);
	void removeHistoricalData(const HistoricalDataEventHandler& value);
	void removeHistoricalDataEnd(const HistoricalDataEndEventHandler& value);
	void removeInstrumentAdded(const InstrumentEventHandler& value);
	void removeInstrumentDefinition(const InstrumentDefinitionEventHandler& value);
	void removeInstrumentDefinitionEnd(const InstrumentDefinitionEndEventHandler& value);
	void removeInstrumentDeleted(const InstrumentEventHandler& value);
	void removeNewGroup(const GroupEventHandler& value);
	void removeNewGroupEvent(const GroupEventEventHandler& value);
	void removeNewGroupUpdate(const GroupUpdateEventHandler& value);
	void removeOrderManagerCleared(const OrderManagerClearedEventHandler& value);
	void removePortfolioAdded(const PortfolioEventHandler& value);
	void removePortfolioDeleted(const PortfolioEventHandler& value);
	void removePortfolioParentChanged(const PortfolioEventHandler& value);
	void removePositionChanged(const PositionEventHandler& value);
	void removePositionClosed(const PositionEventHandler& value);
	void removePositionOpened(const PositionEventHandler& value);
	void removeProviderAdded(const ProviderEventHandler& value);
	void removeProviderConnected(const ProviderEventHandler& value);
	void removeProviderDisconnected(const ProviderEventHandler& value);
	void removeProviderError(const ProviderErrorEventHandler& value);
	void removeProviderRemoved(const ProviderEventHandler& value);
	void removeProviderStatusChanged(const ProviderEventHandler& value);
	void removeSimulatorProgress(const SimulatorProgressEventHandler& value);
	void removeSimulatorStop(const EventHandler& value);
	void removeTrade(const TradeEventHandler& value);
	void removeTransaction(const TransactionEventHandler& value);
	virtual EventDispatcherPrivate* clone() Q_DECL_OVERRIDE { return new EventDispatcherPrivate(*this); }
//private:
	void method_0();
	void method_1(const Event& event);
};

} // namepsace QuantKit


using namespace QuantKit;

EventDispatcherPrivate::EventDispatcherPrivate(const Framework& framework)
	: framework(framework)
	, m_thread(new Thread(new ThreadStart(method_0())))
{
		if (eventQueue_0 != null)
		{
			m_thread.IsBackground = true;
			m_thread.Name = "Event Dispatcher Thread";
			m_thread.Start();
		}
}

EventDispatcherPrivate::~EventDispatcherPrivate ()
{
}

void EventDispatcherPrivate::addAccountData(const AccountDataEventHandler& value)
{
	AccountDataEventHandler accountDataEventHandler = accountDataEventHandler_0;
	AccountDataEventHandler accountDataEventHandler2;
	do
	{
		accountDataEventHandler2 = accountDataEventHandler;
		AccountDataEventHandler value2 = (AccountDataEventHandler)Delegate.Combine(accountDataEventHandler2, value);
		accountDataEventHandler = Interlocked.CompareExchange<AccountDataEventHandler>(ref accountDataEventHandler_0, value2, accountDataEventHandler2);
	}
	while (accountDataEventHandler != accountDataEventHandler2);
}

void EventDispatcherPrivate::addAsk(const AskEventHandler& value)
{
	AskEventHandler askEventHandler = askEventHandler_0;
	AskEventHandler askEventHandler2;
	do
	{
		askEventHandler2 = askEventHandler;
		AskEventHandler value2 = (AskEventHandler)Delegate.Combine(askEventHandler2, value);
		askEventHandler = Interlocked.CompareExchange<AskEventHandler>(ref askEventHandler_0, value2, askEventHandler2);
	}
	while (askEventHandler != askEventHandler2);
}

void EventDispatcherPrivate::addBar(const BarEventHandler& value)
{
	BarEventHandler barEventHandler = barEventHandler_0;
	BarEventHandler barEventHandler2;
	do
	{
		barEventHandler2 = barEventHandler;
		BarEventHandler value2 = (BarEventHandler)Delegate.Combine(barEventHandler2, value);
		barEventHandler = Interlocked.CompareExchange<BarEventHandler>(ref barEventHandler_0, value2, barEventHandler2);
	}
	while (barEventHandler != barEventHandler2);
}

void EventDispatcherPrivate::addBid(const BidEventHandler& value)
{
	BidEventHandler bidEventHandler = bidEventHandler_0;
	BidEventHandler bidEventHandler2;
	do
	{
		bidEventHandler2 = bidEventHandler;
		BidEventHandler value2 = (BidEventHandler)Delegate.Combine(bidEventHandler2, value);
		bidEventHandler = Interlocked.CompareExchange<BidEventHandler>(ref bidEventHandler_0, value2, bidEventHandler2);
	}
	while (bidEventHandler != bidEventHandler2);
}

void EventDispatcherPrivate::addEventManagerPaused(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_3;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_3, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::addEventManagerResumed(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_4;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_4, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::addEventManagerStarted(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_1;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_1, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::addEventManagerStep(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_5;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_5, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::addEventManagerStopped(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_2;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_2, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::addExecutionCommand(const ExecutionCommandEventHandler& value)
{
	ExecutionCommandEventHandler executionCommandEventHandler = executionCommandEventHandler_0;
	ExecutionCommandEventHandler executionCommandEventHandler2;
	do
	{
		executionCommandEventHandler2 = executionCommandEventHandler;
		ExecutionCommandEventHandler value2 = (ExecutionCommandEventHandler)Delegate.Combine(executionCommandEventHandler2, value);
		executionCommandEventHandler = Interlocked.CompareExchange<ExecutionCommandEventHandler>(ref executionCommandEventHandler_0, value2, executionCommandEventHandler2);
	}
	while (executionCommandEventHandler != executionCommandEventHandler2);
}

void EventDispatcherPrivate::addExecutionReport(const ExecutionReportEventHandler& value)
{
	ExecutionReportEventHandler executionReportEventHandler = executionReportEventHandler_0;
	ExecutionReportEventHandler executionReportEventHandler2;
	do
	{
		executionReportEventHandler2 = executionReportEventHandler;
		ExecutionReportEventHandler value2 = (ExecutionReportEventHandler)Delegate.Combine(executionReportEventHandler2, value);
		executionReportEventHandler = Interlocked.CompareExchange<ExecutionReportEventHandler>(ref executionReportEventHandler_0, value2, executionReportEventHandler2);
	}
	while (executionReportEventHandler != executionReportEventHandler2);
}

void EventDispatcherPrivate::addFill(const FillEventHandler& value)
{
	FillEventHandler fillEventHandler = fillEventHandler_0;
	FillEventHandler fillEventHandler2;
	do
	{
		fillEventHandler2 = fillEventHandler;
		FillEventHandler value2 = (FillEventHandler)Delegate.Combine(fillEventHandler2, value);
		fillEventHandler = Interlocked.CompareExchange<FillEventHandler>(ref fillEventHandler_0, value2, fillEventHandler2);
	}
	while (fillEventHandler != fillEventHandler2);
}

void EventDispatcherPrivate::addFrameworkCleared(const FrameworkEventHandler& value)
{
	FrameworkEventHandler frameworkEventHandler = frameworkEventHandler_0;
	FrameworkEventHandler frameworkEventHandler2;
	do
	{
		frameworkEventHandler2 = frameworkEventHandler;
		FrameworkEventHandler value2 = (FrameworkEventHandler)Delegate.Combine(frameworkEventHandler2, value);
		frameworkEventHandler = Interlocked.CompareExchange<FrameworkEventHandler>(ref frameworkEventHandler_0, value2, frameworkEventHandler2);
	}
	while (frameworkEventHandler != frameworkEventHandler2);
}

void EventDispatcherPrivate::addHistoricalData(const HistoricalDataEventHandler& value)
{
	HistoricalDataEventHandler historicalDataEventHandler = historicalDataEventHandler_0;
	HistoricalDataEventHandler historicalDataEventHandler2;
	do
	{
		historicalDataEventHandler2 = historicalDataEventHandler;
		HistoricalDataEventHandler value2 = (HistoricalDataEventHandler)Delegate.Combine(historicalDataEventHandler2, value);
		historicalDataEventHandler = Interlocked.CompareExchange<HistoricalDataEventHandler>(ref historicalDataEventHandler_0, value2, historicalDataEventHandler2);
	}
	while (historicalDataEventHandler != historicalDataEventHandler2);
}

void EventDispatcherPrivate::addHistoricalDataEnd(const HistoricalDataEndEventHandler& value)
{
	HistoricalDataEndEventHandler historicalDataEndEventHandler = historicalDataEndEventHandler_0;
	HistoricalDataEndEventHandler historicalDataEndEventHandler2;
	do
	{
		historicalDataEndEventHandler2 = historicalDataEndEventHandler;
		HistoricalDataEndEventHandler value2 = (HistoricalDataEndEventHandler)Delegate.Combine(historicalDataEndEventHandler2, value);
		historicalDataEndEventHandler = Interlocked.CompareExchange<HistoricalDataEndEventHandler>(ref historicalDataEndEventHandler_0, value2, historicalDataEndEventHandler2);
	}
	while (historicalDataEndEventHandler != historicalDataEndEventHandler2);
}

void EventDispatcherPrivate::addInstrumentAdded(const InstrumentEventHandler& value)
{
	InstrumentEventHandler instrumentEventHandler = instrumentEventHandler_0;
	InstrumentEventHandler instrumentEventHandler2;
	do
	{
		instrumentEventHandler2 = instrumentEventHandler;
		InstrumentEventHandler value2 = (InstrumentEventHandler)Delegate.Combine(instrumentEventHandler2, value);
		instrumentEventHandler = Interlocked.CompareExchange<InstrumentEventHandler>(ref instrumentEventHandler_0, value2, instrumentEventHandler2);
	}
	while (instrumentEventHandler != instrumentEventHandler2);
}

void EventDispatcherPrivate::addInstrumentDefinition(const InstrumentDefinitionEventHandler& value)
{
	InstrumentDefinitionEventHandler instrumentDefinitionEventHandler = instrumentDefinitionEventHandler_0;
	InstrumentDefinitionEventHandler instrumentDefinitionEventHandler2;
	do
	{
		instrumentDefinitionEventHandler2 = instrumentDefinitionEventHandler;
		InstrumentDefinitionEventHandler value2 = (InstrumentDefinitionEventHandler)Delegate.Combine(instrumentDefinitionEventHandler2, value);
		instrumentDefinitionEventHandler = Interlocked.CompareExchange<InstrumentDefinitionEventHandler>(ref instrumentDefinitionEventHandler_0, value2, instrumentDefinitionEventHandler2);
	}
	while (instrumentDefinitionEventHandler != instrumentDefinitionEventHandler2);
}

void EventDispatcherPrivate::addInstrumentDefinitionEnd(const InstrumentDefinitionEndEventHandler& value)
{
	InstrumentDefinitionEndEventHandler instrumentDefinitionEndEventHandler = instrumentDefinitionEndEventHandler_0;
	InstrumentDefinitionEndEventHandler instrumentDefinitionEndEventHandler2;
	do
	{
		instrumentDefinitionEndEventHandler2 = instrumentDefinitionEndEventHandler;
		InstrumentDefinitionEndEventHandler value2 = (InstrumentDefinitionEndEventHandler)Delegate.Combine(instrumentDefinitionEndEventHandler2, value);
		instrumentDefinitionEndEventHandler = Interlocked.CompareExchange<InstrumentDefinitionEndEventHandler>(ref instrumentDefinitionEndEventHandler_0, value2, instrumentDefinitionEndEventHandler2);
	}
	while (instrumentDefinitionEndEventHandler != instrumentDefinitionEndEventHandler2);
}

void EventDispatcherPrivate::addInstrumentDeleted(const InstrumentEventHandler& value)
{
	InstrumentEventHandler instrumentEventHandler = instrumentEventHandler_1;
	InstrumentEventHandler instrumentEventHandler2;
	do
	{
		instrumentEventHandler2 = instrumentEventHandler;
		InstrumentEventHandler value2 = (InstrumentEventHandler)Delegate.Combine(instrumentEventHandler2, value);
		instrumentEventHandler = Interlocked.CompareExchange<InstrumentEventHandler>(ref instrumentEventHandler_1, value2, instrumentEventHandler2);
	}
	while (instrumentEventHandler != instrumentEventHandler2);
}

void EventDispatcherPrivate::addNewGroup(const GroupEventHandler& value)
{
	GroupEventHandler groupEventHandler = groupEventHandler_0;
	GroupEventHandler groupEventHandler2;
	do
	{
		groupEventHandler2 = groupEventHandler;
		GroupEventHandler value2 = (GroupEventHandler)Delegate.Combine(groupEventHandler2, value);
		groupEventHandler = Interlocked.CompareExchange<GroupEventHandler>(ref groupEventHandler_0, value2, groupEventHandler2);
	}
	while (groupEventHandler != groupEventHandler2);
}

void EventDispatcherPrivate::addNewGroupEvent(const GroupEventEventHandler& value)
{
	GroupEventEventHandler groupEventEventHandler = groupEventEventHandler_0;
	GroupEventEventHandler groupEventEventHandler2;
	do
	{
		groupEventEventHandler2 = groupEventEventHandler;
		GroupEventEventHandler value2 = (GroupEventEventHandler)Delegate.Combine(groupEventEventHandler2, value);
		groupEventEventHandler = Interlocked.CompareExchange<GroupEventEventHandler>(ref groupEventEventHandler_0, value2, groupEventEventHandler2);
	}
	while (groupEventEventHandler != groupEventEventHandler2);
}

void EventDispatcherPrivate::addNewGroupUpdate(const GroupUpdateEventHandler& value)
{
	GroupUpdateEventHandler groupUpdateEventHandler = groupUpdateEventHandler_0;
	GroupUpdateEventHandler groupUpdateEventHandler2;
	do
	{
		groupUpdateEventHandler2 = groupUpdateEventHandler;
		GroupUpdateEventHandler value2 = (GroupUpdateEventHandler)Delegate.Combine(groupUpdateEventHandler2, value);
		groupUpdateEventHandler = Interlocked.CompareExchange<GroupUpdateEventHandler>(ref groupUpdateEventHandler_0, value2, groupUpdateEventHandler2);
	}
	while (groupUpdateEventHandler != groupUpdateEventHandler2);
}

void EventDispatcherPrivate::addOrderManagerCleared(const OrderManagerClearedEventHandler& value)
{
	OrderManagerClearedEventHandler orderManagerClearedEventHandler = orderManagerClearedEventHandler_0;
	OrderManagerClearedEventHandler orderManagerClearedEventHandler2;
	do
	{
		orderManagerClearedEventHandler2 = orderManagerClearedEventHandler;
		OrderManagerClearedEventHandler value2 = (OrderManagerClearedEventHandler)Delegate.Combine(orderManagerClearedEventHandler2, value);
		orderManagerClearedEventHandler = Interlocked.CompareExchange<OrderManagerClearedEventHandler>(ref orderManagerClearedEventHandler_0, value2, orderManagerClearedEventHandler2);
	}
	while (orderManagerClearedEventHandler != orderManagerClearedEventHandler2);
}

void EventDispatcherPrivate::addPortfolioAdded(const PortfolioEventHandler& value)
{
	PortfolioEventHandler portfolioEventHandler = portfolioEventHandler_0;
	PortfolioEventHandler portfolioEventHandler2;
	do
	{
		portfolioEventHandler2 = portfolioEventHandler;
		PortfolioEventHandler value2 = (PortfolioEventHandler)Delegate.Combine(portfolioEventHandler2, value);
		portfolioEventHandler = Interlocked.CompareExchange<PortfolioEventHandler>(ref portfolioEventHandler_0, value2, portfolioEventHandler2);
	}
	while (portfolioEventHandler != portfolioEventHandler2);
}

void EventDispatcherPrivate::addPortfolioDeleted(const PortfolioEventHandler& value)
{
	PortfolioEventHandler portfolioEventHandler = portfolioEventHandler_1;
	PortfolioEventHandler portfolioEventHandler2;
	do
	{
		portfolioEventHandler2 = portfolioEventHandler;
		PortfolioEventHandler value2 = (PortfolioEventHandler)Delegate.Combine(portfolioEventHandler2, value);
		portfolioEventHandler = Interlocked.CompareExchange<PortfolioEventHandler>(ref portfolioEventHandler_1, value2, portfolioEventHandler2);
	}
	while (portfolioEventHandler != portfolioEventHandler2);
}

void EventDispatcherPrivate::addPortfolioParentChanged(const PortfolioEventHandler& value)
{
	PortfolioEventHandler portfolioEventHandler = portfolioEventHandler_2;
	PortfolioEventHandler portfolioEventHandler2;
	do
	{
		portfolioEventHandler2 = portfolioEventHandler;
		PortfolioEventHandler value2 = (PortfolioEventHandler)Delegate.Combine(portfolioEventHandler2, value);
		portfolioEventHandler = Interlocked.CompareExchange<PortfolioEventHandler>(ref portfolioEventHandler_2, value2, portfolioEventHandler2);
	}
	while (portfolioEventHandler != portfolioEventHandler2);
}

void EventDispatcherPrivate::addPositionChanged(const PositionEventHandler& value)
{
	PositionEventHandler positionEventHandler = positionEventHandler_1;
	PositionEventHandler positionEventHandler2;
	do
	{
		positionEventHandler2 = positionEventHandler;
		PositionEventHandler value2 = (PositionEventHandler)Delegate.Combine(positionEventHandler2, value);
		positionEventHandler = Interlocked.CompareExchange<PositionEventHandler>(ref positionEventHandler_1, value2, positionEventHandler2);
	}
	while (positionEventHandler != positionEventHandler2);
}

void EventDispatcherPrivate::addPositionClosed(const PositionEventHandler& value)
{
	PositionEventHandler positionEventHandler = positionEventHandler_2;
	PositionEventHandler positionEventHandler2;
	do
	{
		positionEventHandler2 = positionEventHandler;
		PositionEventHandler value2 = (PositionEventHandler)Delegate.Combine(positionEventHandler2, value);
		positionEventHandler = Interlocked.CompareExchange<PositionEventHandler>(ref positionEventHandler_2, value2, positionEventHandler2);
	}
	while (positionEventHandler != positionEventHandler2);
}

void EventDispatcherPrivate::addPositionOpened(const PositionEventHandler& value)
{
	PositionEventHandler positionEventHandler = positionEventHandler_0;
	PositionEventHandler positionEventHandler2;
	do
	{
		positionEventHandler2 = positionEventHandler;
		PositionEventHandler value2 = (PositionEventHandler)Delegate.Combine(positionEventHandler2, value);
		positionEventHandler = Interlocked.CompareExchange<PositionEventHandler>(ref positionEventHandler_0, value2, positionEventHandler2);
	}
	while (positionEventHandler != positionEventHandler2);
}

void EventDispatcherPrivate::addProviderAdded(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_0;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Combine(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_0, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::addProviderConnected(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_3;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Combine(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_3, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::addProviderDisconnected(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_4;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Combine(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_4, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::addProviderError(const ProviderErrorEventHandler& value)
{
	ProviderErrorEventHandler providerErrorEventHandler = providerErrorEventHandler_0;
	ProviderErrorEventHandler providerErrorEventHandler2;
	do
	{
		providerErrorEventHandler2 = providerErrorEventHandler;
		ProviderErrorEventHandler value2 = (ProviderErrorEventHandler)Delegate.Combine(providerErrorEventHandler2, value);
		providerErrorEventHandler = Interlocked.CompareExchange<ProviderErrorEventHandler>(ref providerErrorEventHandler_0, value2, providerErrorEventHandler2);
	}
	while (providerErrorEventHandler != providerErrorEventHandler2);
}

void EventDispatcherPrivate::addProviderRemoved(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_1;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Combine(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_1, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::addProviderStatusChanged(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_2;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Combine(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_2, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::addSimulatorProgress(const SimulatorProgressEventHandler& value)
{
	SimulatorProgressEventHandler simulatorProgressEventHandler = simulatorProgressEventHandler_0;
	SimulatorProgressEventHandler simulatorProgressEventHandler2;
	do
	{
		simulatorProgressEventHandler2 = simulatorProgressEventHandler;
		SimulatorProgressEventHandler value2 = (SimulatorProgressEventHandler)Delegate.Combine(simulatorProgressEventHandler2, value);
		simulatorProgressEventHandler = Interlocked.CompareExchange<SimulatorProgressEventHandler>(ref simulatorProgressEventHandler_0, value2, simulatorProgressEventHandler2);
	}
	while (simulatorProgressEventHandler != simulatorProgressEventHandler2);
}

void EventDispatcherPrivate::addSimulatorStop(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_0;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_0, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::addTrade(const TradeEventHandler& value)
{
	TradeEventHandler tradeEventHandler = tradeEventHandler_0;
	TradeEventHandler tradeEventHandler2;
	do
	{
		tradeEventHandler2 = tradeEventHandler;
		TradeEventHandler value2 = (TradeEventHandler)Delegate.Combine(tradeEventHandler2, value);
		tradeEventHandler = Interlocked.CompareExchange<TradeEventHandler>(ref tradeEventHandler_0, value2, tradeEventHandler2);
	}
	while (tradeEventHandler != tradeEventHandler2);
}

void EventDispatcherPrivate::addTransaction(const TransactionEventHandler& value)
{
	TransactionEventHandler transactionEventHandler = transactionEventHandler_0;
	TransactionEventHandler transactionEventHandler2;
	do
	{
		transactionEventHandler2 = transactionEventHandler;
		TransactionEventHandler value2 = (TransactionEventHandler)Delegate.Combine(transactionEventHandler2, value);
		transactionEventHandler = Interlocked.CompareExchange<TransactionEventHandler>(ref transactionEventHandler_0, value2, transactionEventHandler2);
	}
	while (transactionEventHandler != transactionEventHandler2);
}

void EventDispatcherPrivate::onEvent(const Event& e)
{
	if (framework.mode() != FrameworkMode.Simulation && eventQueue_0 != null)
	{
		eventQueue_0.Enqueue(e);
		return;
	}
	method_1(e);
}

void EventDispatcherPrivate::removeAccountData(const AccountDataEventHandler& value)
{
	AccountDataEventHandler accountDataEventHandler = accountDataEventHandler_0;
	AccountDataEventHandler accountDataEventHandler2;
	do
	{
		accountDataEventHandler2 = accountDataEventHandler;
		AccountDataEventHandler value2 = (AccountDataEventHandler)Delegate.Remove(accountDataEventHandler2, value);
		accountDataEventHandler = Interlocked.CompareExchange<AccountDataEventHandler>(ref accountDataEventHandler_0, value2, accountDataEventHandler2);
	}
	while (accountDataEventHandler != accountDataEventHandler2);
}

void EventDispatcherPrivate::removeAsk(const AskEventHandler& value)
{
	AskEventHandler askEventHandler = askEventHandler_0;
	AskEventHandler askEventHandler2;
	do
	{
		askEventHandler2 = askEventHandler;
		AskEventHandler value2 = (AskEventHandler)Delegate.Remove(askEventHandler2, value);
		askEventHandler = Interlocked.CompareExchange<AskEventHandler>(ref askEventHandler_0, value2, askEventHandler2);
	}
	while (askEventHandler != askEventHandler2);
}

void EventDispatcherPrivate::removeBar(const BarEventHandler& value)
{
	BarEventHandler barEventHandler = barEventHandler_0;
	BarEventHandler barEventHandler2;
	do
	{
		barEventHandler2 = barEventHandler;
		BarEventHandler value2 = (BarEventHandler)Delegate.Remove(barEventHandler2, value);
		barEventHandler = Interlocked.CompareExchange<BarEventHandler>(ref barEventHandler_0, value2, barEventHandler2);
	}
	while (barEventHandler != barEventHandler2);
}

void EventDispatcherPrivate::removeBid(const BidEventHandler& value)
{
	BidEventHandler bidEventHandler = bidEventHandler_0;
	BidEventHandler bidEventHandler2;
	do
	{
		bidEventHandler2 = bidEventHandler;
		BidEventHandler value2 = (BidEventHandler)Delegate.Remove(bidEventHandler2, value);
		bidEventHandler = Interlocked.CompareExchange<BidEventHandler>(ref bidEventHandler_0, value2, bidEventHandler2);
	}
	while (bidEventHandler != bidEventHandler2);
}

void EventDispatcherPrivate::removeEventManagerPaused(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_3;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_3, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::removeEventManagerResumed(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_4;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_4, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::removeEventManagerStarted(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_1;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_1, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::removeEventManagerStep(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_5;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_5, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::removeEventManagerStopped(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_2;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_2, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::removeExecutionCommand(const ExecutionCommandEventHandler& value)
{
	ExecutionCommandEventHandler executionCommandEventHandler = executionCommandEventHandler_0;
	ExecutionCommandEventHandler executionCommandEventHandler2;
	do
	{
		executionCommandEventHandler2 = executionCommandEventHandler;
		ExecutionCommandEventHandler value2 = (ExecutionCommandEventHandler)Delegate.Remove(executionCommandEventHandler2, value);
		executionCommandEventHandler = Interlocked.CompareExchange<ExecutionCommandEventHandler>(ref executionCommandEventHandler_0, value2, executionCommandEventHandler2);
	}
	while (executionCommandEventHandler != executionCommandEventHandler2);
}

void EventDispatcherPrivate::removeExecutionReport(const ExecutionReportEventHandler& value)
{
	ExecutionReportEventHandler executionReportEventHandler = executionReportEventHandler_0;
	ExecutionReportEventHandler executionReportEventHandler2;
	do
	{
		executionReportEventHandler2 = executionReportEventHandler;
		ExecutionReportEventHandler value2 = (ExecutionReportEventHandler)Delegate.Remove(executionReportEventHandler2, value);
		executionReportEventHandler = Interlocked.CompareExchange<ExecutionReportEventHandler>(ref executionReportEventHandler_0, value2, executionReportEventHandler2);
	}
	while (executionReportEventHandler != executionReportEventHandler2);
}

void EventDispatcherPrivate::removeFill(const FillEventHandler& value)
{
	FillEventHandler fillEventHandler = fillEventHandler_0;
	FillEventHandler fillEventHandler2;
	do
	{
		fillEventHandler2 = fillEventHandler;
		FillEventHandler value2 = (FillEventHandler)Delegate.Remove(fillEventHandler2, value);
		fillEventHandler = Interlocked.CompareExchange<FillEventHandler>(ref fillEventHandler_0, value2, fillEventHandler2);
	}
	while (fillEventHandler != fillEventHandler2);
}

void EventDispatcherPrivate::removeFrameworkCleared(const FrameworkEventHandler& value)
{
	FrameworkEventHandler frameworkEventHandler = frameworkEventHandler_0;
	FrameworkEventHandler frameworkEventHandler2;
	do
	{
		frameworkEventHandler2 = frameworkEventHandler;
		FrameworkEventHandler value2 = (FrameworkEventHandler)Delegate.Remove(frameworkEventHandler2, value);
		frameworkEventHandler = Interlocked.CompareExchange<FrameworkEventHandler>(ref frameworkEventHandler_0, value2, frameworkEventHandler2);
	}
	while (frameworkEventHandler != frameworkEventHandler2);
}

void EventDispatcherPrivate::removeHistoricalData(const HistoricalDataEventHandler& value)
{
	HistoricalDataEventHandler historicalDataEventHandler = historicalDataEventHandler_0;
	HistoricalDataEventHandler historicalDataEventHandler2;
	do
	{
		historicalDataEventHandler2 = historicalDataEventHandler;
		HistoricalDataEventHandler value2 = (HistoricalDataEventHandler)Delegate.Remove(historicalDataEventHandler2, value);
		historicalDataEventHandler = Interlocked.CompareExchange<HistoricalDataEventHandler>(ref historicalDataEventHandler_0, value2, historicalDataEventHandler2);
	}
	while (historicalDataEventHandler != historicalDataEventHandler2);
}

void EventDispatcherPrivate::removeHistoricalDataEnd(const HistoricalDataEndEventHandler& value)
{
	HistoricalDataEndEventHandler historicalDataEndEventHandler = historicalDataEndEventHandler_0;
	HistoricalDataEndEventHandler historicalDataEndEventHandler2;
	do
	{
		historicalDataEndEventHandler2 = historicalDataEndEventHandler;
		HistoricalDataEndEventHandler value2 = (HistoricalDataEndEventHandler)Delegate.Remove(historicalDataEndEventHandler2, value);
		historicalDataEndEventHandler = Interlocked.CompareExchange<HistoricalDataEndEventHandler>(ref historicalDataEndEventHandler_0, value2, historicalDataEndEventHandler2);
	}
	while (historicalDataEndEventHandler != historicalDataEndEventHandler2);
}

void EventDispatcherPrivate::removeInstrumentAdded(const InstrumentEventHandler& value)
{
	InstrumentEventHandler instrumentEventHandler = instrumentEventHandler_0;
	InstrumentEventHandler instrumentEventHandler2;
	do
	{
		instrumentEventHandler2 = instrumentEventHandler;
		InstrumentEventHandler value2 = (InstrumentEventHandler)Delegate.Remove(instrumentEventHandler2, value);
		instrumentEventHandler = Interlocked.CompareExchange<InstrumentEventHandler>(ref instrumentEventHandler_0, value2, instrumentEventHandler2);
	}
	while (instrumentEventHandler != instrumentEventHandler2);
}

void EventDispatcherPrivate::removeInstrumentDefinition(const InstrumentDefinitionEventHandler& value)
{
	InstrumentDefinitionEventHandler instrumentDefinitionEventHandler = instrumentDefinitionEventHandler_0;
	InstrumentDefinitionEventHandler instrumentDefinitionEventHandler2;
	do
	{
		instrumentDefinitionEventHandler2 = instrumentDefinitionEventHandler;
		InstrumentDefinitionEventHandler value2 = (InstrumentDefinitionEventHandler)Delegate.Remove(instrumentDefinitionEventHandler2, value);
		instrumentDefinitionEventHandler = Interlocked.CompareExchange<InstrumentDefinitionEventHandler>(ref instrumentDefinitionEventHandler_0, value2, instrumentDefinitionEventHandler2);
	}
	while (instrumentDefinitionEventHandler != instrumentDefinitionEventHandler2);
}

void EventDispatcherPrivate::removeInstrumentDefinitionEnd(const InstrumentDefinitionEndEventHandler& value)
{
	InstrumentDefinitionEndEventHandler instrumentDefinitionEndEventHandler = instrumentDefinitionEndEventHandler_0;
	InstrumentDefinitionEndEventHandler instrumentDefinitionEndEventHandler2;
	do
	{
		instrumentDefinitionEndEventHandler2 = instrumentDefinitionEndEventHandler;
		InstrumentDefinitionEndEventHandler value2 = (InstrumentDefinitionEndEventHandler)Delegate.Remove(instrumentDefinitionEndEventHandler2, value);
		instrumentDefinitionEndEventHandler = Interlocked.CompareExchange<InstrumentDefinitionEndEventHandler>(ref instrumentDefinitionEndEventHandler_0, value2, instrumentDefinitionEndEventHandler2);
	}
	while (instrumentDefinitionEndEventHandler != instrumentDefinitionEndEventHandler2);
}

void EventDispatcherPrivate::removeInstrumentDeleted(const InstrumentEventHandler& value)
{
	InstrumentEventHandler instrumentEventHandler = instrumentEventHandler_1;
	InstrumentEventHandler instrumentEventHandler2;
	do
	{
		instrumentEventHandler2 = instrumentEventHandler;
		InstrumentEventHandler value2 = (InstrumentEventHandler)Delegate.Remove(instrumentEventHandler2, value);
		instrumentEventHandler = Interlocked.CompareExchange<InstrumentEventHandler>(ref instrumentEventHandler_1, value2, instrumentEventHandler2);
	}
	while (instrumentEventHandler != instrumentEventHandler2);
}

void EventDispatcherPrivate::removeNewGroup(const GroupEventHandler& value)
{
	GroupEventHandler groupEventHandler = groupEventHandler_0;
	GroupEventHandler groupEventHandler2;
	do
	{
		groupEventHandler2 = groupEventHandler;
		GroupEventHandler value2 = (GroupEventHandler)Delegate.Remove(groupEventHandler2, value);
		groupEventHandler = Interlocked.CompareExchange<GroupEventHandler>(ref groupEventHandler_0, value2, groupEventHandler2);
	}
	while (groupEventHandler != groupEventHandler2);
}

void EventDispatcherPrivate::removeNewGroupEvent(const GroupEventEventHandler& value)
{
	GroupEventEventHandler groupEventEventHandler = groupEventEventHandler_0;
	GroupEventEventHandler groupEventEventHandler2;
	do
	{
		groupEventEventHandler2 = groupEventEventHandler;
		GroupEventEventHandler value2 = (GroupEventEventHandler)Delegate.Remove(groupEventEventHandler2, value);
		groupEventEventHandler = Interlocked.CompareExchange<GroupEventEventHandler>(ref groupEventEventHandler_0, value2, groupEventEventHandler2);
	}
	while (groupEventEventHandler != groupEventEventHandler2);
}

void EventDispatcherPrivate::removeNewGroupUpdate(const GroupUpdateEventHandler& value)
{
	GroupUpdateEventHandler groupUpdateEventHandler = groupUpdateEventHandler_0;
	GroupUpdateEventHandler groupUpdateEventHandler2;
	do
	{
		groupUpdateEventHandler2 = groupUpdateEventHandler;
		GroupUpdateEventHandler value2 = (GroupUpdateEventHandler)Delegate.Remove(groupUpdateEventHandler2, value);
		groupUpdateEventHandler = Interlocked.CompareExchange<GroupUpdateEventHandler>(ref groupUpdateEventHandler_0, value2, groupUpdateEventHandler2);
	}
	while (groupUpdateEventHandler != groupUpdateEventHandler2);
}

void EventDispatcherPrivate::removeOrderManagerCleared(const OrderManagerClearedEventHandler& value)
{
	OrderManagerClearedEventHandler orderManagerClearedEventHandler = orderManagerClearedEventHandler_0;
	OrderManagerClearedEventHandler orderManagerClearedEventHandler2;
	do
	{
		orderManagerClearedEventHandler2 = orderManagerClearedEventHandler;
		OrderManagerClearedEventHandler value2 = (OrderManagerClearedEventHandler)Delegate.Remove(orderManagerClearedEventHandler2, value);
		orderManagerClearedEventHandler = Interlocked.CompareExchange<OrderManagerClearedEventHandler>(ref orderManagerClearedEventHandler_0, value2, orderManagerClearedEventHandler2);
	}
	while (orderManagerClearedEventHandler != orderManagerClearedEventHandler2);
}

void EventDispatcherPrivate::removePortfolioAdded(const PortfolioEventHandler& value)
{
	PortfolioEventHandler portfolioEventHandler = portfolioEventHandler_0;
	PortfolioEventHandler portfolioEventHandler2;
	do
	{
		portfolioEventHandler2 = portfolioEventHandler;
		PortfolioEventHandler value2 = (PortfolioEventHandler)Delegate.Remove(portfolioEventHandler2, value);
		portfolioEventHandler = Interlocked.CompareExchange<PortfolioEventHandler>(ref portfolioEventHandler_0, value2, portfolioEventHandler2);
	}
	while (portfolioEventHandler != portfolioEventHandler2);
}

void EventDispatcherPrivate::removePortfolioDeleted(const PortfolioEventHandler& value)
{
	PortfolioEventHandler portfolioEventHandler = portfolioEventHandler_1;
	PortfolioEventHandler portfolioEventHandler2;
	do
	{
		portfolioEventHandler2 = portfolioEventHandler;
		PortfolioEventHandler value2 = (PortfolioEventHandler)Delegate.Remove(portfolioEventHandler2, value);
		portfolioEventHandler = Interlocked.CompareExchange<PortfolioEventHandler>(ref portfolioEventHandler_1, value2, portfolioEventHandler2);
	}
	while (portfolioEventHandler != portfolioEventHandler2);
}

void EventDispatcherPrivate::removePortfolioParentChanged(const PortfolioEventHandler& value)
{
	PortfolioEventHandler portfolioEventHandler = portfolioEventHandler_2;
	PortfolioEventHandler portfolioEventHandler2;
	do
	{
		portfolioEventHandler2 = portfolioEventHandler;
		PortfolioEventHandler value2 = (PortfolioEventHandler)Delegate.Remove(portfolioEventHandler2, value);
		portfolioEventHandler = Interlocked.CompareExchange<PortfolioEventHandler>(ref portfolioEventHandler_2, value2, portfolioEventHandler2);
	}
	while (portfolioEventHandler != portfolioEventHandler2);
}

void EventDispatcherPrivate::removePositionChanged(const PositionEventHandler& value)
{
	PositionEventHandler positionEventHandler = positionEventHandler_1;
	PositionEventHandler positionEventHandler2;
	do
	{
		positionEventHandler2 = positionEventHandler;
		PositionEventHandler value2 = (PositionEventHandler)Delegate.Remove(positionEventHandler2, value);
		positionEventHandler = Interlocked.CompareExchange<PositionEventHandler>(ref positionEventHandler_1, value2, positionEventHandler2);
	}
	while (positionEventHandler != positionEventHandler2);
}

void EventDispatcherPrivate::removePositionClosed(const PositionEventHandler& value)
{
	PositionEventHandler positionEventHandler = positionEventHandler_2;
	PositionEventHandler positionEventHandler2;
	do
	{
		positionEventHandler2 = positionEventHandler;
		PositionEventHandler value2 = (PositionEventHandler)Delegate.Remove(positionEventHandler2, value);
		positionEventHandler = Interlocked.CompareExchange<PositionEventHandler>(ref positionEventHandler_2, value2, positionEventHandler2);
	}
	while (positionEventHandler != positionEventHandler2);
}

void EventDispatcherPrivate::removePositionOpened(const PositionEventHandler& value)
{
	PositionEventHandler positionEventHandler = positionEventHandler_0;
	PositionEventHandler positionEventHandler2;
	do
	{
		positionEventHandler2 = positionEventHandler;
		PositionEventHandler value2 = (PositionEventHandler)Delegate.Remove(positionEventHandler2, value);
		positionEventHandler = Interlocked.CompareExchange<PositionEventHandler>(ref positionEventHandler_0, value2, positionEventHandler2);
	}
	while (positionEventHandler != positionEventHandler2);
}

void EventDispatcherPrivate::removeProviderAdded(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_0;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Remove(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_0, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::removeProviderConnected(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_3;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Remove(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_3, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::removeProviderDisconnected(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_4;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Remove(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_4, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::removeProviderError(const ProviderErrorEventHandler& value)
{
	ProviderErrorEventHandler providerErrorEventHandler = providerErrorEventHandler_0;
	ProviderErrorEventHandler providerErrorEventHandler2;
	do
	{
		providerErrorEventHandler2 = providerErrorEventHandler;
		ProviderErrorEventHandler value2 = (ProviderErrorEventHandler)Delegate.Remove(providerErrorEventHandler2, value);
		providerErrorEventHandler = Interlocked.CompareExchange<ProviderErrorEventHandler>(ref providerErrorEventHandler_0, value2, providerErrorEventHandler2);
	}
	while (providerErrorEventHandler != providerErrorEventHandler2);
}

void EventDispatcherPrivate::removeProviderRemoved(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_1;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Remove(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_1, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::removeProviderStatusChanged(const ProviderEventHandler& value)
{
	ProviderEventHandler providerEventHandler = providerEventHandler_2;
	ProviderEventHandler providerEventHandler2;
	do
	{
		providerEventHandler2 = providerEventHandler;
		ProviderEventHandler value2 = (ProviderEventHandler)Delegate.Remove(providerEventHandler2, value);
		providerEventHandler = Interlocked.CompareExchange<ProviderEventHandler>(ref providerEventHandler_2, value2, providerEventHandler2);
	}
	while (providerEventHandler != providerEventHandler2);
}

void EventDispatcherPrivate::removeSimulatorProgress(const SimulatorProgressEventHandler& value)
{
	SimulatorProgressEventHandler simulatorProgressEventHandler = simulatorProgressEventHandler_0;
	SimulatorProgressEventHandler simulatorProgressEventHandler2;
	do
	{
		simulatorProgressEventHandler2 = simulatorProgressEventHandler;
		SimulatorProgressEventHandler value2 = (SimulatorProgressEventHandler)Delegate.Remove(simulatorProgressEventHandler2, value);
		simulatorProgressEventHandler = Interlocked.CompareExchange<SimulatorProgressEventHandler>(ref simulatorProgressEventHandler_0, value2, simulatorProgressEventHandler2);
	}
	while (simulatorProgressEventHandler != simulatorProgressEventHandler2);
}

void EventDispatcherPrivate::removeSimulatorStop(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_0;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_0, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void EventDispatcherPrivate::removeTrade(const TradeEventHandler& value)
{
	TradeEventHandler tradeEventHandler = tradeEventHandler_0;
	TradeEventHandler tradeEventHandler2;
	do
	{
		tradeEventHandler2 = tradeEventHandler;
		TradeEventHandler value2 = (TradeEventHandler)Delegate.Remove(tradeEventHandler2, value);
		tradeEventHandler = Interlocked.CompareExchange<TradeEventHandler>(ref tradeEventHandler_0, value2, tradeEventHandler2);
	}
	while (tradeEventHandler != tradeEventHandler2);
}

void EventDispatcherPrivate::removeTransaction(const TransactionEventHandler& value)
{
	TransactionEventHandler transactionEventHandler = transactionEventHandler_0;
	TransactionEventHandler transactionEventHandler2;
	do
	{
		transactionEventHandler2 = transactionEventHandler;
		TransactionEventHandler value2 = (TransactionEventHandler)Delegate.Remove(transactionEventHandler2, value);
		transactionEventHandler = Interlocked.CompareExchange<TransactionEventHandler>(ref transactionEventHandler_0, value2, transactionEventHandler2);
	}
	while (transactionEventHandler != transactionEventHandler2);
}

void EventDispatcherPrivate::method_0()
{
	Console.WriteLine("Event dispatcher thread started: Framework = " + framework.name() + " Clock = " + framework.clock().GetModeAsString());
	while (true)
	{
		if (framework.mode() != FrameworkMode.Simulation && !eventQueue_0.IsEmpty())
		{
			method_1(eventQueue_0.Read());
		}
		else
		{
			Thread.Sleep(1);
		}
	}
}

void EventDispatcherPrivate::method_1(const Event& event)
{
	byte typeId = @event.typeId();
	if (typeId <= 52)
	{
		if (typeId <= 14)
		{
			switch (typeId)
			{
				case 2:
					if (bidEventHandler_0 != null)
					{
						bidEventHandler_0(this, (Bid)@event);
						return;
					}
					break;
				case 3:
					if (askEventHandler_0 != null)
					{
						askEventHandler_0(this, (Ask)@event);
						return;
					}
					break;
				case 4:
					if (tradeEventHandler_0 != null)
					{
						tradeEventHandler_0(this, (Trade)@event);
						return;
					}
					break;
				case 5:
					break;
				case 6:
					if (barEventHandler_0 != null)
					{
						barEventHandler_0(this, (Bar)@event);
						return;
					}
					break;
				default:
					switch (typeId)
					{
						case 13:
							if (executionReportEventHandler_0 != null)
							{
								executionReportEventHandler_0(this, (ExecutionReport)@event);
								return;
							}
							break;
						case 14:
							if (executionCommandEventHandler_0 != null)
							{
								executionCommandEventHandler_0(this, (ExecutionCommand)@event);
								return;
							}
							break;
						default:
							return;
					}
					break;
			}
		}
		else
		{
			if (typeId != 21)
			{
				switch (typeId)
				{
					case 50:
						if (groupEventHandler_0 != null)
						{
							groupEventHandler_0(this, new GroupEventAgrs((Group)@event));
							return;
						}
						break;
					case 51:
						if (groupUpdateEventHandler_0 != null)
						{
							groupUpdateEventHandler_0(this, new GroupUpdateEventAgrs((GroupUpdate)@event));
							return;
						}
						break;
					case 52:
						if (groupEventEventHandler_0 != null)
						{
							groupEventEventHandler_0(this, new GroupEventEventAgrs((GroupEvent)@event));
							return;
						}
						break;
					default:
						return;
				}
			}
			else
			{
				if (providerErrorEventHandler_0 != null)
				{
					providerErrorEventHandler_0(this, new ProviderErrorEventArgs((ProviderError)@event));
					return;
				}
			}
		}
	}
	else
	{
		if (typeId <= 114)
		{
			if (typeId != 99)
			{
				switch (typeId)
				{
					case 110:
						if (positionEventHandler_0 != null)
						{
							positionEventHandler_0(this, new PositionEventArgs(((OnPositionOpened)@event).portfolio(), ((OnPositionOpened)@event).position()));
							return;
						}
						break;
					case 111:
						if (positionEventHandler_2 != null)
						{
							positionEventHandler_2(this, new PositionEventArgs(((OnPositionClosed)@event).portfolio(), ((OnPositionClosed)@event).position()));
							return;
						}
						break;
					case 112:
						if (positionEventHandler_1 != null)
						{
							positionEventHandler_1(this, new PositionEventArgs(((OnPositionChanged)@event).portfolio(), ((OnPositionChanged)@event).position()));
							return;
						}
						break;
					case 113:
						if (fillEventHandler_0 != null)
						{
							fillEventHandler_0(this, (OnFill)@event);
							return;
						}
						break;
					case 114:
						if (transactionEventHandler_0 != null)
						{
							transactionEventHandler_0(this, (OnTransaction)@event);
							return;
						}
						break;
					default:
						return;
				}
			}
			else
			{
				if (frameworkEventHandler_0 != null)
				{
					frameworkEventHandler_0(this, new FrameworkEventArgs(((OnFrameworkCleared)@event).framework()));
					return;
				}
			}
		}
		else
		{
			switch (typeId)
			{
				case 128:
					if (orderManagerClearedEventHandler_0 != null)
					{
						orderManagerClearedEventHandler_0(this, (OnOrderManagerCleared)@event);
						return;
					}
					break;
				case 129:
					if (instrumentDefinitionEventHandler_0 != null)
					{
						instrumentDefinitionEventHandler_0(this, new InstrumentDefinitionEventArgs(((OnInstrumentDefinition)@event).instrumentDefinition()));
						return;
					}
					break;
				case 130:
					if (instrumentDefinitionEndEventHandler_0 != null)
					{
						instrumentDefinitionEndEventHandler_0(this, new InstrumentDefinitionEndEventArgs(((OnInstrumentDefinitionEnd)@event).instrumentDefinitionEnd()));
						return;
					}
					break;
				case 131:
				case 132:
				case 138:
				case 139:
					break;
				case 133:
					if (portfolioEventHandler_0 != null)
					{
						portfolioEventHandler_0(this, new PortfolioEventArgs(((OnPortfolioAdded)@event).portfolio()));
						return;
					}
					break;
				case 134:
					if (portfolioEventHandler_1 != null)
					{
						portfolioEventHandler_1(this, new PortfolioEventArgs(((OnPortfolioDeleted)@event).portfolio()));
						return;
					}
					break;
				case 135:
					if (portfolioEventHandler_2 != null)
					{
						portfolioEventHandler_2(this, new PortfolioEventArgs(((OnPortfolioParentChanged)@event).portfolio()));
						return;
					}
					break;
				case 136:
					if (historicalDataEventHandler_0 != null)
					{
						historicalDataEventHandler_0(this, new HistoricalDataEventArgs((HistoricalData)@event));
						return;
					}
					break;
				case 137:
					if (historicalDataEndEventHandler_0 != null)
					{
						historicalDataEndEventHandler_0(this, new HistoricalDataEndEventArgs((HistoricalDataEnd)@event));
						return;
					}
					break;
				case 140:
					if (accountDataEventHandler_0 != null)
					{
						accountDataEventHandler_0(this, new AccountDataEventArgs((AccountData)@event));
						return;
					}
					break;
				default:
					switch (typeId)
					{
						case 207:
							if (eventHandler_1 != null)
							{
								eventHandler_1(this, EventArgs.Empty);
								return;
							}
							break;
						case 208:
							if (eventHandler_2 != null)
							{
								eventHandler_2(this, EventArgs.Empty);
								return;
							}
							break;
						case 209:
							if (eventHandler_3 != null)
							{
								eventHandler_3(this, EventArgs.Empty);
								return;
							}
							break;
						case 210:
							if (eventHandler_4 != null)
							{
								eventHandler_4(this, EventArgs.Empty);
								return;
							}
							break;
						case 211:
							if (eventHandler_5 != null)
							{
								eventHandler_5(this, EventArgs.Empty);
							}
							break;
						case 212:
						case 213:
						case 214:
						case 215:
						case 216:
						case 217:
						case 218:
						case 219:
						case 220:
						case 228:
							break;
						case 221:
							if (instrumentEventHandler_0 != null)
							{
								instrumentEventHandler_0(this, new InstrumentEventArgs(((OnInstrumentAdded)@event).instrument()));
								return;
							}
							break;
						case 222:
							if (instrumentEventHandler_1 != null)
							{
								instrumentEventHandler_1(this, new InstrumentEventArgs(((OnInstrumentDeleted)@event).instrument()));
								return;
							}
							break;
						case 223:
							if (providerEventHandler_0 != null)
							{
								providerEventHandler_0(this, new ProviderEventArgs(((OnProviderAdded)@event).iprovider()));
								return;
							}
							break;
						case 224:
							if (providerEventHandler_1 != null)
							{
								providerEventHandler_1(this, new ProviderEventArgs(((OnProviderRemoved)@event).provider()));
								return;
							}
							break;
						case 225:
							if (providerEventHandler_3 != null)
							{
								providerEventHandler_3(this, new ProviderEventArgs(((OnProviderConnected)@event).provider()));
								return;
							}
							break;
						case 226:
							if (providerEventHandler_4 != null)
							{
								providerEventHandler_4(this, new ProviderEventArgs(((OnProviderDisconnected)@event).provider()));
								return;
							}
							break;
						case 227:
							if (providerEventHandler_2 != null)
							{
								providerEventHandler_2(this, new ProviderEventArgs(((OnProviderStatusChanged)@event).rboVjhqyRm()));
								return;
							}
							break;
						case 229:
							if (eventHandler_0 != null)
							{
								eventHandler_0(this, EventArgs.Empty);
								return;
							}
							break;
						case 230:
							if (simulatorProgressEventHandler_0 != null)
							{
								simulatorProgressEventHandler_0(this, new SimulatorProgressEventArgs(((OnSimulatorProgress)@event).long_0(), ((OnSimulatorProgress)@event).int_0()));
								return;
							}
							break;
						default:
							return;
					}
					break;
			}
		}
	}
}


// Pubic API 

EventDispatcher::EventDispatcher(const Framework& framework)
	: d_ptr(new EventDispatcherPrivate(framework))
{
}

EventDispatcher::~EventDispatcher()
{
}

EventDispatcher::EventDispatcher (const EventDispatcher &other)
	: d_ptr(other.d_ptr)
{
}

EventDispatcher& EventDispatcher::operator=(const EventDispatcher &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventDispatcher::operator==(const EventDispatcher &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void EventDispatcher::addAccountData(const AccountDataEventHandler& value)
{
	d_ptr->addAccountData(value);
}

void EventDispatcher::addAsk(const AskEventHandler& value)
{
	d_ptr->addAsk(value);
}

void EventDispatcher::addBar(const BarEventHandler& value)
{
	d_ptr->addBar(value);
}

void EventDispatcher::addBid(const BidEventHandler& value)
{
	d_ptr->addBid(value);
}

void EventDispatcher::addEventManagerPaused(const EventHandler& value)
{
	d_ptr->addEventManagerPaused(value);
}

void EventDispatcher::addEventManagerResumed(const EventHandler& value)
{
	d_ptr->addEventManagerResumed(value);
}

void EventDispatcher::addEventManagerStarted(const EventHandler& value)
{
	d_ptr->addEventManagerStarted(value);
}

void EventDispatcher::addEventManagerStep(const EventHandler& value)
{
	d_ptr->addEventManagerStep(value);
}

void EventDispatcher::addEventManagerStopped(const EventHandler& value)
{
	d_ptr->addEventManagerStopped(value);
}

void EventDispatcher::addExecutionCommand(const ExecutionCommandEventHandler& value)
{
	d_ptr->addExecutionCommand(value);
}

void EventDispatcher::addExecutionReport(const ExecutionReportEventHandler& value)
{
	d_ptr->addExecutionReport(value);
}

void EventDispatcher::addFill(const FillEventHandler& value)
{
	d_ptr->addFill(value);
}

void EventDispatcher::addFrameworkCleared(const FrameworkEventHandler& value)
{
	d_ptr->addFrameworkCleared(value);
}

void EventDispatcher::addHistoricalData(const HistoricalDataEventHandler& value)
{
	d_ptr->addHistoricalData(value);
}

void EventDispatcher::addHistoricalDataEnd(const HistoricalDataEndEventHandler& value)
{
	d_ptr->addHistoricalDataEnd(value);
}

void EventDispatcher::addInstrumentAdded(const InstrumentEventHandler& value)
{
	d_ptr->addInstrumentAdded(value);
}

void EventDispatcher::addInstrumentDefinition(const InstrumentDefinitionEventHandler& value)
{
	d_ptr->addInstrumentDefinition(value);
}

void EventDispatcher::addInstrumentDefinitionEnd(const InstrumentDefinitionEndEventHandler& value)
{
	d_ptr->addInstrumentDefinitionEnd(value);
}

void EventDispatcher::addInstrumentDeleted(const InstrumentEventHandler& value)
{
	d_ptr->addInstrumentDeleted(value);
}

void EventDispatcher::addNewGroup(const GroupEventHandler& value)
{
	d_ptr->addNewGroup(value);
}

void EventDispatcher::addNewGroupEvent(const GroupEventEventHandler& value)
{
	d_ptr->addNewGroupEvent(value);
}

void EventDispatcher::addNewGroupUpdate(const GroupUpdateEventHandler& value)
{
	d_ptr->addNewGroupUpdate(value);
}

void EventDispatcher::addOrderManagerCleared(const OrderManagerClearedEventHandler& value)
{
	d_ptr->addOrderManagerCleared(value);
}

void EventDispatcher::addPortfolioAdded(const PortfolioEventHandler& value)
{
	d_ptr->addPortfolioAdded(value);
}

void EventDispatcher::addPortfolioDeleted(const PortfolioEventHandler& value)
{
	d_ptr->addPortfolioDeleted(value);
}

void EventDispatcher::addPortfolioParentChanged(const PortfolioEventHandler& value)
{
	d_ptr->addPortfolioParentChanged(value);
}

void EventDispatcher::addPositionChanged(const PositionEventHandler& value)
{
	d_ptr->addPositionChanged(value);
}

void EventDispatcher::addPositionClosed(const PositionEventHandler& value)
{
	d_ptr->addPositionClosed(value);
}

void EventDispatcher::addPositionOpened(const PositionEventHandler& value)
{
	d_ptr->addPositionOpened(value);
}

void EventDispatcher::addProviderAdded(const ProviderEventHandler& value)
{
	d_ptr->addProviderAdded(value);
}

void EventDispatcher::addProviderConnected(const ProviderEventHandler& value)
{
	d_ptr->addProviderConnected(value);
}

void EventDispatcher::addProviderDisconnected(const ProviderEventHandler& value)
{
	d_ptr->addProviderDisconnected(value);
}

void EventDispatcher::addProviderError(const ProviderErrorEventHandler& value)
{
	d_ptr->addProviderError(value);
}

void EventDispatcher::addProviderRemoved(const ProviderEventHandler& value)
{
	d_ptr->addProviderRemoved(value);
}

void EventDispatcher::addProviderStatusChanged(const ProviderEventHandler& value)
{
	d_ptr->addProviderStatusChanged(value);
}

void EventDispatcher::addSimulatorProgress(const SimulatorProgressEventHandler& value)
{
	d_ptr->addSimulatorProgress(value);
}

void EventDispatcher::addSimulatorStop(const EventHandler& value)
{
	d_ptr->addSimulatorStop(value);
}

void EventDispatcher::addTrade(const TradeEventHandler& value)
{
	d_ptr->addTrade(value);
}

void EventDispatcher::addTransaction(const TransactionEventHandler& value)
{
	d_ptr->addTransaction(value);
}

void EventDispatcher::onEvent(const Event& e)
{
	d_ptr->onEvent(e);
}

void EventDispatcher::removeAccountData(const AccountDataEventHandler& value)
{
	d_ptr->removeAccountData(value);
}

void EventDispatcher::removeAsk(const AskEventHandler& value)
{
	d_ptr->removeAsk(value);
}

void EventDispatcher::removeBar(const BarEventHandler& value)
{
	d_ptr->removeBar(value);
}

void EventDispatcher::removeBid(const BidEventHandler& value)
{
	d_ptr->removeBid(value);
}

void EventDispatcher::removeEventManagerPaused(const EventHandler& value)
{
	d_ptr->removeEventManagerPaused(value);
}

void EventDispatcher::removeEventManagerResumed(const EventHandler& value)
{
	d_ptr->removeEventManagerResumed(value);
}

void EventDispatcher::removeEventManagerStarted(const EventHandler& value)
{
	d_ptr->removeEventManagerStarted(value);
}

void EventDispatcher::removeEventManagerStep(const EventHandler& value)
{
	d_ptr->removeEventManagerStep(value);
}

void EventDispatcher::removeEventManagerStopped(const EventHandler& value)
{
	d_ptr->removeEventManagerStopped(value);
}

void EventDispatcher::removeExecutionCommand(const ExecutionCommandEventHandler& value)
{
	d_ptr->removeExecutionCommand(value);
}

void EventDispatcher::removeExecutionReport(const ExecutionReportEventHandler& value)
{
	d_ptr->removeExecutionReport(value);
}

void EventDispatcher::removeFill(const FillEventHandler& value)
{
	d_ptr->removeFill(value);
}

void EventDispatcher::removeFrameworkCleared(const FrameworkEventHandler& value)
{
	d_ptr->removeFrameworkCleared(value);
}

void EventDispatcher::removeHistoricalData(const HistoricalDataEventHandler& value)
{
	d_ptr->removeHistoricalData(value);
}

void EventDispatcher::removeHistoricalDataEnd(const HistoricalDataEndEventHandler& value)
{
	d_ptr->removeHistoricalDataEnd(value);
}

void EventDispatcher::removeInstrumentAdded(const InstrumentEventHandler& value)
{
	d_ptr->removeInstrumentAdded(value);
}

void EventDispatcher::removeInstrumentDefinition(const InstrumentDefinitionEventHandler& value)
{
	d_ptr->removeInstrumentDefinition(value);
}

void EventDispatcher::removeInstrumentDefinitionEnd(const InstrumentDefinitionEndEventHandler& value)
{
	d_ptr->removeInstrumentDefinitionEnd(value);
}

void EventDispatcher::removeInstrumentDeleted(const InstrumentEventHandler& value)
{
	d_ptr->removeInstrumentDeleted(value);
}

void EventDispatcher::removeNewGroup(const GroupEventHandler& value)
{
	d_ptr->removeNewGroup(value);
}

void EventDispatcher::removeNewGroupEvent(const GroupEventEventHandler& value)
{
	d_ptr->removeNewGroupEvent(value);
}

void EventDispatcher::removeNewGroupUpdate(const GroupUpdateEventHandler& value)
{
	d_ptr->removeNewGroupUpdate(value);
}

void EventDispatcher::removeOrderManagerCleared(const OrderManagerClearedEventHandler& value)
{
	d_ptr->removeOrderManagerCleared(value);
}

void EventDispatcher::removePortfolioAdded(const PortfolioEventHandler& value)
{
	d_ptr->removePortfolioAdded(value);
}

void EventDispatcher::removePortfolioDeleted(const PortfolioEventHandler& value)
{
	d_ptr->removePortfolioDeleted(value);
}

void EventDispatcher::removePortfolioParentChanged(const PortfolioEventHandler& value)
{
	d_ptr->removePortfolioParentChanged(value);
}

void EventDispatcher::removePositionChanged(const PositionEventHandler& value)
{
	d_ptr->removePositionChanged(value);
}

void EventDispatcher::removePositionClosed(const PositionEventHandler& value)
{
	d_ptr->removePositionClosed(value);
}

void EventDispatcher::removePositionOpened(const PositionEventHandler& value)
{
	d_ptr->removePositionOpened(value);
}

void EventDispatcher::removeProviderAdded(const ProviderEventHandler& value)
{
	d_ptr->removeProviderAdded(value);
}

void EventDispatcher::removeProviderConnected(const ProviderEventHandler& value)
{
	d_ptr->removeProviderConnected(value);
}

void EventDispatcher::removeProviderDisconnected(const ProviderEventHandler& value)
{
	d_ptr->removeProviderDisconnected(value);
}

void EventDispatcher::removeProviderError(const ProviderErrorEventHandler& value)
{
	d_ptr->removeProviderError(value);
}

void EventDispatcher::removeProviderRemoved(const ProviderEventHandler& value)
{
	d_ptr->removeProviderRemoved(value);
}

void EventDispatcher::removeProviderStatusChanged(const ProviderEventHandler& value)
{
	d_ptr->removeProviderStatusChanged(value);
}

void EventDispatcher::removeSimulatorProgress(const SimulatorProgressEventHandler& value)
{
	d_ptr->removeSimulatorProgress(value);
}

void EventDispatcher::removeSimulatorStop(const EventHandler& value)
{
	d_ptr->removeSimulatorStop(value);
}

void EventDispatcher::removeTrade(const TradeEventHandler& value)
{
	d_ptr->removeTrade(value);
}

void EventDispatcher::removeTransaction(const TransactionEventHandler& value)
{
	d_ptr->removeTransaction(value);
}

QDebug operator<<(QDebug dbg, const EventDispatcher& eventdispatcher)
{
	return dbg << eventdispatcher.toString();
}

