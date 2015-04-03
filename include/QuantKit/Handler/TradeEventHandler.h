#ifndef __QUANTKIT_TRADEEVENTHANDLER_H__
#define __QUANTKIT_TRADEEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class TradeEventHandlerPrivate;

class Trade;

class QUANTKIT_EXPORT TradeEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	TradeEventHandler(const QVariant& object, IntPtr method);
	~TradeEventHandler();

	TradeEventHandler(const TradeEventHandler &other);
	TradeEventHandler& operator=(const TradeEventHandler &other);
	bool operator==(const TradeEventHandler &other) const;
	inline bool operator!=(const TradeEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const Trade& trade, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const Trade& trade);

private:
	QSharedDataPointer<TradeEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const TradeEventHandler& tradeeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const TradeEventHandler& tradeeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TradeEventHandler)

#endif // __QUANTKIT_TRADEEVENTHANDLER_H__
