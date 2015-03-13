#ifndef TICK_H
#define TICK_H

#include <QuantKit/Event.h>

namespace QuantKit {

class TickPrivate;

class QUANTKIT_EXPORT Tick : public DataObject
{
public:
    QDateTime exchangeDateTime() const;
    void setExchangeDateTime(const QDateTime& dateTime);

    unsigned char providerId() const;
    void setProviderId(unsigned char providerId);

    unsigned char instrumentId() const;
    void setInstrumentId(unsigned char instrumentId);

    double price() const;
    void setPrice(double price);

    int size() const;
    void setSize(int size);

protected:
    Tick(TickPrivate& dd);

private:
    QK_DECLARE_PRIVATE(Tick)
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Tick)

#endif // TICK_H
