#ifndef __QUANTKIT_MEMORYSERIES_H__
#define __QUANTKIT_MEMORYSERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/IDataSeries.h>
#include <QuantKit/SearchOption.h>

namespace QuantKit {

class MemorySeriesPrivate;

class DataObject;

class QUANTKIT_EXPORT MemorySeries : public IDataSeries
{
public:
	MemorySeries();
	MemorySeries(const QString& name, const QString& description = "");
	~MemorySeries();

	MemorySeries(const MemorySeries &other);
	MemorySeries& operator=(const MemorySeries &other);
	bool operator==(const MemorySeries &other) const;
	inline bool operator!=(const MemorySeries &other) const { return !(this->operator==(other));  }
public:
	long count() const;
	QString name() const;
	QString description() const;
	QDateTime dateTime1() const;
	QDateTime dateTime2() const;
	DataObject item(long index) const;
	void add(const DataObject& obj);
	void clear();
	bool contains(const QDateTime& dateTime);
	long getIndex(const QDateTime& dateTime, SearchOption option = SearchOption::Prev);
	void remove(long index);

private:
	QSharedDataPointer<MemorySeriesPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const MemorySeries& memoryseries);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const MemorySeries& memoryseries);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::MemorySeries)

#endif // __QUANTKIT_MEMORYSERIES_H__
