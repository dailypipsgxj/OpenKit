#ifndef __QUANTKIT_TICK_H__
#define __QUANTKIT_TICK_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class TickPrivate;


class QUANTKIT_EXPORT Tick : public DataObject
{
public:
	Tick();
	Tick(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size);
	Tick(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size);
	~Tick();

public:
	unsigned char providerId() const;
	void setProviderId(unsigned char value);
	int instrumentId() const;
	void setInstrumentId(int value);
	double price() const;
	void setPrice(double value);
	int size() const;
	void setSize(int value);
	QDateTime exchangeDateTime() const;
	void setExchangeDateTime(const QDateTime& value);

protected:
	Tick(TickPrivate& dd);

private:
	QK_DECLARE_PRIVATE(Tick)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Tick)

#endif // __QUANTKIT_TICK_H__
