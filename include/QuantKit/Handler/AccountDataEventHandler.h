#ifndef __QUANTKIT_ACCOUNTDATAEVENTHANDLER_H__
#define __QUANTKIT_ACCOUNTDATAEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class AccountDataEventHandlerPrivate;

class AccountDataEventArgs;

class QUANTKIT_EXPORT AccountDataEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	AccountDataEventHandler(const QVariant& object, IntPtr method);
	~AccountDataEventHandler();

	AccountDataEventHandler(const AccountDataEventHandler &other);
	AccountDataEventHandler& operator=(const AccountDataEventHandler &other);
	bool operator==(const AccountDataEventHandler &other) const;
	inline bool operator!=(const AccountDataEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const AccountDataEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const AccountDataEventArgs& e);

private:
	QSharedDataPointer<AccountDataEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const AccountDataEventHandler& accountdataeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const AccountDataEventHandler& accountdataeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AccountDataEventHandler)

#endif // __QUANTKIT_ACCOUNTDATAEVENTHANDLER_H__
