#ifndef __QUANTKIT_GROUP_H__
#define __QUANTKIT_GROUP_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <Dictionary>
#include <QList>
#include <QVariant>
#include <Color>
#include <QDateTime>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class GroupPrivate;

class GroupField;
class Framework;
class GroupEvent;

class QUANTKIT_EXPORT Group Q_DECL_FINAL : public DataObject
{
public:
	explicit Group(const QString& name);
	~Group();

public:
	int id() const;
	QString name() const;
	Dictionary<QString,GroupField> fields() const;
	Framework framework() const;
	void setFramework(const Framework& value);
	QList<GroupEvent> events() const;
	void add(const QString& name, unsigned char type, const QVariant& value);
	void add(const QString& name, const Color& color);
	void add(const QString& name, const QString& value);
	void add(const QString& name, int value);
	void add(const QString& name, bool value);
	void add(const QString& name, const QDateTime& dateTime);
	void onNewGroupEvent(const GroupEvent& groupEvent);
	void remove(const QString& fieldName);

private:
	QK_DECLARE_PRIVATE(Group)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Group)

#endif // __QUANTKIT_GROUP_H__
