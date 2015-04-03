#ifndef __QUANTKIT_TICK_PRIVATE_H__
#define __QUANTKIT_TICK_PRIVATE_H__

#include <QuantKit/Tick.h>

#include "DataObject_p.h"

namespace QuantKit {

class TickPrivate : public DataObjectPrivate
{
public:
	QDateTime m_exchangeDateTime;
	unsigned char m_providerId;
	int m_instrumentId;
	double m_price;
	int m_size;

public:
	TickPrivate();
	TickPrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size);
	TickPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size);
	virtual ~TickPrivate();

public:
	unsigned char providerId() const { return m_providerId; }
	void setProviderId(unsigned char value) { m_providerId = value; }
	int instrumentId() const { return m_instrumentId; }
	void setInstrumentId(int value) { m_instrumentId = value; }
	double price() const { return m_price; }
	void setPrice(double value) { m_price = value; }
	int size() const { return m_size; }
	void setSize(int value) { m_size = value; }
	QDateTime exchangeDateTime() const { return m_exchangeDateTime; }
	void setExchangeDateTime(const QDateTime& value) { m_exchangeDateTime = value; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Tick"; }
};

} // namepsace QuantKit

#endif // __QUANTKIT_TICK_PRIVATE_H__
