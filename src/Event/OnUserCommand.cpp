#include <QuantKit/Event/OnUserCommand.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnUserCommandPrivate : public EventPrivate
{
public:
	QString string_0;

public:
	explicit OnUserCommandPrivate(const QString& command);
	virtual ~OnUserCommandPrivate();

public:
	QString getString_0() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnUserCommand;
	}

	virtual OnUserCommandPrivate* clone() Q_DECL_OVERRIDE { return new OnUserCommandPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnUserCommandPrivate::OnUserCommandPrivate(const QString& command)
	: string_0(command)
{
}

OnUserCommandPrivate::~OnUserCommandPrivate ()
{
}

QString getString_0() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnUserCommand)

OnUserCommand::OnUserCommand(const QString& command)
	: Event(*new OnUserCommandPrivate(command))
{
}

OnUserCommand::~OnUserCommand()
{
}

QString string_0() const
{
	return d_ptr->
	setString_0()
}


