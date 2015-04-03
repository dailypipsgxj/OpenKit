#ifndef __QUANTKIT_EVENTBUSIDLEMODE_H__
#define __QUANTKIT_EVENTBUSIDLEMODE_H__

namespace QuantKit {

enum class EventBusIdleMode : unsigned char
{
	Spin,
	Sleep,
	Wait
};

} // namespace QuantKit

#endif // __QUANTKIT_EVENTBUSIDLEMODE_H__
