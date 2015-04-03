#ifndef __QUANTKIT_REQUESTRESULT_H__
#define __QUANTKIT_REQUESTRESULT_H__

namespace QuantKit {

enum RequestResult : unsigned char
{
	Completed,
	Cancelled,
	Error
};

} // namespace QuantKit

#endif // __QUANTKIT_REQUESTRESULT_H__
