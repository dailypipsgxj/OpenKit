#ifndef __QUANTKIT_ONPROVIDERADDED_H__
#define __QUANTKIT_ONPROVIDERADDED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>
#include <QuantKit/IProvider.h>

namespace QuantKit {

class OnProviderAddedPrivate;

class QUANTKIT_EXPORT OnProviderAdded Q_DECL_FINAL : public Event
{
public:
	explicit OnProviderAdded(const IProvider& provider);
	~OnProviderAdded();

public:
	IProvider iprovider() const;

private:
	QK_DECLARE_PRIVATE(OnProviderAdded)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnProviderAdded)

#endif // __QUANTKIT_ONPROVIDERADDED_H__
