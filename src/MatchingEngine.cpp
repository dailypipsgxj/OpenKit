#include <QuantKit/MatchingEngine.h>

#include <QuantKit/BarFilter.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Event/ExecutionCommand.h>
#include <QuantKit/Event/Order.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/OrderBook.h>
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Event/Level2Snapshot.h>
#include <QuantKit/Event/Level2Update.h>
#include <QuantKit/IdArray.h>
#include "Provider_p.h"

namespace QuantKit {

class MatchingEnginePrivate : public ProviderPrivate
{
public:
	IdArray<QList<Order>> m_idArray;
	bool m_fillOnQuote;
	bool m_fillOnTrade;
	bool m_fillOnBar;
	bool m_fillOnBarOpen;
	bool m_fillOnLevel2;
	bool m_fillMarketOnNext;
	bool m_fillLimitOnNext;
	bool m_fillStopOnNext;
	bool m_fillStopLimitOnNext;
	bool m_fillAtLimitPrice;
	bool m_fillAtStopPrice;
	bool m_partialFills;
	bool m_queued;
	bool m_addQueueToOrderText;
	BarFilter m_barFilter;
	ICommissionProvider m_commissionProvider;
	ISlippageProvider m_slippageProvider;

public:
	explicit MatchingEnginePrivate(const Framework& framework);
	virtual ~MatchingEnginePrivate();

public:
	BarFilter barFilter() const { return m_barFilter; }
	ICommissionProvider commissionProvider() const { return m_commissionProvider; }
	void setCommissionProvider(const ICommissionProvider& value) { m_commissionProvider = value; }
	ISlippageProvider slippageProvider() const { return m_slippageProvider; }
	void setSlippageProvider(const ISlippageProvider& value) { m_slippageProvider = value; }
	bool fillOnQuote() const { return m_fillOnQuote; }
	void setFillOnQuote(bool value) { m_fillOnQuote = value; }
	bool fillOnTrade() const { return m_fillOnTrade; }
	void setFillOnTrade(bool value) { m_fillOnTrade = value; }
	bool fillOnBar() const { return m_fillOnBar; }
	void setFillOnBar(bool value) { m_fillOnBar = value; }
	bool fillOnBarOpen() const { return m_fillOnBarOpen; }
	void setFillOnBarOpen(bool value) { m_fillOnBarOpen = value; }
	bool fillOnLevel2() const { return m_fillOnLevel2; }
	void setFillOnLevel2(bool value) { m_fillOnLevel2 = value; }
	bool fillMarketOnNext() const { return m_fillMarketOnNext; }
	void setFillMarketOnNext(bool value) { m_fillMarketOnNext = value; }
	bool fillLimitOnNext() const { return m_fillLimitOnNext; }
	void setFillLimitOnNext(bool value) { m_fillLimitOnNext = value; }
	bool fillStopOnNext() const { return m_fillStopOnNext; }
	void setFillStopOnNext(bool value) { m_fillStopOnNext = value; }
	bool fillStopLimitOnNext() const { return m_fillStopLimitOnNext; }
	void setFillStopLimitOnNext(bool value) { m_fillStopLimitOnNext = value; }
	bool fillAtLimitPrice() const { return m_fillAtLimitPrice; }
	void setFillAtLimitPrice(bool value) { m_fillAtLimitPrice = value; }
	bool fillAtStopPrice() const { return m_fillAtStopPrice; }
	void setFillAtStopPrice(bool value) { m_fillAtStopPrice = value; }
	bool partialFills() const { return m_partialFills; }
	void setPartialFills(bool value) { m_partialFills = value; }
	bool queued() const { return m_queued; }
	void setQueued(bool value) { m_queued = value; }
	bool addQueueToOrderText() const { return m_addQueueToOrderText; }
	void setAddQueueToOrderText(bool value) { m_addQueueToOrderText = value; }
	void clear() { m_idArray.Clear(); }
	virtual void connect() Q_DECL_OVERRIDE
	{
		base.setStatus() = ProviderStatus.Connected;
	}

