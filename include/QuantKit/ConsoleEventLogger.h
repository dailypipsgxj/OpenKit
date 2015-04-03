#ifndef __QUANTKIT_CONSOLEEVENTLOGGER_H__
#define __QUANTKIT_CONSOLEEVENTLOGGER_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/EventLogger.h>

namespace QuantKit {

class ConsoleEventLoggerPrivate;

class Framework;
class Event;

class QUANTKIT_EXPORT ConsoleEventLogger Q_DECL_FINAL : public EventLogger
{
public:
	explicit ConsoleEventLogger(const Framework& framework);
	~ConsoleEventLogger();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ConsoleEventLogger)

#endif // __QUANTKIT_CONSOLEEVENTLOGGER_H__
