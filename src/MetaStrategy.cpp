#include <QuantKit/MetaStrategy.h>

#include <QuantKit/Framework.h>
#include "Strategy_p.h"
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/Order.h>
#include <QuantKit/Position.h>
#include <QuantKit/Event/OnFill.h>
#include "Provider_p.h"
#include <QuantKit/IdArray.h>
#include "Strategy_p.h"

namespace QuantKit {

class MetaStrategyPrivate : public StrategyPrivate
{
public:
	IdArray<QList<Strategy>> idArray_4;
	IdArray<Strategy> idArray_5;
	IdArray<Strategy> idArray_6;
	QList<Strategy> list_1;

public:
	MetaStrategyPrivate(const Framework& framework, const QString& name);
	virtual ~MetaStrategyPrivate();

public:
	void add(const Strategy& strategy);
	virtual MetaStrategyPrivate* clone() Q_DECL_OVERRIDE { return new MetaStrategyPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

MetaStrategyPrivate::MetaStrategyPrivate(const Framework& framework, const QString& name)
	: StrategyPrivate (framework, name)
	, idArray_4(new IdArray<QList<Strategy>>(1000))
	, idArray_5(new IdArray<Strategy>(1000))
	, idArray_6(new IdArray<Strategy>(1000))
	, list_1(new QList<Strategy>())
{
}

MetaStrategyPrivate::~MetaStrategyPrivate ()
{
}

void MetaStrategyPrivate::add(const Strategy& strategy)
{
	list_1.Add(strategy);
	strategy.position().setParent() = m_position;
	foreach (Instrument current in strategy.instruments())
	{
		List<Strategy> list;
		if (idArray_4[current.id()] == null)
		{
			list = new List<Strategy>();
			idArray_4[current.id()] = list;
		}
		else
		{
			list = idArray_4[current.id()];
		}
		list.Add(strategy);
		if (!base.instruments().Contains(current))
		{
			base.instruments().Add(current);
		}
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(MetaStrategy)

MetaStrategy::MetaStrategy(const Framework& framework, const QString& name)
	: Strategy(*new MetaStrategyPrivate(framework, name))
{
}

MetaStrategy::~MetaStrategy()
{
}

void MetaStrategy::add(const Strategy& strategy)
{
	Q_D(MetaStrategy);
	d->add(strategy);
}


