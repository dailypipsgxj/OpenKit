#ifndef __QUANTKIT_INSTRUMENTSERVER_PRIVATE_H__
#define __QUANTKIT_INSTRUMENTSERVER_PRIVATE_H__

#include <QuantKit/InstrumentServer.h>

#include <QSharedData>

#include "Framework_p.h"
#include "InstrumentList_p.h"
#include "Instrument_p.h"

namespace QuantKit {

class InstrumentServerPrivate : public QSharedData
{
public:
	Framework m_framework;
	InstrumentList m_instruments;

public:
	explicit InstrumentServerPrivate(const Framework& framework);
	virtual ~InstrumentServerPrivate();

public:
	InstrumentList getInstruments() const;
	virtual void close() Q_DECL_OVERRIDE;
	virtual void delete(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void flush() Q_DECL_OVERRIDE;
	virtual InstrumentList load() Q_DECL_OVERRIDE { return m_instruments; }
	virtual void open() Q_DECL_OVERRIDE;
	virtual void save(const Instrument& instrument) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_INSTRUMENTSERVER_PRIVATE_H__
