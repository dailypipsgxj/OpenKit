#ifndef __QUANTKIT_ICURRENCYCONVERTER_H__
#define __QUANTKIT_ICURRENCYCONVERTER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>

namespace QuantKit {

class QUANTKIT_EXPORT ICurrencyConverter
{
public:
	virtual double convert(double amount, unsigned char fromCurrencyId, unsigned char toCurrencyId) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_ICURRENCYCONVERTER_H__
