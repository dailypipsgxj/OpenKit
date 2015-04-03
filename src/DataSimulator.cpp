#include <QuantKit/DataSimulator.h>

#include <QuantKit/BarFilter.h>
#include <QuantKit/DataProcessor.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentList.h>
#include <QuantKit/LinkedList.h>
#include "Provider_p.h"

namespace QuantKit {

class DataSimulatorPrivate : public ProviderPrivate
{
public:
	Thread m_thread;
	LinkedList<Class52> linkedList_0;
	long long_0;
	QDateTime m_dateTime1;
	QDateTime m_dateTime2;
	bool bool_0;
	bool bool_1;
	bool m_subscribeAll;
	bool m_subscribeAll;
	bool m_subscribeAll;
	bool m_subscribeAll;
	bool m_subscribeAll;
	bool m_subscribeAll;
	bool m_subscribeAll;
	bool m_subscribeAll;
	BarFilter m_barFilter;
	QList<IDataSeries> m_series;
	DataProcessor m_processor;

public:
	explicit DataSimulatorPrivate(const Framework& framework);
	virtual ~DataSimulatorPrivate();

public:
	QDateTime dateTime1() const { return m_dateTime1; }
	void setDateTime1(const QDateTime& value) { m_dateTime1 = value; }
	QDateTime dateTime2() const { return m_dateTime2; }
	void setDateTime2(const QDateTime& value) { m_dateTime2 = value; }
	bool subscribeBid() const { return m_subscribeAll; }
	void setSubscribeBid(bool value) { m_subscribeAll = value; }
	bool subscribeAsk() const { return m_subscribeAll; }
	void setSubscribeAsk(bool value) { m_subscribeAll = value; }
	bool subscribeQuote() const { return m_subscribeAll; }
	void setSubscribeQuote(bool value) { m_subscribeAll = value; }
	bool subscribeTrade() const { return m_subscribeAll; }
	void setSubscribeTrade(bool value) { m_subscribeAll = value; }
	bool subscribeBar() const { return m_subscribeAll; }
	void setSubscribeBar(bool value) { m_subscribeAll = value; }
	bool subscribeLevelII() const { return m_subscribeAll; }
	void setSubscribeLevelII(bool value) { m_subscribeAll = value; }
	bool subscribeNews() const { return m_subscribeAll; }
	void setSubscribeNews(bool value) { m_subscribeAll = value; }
	bool subscribeFundamental() const { return m_subscribeAll; }
	void setSubscribeFundamental(bool value) { m_subscribeAll = value; }
	void setSubscribeAll(bool value);
	BarFilter barFilter() const { return m_barFilter; }
	QList<IDataSeries> series() const { return m_series; }
	void setSeries(const QList<IDataSeries>& value) { m_series = value; }
	DataProcessor processor() const { return m_processor; }
	void setProcessor(const DataProcessor& value) { m_processor = value; }
	void clear();
	virtual void connect() Q_DECL_OVERRIDE;
	virtual void disconnect() Q_DECL_OVERRIDE;
	virtual void subscribe(const Instrument& instrument) Q_DECL_OVERRIDE;
	virtual void subscribe(const InstrumentList& instruments) Q_DECL_OVERRIDE;
	virtual DataSimulatorPrivate* clone() Q_DECL_OVERRIDE { return new DataSimulatorPrivate(*this); }
//private:
	void method_4(const Instrument& instrument, const QDateTime& dateTime_2, const QDateTime& dateTime_3);
	void method_5();
	void method_6();
};

} // namepsace QuantKit


using namespace QuantKit;

DataSimulatorPrivate::DataSimulatorPrivate(const Framework& framework)
	: ProviderPrivate (framework)
	, m_dateTime1(DateTime.MinValue)
	, m_dateTime2(DateTime.MaxValue)
	, m_subscribeAll(true)
	, m_subscribeAll(true)
	, m_subscribeAll(true)
	, m_subscribeAll(true)
	, m_subscribeAll(true)
	, m_subscribeAll(true)
	, m_subscribeAll(true)
	, m_subscribeAll(true)
	, m_barFilter(new BarFilter())
	, m_series(new QList<IDataSeries>())
	, m_processor(new DataProcessor())
{
		m_id = 1;
		m_name = "DataSimulator";
		m_description = "Default data simulator";
		m_url = "www.smartquant.com";
}

DataSimulatorPrivate::~DataSimulatorPrivate ()
{
}

void DataSimulatorPrivate::setSubscribeAll(bool value)
{
	m_subscribeAll = value;
	m_subscribeAll = value;
	m_subscribeAll = value;
	m_subscribeAll = value;
	m_subscribeAll = value;
	m_subscribeAll = value;
	m_subscribeAll = value;
	m_subscribeAll = value;
}

