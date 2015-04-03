#include <QuantKit/ProviderManager.h>

#include <QuantKit/ProviderList.h>
#include <QuantKit/Framework.h>
#include "Provider_p.h"

namespace QuantKit {

class ProviderManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	ProviderList m_providers;
	ProviderList providerList_1;
	ProviderList providerList_2;
	ProviderList providerList_3;
	ProviderList providerList_4;
	ProviderList providerList_5;
	ProviderList providerList_6;
	IDataSimulator m_dataSimulator;
	IExecutionSimulator m_executionSimulator;
	Class69 class69_0;

public:
	ProviderManagerPrivate(const Framework& framework, const IDataSimulator& dataSimulator, const IExecutionSimulator& executionSimulator);
	virtual ~ProviderManagerPrivate();

public:
	ProviderList providers() const { return m_providers; }
	IDataSimulator dataSimulator() const { return m_dataSimulator; }
	void setDataSimulator(const IDataSimulator& value) { m_dataSimulator = value; }
	IExecutionSimulator executionSimulator() const { return m_executionSimulator; }
	void setExecutionSimulator(const IExecutionSimulator& value) { m_executionSimulator = value; }
	void addProvider(const IProvider& provider);
	void clear();
	void disconnectAll();
	void dispose();
	IDataProvider getDataProvider(int id)
	{
		return (IDataProvider)providerList_1.GetById(id);
	}

	IDataProvider getDataProvider(const QString& name)
	{
		return (IDataProvider)providerList_1.GetByName(name);
	}

	IExecutionProvider getExecutionProvider(int id)
	{
		return (IExecutionProvider)providerList_2.GetById(id);
	}

	IExecutionProvider getExecutionProvider(const QString& name)
	{
		return (IExecutionProvider)providerList_2.GetByName(name);
	}

	INewsProvider getFundamentalProvider(int id)
	{
		return (INewsProvider)providerList_6.GetById(id);
	}

	INewsProvider getFundamentalProvider(const QString& name)
	{
		return (INewsProvider)providerList_6.GetByName(name);
	}

	IHistoricalDataProvider getHistoricalDataProvider(int id)
	{
		return (IHistoricalDataProvider)providerList_4.GetById(id);
	}

	IHistoricalDataProvider getHistoricalDataProvider(const QString& name)
	{
		return (IHistoricalDataProvider)providerList_4.GetByName(name);
	}

	IInstrumentProvider getInstrumentProvider(int id)
	{
		return (IInstrumentProvider)providerList_3.GetById(id);
	}

	IInstrumentProvider getInstrumentProvider(const QString& name)
	{
		return (IInstrumentProvider)providerList_3.GetByName(name);
	}

	INewsProvider getNewsProvider(int id)
	{
		return (INewsProvider)providerList_5.GetById(id);
	}

	INewsProvider getNewsProvider(const QString& name)
	{
		return (INewsProvider)providerList_5.GetByName(name);
	}

	IProvider getProvider(int id)
	{
		return m_providers.GetById(id);
	}

	IProvider getProvider(const QString& name)
	{
		return m_providers.GetByName(name);
	}

	void loadSettings(const IProvider& provider);
	void removeProvider(const Provider& provider);
	void saveSettings(const IProvider& provider);
	void setDataSimulator(const QString& name)
	{
		m_dataSimulator = (GetProvider(name) as IDataSimulator);
	}

	void setDataSimulator(int id)
	{
		m_dataSimulator = (GetProvider(id) as IDataSimulator);
	}

	void setExecutionSimulator(const QString& name)
	{
		m_executionSimulator = (GetProvider(name) as IExecutionSimulator);
	}

	void setExecutionSimulator(int id)
	{
		m_executionSimulator = (GetProvider(id) as IExecutionSimulator);
	}

	virtual ProviderManagerPrivate* clone() Q_DECL_OVERRIDE { return new ProviderManagerPrivate(*this); }
//private:
	void method_0();
	void method_1();
	QString method_2()
	{
		return m_framework.configuration().providerManagerFileName();
	}

