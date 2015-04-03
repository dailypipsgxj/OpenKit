#ifndef __QUANTKIT_ONPROVIDERDISCONNECTED_H__
#define __QUANTKIT_ONPROVIDERDISCONNECTED_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnProviderDisconnectedPrivate;

class Provider;

class QUANTKIT_EXPORT OnProviderDisconnected Q_DECL_FINAL : public Event
{
public:
	OnProviderDisconnected(const QDateTime& dateTime, unsigned char providerId);
	OnProviderDisconnected(const QDateTime& dateTime, const Provider& provider);
	~OnProviderDisconnected();

public:
	unsigned char providerId() const;
	Provider provider() const;

private:
	QK_DECLARE_PRIVATE(OnProviderDisconnected)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnProviderDisconnected)

#endif // __QUANTKIT_ONPROVIDERDISCONNECTED_H__