void DataSimulatorPrivate::clear()
{
	m_series.Clear();
	linkedList_0.Clear();
	m_dateTime1 = DateTime.MinValue;
	m_dateTime2 = DateTime.MaxValue;
}

void DataSimulatorPrivate::connect()
{
	if (!base.isConnected())
	{
		base.setStatus() = ProviderStatus.Connected;
	}
}

void DataSimulatorPrivate::disconnect()
{
	if (!base.isDisconnected())
	{
		bool_0 = true;
		while (bool_1)
		{
			Thread.Sleep(1);
		}
		Clear();
		base.setStatus() = ProviderStatus.Disconnected;
	}
}

void DataSimulatorPrivate::subscribe(const Instrument& instrument)
{
	if (!bool_1)
	{
		method_4(instrument, m_dateTime1, m_dateTime2);
		method_5();
		return;
	}
	method_4(instrument, framework.clock().dateTime(), m_dateTime2);
}

void DataSimulatorPrivate::subscribe(const InstrumentList& instruments)
{
	if (!bool_1)
	{
		foreach (Instrument current in instruments)
		{
			method_4(current, m_dateTime1, m_dateTime2);
		}
		method_5();
		return;
	}
	foreach (Instrument current2 in instruments)
	{
		method_4(current2, framework.clock().dateTime(), m_dateTime2);
	}
}

