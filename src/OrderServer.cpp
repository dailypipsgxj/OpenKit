#include <QuantKit/OrderServer.h>

#include "ExecutionMessage_p.h"
#include "OrderServer_p.h"

using namespace QuantKit;

OrderServerPrivate::OrderServerPrivate()
{
}

OrderServerPrivate::~OrderServerPrivate ()
{
}

QList<ExecutionMessage> OrderServerPrivate::load()
{
}

void OrderServerPrivate::save(const ExecutionMessage& message)
{
}


// Pubic API 

OrderServer::OrderServer()
	: FrameworkServer(*new OrderServerPrivate)
{
}

OrderServer::~OrderServer()
{
}

OrderServer::OrderServer (OrderServerPrivate &dd)
	: FrameworkServer(dd)
{
}

QList<ExecutionMessage> OrderServer::load()
{
	Q_D(OrderServer);
	return d->load();
}

void OrderServer::save(const ExecutionMessage& message)
{
	Q_D(OrderServer);
	d->save(message);
}


