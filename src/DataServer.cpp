#include <QuantKit/DataServer.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>
#include "DataObject_p.h"
#include "DataSeries_p.h"
#include "DataServer_p.h"

using namespace QuantKit;

DataServerPrivate::DataServerPrivate(const Framework& framework)
	: framework(framework)
	, m_tapeMode(false)
{
}

DataServerPrivate::~DataServerPrivate ()
{
}

void DataServerPrivate::close()
{
}

void DataServerPrivate::deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
}

void DataServerPrivate::deleteDataSeries(const QString& name)
{
}

void DataServerPrivate::flush()
{
}

void DataServerPrivate::open()
{
}

void DataServerPrivate::save(const Instrument& instrument, const DataObject& obj, SaveMode option)
{
}


// Pubic API 

DataServer::DataServer(const Framework& framework)
	: d_ptr(new DataServerPrivate(framework))
{
}

DataServer::~DataServer()
{
}

DataServer::DataServer (DataServerPrivate &dd)
	: d_ptr(&dd)
{
}

DataServer::DataServer (const DataServer &other)
	: d_ptr(other.d_ptr)
{
}

DataServer& DataServer::operator=(const DataServer &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataServer::operator==(const DataServer &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

bool DataServer::tapeMode() const
{
	return d_ptr->tapeMode();
}

void DataServer::setTapeMode(bool value)
{
	d_ptr->setTapeMode(value);
}

DataSeries DataServer::addDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	return d_ptr->addDataSeries(instrument, type, barType, barSize);
}

DataSeries DataServer::addDataSeries(const QString& name)
{
	return d_ptr->addDataSeries(name);
}

void DataServer::close()
{
	d_ptr->close();
}

void DataServer::deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	d_ptr->deleteDataSeries(instrument, type, barType, barSize);
}

void DataServer::deleteDataSeries(const QString& name)
{
	d_ptr->deleteDataSeries(name);
}

void DataServer::flush()
{
	d_ptr->flush();
}

DataSeries DataServer::getDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	return d_ptr->getDataSeries(instrument, type, barType, barSize);
}

DataSeries DataServer::getDataSeries(const QString& name)
{
	return d_ptr->getDataSeries(name);
}

QList<DataSeries> DataServer::getDataSeriesList(Instrument instrument, QString pattern)
{
	return d_ptr->getDataSeriesList(instrument, pattern);
}

void DataServer::open()
{
	d_ptr->open();
}

void DataServer::save(const Instrument& instrument, const DataObject& obj, SaveMode option)
{
	d_ptr->save(instrument, obj, option);
}

QDebug operator<<(QDebug dbg, const DataServer& dataserver)
{
	return dbg << dataserver.toString();
}

