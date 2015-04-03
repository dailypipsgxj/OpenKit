#ifndef __QUANTKIT_DATASIMULATOR_H__
#define __QUANTKIT_DATASIMULATOR_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QList>
#include <Thread>

#include <QuantKit/Provider.h>
#include <QuantKit/IProvider.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IDataSimulator.h>
#include <QuantKit/IDataSeries.h>

namespace QuantKit {

class DataSimulatorPrivate;

class BarFilter;
class DataProcessor;
class Framework;
class Instrument;
class InstrumentList;
class LinkedList;

class QUANTKIT_EXPORT DataSimulator Q_DECL_FINAL : public Provider , public IProvider , public IDataProvider , public IDataSimulator
{
public:
	explicit DataSimulator(const Framework& framework);
	~DataSimulator();

public:
	QDateTime dateTime1() const;
	void setDateTime1(const QDateTime& value);
	QDateTime dateTime2() const;
	void setDateTime2(const QDateTime& value);
	bool subscribeBid() const;
	void setSubscribeBid(bool value);
	bool subscribeAsk() const;
	void setSubscribeAsk(bool value);
	bool subscribeQuote() const;
	void setSubscribeQuote(bool value);
	bool subscribeTrade() const;
	void setSubscribeTrade(bool value);
	bool subscribeBar() const;
	void setSubscribeBar(bool value);
	bool subscribeLevelII() const;
	void setSubscribeLevelII(bool value);
	bool subscribeNews() const;
	void setSubscribeNews(bool value);
	bool subscribeFundamental() const;
	void setSubscribeFundamental(bool value);
	void setSubscribeAll(bool value);
	BarFilter barFilter() const;
	QList<IDataSeries> series() const;
	void setSeries(const QList<IDataSeries>& value);
	DataProcessor processor() const;
	void setProcessor(const DataProcessor& value);
	void clear();

private:
	QK_DECLARE_PRIVATE(DataSimulator)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataSimulator)

#endif // __QUANTKIT_DATASIMULATOR_H__
