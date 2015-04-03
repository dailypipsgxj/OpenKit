#ifndef __QUANTKIT_ONEVENTMANAGERRESUMED_H__
#define __QUANTKIT_ONEVENTMANAGERRESUMED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnEventManagerResumedPrivate;

class QUANTKIT_EXPORT OnEventManagerResumed Q_DECL_FINAL : public Event
{
public:
	OnEventManagerResumed();
	~OnEventManagerResumed();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnEventManagerResumed)

#endif // __QUANTKIT_ONEVENTMANAGERRESUMED_H__
