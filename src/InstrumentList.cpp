#include <QuantKit/InstrumentList.h>

#include <QuantKit/Instrument.h>
#include <QuantKit/IdArray.h>

namespace QuantKit {

class InstrumentListPrivate : public QSharedData
{
public:
	Dictionary<QString,Instrument> m_dictionary;
	IdArray<Instrument> m_idArray;
	QList<Instrument> m_count;

public:
	InstrumentListPrivate();
	virtual ~InstrumentListPrivate();

public:
	int count() const { return m_count.Count; }
	Instrument item(const QString& symbol) const { return Get(symbol); }
	void add(const Instrument& instrument);
	void clear();
	bool contains(const QString& symbol)
	{
		return m_dictionary.ContainsKey(symbol);
	}

	bool contains(const Instrument& instrument)
	{
		return m_dictionary.ContainsKey(instrument.symbol());
	}

	bool contains(int id) { return m_idArray[id] != null; }
	Instrument get(const QString& symbol);
	Instrument getById(int id) { return m_idArray[id]; }
	Instrument getByIndex(int index) { return m_count[index]; }
	void remove(const Instrument& instrument);
	virtual QString toString() const Q_DECL_OVERRIDE { return "InstrumentList"; }
	virtual InstrumentListPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentListPrivate(*this); }
//private:
	IEnumerator system.Collections.IEnumerable.GetEnumerator()
	{
		return m_count.GetEnumerator();
	}

};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentListPrivate::InstrumentListPrivate()
	: m_dictionary(new Dictionary<string, Instrument>())
	, m_idArray(new IdArray<Instrument>(10000))
	, m_count(new QList<Instrument>())
{
}

InstrumentListPrivate::~InstrumentListPrivate ()
{
}

void InstrumentListPrivate::add(const Instrument& instrument)
{
	if (m_idArray[instrument.id()] == null)
	{
		m_count.Add(instrument);
		m_dictionary[instrument.symbol()] = instrument;
		m_idArray[instrument.id()] = instrument;
		return;
	}
	Console.WriteLine(string.Concat(new object[]
	{
		"InstrumentList::Add Instrument ",
		instrument.symbol(),
		" with Id = ",
		instrument.id(),
		" is already in the list"
	}));
}

void InstrumentListPrivate::clear()
{
	m_dictionary.Clear();
	m_idArray.Clear();
	m_count.Clear();
}

Instrument InstrumentListPrivate::get(const QString& symbol)
{
	Instrument result;
	m_dictionary.TryGetValue(symbol, out result);
	return result;
}

void InstrumentListPrivate::remove(const Instrument& instrument)
{
	m_count.Remove(instrument);
	m_dictionary.Remove(instrument.symbol());
	m_idArray.Remove(instrument.id());
}


// Pubic API 

InstrumentList::InstrumentList()
	: d_ptr(new InstrumentListPrivate)
{
}

InstrumentList::~InstrumentList()
{
}

InstrumentList::InstrumentList (const InstrumentList &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentList& InstrumentList::operator=(const InstrumentList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentList::operator==(const InstrumentList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int InstrumentList::count() const
{
	return d_ptr->count();
}

Instrument InstrumentList::item(const QString& symbol) const
{
	return d_ptr->item(symbol);
}

void InstrumentList::add(const Instrument& instrument)
{
	d_ptr->add(instrument);
}

void InstrumentList::clear()
{
	d_ptr->clear();
}

bool InstrumentList::contains(const QString& symbol)
{
	return d_ptr->contains(symbol);
}

bool InstrumentList::contains(const Instrument& instrument)
{
	return d_ptr->contains(instrument);
}

bool InstrumentList::contains(int id)
{
	return d_ptr->contains(id);
}

Instrument InstrumentList::get(const QString& symbol)
{
	return d_ptr->get(symbol);
}

Instrument InstrumentList::getById(int id)
{
	return d_ptr->getById(id);
}

Instrument InstrumentList::getByIndex(int index)
{
	return d_ptr->getByIndex(index);
}

void InstrumentList::remove(const Instrument& instrument)
{
	d_ptr->remove(instrument);
}

QString InstrumentList::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const InstrumentList& instrumentlist)
{
	return dbg << instrumentlist.toString();
}

