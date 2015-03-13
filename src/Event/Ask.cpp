#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Tick_p.h>

namespace QuantKit {

class AskPrivate Q_DECL_FINAL : public TickPrivate
{
public:
    AskPrivate(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : TickPrivate(dateTime, providerId, instrumentId, price, size) {}

    AskPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
        : TickPrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size) {}

    virtual ~AskPrivate() {}

public:
    virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Ask; }
    virtual AskPrivate* clone() Q_DECL_OVERRIDE { return new AskPrivate(*this); }
};

} // namespace QuantKit

using namespace QuantKit;

// public API

Ask::Ask(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
    : Tick(*new AskPrivate(dateTime, providerId, instrumentId, price, size))
{
}

Ask::Ask(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size)
    : Tick(*new AskPrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size))
{
}

