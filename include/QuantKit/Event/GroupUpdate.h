#ifndef __QUANTKIT_GROUPUPDATE_H__
#define __QUANTKIT_GROUPUPDATE_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QVariant>

#include <QuantKit/DataObject.h>
#include <QuantKit/GroupUpdateType.h>

namespace QuantKit {

class GroupUpdatePrivate;

class QUANTKIT_EXPORT GroupUpdate Q_DECL_FINAL : public DataObject
{
public:
	GroupUpdate(int groupId, const QString& fieldName, unsigned char fieldType, const QVariant& value, const QVariant& oldValue, GroupUpdateType updateType);
	~GroupUpdate();

public:
	int groupId() const;
	QString fieldName() const;
	GroupUpdateType updateType() const;
	unsigned char fieldType() const;
	QVariant value() const;
	QVariant oldValue() const;

private:
	QK_DECLARE_PRIVATE(GroupUpdate)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupUpdate)

#endif // __QUANTKIT_GROUPUPDATE_H__
