#ifndef __QUANTKIT_EVENTMANAGERSTATUS_H__
#define __QUANTKIT_EVENTMANAGERSTATUS_H__

namespace QuantKit {

enum EventManagerStatus : unsigned char
{
	Running,
	Paused,
	Stopping,
	Stopped
};

} // namespace QuantKit

#endif // __QUANTKIT_EVENTMANAGERSTATUS_H__
