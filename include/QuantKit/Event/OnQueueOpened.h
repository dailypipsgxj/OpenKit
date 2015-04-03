#ifndef __QUANTKIT_ONQUEUEOPENED_H__
#define __QUANTKIT_ONQUEUEOPENED_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnQueueOpenedPrivate;

class EventQueue;

class QUANTKIT_EXPORT OnQueueOpened Q_DECL_FINAL : public Event
{
public:
	explicit OnQueueOpened(const EventQueue& queue);
	~OnQueueOpened();

public:

private:
	QK_DECLARE_PRIVATE(OnQueueOpened)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnQueueOpened)

#endif // __QUANTKIT_ONQUEUEOPENED_H__
