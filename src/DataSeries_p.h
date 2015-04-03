#ifndef __QUANTKIT_DATASERIES_PRIVATE_H__
#define __QUANTKIT_DATASERIES_PRIVATE_H__

#include <QuantKit/DataSeries.h>

#include <QSharedData>

#include "DataFile_p.h"
#include "ObjectKey_p.h"
#include "DataObject_p.h"
#include "IdArray_p.h"

namespace QuantKit {

class DataSeriesPrivate : public QSharedData
{
public:
	QString m_name;
	QString m_description;
	DataFile dataFile_0;
	ObjectKey objectKey_0;
	long m_count;
	int int_0;
	QDateTime m_dateTime1;
	QDateTime m_dateTime2;
	long long_1;
	long long_2;
	bool bool_0;
	bool bool_1;
	Class44 class44_0;
	Class44 class44_1;
	Class44 class44_2;
	Class44 class44_3;
	IdArray<Class44> m_idArray;
	ObjectKey objectKey_1;
	long long_3;
	bool m_cacheObjects;
	bool bool_3;

public:
	DataSeriesPrivate();
	explicit DataSeriesPrivate(const QString& name);
	virtual ~DataSeriesPrivate();

public:
	int getInt_0() const;
	void setInt_0(int value);

	long getLong_1() const;
	void setLong_1(long value);

	long getLong_2() const;
	void setLong_2(long value);

	Class44 getClass44_0() const;
	void setClass44_0(Class44 value);

	long getLong_3() const;
	void setLong_3(long value);
	bool getBool_0() const;

	bool getBool_3() const;
	QString name() const { return m_name; }
	QString description() const { return m_description; }
	long count() const { return m_count; }
	QDateTime dateTime1() const { return m_dateTime1; }
	QDateTime dateTime2() const { return m_dateTime2; }
	bool cacheObjects() const { return m_cacheObjects; }
	void setCacheObjects(bool value) { m_cacheObjects = value; }
	DataObject item(long index) const { return Get(index); }
	DataObject item(const QDateTime& dateTime) const { return Get(dateTime); }
	virtual void add(const DataObject& obj) Q_DECL_OVERRIDE;
	virtual void clear() Q_DECL_OVERRIDE;
	virtual bool contains(const QDateTime& dateTime) Q_DECL_OVERRIDE
	{
		return GetIndex(dateTime, SearchOption.ExactFirst) != -1L;
	}

	void dump();
	virtual DataObject get(long index) Q_DECL_OVERRIDE;
	virtual DataObject get(const QDateTime& dateTime) Q_DECL_OVERRIDE;
	virtual long getIndex(const QDateTime& dateTime, SearchOption option) Q_DECL_OVERRIDE;
	virtual void refresh() Q_DECL_OVERRIDE;
	virtual void remove(long index) Q_DECL_OVERRIDE;
	virtual QString toString() const Q_DECL_OVERRIDE { return "DataSeries"; }
	virtual void update(long index, const DataObject& obj) Q_DECL_OVERRIDE;
//protected
	void method_0(const DataFile& dataFile_1, const ObjectKey& objectKey_2);
	void method_1();
	Class44 method_16(long long_4, const Class44& class44_4);
	Class44 method_17(const QDateTime& dateTime_2, const Class44& class44_4, Enum1 enum1);
	void method_18();
	void method_2();

//private:
	void method_10(long long_4, long long_5);
	void method_11(long long_4, long long_5);
	void method_12(const Class44& class44_4);
	Class44 method_13(long long_4);
	Class44 method_14();
	Class44 method_15(const Class44& class44_4);
	void method_3();
	void method_4();
	void method_5(const DataObject& dataObject);
	void method_6(const Class44& class44_4, const Class44& class44_5);
	void method_7(const Class44& class44_4);
	void method_8(const Class44& class44_4, long long_4);
	void method_9(const Class44& class44_4, long long_4);
};

} // namepsace QuantKit

#endif // __QUANTKIT_DATASERIES_PRIVATE_H__
