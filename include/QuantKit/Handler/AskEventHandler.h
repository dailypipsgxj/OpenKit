#ifndef __QUANTKIT_ASKEVENTHANDLER_H__
#define __QUANTKIT_ASKEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class AskEventHandlerPrivate;

class Ask;

class QUANTKIT_EXPORT AskEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	AskEventHandler(const QVariant& object, IntPtr method);
	~AskEventHandler();

	AskEventHandler(const AskEventHandler &other);
	AskEventHandler& operator=(const AskEventHandler &other);
	bool operator==(const AskEventHandler &other) const;
	inline bool operator!=(const AskEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const Ask& ask, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const Ask& ask);

private:
	QSharedDataPointer<AskEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const AskEventHandler& askeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const AskEventHandler& askeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AskEventHandler)

#endif // __QUANTKIT_ASKEVENTHANDLER_H__
