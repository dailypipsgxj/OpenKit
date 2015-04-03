#include <QuantKit/BarFactoryItem.h>

#include <QuantKit/Instrument.h>
#include "DataObject_p.h"
#include <QuantKit/BarFactory.h>
#include <QuantKit/Event/Bar.h>
#include "BarFactoryItem_p.h"

using namespace QuantKit;

BarFactoryItemPrivate::BarFactoryItemPrivate(const Instrument& instrument, BarType barType, long barSize, BarInput barInput)
	: m_factory(null)
	, m_instrument(instrument)
	, m_barType(barType)
	, m_barSize(barSize)
	, m_barInput(barInput)
{
}

BarFactoryItemPrivate::BarFactoryItemPrivate(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: m_factory(null)
	, m_instrument(instrument)
	, m_barType(barType)
	, m_barSize(barSize)
	, m_barInput(barInput)
	, m_sessionEnabled(true)
	, session1(session1)
	, session2(session2)
{
}

BarFactoryItemPrivate::~BarFactoryItemPrivate ()
{
}

BarFactory getFactory() const
{
	return null;
}
void setFactory(BarFactory value)
{
}

Instrument getInstrument() const
{
	return null;
}

long getBarSize() const
{
	return 0;
}

BarInput getBarInput() const
{
	return null;
}

TimeSpan getSession1() const
{
	return null;
}

TimeSpan getSession2() const
{
	return null;
}

Bar getBar() const
{
	return null;
}
//protected
void BarFactoryItemPrivate::emitBar()
{
	bar.setStatus() = BarStatus.Close;
	m_factory.framework().eventServer().OnEvent(bar);
	bar = null;
}

QDateTime BarFactoryItemPrivate::getDataObjectDateTime(const DataObject& obj, ClockType type)
{
	if (type == ClockType.Local)
	{
		return obj.entryDate();
	}
	return ((Tick)obj).exchangeDateTime();
}

bool BarFactoryItemPrivate::inSession(const QDateTime& dateTime)
{
	if (m_sessionEnabled)
	{
		TimeSpan timeOfDay = dateTime.TimeOfDay;
		if (timeOfDay < session1 || timeOfDay > session2)
		{
			return false;
		}
	}
	return true;
}

void BarFactoryItemPrivate::method_0(const DataObject& dataObject)
{
	if (!InSession(dataObject.entryDate()))
	{
		return;
	}
	OnData(dataObject);
}

void BarFactoryItemPrivate::onData(const DataObject& obj)
{
	Tick tick = (Tick)obj;
	if (bar == null)
	{
		bar = new Bar();
		bar.setInstrumentId() = tick.instrumentId();
		bar.setType() = m_barType;
		bar.setSize() = m_barSize;
		bar.setOpenDateTime() = GetBarOpenDateTime(obj);
		bar.setEntryDate() = GetDataObjectDateTime(obj, ClockType.Local);
		bar.setOpen() = tick.price();
		bar.setHigh() = tick.price();
		bar.setLow() = tick.price();
		bar.setClose() = tick.price();
		bar.setVolume() = (long)tick.size();
		bar.setStatus() = BarStatus.Open;
		m_factory.framework().eventServer().OnEvent(bar);
	}
	else
	{
		if (tick.price() > bar.high())
		{
			bar.setHigh() = tick.price();
		}
		if (tick.price() < bar.low())
		{
			bar.setLow() = tick.price();
		}
		bar.setClose() = tick.price();
		bar.setVolume() += (long)tick.size();
		bar.setEntryDate() = GetDataObjectDateTime(obj, ClockType.Local);
	}
	bar.setN() += 1L;
}

void BarFactoryItemPrivate::onReminder(const QDateTime& datetime)
{
}


// Pubic API 

BarFactoryItem::BarFactoryItem(const Instrument& instrument, BarType barType, long barSize, BarInput barInput)
	: d_ptr(new BarFactoryItemPrivate(instrument, barType, barSize, barInput))
{
}

BarFactoryItem::BarFactoryItem(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: d_ptr(new BarFactoryItemPrivate(instrument, barType, barSize, barInput, session1, session2))
{
}

BarFactoryItem::~BarFactoryItem()
{
}

BarFactoryItem::BarFactoryItem (BarFactoryItemPrivate &dd)
	: d_ptr(&dd)
{
}

BarFactoryItem::BarFactoryItem (const BarFactoryItem &other)
	: d_ptr(other.d_ptr)
{
}

BarFactoryItem& BarFactoryItem::operator=(const BarFactoryItem &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BarFactoryItem::operator==(const BarFactoryItem &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

BarFactory factory() const
{
	return d_ptr->
	setFactory()
}

void setFactory(BarFactory value)
{
	d_ptr->factory(value);
}

Instrument instrument() const
{
	return d_ptr->
	setInstrument()
}

long barSize() const
{
	return d_ptr->
	setBarSize()
}

BarInput barInput() const
{
	return d_ptr->
	setBarInput()
}

TimeSpan session1() const
{
	return d_ptr->
	setSession1()
}

TimeSpan session2() const
{
	return d_ptr->
	setSession2()
}

Bar bar() const
{
	return d_ptr->
	setBar()
}

QString BarFactoryItem::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const BarFactoryItem& barfactoryitem)
{
	return dbg << barfactoryitem.toString();
}

