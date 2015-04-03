#ifndef __QUANTKIT_FRAMEWORK_H__
#define __QUANTKIT_FRAMEWORK_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QSharedDataPointer>

#include <QuantKit/Clock.h>
#include <QuantKit/FrameworkMode.h>
#include <QuantKit/ICurrencyConverter.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/IDataProvider.h>

namespace QuantKit {

class FrameworkPrivate;

class Configuration;
class EventBus;
class EventServer;
class EventManager;
class InstrumentServer;
class InstrumentManager;
class DataServer;
class DataManager;
class ProviderManager;
class EventLoggerManager;
class SubscriptionManager;
class OrderServer;
class OrderManager;
class PortfolioManager;
class StrategyManager;
class StatisticsManager;
class GroupManager;
class AccountDataManager;
class LicenseManager;
class GroupDispatcher;
class StreamerManager;
class DataFileManager;
class ServerConfiguration;

class QUANTKIT_EXPORT Framework
{
public:
	Framework(const QString& name = "", FrameworkMode mode = FrameworkMode::Simulation, bool createServers = true);
	Framework(const QString& name, const InstrumentServer& instrumentServer, const DataServer& dataServer);
    Framework(const QString& name, const EventBus& externalBus, const InstrumentServer& instrumentServer, const DataServer& dataServer);
	~Framework();

	Framework(const Framework &other);
	Framework& operator=(const Framework &other);
#ifdef Q_COMPILER_RVALUE_REFS
    Framework &operator=(Framework &&other) { swap(other); return *this; }
#endif

    void swap(Framework& other) { d.swap(other.d); }

	bool operator==(const Framework &other) const;
	inline bool operator!=(const Framework &other) const { return !(this->operator==(other));  }
public:
	bool isExternalDataQueue() const;
	void setIsExternalDataQueue(bool value);
	QString name() const;
	Configuration configuration() const;
	FrameworkMode mode() const;
	void setMode(FrameworkMode value);
	Clock clock() const;
	Clock exchangeClock() const;
	EventBus eventBus() const;
	EventServer eventServer() const;
	EventManager eventManager() const;
	InstrumentServer instrumentServer() const;
	InstrumentManager instrumentManager() const;
	void setInstrumentManager(const InstrumentManager& value);
	DataServer dataServer() const;
	DataManager dataManager() const;
	void setDataManager(const DataManager& value);
	ProviderManager providerManager() const;
	EventLoggerManager eventLoggerManager() const;
	SubscriptionManager subscriptionManager() const;
	OrderServer orderServer() const;
	OrderManager orderManager() const;
	PortfolioManager portfolioManager() const;
	StrategyManager strategyManager() const;
	StatisticsManager statisticsManager() const;
	GroupManager groupManager() const;
	AccountDataManager accountDataManager() const;
	LicenseManager licenseManager() const;
	ICurrencyConverter currencyConverter() const;
	void setCurrencyConverter(const ICurrencyConverter& value);
	GroupDispatcher groupDispatcher() const;
	void setGroupDispatcher(const GroupDispatcher& value);
	StreamerManager streamerManager() const;
	DataFileManager dataFileManager() const;
	Framework current() const;
	IExecutionProvider executionProvider() const;
	IDataProvider dataProvider() const;
	void clear();
	void dump();
	void load(const QByteArray& reader);
	void save(const QByteArray& writer);

private:
    QSharedDataPointer<FrameworkPrivate> d;

	friend QDebug operator<<(QDebug dbg, const Framework& framework);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Framework& framework);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Framework)

#endif // __QUANTKIT_FRAMEWORK_H__
