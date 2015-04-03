#ifndef __QUANTKIT_FILLEVENTHANDLER_H__
#define __QUANTKIT_FILLEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class FillEventHandlerPrivate;

class OnFill;

class QUANTKIT_EXPORT FillEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	FillEventHandler(const QVariant& object, IntPtr method);
	~FillEventHandler();

	FillEventHandler(const FillEventHandler &other);
	FillEventHandler& operator=(const FillEventHandler &other);
	bool operator==(const FillEventHandler &other) const;
	inline bool operator!=(const FillEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const OnFill& fill, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const OnFill& fill);

private:
	QSharedDataPointer<FillEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const FillEventHandler& filleventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const FillEventHandler& filleventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FillEventHandler)

#endif // __QUANTKIT_FILLEVENTHANDLER_H__
