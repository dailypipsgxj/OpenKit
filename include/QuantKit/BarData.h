#ifndef __QUANTKIT_BARDATA_H__
#define __QUANTKIT_BARDATA_H__

namespace QuantKit {

enum class BarData : unsigned char
{
	Close,
	Open,
	High,
	Low,
	Median,
	Typical,
	Weighted,
	Average,
	Volume,
	OpenInt,
	Range,
	Mean,
	Variance,
	StdDev
};

} // namespace QuantKit

#endif // __QUANTKIT_BARDATA_H__
