#ifndef __QUANTKIT_ONPROVIDERCONNECTED_H__
#define __QUANTKIT_ONPROVIDERCONNECTED_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnProviderConnectedPrivate;

class Provider;

class QUANTKIT_EXPORT OnProviderConnected Q_DECL_FINAL : public Event
{
public:
	OnProviderConnected(const QDateTime& dateTime, unsigned char providerId);
	OnProviderConnected(const QDateTime& dateTime, const Provider& provider);
	~OnProviderConnected();

public:
	unsigned char providerId() const;
	Provider provider() const;

private:
	QK_DECLARE_PRIVATE(OnProviderConnected)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnProviderConnected)

#endif // __QUANTKIT_ONPROVIDERCONNECTED_H__
