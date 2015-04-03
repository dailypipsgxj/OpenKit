#ifndef __QUANTKIT_TIMEINFORCE_H__
#define __QUANTKIT_TIMEINFORCE_H__

namespace QuantKit {

enum TimeInForce : unsigned char
{
	ATC,
	Day,
	GTC,
	IOC,
	OPG,
	OC,
	FOK,
	GTX,
	GTD,
	GFS,
	AUC
};

} // namespace QuantKit

#endif // __QUANTKIT_TIMEINFORCE_H__
