#ifndef __QUANTKIT_ONEVENTMANAGERSTEP_H__
#define __QUANTKIT_ONEVENTMANAGERSTEP_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnEventManagerStepPrivate;

class QUANTKIT_EXPORT OnEventManagerStep Q_DECL_FINAL : public Event
{
public:
	OnEventManagerStep();
	~OnEventManagerStep();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnEventManagerStep)

#endif // __QUANTKIT_ONEVENTMANAGERSTEP_H__
