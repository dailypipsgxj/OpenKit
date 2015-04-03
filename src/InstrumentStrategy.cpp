#include <QuantKit/InstrumentStrategy.h>

#include <QuantKit/Instrument.h>
#include <QuantKit/Position.h>
#include <QuantKit/Framework.h>
#include "InstrumentStrategy_p.h"

using namespace QuantKit;

InstrumentStrategyPrivate::~InstrumentStrategyPrivate ()
{
}

void InstrumentStrategyPrivate::setDataProvider(const IDataProvider& value)
{
	m_dataProvider = value;
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.setDataProvider() = m_dataProvider;
	}
}

void InstrumentStrategyPrivate::setExecutionProvider(const IExecutionProvider& value)
{
	m_executionProvider = value;
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		linkedListNode.Data.setExecutionProvider() = m_executionProvider;
	}
}

void InstrumentStrategyPrivate::addInstance(const Instrument& instrument, const InstrumentStrategy& strategy)
{
	strategy.setExecutionProvider() = instrument;
	strategy.instruments().Add(instrument);
	strategy.position().method_0(instrument);
	strategy.setRaiseEvents() = true;
	strategy.setDataProvider() = m_dataProvider;
	strategy.setExecutionProvider() = m_executionProvider;
	method_8(strategy);
	if (base.instruments().GetById(instrument.id()) == null)
	{
		base.instruments().Add(instrument);
	}
	strategy.setStatus() = StrategyStatus.Running;
	strategy.OnStrategyInit();
	strategy.OnStrategyStart();
}

void InstrumentStrategyPrivate::init()
{
	if (!bool_1)
	{
		foreach (Instrument current in m_instruments)
		{
			InstrumentStrategy instrumentStrategy = (InstrumentStrategy)Activator.CreateInstance(base.GetType(), new object[]
			{
				m_global,
				base.name() + " (" + current.symbol() + ")"
			});
			instrumentStrategy.setExecutionProvider() = current;
			instrumentStrategy.instruments().Add(current);
			instrumentStrategy.position().method_0(current);
			instrumentStrategy.setRaiseEvents() = true;
			instrumentStrategy.setDataProvider() = m_dataProvider;
			instrumentStrategy.setExecutionProvider() = m_executionProvider;
			base.AddStrategy(instrumentStrategy, false);
			FieldInfo[] fields = instrumentStrategy.GetType().GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
			for (int i = 0; i < fields.Length; i++)
			{
				FieldInfo fieldInfo = fields[i];
				if (fieldInfo.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
				{
					fieldInfo.SetValue(instrumentStrategy, fieldInfo.GetValue(this));
				}
			}
			if (m_strategies.Count == 1)
			{
				m_bars = instrumentStrategy.bars();
				m_equity = instrumentStrategy.equity();
			}
			instrumentStrategy.OnStrategyInit();
		}
		bool_1 = true;
	}
}

//protected
void InstrumentStrategyPrivate::vmethod_0()
{
	m_status = StrategyStatus.Running;
	if (raiseEvents)
	{
		OnStrategyStart();
	}
	for (LinkedListNode<Strategy> linkedListNode = m_strategies.First; linkedListNode != null; linkedListNode = linkedListNode.Next)
	{
		base.method_3(linkedListNode.Data, linkedListNode.Data.instruments(), (int)linkedListNode.Data.id());
		linkedListNode.Data.OnStrategyStart();
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(InstrumentStrategy)

InstrumentStrategy::InstrumentStrategy(const Framework& framework, const QString& name)
	: Strategy(*new InstrumentStrategyPrivate(framework, name))
{
}

InstrumentStrategy::~InstrumentStrategy()
{
}

InstrumentStrategy::InstrumentStrategy (InstrumentStrategyPrivate &dd)
	: Strategy(dd)
{
}

Instrument InstrumentStrategy::instrument() const
{
	Q_D(const InstrumentStrategy);
	return d->instrument();
}

Position InstrumentStrategy::position() const
{
	Q_D(const InstrumentStrategy);
	return d->position();
}

void InstrumentStrategy::addInstance(const Instrument& instrument, const InstrumentStrategy& strategy)
{
	Q_D(InstrumentStrategy);
	d->addInstance(instrument, strategy);
}

bool InstrumentStrategy::hasLongPosition()
{
	Q_D(InstrumentStrategy);
	return d->hasLongPosition();
}

bool InstrumentStrategy::hasLongPosition(double qty)
{
	Q_D(InstrumentStrategy);
	return d->hasLongPosition(qty);
}

bool InstrumentStrategy::hasPosition()
{
	Q_D(InstrumentStrategy);
	return d->hasPosition();
}

bool InstrumentStrategy::hasPosition(PositionSide side, double qty)
{
	Q_D(InstrumentStrategy);
	return d->hasPosition(side, qty);
}

bool InstrumentStrategy::hasShortPosition()
{
	Q_D(InstrumentStrategy);
	return d->hasShortPosition();
}

bool InstrumentStrategy::hasShortPosition(double qty)
{
	Q_D(InstrumentStrategy);
	return d->hasShortPosition(qty);
}


