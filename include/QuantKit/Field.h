#ifndef __QUANTKIT_FIELD_H__
#define __QUANTKIT_FIELD_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class FieldPrivate;

class QUANTKIT_EXPORT Field
{
public:
	Field();
	~Field();

	Field(const Field &other);
	Field& operator=(const Field &other);
	bool operator==(const Field &other) const;
	inline bool operator!=(const Field &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<FieldPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Field& field);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Field& field);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Field)

#endif // __QUANTKIT_FIELD_H__
