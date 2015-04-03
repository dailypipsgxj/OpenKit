#ifndef __QUANTKIT_ACCOUNTDATATYPE_H__
#define __QUANTKIT_ACCOUNTDATATYPE_H__

namespace QuantKit {

enum class AccountDataType : unsigned char
{
	AccountValue,
	Position,
	Order
};

} // namespace QuantKit

#endif // __QUANTKIT_ACCOUNTDATATYPE_H__
