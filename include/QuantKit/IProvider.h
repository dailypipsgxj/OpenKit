#ifndef IPROVIDER_H
#define IPROVIDER_H

#include <QuantKit/quantkit_global.h>
#include <QString>

namespace QuantKit {

enum ProviderStatus
{
    Connecting,
    Connected,
    Disconnecting,
    Disconnected
};

class QUANTKIT_EXPORT IProvier
{
    virtual ProviderStatus status() = 0;
    virtual bool isConnected() = 0;
    virtual bool isDisconnected() = 0;
    virtual unsigned char id() = 0;
    virtual QString name() = 0;
    virtual void connect() = 0;
    virtual void disconnect() = 0;
};

} // namespace QuantKit

#endif // IPROVIDER_H

