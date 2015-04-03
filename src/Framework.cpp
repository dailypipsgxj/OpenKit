#include <QuantKit/Framework.h>

#include <QuantKit/Configuration.h>
#include <QuantKit/Clock.h>
#include <QuantKit/EventBus.h>
#include <QuantKit/EventServer.h>
#include <QuantKit/EventManager.h>
#include "InstrumentServer_p.h"
#include <QuantKit/InstrumentManager.h>
#include "DataServer_p.h"
#include <QuantKit/DataManager.h>
#include <QuantKit/ProviderManager.h>
#include <QuantKit/EventLoggerManager.h>
#include <QuantKit/SubscriptionManager.h>
#include "OrderServer_p.h"
#include <QuantKit/OrderManager.h>
#include <QuantKit/PortfolioManager.h>
#include <QuantKit/StrategyManager.h>
#include <QuantKit/StatisticsManager.h>
#include <QuantKit/GroupManager.h>
#include <QuantKit/AccountDataManager.h>
#include <QuantKit/LicenseManager.h>
#include <QuantKit/GroupDispatcher.h>
#include <QuantKit/StreamerManager.h>
#include <QuantKit/DataFileManager.h>
#include <QuantKit/ServerConfiguration.h>

namespace QuantKit {

class FrameworkPrivate : public QSharedData
{
public:
	Framework m_current;
	QString m_name;
	FrameworkMode m_mode;
	bool m_isDisposable;
	bool bool_1;
	bool bool_2;
	bool bool_3;
	bool bool_4;
	bool m_isExternalDataQueue;
	Configuration m_configuration;
	Clock m_clock;
	Clock m_exchangeClock;
	EventBus m_eventBus;
	EventServer m_eventServer;
	EventManager m_eventManager;
	InstrumentServer m_instrumentServer;
	InstrumentManager m_instrumentManager;
	DataServer m_dataServer;
	DataManager m_dataManager;
	ProviderManager m_providerManager;
	EventLoggerManager m_eventLoggerManager;
	SubscriptionManager m_subscriptionManager;
	OrderServer m_orderServer;
	OrderManager m_orderManager;
	PortfolioManager m_portfolioManager;
	StrategyManager m_strategyManager;
	StatisticsManager m_statisticsManager;
	GroupManager m_groupManager;
	GroupDispatcher m_groupDispatcher;
	StreamerManager m_streamerManager;
	DataFileManager m_dataFileManager;
	AccountDataManager m_accountDataManager;
	LicenseManager m_licenseManager;
	ICurrencyConverter m_currencyConverter;

public:
	FrameworkPrivate(const QString& name, FrameworkMode mode, bool createServers)
	{
		method_0(name, mode, createServers);
	}

