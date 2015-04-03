#ifndef __QUANTKIT_SELLSIDESTRATEGY_PRIVATE_H__
#define __QUANTKIT_SELLSIDESTRATEGY_PRIVATE_H__

#include <QuantKit/SellSideStrategy.h>

#include "Strategy_p.h"
#include "Framework_p.h"
#include "ExecutionCommand_p.h"
#include "ExecutionReport_p.h"
#include "Bid_p.h"
#include "Ask_p.h"
#include "Trade_p.h"
#include "Bar_p.h"
#include "Instrument_p.h"
#include "InstrumentList_p.h"

namespace QuantKit {

class SellSideStrategyPrivate : public StrategyPrivate
{
public:
	ProviderStatus m_status;

public:
	SellSideStrategyPrivate(const Framework& framework, const QString& name);
	virtual ~SellSideStrategyPrivate();

public:
	ProviderStatus status() const { return m_status; }
	void setStatus(ProviderStatus value) { m_status = value; }
	bool isConnected() const { return true; }
	bool isDisconnected() const { return false; }
	virtual void connect() Q_DECL_OVERRIDE
	{
		Console.WriteLine("SellSideStrategy::Connect");
	}

	virtual bool connect(int timeout) Q_DECL_OVERRIDE;
	virtual void disconnect() Q_DECL_OVERRIDE
	{
		Console.WriteLine("SellSideStrategy::Disconnect");
	}

	void emitAsk(const Ask& ask)
	{
		m_global.eventManager().OnEvent(ask);
	}

	void emitBar(const Bar& bar)
	{
		m_global.eventManager().OnEvent(bar);
	}

	void emitBid(const Bid& bid)
	{
		m_global.eventManager().OnEvent(bid);
	}

	void emitExecutionReport(const ExecutionReport& report)
	{
		m_global.eventManager().OnEvent(report);
	}

	void emitTrade(const Trade& trade)
	{
		m_global.eventManager().OnEvent(trade);
	}

	virtual void onCancelCommand(const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual void onReplaceCommand(const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual void onSendCommand(const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual void send(const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual void subscribe(const Instrument& instrument) Q_DECL_OVERRIDE { OnSubscribe(instrument); }
	virtual void subscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE { OnSubscribe(instruments); }
	virtual void unsubscribe(const Instrument& instrument) Q_DECL_OVERRIDE { OnUnsubscribe(instrument); }
	virtual void unsubscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE { OnUnsubscribe(instruments); }
//protected
	virtual void onSubscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE;
	virtual void onSubscribe(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void onUnsubscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE;
	virtual void onUnsubscribe(const Instrument& instrument) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_SELLSIDESTRATEGY_PRIVATE_H__
