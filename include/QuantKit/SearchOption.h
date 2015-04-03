#ifndef __QUANTKIT_SEARCHOPTION_H__
#define __QUANTKIT_SEARCHOPTION_H__

namespace QuantKit {

enum class SearchOption : unsigned char
{
	Next,
	Prev,
	ExactFirst,
	ExactLast
};

} // namespace QuantKit

#endif // __QUANTKIT_SEARCHOPTION_H__
