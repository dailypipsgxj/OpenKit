#ifndef __QUANTKIT_STRATEGYMODE_H__
#define __QUANTKIT_STRATEGYMODE_H__

namespace QuantKit {

enum class StrategyMode : unsigned char
{
	Backtest = 1,
	Paper,
	Live
};

} // namespace QuantKit

#endif // __QUANTKIT_STRATEGYMODE_H__
