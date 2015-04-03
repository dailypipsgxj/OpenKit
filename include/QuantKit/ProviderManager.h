#ifndef __QUANTKIT_PROVIDERMANAGER_H__
#define __QUANTKIT_PROVIDERMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/IDataSimulator.h>
#include <QuantKit/IExecutionSimulator.h>
#include <QuantKit/IProvider.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/IHistoricalDataProvider.h>
#include <QuantKit/IInstrumentProvider.h>
#include <QuantKit/INewsProvider.h>

namespace QuantKit {

class ProviderManagerPrivate;

class ProviderList;
class Framework;
class Provider;

class QUANTKIT_EXPORT ProviderManager
{
public:
	ProviderManager(const Framework& framework, const IDataSimulator& dataSimulator = 0, const IExecutionSimulator& executionSimulator = 0);
	~ProviderManager();

	ProviderManager(const ProviderManager &other);
	ProviderManager& operator=(const ProviderManager &other);
	bool operator==(const ProviderManager &other) const;
	inline bool operator!=(const ProviderManager &other) const { return !(this->operator==(other));  }
public:
	ProviderList providers() const;
	IDataSimulator dataSimulator() const;
	void setDataSimulator(const IDataSimulator& value);
	IExecutionSimulator executionSimulator() const;
	void setExecutionSimulator(const IExecutionSimulator& value);
	void addProvider(const IProvider& provider);
	void clear();
	void disconnectAll();
	void dispose();
	IDataProvider getDataProvider(int id);
	IDataProvider getDataProvider(const QString& name);
	IExecutionProvider getExecutionProvider(int id);
	IExecutionProvider getExecutionProvider(const QString& name);
	INewsProvider getFundamentalProvider(int id);
	INewsProvider getFundamentalProvider(const QString& name);
	IHistoricalDataProvider getHistoricalDataProvider(int id);
	IHistoricalDataProvider getHistoricalDataProvider(const QString& name);
	IInstrumentProvider getInstrumentProvider(int id);
	IInstrumentProvider getInstrumentProvider(const QString& name);
	INewsProvider getNewsProvider(int id);
	INewsProvider getNewsProvider(const QString& name);
	IProvider getProvider(int id);
	IProvider getProvider(const QString& name);
	void loadSettings(const IProvider& provider);
	void removeProvider(const Provider& provider);
	void saveSettings(const IProvider& provider);
	void setDataSimulator(const QString& name);
	void setDataSimulator(int id);
	void setExecutionSimulator(const QString& name);
	void setExecutionSimulator(int id);

private:
	QSharedDataPointer<ProviderManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ProviderManager& providermanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ProviderManager& providermanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderManager)

#endif // __QUANTKIT_PROVIDERMANAGER_H__
