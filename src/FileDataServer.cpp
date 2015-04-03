#include <QuantKit/FileDataServer.h>

#include <QuantKit/Framework.h>
#include "DataSeries_p.h"
#include <QuantKit/Instrument.h>
#include <QuantKit/Event/Bar.h>
#include "DataObject_p.h"
#include "DataFile_p.h"
#include <QuantKit/IdArray.h>
#include "DataServer_p.h"

namespace QuantKit {

class FileDataServerPrivate : public DataServerPrivate
{
public:
	DataFile dataFile_0;
	QString string_0;
	IdArray m_idArray;
	bool bool_0;
	IdArray<IdArray<DataSeries>> idArray_1;
	IdArray<IdArray<Dictionary<long,DataSeries>>> idArray_2;

public:
	FileDataServerPrivate(const Framework& framework, const QString& fileName, const QString& host, int port);
	virtual ~FileDataServerPrivate();

public:
	virtual DataSeries addDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize) Q_DECL_OVERRIDE;
	virtual DataSeries addDataSeries(const QString& name) Q_DECL_OVERRIDE;
	virtual void close() Q_DECL_OVERRIDE;
	virtual void deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize) Q_DECL_OVERRIDE;
	virtual void deleteDataSeries(const QString& name) Q_DECL_OVERRIDE;
	virtual void flush() Q_DECL_OVERRIDE { dataFile_0.Flush(); }
	virtual DataSeries getDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize) Q_DECL_OVERRIDE;
	virtual DataSeries getDataSeries(const QString& name) Q_DECL_OVERRIDE
	{
		return (DataSeries)dataFile_0.Get(name);
	}

	virtual QList<DataSeries> getDataSeriesList(const Instrument& instrument, const QString& pattern) Q_DECL_OVERRIDE;
	virtual void open() Q_DECL_OVERRIDE;
	virtual void save(const Instrument& instrument, const DataObject& obj, SaveMode option) Q_DECL_OVERRIDE;
	virtual FileDataServerPrivate* clone() Q_DECL_OVERRIDE { return new FileDataServerPrivate(*this); }
//private:
	DataSeries method_0(const Instrument& instrument, BarType barType, long long, bool bool_1);
	void method_1(const Instrument& instrument, const Bar& bar, SaveMode saveMode);
};

} // namepsace QuantKit


using namespace QuantKit;

FileDataServerPrivate::FileDataServerPrivate(const Framework& framework, const QString& fileName, QString host, int port)
	: DataServerPrivate (framework)
	, dataFile_0(new DataFile(fileName, framework.streamerManager()))
	, dataFile_0(new NetDataFile_(fileName, host, port, framework.streamerManager()))
	, string_0(host)
	, idArray_1(new IdArray<IdArray<DataSeries>>(1000))
	, idArray_2(new IdArray<IdArray<Dictionary<long, DataSeries>>>(1000))
{
		if (host == null)
		{
			return;
		}
}

FileDataServerPrivate::~FileDataServerPrivate ()
{
}

DataSeries FileDataServerPrivate::addDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	if (type == 6)
	{
		return method_0(instrument, barType, barSize, true);
	}
	DataSeries dataSeries = m_idArray[(int)type][instrument.id()];
	if (dataSeries == null)
	{
		string name = DataSeriesNameHelper.GetName(instrument, type);
		dataSeries = (DataSeries)dataFile_0.Get(name);
		if (dataSeries == null)
		{
			if (string_0 == null)
			{
				dataSeries = new DataSeries(name);
			}
			else
			{
				dataSeries = new NetDataSeries(name);
			}
			dataFile_0.Write(name, dataSeries);
		}
		m_idArray[(int)type][instrument.id()] = dataSeries;
	}
	return dataSeries;
}

DataSeries FileDataServerPrivate::addDataSeries(const QString& name)
{
	DataSeries dataSeries = (DataSeries)dataFile_0.Get(name);
	if (dataSeries == null)
	{
		if (string_0 == null)
		{
			dataSeries = new DataSeries(name);
		}
		else
		{
			dataSeries = new NetDataSeries(name);
		}
		dataFile_0.Write(name, dataSeries);
	}
	return dataSeries;
}

void FileDataServerPrivate::close()
{
	if (bool_0)
	{
		dataFile_0.Close();
		bool_0 = false;
	}
}

void FileDataServerPrivate::deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	DataSeries dataSeries;
	if (type == 6)
	{
		dataSeries = method_0(instrument, barType, barSize, false);
		if (barType == BarType.Time && barSize <= 86400L)
		{
			DataSeries dataSeries2 = idArray_1[instrument.id()][(int)barSize] = null;
		}
		else
		{
			if (idArray_2[(int)type] == null)
			{
				idArray_2[(int)type] = new IdArray<Dictionary<long, DataSeries>>(1000);
			}
			if (idArray_2[(int)type][instrument.id()] == null)
			{
				idArray_2[(int)type][instrument.id()] = new Dictionary<long, DataSeries>();
			}
			idArray_2[(int)type][instrument.id()].Remove(barSize);
		}
		dataFile_0.Delete(DataSeriesNameHelper.GetName(instrument, barType, barSize));
		return;
	}
	dataSeries = m_idArray[(int)type][instrument.id()];
	if (dataSeries != null)
	{
		m_idArray[(int)type].Remove(instrument.id());
	}
	dataFile_0.Delete(DataSeriesNameHelper.GetName(instrument, type));
}

