#include <QuantKit/EventServer.h>

#include <QuantKit/Framework.h>
#include <QuantKit/EventBus.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentDefinition.h>
#include <QuantKit/InstrumentDefinitionEnd.h>
#include <QuantKit/Event/HistoricalData.h>
#include <QuantKit/Event/HistoricalDataEnd.h>
#include "Provider_p.h"
#include <QuantKit/Event/ProviderError.h>
#include "DataObject_p.h"
#include <QuantKit/Event/ExecutionCommand.h>
#include "Event_p.h"
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/Order.h>
#include <QuantKit/Portfolio.h>
#include <QuantKit/Position.h>
#include <QuantKit/Event/Fill.h>
#include <QuantKit/Transaction.h>
#include <QuantKit/EventQueue.h>

namespace QuantKit {

class EventServerPrivate : public QSharedData
{
public:
	Framework m_framework;
	EventQueue eventQueue_0;
	EventBus eventBus_0;

public:
	EventServerPrivate(const Framework& framework, const EventBus& bus);
	virtual ~EventServerPrivate();

public:
	void emitQueued();
	void onData(const DataObject& data) { OnEvent(data); }
	void onEvent(const Event& e)
	{
		m_framework.eventManager().OnEvent(e);
	}

	void onHistoricalData(const HistoricalData& data)
	{
		OnEvent(new OnHistoricalData(data));
	}

	void onHistoricalDataEnd(const HistoricalDataEnd& end)
	{
		OnEvent(new OnHistoricalDataEnd(end));
	}

	void onInstrumentAdded(const Instrument& instrument)
	{
		OnEvent(new OnInstrumentAdded(instrument));
	}

	void onInstrumentDefinition(const InstrumentDefinition& definition)
	{
		OnEvent(new OnInstrumentDefinition(definition));
	}

	void onInstrumentDefintionEnd(const InstrumentDefinitionEnd& end)
	{
		OnEvent(new OnInstrumentDefinitionEnd(end));
	}

	void onInstrumentDeleted(const Instrument& instrument)
	{
		OnEvent(new OnInstrumentDeleted(instrument));
	}

	void onLog(const Event& e) { OnEvent(e); }
	void onPortfolioAdded(const Portfolio& portfolio)
	{
		OnEvent(new OnPortfolioAdded(portfolio));
	}

	void onPortfolioDeleted(const Portfolio& portfolio)
	{
		OnEvent(new OnPortfolioDeleted(portfolio));
	}

	void onPositionOpened(const Portfolio& portfolio, const Position& position, bool queued);
	void onProviderAdded(const IProvider& provider)
	{
		OnEvent(new OnProviderAdded(provider));
	}

	void onProviderConnected(const Provider& provider)
	{
		OnEvent(new OnProviderConnected(m_framework.clock().dateTime(), provider));
	}

	void onProviderDisconnected(const Provider& provider)
	{
		OnEvent(new OnProviderDisconnected(m_framework.clock().dateTime(), provider));
	}

	void onProviderError(const ProviderError& error)
	{
		m_framework.eventManager().OnEvent(error);
	}

	void onProviderRemoved(const Provider& provider)
	{
		OnEvent(new OnProviderRemoved(provider));
	}

	void onProviderStatusChanged(const Provider& provider);
	virtual EventServerPrivate* clone() Q_DECL_OVERRIDE { return new EventServerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

EventServerPrivate::EventServerPrivate(const Framework& framework, const EventBus& bus)
	: m_framework(framework)
	, eventQueue_0(new EventQueue(0, 0, 2, 10000, null))
	, eventBus_0(bus)
{
}

EventServerPrivate::~EventServerPrivate ()
{
}

void EventServerPrivate::emitQueued()
{
	while (!eventQueue_0.IsEmpty())
	{
		OnEvent(eventQueue_0.Read());
	}
}

void EventServerPrivate::onPositionOpened(const Portfolio& portfolio, const Position& position, bool queued)
{
	if (queued)
	{
		eventQueue_0.Enqueue(new OnPositionOpened(portfolio, position));
		return;
	}
	OnEvent(new OnPositionOpened(portfolio, position));
}

void EventServerPrivate::onProviderStatusChanged(const Provider& provider)
{
	switch (provider.status())
	{
		case ProviderStatus.Connected:
			OnProviderConnected(provider);
			break;
		case ProviderStatus.Disconnected:
			OnProviderDisconnected(provider);
			break;
	}
	OnEvent(new OnProviderStatusChanged(provider));
}


// Pubic API 

EventServer::EventServer(const Framework& framework, const EventBus& bus)
	: d_ptr(new EventServerPrivate(framework, bus))
{
}

EventServer::~EventServer()
{
}

EventServer::EventServer (const EventServer &other)
	: d_ptr(other.d_ptr)
{
}

EventServer& EventServer::operator=(const EventServer &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool EventServer::operator==(const EventServer &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void EventServer::emitQueued()
{
	d_ptr->emitQueued();
}

void EventServer::onData(const DataObject& data)
{
	d_ptr->onData(data);
}

void EventServer::onEvent(const Event& e)
{
	d_ptr->onEvent(e);
}

void EventServer::onHistoricalData(const HistoricalData& data)
{
	d_ptr->onHistoricalData(data);
}

void EventServer::onHistoricalDataEnd(const HistoricalDataEnd& end)
{
	d_ptr->onHistoricalDataEnd(end);
}

void EventServer::onInstrumentAdded(const Instrument& instrument)
{
	d_ptr->onInstrumentAdded(instrument);
}

void EventServer::onInstrumentDefinition(const InstrumentDefinition& definition)
{
	d_ptr->onInstrumentDefinition(definition);
}

void EventServer::onInstrumentDefintionEnd(const InstrumentDefinitionEnd& end)
{
	d_ptr->onInstrumentDefintionEnd(end);
}

void EventServer::onInstrumentDeleted(const Instrument& instrument)
{
	d_ptr->onInstrumentDeleted(instrument);
}

void EventServer::onLog(const Event& e)
{
	d_ptr->onLog(e);
}

void EventServer::onPortfolioAdded(const Portfolio& portfolio)
{
	d_ptr->onPortfolioAdded(portfolio);
}

void EventServer::onPortfolioDeleted(const Portfolio& portfolio)
{
	d_ptr->onPortfolioDeleted(portfolio);
}

void EventServer::onPositionOpened(const Portfolio& portfolio, const Position& position, bool queued)
{
	d_ptr->onPositionOpened(portfolio, position, queued);
}

void EventServer::onProviderAdded(const IProvider& provider)
{
	d_ptr->onProviderAdded(provider);
}

void EventServer::onProviderConnected(const Provider& provider)
{
	d_ptr->onProviderConnected(provider);
}

void EventServer::onProviderDisconnected(const Provider& provider)
{
	d_ptr->onProviderDisconnected(provider);
}

void EventServer::onProviderError(const ProviderError& error)
{
	d_ptr->onProviderError(error);
}

void EventServer::onProviderRemoved(const Provider& provider)
{
	d_ptr->onProviderRemoved(provider);
}

void EventServer::onProviderStatusChanged(const Provider& provider)
{
	d_ptr->onProviderStatusChanged(provider);
}

QDebug operator<<(QDebug dbg, const EventServer& eventserver)
{
	return dbg << eventserver.toString();
}

