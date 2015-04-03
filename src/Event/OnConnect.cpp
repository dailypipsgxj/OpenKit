#include <QuantKit/Event/OnConnect.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnConnectPrivate : public EventPrivate
{
public:
	OnConnectPrivate();
	virtual ~OnConnectPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnConnect; }
	virtual OnConnectPrivate* clone() Q_DECL_OVERRIDE { return new OnConnectPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnConnectPrivate::OnConnectPrivate()
{
}

OnConnectPrivate::~OnConnectPrivate ()
{
}


// Pubic API 

OnConnect::OnConnect()
	: Event(*new OnConnectPrivate)
{
}

OnConnect::~OnConnect()
{
}


