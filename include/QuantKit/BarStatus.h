#ifndef __QUANTKIT_BARSTATUS_H__
#define __QUANTKIT_BARSTATUS_H__

namespace QuantKit {

enum class BarStatus : unsigned char
{
	Incomplete,
	Complete,
	Open,
	High,
	Low,
	Close
};

} // namespace QuantKit

#endif // __QUANTKIT_BARSTATUS_H__
