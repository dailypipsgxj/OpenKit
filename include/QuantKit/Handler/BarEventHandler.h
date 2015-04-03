#ifndef __QUANTKIT_BAREVENTHANDLER_H__
#define __QUANTKIT_BAREVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class BarEventHandlerPrivate;

class Bar;

class QUANTKIT_EXPORT BarEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	BarEventHandler(const QVariant& object, IntPtr method);
	~BarEventHandler();

	BarEventHandler(const BarEventHandler &other);
	BarEventHandler& operator=(const BarEventHandler &other);
	bool operator==(const BarEventHandler &other) const;
	inline bool operator!=(const BarEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const Bar& bar, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const Bar& bar);

private:
	QSharedDataPointer<BarEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const BarEventHandler& bareventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BarEventHandler& bareventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarEventHandler)

#endif // __QUANTKIT_BAREVENTHANDLER_H__
