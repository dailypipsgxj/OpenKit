#include <QuantKit/ExecutionSimulator.h>

#include <QuantKit/BarFilter.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Event/ExecutionCommand.h>
#include <QuantKit/Event/Order.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Event/Level2Snapshot.h>
#include <QuantKit/Event/Level2Update.h>
#include <QuantKit/IdArray.h>
#include "Provider_p.h"

namespace QuantKit {

class ExecutionSimulatorPrivate : public ProviderPrivate
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
	BarFilter m_barFilter;
	ICommissionProvider m_commissionProvider;
	ISlippageProvider m_slippageProvider;
	QList<Order> list_0;
	TimeSpan m_auction1;
	TimeSpan m_auction2;

public:
	explicit ExecutionSimulatorPrivate(const Framework& framework);
	virtual ~ExecutionSimulatorPrivate();

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
	bool fillOnBarOpen() const { return m_fillOnBarOpen; }
	void setFillOnBarOpen(bool value) { m_fillOnBarOpen = value; }
	bool fillOnBar() const { return m_fillOnBar; }
	void setFillOnBar(bool value) { m_fillOnBar = value; }
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
	TimeSpan auction1() const { return m_auction1; }
	void setAuction1(const TimeSpan& value) { m_auction1 = value; }
	TimeSpan auction2() const { return m_auction2; }
	void setAuction2(const TimeSpan& value) { m_auction2 = value; }
	bool queued() const { return m_queued; }
	void setQueued(bool value) { m_queued = value; }
	void clear() { m_idArray.Clear(); }
	void fill(const Order& order, double price, int size);
	void onAsk(const Ask& ask);
	void onBar(const Bar& bar);
	void onBarOpen(const Bar& bar);
	void onBid(const Bid& bid);
	void onLevel2(const Level2Snapshot& snapshot);
	void onLevel2(const Level2Update& update);
	void onTrade(const Trade& trade);
	virtual void send(const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual ExecutionSimulatorPrivate* clone() Q_DECL_OVERRIDE { return new ExecutionSimulatorPrivate(*this); }
//private:
	bool method_10(const Order& order, const Trade& trade);
	bool method_11(const Order& order, const Bar& bar);
	void method_12(const QDateTime& dateTime, const QVariant& object);
	void method_13(const QDateTime& dateTime, const QVariant& object);
	bool method_14(const Order& order);
	void method_4(const Order& order);
	void method_5(const Order& order);
	void method_6(const ExecutionCommand& executionCommand);
	void method_7(int int);
	bool method_8(const Order& order, const Bid& bid);
	bool method_9(const Order& order, const Ask& ask);
};

} // namepsace QuantKit


using namespace QuantKit;

ExecutionSimulatorPrivate::ExecutionSimulatorPrivate(const Framework& framework)
	: ProviderPrivate (framework)
	, m_idArray(new IdArray<QList<Order>>(10000))
	, m_fillOnQuote(true)
	, m_fillOnTrade(true)
	, m_fillOnLevel2(true)
	, m_fillLimitOnNext(true)
	, m_fillStopOnNext(true)
	, m_fillStopLimitOnNext(true)
	, m_fillAtLimitPrice(true)
	, m_queued(true)
	, m_barFilter(new BarFilter())
	, m_commissionProvider(new CommissionProvider())
	, m_slippageProvider(new SlippageProvider())
	, list_0(new QList<Order>())
{
		m_id = 2;
		m_name = "ExecutionSimulator";
		m_description = "Default execution simulator";
		m_url = "www.smartquant.com";
}

ExecutionSimulatorPrivate::~ExecutionSimulatorPrivate ()
{
}

