#ifndef __QUANTKIT_REMINDER_H__
#define __QUANTKIT_REMINDER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QDateTime>
#include <QString>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class ReminderPrivate;

class Clock;
class ReminderCallback;

class QUANTKIT_EXPORT Reminder Q_DECL_FINAL : public DataObject
{
public:
	Reminder(const ReminderCallback& callback, const QDateTime& dateTime, const QVariant& data = 0);
	~Reminder();

public:
	Clock clock() const;
	ReminderCallback callback() const;
	QVariant data() const;
	void setData(const QVariant& value);

private:
	QK_DECLARE_PRIVATE(Reminder)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Reminder)

#endif // __QUANTKIT_REMINDER_H__