	FrameworkPrivate(const QString& name, const InstrumentServer& instrumentServer, const DataServer& dataServer);
	FrameworkPrivate(const QString& name, const EventBus& externalBus, const InstrumentServer& instrumentServer, const DataServer& dataServer);
	virtual ~FrameworkPrivate();

public:
	bool isDisposable() const { return m_isDisposable; }
	void setIsDisposable(bool value) { m_isDisposable = true; }
	bool isExternalDataQueue() const { return m_isExternalDataQueue; }
	void setIsExternalDataQueue(bool value) { m_isExternalDataQueue = value; }
	QString name() const { return m_name; }
	Configuration configuration() const { return m_configuration; }
	FrameworkMode mode() const { return m_mode; }
	void setMode(FrameworkMode value);
	Clock clock() const { return m_clock; }
	Clock exchangeClock() const { return m_exchangeClock; }
	EventBus eventBus() const { return m_eventBus; }
	EventServer eventServer() const { return m_eventServer; }
	EventManager eventManager() const { return m_eventManager; }
	InstrumentServer instrumentServer() const { return m_instrumentServer; }
	InstrumentManager instrumentManager() const { return m_instrumentManager; }
	void setInstrumentManager(const InstrumentManager& value) { m_instrumentManager = value; }
	DataServer dataServer() const { return m_dataServer; }
	DataManager dataManager() const { return m_dataManager; }
	void setDataManager(const DataManager& value) { m_dataManager = value; }
	ProviderManager providerManager() const { return m_providerManager; }
	EventLoggerManager eventLoggerManager() const { return m_eventLoggerManager; }
	SubscriptionManager subscriptionManager() const { return m_subscriptionManager; }
	OrderServer orderServer() const { return m_orderServer; }
	OrderManager orderManager() const { return m_orderManager; }
	PortfolioManager portfolioManager() const { return m_portfolioManager; }
	StrategyManager strategyManager() const { return m_strategyManager; }
	StatisticsManager statisticsManager() const { return m_statisticsManager; }
	GroupManager groupManager() const { return m_groupManager; }
	AccountDataManager accountDataManager() const { return m_accountDataManager; }
	LicenseManager licenseManager() const { return m_licenseManager; }
	ICurrencyConverter currencyConverter() const { return m_currencyConverter; }
	void setCurrencyConverter(const ICurrencyConverter& value) { m_currencyConverter = value; }
	GroupDispatcher groupDispatcher() const { return m_groupDispatcher; }
	void setGroupDispatcher(const GroupDispatcher& value) { m_groupDispatcher = value; }
	StreamerManager streamerManager() const { return m_streamerManager; }
	DataFileManager dataFileManager() const { return m_dataFileManager; }
	Framework current() const;
	IExecutionProvider executionProvider() const
	{
		return m_providerManager.GetExecutionProvider(m_configuration.executionProvider());
	}

	IDataProvider dataProvider() const
	{
		return m_providerManager.GetDataProvider(m_configuration.dataProvider());
	}

	void clear();
	void dump();
	void load(const QByteArray& reader);
	void save(const QByteArray& writer);
	virtual FrameworkPrivate* clone() Q_DECL_OVERRIDE { return new FrameworkPrivate(*this); }
//private:
	void aushibGegJ();
	void method_0(const QString& string_1, FrameworkMode frameworkMode_1, bool bool_6);
	void method_1();
	void method_2();
	void method_3();
	T method_4(const ServerConfiguration& serverConfiguration);
	void method_5(bool bool_6);
};

} // namepsace QuantKit


using namespace QuantKit;

FrameworkPrivate::FrameworkPrivate(const QString& name, const InstrumentServer& instrumentServer, const DataServer& dataServer)
	: m_name(name)
	, m_isDisposable(true)
	, bool_1(true)
	, bool_2(true)
	, bool_3(true)
	, m_clock(new Clock(this, ClockType.Local, false))
	, m_exchangeClock(new Clock(this, ClockType.Exchange, false))
	, m_eventBus(new EventBus(this))
	, m_eventServer(new EventServer(this, m_eventBus))
	, m_eventManager(new EventManager(this, m_eventBus))
	, m_instrumentServer(instrumentServer)
	, m_instrumentManager(new InstrumentManager(this, instrumentServer))
	, m_dataServer(dataServer)
	, m_dataManager(new DataManager(this, dataServer))
	, m_providerManager(new ProviderManager(this, null, new ExecutionSimulator(this)))
	, m_eventLoggerManager(new EventLoggerManager())
	, m_subscriptionManager(new SubscriptionManager(this))
	, m_orderManager(new OrderManager(this, null))
	, m_portfolioManager(new PortfolioManager(this))
	, m_strategyManager(new StrategyManager(this))
	, m_statisticsManager(new StatisticsManager(this))
	, m_groupManager(new GroupManager(this))
	, m_streamerManager(new StreamerManager())
	, m_dataFileManager(new DataFileManager(Installation.dataDir().FullName))
	, m_currencyConverter(new CurrencyConverter(this))
{
		aushibGegJ();
		m_eventBus.setIeventQueue_0() = m_clock.ieventQueue_0();
		m_eventBus.setIeventQueue_1() = m_exchangeClock.ieventQueue_0();
		method_1();
		m_instrumentManager.Load();
		method_2();
		if (Framework.current() == null)
		{
			Framework.setCurrent() = this;
		}
}