void ExecutionSimulatorPrivate::fill(const Order& order, double price, int size)
{
	if (!m_partialFills)
	{
		m_idArray[order.instrument().id()].Remove(order);
		ExecutionReport executionReport = new ExecutionReport();
		executionReport.setEntryDate() = framework.clock().dateTime();
		executionReport.setOrder() = order;
		executionReport.setOrderId() = order.id();
		executionReport.setOrdType() = order.type();
		executionReport.setSide() = order.side();
		executionReport.setInstrument() = order.instrument();
		executionReport.setInstrumentId() = order.instrument();
		executionReport.setOrdQty() = order.qty();
		executionReport.setPrice() = order.price();
		executionReport.setStopPx() = order.stopPx();
		executionReport.setTimeInForce() = order.timeInForce();
		executionReport.setExecType() = ExecType.ExecTrade;
		executionReport.setOrdStatus() = OrderStatus.Filled;
		executionReport.setCurrencyId() = order.instrument().currencyId();
		executionReport.setCumQty() = order.leavesQty();
		executionReport.setLastQty() = order.leavesQty();
		executionReport.setLeavesQty() = 0.0;
		executionReport.setLastPx() = price;
		executionReport.setText() = order.text();
		executionReport.setCommission() = m_commissionProvider.GetCommission(executionReport);
		executionReport.setLastPx() = m_slippageProvider.GetPrice(executionReport);
		base.EmitExecutionReport(executionReport, m_queued);
		return;
	}
	if (size <= 0)
	{
		Console.WriteLine("ExecutionSimulator::Fill Error - using partial fills, size can not be zero");
		return;
	}
	ExecutionReport executionReport2 = new ExecutionReport();
	executionReport2.setEntryDate() = framework.clock().dateTime();
	executionReport2.setOrder() = order;
	executionReport2.setOrderId() = order.id();
	executionReport2.setOrdType() = order.type();
	executionReport2.setSide() = order.side();
	executionReport2.setInstrument() = order.instrument();
	executionReport2.setInstrumentId() = order.instrument();
	executionReport2.setOrdQty() = order.qty();
	executionReport2.setPrice() = order.price();
	executionReport2.setStopPx() = order.stopPx();
	executionReport2.setTimeInForce() = order.timeInForce();
	executionReport2.setExecType() = ExecType.ExecTrade;
	executionReport2.setCurrencyId() = order.instrument().currencyId();
	if ((double)size >= order.leavesQty())
	{
		m_idArray[order.instrument().id()].Remove(order);
		executionReport2.setOrdStatus() = OrderStatus.Filled;
		executionReport2.setCumQty() = order.cumQty() + order.leavesQty();
		executionReport2.setLastQty() = order.leavesQty();
		executionReport2.setLeavesQty() = 0.0;
		executionReport2.setLastPx() = price;
		executionReport2.setText() = order.text();
		order.setLeavesQty() = executionReport2.leavesQty();
	}
	else
	{
		if ((double)size < order.leavesQty())
		{
			executionReport2.setOrdStatus() = OrderStatus.PartiallyFilled;
			executionReport2.setCumQty() = order.cumQty() + (double)size;
			executionReport2.setLastQty() = (double)size;
			executionReport2.setLeavesQty() = order.leavesQty() - (double)size;
			executionReport2.setLastPx() = price;
			executionReport2.setText() = order.text();
			order.setLeavesQty() = executionReport2.leavesQty();
		}
	}
	executionReport2.setCommission() = m_commissionProvider.GetCommission(executionReport2);
	executionReport2.setLastPx() = m_slippageProvider.GetPrice(executionReport2);
	base.EmitExecutionReport(executionReport2, m_queued);
}

void ExecutionSimulatorPrivate::onAsk(const Ask& ask)
{
	if (m_idArray[ask.instrumentId()] == null)
	{
		return;
	}
	if (m_fillOnQuote)
	{
		for (int i = 0; i < m_idArray[ask.instrumentId()].Count; i++)
		{
			Order order = m_idArray[ask.instrumentId()][i];
			method_9(order, ask);
		}
	}
}

