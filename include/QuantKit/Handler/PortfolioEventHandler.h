#ifndef __QUANTKIT_PORTFOLIOEVENTHANDLER_H__
#define __QUANTKIT_PORTFOLIOEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioEventHandlerPrivate;

class PortfolioEventArgs;

class QUANTKIT_EXPORT PortfolioEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	PortfolioEventHandler(const QVariant& object, IntPtr method);
	~PortfolioEventHandler();

	PortfolioEventHandler(const PortfolioEventHandler &other);
	PortfolioEventHandler& operator=(const PortfolioEventHandler &other);
	bool operator==(const PortfolioEventHandler &other) const;
	inline bool operator!=(const PortfolioEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const PortfolioEventArgs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const PortfolioEventArgs& e);

private:
	QSharedDataPointer<PortfolioEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioEventHandler& portfolioeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioEventHandler& portfolioeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioEventHandler)

#endif // __QUANTKIT_PORTFOLIOEVENTHANDLER_H__
