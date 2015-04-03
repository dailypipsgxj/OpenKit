#ifndef __QUANTKIT_SELLSIDESTRATEGY_H__
#define __QUANTKIT_SELLSIDESTRATEGY_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Strategy.h>
#include <QuantKit/IProvider.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/ProviderStatus.h>

namespace QuantKit {

class SellSideStrategyPrivate;

class Framework;
class ExecutionCommand;
class ExecutionReport;
class Bid;
class Ask;
class Trade;
class Bar;
class Instrument;
class InstrumentList;

class QUANTKIT_EXPORT SellSideStrategy : public Strategy , public IProvider , public IDataProvider , public IExecutionProvider
{
public:
	SellSideStrategy(const Framework& framework, const QString& name);
	~SellSideStrategy();

public:
	ProviderStatus status() const;
	void setStatus(ProviderStatus value);
	bool isConnected() const;
	bool isDisconnected() const;
	void emitAsk(const Ask& ask);
	void emitBar(const Bar& bar);
	void emitBid(const Bid& bid);
	void emitExecutionReport(const ExecutionReport& report);
	void emitTrade(const Trade& trade);

protected:
	SellSideStrategy(SellSideStrategyPrivate& dd);

private:
	QK_DECLARE_PRIVATE(SellSideStrategy)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SellSideStrategy)

#endif // __QUANTKIT_SELLSIDESTRATEGY_H__
