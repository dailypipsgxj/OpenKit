#ifndef __QUANTKIT_GROUPFIELD_H__
#define __QUANTKIT_GROUPFIELD_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class GroupFieldPrivate;

class Group;

class QUANTKIT_EXPORT GroupField
{
public:
	GroupField(const QString& name, unsigned char type, const QVariant& value);
	~GroupField();

	GroupField(const GroupField &other);
	GroupField& operator=(const GroupField &other);
	bool operator==(const GroupField &other) const;
	inline bool operator!=(const GroupField &other) const { return !(this->operator==(other));  }
public:
	Group group_0() const;
	void setGroup_0(Group value);
	QString name() const;
	unsigned char type() const;
	QVariant value() const;
	void setValue(const QVariant& value);

private:
	QSharedDataPointer<GroupFieldPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const GroupField& groupfield);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const GroupField& groupfield);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupField)

#endif // __QUANTKIT_GROUPFIELD_H__
