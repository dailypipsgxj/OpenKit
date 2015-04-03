#ifndef __QUANTKIT_EVENTDISPATCHER_H__
#define __QUANTKIT_EVENTDISPATCHER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <Thread>
#include <QSharedDataPointer>

namespace QuantKit {

class EventDispatcherPrivate;

class FrameworkEventHandler;
class InstrumentEventHandler;
class InstrumentDefinitionEventHandler;
class InstrumentDefinitionEndEventHandler;
class ProviderEventHandler;
class ExecutionCommandEventHandler;
class ExecutionReportEventHandler;
class OrderManagerClearedEventHandler;
class FillEventHandler;
class TransactionEventHandler;
class BarEventHandler;
class BidEventHandler;
class AskEventHandler;
class TradeEventHandler;
class ProviderErrorEventHandler;
class HistoricalDataEventHandler;
class HistoricalDataEndEventHandler;
class PortfolioEventHandler;
class PositionEventHandler;
class GroupEventHandler;
class GroupEventEventHandler;
class GroupUpdateEventHandler;
class SimulatorProgressEventHandler;
class AccountDataEventHandler;
class Framework;
class Event;
class EventQueue;

class QUANTKIT_EXPORT EventDispatcher
{
public:
	explicit EventDispatcher(const Framework& framework);
	~EventDispatcher();

	EventDispatcher(const EventDispatcher &other);
	EventDispatcher& operator=(const EventDispatcher &other);
	bool operator==(const EventDispatcher &other) const;
	inline bool operator!=(const EventDispatcher &other) const { return !(this->operator==(other));  }
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

private:
	QSharedDataPointer<EventDispatcherPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventDispatcher& eventdispatcher);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventDispatcher& eventdispatcher);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventDispatcher)

#endif // __QUANTKIT_EVENTDISPATCHER_H__
