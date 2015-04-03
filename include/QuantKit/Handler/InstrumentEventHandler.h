#ifndef __QUANTKIT_INSTRUMENTEVENTHANDLER_H__
#define __QUANTKIT_INSTRUMENTEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class InstrumentEventHandlerPrivate;

class InstrumentEventArgs;

class QUANTKIT_EXPORT InstrumentEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	InstrumentEventHandler(const QVariant& object, IntPtr method);
	~InstrumentEventHandler();

	InstrumentEventHandler(const InstrumentEventHandler &other);
	InstrumentEventHandler& operator=(const InstrumentEventHandler &other);
	bool operator==(const InstrumentEventHandler &other) const;
	inline bool operator!=(const InstrumentEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const InstrumentEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const InstrumentEventArgs& e);

private:
	QSharedDataPointer<InstrumentEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentEventHandler& instrumenteventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentEventHandler& instrumenteventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentEventHandler)

#endif // __QUANTKIT_INSTRUMENTEVENTHANDLER_H__