void ExecutionSimulatorPrivate::onBar(const Bar& bar)
{
	if (m_idArray[bar.instrumentId()] == null)
	{
		return;
	}
	if (m_fillOnBar)
	{
		if (m_barFilter.count() != 0 && !m_barFilter.Contains(bar.type(), bar.size()))
		{
			return;
		}
		for (int i = 0; i < m_idArray[bar.instrumentId()].Count; i++)
		{
			Order order = m_idArray[bar.instrumentId()][i];
			method_11(order, bar);
		}
	}
}

void ExecutionSimulatorPrivate::onBarOpen(const Bar& bar)
{
	if (m_idArray[bar.instrumentId()] == null)
	{
		return;
	}
	if (m_fillOnBarOpen)
	{
		if (m_barFilter.count() != 0 && !m_barFilter.Contains(bar.type(), bar.size()))
		{
			return;
		}
		int i = 0;
		while (i < m_idArray[bar.instrumentId()].Count)
		{
			Order order = m_idArray[bar.instrumentId()][i];
			while (true)
			{
				switch (order.type())
				{
					case OrderType.Market:
						goto IL_13A;
					case OrderType.Stop:
						switch (order.side())
						{
							case OrderSide.Buy:
								if (bar.open() >= order.stopPx())
								{
									if (!m_fillAtStopPrice)
									{
										order.setType() = OrderType.Market;
										continue;
									}
									goto IL_153;
								}
								break;
							case OrderSide.Sell:
								if (bar.open() <= order.stopPx())
								{
									if (!m_fillAtStopPrice)
									{
										order.setType() = OrderType.Market;
										continue;
									}
									goto IL_16C;
								}
								break;
						}
						break;
					case OrderType.Limit:
						goto IL_185;
					case OrderType.StopLimit:
						switch (order.side())
						{
							case OrderSide.Buy:
								if (bar.open() >= order.stopPx())
								{
									order.setType() = OrderType.Limit;
									continue;
								}
								break;
							case OrderSide.Sell:
								if (bar.open() <= order.stopPx())
								{
									order.setType() = OrderType.Limit;
									continue;
								}
								break;
						}
						break;
				}
				break;
			}
			IL_221:
			i++;
			continue;
			goto IL_221;
			IL_13A:
			Fill(order, bar.open(), (int)bar.volume());
			goto IL_221;
			IL_153:
			Fill(order, order.stopPx(), (int)bar.volume());
			goto IL_221;
			IL_16C:
			Fill(order, order.stopPx(), (int)bar.volume());
			goto IL_221;
			IL_185:
			switch (order.side())
			{
				case OrderSide.Buy:
					if (bar.open() > order.price())
					{
						goto IL_221;
					}
					if (m_fillAtLimitPrice)
					{
						Fill(order, order.price(), (int)bar.volume());
						goto IL_221;
					}
					Fill(order, bar.open(), (int)bar.volume());
					goto IL_221;
				case OrderSide.Sell:
					if (bar.open() < order.price())
					{
						goto IL_221;
					}
					if (m_fillAtLimitPrice)
					{
						Fill(order, order.price(), (int)bar.volume());
						goto IL_221;
					}
					Fill(order, bar.open(), (int)bar.volume());
					goto IL_221;
				default:
					goto IL_221;
			}
		}
	}
}

void ExecutionSimulatorPrivate::onBid(const Bid& bid)
{
	if (m_idArray[bid.instrumentId()] == null)
	{
		return;
	}
	if (m_fillOnQuote)
	{
		for (int i = 0; i < m_idArray[bid.instrumentId()].Count; i++)
		{
			Order order = m_idArray[bid.instrumentId()][i];
			method_8(order, bid);
		}
	}
}

void ExecutionSimulatorPrivate::onLevel2(const Level2Snapshot& snapshot)
{
}

void ExecutionSimulatorPrivate::onLevel2(const Level2Update& update)
{
}

void ExecutionSimulatorPrivate::onTrade(const Trade& trade)
{
	if (m_idArray[trade.instrumentId()] == null)
	{
		return;
	}
	if (m_fillOnTrade)
	{
		for (int i = 0; i < m_idArray[trade.instrumentId()].Count; i++)
		{
			Order order = m_idArray[trade.instrumentId()][i];
			method_10(order, trade);
		}
	}
}

