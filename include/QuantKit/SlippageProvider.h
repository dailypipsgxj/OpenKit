#ifndef __QUANTKIT_SLIPPAGEPROVIDER_H__
#define __QUANTKIT_SLIPPAGEPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

#include <QuantKit/ISlippageProvider.h>

namespace QuantKit {

class SlippageProviderPrivate;

class ExecutionReport;

class QUANTKIT_EXPORT SlippageProvider : public ISlippageProvider
{
public:
	SlippageProvider();
	~SlippageProvider();

	SlippageProvider(const SlippageProvider &other);
	SlippageProvider& operator=(const SlippageProvider &other);
	bool operator==(const SlippageProvider &other) const;
	inline bool operator!=(const SlippageProvider &other) const { return !(this->operator==(other));  }
public:
	double slippage() const;
	void setSlippage(double value);
	double getPrice(const ExecutionReport& report);

private:
	QSharedDataPointer<SlippageProviderPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const SlippageProvider& slippageprovider);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const SlippageProvider& slippageprovider);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SlippageProvider)

#endif // __QUANTKIT_SLIPPAGEPROVIDER_H__
