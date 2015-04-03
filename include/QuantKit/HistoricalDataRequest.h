#ifndef __QUANTKIT_HISTORICALDATAREQUEST_H__
#define __QUANTKIT_HISTORICALDATAREQUEST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <Nullable`1>
#include <QSharedDataPointer>

#include <QuantKit/BarType.h>

namespace QuantKit {

class HistoricalDataRequestPrivate;

class Instrument;

class QUANTKIT_EXPORT HistoricalDataRequest
{
public:
	HistoricalDataRequest();
	HistoricalDataRequest(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, unsigned char dataType);
	~HistoricalDataRequest();

	HistoricalDataRequest(const HistoricalDataRequest &other);
	HistoricalDataRequest& operator=(const HistoricalDataRequest &other);
	bool operator==(const HistoricalDataRequest &other) const;
	inline bool operator!=(const HistoricalDataRequest &other) const { return !(this->operator==(other));  }
public:
	QString requestId() const;
	void setRequestId(const QString& value);
	Instrument instrument() const;
	void setInstrument(const Instrument& value);
	QDateTime dateTime1() const;
	void setDateTime1(const QDateTime& value);
	QDateTime dateTime2() const;
	void setDateTime2(const QDateTime& value);
	unsigned char dataType() const;
	void setDataType(unsigned char value);
	Nullable`1<BarType> barType() const;
	void setBarType(const Nullable`1<BarType>& value);
	Nullable`1<long> barSize() const;
	void setBarSize(const Nullable`1<long>& value);

private:
	QSharedDataPointer<HistoricalDataRequestPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const HistoricalDataRequest& historicaldatarequest);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const HistoricalDataRequest& historicaldatarequest);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::HistoricalDataRequest)

#endif // __QUANTKIT_HISTORICALDATAREQUEST_H__
