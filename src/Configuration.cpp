#include <QuantKit/Configuration.h>

#include <QuantKit/ServerConfiguration.h>
#include <QuantKit/StreamerPlugin.h>
#include <QuantKit/ProviderPlugin.h>

namespace QuantKit {

class ConfigurationPrivate : public QSharedData
{
public:
	bool IsInstrumentFileLocal;
	QString InstrumentFileHost;
	int InstrumentFilePort;
	QString InstrumentFileName;
	bool IsDataFileLocal;
	QString DataFileHost;
	int DataFilePort;
	QString DataFileName;
	ServerConfiguration OrderServer;
	QString DefaultCurrency;
	QString DefaultExchange;
	QString m_dataProvider;
	QString m_executionProvider;
	QString ProviderManagerFileName;
	QList<StreamerPlugin> Streamers;
	QList<ProviderPlugin> Providers;
	QString QuantControllerHost;
	int QuantControllerPort;
	QString QuantControllerUsername;
	QString QuantControllerPassword;
	int QuantControllerUpdateStatusInterval;
	bool QuantControllerAutoConnect;

public:
	ConfigurationPrivate();
	virtual ~ConfigurationPrivate();

public:
	bool getIsInstrumentFileLocal() const;

	QString getInstrumentFileHost() const;

	int getInstrumentFilePort() const;

	QString getInstrumentFileName() const;

	bool getIsDataFileLocal() const;

	QString getDataFileHost() const;

	int getDataFilePort() const;

	QString getDataFileName() const;

	ServerConfiguration getOrderServer() const;

	QString getProviderManagerFileName() const;

	QList<StreamerPlugin> getStreamers() const;

	QList<ProviderPlugin> getProviders() const;

	QString getQuantControllerHost() const;

	int getQuantControllerPort() const;

	QString getQuantControllerUsername() const;

	QString getQuantControllerPassword() const;

	int getQuantControllerUpdateStatusInterval() const;

