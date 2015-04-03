#ifndef __QUANTKIT_ORDERSTATUS_H__
#define __QUANTKIT_ORDERSTATUS_H__

namespace QuantKit {

enum OrderStatus : unsigned char
{
	NotSent,
	PendingNew,
	New,
	Rejected,
	PartiallyFilled,
	Filled,
	PendingCancel,
	Cancelled,
	Expired,
	PendingReplace,
	Replaced
};

} // namespace QuantKit

#endif // __QUANTKIT_ORDERSTATUS_H__
