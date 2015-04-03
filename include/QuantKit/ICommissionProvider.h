#ifndef __QUANTKIT_ICOMMISSIONPROVIDER_H__
#define __QUANTKIT_ICOMMISSIONPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>

#include <QuantKit/CommissionType.h>

namespace QuantKit {

class ExecutionReport;

class QUANTKIT_EXPORT ICommissionProvider
{
public:
	virtual CommissionType type() const = 0;
	virtual void setType(CommissionType value) = 0;
	virtual double commission() const = 0;
	virtual void setCommission(double value) = 0;
	virtual double minCommission() const = 0;
	virtual void setMinCommission(double value) = 0;
	virtual double getCommission(const ExecutionReport& report) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_ICOMMISSIONPROVIDER_H__
