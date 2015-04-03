#ifndef __QUANTKIT_BARINPUT_H__
#define __QUANTKIT_BARINPUT_H__

namespace QuantKit {

enum class BarInput : unsigned char
{
	Trade,
	Bid,
	Ask,
	Middle,
	Tick,
	BidAsk
};

} // namespace QuantKit

#endif // __QUANTKIT_BARINPUT_H__
