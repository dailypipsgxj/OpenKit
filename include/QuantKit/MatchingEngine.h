#ifndef __QUANTKIT_MATCHINGENGINE_H__
#define __QUANTKIT_MATCHINGENGINE_H__

#include <QuantKit/quantkit_global.h>
#include <QList>

#include <QuantKit/Provider.h>
#include <QuantKit/IProvider.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/IExecutionSimulator.h>
#include <QuantKit/ICommissionProvider.h>
#include <QuantKit/ISlippageProvider.h>

namespace QuantKit {

class MatchingEnginePrivate;

class BarFilter;
class Framework;
class ExecutionCommand;
class Order;
class Trade;
class Bid;
class Ask;
class OrderBook;
class Bar;
class Level2Snapshot;
class Level2Update;
class IdArray;

class QUANTKIT_EXPORT MatchingEngine Q_DECL_FINAL : public Provider , public IProvider , public IExecutionProvider , public IExecutionSimulator
{
public:
	explicit MatchingEngine(const Framework& framework);
	~MatchingEngine();

public:
	BarFilter barFilter() const;
	ICommissionProvider commissionProvider() const;
	void setCommissionProvider(const ICommissionProvider& value);
	ISlippageProvider slippageProvider() const;
	void setSlippageProvider(const ISlippageProvider& value);
	bool fillOnQuote() const;
	void setFillOnQuote(bool value);
	bool fillOnTrade() const;
	void setFillOnTrade(bool value);
	bool fillOnBar() const;
	void setFillOnBar(bool value);
	bool fillOnBarOpen() const;
	void setFillOnBarOpen(bool value);
	bool fillOnLevel2() const;
	void setFillOnLevel2(bool value);
	bool fillMarketOnNext() const;
	void setFillMarketOnNext(bool value);
	bool fillLimitOnNext() const;
	void setFillLimitOnNext(bool value);
	bool fillStopOnNext() const;
	void setFillStopOnNext(bool value);
	bool fillStopLimitOnNext() const;
	void setFillStopLimitOnNext(bool value);
	bool fillAtLimitPrice() const;
	void setFillAtLimitPrice(bool value);
	bool fillAtStopPrice() const;
	void setFillAtStopPrice(bool value);
	bool partialFills() const;
	void setPartialFills(bool value);
	bool queued() const;
	void setQueued(bool value);
	bool addQueueToOrderText() const;
	void setAddQueueToOrderText(bool value);
	void clear();
	void fill(const Order& order, double price, int size);
	void onAsk(const Ask& ask);
	void onBar(const Bar& bar);
	void onBarOpen(const Bar& bar);
	void onBid(const Bid& bid);
	void onLevel2(const Level2Snapshot& snapshot);
	void onLevel2(const Level2Update& update);
	void onTrade(const Trade& trade);

private:
	QK_DECLARE_PRIVATE(MatchingEngine)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::MatchingEngine)

#endif // __QUANTKIT_MATCHINGENGINE_H__
