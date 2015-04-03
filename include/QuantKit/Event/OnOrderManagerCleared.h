#ifndef __QUANTKIT_ONORDERMANAGERCLEARED_H__
#define __QUANTKIT_ONORDERMANAGERCLEARED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderManagerClearedPrivate;

class QUANTKIT_EXPORT OnOrderManagerCleared Q_DECL_FINAL : public Event
{
public:
	OnOrderManagerCleared();
	~OnOrderManagerCleared();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderManagerCleared)

#endif // __QUANTKIT_ONORDERMANAGERCLEARED_H__
