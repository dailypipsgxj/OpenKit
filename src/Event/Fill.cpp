#include <QuantKit/Event/Fill.h>

#include <QuantKit/Event/Order.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/Event/ExecutionReport.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class FillPrivate : public DataObjectPrivate
{
public:
	Order m_text;
	Instrument m_instrument;
	int int_0;
	unsigned char m_currencyId;
	OrderSide m_side;
	double m_entryQty;
	double m_entryPrice;
	QString m_text;
	double m_commission;

public:
	FillPrivate();
	explicit FillPrivate(const ExecutionReport& report)
	{
		m_entryDate = report.entryDate();
	}

	FillPrivate(const QDateTime& dateTime, const Order& order, const Instrument& instrument, unsigned char currencyId, OrderSide side, double qty, double price, const QString& text) { m_entryDate = dateTime; }
	virtual ~FillPrivate();

public:
	int getInt_0() const;
	void setInt_0(int value);
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Fill; }
	Order order() const { return m_text; }
	Instrument instrument() const { return m_instrument; }
	unsigned char currencyId() const { return m_currencyId; }
	OrderSide side() const { return m_side; }
	double qty() const { return m_entryQty; }
	double price() const { return m_entryPrice; }
	double value() const;
	double netCashFlow() const;
	double cashFlow() const
	{
		return netCashFlow() - m_commission;
	}

	QString text() const { return m_text; }
	double commission() const { return m_commission; }
	QString getSideAsString();
	virtual QString toString() const Q_DECL_OVERRIDE { return "Fill"; }
	virtual FillPrivate* clone() Q_DECL_OVERRIDE { return new FillPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FillPrivate::FillPrivate()
{
}

FillPrivate::~FillPrivate ()
{
}

int getInt_0() const
{
	return 0;
}
void setInt_0(int value)
{
}
double FillPrivate::value() const
{
	if (m_instrument.factor() != 0.0)
	{
		return m_entryPrice * m_entryQty * m_instrument.factor();
	}
	return m_entryPrice * m_entryQty;
}

double FillPrivate::netCashFlow() const
{
	if (m_side == OrderSide.Buy)
	{
		return -value();
	}
	return value();
}

QString FillPrivate::getSideAsString()
{
	switch (m_side)
	{
		case OrderSide.Buy:
			return "Buy";
		case OrderSide.Sell:
			return "Sell";
		default:
			return "Undefined";
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Fill)

Fill::Fill()
	: DataObject(*new FillPrivate)
{
}

Fill::Fill(const ExecutionReport& report)
	: DataObject(*new FillPrivate(report))
{
}

Fill::Fill(const QDateTime& dateTime, const Order& order, const Instrument& instrument, unsigned char currencyId, OrderSide side, double qty, double price, const QString& text)
	: DataObject(*new FillPrivate(dateTime, order, instrument, currencyId, side, qty, price, text))
{
}

Fill::~Fill()
{
}

int int_0() const
{
	return d_ptr->
	setInt_0()
}

void setInt_0(int value)
{
	d_ptr->int_0(value);
}

Order Fill::order() const
{
	Q_D(const Fill);
	return d->order();
}

Instrument Fill::instrument() const
{
	Q_D(const Fill);
	return d->instrument();
}

unsigned char Fill::currencyId() const
{
	Q_D(const Fill);
	return d->currencyId();
}

OrderSide Fill::side() const
{
	Q_D(const Fill);
	return d->side();
}

double Fill::qty() const
{
	Q_D(const Fill);
	return d->qty();
}

double Fill::price() const
{
	Q_D(const Fill);
	return d->price();
}

double Fill::value() const
{
	Q_D(const Fill);
	return d->value();
}

double Fill::netCashFlow() const
{
	Q_D(const Fill);
	return d->netCashFlow();
}

double Fill::cashFlow() const
{
	Q_D(const Fill);
	return d->cashFlow();
}

QString Fill::text() const
{
	Q_D(const Fill);
	return d->text();
}

double Fill::commission() const
{
	Q_D(const Fill);
	return d->commission();
}

QString Fill::getSideAsString()
{
	Q_D(Fill);
	return d->getSideAsString();
}


