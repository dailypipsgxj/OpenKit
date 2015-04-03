#ifndef __QUANTKIT_FRAMEWORKEVENTHANDLER_H__
#define __QUANTKIT_FRAMEWORKEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class FrameworkEventHandlerPrivate;

class FrameworkEventArgs;

class QUANTKIT_EXPORT FrameworkEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	FrameworkEventHandler(const QVariant& object, IntPtr method);
	~FrameworkEventHandler();

	FrameworkEventHandler(const FrameworkEventHandler &other);
	FrameworkEventHandler& operator=(const FrameworkEventHandler &other);
	bool operator==(const FrameworkEventHandler &other) const;
	inline bool operator!=(const FrameworkEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const FrameworkEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const FrameworkEventArgs& e);

private:
	QSharedDataPointer<FrameworkEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const FrameworkEventHandler& frameworkeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const FrameworkEventHandler& frameworkeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FrameworkEventHandler)

#endif // __QUANTKIT_FRAMEWORKEVENTHANDLER_H__
