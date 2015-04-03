#ifndef __QUANTKIT_QUOTESERIES_H__
#define __QUANTKIT_QUOTESERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/IDataSeries.h>
#include <QuantKit/SearchOption.h>
#include <QuantKit/IndexOption.h>

namespace QuantKit {

class QuoteSeriesPrivate;

class Quote;
class DataObject;

class QUANTKIT_EXPORT QuoteSeries : public IDataSeries
{
public:
	explicit QuoteSeries(const QString& name = "");
	~QuoteSeries();

	QuoteSeries(const QuoteSeries &other);
	QuoteSeries& operator=(const QuoteSeries &other);
	bool operator==(const QuoteSeries &other) const;
	inline bool operator!=(const QuoteSeries &other) const { return !(this->operator==(other));  }
public:
	QString name() const;
	QString description() const;
	int count() const;
	QDateTime firstDateTime() const;
	QDateTime lastDateTime() const;
	Quote item(int index) const;
	void add(const Quote& quote);
	void clear();
	bool contains(const QDateTime& dateTime);
	int getIndex(const QDateTime& datetime, IndexOption option);

private:
	QSharedDataPointer<QuoteSeriesPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const QuoteSeries& quoteseries);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const QuoteSeries& quoteseries);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::QuoteSeries)

#endif // __QUANTKIT_QUOTESERIES_H__