FrameworkPrivate::FrameworkPrivate(const QString& name, const EventBus& externalBus, const InstrumentServer& instrumentServer, DataServer dataServer)
	: m_name(name)
	, m_isDisposable(true)
	, bool_1(true)
	, bool_1(false)
	, bool_2(true)
	, bool_2(false)
	, bool_3(true)
	, m_isExternalDataQueue(true)
	, m_clock(new Clock(this, ClockType.Local, false))
	, m_exchangeClock(new Clock(this, ClockType.Exchange, false))
	, m_eventBus(new EventBus(this))
	, m_eventServer(new EventServer(this, m_eventBus))
	, m_eventManager(new EventManager(this, m_eventBus))
	, m_instrumentServer(instrumentServer)
	, m_instrumentManager(new InstrumentManager(this, instrumentServer))
	, m_dataServer(dataServer)
	, m_dataManager(new DataManager(this, dataServer))
	, m_providerManager(new ProviderManager(this, null, new ExecutionSimulator(this)))
	, m_eventLoggerManager(new EventLoggerManager())
	, m_subscriptionManager(new SubscriptionManager(this))
	, m_orderManager(new OrderManager(this, null))
	, m_portfolioManager(new PortfolioManager(this))
	, m_strategyManager(new StrategyManager(this))
	, m_statisticsManager(new StatisticsManager(this))
	, m_groupManager(new GroupManager(this))
	, m_streamerManager(new StreamerManager())
	, m_dataFileManager(new DataFileManager(Installation.dataDir().FullName))
	, m_currencyConverter(new CurrencyConverter(this))
{
		aushibGegJ();
		m_eventBus.setIeventQueue_0() = m_clock.ieventQueue_0();
		m_eventBus.setIeventQueue_1() = m_exchangeClock.ieventQueue_0();
		externalBus.Attach(m_eventBus);
		method_1();
		m_instrumentManager.Load();
		method_2();
		if (Framework.current() == null)
		{
			Framework.setCurrent() = this;
		}
}

FrameworkPrivate::~FrameworkPrivate ()
{
}

void FrameworkPrivate::setMode(FrameworkMode value)
{
	if (value != m_mode)
	{
		m_providerManager.DisconnectAll();
		m_mode = value;
		switch (m_mode)
		{
			case FrameworkMode.Simulation:
				m_clock.setMode() = ClockMode.Simulation;
				if (m_eventBus != null)
				{
					m_eventBus.setMode() = EventBusMode.Simulation;
					return;
				}
				break;
			case FrameworkMode.Realtime:
				m_clock.setMode() = ClockMode.Realtime;
				if (m_eventBus != null)
				{
					m_eventBus.setMode() = EventBusMode.Realtime;
				}
				break;
			default:
				return;
		}
	}
}

Framework FrameworkPrivate::current() const
{
	if (Framework.current() == null)
	{
		Framework.setCurrent() = new Framework("", FrameworkMode.Simulation, true);
	}
	return Framework.current();
}

void FrameworkPrivate::clear()
{
	Console.WriteLine(DateTime.Now + " Framework::Clear");
	if (m_clock != null)
	{
		m_clock.Clear();
	}
	if (m_exchangeClock != null)
	{
		m_exchangeClock.Clear();
	}
	if (m_eventBus != null)
	{
		m_eventBus.Clear();
	}
	if (m_eventManager != null)
	{
		m_eventManager.Clear();
	}
	if (m_providerManager != null)
	{
		m_providerManager.DisconnectAll();
		m_providerManager.Clear();
	}
	if (m_instrumentManager != null)
	{
		m_instrumentManager.Clear();
	}
	if (m_dataManager != null)
	{
		m_dataManager.Clear();
	}
	if (m_subscriptionManager != null)
	{
		m_subscriptionManager.Clear();
	}
	if (m_orderManager != null)
	{
		m_orderManager.Clear();
	}
	if (m_portfolioManager != null)
	{
		m_portfolioManager.Clear();
	}
	if (m_strategyManager != null)
	{
		m_strategyManager.Clear();
	}
	if (m_accountDataManager != null)
	{
		m_accountDataManager.method_0();
	}
	if (m_groupManager != null)
	{
		m_groupManager.Clear();
	}
	GC.Collect();
	m_eventServer.method_20(this);
}

