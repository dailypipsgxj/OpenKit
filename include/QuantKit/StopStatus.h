#ifndef __QUANTKIT_STOPSTATUS_H__
#define __QUANTKIT_STOPSTATUS_H__

namespace QuantKit {

enum class StopStatus : unsigned char
{
	Active,
	Executed,
	Canceled
};

} // namespace QuantKit

#endif // __QUANTKIT_STOPSTATUS_H__
