#ifndef __QUANTKIT_IPROVIDER_H__
#define __QUANTKIT_IPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>

#include <QuantKit/ProviderStatus.h>

namespace QuantKit {

class QUANTKIT_EXPORT IProvider
{
public:
	virtual ProviderStatus status() const = 0;
	virtual bool isConnected() const = 0;
	virtual bool isDisconnected() const = 0;
	virtual unsigned char id() const = 0;
	virtual QString name() const = 0;
	virtual void connect() = 0;
	virtual bool connect(int timeout) = 0;
	virtual void disconnect() = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IPROVIDER_H__
