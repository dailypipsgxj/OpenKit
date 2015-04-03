#ifndef __QUANTKIT_METASTRATEGY_H__
#define __QUANTKIT_METASTRATEGY_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QList>

#include <QuantKit/Strategy.h>

namespace QuantKit {

class MetaStrategyPrivate;

class Framework;
class Strategy;
class Bar;
class Trade;
class Bid;
class Ask;
class ExecutionReport;
class Order;
class Position;
class OnFill;
class Provider;
class IdArray;

class QUANTKIT_EXPORT MetaStrategy Q_DECL_FINAL : public Strategy
{
public:
	MetaStrategy(const Framework& framework, const QString& name);
	~MetaStrategy();

public:
	void add(const Strategy& strategy);

private:
	QK_DECLARE_PRIVATE(MetaStrategy)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::MetaStrategy)

#endif // __QUANTKIT_METASTRATEGY_H__
