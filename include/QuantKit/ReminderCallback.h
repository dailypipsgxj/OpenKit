#ifndef __QUANTKIT_REMINDERCALLBACK_H__
#define __QUANTKIT_REMINDERCALLBACK_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QDateTime>
#include <QSharedDataPointer>

namespace QuantKit {

class ReminderCallbackPrivate;

class QUANTKIT_EXPORT ReminderCallback Q_DECL_FINAL : public MulticastDelegate
{
public:
	ReminderCallback(const QVariant& object, IntPtr method);
	~ReminderCallback();

	ReminderCallback(const ReminderCallback &other);
	ReminderCallback& operator=(const ReminderCallback &other);
	bool operator==(const ReminderCallback &other) const;
	inline bool operator!=(const ReminderCallback &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QDateTime& dateTime, const QVariant& data, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QDateTime& dateTime, const QVariant& data);

private:
	QSharedDataPointer<ReminderCallbackPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ReminderCallback& remindercallback);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ReminderCallback& remindercallback);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ReminderCallback)

#endif // __QUANTKIT_REMINDERCALLBACK_H__
