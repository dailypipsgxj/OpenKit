#include <QuantKit/DataManager.h>

#include "DataServer_p.h"
#include <QuantKit/Framework.h>
#include "DataSeries_p.h"
#include <QuantKit/Instrument.h>
#include "TimeSeries_p.h"
#include <QuantKit/BarSeries.h>
#include <QuantKit/TickSeries.h>
#include "Tick_p.h"
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Event/Level2.h>
#include <QuantKit/Event/Level2Snapshot.h>
#include <QuantKit/Event/Level2Update.h>
#include <QuantKit/Event/Fundamental.h>
#include <QuantKit/Event/News.h>
#include "DataObject_p.h"
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/OrderBook.h>
#include <QuantKit/Event/HistoricalData.h>
#include <QuantKit/Event/HistoricalDataEnd.h>
#include <QuantKit/IdArray.h>

namespace QuantKit {

class DataManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	DataServer m_server;
	IdArray<Bid> m_idArray;
	IdArray<Ask> idArray_1;
	IdArray<Trade> idArray_2;
	IdArray<Bar> idArray_3;
	IdArray<OrderBook> idArray_4;
	IdArray<News> idArray_5;
	IdArray<Fundamental> idArray_6;
	Thread m_thread;
	bool bool_0;
	Dictionary<QString,Class46> m_dictionary;

public:
	DataManagerPrivate(const Framework& framework, const DataServer& server);
	virtual ~DataManagerPrivate();

public:
	DataServer server() const { return m_server; }
	DataSeries addDataSeries(const Instrument& instrument, unsigned char type)
	{
		return m_server.AddDataSeries(instrument, type, BarType.Time, 60L);
	}

	DataSeries addDataSeries(const QString& name)
	{
		return m_server.AddDataSeries(name);
	}

	TimeSeries addTimeSeries(const QString& name)
	{
		return new TimeSeries(m_server.AddDataSeries(name));
	}

	void clear();
	void deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
	{
		m_server.DeleteDataSeries(instrument, type, barType, barSize);
	}

	void deleteDataSeries(const QString& symbol, unsigned char type, BarType barType, long barSize)
	{
		m_server.DeleteDataSeries(m_framework.instrumentManager().instruments()[symbol], type, barType, barSize);
	}

	void deleteDataSeries(const QString& name)
	{
		m_server.DeleteDataSeries(name);
	}

	void dispose();
	void dump();
	Ask getAsk(const Instrument& instrument)
	{
		return idArray_1[instrument.id()];
	}

	Ask getAsk(int instrumentId)
	{
		return idArray_1[instrumentId];
	}

	Bar getBar(const Instrument& instrument)
	{
		return idArray_3[instrument.id()];
	}

	Bar getBar(int instrumentId)
	{
		return idArray_3[instrumentId];
	}

	Bid getBid(const Instrument& instrument)
	{
		return m_idArray[instrument.id()];
	}

	Bid getBid(int instrumentId)
	{
		return m_idArray[instrumentId];
	}

	DataSeries getDataSeries(const QString& symbol, unsigned char type, BarType barType, long barSize)
	{
		return m_server.GetDataSeries(m_framework.instrumentManager().instruments()[symbol], type, barType, barSize);
	}

	DataSeries getDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
	{
		return m_server.GetDataSeries(instrument, type, barType, barSize);
	}

	DataSeries getDataSeries(const QString& name)
	{
		return m_server.GetDataSeries(name);
	}

	QList<DataSeries> getDataSeriesList(const Instrument& instrument, const QString& pattern)
	{
		return m_server.GetDataSeriesList(instrument, pattern);
	}

	TickSeries getHistoricalAsks(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(TickType.Ask, symbol, dateTime1, dateTime2);
	}

