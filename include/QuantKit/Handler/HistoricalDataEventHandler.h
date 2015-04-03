#ifndef __QUANTKIT_HISTORICALDATAEVENTHANDLER_H__
#define __QUANTKIT_HISTORICALDATAEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class HistoricalDataEventHandlerPrivate;

class HistoricalDataEventArgs;

class QUANTKIT_EXPORT HistoricalDataEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	HistoricalDataEventHandler(const QVariant& object, IntPtr method);
	~HistoricalDataEventHandler();

	HistoricalDataEventHandler(const HistoricalDataEventHandler &other);
	HistoricalDataEventHandler& operator=(const HistoricalDataEventHandler &other);
	bool operator==(const HistoricalDataEventHandler &other) const;
	inline bool operator!=(const HistoricalDataEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const HistoricalDataEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const HistoricalDataEventArgs& e);

private:
	QSharedDataPointer<HistoricalDataEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const HistoricalDataEventHandler& historicaldataeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const HistoricalDataEventHandler& historicaldataeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::HistoricalDataEventHandler)

#endif // __QUANTKIT_HISTORICALDATAEVENTHANDLER_H__