	void method_3(bool bool);
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderManagerPrivate::ProviderManagerPrivate(const Framework& framework, IDataSimulator dataSimulator, IExecutionSimulator executionSimulator)
	: m_framework(framework)
	, m_providers(new ProviderList())
	, providerList_1(new ProviderList())
	, providerList_2(new ProviderList())
	, providerList_3(new ProviderList())
	, providerList_4(new ProviderList())
	, providerList_5(new ProviderList())
	, providerList_6(new ProviderList())
	, m_dataSimulator(new DataSimulator(framework))
	, m_dataSimulator(dataSimulator)
	, m_executionSimulator(new ExecutionSimulator(framework))
	, m_executionSimulator(executionSimulator)
{
		method_0();
		if (dataSimulator == null)
		{
		}
		else
		{
		}
		AddProvider(m_dataSimulator);
		if (executionSimulator == null)
		{
		}
		else
		{
		}
		AddProvider(m_executionSimulator);
}

ProviderManagerPrivate::~ProviderManagerPrivate ()
{
}

void ProviderManagerPrivate::addProvider(const IProvider& provider)
{
	if (provider.id() > 100)
	{
		Console.WriteLine("ProviderManager::AddProvider Error. Provider Id must be smaller than 100. You are trying to add provider with Id = " + provider.id());
		return;
	}
	m_providers.Add(provider);
	if (provider is IDataProvider)
	{
		providerList_1.Add(provider);
	}
	if (provider is IExecutionProvider)
	{
		providerList_2.Add(provider);
	}
	if (provider is IHistoricalDataProvider)
	{
		providerList_4.Add(provider);
	}
	if (provider is IInstrumentProvider)
	{
		providerList_3.Add(provider);
	}
	if (provider is INewsProvider)
	{
		providerList_5.Add(provider);
	}
	if (provider is INewsProvider)
	{
		providerList_6.Add(provider);
	}
	LoadSettings(provider);
	m_framework.eventServer().OnProviderAdded(provider);
}

void ProviderManagerPrivate::clear()
{
	if (m_dataSimulator != null)
	{
		m_dataSimulator.Clear();
	}
	if (m_executionSimulator != null)
	{
		m_executionSimulator.Clear();
	}
}

void ProviderManagerPrivate::disconnectAll()
{
	using (IEnumerator<IProvider> enumerator = m_providers.GetEnumerator())
	{
		while (enumerator.MoveNext())
		{
			Provider provider = (Provider)enumerator.Current;
			if (provider.isConnected())
			{
				provider.Disconnect();
			}
		}
	}
}

void ProviderManagerPrivate::dispose()
{
	method_3(true);
	GC.SuppressFinalize(this);
}

void ProviderManagerPrivate::loadSettings(const IProvider& provider)
{
	if (provider is Provider)
	{
		Class70 @class = class69_0.method_0().method_3(provider);
		if (@class != null)
		{
			((Provider)provider).SetProperties(@class.method_4());
		}
	}
}

void ProviderManagerPrivate::removeProvider(const Provider& provider)
{
	m_providers.Remove(provider);
	if (provider is IDataProvider)
	{
		providerList_1.Remove(provider);
	}
	if (provider is IExecutionProvider)
	{
		providerList_2.Remove(provider);
	}
	if (provider is IHistoricalDataProvider)
	{
		providerList_4.Remove(provider);
	}
	if (provider is IInstrumentProvider)
	{
		providerList_3.Remove(provider);
	}
	if (provider is INewsProvider)
	{
		providerList_5.Remove(provider);
	}
	if (provider is INewsProvider)
	{
		providerList_6.Remove(provider);
	}
	m_framework.eventServer().OnProviderRemoved(provider);
}

void ProviderManagerPrivate::saveSettings(const IProvider& provider)
{
	Class70 @class = class69_0.method_0().method_3(provider);
	if (@class == null)
	{
		@class = new Class70(provider);
		class69_0.method_0().method_4(provider, @class);
	}
	if (provider is Provider)
	{
		@class.method_5(new ProviderPropertyList(((Provider)provider).GetProperties()));
	}
	method_1();
}

void ProviderManagerPrivate::method_0()
{
	try
	{
		string path = method_2();
		if (File.Exists(path))
		{
			XmlSerializer xmlSerializer = new XmlSerializer(typeof(XmlProviderManagerSettings));
			using (FileStream fileStream = new FileStream(path, FileMode.Open))
			{
				XmlProviderManagerSettings xmlProviderManagerSettings = (XmlProviderManagerSettings)xmlSerializer.Deserialize(fileStream);
				class69_0.method_3(xmlProviderManagerSettings);
			}
		}
	}
	catch
	{
	}
}

void ProviderManagerPrivate::method_1()
{
	try
	{
		XmlSerializer xmlSerializer = new XmlSerializer(typeof(XmlProviderManagerSettings));
		using (FileStream fileStream = new FileStream(method_2(), FileMode.Create))
		{
			xmlSerializer.Serialize(fileStream, class69_0.method_2());
		}
	}
	catch
	{
	}
}

void ProviderManagerPrivate::method_3(bool bool)
{
	if (@bool)
	{
		DisconnectAll();
		using (IEnumerator<IProvider> enumerator = m_providers.GetEnumerator())
		{
			while (enumerator.MoveNext())
			{
				Provider provider = (Provider)enumerator.Current;
				provider.Dispose();
			}
		}
	}
}


// Pubic API 

ProviderManager::ProviderManager(const Framework& framework, IDataSimulator dataSimulator, IExecutionSimulator executionSimulator)
	: d_ptr(new ProviderManagerPrivate(framework, dataSimulator, executionSimulator))
{
}

ProviderManager::~ProviderManager()
{
}

ProviderManager::ProviderManager (const ProviderManager &other)
	: d_ptr(other.d_ptr)
{
}

ProviderManager& ProviderManager::operator=(const ProviderManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ProviderManager::operator==(const ProviderManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

ProviderList ProviderManager::providers() const
{
	return d_ptr->providers();
}

IDataSimulator ProviderManager::dataSimulator() const
{
	return d_ptr->dataSimulator();
}

void ProviderManager::setDataSimulator(const IDataSimulator& value)
{
	d_ptr->setDataSimulator(value);
}

IExecutionSimulator ProviderManager::executionSimulator() const
{
	return d_ptr->executionSimulator();
}

void ProviderManager::setExecutionSimulator(const IExecutionSimulator& value)
{
	d_ptr->setExecutionSimulator(value);
}

void ProviderManager::addProvider(const IProvider& provider)
{
	d_ptr->addProvider(provider);
}

void ProviderManager::clear()
{
	d_ptr->clear();
}

void ProviderManager::disconnectAll()
{
	d_ptr->disconnectAll();
}

void ProviderManager::dispose()
{
	d_ptr->dispose();
}

IDataProvider ProviderManager::getDataProvider(int id)
{
	return d_ptr->getDataProvider(id);
}

IDataProvider ProviderManager::getDataProvider(const QString& name)
{
	return d_ptr->getDataProvider(name);
}

IExecutionProvider ProviderManager::getExecutionProvider(int id)
{
	return d_ptr->getExecutionProvider(id);
}

IExecutionProvider ProviderManager::getExecutionProvider(const QString& name)
{
	return d_ptr->getExecutionProvider(name);
}

INewsProvider ProviderManager::getFundamentalProvider(int id)
{
	return d_ptr->getFundamentalProvider(id);
}

INewsProvider ProviderManager::getFundamentalProvider(const QString& name)
{
	return d_ptr->getFundamentalProvider(name);
}

IHistoricalDataProvider ProviderManager::getHistoricalDataProvider(int id)
{
	return d_ptr->getHistoricalDataProvider(id);
}

IHistoricalDataProvider ProviderManager::getHistoricalDataProvider(const QString& name)
{
	return d_ptr->getHistoricalDataProvider(name);
}

IInstrumentProvider ProviderManager::getInstrumentProvider(int id)
{
	return d_ptr->getInstrumentProvider(id);
}

IInstrumentProvider ProviderManager::getInstrumentProvider(const QString& name)
{
	return d_ptr->getInstrumentProvider(name);
}

INewsProvider ProviderManager::getNewsProvider(int id)
{
	return d_ptr->getNewsProvider(id);
}

INewsProvider ProviderManager::getNewsProvider(const QString& name)
{
	return d_ptr->getNewsProvider(name);
}

IProvider ProviderManager::getProvider(int id)
{
	return d_ptr->getProvider(id);
}

IProvider ProviderManager::getProvider(const QString& name)
{
	return d_ptr->getProvider(name);
}

void ProviderManager::loadSettings(const IProvider& provider)
{
	d_ptr->loadSettings(provider);
}

void ProviderManager::removeProvider(const Provider& provider)
{
	d_ptr->removeProvider(provider);
}

void ProviderManager::saveSettings(const IProvider& provider)
{
	d_ptr->saveSettings(provider);
}

void ProviderManager::setDataSimulator(const QString& name)
{
	d_ptr->setDataSimulator(name);
}

void ProviderManager::setDataSimulator(int id)
{
	d_ptr->setDataSimulator(id);
}

void ProviderManager::setExecutionSimulator(const QString& name)
{
	d_ptr->setExecutionSimulator(name);
}

void ProviderManager::setExecutionSimulator(int id)
{
	d_ptr->setExecutionSimulator(id);
}

QDebug operator<<(QDebug dbg, const ProviderManager& providermanager)
{
	return dbg << providermanager.toString();
}

