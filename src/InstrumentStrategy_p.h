#ifndef __QUANTKIT_INSTRUMENTSTRATEGY_PRIVATE_H__
#define __QUANTKIT_INSTRUMENTSTRATEGY_PRIVATE_H__

#include <QuantKit/InstrumentStrategy.h>

#include "Strategy_p.h"
#include "Instrument_p.h"
#include "Position_p.h"
#include "Framework_p.h"

namespace QuantKit {

class InstrumentStrategyPrivate : public StrategyPrivate
{
public:
	Instrument m_executionProvider;

public:
	InstrumentStrategyPrivate(const Framework& framework, const QString& name) { raiseEvents = false; }
	virtual ~InstrumentStrategyPrivate();

public:
	Instrument instrument() const { return m_executionProvider; }
	Position position() const
	{
		return m_position.GetPosition(m_executionProvider);
	}

	virtual IDataProvider dataProvider() const Q_DECL_OVERRIDE
	{
		return base.method_7(this, m_executionProvider);
	}

	virtual void setDataProvider(const IDataProvider& value) Q_DECL_OVERRIDE;
	virtual IExecutionProvider executionProvider() const Q_DECL_OVERRIDE
	{
		return base.method_6(m_executionProvider);
	}

	virtual void setExecutionProvider(const IExecutionProvider& value) Q_DECL_OVERRIDE;
	void addInstance(const Instrument& instrument, const InstrumentStrategy& strategy);
	bool hasLongPosition()
	{
		return base.HasLongPosition(m_executionProvider);
	}

	bool hasLongPosition(double qty)
	{
		return base.HasLongPosition(m_executionProvider, qty);
	}

	bool hasPosition()
	{
		return base.HasPosition(m_executionProvider);
	}

	bool hasPosition(PositionSide side, double qty)
	{
		return base.HasPosition(m_executionProvider, side, qty);
	}

	bool hasShortPosition()
	{
		return base.HasShortPosition(m_executionProvider);
	}

	bool hasShortPosition(double qty)
	{
		return base.HasShortPosition(m_executionProvider, qty);
	}

	virtual void init() Q_DECL_OVERRIDE;
//protected
	virtual void vmethod_0() Q_DECL_OVERRIDE;

//private:
	void method_8(const InstrumentStrategy& instrumentStrategy)
	{
		base.AddStrategy(instrumentStrategy, false);
	}

};

} // namepsace QuantKit

#endif // __QUANTKIT_INSTRUMENTSTRATEGY_PRIVATE_H__
