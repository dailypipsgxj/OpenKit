#ifndef __QUANTKIT_EXECTYPE_H__
#define __QUANTKIT_EXECTYPE_H__

namespace QuantKit {

enum class ExecType : unsigned char
{
	ExecNew,
	ExecRejected,
	ExecTrade,
	ExecPendingCancel,
	ExecCancelled,
	ExecCancelReject,
	ExecPendingReplace,
	ExecReplace,
	ExecReplaceReject
};

} // namespace QuantKit

#endif // __QUANTKIT_EXECTYPE_H__
