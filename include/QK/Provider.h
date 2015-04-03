#ifndef __QUANTKIT_IPROVIDER_H__
#define __QUANTKIT_IPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <extensionsystem/iplugin.h>

namespace QuantKit {

enum ProviderStatus
{
    Connecting,
    Connected,
    Disconnecting,
    Disconnected
};

class Framework;
class Event;

namespace Internal { class QKProviderPrivate; }

class QUANTKIT_EXPORT QKProvider : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PROPERTY(unsigned char id READ id)
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QString description READ description)
    Q_PROPERTY(QString Url READ Url)
    Q_PROPERTY(ProviderStatus Status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(bool isConnected READ isConnected)
    Q_PROPERTY(bool isDisconnected READ isDisconnected)

public:
    QKProvider(Framework *framework);
    virtual ~QKProvider() {}

public:
    ProviderStatus status() const;
    void setStatus();
    bool isConnected() const;
    bool isDisconnected() const;
    bool connect(int timeout);

public:
    virtual void connect();
    virtual void disconnect();
    virtual void process(const Event& e);

public slots:
    void statusChanged();

protected:
    virtual void onConnected();
    virtual void onDisconnected();

private:
    Internal::QKProviderPrivate *d;
};

} // namespace QuantKit

#endif // __QUANTKIT_IPROVIDER_H__

