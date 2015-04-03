#include <QuantKit/BarFactory.h>

#include <QuantKit/Framework.h>
#include "BarFactoryItem_p.h"
#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentList.h>
#include "DataObject_p.h"

namespace QuantKit {

class BarFactoryPrivate : public QSharedData
{
public:
	Framework m_framework;
	IdArray<QList<BarFactoryItem>> itemLists;
	SortedList<QDateTime,SortedList<long,QList<BarFactoryItem>>> sortedList_0;

public:
	explicit BarFactoryPrivate(const Framework& framework);
	virtual ~BarFactoryPrivate();

public:
	Framework getFramework() const;
	void add(const BarFactoryItem& item);
	void add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, ClockType type);
	void add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	void add(const QString& symbol, BarType barType, long barSize, BarInput barInput, ClockType type)
	{
		Add(m_framework.instrumentManager()[symbol], barType, barSize, barInput, type);
	}

	void add(const InstrumentList& instruments, BarType barType, long barSize, BarInput barInput, ClockType type);
	void add(const QString& symbols, BarType barType, long barSize, BarInput barInput, ClockType type);
	void add(const Instrument& instrument, BarType barType, long barSize, const TimeSpan& session1, const TimeSpan& session2)
	{
		Add(instrument, barType, barSize, BarInput.Trade, ClockType.Local, session1, session2);
	}

	void add(const QString& symbol, BarType barType, long barSize, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2)
	{
		Add(m_framework.instrumentManager()[symbol], barType, barSize, barInput, type, session1, session2);
	}

	void add(const QString& symbol, BarType barType, long barSize, const TimeSpan& session1, const TimeSpan& session2)
	{
		Add(m_framework.instrumentManager()[symbol], barType, barSize, BarInput.Trade, ClockType.Local, session1, session2);
	}

	void add(const Instrument& instrument, const TimeSpan& session1, const TimeSpan& session2)
	{
		Add(instrument, BarType.Session, (long)(session2 - session1).Seconds, BarInput.Trade, ClockType.Local, session1, session2);
	}

	void add(const QString& symbol, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2)
	{
		Add(m_framework.instrumentManager()[symbol], BarType.Session, (long)(session2 - session1).Seconds, barInput, type, session1, session2);
	}

	void add(const QString& symbol, const TimeSpan& session1, const TimeSpan& session2)
	{
		Add(m_framework.instrumentManager()[symbol], BarType.Session, (long)(session2 - session1).Seconds, BarInput.Trade, ClockType.Local, session1, session2);
	}

	virtual BarFactoryPrivate* clone() Q_DECL_OVERRIDE { return new BarFactoryPrivate(*this); }
//private:
	void method_3(const QDateTime& dateTime, const QVariant& object);
};

} // namepsace QuantKit


using namespace QuantKit;

BarFactoryPrivate::BarFactoryPrivate(const Framework& framework)
	: m_framework(framework)
	, itemLists(new IdArray<QList<BarFactoryItem>>(10000))
	, sortedList_0(new SortedQList<DateTime, SortedQList<long, QList<BarFactoryItem>>>())
{
}

BarFactoryPrivate::~BarFactoryPrivate ()
{
}

Framework getFramework() const
{
	return null;
}
void BarFactoryPrivate::add(const BarFactoryItem& item)
{
	if (item.factory() != null)
	{
		throw new InvalidOperationException("BarFactoryItem is already added to another BarFactory instance.");
	}
	item.setFactory() = this;
	int id = item.instrument().id();
	List<BarFactoryItem> list = itemLists[id];
	if (list == null)
	{
		list = new List<BarFactoryItem>();
		itemLists[id] = list;
	}
	if (list.Exists((BarFactoryItem match) => item.barType() == match.barType() && item.barSize() == match.barSize() && item.barInput() == match.barInput()))
	{
		Console.WriteLine("{0} BarFactory::Add Item '{1}' is already added", DateTime.Now, item);
		return;
	}
	list.Add(item);
}

void BarFactoryPrivate::add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, ClockType type)
{
	BarFactoryItem item;
	switch (barType)
	{
		case BarType.Time:
			item = new TimeBarFactoryItem(instrument, barSize, barInput, type);
			break;
		case BarType.Tick:
			item = new TickBarFactoryItem(instrument, barSize, barInput);
			break;
		case BarType.Volume:
			item = new VolumeBarFactoryItem(instrument, barSize, barInput);
			break;
		case BarType.Range:
			item = new RangeBarFactoryItem(instrument, barSize, barInput);
			break;
		case BarType.Session:
			throw new ArgumentException("BarFactory::Add Can not create SessionBarFactoryItem without session parameters");
		default:
			throw new ArgumentException(string.Format("Unknown bar type - {0}", barType));
	}
	Add(item);
}

