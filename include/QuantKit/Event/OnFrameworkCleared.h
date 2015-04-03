#ifndef __QUANTKIT_ONFRAMEWORKCLEARED_H__
#define __QUANTKIT_ONFRAMEWORKCLEARED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnFrameworkClearedPrivate;

class Framework;

class QUANTKIT_EXPORT OnFrameworkCleared Q_DECL_FINAL : public Event
{
public:
	explicit OnFrameworkCleared(const Framework& framework);
	~OnFrameworkCleared();

public:
	Framework framework() const;

private:
	QK_DECLARE_PRIVATE(OnFrameworkCleared)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnFrameworkCleared)

#endif // __QUANTKIT_ONFRAMEWORKCLEARED_H__
