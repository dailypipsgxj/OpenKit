#ifndef ONDISCONNECT_H
#define ONDISCONNECT_H

#include <QuantKit/quantkit_global.h>
#include <QuantKit/Event.h>

namespace QuantKit {

class OnDisconnectPrivate;

class QUANTKIT_EXPORT OnDisconnect Q_DECL_FINAL : public Event
{
public:
    OnDisconnect();
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnDisconnect)

#endif // ONDISCONNECT_H
