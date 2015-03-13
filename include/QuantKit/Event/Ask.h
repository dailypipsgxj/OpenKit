#ifndef ASK_H
#define ASK_H

#include <QuantKit/Event/Tick.h>

namespace QuantKit {

class AskPrivate;

class QUANTKIT_EXPORT Ask Q_DECL_FINAL : public Tick
{
public:
    Ask(const QDateTime& dateTime, unsigned char providerId, unsigned char instrumentId, double price, int size);
    Ask(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, unsigned char instrumentId, double price, int size);
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Ask)

#endif // ASK_H
