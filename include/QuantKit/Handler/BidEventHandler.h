#ifndef __QUANTKIT_BIDEVENTHANDLER_H__
#define __QUANTKIT_BIDEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class BidEventHandlerPrivate;

class Bid;

class QUANTKIT_EXPORT BidEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	BidEventHandler(const QVariant& object, IntPtr method);
	~BidEventHandler();

	BidEventHandler(const BidEventHandler &other);
	BidEventHandler& operator=(const BidEventHandler &other);
	bool operator==(const BidEventHandler &other) const;
	inline bool operator!=(const BidEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const Bid& bid, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const Bid& bid);

private:
	QSharedDataPointer<BidEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const BidEventHandler& bideventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BidEventHandler& bideventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BidEventHandler)

#endif // __QUANTKIT_BIDEVENTHANDLER_H__