void BarFactoryPrivate::add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
{
	BarFactoryItem item;
	switch (barType)
	{
		case BarType.Time:
			item = new TimeBarFactoryItem(instrument, barSize, barInput, type, session1, session2);
			break;
		case BarType.Tick:
			item = new TickBarFactoryItem(instrument, barSize, barInput, session1, session2);
			break;
		case BarType.Volume:
			item = new VolumeBarFactoryItem(instrument, barSize, barInput, session1, session2);
			break;
		case BarType.Range:
			item = new RangeBarFactoryItem(instrument, barSize, barInput, session1, session2);
			break;
		case BarType.Session:
			item = new SessionBarFactoryItem(instrument, barInput, type, session1, session2);
			break;
		default:
			throw new ArgumentException(string.Format("Unknown bar type - {0}", barType));
	}
	Add(item);
}

void BarFactoryPrivate::add(const InstrumentList& instruments, BarType barType, long barSize, BarInput barInput, ClockType type)
{
	foreach (Instrument current in instruments)
	{
		Add(current, barType, barSize, barInput, type);
	}
}

void BarFactoryPrivate::add(QString symbols, BarType barType, long barSize, BarInput barInput, ClockType type)
{
	for (int i = 0; i < symbols.Length; i++)
	{
		string symbol = symbols[i];
		Add(m_framework.instrumentManager().Get(symbol), barType, barSize, barInput, type);
	}
}

void BarFactoryPrivate::method_3(const QDateTime& dateTime, const QVariant& object)
{
	SortedList<long, List<BarFactoryItem>> sortedList;
	if (sortedList_0.TryGetValue(dateTime, out sortedList))
	{
		sortedList_0.Remove(dateTime);
		foreach (List<BarFactoryItem> current in sortedList.Values)
		{
			foreach (BarFactoryItem current2 in current)
			{
				current2.OnReminder(dateTime);
			}
		}
	}
}


// Pubic API 

BarFactory::BarFactory(const Framework& framework)
	: d_ptr(new BarFactoryPrivate(framework))
{
}

BarFactory::~BarFactory()
{
}

BarFactory::BarFactory (const BarFactory &other)
	: d_ptr(other.d_ptr)
{
}

BarFactory& BarFactory::operator=(const BarFactory &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BarFactory::operator==(const BarFactory &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Framework framework() const
{
	return d_ptr->
	setFramework()
}

void BarFactory::add(const BarFactoryItem& item)
{
	d_ptr->add(item);
}

void BarFactory::add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, ClockType type)
{
	d_ptr->add(instrument, barType, barSize, barInput, type);
}

void BarFactory::add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
{
	d_ptr->add(instrument, barType, barSize, barInput, type, session1, session2);
}

void BarFactory::add(const QString& symbol, BarType barType, long barSize, BarInput barInput, ClockType type)
{
	d_ptr->add(symbol, barType, barSize, barInput, type);
}

void BarFactory::add(const InstrumentList& instruments, BarType barType, long barSize, BarInput barInput, ClockType type)
{
	d_ptr->add(instruments, barType, barSize, barInput, type);
}

void BarFactory::add(QString symbols, BarType barType, long barSize, BarInput barInput, ClockType type)
{
	d_ptr->add(symbols, barType, barSize, barInput, type);
}

void BarFactory::add(const Instrument& instrument, BarType barType, long barSize, TimeSpan session1, TimeSpan session2)
{
	d_ptr->add(instrument, barType, barSize, session1, session2);
}

void BarFactory::add(const QString& symbol, BarType barType, long barSize, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
{
	d_ptr->add(symbol, barType, barSize, barInput, type, session1, session2);
}

void BarFactory::add(const QString& symbol, BarType barType, long barSize, TimeSpan session1, TimeSpan session2)
{
	d_ptr->add(symbol, barType, barSize, session1, session2);
}

void BarFactory::add(const Instrument& instrument, TimeSpan session1, TimeSpan session2)
{
	d_ptr->add(instrument, session1, session2);
}

void BarFactory::add(const QString& symbol, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
{
	d_ptr->add(symbol, barInput, type, session1, session2);
}

void BarFactory::add(const QString& symbol, TimeSpan session1, TimeSpan session2)
{
	d_ptr->add(symbol, session1, session2);
}

QDebug operator<<(QDebug dbg, const BarFactory& barfactory)
{
	return dbg << barfactory.toString();
}

