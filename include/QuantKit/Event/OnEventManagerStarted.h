#ifndef __QUANTKIT_ONEVENTMANAGERSTARTED_H__
#define __QUANTKIT_ONEVENTMANAGERSTARTED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnEventManagerStartedPrivate;

class QUANTKIT_EXPORT OnEventManagerStarted Q_DECL_FINAL : public Event
{
public:
	OnEventManagerStarted();
	~OnEventManagerStarted();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnEventManagerStarted)

#endif // __QUANTKIT_ONEVENTMANAGERSTARTED_H__
