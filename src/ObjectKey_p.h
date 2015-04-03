#ifndef __QUANTKIT_OBJECTKEY_PRIVATE_H__
#define __QUANTKIT_OBJECTKEY_PRIVATE_H__

#include <QuantKit/ObjectKey.h>

#include <QSharedData>

#include "DataFile_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class ObjectKeyPrivate : public QSharedData
{
public:
	DataFile dataFile_0;
	Class45 class45_0;
	QString string_0;
	bool bool_0;
	QDateTime dateTime_0;
	long long_0;
	int int_0;
	int int_1;
	int int_2;
	unsigned char byte_0;
	unsigned char byte_1;
	unsigned char m_typeId;
	QString string_1;
	bool changed;

public:
	ObjectKeyPrivate();
	ObjectKeyPrivate(const DataFile& file, const QString& name, const QVariant& obj);
	virtual ~ObjectKeyPrivate();

public:
	DataFile getDataFile_0() const;
	void setDataFile_0(DataFile value);

	Class45 getClass45_0() const;
	void setClass45_0(Class45 value);

	QString getString_0() const;
	void setString_0(QString value);

	bool getBool_0() const;
	void setBool_0(bool value);

	QDateTime getDateTime_0() const;
	void setDateTime_0(QDateTime value);

	long getLong_0() const;
	void setLong_0(long value);

	int getInt_0() const;
	void setInt_0(int value);

	int getInt_1() const;
	void setInt_1(int value);

	int getInt_2() const;
	void setInt_2(int value);

	unsigned char getByte_0() const;
	void setByte_0(unsigned char value);

	unsigned char getByte_1() const;
	void setByte_1(unsigned char value);

	QString getString_1() const;
	void setString_1(QString value);

	bool getChanged() const;
	void setChanged(bool value);
	unsigned char typeId() const { return EventType::ObjectKey; }
	int compareTo(const ObjectKey& other);
	virtual void dump() Q_DECL_OVERRIDE;
	virtual QVariant getObject() Q_DECL_OVERRIDE;
//protected
	void method_0(const DataFile& dataFile_1);
	unsigned char method_1(bool bool_1);
	virtual void read(const QByteArray& reader, bool readLabel) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer) Q_DECL_OVERRIDE;
	virtual void writeKey(const QByteArray& writer) Q_DECL_OVERRIDE;
	virtual unsigned char writeObjectData(bool compress) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_OBJECTKEY_PRIVATE_H__
