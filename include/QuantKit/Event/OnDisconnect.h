#ifndef __QUANTKIT_ONDISCONNECT_H__
#define __QUANTKIT_ONDISCONNECT_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnDisconnectPrivate;

class QUANTKIT_EXPORT OnDisconnect Q_DECL_FINAL : public Event
{
public:
	OnDisconnect();
	~OnDisconnect();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnDisconnect)

#endif // __QUANTKIT_ONDISCONNECT_H__
