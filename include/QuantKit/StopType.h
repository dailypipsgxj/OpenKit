#ifndef __QUANTKIT_STOPTYPE_H__
#define __QUANTKIT_STOPTYPE_H__

namespace QuantKit {

enum class StopType : unsigned char
{
	Fixed,
	Trailing,
	Time
};

} // namespace QuantKit

#endif // __QUANTKIT_STOPTYPE_H__
