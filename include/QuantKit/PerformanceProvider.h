#ifndef __QUANTKIT_PERFORMANCEPROVIDER_H__
#define __QUANTKIT_PERFORMANCEPROVIDER_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Provider.h>
#include <QuantKit/IProvider.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IExecutionProvider.h>

namespace QuantKit {

class PerformanceProviderPrivate;

class Framework;

class QUANTKIT_EXPORT PerformanceProvider Q_DECL_FINAL : public Provider , public IProvider , public IDataProvider , public IExecutionProvider
{
public:
	explicit PerformanceProvider(const Framework& framework);
	~PerformanceProvider();


private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PerformanceProvider)

#endif // __QUANTKIT_PERFORMANCEPROVIDER_H__