	TickSeries getHistoricalAsks(const QString& symbol)
	{
		return GetHistoricalAsks(symbol, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalAsks(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(TickType.Ask, instrument, dateTime1, dateTime2);
	}

	TickSeries getHistoricalAsks(const Instrument& instrument)
	{
		return GetHistoricalTicks(TickType.Ask, instrument, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalAsks(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalAsks(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(provider, TickType.Ask, instrument, dateTime1, dateTime2);
	}

	BarSeries getHistoricalBars(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize);
	BarSeries getHistoricalBars(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize);
	BarSeries getHistoricalBars(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize);
	TickSeries getHistoricalBids(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(TickType.Bid, symbol, dateTime1, dateTime2);
	}

	TickSeries getHistoricalBids(const QString& symbol)
	{
		return GetHistoricalBids(symbol, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalBids(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(TickType.Bid, instrument, dateTime1, dateTime2);
	}

	TickSeries getHistoricalBids(const Instrument& instrument)
	{
		return GetHistoricalTicks(TickType.Bid, instrument, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalBids(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalBids(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(provider, TickType.Bid, instrument, dateTime1, dateTime2);
	}

	TickSeries getHistoricalTicks(TickType type, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTicks(TickType type, const QString& symbol)
	{
		return GetHistoricalTicks(type, symbol, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalTicks(TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTicks(TickType type, const Instrument& instrument)
	{
		return GetHistoricalTicks(type, instrument, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalTicks(const IHistoricalDataProvider& provider, TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(TickType.Trade, symbol, dateTime1, dateTime2);
	}

	TickSeries getHistoricalTrades(const QString& symbol)
	{
		return GetHistoricalTrades(symbol, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalTrades(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(TickType.Trade, instrument, dateTime1, dateTime2);
	}

	TickSeries getHistoricalTrades(const Instrument& instrument)
	{
		return GetHistoricalTicks(TickType.Trade, instrument, DateTime.MinValue, DateTime.MaxValue);
	}

	TickSeries getHistoricalTrades(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	{
		return GetHistoricalTicks(provider, TickType.Trade, instrument, dateTime1, dateTime2);
	}

	OrderBook getOrderBook(const Instrument& instrument)
	{
		return idArray_4[instrument.id()];
	}

	OrderBook getOrderBook(int instrumentId)
	{
		return idArray_4[instrumentId];
	}

	TimeSeries getTimeSeries(const QString& name)
	{
		return new TimeSeries(m_server.GetDataSeries(name));
	}

	Trade getTrade(const Instrument& instrument)
	{
		return idArray_2[instrument.id()];
	}

	Trade getTrade(int instrumentId)
	{
		return idArray_2[instrumentId];
	}

	void save(const BarSeries& series, SaveMode option);
	void save(const TickSeries& series, SaveMode option);
	void save(const Tick& tick, SaveMode option)
	{
		Save(tick.instrumentId(), tick, option);
	}

	void save(const Bar& bar, SaveMode option)
	{
		Save(bar.instrumentId(), bar, option);
	}

	void save(const Level2& level2, SaveMode option)
	{
		Save(level2.instrumentId(), level2, option);
	}

	void save(const Level2Snapshot& level2, SaveMode option)
	{
		Save(level2.int_0(), level2, option);
	}

	void save(const Level2Update& level2, SaveMode option)
	{
		Save(level2.int_0(), level2, option);
	}

	void save(const Fundamental& fundamental, SaveMode option)
	{
		Save(fundamental.int_1(), fundamental, option);
	}

	void save(const News& news, SaveMode option)
	{
		Save(news.int_1(), news, option);
	}

	void save(const Instrument& instrument, const DataObject& obj, SaveMode option)
	{
		m_server.Save(instrument, obj, option);
	}

	void save(int instrumentId, const DataObject& obj, SaveMode option);
	void save(const QString& symbol, const DataObject& obj, SaveMode option);
	void save(const Instrument& instrument, const IDataSeries& series, SaveMode option);
	virtual DataManagerPrivate* clone() Q_DECL_OVERRIDE { return new DataManagerPrivate(*this); }
//private:
	void method_0();
	void method_13(bool bool_1);
};

} // namepsace QuantKit


using namespace QuantKit;

DataManagerPrivate::DataManagerPrivate(const Framework& framework, const DataServer& server)
	: m_framework(framework)
	, m_server(server)
	, m_idArray(new IdArray<Bid>(10000))
	, idArray_1(new IdArray<Ask>(10000))
	, idArray_2(new IdArray<Trade>(10000))
	, idArray_3(new IdArray<Bar>(10000))
	, idArray_4(new IdArray<OrderBook>(10000))
	, idArray_5(new IdArray<News>(10000))
	, idArray_6(new IdArray<Fundamental>(10000))
	, m_thread(new Thread(new ThreadStart(method_0())))
{
		if (server != null)
		{
			server.Open();
		}
		m_thread.Name = "Data Manager Thread";
		m_thread.IsBackground = true;
		m_thread.Start();
}

DataManagerPrivate::~DataManagerPrivate ()
{
}

void DataManagerPrivate::clear()
{
	m_idArray.Clear();
	idArray_1.Clear();
	idArray_2.Clear();
	idArray_3.Clear();
	idArray_4.Clear();
}

void DataManagerPrivate::dispose()
{
	method_13(true);
	GC.SuppressFinalize(this);
}

void DataManagerPrivate::dump()
{
	Console.WriteLine("Bid");
	for (int i = 0; i < m_idArray.Size; i++)
	{
		if (m_idArray[i] != null)
		{
			Console.WriteLine(m_idArray[i]);
		}
	}
	Console.WriteLine("Ask");
	for (int j = 0; j < idArray_1.Size; j++)
	{
		if (idArray_1[j] != null)
		{
			Console.WriteLine(idArray_1[j]);
		}
	}
	Console.WriteLine("Trade");
	for (int k = 0; k < idArray_2.Size; k++)
	{
		if (idArray_2[k] != null)
		{
			Console.WriteLine(idArray_2[k]);
		}
	}
}

TickSeries DataManagerPrivate::getHistoricalAsks(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	IHistoricalDataProvider historicalDataProvider = m_framework.providerManager().GetHistoricalDataProvider(provider);
	if (historicalDataProvider == null)
	{
		Console.WriteLine("DataManager::GetHistoricalAsks Error. Provider does not exist : " + provider);
		return null;
	}
	Instrument instrument = m_framework.instrumentManager()[symbol];
	if (instrument == null)
	{
		Console.WriteLine("DataManager::GetHistoricalAsks Error. Instrument with such symbol does not exist : " + symbol);
		return null;
	}
	return GetHistoricalAsks(historicalDataProvider, instrument, dateTime1, dateTime2);
}

BarSeries DataManagerPrivate::getHistoricalBars(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize)
{
	IHistoricalDataProvider historicalDataProvider = m_framework.providerManager().GetHistoricalDataProvider(provider);
	if (historicalDataProvider == null)
	{
		Console.WriteLine("DataManager::GetHistoricalBars Error. Provider does not exist : " + provider);
		return null;
	}
	return GetHistoricalBars(historicalDataProvider, instrument, dateTime1, dateTime2, barType, barSize);
}

BarSeries DataManagerPrivate::getHistoricalBars(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize)
{
	IHistoricalDataProvider historicalDataProvider = m_framework.providerManager().GetHistoricalDataProvider(provider);
	if (historicalDataProvider == null)
	{
		Console.WriteLine("DataManager::GetHistoricalBars Error. Provider does not exist : " + provider);
		return null;
	}
	Instrument instrument = m_framework.instrumentManager()[symbol];
	if (instrument == null)
	{
		Console.WriteLine("DataManager::GetHistoricalBars Error. Instrument with such symbol does not exist : " + symbol);
		return null;
	}
	return GetHistoricalBars(historicalDataProvider, instrument, dateTime1, dateTime2, barType, barSize);
}

BarSeries DataManagerPrivate::getHistoricalBars(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize)
{
	if (provider.isDisconnected())
	{
		provider.Connect();
	}
	DataManager.Class46 @class = new DataManager.Class46();
	string text = Guid.NewGuid().ToString();
	lock (m_dictionary)
	{
		m_dictionary.Add(text, @class);
	}
	provider.Send(new HistoricalDataRequest(instrument, dateTime1, dateTime2, 6)
	{
		RequestId = text,
		BarType = new BarType?(barType),
		BarSize = new long?(barSize)
	});
	@class.method_2().WaitOne();
	lock (m_dictionary)
	{
		m_dictionary.Remove(text);
	}
	BarSeries barSeries = new BarSeries("", "", -1);
	foreach (HistoricalData current in @class.method_0())
	{
		DataObject[] objects = current.objects();
		for (int i = 0; i < objects.Length; i++)
		{
			Bar bar = (Bar)objects[i];
			barSeries.Add(bar);
		}
	}
	return barSeries;
}

TickSeries DataManagerPrivate::getHistoricalBids(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	IHistoricalDataProvider historicalDataProvider = m_framework.providerManager().GetHistoricalDataProvider(provider);
	if (historicalDataProvider == null)
	{
		Console.WriteLine("DataManager::GetHistoricalBids Error. Provider does not exist : " + provider);
		return null;
	}
	Instrument instrument = m_framework.instrumentManager()[symbol];
	if (instrument == null)
	{
		Console.WriteLine("DataManager::GetHistoricalBids Error. Instrument with such symbol does not exist : " + symbol);
		return null;
	}
	return GetHistoricalBids(historicalDataProvider, instrument, dateTime1, dateTime2);
}

TickSeries DataManagerPrivate::getHistoricalTicks(TickType type, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	Instrument instrument = m_framework.instrumentManager().instruments()[symbol];
	return GetHistoricalTicks(type, instrument, dateTime1, dateTime2);
}

TickSeries DataManagerPrivate::getHistoricalTicks(TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	DataSeries dataSeries = null;
	switch (type)
	{
		case TickType.Bid:
			dataSeries = GetDataSeries(instrument, 2, BarType.Time, 60L);
			break;
		case TickType.Ask:
			dataSeries = GetDataSeries(instrument, 3, BarType.Time, 60L);
			break;
		case TickType.Trade:
			dataSeries = GetDataSeries(instrument, 4, BarType.Time, 60L);
			break;
	}
	long index = dataSeries.GetIndex(dateTime1, SearchOption.Next);
	long index2 = dataSeries.GetIndex(dateTime2, SearchOption.Prev);
	TickSeries tickSeries = new TickSeries("");
	for (long num = index; num <= index2; num += 1L)
	{
		DataObject dataObject = dataSeries[num];
		switch (type)
		{
			case TickType.Bid:
				if (dataObject.typeId() == 2)
				{
					tickSeries.Add((Bid)dataObject);
				}
				else
				{
					Console.WriteLine("DataManager::GetHistoricalTicks Error, object type is not Bid " + dataObject);
				}
				break;
			case TickType.Ask:
				if (dataObject.typeId() == 3)
				{
					tickSeries.Add((Ask)dataObject);
				}
				else
				{
					Console.WriteLine("DataManager::GetHistoricalTicks Error, object type is not Ask " + dataObject);
				}
				break;
			case TickType.Trade:
				if (dataObject.typeId() == 4)
				{
					tickSeries.Add((Trade)dataObject);
				}
				else
				{
					Console.WriteLine("DataManager::GetHistoricalTicks Error, object type is not Trade " + dataObject);
				}
				break;
		}
	}
	return tickSeries;
}

TickSeries DataManagerPrivate::getHistoricalTicks(const IHistoricalDataProvider& provider, TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	if (provider.isDisconnected())
	{
		provider.Connect();
	}
	DataManager.Class46 @class = new DataManager.Class46();
	string text = Guid.NewGuid().ToString();
	lock (m_dictionary)
	{
		m_dictionary.Add(text, @class);
	}
	HistoricalDataRequest historicalDataRequest = null;
	switch (type)
	{
		case TickType.Bid:
			historicalDataRequest = new HistoricalDataRequest(instrument, dateTime1, dateTime2, 2);
			break;
		case TickType.Ask:
			historicalDataRequest = new HistoricalDataRequest(instrument, dateTime1, dateTime2, 3);
			break;
		case TickType.Trade:
			historicalDataRequest = new HistoricalDataRequest(instrument, dateTime1, dateTime2, 4);
			break;
	}
	historicalDataRequest.setRequestId() = text;
	provider.Send(historicalDataRequest);
	@class.method_2().WaitOne();
	lock (m_dictionary)
	{
		m_dictionary.Remove(text);
	}
	TickSeries tickSeries = new TickSeries("");
	foreach (HistoricalData current in @class.method_0())
	{
		DataObject[] objects = current.objects();
		for (int i = 0; i < objects.Length; i++)
		{
			DataObject dataObject = objects[i];
			tickSeries.Add((Tick)dataObject);
		}
	}
	return tickSeries;
}

TickSeries DataManagerPrivate::getHistoricalTrades(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	IHistoricalDataProvider historicalDataProvider = m_framework.providerManager().GetHistoricalDataProvider(provider);
	if (historicalDataProvider == null)
	{
		Console.WriteLine("DataManager::GetHistoricalTrades Error. Provider does not exist : " + provider);
		return null;
	}
	return GetHistoricalTrades(historicalDataProvider, instrument, dateTime1, dateTime2);
}

TickSeries DataManagerPrivate::getHistoricalTrades(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	IHistoricalDataProvider historicalDataProvider = m_framework.providerManager().GetHistoricalDataProvider(provider);
	if (historicalDataProvider == null)
	{
		Console.WriteLine("DataManager::GetHistoricalTrades Error. Provider does not exist : " + provider);
		return null;
	}
	Instrument instrument = m_framework.instrumentManager()[symbol];
	if (instrument == null)
	{
		Console.WriteLine("DataManager::GetHistoricalTrades Error. Instrument with such symbol does not exist : " + symbol);
		return null;
	}
	return GetHistoricalTrades(historicalDataProvider, instrument, dateTime1, dateTime2);
}

void DataManagerPrivate::save(const BarSeries& series, SaveMode option)
{
	for (int i = 0; i < series.count(); i++)
	{
		Save(series[i], option);
	}
}

void DataManagerPrivate::save(const TickSeries& series, SaveMode option)
{
	for (int i = 0; i < series.count(); i++)
	{
		Save(series[i], option);
	}
}

void DataManagerPrivate::save(int instrumentId, const DataObject& obj, SaveMode option)
{
	Instrument byId = m_framework.instrumentManager().GetById(instrumentId);
	if (byId == null)
	{
		Console.WriteLine("DataManager::Save Instrument with id does not exist in the framework id = " + instrumentId);
		return;
	}
	m_server.Save(byId, obj, option);
}

void DataManagerPrivate::save(const QString& symbol, const DataObject& obj, SaveMode option)
{
	Instrument instrument = m_framework.instrumentManager()[symbol];
	if (instrument == null)
	{
		Console.WriteLine("DataManager::Save Instrument with symbol does not exist in the framework " + symbol);
		return;
	}
	m_server.Save(instrument, obj, option);
}

void DataManagerPrivate::save(const Instrument& instrument, const IDataSeries& series, SaveMode option)
{
	int num = 0;
	while ((long)num < series.count())
	{
		m_server.Save(instrument, series[(long)num], option);
		num++;
	}
}

void DataManagerPrivate::method_0()
{
	Console.WriteLine(string.Concat(new object[]
	{
		DateTime.Now,
		" Data manager thread started: Framework = ",
		m_framework.name(),
		" Clock = ",
		m_framework.clock().GetModeAsString()
	}));
	EventPipe historicalPipe = m_framework.eventBus().historicalPipe();
	while (!bool_0)
	{
		if (!historicalPipe.IsEmpty())
		{
			Event @event = historicalPipe.Read();
			byte typeId = @event.typeId();
			switch (typeId)
			{
				case 136:
					method_9((HistoricalData)@event);
					break;
				case 137:
					method_10((HistoricalDataEnd)@event);
					break;
				default:
					switch (typeId)
					{
						case 205:
						case 206:
							break;
						default:
							Console.WriteLine("DataManager::ThreadRun Error. Unknown event type : " + @event.typeId());
							break;
					}
					break;
			}
			m_framework.eventManager().dispatcher().OnEvent(@event);
		}
		else
		{
			Thread.Sleep(1);
		}
	}
	Console.WriteLine(string.Concat(new object[]
	{
		DateTime.Now,
		" Data manager thread stopped: Framework = ",
		m_framework.name(),
		" Clock = ",
		m_framework.clock().GetModeAsString()
	}));
}

void DataManagerPrivate::method_13(bool bool_1)
{
	if (bool_1)
	{
		bool_0 = true;
	}
}


// Pubic API 

DataManager::DataManager(const Framework& framework, const DataServer& server)
	: d_ptr(new DataManagerPrivate(framework, server))
{
}

DataManager::~DataManager()
{
}

DataManager::DataManager (const DataManager &other)
	: d_ptr(other.d_ptr)
{
}

DataManager& DataManager::operator=(const DataManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataManager::operator==(const DataManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

DataServer DataManager::server() const
{
	return d_ptr->server();
}

DataSeries DataManager::addDataSeries(const Instrument& instrument, unsigned char type)
{
	return d_ptr->addDataSeries(instrument, type);
}

DataSeries DataManager::addDataSeries(const QString& name)
{
	return d_ptr->addDataSeries(name);
}

TimeSeries DataManager::addTimeSeries(const QString& name)
{
	return d_ptr->addTimeSeries(name);
}

void DataManager::clear()
{
	d_ptr->clear();
}

void DataManager::deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	d_ptr->deleteDataSeries(instrument, type, barType, barSize);
}

void DataManager::deleteDataSeries(const QString& symbol, unsigned char type, BarType barType, long barSize)
{
	d_ptr->deleteDataSeries(symbol, type, barType, barSize);
}

void DataManager::deleteDataSeries(const QString& name)
{
	d_ptr->deleteDataSeries(name);
}

void DataManager::dispose()
{
	d_ptr->dispose();
}

void DataManager::dump()
{
	d_ptr->dump();
}

Ask DataManager::getAsk(const Instrument& instrument)
{
	return d_ptr->getAsk(instrument);
}

Ask DataManager::getAsk(int instrumentId)
{
	return d_ptr->getAsk(instrumentId);
}

Bar DataManager::getBar(const Instrument& instrument)
{
	return d_ptr->getBar(instrument);
}

Bar DataManager::getBar(int instrumentId)
{
	return d_ptr->getBar(instrumentId);
}

Bid DataManager::getBid(const Instrument& instrument)
{
	return d_ptr->getBid(instrument);
}

Bid DataManager::getBid(int instrumentId)
{
	return d_ptr->getBid(instrumentId);
}

DataSeries DataManager::getDataSeries(const QString& symbol, unsigned char type, BarType barType, long barSize)
{
	return d_ptr->getDataSeries(symbol, type, barType, barSize);
}

DataSeries DataManager::getDataSeries(const Instrument& instrument, unsigned char type, BarType barType, long barSize)
{
	return d_ptr->getDataSeries(instrument, type, barType, barSize);
}

DataSeries DataManager::getDataSeries(const QString& name)
{
	return d_ptr->getDataSeries(name);
}

QList<DataSeries> DataManager::getDataSeriesList(Instrument instrument, QString pattern)
{
	return d_ptr->getDataSeriesList(instrument, pattern);
}

TickSeries DataManager::getHistoricalAsks(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalAsks(symbol, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalAsks(const QString& symbol)
{
	return d_ptr->getHistoricalAsks(symbol);
}

TickSeries DataManager::getHistoricalAsks(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalAsks(instrument, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalAsks(const Instrument& instrument)
{
	return d_ptr->getHistoricalAsks(instrument);
}

TickSeries DataManager::getHistoricalAsks(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalAsks(provider, symbol, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalAsks(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalAsks(provider, instrument, dateTime1, dateTime2);
}

BarSeries DataManager::getHistoricalBars(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize)
{
	return d_ptr->getHistoricalBars(provider, instrument, dateTime1, dateTime2, barType, barSize);
}

BarSeries DataManager::getHistoricalBars(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize)
{
	return d_ptr->getHistoricalBars(provider, symbol, dateTime1, dateTime2, barType, barSize);
}

BarSeries DataManager::getHistoricalBars(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize)
{
	return d_ptr->getHistoricalBars(provider, instrument, dateTime1, dateTime2, barType, barSize);
}

TickSeries DataManager::getHistoricalBids(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalBids(symbol, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalBids(const QString& symbol)
{
	return d_ptr->getHistoricalBids(symbol);
}

TickSeries DataManager::getHistoricalBids(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalBids(instrument, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalBids(const Instrument& instrument)
{
	return d_ptr->getHistoricalBids(instrument);
}

TickSeries DataManager::getHistoricalBids(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalBids(provider, symbol, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalBids(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalBids(provider, instrument, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTicks(TickType type, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTicks(type, symbol, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTicks(TickType type, const QString& symbol)
{
	return d_ptr->getHistoricalTicks(type, symbol);
}

TickSeries DataManager::getHistoricalTicks(TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTicks(type, instrument, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTicks(TickType type, const Instrument& instrument)
{
	return d_ptr->getHistoricalTicks(type, instrument);
}

TickSeries DataManager::getHistoricalTicks(const IHistoricalDataProvider& provider, TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTicks(provider, type, instrument, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTrades(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTrades(symbol, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTrades(const QString& symbol)
{
	return d_ptr->getHistoricalTrades(symbol);
}

TickSeries DataManager::getHistoricalTrades(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTrades(instrument, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTrades(const Instrument& instrument)
{
	return d_ptr->getHistoricalTrades(instrument);
}

TickSeries DataManager::getHistoricalTrades(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTrades(provider, instrument, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTrades(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTrades(provider, symbol, dateTime1, dateTime2);
}

TickSeries DataManager::getHistoricalTrades(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
{
	return d_ptr->getHistoricalTrades(provider, instrument, dateTime1, dateTime2);
}

OrderBook DataManager::getOrderBook(const Instrument& instrument)
{
	return d_ptr->getOrderBook(instrument);
}

OrderBook DataManager::getOrderBook(int instrumentId)
{
	return d_ptr->getOrderBook(instrumentId);
}

TimeSeries DataManager::getTimeSeries(const QString& name)
{
	return d_ptr->getTimeSeries(name);
}

Trade DataManager::getTrade(const Instrument& instrument)
{
	return d_ptr->getTrade(instrument);
}

Trade DataManager::getTrade(int instrumentId)
{
	return d_ptr->getTrade(instrumentId);
}

void DataManager::save(const BarSeries& series, SaveMode option)
{
	d_ptr->save(series, option);
}

void DataManager::save(const TickSeries& series, SaveMode option)
{
	d_ptr->save(series, option);
}

void DataManager::save(const Tick& tick, SaveMode option)
{
	d_ptr->save(tick, option);
}

void DataManager::save(const Bar& bar, SaveMode option)
{
	d_ptr->save(bar, option);
}

void DataManager::save(const Level2& level2, SaveMode option)
{
	d_ptr->save(level2, option);
}

void DataManager::save(const Level2Snapshot& level2, SaveMode option)
{
	d_ptr->save(level2, option);
}

void DataManager::save(const Level2Update& level2, SaveMode option)
{
	d_ptr->save(level2, option);
}

void DataManager::save(const Fundamental& fundamental, SaveMode option)
{
	d_ptr->save(fundamental, option);
}

void DataManager::save(const News& news, SaveMode option)
{
	d_ptr->save(news, option);
}

void DataManager::save(const Instrument& instrument, const DataObject& obj, SaveMode option)
{
	d_ptr->save(instrument, obj, option);
}

void DataManager::save(int instrumentId, const DataObject& obj, SaveMode option)
{
	d_ptr->save(instrumentId, obj, option);
}

void DataManager::save(const QString& symbol, const DataObject& obj, SaveMode option)
{
	d_ptr->save(symbol, obj, option);
}

void DataManager::save(const Instrument& instrument, const IDataSeries& series, SaveMode option)
{
	d_ptr->save(instrument, series, option);
}

QDebug operator<<(QDebug dbg, const DataManager& datamanager)
{
	return dbg << datamanager.toString();
}

