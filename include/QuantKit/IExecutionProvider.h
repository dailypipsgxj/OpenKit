#ifndef __QUANTKIT_IEXECUTIONPROVIDER_H__
#define __QUANTKIT_IEXECUTIONPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>

#include <QuantKit/IProvider.h>

namespace QuantKit {

class ExecutionCommand;

class QUANTKIT_EXPORT IExecutionProvider : public IProvider
{
public:
	virtual void send(const ExecutionCommand& command) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IEXECUTIONPROVIDER_H__
