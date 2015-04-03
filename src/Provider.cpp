#include <QuantKit/Provider.h>

#include <QuantKit/Framework.h>
#include "Event_p.h"
#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentList.h>
#include <QuantKit/Event/ExecutionCommand.h>
#include <QuantKit/HistoricalDataRequest.h>
#include <QuantKit/InstrumentDefinitionRequest.h>
#include <QuantKit/Event/ProviderError.h>
#include "DataObject_p.h"
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/AccountData.h>
#include <QuantKit/Event/HistoricalData.h>
#include <QuantKit/Event/HistoricalDataEnd.h>
#include <QuantKit/InstrumentDefinition.h>
#include <QuantKit/InstrumentDefinitionEnd.h>
#include <QuantKit/ProviderPropertyList.h>
#include <QuantKit/EventQueue.h>
#include "Provider_p.h"

using namespace QuantKit;

ProviderPrivate::ProviderPrivate(const Framework& framework)
	: framework(framework)
	, m_isDisconnected(ProviderStatus.Disconnected)
	, m_isDisconnected(ProviderStatus.Disconnected)
{
}

ProviderPrivate::~ProviderPrivate ()
{
}

Framework getFramework() const
{
	return null;
}
bool ProviderPrivate::connect(int timeout)
{
	long ticks = DateTime.Now.Ticks;
	Connect();
	while (!m_isDisconnected)
	{
		Thread.Sleep(1);
		double totalMilliseconds = TimeSpan.FromTicks(DateTime.Now.Ticks - ticks).TotalMilliseconds;
		if (totalMilliseconds >= (double)timeout)
		{
			Console.WriteLine("Provider::Connect timed out : " + m_name);
			return false;
		}
	}
	return true;
}

void ProviderPrivate::dispose()
{
	Dispose(true);
	GC.SuppressFinalize(this);
}

void ProviderPrivate::process(const Event& e)
{
	switch (e.typeId())
	{
		case 201:
			Connect();
			return;
		case 202:
			Disconnect();
			return;
		case 203:
			Subscribe(((OnSubscribe)e).instrument());
			return;
		case 204:
			Unsubscribe(((OnUnsubscribe)e).instrument());
			return;
		default:
			return;
	}
}

void ProviderPrivate::requestHistoricalData(const HistoricalDataRequest& request)
{
}

void ProviderPrivate::requestInstrumentDefinitions(const InstrumentDefinitionRequest& request)
{
}

void ProviderPrivate::send(const HistoricalDataRequest& request)
{
}

void ProviderPrivate::send(const InstrumentDefinitionRequest& request)
{
}

void ProviderPrivate::subscribe(const Instrument& instrument)
{
}

void ProviderPrivate::subscribe(const InstrumentList& instruments)
{
	foreach (Instrument current in instruments)
	{
		Subscribe(current);
	}
}

void ProviderPrivate::unsubscribe(const Instrument& instrument)
{
}

void ProviderPrivate::unsubscribe(const InstrumentList& instruments)
{
	foreach (Instrument current in instruments)
	{
		Unsubscribe(current);
	}
}

//protected
void ProviderPrivate::setStatus(ProviderStatus value)
{
	if (m_isDisconnected != value)
	{
		m_isDisconnected = value;
		if (m_isDisconnected == ProviderStatus.Connected)
		{
			OnConnected();
		}
		if (m_isDisconnected == ProviderStatus.Disconnected)
		{
			OnDisconnected();
		}
		framework.eventServer().OnProviderStatusChanged(this);
	}
}

void ProviderPrivate::dispose(bool disposing)
{
}

void ProviderPrivate::emitAccountData(const AccountData& data)
{
	if (m_executionQueue == null)
	{
		framework.accountDataManager().method_1(data);
		return;
	}
	m_executionQueue.Enqueue(data);
}

void ProviderPrivate::emitData(const DataObject& data, bool queued)
{
	if (queued)
	{
		m_dataQueue.Enqueue(data);
		return;
	}
	framework.eventServer().OnData(data);
}

void ProviderPrivate::emitExecutionReport(const ExecutionReport& report, bool queued)
{
	if (queued)
	{
		m_executionQueue.Enqueue(report);
		return;
	}
	framework.eventServer().method_2(report);
}

