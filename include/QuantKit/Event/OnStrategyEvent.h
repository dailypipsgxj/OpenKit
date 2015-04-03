#ifndef __QUANTKIT_ONSTRATEGYEVENT_H__
#define __QUANTKIT_ONSTRATEGYEVENT_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnStrategyEventPrivate;

class QUANTKIT_EXPORT OnStrategyEvent Q_DECL_FINAL : public Event
{
public:
	explicit OnStrategyEvent(const QVariant& data);
	~OnStrategyEvent();

public:
	QVariant object_0() const;

private:
	QK_DECLARE_PRIVATE(OnStrategyEvent)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnStrategyEvent)

#endif // __QUANTKIT_ONSTRATEGYEVENT_H__
