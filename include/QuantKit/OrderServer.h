#ifndef __QUANTKIT_ORDERSERVER_H__
#define __QUANTKIT_ORDERSERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QList>

#include <QuantKit/FrameworkServer.h>

namespace QuantKit {

class OrderServerPrivate;

class ExecutionMessage;

class QUANTKIT_EXPORT OrderServer : public FrameworkServer
{
public:
	OrderServer();
	~OrderServer();

public:
	QList<ExecutionMessage> load();
	void save(const ExecutionMessage& message);

protected:
	OrderServer(OrderServerPrivate& dd);

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OrderServer)

#endif // __QUANTKIT_ORDERSERVER_H__
