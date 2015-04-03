#ifndef __QUANTKIT_DATASERIES_H__
#define __QUANTKIT_DATASERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <Enum1>
#include <QSharedDataPointer>

#include <QuantKit/IDataSeries.h>
#include <QuantKit/SearchOption.h>

namespace QuantKit {

class DataSeriesPrivate;

class DataFile;
class ObjectKey;
class DataObject;
class IdArray;

class QUANTKIT_EXPORT DataSeries : public IDataSeries
{
public:
	DataSeries();
	explicit DataSeries(const QString& name);
	~DataSeries();

	DataSeries(const DataSeries &other);
	DataSeries& operator=(const DataSeries &other);
	bool operator==(const DataSeries &other) const;
	inline bool operator!=(const DataSeries &other) const { return !(this->operator==(other));  }
public:
	int int_0() const;
	void setInt_0(int value);

	long long_1() const;
	void setLong_1(long value);

	long long_2() const;
	void setLong_2(long value);

	Class44 class44_0() const;
	void setClass44_0(Class44 value);

	long long_3() const;
	void setLong_3(long value);
	bool bool_0() const;

	bool bool_3() const;
	QString name() const;
	QString description() const;
	long count() const;
	QDateTime dateTime1() const;
	QDateTime dateTime2() const;
	bool cacheObjects() const;
	void setCacheObjects(bool value);
	DataObject item(long index) const;
	DataObject item(const QDateTime& dateTime) const;
	void add(const DataObject& obj);
	void clear();
	bool contains(const QDateTime& dateTime);
	void dump();
	DataObject get(long index);
	DataObject get(const QDateTime& dateTime);
	long getIndex(const QDateTime& dateTime, SearchOption option = SearchOption::Prev);
	void refresh();
	void remove(long index);
	QString toString() const;
	void update(long index, const DataObject& obj);

protected:
	DataSeries(DataSeriesPrivate& dd);
	QSharedDataPointer<DataSeriesPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const DataSeries& dataseries);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataSeries& dataseries);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataSeries)

#endif // __QUANTKIT_DATASERIES_H__
