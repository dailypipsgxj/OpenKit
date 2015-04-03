#ifndef __QUANTKIT_IDATASERIES_H__
#define __QUANTKIT_IDATASERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>

#include <QuantKit/SearchOption.h>

namespace QuantKit {

class DataObject;

class QUANTKIT_EXPORT IDataSeries
{
public:
	virtual long count() const = 0;
	virtual QString name() const = 0;
	virtual QString description() const = 0;
	virtual QDateTime dateTime1() const = 0;
	virtual QDateTime dateTime2() const = 0;
	virtual DataObject item(long index) const = 0;
	virtual void add(const DataObject& obj) = 0;
	virtual void clear() = 0;
	virtual bool contains(const QDateTime& dateTime) = 0;
	virtual long getIndex(const QDateTime& dateTime, SearchOption option = SearchOption::Prev) = 0;
	virtual void remove(long index) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IDATASERIES_H__
