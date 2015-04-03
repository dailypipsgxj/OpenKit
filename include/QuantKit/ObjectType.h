#ifndef __QUANTKIT_OBJECTTYPE_H__
#define __QUANTKIT_OBJECTTYPE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class ObjectTypePrivate;

class QUANTKIT_EXPORT ObjectType
{
public:
	ObjectType();
	~ObjectType();

	ObjectType(const ObjectType &other);
	ObjectType& operator=(const ObjectType &other);
	bool operator==(const ObjectType &other) const;
	inline bool operator!=(const ObjectType &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<ObjectTypePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ObjectType& objecttype);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ObjectType& objecttype);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ObjectType)

#endif // __QUANTKIT_OBJECTTYPE_H__
