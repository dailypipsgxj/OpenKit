#ifndef __QUANTKIT_PARAMETERATTRIBUTE_H__
#define __QUANTKIT_PARAMETERATTRIBUTE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class ParameterAttributePrivate;

class QUANTKIT_EXPORT ParameterAttribute Q_DECL_FINAL : public Attribute
{
public:
	ParameterAttribute();
	~ParameterAttribute();

	ParameterAttribute(const ParameterAttribute &other);
	ParameterAttribute& operator=(const ParameterAttribute &other);
	bool operator==(const ParameterAttribute &other) const;
	inline bool operator!=(const ParameterAttribute &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<ParameterAttributePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ParameterAttribute& parameterattribute);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ParameterAttribute& parameterattribute);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ParameterAttribute)

#endif // __QUANTKIT_PARAMETERATTRIBUTE_H__
