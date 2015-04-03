#include <QuantKit/FileInstrumentServer.h>

#include <QuantKit/Framework.h>
#include <QuantKit/InstrumentList.h>
#include <QuantKit/Instrument.h>
#include "DataFile_p.h"
#include "InstrumentServer_p.h"

namespace QuantKit {

class FileInstrumentServerPrivate : public InstrumentServerPrivate
{
public:
	DataFile dataFile_0;
	bool bool_0;

public:
	FileInstrumentServerPrivate(const Framework& framework, const QString& fileName, const QString& host, int port);
	virtual ~FileInstrumentServerPrivate();

public:
	virtual void close() Q_DECL_OVERRIDE;
	virtual void delete(const Instrument& instrument) Q_DECL_OVERRIDE
	{
		dataFile_0.Delete(instrument.symbol());
	}

	virtual void flush() Q_DECL_OVERRIDE { dataFile_0.Flush(); }
	virtual InstrumentList load() Q_DECL_OVERRIDE;
	virtual void open() Q_DECL_OVERRIDE;
	virtual void save(const Instrument& instrument) Q_DECL_OVERRIDE
	{
		dataFile_0.Write(instrument.symbol(), instrument);
	}

	virtual FileInstrumentServerPrivate* clone() Q_DECL_OVERRIDE { return new FileInstrumentServerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FileInstrumentServerPrivate::FileInstrumentServerPrivate(const Framework& framework, const QString& fileName, QString host, int port)
	: InstrumentServerPrivate (framework)
	, dataFile_0(new DataFile(fileName, framework.streamerManager()))
	, dataFile_0(new NetDataFile_(fileName, host, port, framework.streamerManager()))
{
		if (host == null)
		{
			return;
		}
}

FileInstrumentServerPrivate::~FileInstrumentServerPrivate ()
{
}

void FileInstrumentServerPrivate::close()
{
	if (bool_0)
	{
		dataFile_0.Close();
		bool_0 = false;
	}
}

InstrumentList FileInstrumentServerPrivate::load()
{
	m_instruments.Clear();
	foreach (ObjectKey current in dataFile_0.keys().Values)
	{
		if (current.typeId() == 106)
		{
			Instrument instrument = (Instrument)dataFile_0.Get(current.string_1());
			m_instruments.Add(instrument);
		}
	}
	return m_instruments;
}

void FileInstrumentServerPrivate::open()
{
	if (!bool_0)
	{
		dataFile_0.Open(FileMode.OpenOrCreate);
		bool_0 = true;
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(FileInstrumentServer)

FileInstrumentServer::FileInstrumentServer(const Framework& framework, const QString& fileName, QString host, int port)
	: InstrumentServer(*new FileInstrumentServerPrivate(framework, fileName, host, port))
{
}

FileInstrumentServer::~FileInstrumentServer()
{
}


