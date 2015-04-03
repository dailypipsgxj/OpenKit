#ifndef __QUANTKIT_CONFIGURATION_H__
#define __QUANTKIT_CONFIGURATION_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class ConfigurationPrivate;

class ServerConfiguration;
class StreamerPlugin;
class ProviderPlugin;

class QUANTKIT_EXPORT Configuration
{
public:
	Configuration();
	~Configuration();

	Configuration(const Configuration &other);
	Configuration& operator=(const Configuration &other);
	bool operator==(const Configuration &other) const;
	inline bool operator!=(const Configuration &other) const { return !(this->operator==(other));  }
public:
	bool isInstrumentFileLocal() const;

	QString instrumentFileHost() const;

	int instrumentFilePort() const;

	QString instrumentFileName() const;

	bool isDataFileLocal() const;

	QString dataFileHost() const;

	int dataFilePort() const;

	QString dataFileName() const;

	ServerConfiguration orderServer() const;

	QString providerManagerFileName() const;

	QList<StreamerPlugin> streamers() const;

	QList<ProviderPlugin> providers() const;

	QString quantControllerHost() const;

	int quantControllerPort() const;

	QString quantControllerUsername() const;

	QString quantControllerPassword() const;

	int quantControllerUpdateStatusInterval() const;

	bool quantControllerAutoConnect() const;
	void addDefaultProviders();
	void addDefaultStreamers();
	Configuration defaultConfiguaration();

private:
	QSharedDataPointer<ConfigurationPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Configuration& configuration);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Configuration& configuration);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Configuration)

#endif // __QUANTKIT_CONFIGURATION_H__