void FileDataServerPrivate::deleteDataSeries(const QString& name)
{
	DataSeries dataSeries = (DataSeries)dataFile_0.Get(name);
	if (dataSeries != null)
	{
		for (int i = 0; i < m_idArray.Length; i++)
		{
			for (int j = 0; j < m_idArray[i].Size; j++)
			{
				if (m_idArray[i][j] == dataSeries)
				{
					m_idArray[i].Remove(j);
				}
			}
		}
		dataFile_0.Delete(name);
	}
}

DataSeries FileDataServerPrivate::getDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	if (type == 6)
	{
		return method_0(instrument, barType, barSize, false);
	}
	DataSeries dataSeries = m_idArray[(int)type][instrument.id()];
	if (dataSeries == null)
	{
		string name = DataSeriesNameHelper.GetName(instrument, type);
		dataSeries = (dataFile_0.Get(name) as DataSeries);
		m_idArray[(int)type][instrument.id()] = dataSeries;
	}
	return dataSeries;
}

QList<DataSeries> FileDataServerPrivate::getDataSeriesList(Instrument instrument, QString pattern)
{
	List<DataSeries> list = new List<DataSeries>();
	foreach (ObjectKey current in dataFile_0.keys().Values)
	{
		if (current.typeId() == 101 && (instrument == null || !(DataSeriesNameHelper.GetSymbol(current.string_1()) != instrument.symbol())) && (pattern == null || current.string_1().Contains(pattern)))
		{
			list.Add((DataSeries)dataFile_0.Get(current.string_1()));
		}
	}
	return list;
}

void FileDataServerPrivate::open()
{
	if (!bool_0)
	{
		dataFile_0.Open(FileMode.OpenOrCreate);
		m_idArray = new IdArray<DataSeries>[128];
		for (int i = 0; i < m_idArray.Length; i++)
		{
			m_idArray[i] = new IdArray<DataSeries>(1000);
		}
		bool_0 = true;
	}
}

void FileDataServerPrivate::save(const Instrument& instrument, const DataObject& obj, SaveMode option)
{
	byte b;
	if (m_tapeMode)
	{
		b = 1;
	}
	else
	{
		b = obj.typeId();
	}
	if (b == 6)
	{
		method_1(instrument, (Bar)obj, option);
		return;
	}
	DataSeries dataSeries = m_idArray[(int)b][instrument.id()];
	if (dataSeries == null)
	{
		string name = DataSeriesNameHelper.GetName(instrument, b);
		dataSeries = (DataSeries)dataFile_0.Get(name);
		if (dataSeries == null)
		{
			if (string_0 == null)
			{
				dataSeries = new DataSeries(name);
			}
			else
			{
				dataSeries = new NetDataSeries(name);
			}
			dataFile_0.Write(name, dataSeries);
			dataFile_0.Flush();
		}
		m_idArray[(int)b][instrument.id()] = dataSeries;
	}
	switch (option)
	{
		case SaveMode.Add:
			dataSeries.Add(obj);
			return;
		case SaveMode.Append:
			if (obj.entryDate() > dataSeries.dateTime2())
			{
				dataSeries.Add(obj);
			}
			return;
		default:
			return;
	}
}

DataSeries FileDataServerPrivate::method_0(const Instrument& instrument, BarType barType, long long, bool bool_1)
{
	DataSeries dataSeries;
	if (barType == BarType.Time && @long <= 86400L)
	{
		if (idArray_1[instrument.id()] == null)
		{
			idArray_1[instrument.id()] = new IdArray<DataSeries>(1000);
		}
		dataSeries = idArray_1[instrument.id()][(int)@long];
	}
	else
	{
		if (idArray_2[(int)barType] == null)
		{
			idArray_2[(int)barType] = new IdArray<Dictionary<long, DataSeries>>(1000);
		}
		if (idArray_2[(int)barType][instrument.id()] == null)
		{
			idArray_2[(int)barType][instrument.id()] = new Dictionary<long, DataSeries>();
		}
		idArray_2[(int)barType][instrument.id()].TryGetValue(@long, out dataSeries);
	}
	if (dataSeries == null)
	{
		string name = DataSeriesNameHelper.GetName(instrument, barType, @long);
		dataSeries = (DataSeries)dataFile_0.Get(name);
		if (dataSeries == null & bool_1)
		{
			if (string_0 == null)
			{
				dataSeries = new DataSeries(name);
			}
			else
			{
				dataSeries = new NetDataSeries(name);
			}
			dataFile_0.Write(name, dataSeries);
			dataFile_0.Flush();
		}
		if (dataSeries != null)
		{
			if (barType == BarType.Time && @long <= 86400L)
			{
				idArray_1[instrument.id()][(int)@long] = dataSeries;
			}
			else
			{
				idArray_2[(int)barType][instrument.id()][@long] = dataSeries;
			}
		}
	}
	return dataSeries;
}

void FileDataServerPrivate::method_1(const Instrument& instrument, const Bar& bar, SaveMode saveMode)
{
	DataSeries dataSeries = method_0(instrument, bar.type(), bar.size(), true);
	switch (saveMode)
	{
		case SaveMode.Add:
			dataSeries.Add(bar);
			return;
		case SaveMode.Append:
			if (bar.entryDate() > dataSeries.dateTime2())
			{
				dataSeries.Add(bar);
			}
			return;
		default:
			return;
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(FileDataServer)

FileDataServer::FileDataServer(const Framework& framework, const QString& fileName, QString host, int port)
	: DataServer(*new FileDataServerPrivate(framework, fileName, host, port))
{
}

FileDataServer::~FileDataServer()
{
}


