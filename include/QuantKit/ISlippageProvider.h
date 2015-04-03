#ifndef __QUANTKIT_ISLIPPAGEPROVIDER_H__
#define __QUANTKIT_ISLIPPAGEPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>

namespace QuantKit {

class ExecutionReport;

class QUANTKIT_EXPORT ISlippageProvider
{
public:
	virtual double slippage() const = 0;
	virtual void setSlippage(double value) = 0;
	virtual double getPrice(const ExecutionReport& report) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_ISLIPPAGEPROVIDER_H__
