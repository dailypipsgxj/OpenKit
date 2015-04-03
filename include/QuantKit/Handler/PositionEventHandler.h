#ifndef __QUANTKIT_POSITIONEVENTHANDLER_H__
#define __QUANTKIT_POSITIONEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class PositionEventHandlerPrivate;

class PositionEventArgs;

class QUANTKIT_EXPORT PositionEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	PositionEventHandler(const QVariant& object, IntPtr method);
	~PositionEventHandler();

	PositionEventHandler(const PositionEventHandler &other);
	PositionEventHandler& operator=(const PositionEventHandler &other);
	bool operator==(const PositionEventHandler &other) const;
	inline bool operator!=(const PositionEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const PositionEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const PositionEventArgs& e);

private:
	QSharedDataPointer<PositionEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PositionEventHandler& positioneventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PositionEventHandler& positioneventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PositionEventHandler)

#endif // __QUANTKIT_POSITIONEVENTHANDLER_H__
