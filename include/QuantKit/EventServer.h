#ifndef __QUANTKIT_EVENTSERVER_H__
#define __QUANTKIT_EVENTSERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

#include <QuantKit/IProvider.h>

namespace QuantKit {

class EventServerPrivate;

class Framework;
class EventBus;
class Instrument;
class InstrumentDefinition;
class InstrumentDefinitionEnd;
class HistoricalData;
class HistoricalDataEnd;
class Provider;
class ProviderError;
class DataObject;
class ExecutionCommand;
class Event;
class ExecutionReport;
class Order;
class Portfolio;
class Position;
class Fill;
class Transaction;
class EventQueue;

class QUANTKIT_EXPORT EventServer
{
public:
	EventServer(const Framework& framework, const EventBus& bus);
	~EventServer();

	EventServer(const EventServer &other);
	EventServer& operator=(const EventServer &other);
	bool operator==(const EventServer &other) const;
	inline bool operator!=(const EventServer &other) const { return !(this->operator==(other));  }
public:
	void emitQueued();
	void onData(const DataObject& data);
	void onEvent(const Event& e);
	void onHistoricalData(const HistoricalData& data);
	void onHistoricalDataEnd(const HistoricalDataEnd& end);
	void onInstrumentAdded(const Instrument& instrument);
	void onInstrumentDefinition(const InstrumentDefinition& definition);
	void onInstrumentDefintionEnd(const InstrumentDefinitionEnd& end);
	void onInstrumentDeleted(const Instrument& instrument);
	void onLog(const Event& e);
	void onPortfolioAdded(const Portfolio& portfolio);
	void onPortfolioDeleted(const Portfolio& portfolio);
	void onPositionOpened(const Portfolio& portfolio, const Position& position, bool queued = true);
	void onProviderAdded(const IProvider& provider);
	void onProviderConnected(const Provider& provider);
	void onProviderDisconnected(const Provider& provider);
	void onProviderError(const ProviderError& error);
	void onProviderRemoved(const Provider& provider);
	void onProviderStatusChanged(const Provider& provider);

private:
	QSharedDataPointer<EventServerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventServer& eventserver);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventServer& eventserver);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventServer)

#endif // __QUANTKIT_EVENTSERVER_H__
