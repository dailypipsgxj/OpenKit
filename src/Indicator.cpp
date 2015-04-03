#include <QuantKit/Indicator.h>

#include "Indicator_p.h"

using namespace QuantKit;

IndicatorPrivate::~IndicatorPrivate ()
{
}

bool getCalculate() const
{
	return false;
}
void setCalculate(bool value)
{
}

ISeries getInput() const
{
	return null;
}
int IndicatorPrivate::count() const
{
	Calculate();
	return base.count();
}

double IndicatorPrivate::first() const
{
	Calculate();
	return base.first();
}

double IndicatorPrivate::last() const
{
	Calculate();
	return base.last();
}

QDateTime IndicatorPrivate::firstDateTime() const
{
	Calculate();
	return base.firstDateTime();
}

QDateTime IndicatorPrivate::lastDateTime() const
{
	Calculate();
	return base.lastDateTime();
}

double IndicatorPrivate::item(int index) const
{
	Calculate();
	return base[index];
}

double IndicatorPrivate::item(int index, BarData barData) const
{
	Calculate();
	return base[index, barData];
}

void IndicatorPrivate::calculate(int index)
{
}

QDateTime IndicatorPrivate::getDateTime(int index)
{
	Calculate();
	return base.GetDateTime(index);
}

int IndicatorPrivate::getIndex(const QDateTime& datetime, IndexOption option)
{
	Calculate();
	return base.GetIndex(datetime, option);
}

double IndicatorPrivate::getMax(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	Calculate();
	return base.GetMax(dateTime1, dateTime2);
}

double IndicatorPrivate::getMin(const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	Calculate();
	return base.GetMin(dateTime1, dateTime2);
}

//protected
void IndicatorPrivate::calculate()
{
	if (m_calculate)
	{
		m_calculate = false;
		Indicator indicator = m_input as Indicator;
		if (indicator != null)
		{
			indicator.Calculate();
		}
		for (int i = 0; i < m_input.count(); i++)
		{
			method_0(i);
		}
	}
}

void IndicatorPrivate::init()
{
}

void IndicatorPrivate::method_0(int int)
{
	if (m_calculate)
	{
		Calculate();
		return;
	}
	Calculate(@int);
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Indicator)

Indicator::Indicator(const ISeries& input)
	: TimeSeries(*new IndicatorPrivate(input))
{
}

Indicator::~Indicator()
{
}

Indicator::Indicator (IndicatorPrivate &dd)
	: TimeSeries(dd)
{
}

bool calculate() const
{
	return d_ptr->
	setCalculate()
}

void setCalculate(bool value)
{
	d_ptr->calculate(value);
}

ISeries input() const
{
	return d_ptr->
	setInput()
}

bool Indicator::autoUpdate() const
{
	Q_D(const Indicator);
	return d->autoUpdate();
}

void Indicator::setAutoUpdate(bool value)
{
	Q_D(Indicator);
	d->setAutoUpdate(value);
}

void Indicator::attach()
{
	Q_D(Indicator);
	d->attach();
}

void Indicator::detach()
{
	Q_D(Indicator);
	d->detach();
}