void FrameworkPrivate::dump()
{
	Console.WriteLine("Framework " + m_name);
	m_dataManager.Dump();
}

void FrameworkPrivate::load(const QByteArray& reader)
{
	m_name = reader.ReadString();
	m_dataManager.method_12(reader);
	m_subscriptionManager.method_3(reader);
	m_portfolioManager.method_3(reader);
}

void FrameworkPrivate::save(const QByteArray& writer)
{
	writer.Write(m_name);
	m_dataManager.method_11(writer);
	m_subscriptionManager.method_2(writer);
	m_portfolioManager.method_2(writer);
}

void FrameworkPrivate::aushibGegJ()
{
	string text;
	try
	{
		text = File.ReadAllText(Installation.configDir().FullName + "\\configuration.xml");
	}
	catch (Exception)
	{
		text = null;
	}
	if (text != null)
	{
		using (MemoryStream memoryStream = new MemoryStream(Encoding.UTF8.GetBytes(text)))
		{
			XmlSerializer xmlSerializer = new XmlSerializer(typeof(Configuration));
			m_configuration = (Configuration)xmlSerializer.Deserialize(memoryStream);
			if (m_configuration.streamers().Count == 0)
			{
				m_configuration.AddDefaultStreamers();
			}
			if (m_configuration.providers().Count == 0)
			{
				m_configuration.AddDefaultProviders();
			}
			return;
		}
	}
	m_configuration = Configuration.DefaultConfiguaration();
}

void FrameworkPrivate::method_0(const QString& string_1, FrameworkMode frameworkMode_1, bool bool_6)
{
	m_name = string_1;
	m_mode = frameworkMode_1;
	aushibGegJ();
	m_eventBus = new EventBus(this);
	m_clock = new Clock(this, ClockType.Local, false);
	m_eventBus.setIeventQueue_0() = m_clock.ieventQueue_0();
	m_exchangeClock = new Clock(this, ClockType.Exchange, false);
	m_eventBus.setIeventQueue_1() = m_exchangeClock.ieventQueue_0();
	m_eventServer = new EventServer(this, m_eventBus);
	m_eventManager = new EventManager(this, m_eventBus);
	m_streamerManager = new StreamerManager();
	method_1();
	if (bool_6)
	{
		if (m_configuration.isInstrumentFileLocal())
		{
			m_instrumentServer = new FileInstrumentServer(this, m_configuration.instrumentFileName(), null, -1);
		}
		else
		{
			m_instrumentServer = new FileInstrumentServer(this, "instruments.quant", m_configuration.instrumentFileHost(), m_configuration.instrumentFilePort());
		}
		m_instrumentManager = new InstrumentManager(this, m_instrumentServer);
		m_instrumentManager.Load();
		if (m_configuration.isDataFileLocal())
		{
			m_dataServer = new FileDataServer(this, m_configuration.dataFileName(), null, -1);
		}
		else
		{
			m_dataServer = new FileDataServer(this, "data.quant", m_configuration.dataFileHost(), m_configuration.dataFilePort());
		}
		m_dataManager = new DataManager(this, m_dataServer);
		m_orderServer = method_4<OrderServer>(m_configuration.orderServer());
	}
	m_providerManager = new ProviderManager(this, null, new ExecutionSimulator(this));
	method_2();
	m_eventLoggerManager = new EventLoggerManager();
	m_subscriptionManager = new SubscriptionManager(this);
	m_orderManager = new OrderManager(this, null);
	m_orderManager.Load();
	m_portfolioManager = new PortfolioManager(this);
	m_strategyManager = new StrategyManager(this);
	m_statisticsManager = new StatisticsManager(this);
	m_groupManager = new GroupManager(this);
	m_accountDataManager = new AccountDataManager(this);
	m_licenseManager = new LicenseManager();
	m_currencyConverter = new CurrencyConverter(this);
	m_dataFileManager = new DataFileManager(Installation.dataDir().FullName);
	if (Framework.current() == null)
	{
		Framework.setCurrent() = this;
	}
}

