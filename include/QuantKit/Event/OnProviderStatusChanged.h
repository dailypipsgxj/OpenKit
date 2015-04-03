#ifndef __QUANTKIT_ONPROVIDERSTATUSCHANGED_H__
#define __QUANTKIT_ONPROVIDERSTATUSCHANGED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnProviderStatusChangedPrivate;

class Provider;

class QUANTKIT_EXPORT OnProviderStatusChanged Q_DECL_FINAL : public Event
{
public:
	explicit OnProviderStatusChanged(const Provider& provider);
	~OnProviderStatusChanged();

public:
	Provider rboVjhqyRm() const;

private:
	QK_DECLARE_PRIVATE(OnProviderStatusChanged)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnProviderStatusChanged)

#endif // __QUANTKIT_ONPROVIDERSTATUSCHANGED_H__
