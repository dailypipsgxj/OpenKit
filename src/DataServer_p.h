#ifndef __QUANTKIT_DATASERVER_PRIVATE_H__
#define __QUANTKIT_DATASERVER_PRIVATE_H__

#include <QuantKit/DataServer.h>

#include <QSharedData>

#include "Framework_p.h"
#include "Instrument_p.h"
#include "DataObject_p.h"
#include "DataSeries_p.h"

namespace QuantKit {

class DataServerPrivate : public QSharedData
{
public:
	Framework framework;
	bool m_tapeMode;

public:
	explicit DataServerPrivate(const Framework& framework);
	virtual ~DataServerPrivate();

public:
	bool tapeMode() const { return m_tapeMode; }
	void setTapeMode(bool value) { m_tapeMode = value; }
	virtual DataSeries addDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize) Q_DECL_OVERRIDE { return null; }
	virtual DataSeries addDataSeries(const QString& name) Q_DECL_OVERRIDE { return null; }
	virtual void close() Q_DECL_OVERRIDE;
	virtual void deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize) Q_DECL_OVERRIDE;
	virtual void deleteDataSeries(const QString& name) Q_DECL_OVERRIDE;
	virtual void flush() Q_DECL_OVERRIDE;
	virtual DataSeries getDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize) Q_DECL_OVERRIDE { return null; }
	virtual DataSeries getDataSeries(const QString& name) Q_DECL_OVERRIDE { return null; }
	virtual QList<DataSeries> getDataSeriesList(const Instrument& instrument, const QString& pattern) Q_DECL_OVERRIDE { return null; }
	virtual void open() Q_DECL_OVERRIDE;
	virtual void save(const Instrument& instrument, const DataObject& obj, SaveMode option) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_DATASERVER_PRIVATE_H__
