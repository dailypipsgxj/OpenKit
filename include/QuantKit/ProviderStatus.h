#ifndef __QUANTKIT_PROVIDERSTATUS_H__
#define __QUANTKIT_PROVIDERSTATUS_H__

namespace QuantKit {

enum class ProviderStatus : unsigned char
{
	Connecting,
	Connected,
	Disconnecting,
	Disconnected
};

} // namespace QuantKit

#endif // __QUANTKIT_PROVIDERSTATUS_H__
