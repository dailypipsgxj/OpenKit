#ifndef __QUANTKIT_CURRENCYCONVERTER_H__
#define __QUANTKIT_CURRENCYCONVERTER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

#include <QuantKit/ICurrencyConverter.h>

namespace QuantKit {

class CurrencyConverterPrivate;

class Framework;
class DataManager;

class QUANTKIT_EXPORT CurrencyConverter : public ICurrencyConverter
{
public:
	explicit CurrencyConverter(const Framework& framework);
	~CurrencyConverter();

	CurrencyConverter(const CurrencyConverter &other);
	CurrencyConverter& operator=(const CurrencyConverter &other);
	bool operator==(const CurrencyConverter &other) const;
	inline bool operator!=(const CurrencyConverter &other) const { return !(this->operator==(other));  }
public:
	Framework framework() const;
	DataManager dataManager() const;
	double convert(double amount, unsigned char fromCurrencyId, unsigned char toCurrencyId);

private:
	QSharedDataPointer<CurrencyConverterPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const CurrencyConverter& currencyconverter);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const CurrencyConverter& currencyconverter);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::CurrencyConverter)

#endif // __QUANTKIT_CURRENCYCONVERTER_H__
