#include <QuantKit/Event/OnExecutionCommand.h>

#include <QuantKit/Event/ExecutionCommand.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnExecutionCommandPrivate : public EventPrivate
{
public:
	ExecutionCommand m_executionCommand;

public:
	explicit OnExecutionCommandPrivate(const ExecutionCommand& command);
	virtual ~OnExecutionCommandPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnExecutionCommand;
	}

	virtual OnExecutionCommandPrivate* clone() Q_DECL_OVERRIDE { return new OnExecutionCommandPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnExecutionCommandPrivate::OnExecutionCommandPrivate(const ExecutionCommand& command)
	: m_executionCommand(command)
{
}

OnExecutionCommandPrivate::~OnExecutionCommandPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnExecutionCommand)

OnExecutionCommand::OnExecutionCommand(const ExecutionCommand& command)
	: Event(*new OnExecutionCommandPrivate(command))
{
}

OnExecutionCommand::~OnExecutionCommand()
{
}


