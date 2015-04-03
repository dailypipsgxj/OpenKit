#ifndef __QUANTKIT_EXECUTIONCOMMANDTYPE_H__
#define __QUANTKIT_EXECUTIONCOMMANDTYPE_H__

namespace QuantKit {

enum class ExecutionCommandType : unsigned char
{
	Send,
	Cancel,
	Replace
};

} // namespace QuantKit

#endif // __QUANTKIT_EXECUTIONCOMMANDTYPE_H__
