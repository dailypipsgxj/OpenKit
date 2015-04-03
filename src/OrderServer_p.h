#ifndef __QUANTKIT_ORDERSERVER_PRIVATE_H__
#define __QUANTKIT_ORDERSERVER_PRIVATE_H__

#include <QuantKit/OrderServer.h>

#include "FrameworkServer_p.h"
#include "ExecutionMessage_p.h"

namespace QuantKit {

class OrderServerPrivate : public FrameworkServerPrivate
{
public:
	OrderServerPrivate();
	virtual ~OrderServerPrivate();

public:
	QList<ExecutionMessage> load();
	void save(const ExecutionMessage& message);
};

} // namepsace QuantKit

#endif // __QUANTKIT_ORDERSERVER_PRIVATE_H__
