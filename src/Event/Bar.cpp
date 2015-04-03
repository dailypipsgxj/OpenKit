#include <QuantKit/Event/Bar.h>

#include <QuantKit/IdArray.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class BarPrivate : public DataObjectPrivate
{
public:
	int m_instrumentId;
	BarType m_type;
	long m_size;
	QDateTime m_openDateTime;
	double m_high;
	double m_low;
	double m_open;
	double m_close;
	long m_volume;
	long m_openInt;
	long m_n;
	double m_mean;
	double m_stdDev;
	BarStatus m_status;
	IdArray<double> m_item;
	Class32 m_item;

public:
	BarPrivate();
	BarPrivate(const QDateTime& openDateTime, const QDateTime& closeDateTime, int instrumentId, BarType type, long size, double open, double high, double low, double close, long volume, long openInt);
	virtual ~BarPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Bar; }
	BarType type() const { return m_type; }
	void setType(BarType value) { m_type = value; }
	QDateTime closeDateTime() const { return m_entryDate; }
	QDateTime openDateTime() const { return m_openDateTime; }
	TimeSpan duration() const
	{
		return m_entryDate - m_openDateTime;
	}

	int instrumentId() const { return m_instrumentId; }
	void setInstrumentId(int value) { m_instrumentId = value; }
	BarStatus status() const { return m_status; }
	void setStatus(BarStatus value) { m_status = value; }
	double open() const { return m_open; }
	void setOpen(double value) { m_open = value; }
	double high() const { return m_high; }
	void setHigh(double value) { m_high = value; }
	double low() const { return m_low; }
	void setLow(double value) { m_low = value; }
	double close() const { return m_close; }
	void setClose(double value) { m_close = value; }
	long volume() const { return m_volume; }
	void setVolume(long value) { m_volume = value; }
	long openInt() const { return m_openInt; }
	void setOpenInt(long value) { m_openInt = value; }
	long n() const { return m_n; }
	void setN(long value) { m_n = value; }
	long size() const { return m_size; }
	void setSize(long value) { m_size = value; }
	double mean() const { return m_mean; }
	void setMean(double value) { m_mean = value; }
	double variance() const { return m_stdDev; }
	void setVariance(double value) { m_stdDev = value; }
	double stdDev() const { return Math.Sqrt(m_stdDev); }
	double range() const { return m_high - m_low; }
	double median() const { return (m_high + m_low) / 2.0; }
	double typical() const
	{
		return (m_high + m_low + m_close) / 3.0;
	}

	double weighted() const
	{
		return (m_high + m_low + 2.0 * m_close) / 4.0;
	}

	double average() const
	{
		return (m_open + m_high + m_low + m_close) / 4.0;
	}

	double item(unsigned char index) const { return m_item[(int)index]; }
	void setItem(unsigned char index, double value);
	double item(const QString& name) const
	{
		return m_item[(int)Bar.item()[name]];
	}

	void setItem(const QString& name, double value)
	{
		this[Bar.item()[name]] = value;
	}

	void addField(const QString& name, unsigned char index) { Bar.item().Add(name, index); }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Bar"; }
	virtual BarPrivate* clone() Q_DECL_OVERRIDE { return new BarPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BarPrivate::BarPrivate()
	: m_type(BarType.Time)
	, m_openDateTime(DateTime.MinValue)
	, m_close(double.NaN)
{
}

BarPrivate::BarPrivate(const QDateTime& openDateTime, const QDateTime& closeDateTime, int instrumentId, BarType type, long size, double open, double high, double low, double close, long volume, long openInt)
	: DataObjectPrivate (closeDateTime)
	, m_instrumentId(instrumentId)
	, m_type(BarType.Time)
	, m_type(type)
	, m_size(size)
	, m_openDateTime(DateTime.MinValue)
	, m_openDateTime(openDateTime)
	, m_high(high)
	, m_low(low)
	, m_open(open)
	, m_close(double.NaN)
	, m_close(close)
	, m_volume(volume)
	, m_openInt(openInt)
	, m_status(BarStatus.Open)
	, m_status(BarStatus.Close)
{
		if (openDateTime == closeDateTime)
		{
			return;
		}
}

BarPrivate::~BarPrivate ()
{
}

void BarPrivate::setItem(unsigned char index, double value)
{
	if (m_item == null)
	{
		m_item = new IdArray<double>(10);
	}
	m_item[(int)index] = value;
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Bar)

Bar::Bar()
	: DataObject(*new BarPrivate)
{
}

Bar::Bar(const QDateTime& openDateTime, const QDateTime& closeDateTime, int instrumentId, BarType type, long size, double open, double high, double low, double close, long volume, long openInt)
	: DataObject(*new BarPrivate(openDateTime, closeDateTime, instrumentId, type, size, open, high, low, close, volume, openInt))
{
}

Bar::~Bar()
{
}

BarType Bar::type() const
{
	Q_D(const Bar);
	return d->type();
}

void Bar::setType(BarType value)
{
	Q_D(Bar);
	d->setType(value);
}

QDateTime Bar::closeDateTime() const
{
	Q_D(const Bar);
	return d->closeDateTime();
}

QDateTime Bar::openDateTime() const
{
	Q_D(const Bar);
	return d->openDateTime();
}

TimeSpan Bar::duration() const
{
	Q_D(const Bar);
	return d->duration();
}

int Bar::instrumentId() const
{
	Q_D(const Bar);
	return d->instrumentId();
}

void Bar::setInstrumentId(int value)
{
	Q_D(Bar);
	d->setInstrumentId(value);
}

BarStatus Bar::status() const
{
	Q_D(const Bar);
	return d->status();
}

void Bar::setStatus(BarStatus value)
{
	Q_D(Bar);
	d->setStatus(value);
}

double Bar::open() const
{
	Q_D(const Bar);
	return d->open();
}

void Bar::setOpen(double value)
{
	Q_D(Bar);
	d->setOpen(value);
}

double Bar::high() const
{
	Q_D(const Bar);
	return d->high();
}

void Bar::setHigh(double value)
{
	Q_D(Bar);
	d->setHigh(value);
}

double Bar::low() const
{
	Q_D(const Bar);
	return d->low();
}

void Bar::setLow(double value)
{
	Q_D(Bar);
	d->setLow(value);
}

double Bar::close() const
{
	Q_D(const Bar);
	return d->close();
}

void Bar::setClose(double value)
{
	Q_D(Bar);
	d->setClose(value);
}

long Bar::volume() const
{
	Q_D(const Bar);
	return d->volume();
}

void Bar::setVolume(long value)
{
	Q_D(Bar);
	d->setVolume(value);
}

long Bar::openInt() const
{
	Q_D(const Bar);
	return d->openInt();
}

void Bar::setOpenInt(long value)
{
	Q_D(Bar);
	d->setOpenInt(value);
}

long Bar::n() const
{
	Q_D(const Bar);
	return d->n();
}

void Bar::setN(long value)
{
	Q_D(Bar);
	d->setN(value);
}

long Bar::size() const
{
	Q_D(const Bar);
	return d->size();
}

void Bar::setSize(long value)
{
	Q_D(Bar);
	d->setSize(value);
}

double Bar::mean() const
{
	Q_D(const Bar);
	return d->mean();
}

void Bar::setMean(double value)
{
	Q_D(Bar);
	d->setMean(value);
}

double Bar::variance() const
{
	Q_D(const Bar);
	return d->variance();
}

void Bar::setVariance(double value)
{
	Q_D(Bar);
	d->setVariance(value);
}

double Bar::stdDev() const
{
	Q_D(const Bar);
	return d->stdDev();
}

double Bar::range() const
{
	Q_D(const Bar);
	return d->range();
}

double Bar::median() const
{
	Q_D(const Bar);
	return d->median();
}

double Bar::typical() const
{
	Q_D(const Bar);
	return d->typical();
}

double Bar::weighted() const
{
	Q_D(const Bar);
	return d->weighted();
}

double Bar::average() const
{
	Q_D(const Bar);
	return d->average();
}

double Bar::item(unsigned char index) const
{
	Q_D(const Bar);
	return d->item(index);
}

void Bar::setItem(unsigned char index, double value)
{
	Q_D(Bar);
	d->setItem(index, value);
}

double Bar::item(const QString& name) const
{
	Q_D(const Bar);
	return d->item(name);
}

void Bar::setItem(const QString& name, double value)
{
	Q_D(Bar);
	d->setItem(name, value);
}

void Bar::addField(const QString& name, unsigned char index)
{
	Q_D(Bar);
	d->addField(name, index);
}