	virtual void disconnect() Q_DECL_OVERRIDE
	{
		base.setStatus() = ProviderStatus.Disconnected;
	}

	void fill(const Order& order, double price, int size);
	void onAsk(const Ask& ask);
	void onBar(const Bar& bar);
	void onBarOpen(const Bar& bar);
	void onBid(const Bid& bid);
	void onLevel2(const Level2Snapshot& snapshot);
	void onLevel2(const Level2Update& update);
	void onTrade(const Trade& trade);
	virtual void send(const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual MatchingEnginePrivate* clone() Q_DECL_OVERRIDE { return new MatchingEnginePrivate(*this); }
//private:
	void method_10(int int);
	void method_11(const Order& order);
	void method_12(const Order& order);
	void method_4(const Order& order);
	void method_5(const Order& order);
	void method_6(const ExecutionCommand& executionCommand);
	void method_7(const Order& order, const Trade& trade);
	void method_8(const Order& order, const Bid& bid, const Ask& ask);
	void method_9(const Order& order, const OrderBook& orderBook);
};

} // namepsace QuantKit


using namespace QuantKit;

MatchingEnginePrivate::MatchingEnginePrivate(const Framework& framework)
	: ProviderPrivate (framework)
	, m_idArray(new IdArray<QList<Order>>(1000))
	, m_fillOnQuote(true)
	, m_fillOnTrade(false)
	, m_fillOnBar(false)
	, m_fillOnLevel2(false)
	, m_fillMarketOnNext(false)
	, m_fillLimitOnNext(false)
	, m_fillStopOnNext(false)
	, m_fillStopLimitOnNext(false)
	, m_fillAtLimitPrice(true)
	, m_queued(true)
	, m_addQueueToOrderText(false)
	, m_barFilter(new BarFilter())
	, m_commissionProvider(new CommissionProvider())
	, m_slippageProvider(new SlippageProvider())
{
		m_id = 99;
		m_name = "MatchingEngine";
}

MatchingEnginePrivate::~MatchingEnginePrivate ()
{
}

void MatchingEnginePrivate::fill(const Order& order, double price, int size)
{
	if ((double)size < order.leavesQty())
	{
		base.EmitExecutionReport(new ExecutionReport
		{
			m_entryDate = framework.clock().dateTime(),
			m_order = order,
			m_orderId = order.id(),
			m_ordType = order.type(),
			m_side = order.side(),
			m_instrument = order.instrument(),
			m_instrumentId = order.instrument().id(),
			m_ordQty = order.qty(),
			m_execType = ExecType.ExecTrade,
			m_ordStatus = OrderStatus.PartiallyFilled,
			m_currencyId = order.instrument().currencyId(),
			m_cumQty = order.qty() + (double)size,
			m_lastQty = (double)size,
			m_leavesQty = order.leavesQty() - (double)size,
			m_lastPx = price,
			m_avgPx = (order.avgPx() * order.cumQty() + price * (double)size) / (order.cumQty() + (double)size),
			m_text = order.text()
		}, m_queued);
		return;
	}
	m_idArray[order.instrument().id()].Remove(order);
	base.EmitExecutionReport(new ExecutionReport
	{
		m_entryDate = framework.clock().dateTime(),
		m_order = order,
		m_orderId = order.id(),
		m_ordType = order.type(),
		m_side = order.side(),
		m_instrument = order.instrument(),
		m_instrumentId = order.instrument().id(),
		m_ordQty = order.qty(),
		m_execType = ExecType.ExecTrade,
		m_ordStatus = OrderStatus.Filled,
		m_currencyId = order.instrument().currencyId(),
		m_cumQty = order.qty(),
		m_lastQty = order.qty(),
		m_leavesQty = 0.0,
		m_lastPx = price,
		m_avgPx = price,
		m_text = order.text()
	}, m_queued);
}

void MatchingEnginePrivate::onAsk(const Ask& ask)
{
	if (m_idArray[ask.instrumentId()] == null)
	{
		return;
	}
	for (int i = 0; i < m_idArray[ask.instrumentId()].Count; i++)
	{
		Order order = m_idArray[ask.instrumentId()][i];
		method_8(order, framework.dataManager().GetBid(order.instrument()), ask);
		if (m_addQueueToOrderText)
		{
			order.setText() = order.double_6().ToString();
		}
	}
}

void MatchingEnginePrivate::onBar(const Bar& bar)
{
}

void MatchingEnginePrivate::onBarOpen(const Bar& bar)
{
}

void MatchingEnginePrivate::onBid(const Bid& bid)
{
	if (m_idArray[bid.instrumentId()] == null)
	{
		return;
	}
	for (int i = 0; i < m_idArray[bid.instrumentId()].Count; i++)
	{
		Order order = m_idArray[bid.instrumentId()][i];
		method_8(order, bid, framework.dataManager().GetAsk(order.instrument()));
		if (m_addQueueToOrderText)
		{
			order.setText() = order.double_6().ToString();
		}
	}
}

void MatchingEnginePrivate::onLevel2(const Level2Snapshot& snapshot)
{
	if (m_idArray[snapshot.int_0()] == null)
	{
		return;
	}
	for (int i = 0; i < m_idArray[snapshot.int_0()].Count; i++)
	{
		Order order = m_idArray[snapshot.int_0()][i];
		method_9(order, framework.dataManager().GetOrderBook(order.instrument()));
		if (m_addQueueToOrderText)
		{
			order.setText() = order.double_6().ToString();
		}
	}
}

void MatchingEnginePrivate::onLevel2(const Level2Update& update)
{
}

void MatchingEnginePrivate::onTrade(const Trade& trade)
{
	if (m_idArray[trade.instrumentId()] == null)
	{
		return;
	}
	for (int i = 0; i < m_idArray[trade.instrumentId()].Count; i++)
	{
		Order order = m_idArray[trade.instrumentId()][i];
		if (!order.bool_0())
		{
			method_7(order, trade);
		}
		if (m_addQueueToOrderText)
		{
			order.setText() = order.double_6().ToString();
		}
	}
}

void MatchingEnginePrivate::send(const ExecutionCommand& command)
{
	switch (command.type())
	{
		case ExecutionCommandType.Send:
			method_4(command.order());
			return;
		case ExecutionCommandType.Cancel:
			method_5(command.order());
			return;
		case ExecutionCommandType.Replace:
			method_6(command);
			return;
		default:
			return;
	}
}

void MatchingEnginePrivate::method_10(int int)
{
	for (int i = m_idArray[@int].Count - 1; i >= 0; i--)
	{
		if (m_idArray[@int][i].isDone())
		{
			m_idArray[@int].RemoveAt(i);
		}
	}
}

void MatchingEnginePrivate::method_11(const Order& order)
{
	Bid bid = framework.dataManager().GetBid(order.instrument());
	Ask ask = framework.dataManager().GetAsk(order.instrument());
	order.setBool_1() = true;
	order.setDouble_6() = 0.0;
	if (order.type() == OrderType.Limit)
	{
		if (order.side() == OrderSide.Buy && bid != null)
		{
			if (order.price() == bid.price())
			{
				order.setDouble_6() = (double)bid.size() + order.qty();
				order.setBool_0() = false;
				return;
			}
			order.setDouble_6() = (double)bid.size() + order.qty();
			order.setBool_0() = true;
			return;
		}
		else
		{
			if (order.side() == OrderSide.Sell && ask != null)
			{
				if (order.price() == ask.price())
				{
					order.setDouble_6() = (double)ask.size() + order.qty();
					order.setBool_0() = false;
					return;
				}
				order.setDouble_6() = (double)ask.size() + order.qty();
				order.setBool_0() = true;
			}
		}
	}
}

void MatchingEnginePrivate::method_12(const Order& order)
{
	OrderBook orderBook = framework.dataManager().GetOrderBook(order.instrument());
	order.setBool_1() = true;
	order.setDouble_6() = 0.0;
	if (order.type() == OrderType.Limit)
	{
		if (order.side() == OrderSide.Buy && orderBook.bids().Count > 0)
		{
			for (int i = 0; i < orderBook.bids().Count; i++)
			{
				Tick tick = orderBook.bids()[i];
				order.setDouble_6() = (double)tick.size() + order.qty();
				order.setBool_0() = true;
				if (order.price() == tick.price())
				{
					order.setBool_0() = false;
					return;
				}
			}
			return;
		}
		if (order.side() == OrderSide.Sell && orderBook.asks().Count > 0)
		{
			for (int j = 0; j < orderBook.asks().Count; j++)
			{
				Tick tick2 = orderBook.asks()[j];
				order.setDouble_6() = (double)tick2.size() + order.qty();
				order.setBool_0() = true;
				if (order.price() == tick2.price())
				{
					order.setBool_0() = false;
					return;
				}
			}
		}
	}
}

void MatchingEnginePrivate::method_4(const Order& order)
{
	base.EmitExecutionReport(new ExecutionReport
	{
		m_entryDate = framework.clock().dateTime(),
		m_order = order,
		m_orderId = order.id(),
		m_instrument = order.instrument(),
		m_instrumentId = order.instrument().id(),
		m_ordQty = order.qty(),
		m_execType = ExecType.ExecNew,
		m_ordStatus = OrderStatus.New,
		m_currencyId = order.instrument().currencyId(),
		m_ordType = order.type(),
		m_side = order.side(),
		m_cumQty = 0.0,
		m_lastQty = 0.0,
		m_leavesQty = 0.0,
		m_lastPx = 0.0,
		m_avgPx = 0.0
	}, m_queued);
	int id = order.instrument().id();
	if (m_idArray[id] == null)
	{
		m_idArray[id] = new List<Order>();
	}
	m_idArray[id].Add(order);
	if (m_fillOnQuote)
	{
		if (!m_fillMarketOnNext && !m_fillLimitOnNext)
		{
			method_11(order);
			if (m_addQueueToOrderText)
			{
				order.setText() = order.double_6().ToString();
			}
			method_8(order, framework.dataManager().GetBid(order.instrument()), framework.dataManager().GetAsk(order.instrument()));
			return;
		}
	}
	else
	{
		if (m_fillOnLevel2 && !m_fillMarketOnNext && !m_fillLimitOnNext)
		{
			method_12(order);
			if (m_addQueueToOrderText)
			{
				order.setText() = order.double_6().ToString();
			}
			method_9(order, framework.dataManager().GetOrderBook(order.instrument()));
		}
	}
}

void MatchingEnginePrivate::method_5(const Order& order)
{
	m_idArray[order.instrument().id()].Remove(order);
	base.EmitExecutionReport(new ExecutionReport
	{
		m_entryDate = framework.clock().dateTime(),
		m_order = order,
		m_orderId = order.id(),
		m_instrument = order.instrument(),
		m_instrumentId = order.instrument().id(),
		m_ordQty = order.qty(),
		m_execType = ExecType.ExecCancelled,
		m_ordStatus = OrderStatus.Cancelled,
		m_currencyId = order.instrument().currencyId(),
		m_ordType = order.type(),
		m_side = order.side(),
		m_cumQty = order.cumQty(),
		m_lastQty = 0.0,
		m_leavesQty = order.leavesQty(),
		m_lastPx = 0.0,
		m_avgPx = 0.0
	}, m_queued);
}

void MatchingEnginePrivate::method_6(const ExecutionCommand& executionCommand)
{
	Order order = executionCommand.order();
	base.EmitExecutionReport(new ExecutionReport
	{
		m_entryDate = framework.clock().dateTime(),
		m_order = order,
		m_orderId = order.id(),
		m_instrument = order.instrument(),
		m_instrumentId = order.instrument().id(),
		m_ordQty = order.qty(),
		m_execType = ExecType.ExecReplace,
		m_ordStatus = OrderStatus.Replaced,
		m_currencyId = order.instrument().currencyId(),
		m_ordType = order.type(),
		m_side = order.side(),
		m_cumQty = order.cumQty(),
		m_lastQty = 0.0,
		m_leavesQty = order.leavesQty(),
		m_lastPx = 0.0,
		m_avgPx = 0.0,
		m_ordType = order.type(),
		m_price = executionCommand.price(),
		m_stopPx = order.stopPx(),
		m_ordQty = order.qty()
	}, m_queued);
}

void MatchingEnginePrivate::method_7(const Order& order, const Trade& trade)
{
	if (!order.bool_1())
	{
		return;
	}
	if (order.type() == OrderType.Limit && order.price() == trade.price())
	{
		order.setDouble_6() -= (double)trade.size();
		if (order.double_6() < order.leavesQty())
		{
			if (order.double_6() > 0.0)
			{
				double num = order.leavesQty() - order.double_6();
				Fill(order, order.price(), (int)num);
				return;
			}
			if (order.double_6() < 0.0)
			{
				order.setDouble_6() = 0.0;
				Fill(order, order.price(), (int)order.leavesQty());
			}
		}
	}
}

void MatchingEnginePrivate::method_8(const Order& order, const Bid& bid, const Ask& ask)
{
	if (ask != null && bid != null)
	{
		if (!order.bool_1())
		{
			method_11(order);
		}
		if (order.type() == OrderType.Limit)
		{
			if (order.bool_0())
			{
				double double_ = order.double_6();
				method_11(order);
				if (order.bool_0())
				{
					order.setDouble_6() = double_;
				}
			}
			if (order.side() == OrderSide.Buy)
			{
				if (bid.price() < order.price())
				{
					order.setDouble_6() = 0.0;
					Fill(order, order.price(), (int)order.leavesQty());
					return;
				}
				if (bid.price() == order.price() && order.double_6() > (double)bid.size() + order.qty())
				{
					order.setDouble_6() = (double)bid.size() + order.qty();
					return;
				}
			}
			else
			{
				if (order.side() == OrderSide.Sell)
				{
					if (ask.price() > order.price())
					{
						order.setDouble_6() = 0.0;
						Fill(order, order.price(), (int)order.leavesQty());
						return;
					}
					if (ask.price() == order.price() && order.double_6() > (double)ask.size() + order.qty())
					{
						order.setDouble_6() = (double)ask.size() + order.qty();
						return;
					}
				}
			}
		}
		else
		{
			if (order.side() == OrderSide.Buy)
			{
				if ((double)ask.size() >= order.qty())
				{
					Fill(order, ask.price(), (int)order.leavesQty());
					return;
				}
				Fill(order, ask.price(), ask.size());
				if (order.leavesQty() > 0.0)
				{
					double num = ask.price() + order.instrument().tickSize();
					double num2 = Math.Ceiling(order.leavesQty() / (double)ask.size());
					if (num2 >= 1.0)
					{
						int num3 = 0;
						while ((double)num3 < num2)
						{
							if (order.leavesQty() >= (double)ask.size())
							{
								Fill(order, num + (double)num3 * order.instrument().tickSize(), ask.size());
							}
							else
							{
								if (order.leavesQty() < (double)ask.size())
								{
									Fill(order, num + (double)num3 * order.instrument().tickSize(), (int)order.leavesQty());
									return;
								}
							}
							num3++;
						}
						return;
					}
					Fill(order, num, (int)order.leavesQty());
					return;
				}
			}
			else
			{
				if (order.side() == OrderSide.Sell)
				{
					if ((double)bid.size() >= order.leavesQty())
					{
						Fill(order, bid.price(), (int)order.leavesQty());
						return;
					}
					Fill(order, bid.price(), bid.size());
					if (order.leavesQty() > 0.0)
					{
						double num4 = bid.price() - order.instrument().tickSize();
						double num5 = Math.Ceiling(order.leavesQty() / (double)bid.size());
						if (num5 >= 1.0)
						{
							int num6 = 0;
							while ((double)num6 < num5)
							{
								if (order.leavesQty() >= (double)bid.size())
								{
									Fill(order, num4 - (double)num6 * order.instrument().tickSize(), bid.size());
								}
								else
								{
									if (order.leavesQty() < (double)bid.size())
									{
										Fill(order, num4 - (double)num6 * order.instrument().tickSize(), (int)order.leavesQty());
										return;
									}
								}
								num6++;
							}
							return;
						}
						Fill(order, num4, (int)order.leavesQty());
					}
				}
			}
		}
		return;
	}
}

void MatchingEnginePrivate::method_9(const Order& order, const OrderBook& orderBook)
{
	if (!order.bool_1())
	{
		method_12(order);
	}
	if (order.type() == OrderType.Limit)
	{
		if (orderBook.bids().Count == 0 || orderBook.asks().Count == 0)
		{
			return;
		}
		if (order.bool_0())
		{
			double double_ = order.double_6();
			method_12(order);
			if (order.bool_0())
			{
				order.setDouble_6() = double_;
			}
		}
		if (order.side() == OrderSide.Buy)
		{
			if (orderBook.bids()[0].price() < order.price())
			{
				order.setDouble_6() = 0.0;
				Fill(order, orderBook.bids()[0].price(), (int)order.leavesQty());
				return;
			}
			Tick tick = null;
			for (int i = 0; i < orderBook.bids().Count; i++)
			{
				tick = orderBook.bids()[i];
				if (tick.price() == order.price())
				{
					break;
				}
			}
			if (tick != null && order.double_6() > (double)tick.size() + order.qty())
			{
				order.setDouble_6() = (double)tick.size() + order.qty();
				return;
			}
		}
		else
		{
			if (order.side() == OrderSide.Sell)
			{
				if (orderBook.asks()[0].price() > order.price())
				{
					order.setDouble_6() = 0.0;
					Fill(order, orderBook.asks()[0].price(), (int)order.leavesQty());
					return;
				}
				Tick tick2 = null;
				for (int j = 0; j < orderBook.asks().Count; j++)
				{
					tick2 = orderBook.asks()[j];
					if (tick2.price() == order.price())
					{
						break;
					}
				}
				if (tick2 != null && order.double_6() > (double)tick2.size() + order.qty())
				{
					order.setDouble_6() = (double)tick2.size() + order.qty();
					return;
				}
			}
		}
	}
	else
	{
		if (order.side() == OrderSide.Buy && orderBook.asks().Count > 0)
		{
			Tick tick3 = null;
			int k = 0;
			while (k < orderBook.asks().Count)
			{
				tick3 = orderBook.asks()[k];
				if ((double)tick3.size() < order.leavesQty())
				{
					Fill(order, tick3.price(), tick3.size());
					k++;
				}
				else
				{
					Fill(order, tick3.price(), (int)order.leavesQty());
					IL_25F:
					if (tick3 == null || order.leavesQty() <= 0.0)
					{
						return;
					}
					double num = tick3.price() + order.instrument().tickSize();
					double num2 = Math.Ceiling(order.leavesQty() / (double)tick3.size());
					if (num2 >= 1.0)
					{
						int num3 = 0;
						while ((double)num3 < num2)
						{
							if (order.leavesQty() >= (double)tick3.size())
							{
								Fill(order, num + (double)num3 * order.instrument().tickSize(), tick3.size());
							}
							else
							{
								if (order.leavesQty() < (double)tick3.size())
								{
									Fill(order, num + (double)num3 * order.instrument().tickSize(), (int)order.leavesQty());
									return;
								}
							}
							num3++;
						}
						return;
					}
					Fill(order, num, (int)order.leavesQty());
					return;
				}
			}
			goto IL_25F;
		}
		if (order.side() == OrderSide.Sell && orderBook.bids().Count > 0)
		{
			Tick tick4 = null;
			int l = 0;
			while (l < orderBook.bids().Count)
			{
				tick4 = orderBook.bids()[l];
				if ((double)tick4.size() < order.leavesQty())
				{
					Fill(order, tick4.price(), tick4.size());
					l++;
				}
				else
				{
					Fill(order, tick4.price(), (int)order.leavesQty());
					IL_3BE:
					if (tick4 == null || order.leavesQty() <= 0.0)
					{
						return;
					}
					double num4 = tick4.price() - order.instrument().tickSize();
					double num5 = Math.Ceiling(order.leavesQty() / (double)tick4.size());
					if (num5 >= 1.0)
					{
						int num6 = 0;
						while ((double)num6 < num5)
						{
							if (order.leavesQty() >= (double)tick4.size())
							{
								Fill(order, num4 - (double)num6 * order.instrument().tickSize(), tick4.size());
							}
							else
							{
								if (order.leavesQty() < (double)tick4.size())
								{
									Fill(order, num4 - (double)num6 * order.instrument().tickSize(), (int)order.leavesQty());
									return;
								}
							}
							num6++;
						}
						return;
					}
					Fill(order, num4, (int)order.leavesQty());
					return;
				}
			}
			goto IL_3BE;
		}
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(MatchingEngine)

MatchingEngine::MatchingEngine(const Framework& framework)
	: Provider(*new MatchingEnginePrivate(framework))
{
}

MatchingEngine::~MatchingEngine()
{
}

BarFilter MatchingEngine::barFilter() const
{
	Q_D(const MatchingEngine);
	return d->barFilter();
}

ICommissionProvider MatchingEngine::commissionProvider() const
{
	Q_D(const MatchingEngine);
	return d->commissionProvider();
}

void MatchingEngine::setCommissionProvider(const ICommissionProvider& value)
{
	Q_D(MatchingEngine);
	d->setCommissionProvider(value);
}

ISlippageProvider MatchingEngine::slippageProvider() const
{
	Q_D(const MatchingEngine);
	return d->slippageProvider();
}

void MatchingEngine::setSlippageProvider(const ISlippageProvider& value)
{
	Q_D(MatchingEngine);
	d->setSlippageProvider(value);
}

bool MatchingEngine::fillOnQuote() const
{
	Q_D(const MatchingEngine);
	return d->fillOnQuote();
}

void MatchingEngine::setFillOnQuote(bool value)
{
	Q_D(MatchingEngine);
	d->setFillOnQuote(value);
}

bool MatchingEngine::fillOnTrade() const
{
	Q_D(const MatchingEngine);
	return d->fillOnTrade();
}

void MatchingEngine::setFillOnTrade(bool value)
{
	Q_D(MatchingEngine);
	d->setFillOnTrade(value);
}

bool MatchingEngine::fillOnBar() const
{
	Q_D(const MatchingEngine);
	return d->fillOnBar();
}

void MatchingEngine::setFillOnBar(bool value)
{
	Q_D(MatchingEngine);
	d->setFillOnBar(value);
}

bool MatchingEngine::fillOnBarOpen() const
{
	Q_D(const MatchingEngine);
	return d->fillOnBarOpen();
}

void MatchingEngine::setFillOnBarOpen(bool value)
{
	Q_D(MatchingEngine);
	d->setFillOnBarOpen(value);
}

bool MatchingEngine::fillOnLevel2() const
{
	Q_D(const MatchingEngine);
	return d->fillOnLevel2();
}

void MatchingEngine::setFillOnLevel2(bool value)
{
	Q_D(MatchingEngine);
	d->setFillOnLevel2(value);
}

bool MatchingEngine::fillMarketOnNext() const
{
	Q_D(const MatchingEngine);
	return d->fillMarketOnNext();
}

void MatchingEngine::setFillMarketOnNext(bool value)
{
	Q_D(MatchingEngine);
	d->setFillMarketOnNext(value);
}

bool MatchingEngine::fillLimitOnNext() const
{
	Q_D(const MatchingEngine);
	return d->fillLimitOnNext();
}

void MatchingEngine::setFillLimitOnNext(bool value)
{
	Q_D(MatchingEngine);
	d->setFillLimitOnNext(value);
}

bool MatchingEngine::fillStopOnNext() const
{
	Q_D(const MatchingEngine);
	return d->fillStopOnNext();
}

void MatchingEngine::setFillStopOnNext(bool value)
{
	Q_D(MatchingEngine);
	d->setFillStopOnNext(value);
}

bool MatchingEngine::fillStopLimitOnNext() const
{
	Q_D(const MatchingEngine);
	return d->fillStopLimitOnNext();
}

void MatchingEngine::setFillStopLimitOnNext(bool value)
{
	Q_D(MatchingEngine);
	d->setFillStopLimitOnNext(value);
}

bool MatchingEngine::fillAtLimitPrice() const
{
	Q_D(const MatchingEngine);
	return d->fillAtLimitPrice();
}

void MatchingEngine::setFillAtLimitPrice(bool value)
{
	Q_D(MatchingEngine);
	d->setFillAtLimitPrice(value);
}

bool MatchingEngine::fillAtStopPrice() const
{
	Q_D(const MatchingEngine);
	return d->fillAtStopPrice();
}

void MatchingEngine::setFillAtStopPrice(bool value)
{
	Q_D(MatchingEngine);
	d->setFillAtStopPrice(value);
}

bool MatchingEngine::partialFills() const
{
	Q_D(const MatchingEngine);
	return d->partialFills();
}

void MatchingEngine::setPartialFills(bool value)
{
	Q_D(MatchingEngine);
	d->setPartialFills(value);
}

bool MatchingEngine::queued() const
{
	Q_D(const MatchingEngine);
	return d->queued();
}

void MatchingEngine::setQueued(bool value)
{
	Q_D(MatchingEngine);
	d->setQueued(value);
}

bool MatchingEngine::addQueueToOrderText() const
{
	Q_D(const MatchingEngine);
	return d->addQueueToOrderText();
}

void MatchingEngine::setAddQueueToOrderText(bool value)
{
	Q_D(MatchingEngine);
	d->setAddQueueToOrderText(value);
}

void MatchingEngine::clear()
{
	Q_D(MatchingEngine);
	d->clear();
}

void MatchingEngine::fill(const Order& order, double price, int size)
{
	Q_D(MatchingEngine);
	d->fill(order, price, size);
}

void MatchingEngine::onAsk(const Ask& ask)
{
	Q_D(MatchingEngine);
	d->onAsk(ask);
}

void MatchingEngine::onBar(const Bar& bar)
{
	Q_D(MatchingEngine);
	d->onBar(bar);
}

void MatchingEngine::onBarOpen(const Bar& bar)
{
	Q_D(MatchingEngine);
	d->onBarOpen(bar);
}

void MatchingEngine::onBid(const Bid& bid)
{
	Q_D(MatchingEngine);
	d->onBid(bid);
}

void MatchingEngine::onLevel2(const Level2Snapshot& snapshot)
{
	Q_D(MatchingEngine);
	d->onLevel2(snapshot);
}

void MatchingEngine::onLevel2(const Level2Update& update)
{
	Q_D(MatchingEngine);
	d->onLevel2(update);
}

void MatchingEngine::onTrade(const Trade& trade)
{
	Q_D(MatchingEngine);
	d->onTrade(trade);
}


