#ifndef __QUANTKIT_ONPROVIDERREMOVED_H__
#define __QUANTKIT_ONPROVIDERREMOVED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnProviderRemovedPrivate;

class Provider;

class QUANTKIT_EXPORT OnProviderRemoved Q_DECL_FINAL : public Event
{
public:
	explicit OnProviderRemoved(const Provider& provider);
	~OnProviderRemoved();

public:
	Provider provider() const;

private:
	QK_DECLARE_PRIVATE(OnProviderRemoved)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnProviderRemoved)

#endif // __QUANTKIT_ONPROVIDERREMOVED_H__
