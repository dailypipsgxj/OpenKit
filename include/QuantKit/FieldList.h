#ifndef __QUANTKIT_FIELDLIST_H__
#define __QUANTKIT_FIELDLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class FieldListPrivate;

class IdArray;

class QUANTKIT_EXPORT FieldList
{
public:
	FieldList();
	~FieldList();

	FieldList(const FieldList &other);
	FieldList& operator=(const FieldList &other);
	bool operator==(const FieldList &other) const;
	inline bool operator!=(const FieldList &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<FieldListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const FieldList& fieldlist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const FieldList& fieldlist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FieldList)

#endif // __QUANTKIT_FIELDLIST_H__
