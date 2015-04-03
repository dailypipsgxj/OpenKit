#ifndef __QUANTKIT_ASK_H__
#define __QUANTKIT_ASK_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

#include <QuantKit/Tick.h>

namespace QuantKit {

class AskPrivate;


class QUANTKIT_EXPORT Ask Q_DECL_FINAL : public Tick
{
public:
	Ask();
	Ask(const QDateTime& dateTime, unsigned char providerId, int instrument, double price, int size);
	Ask(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrument, double price, int size);
	~Ask();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Ask)

#endif // __QUANTKIT_ASK_H__
