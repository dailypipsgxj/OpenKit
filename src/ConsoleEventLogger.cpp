#include <QuantKit/ConsoleEventLogger.h>

#include <QuantKit/Framework.h>
#include "Event_p.h"
#include "EventLogger_p.h"

namespace QuantKit {

class ConsoleEventLoggerPrivate : public EventLoggerPrivate
{
public:
	explicit ConsoleEventLoggerPrivate(const Framework& framework);
	virtual ~ConsoleEventLoggerPrivate();

public:
	virtual void onEvent(const Event& e) Q_DECL_OVERRIDE;
	virtual ConsoleEventLoggerPrivate* clone() Q_DECL_OVERRIDE { return new ConsoleEventLoggerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ConsoleEventLoggerPrivate::ConsoleEventLoggerPrivate(const Framework& framework)
	: EventLoggerPrivate (framework, "Console")
{
}

ConsoleEventLoggerPrivate::~ConsoleEventLoggerPrivate ()
{
}

void ConsoleEventLoggerPrivate::onEvent(const Event& e)
{
	if (e != null && e.typeId() != 2 && e.typeId() != 3 && e.typeId() != 4 && e.typeId() != 6)
	{
		Console.WriteLine(string.Concat(new object[]
		{
			"Event ",
			e.typeId(),
			" ",
			e.GetType()
		}));
	}
}


// Pubic API 

ConsoleEventLogger::ConsoleEventLogger(const Framework& framework)
	: EventLogger(*new ConsoleEventLoggerPrivate(framework))
{
}

ConsoleEventLogger::~ConsoleEventLogger()
{
}


