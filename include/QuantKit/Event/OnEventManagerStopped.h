#ifndef __QUANTKIT_ONEVENTMANAGERSTOPPED_H__
#define __QUANTKIT_ONEVENTMANAGERSTOPPED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnEventManagerStoppedPrivate;

class QUANTKIT_EXPORT OnEventManagerStopped Q_DECL_FINAL : public Event
{
public:
	OnEventManagerStopped();
	~OnEventManagerStopped();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnEventManagerStopped)

#endif // __QUANTKIT_ONEVENTMANAGERSTOPPED_H__
