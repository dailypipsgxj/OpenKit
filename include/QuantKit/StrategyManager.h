#ifndef __QUANTKIT_STRATEGYMANAGER_H__
#define __QUANTKIT_STRATEGYMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QSharedDataPointer>

#include <QuantKit/StrategyMode.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/StrategyStatus.h>

namespace QuantKit {

class StrategyManagerPrivate;

class Global;
class Framework;
class InstrumentList;
class Strategy;
class Group;
class Provider;
class ProviderError;
class Bid;
class Ask;
class Trade;
class Level2Snapshot;
class Level2Update;
class Bar;
class BarSlice;
class News;
class Fundamental;
class Order;
class ExecutionReport;
class OnFill;
class OnTransaction;
class Portfolio;
class Position;

class QUANTKIT_EXPORT StrategyManager
{
public:
	explicit StrategyManager(const Framework& framework);
	~StrategyManager();

	StrategyManager(const StrategyManager &other);
	StrategyManager& operator=(const StrategyManager &other);
	bool operator==(const StrategyManager &other) const;
	inline bool operator!=(const StrategyManager &other) const { return !(this->operator==(other));  }
public:
	Global global() const;
	StrategyMode mode() const;
	void setMode(StrategyMode value);
	void clear();
	unsigned char getNextId();
	void registerMarketDataRequest(const IDataProvider& dataProvider, const InstrumentList& instrumentList);
	void startStrategy(const Strategy& strategy);
	void startStrategy(const Strategy& strategy, StrategyMode mode);
	void stop();

private:
	QSharedDataPointer<StrategyManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const StrategyManager& strategymanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const StrategyManager& strategymanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StrategyManager)

#endif // __QUANTKIT_STRATEGYMANAGER_H__
