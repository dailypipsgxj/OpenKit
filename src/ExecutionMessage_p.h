#ifndef __QUANTKIT_EXECUTIONMESSAGE_PRIVATE_H__
#define __QUANTKIT_EXECUTIONMESSAGE_PRIVATE_H__

#include <QuantKit/ExecutionMessage.h>

#include "DataObject_p.h"
#include "Order_p.h"
#include "Instrument_p.h"
#include "ObjectTable_p.h"

namespace QuantKit {

class ExecutionMessagePrivate : public DataObjectPrivate
{
public:
	int m_id;
	Order m_order;
	int m_orderId;
	Instrument m_instrument;
	int m_instrumentId;
	ObjectTable m_item;

public:
	ExecutionMessagePrivate();
	virtual ~ExecutionMessagePrivate();

public:
	int id() const { return m_id; }
	Order order() const { return m_order; }
	void setOrder(const Order& value);
	int orderId() const { return m_orderId; }
	void setOrderId(int value) { m_orderId = value; }
	Instrument instrument() const { return m_instrument; }
	void setInstrument(const Instrument& value);
	int instrumentId() const { return m_instrumentId; }
	QVariant item(int index) const;
	void setItem(int index, const QVariant& value);
};

} // namepsace QuantKit

#endif // __QUANTKIT_EXECUTIONMESSAGE_PRIVATE_H__
