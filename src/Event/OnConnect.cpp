#include <QuantKit/Event/OnConnect.h>
#include <QuantKit/Event_p.h>

namespace QuantKit {

class OnConnectPrivate Q_DECL_FINAL : public EventPrivate
{
public:
    OnConnectPrivate() : EventPrivate() {}
    virtual ~OnConnectPrivate() {}

public:
    virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnConnect; }
    virtual OnConnectPrivate* clone() Q_DECL_OVERRIDE { return new OnConnectPrivate(*this); }
};

} // namespace QuantKit

using namespace QuantKit;

OnConnect::OnConnect()
    : Event(*new OnConnectPrivate)
{
}

