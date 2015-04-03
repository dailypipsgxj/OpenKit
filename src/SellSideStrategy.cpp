#include <QuantKit/SellSideStrategy.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Event/ExecutionCommand.h>
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentList.h>
#include "SellSideStrategy_p.h"

using namespace QuantKit;

SellSideStrategyPrivate::SellSideStrategyPrivate(const Framework& framework, const QString& name)
	: StrategyPrivate (framework, name)
{
}

SellSideStrategyPrivate::~SellSideStrategyPrivate ()
{
}

bool SellSideStrategyPrivate::connect(int timeout)
{
	long ticks = DateTime.Now.Ticks;
	Connect();
	while (!isConnected())
	{
		Thread.Sleep(1);
		double totalMilliseconds = TimeSpan.FromTicks(DateTime.Now.Ticks - ticks).TotalMilliseconds;
		if (totalMilliseconds >= (double)timeout)
		{
			Console.WriteLine("SellSideStrategy::Connect timed out : " + m_name);
			return false;
		}
	}
	return true;
}

void SellSideStrategyPrivate::onCancelCommand(const ExecutionCommand& command)
{
}

void SellSideStrategyPrivate::onReplaceCommand(const ExecutionCommand& command)
{
}

void SellSideStrategyPrivate::onSendCommand(const ExecutionCommand& command)
{
}

void SellSideStrategyPrivate::send(const ExecutionCommand& command)
{
	switch (command.type())
	{
		case ExecutionCommandType.Send:
			OnSendCommand(command);
			return;
		case ExecutionCommandType.Cancel:
			OnCancelCommand(command);
			return;
		case ExecutionCommandType.Replace:
			OnReplaceCommand(command);
			return;
		default:
			return;
	}
}

//protected
void SellSideStrategyPrivate::onSubscribe(const InstrumentList& instruments)
{
}

void SellSideStrategyPrivate::onSubscribe(const Instrument& instrument)
{
}

void SellSideStrategyPrivate::onUnsubscribe(const InstrumentList& instruments)
{
}

void SellSideStrategyPrivate::onUnsubscribe(const Instrument& instrument)
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(SellSideStrategy)

SellSideStrategy::SellSideStrategy(const Framework& framework, const QString& name)
	: Strategy(*new SellSideStrategyPrivate(framework, name))
{
}

SellSideStrategy::~SellSideStrategy()
{
}

SellSideStrategy::SellSideStrategy (SellSideStrategyPrivate &dd)
	: Strategy(dd)
{
}

ProviderStatus SellSideStrategy::status() const
{
	Q_D(const SellSideStrategy);
	return d->status();
}

void SellSideStrategy::setStatus(ProviderStatus value)
{
	Q_D(SellSideStrategy);
	d->setStatus(value);
}

bool SellSideStrategy::isConnected() const
{
	Q_D(const SellSideStrategy);
	return d->isConnected();
}

bool SellSideStrategy::isDisconnected() const
{
	Q_D(const SellSideStrategy);
	return d->isDisconnected();
}

void SellSideStrategy::emitAsk(const Ask& ask)
{
	Q_D(SellSideStrategy);
	d->emitAsk(ask);
}

void SellSideStrategy::emitBar(const Bar& bar)
{
	Q_D(SellSideStrategy);
	d->emitBar(bar);
}

void SellSideStrategy::emitBid(const Bid& bid)
{
	Q_D(SellSideStrategy);
	d->emitBid(bid);
}

void SellSideStrategy::emitExecutionReport(const ExecutionReport& report)
{
	Q_D(SellSideStrategy);
	d->emitExecutionReport(report);
}

void SellSideStrategy::emitTrade(const Trade& trade)
{
	Q_D(SellSideStrategy);
	d->emitTrade(trade);
}


