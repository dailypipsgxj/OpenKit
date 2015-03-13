#include <QuantKit/Event/OnDisconnect.h>
#include <QuantKit/Event_p.h>

namespace QuantKit {

class OnDisconnectPrivate Q_DECL_FINAL : public EventPrivate
{
public:
    OnDisconnectPrivate() : EventPrivate() {}
    virtual ~OnDisconnectPrivate() {}

public:
    virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnDisconnect; }
    virtual OnDisconnectPrivate* clone() Q_DECL_OVERRIDE { return new OnDisconnectPrivate(*this); }
};

} // namespace QuantKit

using namespace QuantKit;

OnDisconnect::OnDisconnect()
    : Event(*new OnDisconnectPrivate)
{
}

