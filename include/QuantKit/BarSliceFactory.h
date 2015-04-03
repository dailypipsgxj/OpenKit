#ifndef __QUANTKIT_BARSLICEFACTORY_H__
#define __QUANTKIT_BARSLICEFACTORY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class BarSliceFactoryPrivate;

class Framework;
class Bar;
class IdArray;

class QUANTKIT_EXPORT BarSliceFactory
{
public:
	explicit BarSliceFactory(const Framework& framework);
	~BarSliceFactory();

	BarSliceFactory(const BarSliceFactory &other);
	BarSliceFactory& operator=(const BarSliceFactory &other);
	bool operator==(const BarSliceFactory &other) const;
	inline bool operator!=(const BarSliceFactory &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<BarSliceFactoryPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const BarSliceFactory& barslicefactory);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BarSliceFactory& barslicefactory);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarSliceFactory)

#endif // __QUANTKIT_BARSLICEFACTORY_H__
