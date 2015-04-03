#ifndef __QUANTKIT_ONEVENTMANAGERPAUSED_H__
#define __QUANTKIT_ONEVENTMANAGERPAUSED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnEventManagerPausedPrivate;

class QUANTKIT_EXPORT OnEventManagerPaused Q_DECL_FINAL : public Event
{
public:
	OnEventManagerPaused();
	~OnEventManagerPaused();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnEventManagerPaused)

#endif // __QUANTKIT_ONEVENTMANAGERPAUSED_H__
