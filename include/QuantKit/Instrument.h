#ifndef __QUANTKIT_INSTRUMENT_H__
#define __QUANTKIT_INSTRUMENT_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/InstrumentType.h>
#include <QuantKit/PutCall.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/CurrencyId.h>

namespace QuantKit {

class InstrumentPrivate;

class ObjectTable;
class AltIdList;
class Leg;
class Bid;
class Ask;
class Trade;
class Bar;
class Framework;

class QUANTKIT_EXPORT Instrument
{
public:
	Instrument();
	Instrument(InstrumentType type, const QString& symbol, const QString& description = "", unsigned char currencyId = CurrencyId::USD);
	Instrument(int id, InstrumentType type, const QString& symbol, const QString& description = "", unsigned char currencyId = CurrencyId::USD);
	Instrument(int id, InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId = CurrencyId::USD, const QString& exchange = "");
	~Instrument();

	Instrument(const Instrument &other);
	Instrument& operator=(const Instrument &other);
	bool operator==(const Instrument &other) const;
	inline bool operator!=(const Instrument &other) const { return !(this->operator==(other));  }
public:
	bool bool_0() const;
	void setBool_0(bool value);

	bool bool_1() const;
	void setBool_1(bool value);
	Framework framework() const;
	ObjectTable fields() const;
	Instrument parent() const;
	void setParent(const Instrument& value);
	int id() const;
	InstrumentType type() const;
	QString symbol() const;
	QString description() const;
	void setDescription(const QString& value);
	QString exchange() const;
	void setExchange(const QString& value);
	unsigned char currencyId() const;
	void setCurrencyId(unsigned char value);
	unsigned char CCY1() const;
	void setCCY1(unsigned char value);
	unsigned char CCY2() const;
	void setCCY2(unsigned char value);
	double tickSize() const;
	void setTickSize(double value);
	QDateTime maturity() const;
	void setMaturity(const QDateTime& value);
	double factor() const;
	void setFactor(double value);
	double strike() const;
	void setStrike(double value);
	PutCall putCall() const;
	void setPutCall(PutCall value);
	double margin() const;
	void setMargin(double value);
	QString priceFormat() const;
	void setPriceFormat(const QString& value);
	QString formula() const;
	void setFormula(const QString& value);
	AltIdList altId() const;
	QList<Leg> legs() const;
	Bid bid() const;
	Ask ask() const;
	Trade trade() const;
	Bar bar() const;
	IDataProvider dataProvider() const;
	void setDataProvider(const IDataProvider& value);
	IExecutionProvider executionProvider() const;
	void setExecutionProvider(const IExecutionProvider& value);
	Instrument clone(const QString& symbol = "");
	QString getExchange(unsigned char providerId);
	QString getSymbol(unsigned char providerId);
	QString toString() const;

private:
	QSharedDataPointer<InstrumentPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Instrument& instrument);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Instrument& instrument);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Instrument)

#endif // __QUANTKIT_INSTRUMENT_H__
