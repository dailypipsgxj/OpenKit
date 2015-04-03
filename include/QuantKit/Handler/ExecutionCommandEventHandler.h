#ifndef __QUANTKIT_EXECUTIONCOMMANDEVENTHANDLER_H__
#define __QUANTKIT_EXECUTIONCOMMANDEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class ExecutionCommandEventHandlerPrivate;

class ExecutionCommand;

class QUANTKIT_EXPORT ExecutionCommandEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	ExecutionCommandEventHandler(const QVariant& object, IntPtr method);
	~ExecutionCommandEventHandler();

	ExecutionCommandEventHandler(const ExecutionCommandEventHandler &other);
	ExecutionCommandEventHandler& operator=(const ExecutionCommandEventHandler &other);
	bool operator==(const ExecutionCommandEventHandler &other) const;
	inline bool operator!=(const ExecutionCommandEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const ExecutionCommand& command, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const ExecutionCommand& command);

private:
	QSharedDataPointer<ExecutionCommandEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ExecutionCommandEventHandler& executioncommandeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ExecutionCommandEventHandler& executioncommandeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionCommandEventHandler)

#endif // __QUANTKIT_EXECUTIONCOMMANDEVENTHANDLER_H__
