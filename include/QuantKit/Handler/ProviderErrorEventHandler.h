#ifndef __QUANTKIT_PROVIDERERROREVENTHANDLER_H__
#define __QUANTKIT_PROVIDERERROREVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class ProviderErrorEventHandlerPrivate;

class ProviderErrorEventArgs;

class QUANTKIT_EXPORT ProviderErrorEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	ProviderErrorEventHandler(const QVariant& object, IntPtr method);
	~ProviderErrorEventHandler();

	ProviderErrorEventHandler(const ProviderErrorEventHandler &other);
	ProviderErrorEventHandler& operator=(const ProviderErrorEventHandler &other);
	bool operator==(const ProviderErrorEventHandler &other) const;
	inline bool operator!=(const ProviderErrorEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const ProviderErrorEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const ProviderErrorEventArgs& e);

private:
	QSharedDataPointer<ProviderErrorEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ProviderErrorEventHandler& providererroreventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ProviderErrorEventHandler& providererroreventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderErrorEventHandler)

#endif // __QUANTKIT_PROVIDERERROREVENTHANDLER_H__
