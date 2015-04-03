#include <QuantKit/HistoricalDataRequest.h>

#include <QuantKit/Instrument.h>

namespace QuantKit {

class HistoricalDataRequestPrivate : public QSharedData
{
public:
	QString m_requestId;
	Instrument m_instrument;
	QDateTime m_dateTime1;
	QDateTime m_dateTime2;
	unsigned char m_dataType;
	Nullable`1<BarType> m_barType;
	Nullable`1<long> m_barSize;

public:
	HistoricalDataRequestPrivate();
	HistoricalDataRequestPrivate(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, unsigned char dataType);
	virtual ~HistoricalDataRequestPrivate();

public:
	QString requestId() const { return m_requestId; }
	void setRequestId(const QString& value) { m_requestId = value; }
	Instrument instrument() const { return m_instrument; }
	void setInstrument(const Instrument& value) { m_instrument = value; }
	QDateTime dateTime1() const { return m_dateTime1; }
	void setDateTime1(const QDateTime& value) { m_dateTime1 = value; }
	QDateTime dateTime2() const { return m_dateTime2; }
	void setDateTime2(const QDateTime& value) { m_dateTime2 = value; }
	unsigned char dataType() const { return m_dataType; }
	void setDataType(unsigned char value) { m_dataType = value; }
	Nullable`1<BarType> barType() const { return m_barType; }
	void setBarType(const Nullable`1<BarType>& value) { m_barType = value; }
	Nullable`1<long> barSize() const { return m_barSize; }
	void setBarSize(const Nullable`1<long>& value) { m_barSize = value; }
	virtual HistoricalDataRequestPrivate* clone() Q_DECL_OVERRIDE { return new HistoricalDataRequestPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

HistoricalDataRequestPrivate::HistoricalDataRequestPrivate()
{
}

HistoricalDataRequestPrivate::HistoricalDataRequestPrivate(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, unsigned char dataType)
	: m_instrument(instrument)
	, m_dateTime1(dateTime1)
	, m_dateTime2(dateTime2)
	, m_dataType(dataType)
{
}

HistoricalDataRequestPrivate::~HistoricalDataRequestPrivate ()
{
}


// Pubic API 

HistoricalDataRequest::HistoricalDataRequest()
	: d_ptr(new HistoricalDataRequestPrivate)
{
}

HistoricalDataRequest::HistoricalDataRequest(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, unsigned char dataType)
	: d_ptr(new HistoricalDataRequestPrivate(instrument, dateTime1, dateTime2, dataType))
{
}

HistoricalDataRequest::~HistoricalDataRequest()
{
}

HistoricalDataRequest::HistoricalDataRequest (const HistoricalDataRequest &other)
	: d_ptr(other.d_ptr)
{
}

HistoricalDataRequest& HistoricalDataRequest::operator=(const HistoricalDataRequest &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool HistoricalDataRequest::operator==(const HistoricalDataRequest &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString HistoricalDataRequest::requestId() const
{
	return d_ptr->requestId();
}

void HistoricalDataRequest::setRequestId(const QString& value)
{
	d_ptr->setRequestId(value);
}

Instrument HistoricalDataRequest::instrument() const
{
	return d_ptr->instrument();
}

void HistoricalDataRequest::setInstrument(const Instrument& value)
{
	d_ptr->setInstrument(value);
}

QDateTime HistoricalDataRequest::dateTime1() const
{
	return d_ptr->dateTime1();
}

void HistoricalDataRequest::setDateTime1(const QDateTime& value)
{
	d_ptr->setDateTime1(value);
}

QDateTime HistoricalDataRequest::dateTime2() const
{
	return d_ptr->dateTime2();
}

void HistoricalDataRequest::setDateTime2(const QDateTime& value)
{
	d_ptr->setDateTime2(value);
}

unsigned char HistoricalDataRequest::dataType() const
{
	return d_ptr->dataType();
}

void HistoricalDataRequest::setDataType(unsigned char value)
{
	d_ptr->setDataType(value);
}

Nullable`1<BarType> HistoricalDataRequest::barType() const
{
	return d_ptr->barType();
}

void HistoricalDataRequest::setBarType(const Nullable`1<BarType>& value)
{
	d_ptr->setBarType(value);
}

Nullable`1<long> HistoricalDataRequest::barSize() const
{
	return d_ptr->barSize();
}

void HistoricalDataRequest::setBarSize(const Nullable`1<long>& value)
{
	d_ptr->setBarSize(value);
}

QDebug operator<<(QDebug dbg, const HistoricalDataRequest& historicaldatarequest)
{
	return dbg << historicaldatarequest.toString();
}

