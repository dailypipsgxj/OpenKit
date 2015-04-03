#ifndef __QUANTKIT_TRANSACTION_H__
#define __QUANTKIT_TRANSACTION_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/OrderSide.h>

namespace QuantKit {

class TransactionPrivate;

class Fill;
class Instrument;
class Order;

class QUANTKIT_EXPORT Transaction
{
public:
	Transaction();
	explicit Transaction(const Fill& fill);
	~Transaction();

	Transaction(const Transaction &other);
	Transaction& operator=(const Transaction &other);
	bool operator==(const Transaction &other) const;
	inline bool operator!=(const Transaction &other) const { return !(this->operator==(other));  }
public:
	QList<Fill> fills() const;
	Instrument instrument() const;
	Order order() const;
	OrderSide side() const;
	QString text() const;
	double price() const;
	double qty() const;
	double commission() const;
	bool isDone() const;
	double amount() const;
	double value() const;
	double netCashFlow() const;
	double cashFlow() const;
	void add(const Fill& fill);
	QString toString() const;

private:
	QSharedDataPointer<TransactionPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Transaction& transaction);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Transaction& transaction);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Transaction)

#endif // __QUANTKIT_TRANSACTION_H__
