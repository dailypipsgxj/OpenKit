#ifndef __QUANTKIT_EXECUTIONMESSAGE_H__
#define __QUANTKIT_EXECUTIONMESSAGE_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class ExecutionMessagePrivate;

class Order;
class Instrument;
class ObjectTable;

class QUANTKIT_EXPORT ExecutionMessage : public DataObject
{
public:
	ExecutionMessage();
	~ExecutionMessage();

public:
	int id() const;
	Order order() const;
	void setOrder(const Order& value);
	int orderId() const;
	void setOrderId(int value);
	Instrument instrument() const;
	void setInstrument(const Instrument& value);
	int instrumentId() const;
	QVariant item(int index) const;
	void setItem(int index, const QVariant& value);

protected:
	ExecutionMessage(ExecutionMessagePrivate& dd);

private:
	QK_DECLARE_PRIVATE(ExecutionMessage)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionMessage)

#endif // __QUANTKIT_EXECUTIONMESSAGE_H__
