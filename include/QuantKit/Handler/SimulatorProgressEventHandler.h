#ifndef __QUANTKIT_SIMULATORPROGRESSEVENTHANDLER_H__
#define __QUANTKIT_SIMULATORPROGRESSEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class SimulatorProgressEventHandlerPrivate;

class SimulatorProgressEventArgs;

class QUANTKIT_EXPORT SimulatorProgressEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	SimulatorProgressEventHandler(const QVariant& object, IntPtr method);
	~SimulatorProgressEventHandler();

	SimulatorProgressEventHandler(const SimulatorProgressEventHandler &other);
	SimulatorProgressEventHandler& operator=(const SimulatorProgressEventHandler &other);
	bool operator==(const SimulatorProgressEventHandler &other) const;
	inline bool operator!=(const SimulatorProgressEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const SimulatorProgressEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const SimulatorProgressEventArgs& e);

private:
	QSharedDataPointer<SimulatorProgressEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const SimulatorProgressEventHandler& simulatorprogresseventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const SimulatorProgressEventHandler& simulatorprogresseventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SimulatorProgressEventHandler)

#endif // __QUANTKIT_SIMULATORPROGRESSEVENTHANDLER_H__
