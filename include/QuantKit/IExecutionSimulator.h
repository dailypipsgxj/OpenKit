#ifndef __QUANTKIT_IEXECUTIONSIMULATOR_H__
#define __QUANTKIT_IEXECUTIONSIMULATOR_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>

#include <QuantKit/IProvider.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/ICommissionProvider.h>
#include <QuantKit/ISlippageProvider.h>

namespace QuantKit {

class BarFilter;
class Bid;
class Ask;
class Level2Snapshot;
class Level2Update;
class Trade;
class Bar;

class QUANTKIT_EXPORT IExecutionSimulator : public IProvider , public IExecutionProvider
{
public:
	virtual bool fillOnQuote() const = 0;
	virtual void setFillOnQuote(bool value) = 0;
	virtual bool fillOnTrade() const = 0;
	virtual void setFillOnTrade(bool value) = 0;
	virtual bool fillOnBar() const = 0;
	virtual void setFillOnBar(bool value) = 0;
	virtual bool fillOnBarOpen() const = 0;
	virtual void setFillOnBarOpen(bool value) = 0;
	virtual bool fillOnLevel2() const = 0;
	virtual void setFillOnLevel2(bool value) = 0;
	virtual bool fillMarketOnNext() const = 0;
	virtual void setFillMarketOnNext(bool value) = 0;
	virtual bool fillLimitOnNext() const = 0;
	virtual void setFillLimitOnNext(bool value) = 0;
	virtual bool fillStopOnNext() const = 0;
	virtual void setFillStopOnNext(bool value) = 0;
	virtual bool fillStopLimitOnNext() const = 0;
	virtual void setFillStopLimitOnNext(bool value) = 0;
	virtual bool fillAtLimitPrice() const = 0;
	virtual void setFillAtLimitPrice(bool value) = 0;
	virtual bool fillAtStopPrice() const = 0;
	virtual void setFillAtStopPrice(bool value) = 0;
	virtual bool partialFills() const = 0;
	virtual void setPartialFills(bool value) = 0;
	virtual bool queued() const = 0;
	virtual void setQueued(bool value) = 0;
	virtual BarFilter barFilter() const = 0;
	virtual ICommissionProvider commissionProvider() const = 0;
	virtual void setCommissionProvider(const ICommissionProvider& value) = 0;
	virtual ISlippageProvider slippageProvider() const = 0;
	virtual void setSlippageProvider(const ISlippageProvider& value) = 0;
	virtual void clear() = 0;
	virtual void onAsk(const Ask& ask) = 0;
	virtual void onBar(const Bar& bar) = 0;
	virtual void onBarOpen(const Bar& bar) = 0;
	virtual void onBid(const Bid& bid) = 0;
	virtual void onLevel2(const Level2Snapshot& snapshot) = 0;
	virtual void onLevel2(const Level2Update& update) = 0;
	virtual void onTrade(const Trade& trade) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IEXECUTIONSIMULATOR_H__
