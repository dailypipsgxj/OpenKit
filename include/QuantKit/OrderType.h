#ifndef __QUANTKIT_ORDERTYPE_H__
#define __QUANTKIT_ORDERTYPE_H__

namespace QuantKit {

enum OrderType : unsigned char
{
	Market,
	Stop,
	Limit,
	StopLimit,
	MarketOnClose,
	TrailingStop,
	TrailingStopLimit
};

} // namespace QuantKit

#endif // __QUANTKIT_ORDERTYPE_H__
