#ifndef __QUANTKIT_BARTYPE_H__
#define __QUANTKIT_BARTYPE_H__

namespace QuantKit {

enum class BarType : unsigned char
{
	Time = 1,
	Tick,
	Volume,
	Range,
	Session
};

} // namespace QuantKit

#endif // __QUANTKIT_BARTYPE_H__
