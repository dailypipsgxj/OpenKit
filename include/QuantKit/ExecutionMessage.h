#ifndef __QUANTKIT_EXECUTIONMESSAGE_H__
#define __QUANTKIT_EXECUTIONMESSAGE_H__

#include <QuantKit/quantkit_global.h>
#include <QList>
#include <QVariant>
#include <QSharedPointer>

namespace QuantKit {

class Order;
class Instrument;
class ObjectTable;

class QUANTKIT_EXPORT ExecutionMessage
{
public:
	ExecutionMessage();
	~ExecutionMessage();

public:
    int id() const { return m_ordId; }
    QSharedPointer<Order> order() const { return m_order; }
    void setOrder(const QSharedPointer<Order>& order) { m_order = order; }
	int orderId() const;
	void setOrderId(int value);
    QSharedPointer<Instrument> instrument() const { return m_instrument; }
    void setInstrument(const QSharedPointer<Instrument>& inst) { m_instrument = inst; }
	int instrumentId() const;
	QVariant item(int index) const;
	void setItem(int index, const QVariant& value);

private:
    int m_ordId;
    QSharedPointer<Order> m_order;
    int m_orderId;
    Instrument m_instrument;
    int m_instrumentId;
    QList<QVariant> m_objectTable;
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionMessage)

#endif // __QUANTKIT_EXECUTIONMESSAGE_H__
