#ifndef __QUANTKIT_ONQUEUECLOSED_H__
#define __QUANTKIT_ONQUEUECLOSED_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnQueueClosedPrivate;

class EventQueue;

class QUANTKIT_EXPORT OnQueueClosed Q_DECL_FINAL : public Event
{
public:
	explicit OnQueueClosed(const EventQueue& queue);
	~OnQueueClosed();

public:
	EventQueue eventQueue_0() const;

private:
	QK_DECLARE_PRIVATE(OnQueueClosed)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnQueueClosed)

#endif // __QUANTKIT_ONQUEUECLOSED_H__
