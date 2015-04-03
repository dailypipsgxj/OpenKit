#include <QuantKit/InstrumentServer.h>

#include <QuantKit/Framework.h>
#include <QuantKit/InstrumentList.h>
#include <QuantKit/Instrument.h>
#include "InstrumentServer_p.h"

using namespace QuantKit;

InstrumentServerPrivate::InstrumentServerPrivate(const Framework& framework)
	: m_framework(framework)
	, m_instruments(new InstrumentList())
{
}

InstrumentServerPrivate::~InstrumentServerPrivate ()
{
}

InstrumentList getInstruments() const
{
	return null;
}
void InstrumentServerPrivate::close()
{
}

void InstrumentServerPrivate::delete(const Instrument& instrument)
{
}

void InstrumentServerPrivate::flush()
{
}

void InstrumentServerPrivate::open()
{
}

void InstrumentServerPrivate::save(const Instrument& instrument)
{
}


// Pubic API 

InstrumentServer::InstrumentServer(const Framework& framework)
	: d_ptr(new InstrumentServerPrivate(framework))
{
}

InstrumentServer::~InstrumentServer()
{
}

InstrumentServer::InstrumentServer (InstrumentServerPrivate &dd)
	: d_ptr(&dd)
{
}

InstrumentServer::InstrumentServer (const InstrumentServer &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentServer& InstrumentServer::operator=(const InstrumentServer &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentServer::operator==(const InstrumentServer &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

InstrumentList instruments() const
{
	return d_ptr->
	setInstruments()
}

void InstrumentServer::close()
{
	d_ptr->close();
}

void InstrumentServer::delete(const Instrument& instrument)
{
	d_ptr->delete(instrument);
}

void InstrumentServer::flush()
{
	d_ptr->flush();
}

InstrumentList InstrumentServer::load()
{
	return d_ptr->load();
}

void InstrumentServer::open()
{
	d_ptr->open();
}

void InstrumentServer::save(const Instrument& instrument)
{
	d_ptr->save(instrument);
}

QDebug operator<<(QDebug dbg, const InstrumentServer& instrumentserver)
{
	return dbg << instrumentserver.toString();
}

