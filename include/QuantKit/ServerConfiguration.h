#ifndef __QUANTKIT_SERVERCONFIGURATION_H__
#define __QUANTKIT_SERVERCONFIGURATION_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class ServerConfigurationPrivate;

class QUANTKIT_EXPORT ServerConfiguration
{
public:
	ServerConfiguration();
	~ServerConfiguration();

	ServerConfiguration(const ServerConfiguration &other);
	ServerConfiguration& operator=(const ServerConfiguration &other);
	bool operator==(const ServerConfiguration &other) const;
	inline bool operator!=(const ServerConfiguration &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<ServerConfigurationPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ServerConfiguration& serverconfiguration);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ServerConfiguration& serverconfiguration);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ServerConfiguration)

#endif // __QUANTKIT_SERVERCONFIGURATION_H__
