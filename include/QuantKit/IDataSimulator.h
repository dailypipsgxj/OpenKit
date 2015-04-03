#ifndef __QUANTKIT_IDATASIMULATOR_H__
#define __QUANTKIT_IDATASIMULATOR_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QList>

#include <QuantKit/IProvider.h>
#include <QuantKit/IDataProvider.h>
#include <QuantKit/IDataSeries.h>

namespace QuantKit {

class BarFilter;
class DataProcessor;

class QUANTKIT_EXPORT IDataSimulator : public IProvider , public IDataProvider
{
public:
	virtual QDateTime dateTime1() const = 0;
	virtual void setDateTime1(const QDateTime& value) = 0;
	virtual QDateTime dateTime2() const = 0;
	virtual void setDateTime2(const QDateTime& value) = 0;
	virtual bool subscribeBid() const = 0;
	virtual void setSubscribeBid(bool value) = 0;
	virtual bool subscribeAsk() const = 0;
	virtual void setSubscribeAsk(bool value) = 0;
	virtual bool subscribeTrade() const = 0;
	virtual void setSubscribeTrade(bool value) = 0;
	virtual bool subscribeBar() const = 0;
	virtual void setSubscribeBar(bool value) = 0;
	virtual bool subscribeLevelII() const = 0;
	virtual void setSubscribeLevelII(bool value) = 0;
	virtual bool subscribeNews() const = 0;
	virtual void setSubscribeNews(bool value) = 0;
	virtual bool subscribeFundamental() const = 0;
	virtual void setSubscribeFundamental(bool value) = 0;
	virtual void setSubscribeAll(bool value) = 0;
	virtual BarFilter barFilter() const = 0;
	virtual DataProcessor processor() const = 0;
	virtual void setProcessor(const DataProcessor& value) = 0;
	virtual QList<IDataSeries> series() const = 0;
	virtual void setSeries(const QList<IDataSeries>& value) = 0;
	virtual void clear() = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IDATASIMULATOR_H__
