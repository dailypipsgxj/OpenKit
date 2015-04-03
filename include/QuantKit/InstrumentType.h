#ifndef __QUANTKIT_INSTRUMENTTYPE_H__
#define __QUANTKIT_INSTRUMENTTYPE_H__

namespace QuantKit {

enum InstrumentType : unsigned char
{
	Stock,
	Future,
	Option,
	FutureOption,
	Bond,
	FX,
	Index,
	ETF,
	MultiLeg,
	Synthetic
};

} // namespace QuantKit

#endif // __QUANTKIT_INSTRUMENTTYPE_H__
