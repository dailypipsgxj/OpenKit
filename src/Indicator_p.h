#ifndef __QUANTKIT_INDICATOR_PRIVATE_H__
#define __QUANTKIT_INDICATOR_PRIVATE_H__

#include <QuantKit/Indicator.h>

#include "TimeSeries_p.h"

namespace QuantKit {

class IndicatorPrivate : public TimeSeriesPrivate
{
public:
	ISeries m_input;
	bool m_calculate;
	bool m_autoUpdate;

public:
	explicit IndicatorPrivate(const ISeries& input)
	{
		m_input.indicators().Add(this);
	}

	virtual ~IndicatorPrivate();

public:
	bool getCalculate() const;
	void setCalculate(bool value);
	ISeries getInput() const;
	bool autoUpdate() const { return m_autoUpdate; }
	void setAutoUpdate(bool value) { m_autoUpdate = value; }
	virtual int count() const Q_DECL_OVERRIDE;
	virtual double first() const Q_DECL_OVERRIDE;
	virtual double last() const Q_DECL_OVERRIDE;
	virtual QDateTime firstDateTime() const Q_DECL_OVERRIDE;
	virtual QDateTime lastDateTime() const Q_DECL_OVERRIDE;
	virtual double item(int index) const Q_DECL_OVERRIDE;
	virtual double item(int index, BarData barData) const Q_DECL_OVERRIDE;
	void attach()
	{
		m_input.indicators().Add(this);
	}

	virtual void calculate(int index) Q_DECL_OVERRIDE;
	void detach()
	{
		m_input.indicators().Remove(this);
	}

	virtual QDateTime getDateTime(int index) Q_DECL_OVERRIDE;
	virtual int getIndex(const QDateTime& datetime, IndexOption option) Q_DECL_OVERRIDE;
	virtual double getMax(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE;
	virtual double getMin(const QDateTime& dateTime1, const QDateTime& dateTime2) Q_DECL_OVERRIDE;
//protected
	virtual void calculate() Q_DECL_OVERRIDE;
	virtual void init() Q_DECL_OVERRIDE;
	void method_0(int int);
};

} // namepsace QuantKit

#endif // __QUANTKIT_INDICATOR_PRIVATE_H__
