#ifndef __QUANTKIT_STOPFILLMODE_H__
#define __QUANTKIT_STOPFILLMODE_H__

namespace QuantKit {

enum class StopFillMode : unsigned char
{
	Close,
	HighLow,
	Stop
};

} // namespace QuantKit

#endif // __QUANTKIT_STOPFILLMODE_H__