void ProviderPrivate::emitHistoricalData(const HistoricalData& data)
{
	method_0();
	m_historicalQueue.Enqueue(data);
}

void ProviderPrivate::emitHistoricalDataEnd(const HistoricalDataEnd& end)
{
	method_0();
	m_historicalQueue.Enqueue(end);
	method_1();
}

void ProviderPrivate::emitHistoricalDataEnd(const QString& requestId, RequestResult result, const QString& text)
{
	EmitHistoricalDataEnd(new HistoricalDataEnd
	{
		RequestId = requestId,
		Result = result,
		Text = text
	});
}

void ProviderPrivate::emitInstrumentDefinition(const InstrumentDefinition& definition)
{
	method_2();
	m_instrumentQueue.Enqueue(new OnInstrumentDefinition(definition));
}

void ProviderPrivate::emitInstrumentDefinitionEnd(const InstrumentDefinitionEnd& end)
{
	method_2();
	m_instrumentQueue.Enqueue(new OnInstrumentDefinitionEnd(end));
	method_3();
}

void ProviderPrivate::emitInstrumentDefinitionEnd(const QString& requestId, RequestResult result, const QString& text)
{
	EmitInstrumentDefinitionEnd(new InstrumentDefinitionEnd
	{
		RequestId = requestId,
		Result = result,
		Text = text
	});
}

ProviderPropertyList ProviderPrivate::getProperties()
{
	ProviderPropertyList providerPropertyList = new ProviderPropertyList();
	PropertyInfo[] properties = base.GetType().GetProperties();
	for (int i = 0; i < properties.Length; i++)
	{
		PropertyInfo propertyInfo = properties[i];
		if (propertyInfo.CanRead && propertyInfo.CanWrite && !(propertyInfo.DeclaringType == typeof(Provider)))
		{
			TypeConverter converter = TypeDescriptor.GetConverter(propertyInfo.PropertyType);
			if (converter != null && converter.CanConvertTo(typeof(string)) && converter.CanConvertFrom(typeof(string)))
			{
				object value = propertyInfo.GetValue(this, null);
				providerPropertyList.SetValue(propertyInfo.Name, converter.ConvertToInvariantString(value));
			}
		}
	}
	return providerPropertyList;
}

void ProviderPrivate::onConnected()
{
	if (this is IDataProvider || this is INewsProvider)
	{
		m_dataQueue = new EventQueue(1, 0, 2, 25000, framework.eventBus());
		m_dataQueue.Enqueue(new OnQueueOpened(m_dataQueue));
		m_dataQueue.setName() = m_name + " data queue";
		framework.eventBus().dataPipe().Add(m_dataQueue);
	}
	if (this is IExecutionProvider)
	{
		m_executionQueue = new EventQueue(2, 0, 2, 25000, framework.eventBus());
		m_executionQueue.Enqueue(new OnQueueOpened(m_executionQueue));
		m_executionQueue.setName() = m_name + " execution queue";
		framework.eventBus().executionPipe().Add(m_executionQueue);
	}
}

void ProviderPrivate::onDisconnected()
{
	if (this is IDataProvider && m_dataQueue != null)
	{
		m_dataQueue.Enqueue(new OnQueueClosed(m_dataQueue));
		m_dataQueue = null;
	}
	if (this is IExecutionProvider && m_executionQueue != null)
	{
		m_executionQueue.Enqueue(new OnQueueClosed(m_executionQueue));
		m_executionQueue = null;
	}
}

void ProviderPrivate::setProperties(const ProviderPropertyList& properties)
{
	PropertyInfo[] properties2 = base.GetType().GetProperties();
	for (int i = 0; i < properties2.Length; i++)
	{
		PropertyInfo propertyInfo = properties2[i];
		if (propertyInfo.CanRead && propertyInfo.CanWrite)
		{
			TypeConverter converter = TypeDescriptor.GetConverter(propertyInfo.PropertyType);
			if (converter != null && converter.CanConvertFrom(typeof(string)))
			{
				string stringValue = properties.GetStringValue(propertyInfo.Name, null);
				if (stringValue != null && converter.IsValid(stringValue))
				{
					propertyInfo.SetValue(this, converter.ConvertFromInvariantString(stringValue), null);
				}
			}
		}
	}
}