void DataSimulatorPrivate::method_4(const Instrument& instrument, const QDateTime& dateTime_2, const QDateTime& dateTime_3)
{
	Console.WriteLine(DateTime.Now + " DataSimulator::Subscribe " + instrument.symbol());
	if (m_subscribeAll)
	{
		DataSeries dataSeries = framework.dataManager().GetDataSeries(instrument, 4, BarType.Time, 60L);
		if (dataSeries != null)
		{
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = dataSeries.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(dataSeries, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
	if (m_subscribeAll)
	{
		DataSeries dataSeries = framework.dataManager().GetDataSeries(instrument, 2, BarType.Time, 60L);
		if (dataSeries != null)
		{
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = dataSeries.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(dataSeries, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
	if (m_subscribeAll)
	{
		DataSeries dataSeries = framework.dataManager().GetDataSeries(instrument, 3, BarType.Time, 60L);
		if (dataSeries != null)
		{
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = dataSeries.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(dataSeries, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
	if (m_subscribeAll)
	{
		DataSeries dataSeries = framework.dataManager().GetDataSeries(instrument, 5, BarType.Time, 60L);
		if (dataSeries != null)
		{
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = dataSeries.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(dataSeries, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
	if (m_subscribeAll)
	{
		List<DataSeries> dataSeriesList = framework.dataManager().GetDataSeriesList(instrument, "Bar");
		foreach (DataSeries current in dataSeriesList)
		{
			if (m_barFilter.count() != 0)
			{
				BarType barType;
				long barSize;
				DataSeriesNameHelper.TryGetBarTypeSize(current, out barType, out barSize);
				if (!m_barFilter.Contains(barType, barSize))
				{
					continue;
				}
			}
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = current.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(current, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
	if (m_subscribeAll)
	{
		DataSeries dataSeries = framework.dataManager().GetDataSeries(instrument, 7, BarType.Time, 60L);
		if (dataSeries != null)
		{
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = dataSeries.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(dataSeries, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
	if (m_subscribeAll)
	{
		DataSeries dataSeries = framework.dataManager().GetDataSeries(instrument, 22, BarType.Time, 60L);
		if (dataSeries != null)
		{
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = dataSeries.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(dataSeries, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
	if (m_subscribeAll)
	{
		DataSeries dataSeries = framework.dataManager().GetDataSeries(instrument, 23, BarType.Time, 60L);
		if (dataSeries != null)
		{
			EventQueue eventQueue = new EventQueue(1, 0, 2, 25000, null);
			eventQueue.setIsSynched() = true;
			eventQueue.setName() = dataSeries.name();
			eventQueue.Enqueue(new OnQueueOpened(eventQueue));
			framework.eventBus().dataPipe().Add(eventQueue);
			linkedList_0.Add(new Class52(dataSeries, dateTime_2, dateTime_3, eventQueue, m_processor));
		}
	}
}

void DataSimulatorPrivate::method_5()
{
	m_thread = new Thread(new ThreadStart(method_6()));
	m_thread.Name = "Data Simulator Thread";
	m_thread.IsBackground = true;
	m_thread.Start();
}

void DataSimulatorPrivate::method_6()
{
	Console.WriteLine(DateTime.Now + " Data simulator thread started");
	if (!base.isConnected())
	{
		Connect();
	}
	EventQueue eventQueue = new EventQueue(1, 0, 2, 10, null);
	eventQueue.setIsSynched() = true;
	eventQueue.Enqueue(new OnQueueOpened(eventQueue));
	eventQueue.Enqueue(new OnSimulatorStart(m_dateTime1, m_dateTime2, 0L));
	eventQueue.Enqueue(new OnQueueClosed(eventQueue));
	framework.eventBus().dataPipe().Add(eventQueue);
	bool_1 = true;
	bool_0 = false;
	while (!bool_0)
	{
		LinkedListNode<Class52> linkedListNode = linkedList_0.First;
		LinkedListNode<Class52> linkedListNode2 = null;
		while (linkedListNode != null)
		{
			Class52 data = linkedListNode.Data;
			if (!data.bool_0())
			{
				if (data.method_1())
				{
					long_0 += 1L;
				}
				linkedListNode2 = linkedListNode;
			}
			else
			{
				if (linkedListNode2 == null)
				{
					linkedList_0.First = linkedListNode.Next;
				}
				else
				{
					linkedListNode2.Next = linkedListNode.Next;
				}
				linkedList_0.Count--;
				data.eventQueue_0().Enqueue(new OnQueueClosed(data.eventQueue_0()));
			}
			linkedListNode = linkedListNode.Next;
		}
	}
	bool_0 = false;
	bool_1 = false;
	Console.WriteLine(DateTime.Now + " Data simulator thread stopped");
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(DataSimulator)

DataSimulator::DataSimulator(const Framework& framework)
	: Provider(*new DataSimulatorPrivate(framework))
{
}

DataSimulator::~DataSimulator()
{
}

QDateTime DataSimulator::dateTime1() const
{
	Q_D(const DataSimulator);
	return d->dateTime1();
}

void DataSimulator::setDateTime1(const QDateTime& value)
{
	Q_D(DataSimulator);
	d->setDateTime1(value);
}

QDateTime DataSimulator::dateTime2() const
{
	Q_D(const DataSimulator);
	return d->dateTime2();
}

void DataSimulator::setDateTime2(const QDateTime& value)
{
	Q_D(DataSimulator);
	d->setDateTime2(value);
}

bool DataSimulator::subscribeBid() const
{
	Q_D(const DataSimulator);
	return d->subscribeBid();
}

void DataSimulator::setSubscribeBid(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeBid(value);
}

bool DataSimulator::subscribeAsk() const
{
	Q_D(const DataSimulator);
	return d->subscribeAsk();
}

void DataSimulator::setSubscribeAsk(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeAsk(value);
}

bool DataSimulator::subscribeQuote() const
{
	Q_D(const DataSimulator);
	return d->subscribeQuote();
}

void DataSimulator::setSubscribeQuote(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeQuote(value);
}

bool DataSimulator::subscribeTrade() const
{
	Q_D(const DataSimulator);
	return d->subscribeTrade();
}

void DataSimulator::setSubscribeTrade(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeTrade(value);
}

bool DataSimulator::subscribeBar() const
{
	Q_D(const DataSimulator);
	return d->subscribeBar();
}

void DataSimulator::setSubscribeBar(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeBar(value);
}

bool DataSimulator::subscribeLevelII() const
{
	Q_D(const DataSimulator);
	return d->subscribeLevelII();
}

void DataSimulator::setSubscribeLevelII(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeLevelII(value);
}

bool DataSimulator::subscribeNews() const
{
	Q_D(const DataSimulator);
	return d->subscribeNews();
}

void DataSimulator::setSubscribeNews(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeNews(value);
}

bool DataSimulator::subscribeFundamental() const
{
	Q_D(const DataSimulator);
	return d->subscribeFundamental();
}

void DataSimulator::setSubscribeFundamental(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeFundamental(value);
}

void DataSimulator::setSubscribeAll(bool value)
{
	Q_D(DataSimulator);
	d->setSubscribeAll(value);
}

BarFilter DataSimulator::barFilter() const
{
	Q_D(const DataSimulator);
	return d->barFilter();
}

QList<IDataSeries> DataSimulator::series() const
{
	Q_D(const DataSimulator);
	return d->series();
}

void DataSimulator::setSeries(const QList<IDataSeries>& value)
{
	Q_D(DataSimulator);
	d->setSeries(value);
}

DataProcessor DataSimulator::processor() const
{
	Q_D(const DataSimulator);
	return d->processor();
}

void DataSimulator::setProcessor(const DataProcessor& value)
{
	Q_D(DataSimulator);
	d->setProcessor(value);
}

void DataSimulator::clear()
{
	Q_D(DataSimulator);
	d->clear();
}


