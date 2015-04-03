#ifndef __QUANTKIT_COMMISSIONPROVIDER_H__
#define __QUANTKIT_COMMISSIONPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

#include <QuantKit/ICommissionProvider.h>
#include <QuantKit/CommissionType.h>

namespace QuantKit {

class CommissionProviderPrivate;

class ExecutionReport;

class QUANTKIT_EXPORT CommissionProvider : public ICommissionProvider
{
public:
	CommissionProvider();
	~CommissionProvider();

	CommissionProvider(const CommissionProvider &other);
	CommissionProvider& operator=(const CommissionProvider &other);
	bool operator==(const CommissionProvider &other) const;
	inline bool operator!=(const CommissionProvider &other) const { return !(this->operator==(other));  }
public:
	double commission() const;
	void setCommission(double value);
	CommissionType type() const;
	void setType(CommissionType value);
	double minCommission() const;
	void setMinCommission(double value);
	double getCommission(const ExecutionReport& report);

private:
	QSharedDataPointer<CommissionProviderPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const CommissionProvider& commissionprovider);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const CommissionProvider& commissionprovider);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::CommissionProvider)

#endif // __QUANTKIT_COMMISSIONPROVIDER_H__
