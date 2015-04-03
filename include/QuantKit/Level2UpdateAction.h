#ifndef __QUANTKIT_LEVEL2UPDATEACTION_H__
#define __QUANTKIT_LEVEL2UPDATEACTION_H__

namespace QuantKit {

enum Level2UpdateAction : unsigned char
{
	New,
	Change,
	Delete,
	Reset
};

} // namespace QuantKit

#endif // __QUANTKIT_LEVEL2UPDATEACTION_H__
