#ifndef __QUANTKIT_OBJECTTABLE_H__
#define __QUANTKIT_OBJECTTABLE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class ObjectTablePrivate;

class IdArray;

class QUANTKIT_EXPORT ObjectTable
{
public:
	ObjectTable();
	~ObjectTable();

	ObjectTable(const ObjectTable &other);
	ObjectTable& operator=(const ObjectTable &other);
	bool operator==(const ObjectTable &other) const;
	inline bool operator!=(const ObjectTable &other) const { return !(this->operator==(other));  }
public:
	int size() const;
	QVariant item(int index) const;
	void setItem(int index, const QVariant& value);
	void clear();
	void copyTo(const ObjectTable& table);
	double getDouble(int index);
	int getInt(int index);
	QString getString(int index);
	void remove(int id);

private:
	QSharedDataPointer<ObjectTablePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ObjectTable& objecttable);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ObjectTable& objecttable);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ObjectTable)

#endif // __QUANTKIT_OBJECTTABLE_H__