	bool getQuantControllerAutoConnect() const;
	void addDefaultProviders();
	void addDefaultStreamers();
	Configuration defaultConfiguaration();
	virtual ConfigurationPrivate* clone() Q_DECL_OVERRIDE { return new ConfigurationPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ConfigurationPrivate::ConfigurationPrivate()
{
}

ConfigurationPrivate::~ConfigurationPrivate ()
{
}

bool getIsInstrumentFileLocal() const
{
	return false;
}

QString getInstrumentFileHost() const
{
	return null;
}

int getInstrumentFilePort() const
{
	return 0;
}

QString getInstrumentFileName() const
{
	return null;
}

bool getIsDataFileLocal() const
{
	return false;
}

QString getDataFileHost() const
{
	return null;
}

int getDataFilePort() const
{
	return 0;
}

QString getDataFileName() const
{
	return null;
}

ServerConfiguration getOrderServer() const
{
	return null;
}

QString getProviderManagerFileName() const
{
	return null;
}

QList<StreamerPlugin> getStreamers() const
{
	return null;
}

QList<ProviderPlugin> getProviders() const
{
	return null;
}

QString getQuantControllerHost() const
{
	return null;
}

int getQuantControllerPort() const
{
	return 0;
}

QString getQuantControllerUsername() const
{
	return null;
}

QString getQuantControllerPassword() const
{
	return null;
}

int getQuantControllerUpdateStatusInterval() const
{
	return 0;
}

bool getQuantControllerAutoConnect() const
{
	return false;
}
void ConfigurationPrivate::addDefaultProviders()
{
	Providers.Add(new ProviderPlugin("SmartQuant.QR.QuantRouter, SmartQuant.QR", true));
	Providers.Add(new ProviderPlugin("SmartQuant.QR2014.QuantRouter2014, SmartQuant.QR2014", true));
	Providers.Add(new ProviderPlugin("SmartQuant.QB.QuantBase, SmartQuant.QB", true));
	Providers.Add(new ProviderPlugin("SmartQuant.IB.IBTWS, SmartQuant.IB", true));
	Providers.Add(new ProviderPlugin("SmartQuant.TT.TTFIX, SmartQuant.TT", true));
	Providers.Add(new ProviderPlugin("SmartQuant.OEC.OpenECry, SmartQuant.OEC", true));
	Providers.Add(new ProviderPlugin("SmartQuant.IQ.IQFeed, SmartQuant.IQ", true));
	Providers.Add(new ProviderPlugin("SmartQuant.MNI.MNIProvider, SmartQuant.MNI", true));
}

void ConfigurationPrivate::addDefaultStreamers()
{
	Streamers.Add(new StreamerPlugin("SmartQuant.DataObjectStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.InstrumentStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.AltIdStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.LegStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.BidStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.AskStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.QuoteStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.TradeStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.BarStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.Level2SnapshotStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.NewsStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.FundamentalStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.DataSeriesStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.ExecutionCommandStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.ExecutionReportStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.PositionStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.PortfolioStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.ObjectTableStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.DoubleStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.Int16Streamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.Int32Streamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.Int64Streamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.StringStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.TimeSeriesItemStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.OnProviderConnectedStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.OnProviderDisconnectedStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.ProviderErrorStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.OnLoginStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.OnLoggedInStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.OnHeartbeatStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.OnSubscribeStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
	Streamers.Add(new StreamerPlugin("SmartQuant.OnUnsubscribeStreamer, SmartQuant, Version=1.2.0.0, Culture=neutral, PublicKeyToken=023ca4f8a69375d5"));
}

Configuration ConfigurationPrivate::defaultConfiguaration()
{
	Configuration configuration = new Configuration();
	configuration.setIsInstrumentFileLocal() = true;
	configuration.setInstrumentFileHost() = "127.0.0.1";
	configuration.setInstrumentFilePort() = 1000;
	configuration.setInstrumentFileName() = Installation.dataDir().FullName + "\\instruments.quant";
	configuration.setIsDataFileLocal() = true;
	configuration.setDataFileHost() = "127.0.0.1";
	configuration.setDataFilePort() = 1000;
	configuration.setDataFileName() = Installation.dataDir().FullName + "\\data.quant";
	configuration.setOrderServer() = new ServerConfiguration();
	configuration.orderServer().setTypeName() = "SmartQuant.FileOrderServer, SmartQuant";
	configuration.orderServer().setConnectionString() = string.Format("PATH={0}\\orders.quant", Installation.dataDir().FullName);
	configuration.setDefaultCurrency() = "USD";
	configuration.setDefaultExchange() = "SMART";
	configuration.setDataProvider() = "QuantRouter";
	configuration.setExecutionProvider() = "QuantRouter";
	configuration.setProviderManagerFileName() = Installation.configDir().FullName + "\\providermanager.xml";
	configuration.setStreamers() = new List<StreamerPlugin>();
	configuration.AddDefaultStreamers();
	configuration.setProviders() = new List<ProviderPlugin>();
	configuration.AddDefaultProviders();
	configuration.setQuantControllerHost() = "localhost";
	configuration.setQuantControllerPort() = 3300;
	configuration.setQuantControllerUsername() = "OpenQuant";
	configuration.setQuantControllerPassword() = string.Empty;
	configuration.setQuantControllerUpdateStatusInterval() = 1000;
	configuration.setQuantControllerAutoConnect() = false;
	return configuration;
}


// Pubic API 

Configuration::Configuration()
	: d_ptr(new ConfigurationPrivate)
{
}

Configuration::~Configuration()
{
}

Configuration::Configuration (const Configuration &other)
	: d_ptr(other.d_ptr)
{
}

Configuration& Configuration::operator=(const Configuration &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Configuration::operator==(const Configuration &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

bool isInstrumentFileLocal() const
{
	return d_ptr->
	setIsInstrumentFileLocal()
}

QString instrumentFileHost() const
{
	return d_ptr->
	setInstrumentFileHost()
}

int instrumentFilePort() const
{
	return d_ptr->
	setInstrumentFilePort()
}

QString instrumentFileName() const
{
	return d_ptr->
	setInstrumentFileName()
}

bool isDataFileLocal() const
{
	return d_ptr->
	setIsDataFileLocal()
}

QString dataFileHost() const
{
	return d_ptr->
	setDataFileHost()
}

int dataFilePort() const
{
	return d_ptr->
	setDataFilePort()
}

QString dataFileName() const
{
	return d_ptr->
	setDataFileName()
}

ServerConfiguration orderServer() const
{
	return d_ptr->
	setOrderServer()
}

QString providerManagerFileName() const
{
	return d_ptr->
	setProviderManagerFileName()
}

QList<StreamerPlugin> streamers() const
{
	return d_ptr->
	setStreamers()
}

QList<ProviderPlugin> providers() const
{
	return d_ptr->
	setProviders()
}

QString quantControllerHost() const
{
	return d_ptr->
	setQuantControllerHost()
}

int quantControllerPort() const
{
	return d_ptr->
	setQuantControllerPort()
}

QString quantControllerUsername() const
{
	return d_ptr->
	setQuantControllerUsername()
}

QString quantControllerPassword() const
{
	return d_ptr->
	setQuantControllerPassword()
}

int quantControllerUpdateStatusInterval() const
{
	return d_ptr->
	setQuantControllerUpdateStatusInterval()
}

bool quantControllerAutoConnect() const
{
	return d_ptr->
	setQuantControllerAutoConnect()
}

void Configuration::addDefaultProviders()
{
	d_ptr->addDefaultProviders();
}

void Configuration::addDefaultStreamers()
{
	d_ptr->addDefaultStreamers();
}

Configuration Configuration::defaultConfiguaration()
{
	return d_ptr->defaultConfiguaration();
}

QDebug operator<<(QDebug dbg, const Configuration& configuration)
{
	return dbg << configuration.toString();
}

