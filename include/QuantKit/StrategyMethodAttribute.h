#ifndef __QUANTKIT_STRATEGYMETHODATTRIBUTE_H__
#define __QUANTKIT_STRATEGYMETHODATTRIBUTE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class StrategyMethodAttributePrivate;

class QUANTKIT_EXPORT StrategyMethodAttribute Q_DECL_FINAL : public Attribute
{
public:
	StrategyMethodAttribute();
	~StrategyMethodAttribute();

	StrategyMethodAttribute(const StrategyMethodAttribute &other);
	StrategyMethodAttribute& operator=(const StrategyMethodAttribute &other);
	bool operator==(const StrategyMethodAttribute &other) const;
	inline bool operator!=(const StrategyMethodAttribute &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<StrategyMethodAttributePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const StrategyMethodAttribute& strategymethodattribute);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const StrategyMethodAttribute& strategymethodattribute);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StrategyMethodAttribute)

#endif // __QUANTKIT_STRATEGYMETHODATTRIBUTE_H__
