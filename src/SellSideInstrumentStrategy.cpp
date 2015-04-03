#include <QuantKit/SellSideInstrumentStrategy.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>
#include "Strategy_p.h"
#include <QuantKit/InstrumentList.h>
#include <QuantKit/Event/ExecutionCommand.h>
#include "SellSideStrategy_p.h"

namespace QuantKit {

class SellSideInstrumentStrategyPrivate : public SellSideStrategyPrivate
{
public:
	Instrument Instrument;

public:
	SellSideInstrumentStrategyPrivate(const Framework& framework, const QString& name) { raiseEvents = false; }
	virtual ~SellSideInstrumentStrategyPrivate();

public:
	virtual void init() Q_DECL_OVERRIDE;
	virtual void send(const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual void subscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE;
	virtual void subscribe(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void unsubscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE;
	virtual void unsubscribe(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual SellSideInstrumentStrategyPrivate* clone() Q_DECL_OVERRIDE { return new SellSideInstrumentStrategyPrivate(*this); }
//private:
	void method_10(const SellSideInstrumentStrategy& sellSideInstrumentStrategy);
	SellSideInstrumentStrategy method_8(const Instrument& instrument, bool bool_2, bool bool_3);
	void method_9(const Strategy& strategy_1, const Instrument& instrument);
};

} // namepsace QuantKit


using namespace QuantKit;

SellSideInstrumentStrategyPrivate::~SellSideInstrumentStrategyPrivate ()
{
}

void SellSideInstrumentStrategyPrivate::init()
{
	if (!bool_1)
	{
		foreach (Instrument current in m_instruments)
		{
			if (m_idArray[current.id()] == null)
			{
				method_8(current, true, false);
			}
		}
		bool_1 = true;
	}
}

void SellSideInstrumentStrategyPrivate::send(const ExecutionCommand& command)
{
	SellSideInstrumentStrategy sellSideInstrumentStrategy = m_idArray[command.order().instrument().id()].First.Data as SellSideInstrumentStrategy;
	switch (command.type())
	{
		case ExecutionCommandType.Send:
			sellSideInstrumentStrategy.OnSendCommand(command);
			return;
		case ExecutionCommandType.Cancel:
			sellSideInstrumentStrategy.OnCancelCommand(command);
			return;
		case ExecutionCommandType.Replace:
			sellSideInstrumentStrategy.OnReplaceCommand(command);
			return;
		default:
			return;
	}
}

void SellSideInstrumentStrategyPrivate::subscribe(const InstrumentList& instruments)
{
	foreach (Instrument current in instruments)
	{
		Subscribe(current);
	}
}

void SellSideInstrumentStrategyPrivate::subscribe(const Instrument& instrument)
{
	if (m_idArray[instrument.id()] == null)
	{
		SellSideInstrumentStrategy sellSideInstrumentStrategy = method_8(instrument, false, true);
		sellSideInstrumentStrategy.OnStrategyStart();
	}
}

void SellSideInstrumentStrategyPrivate::unsubscribe(const InstrumentList& instruments)
{
	foreach (Instrument current in instruments)
	{
		Unsubscribe(current);
	}
}

void SellSideInstrumentStrategyPrivate::unsubscribe(const Instrument& instrument)
{
	if (m_idArray[instrument.id()] != null)
	{
		SellSideInstrumentStrategy sellSideInstrumentStrategy = m_idArray[instrument.id()].First.Data as SellSideInstrumentStrategy;
		sellSideInstrumentStrategy.OnUnsubscribe(instrument);
	}
}

void SellSideInstrumentStrategyPrivate::method_10(const SellSideInstrumentStrategy& sellSideInstrumentStrategy)
{
	FieldInfo[] fields = sellSideInstrumentStrategy.GetType().GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
	for (int i = 0; i < fields.Length; i++)
	{
		FieldInfo fieldInfo = fields[i];
		if (fieldInfo.GetCustomAttributes(typeof(ParameterAttribute), true).Length > 0)
		{
			fieldInfo.SetValue(sellSideInstrumentStrategy, fieldInfo.GetValue(this));
		}
	}
}

SellSideInstrumentStrategy SellSideInstrumentStrategyPrivate::method_8(const Instrument& instrument, bool bool_2, bool bool_3)
{
	SellSideInstrumentStrategy sellSideInstrumentStrategy = (SellSideInstrumentStrategy)Activator.CreateInstance(base.GetType(), new object[]
	{
		m_global,
		string.Concat(new object[]
		{
			base.name(),
			"(",
			instrument,
			")"
		})
	});
	sellSideInstrumentStrategy.setInstrument() = instrument;
	if (bool_2)
	{
		sellSideInstrumentStrategy.instruments().Add(instrument);
	}
	sellSideInstrumentStrategy.setDataProvider() = m_dataProvider;
	sellSideInstrumentStrategy.setExecutionProvider() = m_executionProvider;
	sellSideInstrumentStrategy.setRaiseEvents() = true;
	method_10(sellSideInstrumentStrategy);
	method_9(sellSideInstrumentStrategy, instrument);
	if (bool_3)
	{
		sellSideInstrumentStrategy.OnSubscribe(instrument);
	}
	base.AddStrategy(sellSideInstrumentStrategy, false);
	sellSideInstrumentStrategy.OnStrategyInit();
	return sellSideInstrumentStrategy;
}

void SellSideInstrumentStrategyPrivate::method_9(const Strategy& strategy_1, const Instrument& instrument)
{
	LinkedList<Strategy> linkedList;
	if (m_idArray[instrument.id()] == null)
	{
		linkedList = new LinkedList<Strategy>();
		m_idArray[instrument.id()] = linkedList;
	}
	else
	{
		linkedList = m_idArray[instrument.id()];
	}
	linkedList.Add(strategy_1);
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(SellSideInstrumentStrategy)

SellSideInstrumentStrategy::SellSideInstrumentStrategy(const Framework& framework, const QString& name)
	: SellSideStrategy(*new SellSideInstrumentStrategyPrivate(framework, name))
{
}

SellSideInstrumentStrategy::~SellSideInstrumentStrategy()
{
}


