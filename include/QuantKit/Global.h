#ifndef __QUANTKIT_GLOBAL_H__
#define __QUANTKIT_GLOBAL_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <IEnumerator>
#include <Dictionary>
#include <QSharedDataPointer>

namespace QuantKit {

class GlobalPrivate;

class QUANTKIT_EXPORT Global
{
public:
	Global();
	~Global();

	Global(const Global &other);
	Global& operator=(const Global &other);
	bool operator==(const Global &other) const;
	inline bool operator!=(const Global &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	QVariant item(const QString& key) const;
	void setItem(const QString& key, const QVariant& value);
	void add(const QString& key, const QVariant& obj);
	void clear();
	bool containsKey(const QString& key);
	bool containsValue(const QVariant& obj);
	double getDouble(const QString& key);
	int getInt(const QString& key);
	QString getString(const QString& key);
	void remove(const QString& key);

private:
	QSharedDataPointer<GlobalPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Global& global);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Global& global);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Global)

#endif // __QUANTKIT_GLOBAL_H__