void ProviderPrivate::method_0()
{
	if (m_historicalQueue == null)
	{
		m_historicalQueue = new EventQueue(0, 0, 2, 1000, framework.eventBus());
		m_historicalQueue.setName() = m_name + " historical queue";
		m_historicalQueue.Enqueue(new OnQueueOpened(m_historicalQueue));
		framework.eventBus().historicalPipe().Add(m_historicalQueue);
	}
}

void ProviderPrivate::method_1()
{
	if (m_historicalQueue != null)
	{
		m_historicalQueue.Enqueue(new OnQueueClosed(m_historicalQueue));
		m_historicalQueue = null;
	}
}

void ProviderPrivate::method_2()
{
	if (m_instrumentQueue == null)
	{
		m_instrumentQueue = new EventQueue(0, 0, 2, 1000, framework.eventBus());
		m_instrumentQueue.setName() = m_name + " instrument queue";
		m_instrumentQueue.Enqueue(new OnQueueOpened(m_instrumentQueue));
		framework.eventBus().servicePipe().Add(m_instrumentQueue);
	}
}

void ProviderPrivate::method_3()
{
	if (m_instrumentQueue != null)
	{
		m_instrumentQueue.Enqueue(new OnQueueClosed(m_instrumentQueue));
		m_instrumentQueue = null;
	}
}


// Pubic API 

Provider::Provider(const Framework& framework)
	: d_ptr(new ProviderPrivate(framework))
{
}

Provider::~Provider()
{
}

Provider::Provider (ProviderPrivate &dd)
	: d_ptr(&dd)
{
}

Provider::Provider (const Provider &other)
	: d_ptr(other.d_ptr)
{
}

Provider& Provider::operator=(const Provider &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Provider::operator==(const Provider &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Framework framework() const
{
	return d_ptr->
	setFramework()
}

unsigned char Provider::id() const
{
	return d_ptr->id();
}

QString Provider::name() const
{
	return d_ptr->name();
}

QString Provider::description() const
{
	return d_ptr->description();
}

QString Provider::url() const
{
	return d_ptr->url();
}

ProviderStatus Provider::status() const
{
	return d_ptr->status();
}

bool Provider::isConnected() const
{
	return d_ptr->isConnected();
}

bool Provider::isDisconnected() const
{
	return d_ptr->isDisconnected();
}

void Provider::connect()
{
	d_ptr->connect();
}

bool Provider::connect(int timeout)
{
	return d_ptr->connect(timeout);
}

void Provider::disconnect()
{
	d_ptr->disconnect();
}

void Provider::dispose()
{
	d_ptr->dispose();
}

void Provider::process(const Event& e)
{
	d_ptr->process(e);
}

void Provider::requestHistoricalData(const HistoricalDataRequest& request)
{
	d_ptr->requestHistoricalData(request);
}

void Provider::requestInstrumentDefinitions(const InstrumentDefinitionRequest& request)
{
	d_ptr->requestInstrumentDefinitions(request);
}

void Provider::send(const ExecutionCommand& command)
{
	d_ptr->send(command);
}

void Provider::send(const HistoricalDataRequest& request)
{
	d_ptr->send(request);
}

void Provider::send(const InstrumentDefinitionRequest& request)
{
	d_ptr->send(request);
}

void Provider::subscribe(const Instrument& instrument)
{
	d_ptr->subscribe(instrument);
}

void Provider::subscribe(const InstrumentList& instruments)
{
	d_ptr->subscribe(instruments);
}

QString Provider::toString() const
{
	return d_ptr->toString();
}

void Provider::unsubscribe(const Instrument& instrument)
{
	d_ptr->unsubscribe(instrument);
}

void Provider::unsubscribe(const InstrumentList& instruments)
{
	d_ptr->unsubscribe(instruments);
}

QDebug operator<<(QDebug dbg, const Provider& provider)
{
	return dbg << provider.toString();
}

