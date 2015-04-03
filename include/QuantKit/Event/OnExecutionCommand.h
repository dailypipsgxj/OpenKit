#ifndef __QUANTKIT_ONEXECUTIONCOMMAND_H__
#define __QUANTKIT_ONEXECUTIONCOMMAND_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnExecutionCommandPrivate;

class ExecutionCommand;

class QUANTKIT_EXPORT OnExecutionCommand Q_DECL_FINAL : public Event
{
public:
	explicit OnExecutionCommand(const ExecutionCommand& command);
	~OnExecutionCommand();

public:

private:
	QK_DECLARE_PRIVATE(OnExecutionCommand)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnExecutionCommand)

#endif // __QUANTKIT_ONEXECUTIONCOMMAND_H__
