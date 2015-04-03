#ifndef __QUANTKIT_FILL_H__
#define __QUANTKIT_FILL_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/DataObject.h>
#include <QuantKit/OrderSide.h>

namespace QuantKit {

class FillPrivate;

class Order;
class Instrument;
class ExecutionReport;

class QUANTKIT_EXPORT Fill Q_DECL_FINAL : public DataObject
{
public:
	Fill();
	explicit Fill(const ExecutionReport& report);
	Fill(const QDateTime& dateTime, const Order& order, const Instrument& instrument, unsigned char currencyId, OrderSide side, double qty, double price, const QString& text = "");
	~Fill();

public:
	int int_0() const;
	void setInt_0(int value);
	Order order() const;
	Instrument instrument() const;
	unsigned char currencyId() const;
	OrderSide side() const;
	double qty() const;
	double price() const;
	double value() const;
	double netCashFlow() const;
	double cashFlow() const;
	QString text() const;
	double commission() const;
	QString getSideAsString();

private:
	QK_DECLARE_PRIVATE(Fill)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Fill)

#endif // __QUANTKIT_FILL_H__
