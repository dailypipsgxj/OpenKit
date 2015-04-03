#ifndef __QUANTKIT_DATAMANAGER_H__
#define __QUANTKIT_DATAMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QDateTime>
#include <QByteArray>
#include <Thread>
#include <Dictionary>
#include <QSharedDataPointer>

#include <QuantKit/BarType.h>
#include <QuantKit/SaveMode.h>
#include <QuantKit/IDataSeries.h>
#include <QuantKit/TickType.h>
#include <QuantKit/IHistoricalDataProvider.h>

namespace QuantKit {

class DataManagerPrivate;

class DataServer;
class Framework;
class DataSeries;
class Instrument;
class TimeSeries;
class BarSeries;
class TickSeries;
class Tick;
class Bar;
class Level2;
class Level2Snapshot;
class Level2Update;
class Fundamental;
class News;
class DataObject;
class Bid;
class Ask;
class Trade;
class OrderBook;
class HistoricalData;
class HistoricalDataEnd;
class IdArray;

class QUANTKIT_EXPORT DataManager
{
public:
	DataManager(const Framework& framework, const DataServer& server);
	~DataManager();

	DataManager(const DataManager &other);
	DataManager& operator=(const DataManager &other);
	bool operator==(const DataManager &other) const;
	inline bool operator!=(const DataManager &other) const { return !(this->operator==(other));  }
public:
	DataServer server() const;
	DataSeries addDataSeries(const Instrument& instrument, unsigned char type);
	DataSeries addDataSeries(const QString& name);
	TimeSeries addTimeSeries(const QString& name);
	void clear();
	void deleteDataSeries(const Instrument& instrument, unsigned char type, BarType barType = BarType::Time, long barSize = 60);
	void deleteDataSeries(const QString& symbol, unsigned char type, BarType barType = BarType::Time, long barSize = 60);
	void deleteDataSeries(const QString& name);
	void dispose();
	void dump();
	Ask getAsk(const Instrument& instrument);
	Ask getAsk(int instrumentId);
	Bar getBar(const Instrument& instrument);
	Bar getBar(int instrumentId);
	Bid getBid(const Instrument& instrument);
	Bid getBid(int instrumentId);
	DataSeries getDataSeries(const QString& symbol, unsigned char type, BarType barType = BarType::Time, long barSize = 60);
	DataSeries getDataSeries(const Instrument& instrument, unsigned char type, BarType barType = BarType::Time, long barSize = 60);
	DataSeries getDataSeries(const QString& name);
	QList<DataSeries> getDataSeriesList(const Instrument& instrument = 0, const QString& pattern = "");
	TickSeries getHistoricalAsks(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalAsks(const QString& symbol);
	TickSeries getHistoricalAsks(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalAsks(const Instrument& instrument);
	TickSeries getHistoricalAsks(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalAsks(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	BarSeries getHistoricalBars(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize);
	BarSeries getHistoricalBars(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize);
	BarSeries getHistoricalBars(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2, BarType barType, long barSize);
	TickSeries getHistoricalBids(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalBids(const QString& symbol);
	TickSeries getHistoricalBids(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalBids(const Instrument& instrument);
	TickSeries getHistoricalBids(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalBids(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTicks(TickType type, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTicks(TickType type, const QString& symbol);
	TickSeries getHistoricalTicks(TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTicks(TickType type, const Instrument& instrument);
	TickSeries getHistoricalTicks(const IHistoricalDataProvider& provider, TickType type, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const QString& symbol);
	TickSeries getHistoricalTrades(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const Instrument& instrument);
	TickSeries getHistoricalTrades(const QString& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const QString& provider, const QString& symbol, const QDateTime& dateTime1, const QDateTime& dateTime2);
	TickSeries getHistoricalTrades(const IHistoricalDataProvider& provider, const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	OrderBook getOrderBook(const Instrument& instrument);
	OrderBook getOrderBook(int instrumentId);
	TimeSeries getTimeSeries(const QString& name);
	Trade getTrade(const Instrument& instrument);
	Trade getTrade(int instrumentId);
	void save(const BarSeries& series, SaveMode option = SaveMode::Add);
	void save(const TickSeries& series, SaveMode option = SaveMode::Add);
	void save(const Tick& tick, SaveMode option = SaveMode::Add);
	void save(const Bar& bar, SaveMode option = SaveMode::Add);
	void save(const Level2& level2, SaveMode option = SaveMode::Add);
	void save(const Level2Snapshot& level2, SaveMode option = SaveMode::Add);
	void save(const Level2Update& level2, SaveMode option = SaveMode::Add);
	void save(const Fundamental& fundamental, SaveMode option = SaveMode::Add);
	void save(const News& news, SaveMode option = SaveMode::Add);
	void save(const Instrument& instrument, const DataObject& obj, SaveMode option = SaveMode::Add);
	void save(int instrumentId, const DataObject& obj, SaveMode option = SaveMode::Add);
	void save(const QString& symbol, const DataObject& obj, SaveMode option = SaveMode::Add);
	void save(const Instrument& instrument, const IDataSeries& series, SaveMode option = SaveMode::Add);

private:
	QSharedDataPointer<DataManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataManager& datamanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataManager& datamanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataManager)

#endif // __QUANTKIT_DATAMANAGER_H__
