#ifndef __QUANTKIT_PROVIDEREVENTHANDLER_H__
#define __QUANTKIT_PROVIDEREVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class ProviderEventHandlerPrivate;

class ProviderEventArgs;

class QUANTKIT_EXPORT ProviderEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	ProviderEventHandler(const QVariant& object, IntPtr method);
	~ProviderEventHandler();

	ProviderEventHandler(const ProviderEventHandler &other);
	ProviderEventHandler& operator=(const ProviderEventHandler &other);
	bool operator==(const ProviderEventHandler &other) const;
	inline bool operator!=(const ProviderEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const ProviderEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const ProviderEventArgs& e);

private:
	QSharedDataPointer<ProviderEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ProviderEventHandler& providereventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ProviderEventHandler& providereventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderEventHandler)

#endif // __QUANTKIT_PROVIDEREVENTHANDLER_H__
