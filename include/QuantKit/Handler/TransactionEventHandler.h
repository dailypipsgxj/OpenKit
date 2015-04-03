#ifndef __QUANTKIT_TRANSACTIONEVENTHANDLER_H__
#define __QUANTKIT_TRANSACTIONEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class TransactionEventHandlerPrivate;

class OnTransaction;

class QUANTKIT_EXPORT TransactionEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	TransactionEventHandler(const QVariant& object, IntPtr method);
	~TransactionEventHandler();

	TransactionEventHandler(const TransactionEventHandler &other);
	TransactionEventHandler& operator=(const TransactionEventHandler &other);
	bool operator==(const TransactionEventHandler &other) const;
	inline bool operator!=(const TransactionEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const OnTransaction& transaction, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const OnTransaction& transaction);

private:
	QSharedDataPointer<TransactionEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const TransactionEventHandler& transactioneventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const TransactionEventHandler& transactioneventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TransactionEventHandler)

#endif // __QUANTKIT_TRANSACTIONEVENTHANDLER_H__
