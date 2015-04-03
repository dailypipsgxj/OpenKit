#ifndef __QUANTKIT_COMMISSIONTYPE_H__
#define __QUANTKIT_COMMISSIONTYPE_H__

namespace QuantKit {

enum class CommissionType : unsigned char
{
	PerShare,
	Percent,
	Absolute
};

} // namespace QuantKit

#endif // __QUANTKIT_COMMISSIONTYPE_H__
