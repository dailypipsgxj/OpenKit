#ifndef __QUANTKIT_ONCONNECT_H__
#define __QUANTKIT_ONCONNECT_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnConnectPrivate;

class QUANTKIT_EXPORT OnConnect Q_DECL_FINAL : public Event
{
public:
	OnConnect();
	~OnConnect();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnConnect)

#endif // __QUANTKIT_ONCONNECT_H__