void FrameworkPrivate::method_1()
{
	foreach (StreamerPlugin current in m_configuration.streamers())
	{
		Type type = Type.GetType(current.typeName());
		if (type == null)
		{
			Console.WriteLine("Can not create streamer type " + current.typeName());
		}
		else
		{
			ObjectStreamer objectStreamer = (ObjectStreamer)Activator.CreateInstance(type);
			if (objectStreamer == null)
			{
				Console.WriteLine("Can not create streamer object " + current.typeName());
			}
			else
			{
				m_streamerManager.Add(objectStreamer);
			}
		}
	}
}

void FrameworkPrivate::method_2()
{
	foreach (ProviderPlugin current in m_configuration.providers())
	{
		Type type = Type.GetType(current.typeName());
		if (type == null)
		{
			Console.WriteLine("Can not create provider type " + current.typeName());
		}
		else
		{
			Provider provider = (Provider)Activator.CreateInstance(type, new object[]
			{
				this
			});
			if (provider == null)
			{
				Console.WriteLine("Can not create provider object " + current.typeName());
			}
			else
			{
				m_providerManager.AddProvider(provider);
			}
		}
	}
}

void FrameworkPrivate::method_3()
{
	XmlSerializer xmlSerializer = new XmlSerializer(typeof(Configuration));
	StreamWriter streamWriter = new StreamWriter(Installation.configDir().FullName + "\\configuration.xml");
	xmlSerializer.Serialize(streamWriter, m_configuration);
	streamWriter.Close();
}

T FrameworkPrivate::method_4(const ServerConfiguration& serverConfiguration)
{
	Type type = Type.GetType(serverConfiguration.typeName());
	if (type == null)
	{
		return default(T);
	}
	object obj = Activator.CreateInstance(type);
	if (!(obj is T))
	{
		return default(T);
	}
	T result = (T)((object)obj);
	result.setFramework() = this;
	result.setConnectionString() = serverConfiguration.connectionString();
	return result;
}

void FrameworkPrivate::method_5(bool bool_6)
{
	if (!bool_4)
	{
		if (bool_6)
		{
			method_3();
			if (m_instrumentServer != null && bool_1)
			{
				m_instrumentServer.Dispose();
			}
			if (m_dataServer != null && bool_2)
			{
				m_dataServer.Dispose();
			}
			if (m_orderServer != null && bool_3)
			{
				m_orderServer.Dispose();
			}
			if (m_providerManager != null)
			{
				m_providerManager.Dispose();
			}
			if (m_dataManager != null)
			{
				m_dataManager.Dispose();
			}
			if (m_eventManager != null)
			{
				m_eventManager.Dispose();
			}
		}
		bool_4 = true;
	}
}


// Pubic API 

Framework::Framework(const QString& name, FrameworkMode mode, bool createServers)
	: d_ptr(new FrameworkPrivate(name, mode, createServers))
{
}

Framework::Framework(const QString& name, const InstrumentServer& instrumentServer, const DataServer& dataServer)
	: d_ptr(new FrameworkPrivate(name, instrumentServer, dataServer))
{
}

Framework::Framework(const QString& name, const EventBus& externalBus, const InstrumentServer& instrumentServer, DataServer dataServer)
	: d_ptr(new FrameworkPrivate(name, externalBus, instrumentServer, dataServer))
{
}

Framework::~Framework()
{
}

Framework::Framework (const Framework &other)
	: d_ptr(other.d_ptr)
{
}

