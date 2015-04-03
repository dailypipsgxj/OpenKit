#include <QuantKit/InstrumentManager.h>

#include <QuantKit/InstrumentList.h>
#include "InstrumentServer_p.h"
#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>

namespace QuantKit {

class InstrumentManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	InstrumentServer m_server;
	InstrumentList m_item;
	InstrumentList instrumentList_1;
	int int_0;

public:
	InstrumentManagerPrivate(const Framework& framework, const InstrumentServer& server);
	virtual ~InstrumentManagerPrivate();

public:
	InstrumentList instruments() const { return m_item; }
	InstrumentServer server() const { return m_server; }
	Instrument item(const QString& symbol) const { return m_item.Get(symbol); }
	void add(const Instrument& instrument, bool save);
	void clear();
	bool contains(const QString& symbol)
	{
		return m_item.Contains(symbol);
	}

	void delete(const Instrument& instrument);
	void delete(const QString& symbol);
	void dump();
	Instrument get(const QString& symbol) { return m_item.Get(symbol); }
	Instrument getById(int id);
	void load();
	void save(const Instrument& instrument);
	virtual InstrumentManagerPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentManagerPrivate::InstrumentManagerPrivate(const Framework& framework, const InstrumentServer& server)
	: m_framework(framework)
	, m_server(server)
	, m_item(new InstrumentList())
	, instrumentList_1(new InstrumentList())
{
}

InstrumentManagerPrivate::~InstrumentManagerPrivate ()
{
}

void InstrumentManagerPrivate::add(const Instrument& instrument, bool save)
{
	if (Contains(instrument.symbol()))
	{
		throw new ApplicationException("Instrument with the same symbol is already present in the framework : " + instrument.symbol());
	}
	Instrument instrument2 = instrumentList_1.Get(instrument.symbol());
	if (instrument2 != null)
	{
		Console.WriteLine(string.Concat(new object[]
		{
			"InstrumentManager::Add Using deleted instrument id = ",
			instrument2.id(),
			" for symbol ",
			instrument.symbol()
		}));
		instrument.setId() = instrument2.id();
		instrumentList_1.Remove(instrument2);
	}
	else
	{
		instrument.setId() = int_0;
		int_0++;
	}
	m_item.Add(instrument);
	if (instrument.framework() == null)
	{
		instrument.method_0(m_framework);
	}
	if (save)
	{
		instrument.setBool_1() = true;
		Save(instrument);
	}
	m_framework.eventServer().OnInstrumentAdded(instrument);
}

void InstrumentManagerPrivate::clear()
{
	foreach (Instrument current in m_item)
	{
		current.setBid() = null;
		current.setAsk() = null;
		current.setTrade() = null;
		current.setBar() = null;
	}
	InstrumentList instrumentList = new InstrumentList();
	foreach (Instrument current2 in m_item)
	{
		if (!current2.bool_1())
		{
			instrumentList.Add(current2);
		}
	}
	foreach (Instrument current3 in instrumentList)
	{
		Delete(current3);
	}
}

void InstrumentManagerPrivate::delete(const Instrument& instrument)
{
	m_item.Remove(instrument);
	instrument.setBool_0() = true;
	instrumentList_1.Add(instrument);
	Save(instrument);
	m_framework.eventServer().OnInstrumentDeleted(instrument);
}

void InstrumentManagerPrivate::delete(const QString& symbol)
{
	Instrument instrument = Get(symbol);
	if (instrument != null)
	{
		Delete(instrument);
	}
}

void InstrumentManagerPrivate::dump()
{
	Console.WriteLine("Instrument manager contains " + m_item.count() + " intruments:");
	foreach (Instrument current in m_item)
	{
		Console.WriteLine(current);
	}
}

Instrument InstrumentManagerPrivate::getById(int id)
{
	Instrument instrument = m_item.GetById(id);
	if (instrument == null)
	{
		instrument = new Instrument(id, InstrumentType.Synthetic, Guid.NewGuid().ToString(), "", 148);
		m_item.Add(instrument);
	}
	return instrument;
}

void InstrumentManagerPrivate::load()
{
	m_server.Open();
	int_0 = -1;
	InstrumentList instrumentList = m_server.Load();
	foreach (Instrument current in instrumentList)
	{
		current.method_0(m_framework);
		current.setBool_1() = true;
		if (current.bool_0())
		{
			instrumentList_1.Add(current);
		}
		else
		{
			m_item.Add(current);
		}
		int id = current.id();
		if (id > int_0)
		{
			int_0 = id;
		}
	}
	int_0++;
}

void InstrumentManagerPrivate::save(const Instrument& instrument)
{
	if (m_server != null && instrument.bool_1())
	{
		m_server.Save(instrument);
	}
}


// Pubic API 

InstrumentManager::InstrumentManager(const Framework& framework, const InstrumentServer& server)
	: d_ptr(new InstrumentManagerPrivate(framework, server))
{
}

InstrumentManager::~InstrumentManager()
{
}

InstrumentManager::InstrumentManager (const InstrumentManager &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentManager& InstrumentManager::operator=(const InstrumentManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentManager::operator==(const InstrumentManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

InstrumentList InstrumentManager::instruments() const
{
	return d_ptr->instruments();
}

InstrumentServer InstrumentManager::server() const
{
	return d_ptr->server();
}

Instrument InstrumentManager::item(const QString& symbol) const
{
	return d_ptr->item(symbol);
}

void InstrumentManager::add(const Instrument& instrument, bool save)
{
	d_ptr->add(instrument, save);
}

void InstrumentManager::clear()
{
	d_ptr->clear();
}

bool InstrumentManager::contains(const QString& symbol)
{
	return d_ptr->contains(symbol);
}

void InstrumentManager::delete(const Instrument& instrument)
{
	d_ptr->delete(instrument);
}

void InstrumentManager::delete(const QString& symbol)
{
	d_ptr->delete(symbol);
}

void InstrumentManager::dump()
{
	d_ptr->dump();
}

Instrument InstrumentManager::get(const QString& symbol)
{
	return d_ptr->get(symbol);
}

Instrument InstrumentManager::getById(int id)
{
	return d_ptr->getById(id);
}

void InstrumentManager::load()
{
	d_ptr->load();
}

void InstrumentManager::save(const Instrument& instrument)
{
	d_ptr->save(instrument);
}

QDebug operator<<(QDebug dbg, const InstrumentManager& instrumentmanager)
{
	return dbg << instrumentmanager.toString();
}

