#ifndef __QUANTKIT_OBJECTKEY_H__
#define __QUANTKIT_OBJECTKEY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QByteArray>
#include <QDateTime>
#include <QSharedDataPointer>

namespace QuantKit {

class ObjectKeyPrivate;

class DataFile;

class QUANTKIT_EXPORT ObjectKey
{
public:
	ObjectKey();
	ObjectKey(const DataFile& file, const QString& name = "", const QVariant& obj = 0);
	~ObjectKey();

	ObjectKey(const ObjectKey &other);
	ObjectKey& operator=(const ObjectKey &other);
	bool operator==(const ObjectKey &other) const;
	inline bool operator!=(const ObjectKey &other) const { return !(this->operator==(other));  }
public:
	DataFile dataFile_0() const;
	void setDataFile_0(DataFile value);

	Class45 class45_0() const;
	void setClass45_0(Class45 value);

	QString string_0() const;
	void setString_0(QString value);

	bool bool_0() const;
	void setBool_0(bool value);

	QDateTime dateTime_0() const;
	void setDateTime_0(QDateTime value);

	long long_0() const;
	void setLong_0(long value);

	int int_0() const;
	void setInt_0(int value);

	int int_1() const;
	void setInt_1(int value);

	int int_2() const;
	void setInt_2(int value);

	unsigned char byte_0() const;
	void setByte_0(unsigned char value);

	unsigned char byte_1() const;
	void setByte_1(unsigned char value);

	QString string_1() const;
	void setString_1(QString value);

	bool changed() const;
	void setChanged(bool value);
	unsigned char typeId() const;
	int compareTo(const ObjectKey& other);
	void dump();
	QVariant getObject();

protected:
	ObjectKey(ObjectKeyPrivate& dd);
	QSharedDataPointer<ObjectKeyPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const ObjectKey& objectkey);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ObjectKey& objectkey);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ObjectKey)

#endif // __QUANTKIT_OBJECTKEY_H__
