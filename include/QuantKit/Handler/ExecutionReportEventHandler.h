#ifndef __QUANTKIT_EXECUTIONREPORTEVENTHANDLER_H__
#define __QUANTKIT_EXECUTIONREPORTEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class ExecutionReportEventHandlerPrivate;

class ExecutionReport;

class QUANTKIT_EXPORT ExecutionReportEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	ExecutionReportEventHandler(const QVariant& object, IntPtr method);
	~ExecutionReportEventHandler();

	ExecutionReportEventHandler(const ExecutionReportEventHandler &other);
	ExecutionReportEventHandler& operator=(const ExecutionReportEventHandler &other);
	bool operator==(const ExecutionReportEventHandler &other) const;
	inline bool operator!=(const ExecutionReportEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const ExecutionReport& report, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const ExecutionReport& report);

private:
	QSharedDataPointer<ExecutionReportEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ExecutionReportEventHandler& executionreporteventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ExecutionReportEventHandler& executionreporteventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionReportEventHandler)

#endif // __QUANTKIT_EXECUTIONREPORTEVENTHANDLER_H__
