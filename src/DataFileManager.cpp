#include <QuantKit/DataFileManager.h>

#include "DataFile_p.h"
#include "DataSeries_p.h"
#include <QuantKit/StreamerManager.h>

namespace QuantKit {

class DataFileManagerPrivate : public QSharedData
{
public:
	QString string_0;
	Dictionary<QString,DataFile> m_dictionary;
	StreamerManager streamerManager_0;

public:
	explicit DataFileManagerPrivate(const QString& path);
	virtual ~DataFileManagerPrivate();

public:
	void close(const QString& name);
	void close();
	void delete(const QString& fileName, const QString& objectName);
	DataFile getFile(const QString& name, FileMode mode);
	DataSeries getSeries(const QString& fileName, const QString& seriesName);
	virtual DataFileManagerPrivate* clone() Q_DECL_OVERRIDE { return new DataFileManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataFileManagerPrivate::DataFileManagerPrivate(const QString& path)
	: string_0(path)
	, m_dictionary(new Dictionary<string, DataFile>())
	, streamerManager_0(new StreamerManager())
{
		streamerManager_0.Add(new DataObjectStreamer());
		streamerManager_0.Add(new BidStreamer());
		streamerManager_0.Add(new AskStreamer());
		streamerManager_0.Add(new QuoteStreamer());
		streamerManager_0.Add(new TradeStreamer());
		streamerManager_0.Add(new BarStreamer());
		streamerManager_0.Add(new Level2SnapshotStreamer());
		streamerManager_0.Add(new Level2UpdateStreamer());
		streamerManager_0.Add(new NewsStreamer());
		streamerManager_0.Add(new FundamentalStreamer());
		streamerManager_0.Add(new DataSeriesStreamer());
		streamerManager_0.Add(new ObjectTableStreamer());
		streamerManager_0.Add(new InstrumentStreamer());
		streamerManager_0.Add(new AltIdStreamer());
		streamerManager_0.Add(new LegStreamer());
		streamerManager_0.Add(new ExecutionCommandStreamer());
		streamerManager_0.Add(new ExecutionReportStreamer());
		streamerManager_0.Add(new PositionStreamer());
		streamerManager_0.Add(new PortfolioStreamer());
		streamerManager_0.Add(new DoubleStreamer());
		streamerManager_0.Add(new Int16Streamer());
		streamerManager_0.Add(new Int32Streamer());
		streamerManager_0.Add(new Int64Streamer());
		streamerManager_0.Add(new StringStreamer());
		streamerManager_0.Add(new TimeSeriesItemStreamer());
}

DataFileManagerPrivate::~DataFileManagerPrivate ()
{
}

void DataFileManagerPrivate::close(const QString& name)
{
	DataFile dataFile;
	m_dictionary.TryGetValue(name, out dataFile);
	if (dataFile != null)
	{
		dataFile.Close();
		m_dictionary.Remove(name);
	}
}

void DataFileManagerPrivate::close()
{
	foreach (DataFile current in m_dictionary.Values)
	{
		current.Close();
	}
}

void DataFileManagerPrivate::delete(const QString& fileName, const QString& objectName)
{
	DataFile file = GetFile(fileName, FileMode.OpenOrCreate);
	file.Delete(objectName);
}

DataFile DataFileManagerPrivate::getFile(const QString& name, FileMode mode)
{
	bool flag = false;
	DataFile result;
	try
	{
		Monitor.Enter(this, ref flag);
		DataFile dataFile;
		m_dictionary.TryGetValue(name, out dataFile);
		if (dataFile == null)
		{
			Console.WriteLine(DateTime.Now + " Opening file : " + name);
			dataFile = new DataFile(string_0 + "\\" + name, streamerManager_0);
			dataFile.Open(mode);
			m_dictionary.Add(name, dataFile);
		}
		result = dataFile;
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
	return result;
}

DataSeries DataFileManagerPrivate::getSeries(const QString& fileName, const QString& seriesName)
{
	DataFile file = GetFile(fileName, FileMode.OpenOrCreate);
	DataSeries dataSeries = (DataSeries)file.Get(seriesName);
	if (dataSeries == null)
	{
		dataSeries = new DataSeries(seriesName);
		file.Write(seriesName, dataSeries);
	}
	return dataSeries;
}


// Pubic API 

DataFileManager::DataFileManager(const QString& path)
	: d_ptr(new DataFileManagerPrivate(path))
{
}

DataFileManager::~DataFileManager()
{
}

DataFileManager::DataFileManager (const DataFileManager &other)
	: d_ptr(other.d_ptr)
{
}

DataFileManager& DataFileManager::operator=(const DataFileManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataFileManager::operator==(const DataFileManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void DataFileManager::close(const QString& name)
{
	d_ptr->close(name);
}

void DataFileManager::close()
{
	d_ptr->close();
}

void DataFileManager::delete(const QString& fileName, const QString& objectName)
{
	d_ptr->delete(fileName, objectName);
}

DataFile DataFileManager::getFile(const QString& name, FileMode mode)
{
	return d_ptr->getFile(name, mode);
}

DataSeries DataFileManager::getSeries(const QString& fileName, const QString& seriesName)
{
	return d_ptr->getSeries(fileName, seriesName);
}

QDebug operator<<(QDebug dbg, const DataFileManager& datafilemanager)
{
	return dbg << datafilemanager.toString();
}