void ExecutionSimulatorPrivate::send(const ExecutionCommand& command)
{
	if (base.isDisconnected())
	{
		Connect();
	}
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

bool ExecutionSimulatorPrivate::method_10(const Order& order, const Trade& trade)
{
	while (true)
	{
		switch (order.type())
		{
			case OrderType.Market:
				goto IL_D2;
			case OrderType.Stop:
				switch (order.side())
				{
					case OrderSide.Buy:
						if (trade.price() >= order.stopPx())
						{
							if (!m_fillAtStopPrice)
							{
								order.setType() = OrderType.Market;
								continue;
							}
							goto IL_E7;
						}
						break;
					case OrderSide.Sell:
						if (trade.price() <= order.stopPx())
						{
							if (!m_fillAtStopPrice)
							{
								order.setType() = OrderType.Market;
								continue;
							}
							goto IL_FC;
						}
						break;
				}
				break;
			case OrderType.Limit:
				goto IL_111;
			case OrderType.StopLimit:
				switch (order.side())
				{
					case OrderSide.Buy:
						if (trade.price() >= order.stopPx())
						{
							order.setType() = OrderType.Limit;
							continue;
						}
						break;
					case OrderSide.Sell:
						if (trade.price() <= order.stopPx())
						{
							order.setType() = OrderType.Limit;
							continue;
						}
						break;
				}
				break;
		}
		break;
	}
	return false;
	IL_D2:
	Fill(order, trade.price(), trade.size());
	return true;
	IL_E7:
	Fill(order, order.stopPx(), trade.size());
	return true;
	IL_FC:
	Fill(order, order.stopPx(), trade.size());
	return true;
	IL_111:
	switch (order.side())
	{
		case OrderSide.Buy:
			if (trade.price() <= order.price())
			{
				if (m_fillAtLimitPrice)
				{
					Fill(order, order.price(), trade.size());
				}
				else
				{
					Fill(order, trade.price(), trade.size());
				}
				return true;
			}
			break;
		case OrderSide.Sell:
			if (trade.price() >= order.price())
			{
				if (m_fillAtLimitPrice)
				{
					Fill(order, order.price(), trade.size());
				}
				else
				{
					Fill(order, trade.price(), trade.size());
				}
				return true;
			}
			break;
	}
	return false;
}

bool ExecutionSimulatorPrivate::method_11(const Order& order, const Bar& bar)
{
	while (true)
	{
		switch (order.type())
		{
			case OrderType.Market:
				goto IL_D2;
			case OrderType.Stop:
				switch (order.side())
				{
					case OrderSide.Buy:
						if (bar.high() >= order.stopPx())
						{
							if (!m_fillAtStopPrice)
							{
								order.setType() = OrderType.Market;
								continue;
							}
							goto IL_E8;
						}
						break;
					case OrderSide.Sell:
						if (bar.low() <= order.stopPx())
						{
							if (!m_fillAtStopPrice)
							{
								order.setType() = OrderType.Market;
								continue;
							}
							goto IL_FE;
						}
						break;
				}
				break;
			case OrderType.Limit:
				goto IL_114;
			case OrderType.StopLimit:
				switch (order.side())
				{
					case OrderSide.Buy:
						if (bar.high() >= order.stopPx())
						{
							order.setType() = OrderType.Limit;
							continue;
						}
						break;
					case OrderSide.Sell:
						if (bar.low() <= order.stopPx())
						{
							order.setType() = OrderType.Limit;
							continue;
						}
						break;
				}
				break;
		}
		break;
	}
	return false;
	IL_D2:
	Fill(order, bar.close(), (int)bar.volume());
	return true;
	IL_E8:
	Fill(order, order.stopPx(), (int)bar.volume());
	return true;
	IL_FE:
	Fill(order, order.stopPx(), (int)bar.volume());
	return true;
	IL_114:
	switch (order.side())
	{
		case OrderSide.Buy:
			if (bar.low() <= order.price())
			{
				if (m_fillAtLimitPrice)
				{
					Fill(order, order.price(), (int)bar.volume());
				}
				else
				{
					Fill(order, bar.close(), (int)bar.volume());
				}
				return true;
			}
			break;
		case OrderSide.Sell:
			if (bar.high() >= order.price())
			{
				if (m_fillAtLimitPrice)
				{
					Fill(order, order.price(), (int)bar.volume());
				}
				else
				{
					Fill(order, bar.close(), (int)bar.volume());
				}
				return true;
			}
			break;
	}
	return false;
}

void ExecutionSimulatorPrivate::method_12(const QDateTime& dateTime, const QVariant& object)
{
	for (int i = list_0.Count - 1; i >= 0; i--)
	{
		Order order = list_0[i];
		if (m_idArray[order.instrument()] == null)
		{
			m_idArray[order.instrument()] = new List<Order>();
		}
		m_idArray[order.instrument()].Add(order);
		method_14(order);
		list_0.RemoveAt(i);
	}
}

void ExecutionSimulatorPrivate::method_13(const QDateTime& dateTime, const QVariant& object)
{
	for (int i = list_0.Count - 1; i >= 0; i--)
	{
		Order order = list_0[i];
		if (m_idArray[order.instrument()] == null)
		{
			m_idArray[order.instrument()] = new List<Order>();
		}
		m_idArray[order.instrument()].Add(order);
		if (!method_14(order))
		{
			method_5(order);
		}
		list_0.RemoveAt(i);
	}
}

bool ExecutionSimulatorPrivate::method_14(const Order& order)
{
	if (order.type() == OrderType.Limit)
	{
		int instrument = order.instrument();
		if (m_fillOnQuote)
		{
			Ask ask = framework.dataManager().GetAsk(instrument);
			if (ask != null && method_9(order, ask))
			{
				return true;
			}
			Bid bid = framework.dataManager().GetBid(instrument);
			if (bid != null && method_8(order, bid))
			{
				return true;
			}
		}
		if (m_fillOnTrade)
		{
			Trade trade = framework.dataManager().GetTrade(instrument);
			if (trade != null && method_10(order, trade))
			{
				return true;
			}
		}
		if (m_fillOnBar)
		{
			Bar bar = framework.dataManager().GetBar(instrument);
			if (m_barFilter.count() != 0 && !m_barFilter.Contains(bar.type(), bar.size()))
			{
				return false;
			}
			if (bar != null && method_11(order, bar))
			{
				return true;
			}
		}
	}
	return false;
}

void ExecutionSimulatorPrivate::method_4(const Order& order)
{
	ExecutionReport executionReport = new ExecutionReport();
	executionReport.setEntryDate() = framework.clock().dateTime();
	executionReport.setOrder() = order;
	executionReport.setOrderId() = order.id();
	executionReport.setInstrument() = order.instrument();
	executionReport.setInstrumentId() = order.instrument();
	executionReport.setExecType() = ExecType.ExecNew;
	executionReport.setOrdStatus() = OrderStatus.New;
	executionReport.setCurrencyId() = order.instrument().currencyId();
	executionReport.setOrdType() = order.type();
	executionReport.setSide() = order.side();
	executionReport.setOrdQty() = order.qty();
	executionReport.setPrice() = order.price();
	executionReport.setStopPx() = order.stopPx();
	executionReport.setTimeInForce() = order.timeInForce();
	executionReport.setCumQty() = 0.0;
	executionReport.setLastQty() = 0.0;
	executionReport.setLeavesQty() = order.qty();
	executionReport.setLastPx() = 0.0;
	executionReport.setAvgPx() = 0.0;
	executionReport.setText() = order.text();
	order.setLeavesQty() = executionReport.leavesQty();
	base.EmitExecutionReport(executionReport, m_queued);
	if (order.timeInForce() == TimeInForce.AUC)
	{
		list_0.Add(order);
		if (list_0.Count == 1)
		{
			framework.clock().AddReminder(new ReminderCallback(method_12()), framework.clock().dateTime().Date.Add(m_auction1), null);
			framework.clock().AddReminder(new ReminderCallback(method_13()), framework.clock().dateTime().Date.Add(m_auction2), null);
		}
		return;
	}
	int instrument = order.instrument();
	if (m_idArray[instrument] == null)
	{
		m_idArray[instrument] = new List<Order>();
	}
	m_idArray[instrument].Add(order);
	if ((order.type() == OrderType.Market && !m_fillMarketOnNext) || (order.type() == OrderType.Limit && !m_fillLimitOnNext) || (order.type() == OrderType.Stop && !m_fillStopOnNext) || (order.type() == OrderType.StopLimit && !m_fillStopLimitOnNext))
	{
		if (m_fillOnQuote)
		{
			Ask ask = framework.dataManager().GetAsk(instrument);
			if (ask != null && method_9(order, ask))
			{
				return;
			}
			Bid bid = framework.dataManager().GetBid(instrument);
			if (bid != null && method_8(order, bid))
			{
				return;
			}
		}
		if (m_fillOnTrade)
		{
			Trade trade = framework.dataManager().GetTrade(instrument);
			if (trade != null && method_10(order, trade))
			{
				return;
			}
		}
		if (m_fillOnBar)
		{
			Bar bar = framework.dataManager().GetBar(instrument);
			if (m_barFilter.count() != 0 && !m_barFilter.Contains(bar.type(), bar.size()))
			{
				return;
			}
			if (bar != null)
			{
				method_11(order, bar);
			}
		}
	}
}

void ExecutionSimulatorPrivate::method_5(const Order& order)
{
	m_idArray[order.instrument().id()].Remove(order);
	base.EmitExecutionReport(new ExecutionReport
	{
		m_entryDate = framework.clock().dateTime(),
		m_order = order,
		m_orderId = order.id(),
		m_instrument = order.instrument(),
		m_instrumentId = order.instrument(),
		m_ordQty = order.qty(),
		m_price = order.price(),
		m_stopPx = order.stopPx(),
		m_timeInForce = order.timeInForce(),
		m_execType = ExecType.ExecCancelled,
		m_ordStatus = OrderStatus.Cancelled,
		m_currencyId = order.instrument().currencyId(),
		m_ordType = order.type(),
		m_side = order.side(),
		m_cumQty = order.cumQty(),
		m_lastQty = 0.0,
		m_leavesQty = order.leavesQty(),
		m_lastPx = 0.0,
		m_avgPx = 0.0,
		m_text = order.text()
	}, m_queued);
}

void ExecutionSimulatorPrivate::method_6(const ExecutionCommand& executionCommand)
{
	Order order = executionCommand.order();
	base.EmitExecutionReport(new ExecutionReport
	{
		m_entryDate = framework.clock().dateTime(),
		m_order = order,
		m_orderId = order.id(),
		m_instrument = order.instrument(),
		m_instrumentId = order.instrument(),
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
		m_ordQty = order.qty(),
		m_timeInForce = order.timeInForce(),
		m_text = order.text()
	}, m_queued);
}

void ExecutionSimulatorPrivate::method_7(int int)
{
	for (int i = m_idArray[@int].Count - 1; i >= 0; i--)
	{
		if (m_idArray[@int][i].isDone())
		{
			m_idArray[@int].RemoveAt(i);
		}
	}
}

bool ExecutionSimulatorPrivate::method_8(const Order& order, const Bid& bid)
{
	if (order.side() == OrderSide.Sell)
	{
		while (true)
		{
			switch (order.type())
			{
				case OrderType.Market:
					goto IL_67;
				case OrderType.Stop:
					if (bid.price() <= order.stopPx())
					{
						if (!m_fillAtStopPrice)
						{
							order.setType() = OrderType.Market;
							continue;
						}
						goto IL_7C;
					}
					break;
				case OrderType.Limit:
					goto IL_91;
				case OrderType.StopLimit:
					if (bid.price() <= order.stopPx())
					{
						order.setType() = OrderType.Limit;
						continue;
					}
					break;
			}
			break;
		}
		return false;
		IL_67:
		Fill(order, bid.price(), bid.size());
		return true;
		IL_7C:
		Fill(order, order.stopPx(), bid.size());
		return true;
		IL_91:
		if (bid.price() >= order.price())
		{
			if (m_fillAtLimitPrice)
			{
				Fill(order, order.price(), bid.size());
			}
			else
			{
				Fill(order, bid.price(), bid.size());
			}
			return true;
		}
	}
	return false;
}

bool ExecutionSimulatorPrivate::method_9(const Order& order, const Ask& ask)
{
	if (order.side() == OrderSide.Buy)
	{
		while (true)
		{
			switch (order.type())
			{
				case OrderType.Market:
					goto IL_66;
				case OrderType.Stop:
					if (ask.price() >= order.stopPx())
					{
						if (!m_fillAtStopPrice)
						{
							order.setType() = OrderType.Market;
							continue;
						}
						goto IL_7B;
					}
					break;
				case OrderType.Limit:
					goto IL_90;
				case OrderType.StopLimit:
					if (ask.price() >= order.stopPx())
					{
						order.setType() = OrderType.Limit;
						continue;
					}
					break;
			}
			break;
		}
		return false;
		IL_66:
		Fill(order, ask.price(), ask.size());
		return true;
		IL_7B:
		Fill(order, order.stopPx(), ask.size());
		return true;
		IL_90:
		if (ask.price() <= order.price())
		{
			if (m_fillAtLimitPrice)
			{
				Fill(order, order.price(), ask.size());
			}
			else
			{
				Fill(order, ask.price(), ask.size());
			}
			return true;
		}
	}
	return false;
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(ExecutionSimulator)

ExecutionSimulator::ExecutionSimulator(const Framework& framework)
	: Provider(*new ExecutionSimulatorPrivate(framework))
{
}

ExecutionSimulator::~ExecutionSimulator()
{
}

BarFilter ExecutionSimulator::barFilter() const
{
	Q_D(const ExecutionSimulator);
	return d->barFilter();
}

ICommissionProvider ExecutionSimulator::commissionProvider() const
{
	Q_D(const ExecutionSimulator);
	return d->commissionProvider();
}

void ExecutionSimulator::setCommissionProvider(const ICommissionProvider& value)
{
	Q_D(ExecutionSimulator);
	d->setCommissionProvider(value);
}

ISlippageProvider ExecutionSimulator::slippageProvider() const
{
	Q_D(const ExecutionSimulator);
	return d->slippageProvider();
}

void ExecutionSimulator::setSlippageProvider(const ISlippageProvider& value)
{
	Q_D(ExecutionSimulator);
	d->setSlippageProvider(value);
}

bool ExecutionSimulator::fillOnQuote() const
{
	Q_D(const ExecutionSimulator);
	return d->fillOnQuote();
}

void ExecutionSimulator::setFillOnQuote(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillOnQuote(value);
}

bool ExecutionSimulator::fillOnTrade() const
{
	Q_D(const ExecutionSimulator);
	return d->fillOnTrade();
}

void ExecutionSimulator::setFillOnTrade(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillOnTrade(value);
}

bool ExecutionSimulator::fillOnBarOpen() const
{
	Q_D(const ExecutionSimulator);
	return d->fillOnBarOpen();
}

void ExecutionSimulator::setFillOnBarOpen(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillOnBarOpen(value);
}

bool ExecutionSimulator::fillOnBar() const
{
	Q_D(const ExecutionSimulator);
	return d->fillOnBar();
}

void ExecutionSimulator::setFillOnBar(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillOnBar(value);
}

bool ExecutionSimulator::fillOnLevel2() const
{
	Q_D(const ExecutionSimulator);
	return d->fillOnLevel2();
}

void ExecutionSimulator::setFillOnLevel2(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillOnLevel2(value);
}

bool ExecutionSimulator::fillMarketOnNext() const
{
	Q_D(const ExecutionSimulator);
	return d->fillMarketOnNext();
}

void ExecutionSimulator::setFillMarketOnNext(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillMarketOnNext(value);
}

bool ExecutionSimulator::fillLimitOnNext() const
{
	Q_D(const ExecutionSimulator);
	return d->fillLimitOnNext();
}

void ExecutionSimulator::setFillLimitOnNext(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillLimitOnNext(value);
}

bool ExecutionSimulator::fillStopOnNext() const
{
	Q_D(const ExecutionSimulator);
	return d->fillStopOnNext();
}

void ExecutionSimulator::setFillStopOnNext(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillStopOnNext(value);
}

bool ExecutionSimulator::fillStopLimitOnNext() const
{
	Q_D(const ExecutionSimulator);
	return d->fillStopLimitOnNext();
}

void ExecutionSimulator::setFillStopLimitOnNext(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillStopLimitOnNext(value);
}

bool ExecutionSimulator::fillAtLimitPrice() const
{
	Q_D(const ExecutionSimulator);
	return d->fillAtLimitPrice();
}

void ExecutionSimulator::setFillAtLimitPrice(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillAtLimitPrice(value);
}

bool ExecutionSimulator::fillAtStopPrice() const
{
	Q_D(const ExecutionSimulator);
	return d->fillAtStopPrice();
}

void ExecutionSimulator::setFillAtStopPrice(bool value)
{
	Q_D(ExecutionSimulator);
	d->setFillAtStopPrice(value);
}

bool ExecutionSimulator::partialFills() const
{
	Q_D(const ExecutionSimulator);
	return d->partialFills();
}

void ExecutionSimulator::setPartialFills(bool value)
{
	Q_D(ExecutionSimulator);
	d->setPartialFills(value);
}

TimeSpan ExecutionSimulator::auction1() const
{
	Q_D(const ExecutionSimulator);
	return d->auction1();
}

void ExecutionSimulator::setAuction1(TimeSpan value)
{
	Q_D(ExecutionSimulator);
	d->setAuction1(value);
}

TimeSpan ExecutionSimulator::auction2() const
{
	Q_D(const ExecutionSimulator);
	return d->auction2();
}

void ExecutionSimulator::setAuction2(TimeSpan value)
{
	Q_D(ExecutionSimulator);
	d->setAuction2(value);
}

bool ExecutionSimulator::queued() const
{
	Q_D(const ExecutionSimulator);
	return d->queued();
}

void ExecutionSimulator::setQueued(bool value)
{
	Q_D(ExecutionSimulator);
	d->setQueued(value);
}

void ExecutionSimulator::clear()
{
	Q_D(ExecutionSimulator);
	d->clear();
}

void ExecutionSimulator::fill(const Order& order, double price, int size)
{
	Q_D(ExecutionSimulator);
	d->fill(order, price, size);
}

void ExecutionSimulator::onAsk(const Ask& ask)
{
	Q_D(ExecutionSimulator);
	d->onAsk(ask);
}

void ExecutionSimulator::onBar(const Bar& bar)
{
	Q_D(ExecutionSimulator);
	d->onBar(bar);
}

void ExecutionSimulator::onBarOpen(const Bar& bar)
{
	Q_D(ExecutionSimulator);
	d->onBarOpen(bar);
}

void ExecutionSimulator::onBid(const Bid& bid)
{
	Q_D(ExecutionSimulator);
	d->onBid(bid);
}

void ExecutionSimulator::onLevel2(const Level2Snapshot& snapshot)
{
	Q_D(ExecutionSimulator);
	d->onLevel2(snapshot);
}

void ExecutionSimulator::onLevel2(const Level2Update& update)
{
	Q_D(ExecutionSimulator);
	d->onLevel2(update);
}

void ExecutionSimulator::onTrade(const Trade& trade)
{
	Q_D(ExecutionSimulator);
	d->onTrade(trade);
}


