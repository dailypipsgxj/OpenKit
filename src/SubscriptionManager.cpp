#include <QuantKit/SubscriptionManager.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentList.h>

namespace QuantKit {

class SubscriptionManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	Dictionary<int,Dictionary<Instrument,int>> m_dictionary;

public:
	explicit SubscriptionManagerPrivate(const Framework& framework);
	virtual ~SubscriptionManagerPrivate();

public:
	void clear() { m_dictionary.Clear(); }
	bool isSubscribed(const IDataProvider& provider, const Instrument& instrument)
	{
		return m_dictionary.ContainsKey((int)provider.id()) && m_dictionary[(int)provider.id()].ContainsKey(instrument) && m_dictionary[(int)provider.id()][instrument] > 0;
	}

	void subscribe(int providerId, const Instrument& instrument);
	void subscribe(int providerId, int instrumentId);
	void subscribe(const QString& provider, const Instrument& instrument);
	void subscribe(const QString& provider, const QString& symbol);
	void subscribe(const IDataProvider& provider, const Instrument& instrument);
	void subscribe(const IDataProvider& provider, const InstrumentList& instruments);
	void unsubscribe(int providerId, const Instrument& instrument);
	void unsubscribe(int providerId, int instrumentId);
	void unsubscribe(const IDataProvider& provider, const Instrument& instrument);
	void unsubscribe(const QString& provider, const Instrument& instrument);
	void unsubscribe(const QString& provider, const QString& symbol);
	void unsubscribe(const IDataProvider& provider, const InstrumentList& instruments);
	virtual SubscriptionManagerPrivate* clone() Q_DECL_OVERRIDE { return new SubscriptionManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

SubscriptionManagerPrivate::SubscriptionManagerPrivate(const Framework& framework)
	: m_framework(framework)
	, m_dictionary(new Dictionary<int, Dictionary<Instrument, int>>())
{
}

SubscriptionManagerPrivate::~SubscriptionManagerPrivate ()
{
}

void SubscriptionManagerPrivate::subscribe(int providerId, const Instrument& instrument)
{
	IDataProvider provider = m_framework.providerManager().GetProvider(providerId) as IDataProvider;
	Subscribe(provider, instrument);
}

void SubscriptionManagerPrivate::subscribe(int providerId, int instrumentId)
{
	Instrument byId = m_framework.instrumentManager().GetById(instrumentId);
	Subscribe(providerId, byId);
}

void SubscriptionManagerPrivate::subscribe(const QString& provider, const Instrument& instrument)
{
	IDataProvider provider2 = m_framework.providerManager().GetProvider(provider) as IDataProvider;
	Subscribe(provider2, instrument);
}

void SubscriptionManagerPrivate::subscribe(const QString& provider, const QString& symbol)
{
	IDataProvider provider2 = m_framework.providerManager().GetProvider(provider) as IDataProvider;
	Instrument instrument = m_framework.instrumentManager().Get(symbol);
	Subscribe(provider2, instrument);
}

void SubscriptionManagerPrivate::subscribe(const IDataProvider& provider, const Instrument& instrument)
{
	if (provider.status() != ProviderStatus.Connected)
	{
		provider.Connect();
	}
	Dictionary<Instrument, int> dictionary = null;
	if (!m_dictionary.TryGetValue((int)provider.id(), out dictionary))
	{
		dictionary = new Dictionary<Instrument, int>();
		m_dictionary[(int)provider.id()] = dictionary;
	}
	int num = 0;
	bool flag = false;
	if (!dictionary.TryGetValue(instrument, out num))
	{
		flag = true;
		num = 1;
	}
	else
	{
		if (num == 0)
		{
			flag = true;
		}
		num++;
	}
	dictionary[instrument] = num;
	if (flag)
	{
		provider.Subscribe(instrument);
	}
}

void SubscriptionManagerPrivate::subscribe(const IDataProvider& provider, const InstrumentList& instruments)
{
	if (provider.status() != ProviderStatus.Connected)
	{
		provider.Connect();
	}
	InstrumentList instrumentList = new InstrumentList();
	for (int i = 0; i < instruments.count(); i++)
	{
		Instrument byIndex = instruments.GetByIndex(i);
		if (!m_dictionary.ContainsKey((int)provider.id()))
		{
			m_dictionary[(int)provider.id()] = new Dictionary<Instrument, int>();
		}
		if (!m_dictionary[(int)provider.id()].ContainsKey(byIndex) || m_dictionary[(int)provider.id()][byIndex] == 0)
		{
			m_dictionary[(int)provider.id()][byIndex] = 0;
			instrumentList.Add(byIndex);
		}
		Dictionary<Instrument, int> dictionary;
		Instrument key;
		(dictionary = m_dictionary[(int)provider.id()])[key = byIndex] = dictionary[key] + 1;
	}
	if (instrumentList.count() > 0)
	{
		provider.Subscribe(instrumentList);
	}
}

void SubscriptionManagerPrivate::unsubscribe(int providerId, const Instrument& instrument)
{
	IDataProvider provider = m_framework.providerManager().GetProvider(providerId) as IDataProvider;
	Unsubscribe(provider, instrument);
}

void SubscriptionManagerPrivate::unsubscribe(int providerId, int instrumentId)
{
	Instrument byId = m_framework.instrumentManager().GetById(instrumentId);
	Unsubscribe(providerId, byId);
}

void SubscriptionManagerPrivate::unsubscribe(const IDataProvider& provider, const Instrument& instrument)
{
	if (m_dictionary[(int)provider.id()][instrument] == 0)
	{
		Console.WriteLine("SubscriptionManager::Unsubscribe Error. Instrument has no subscriptions " + instrument.symbol() + " on data provider " + provider.name());
		return;
	}
	Dictionary<Instrument, int> dictionary;
	(dictionary = m_dictionary[(int)provider.id()])[instrument] = dictionary[instrument] - 1;
	if (m_dictionary[(int)provider.id()][instrument] == 0)
	{
		provider.Unsubscribe(instrument);
	}
}

void SubscriptionManagerPrivate::unsubscribe(const QString& provider, const Instrument& instrument)
{
	IDataProvider provider2 = m_framework.providerManager().GetProvider(provider) as IDataProvider;
	Unsubscribe(provider2, instrument);
}

void SubscriptionManagerPrivate::unsubscribe(const QString& provider, const QString& symbol)
{
	IDataProvider provider2 = m_framework.providerManager().GetProvider(provider) as IDataProvider;
	Instrument instrument = m_framework.instrumentManager().Get(symbol);
	Unsubscribe(provider2, instrument);
}

void SubscriptionManagerPrivate::unsubscribe(const IDataProvider& provider, const InstrumentList& instruments)
{
	InstrumentList instrumentList = new InstrumentList();
	for (int i = 0; i < instruments.count(); i++)
	{
		Instrument byIndex = instruments.GetByIndex(i);
		if (m_dictionary[(int)provider.id()][byIndex] == 0)
		{
			Console.WriteLine("SubscriptionManager::Unsubscribe Error. Instrument has no subscriptions " + byIndex.symbol() + " on data provider " + provider.name());
		}
		else
		{
			Dictionary<Instrument, int> dictionary;
			Instrument key;
			(dictionary = m_dictionary[(int)provider.id()])[key = byIndex] = dictionary[key] - 1;
			if (m_dictionary[(int)provider.id()][byIndex] == 0)
			{
				instrumentList.Add(byIndex);
			}
		}
	}
	provider.Unsubscribe(instrumentList);
}


// Pubic API 

SubscriptionManager::SubscriptionManager(const Framework& framework)
	: d_ptr(new SubscriptionManagerPrivate(framework))
{
}

SubscriptionManager::~SubscriptionManager()
{
}

SubscriptionManager::SubscriptionManager (const SubscriptionManager &other)
	: d_ptr(other.d_ptr)
{
}

SubscriptionManager& SubscriptionManager::operator=(const SubscriptionManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool SubscriptionManager::operator==(const SubscriptionManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void SubscriptionManager::clear()
{
	d_ptr->clear();
}

bool SubscriptionManager::isSubscribed(const IDataProvider& provider, const Instrument& instrument)
{
	return d_ptr->isSubscribed(provider, instrument);
}

void SubscriptionManager::subscribe(int providerId, const Instrument& instrument)
{
	d_ptr->subscribe(providerId, instrument);
}

void SubscriptionManager::subscribe(int providerId, int instrumentId)
{
	d_ptr->subscribe(providerId, instrumentId);
}

void SubscriptionManager::subscribe(const QString& provider, const Instrument& instrument)
{
	d_ptr->subscribe(provider, instrument);
}

void SubscriptionManager::subscribe(const QString& provider, const QString& symbol)
{
	d_ptr->subscribe(provider, symbol);
}

void SubscriptionManager::subscribe(const IDataProvider& provider, const Instrument& instrument)
{
	d_ptr->subscribe(provider, instrument);
}

void SubscriptionManager::subscribe(const IDataProvider& provider, const InstrumentList& instruments)
{
	d_ptr->subscribe(provider, instruments);
}

void SubscriptionManager::unsubscribe(int providerId, const Instrument& instrument)
{
	d_ptr->unsubscribe(providerId, instrument);
}

void SubscriptionManager::unsubscribe(int providerId, int instrumentId)
{
	d_ptr->unsubscribe(providerId, instrumentId);
}

void SubscriptionManager::unsubscribe(const IDataProvider& provider, const Instrument& instrument)
{
	d_ptr->unsubscribe(provider, instrument);
}

void SubscriptionManager::unsubscribe(const QString& provider, const Instrument& instrument)
{
	d_ptr->unsubscribe(provider, instrument);
}

void SubscriptionManager::unsubscribe(const QString& provider, const QString& symbol)
{
	d_ptr->unsubscribe(provider, symbol);
}

void SubscriptionManager::unsubscribe(const IDataProvider& provider, const InstrumentList& instruments)
{
	d_ptr->unsubscribe(provider, instruments);
}

QDebug operator<<(QDebug dbg, const SubscriptionManager& subscriptionmanager)
{
	return dbg << subscriptionmanager.toString();
}

