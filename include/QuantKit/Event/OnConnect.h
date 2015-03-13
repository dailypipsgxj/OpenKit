#ifndef ONCONNECT_H
#define ONCONNECT_H

#include <QuantKit/quantkit_global.h>
#include <QuantKit/Event.h>

namespace QuantKit {

class OnConnectPrivate;

class QUANTKIT_EXPORT OnConnect Q_DECL_FINAL : public Event
{
public:
    OnConnect();
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnConnect)

#endif // ONCONNECT_H
