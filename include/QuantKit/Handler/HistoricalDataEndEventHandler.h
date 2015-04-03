#ifndef __QUANTKIT_HISTORICALDATAENDEVENTHANDLER_H__
#define __QUANTKIT_HISTORICALDATAENDEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class HistoricalDataEndEventHandlerPrivate;

class HistoricalDataEndEventArgs;

class QUANTKIT_EXPORT HistoricalDataEndEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	HistoricalDataEndEventHandler(const QVariant& object, IntPtr method);
	~HistoricalDataEndEventHandler();

	HistoricalDataEndEventHandler(const HistoricalDataEndEventHandler &other);
	HistoricalDataEndEventHandler& operator=(const HistoricalDataEndEventHandler &other);
	bool operator==(const HistoricalDataEndEventHandler &other) const;
	inline bool operator!=(const HistoricalDataEndEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const HistoricalDataEndEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const HistoricalDataEndEventArgs& e);

private:
	QSharedDataPointer<HistoricalDataEndEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const HistoricalDataEndEventHandler& historicaldataendeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const HistoricalDataEndEventHandler& historicaldataendeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::HistoricalDataEndEventHandler)

#endif // __QUANTKIT_HISTORICALDATAENDEVENTHANDLER_H__