Framework& Framework::operator=(const Framework &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Framework::operator==(const Framework &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

bool Framework::isDisposable() const
{
	return d_ptr->isDisposable();
}

void Framework::setIsDisposable(bool value)
{
	d_ptr->setIsDisposable(value);
}

bool Framework::isExternalDataQueue() const
{
	return d_ptr->isExternalDataQueue();
}

void Framework::setIsExternalDataQueue(bool value)
{
	d_ptr->setIsExternalDataQueue(value);
}

QString Framework::name() const
{
	return d_ptr->name();
}

Configuration Framework::configuration() const
{
	return d_ptr->configuration();
}

FrameworkMode Framework::mode() const
{
	return d_ptr->mode();
}

void Framework::setMode(FrameworkMode value)
{
	d_ptr->setMode(value);
}

Clock Framework::clock() const
{
	return d_ptr->clock();
}

Clock Framework::exchangeClock() const
{
	return d_ptr->exchangeClock();
}

EventBus Framework::eventBus() const
{
	return d_ptr->eventBus();
}

EventServer Framework::eventServer() const
{
	return d_ptr->eventServer();
}

EventManager Framework::eventManager() const
{
	return d_ptr->eventManager();
}

InstrumentServer Framework::instrumentServer() const
{
	return d_ptr->instrumentServer();
}

InstrumentManager Framework::instrumentManager() const
{
	return d_ptr->instrumentManager();
}

void Framework::setInstrumentManager(const InstrumentManager& value)
{
	d_ptr->setInstrumentManager(value);
}

DataServer Framework::dataServer() const
{
	return d_ptr->dataServer();
}

DataManager Framework::dataManager() const
{
	return d_ptr->dataManager();
}

void Framework::setDataManager(const DataManager& value)
{
	d_ptr->setDataManager(value);
}

ProviderManager Framework::providerManager() const
{
	return d_ptr->providerManager();
}

EventLoggerManager Framework::eventLoggerManager() const
{
	return d_ptr->eventLoggerManager();
}

SubscriptionManager Framework::subscriptionManager() const
{
	return d_ptr->subscriptionManager();
}

OrderServer Framework::orderServer() const
{
	return d_ptr->orderServer();
}

OrderManager Framework::orderManager() const
{
	return d_ptr->orderManager();
}

PortfolioManager Framework::portfolioManager() const
{
	return d_ptr->portfolioManager();
}

StrategyManager Framework::strategyManager() const
{
	return d_ptr->strategyManager();
}

StatisticsManager Framework::statisticsManager() const
{
	return d_ptr->statisticsManager();
}

GroupManager Framework::groupManager() const
{
	return d_ptr->groupManager();
}

AccountDataManager Framework::accountDataManager() const
{
	return d_ptr->accountDataManager();
}

LicenseManager Framework::licenseManager() const
{
	return d_ptr->licenseManager();
}

ICurrencyConverter Framework::currencyConverter() const
{
	return d_ptr->currencyConverter();
}

void Framework::setCurrencyConverter(const ICurrencyConverter& value)
{
	d_ptr->setCurrencyConverter(value);
}

GroupDispatcher Framework::groupDispatcher() const
{
	return d_ptr->groupDispatcher();
}

void Framework::setGroupDispatcher(const GroupDispatcher& value)
{
	d_ptr->setGroupDispatcher(value);
}

StreamerManager Framework::streamerManager() const
{
	return d_ptr->streamerManager();
}

DataFileManager Framework::dataFileManager() const
{
	return d_ptr->dataFileManager();
}

Framework Framework::current() const
{
	return d_ptr->current();
}

IExecutionProvider Framework::executionProvider() const
{
	return d_ptr->executionProvider();
}

IDataProvider Framework::dataProvider() const
{
	return d_ptr->dataProvider();
}

void Framework::clear()
{
	d_ptr->clear();
}

void Framework::dump()
{
	d_ptr->dump();
}

void Framework::load(const QByteArray& reader)
{
	d_ptr->load(reader);
}

void Framework::save(const QByteArray& writer)
{
	d_ptr->save(writer);
}

QDebug operator<<(QDebug dbg, const Framework& framework)
{
	return dbg << framework.toString();
}

