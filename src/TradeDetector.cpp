#include <QuantKit/TradeDetector.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/TradeInfo.h>
#include <QuantKit/Event/Fill.h>
#include <QuantKit/Instrument.h>
#include "TimeSeries_p.h"

namespace QuantKit {

class TradeDetectorPrivate : public QSharedData
{
public:
	Interface0 m_hasPosition;
	Instrument instrument_0;
	double double_0;
	QList<TradeInfo> m_trades;
	TimeSeries timeSeries_0;
	Portfolio portfolio_0;
	Delegate7 delegate7_0;

public:
	TradeDetectorPrivate(TradeDetectionType type, const Portfolio& portfolio);
	virtual ~TradeDetectorPrivate();

public:
	QList<TradeInfo> trades() const { return m_trades; }
	bool hasPosition() const
	{
		return m_hasPosition.Peek() != null;
	}

	QDateTime openDateTime() const;
	void add(const Fill& fill);
	void onEquity(double equity);
	virtual TradeDetectorPrivate* clone() Q_DECL_OVERRIDE { return new TradeDetectorPrivate(*this); }
//private:
	void method_0(const TradeInfo& tradeInfo);
	TradeInfo method_1(const Fill& fill_0, const Fill& fill_1, double double_1);
	bool method_2(const Fill& fill)
	{
		return fill.side() == OrderSide.Buy;
	}

	double method_3(const Instrument& instrument_1);
};

} // namepsace QuantKit


using namespace QuantKit;

TradeDetectorPrivate::TradeDetectorPrivate(TradeDetectionType type, const Portfolio& portfolio)
	: m_hasPosition(new Class67())
	, m_hasPosition(new Class68())
	, m_trades(new QList<TradeInfo>())
	, timeSeries_0(new TimeSeries())
	, portfolio_0(portfolio)
{
		if (type == TradeDetectionType.FIFO)
		{
		}
		else
		{
		}
}

TradeDetectorPrivate::~TradeDetectorPrivate ()
{
}

QDateTime TradeDetectorPrivate::openDateTime() const
{
	Fill fill = m_hasPosition.Peek();
	if (fill == null)
	{
		return DateTime.MinValue;
	}
	return fill.dateTime();
}

void TradeDetectorPrivate::add(const Fill& fill)
{
	Fill fill2 = m_hasPosition.Peek();
	if (fill2 == null)
	{
		instrument_0 = fill.instrument();
		timeSeries_0.Clear();
		timeSeries_0.Add(portfolio_0.clock().clock().dateTime(), method_3(instrument_0));
	}
	if (fill2 != null && (!method_2(fill2) || !method_2(fill)) && (method_2(fill2) || method_2(fill)))
	{
		double num = fill.qty();
		while (num > 0.0 && (fill2 = m_hasPosition.Peek()) != null)
		{
			if (double_0 > num)
			{
				method_0(method_1(fill2, fill, num));
				double_0 -= Math.Round(num, 5);
				num = 0.0;
			}
			else
			{
				method_0(method_1(fill2, fill, double_0));
				m_hasPosition.imethod_0();
				num -= Math.Round(double_0, 5);
			}
		}
		if (num > 0.0)
		{
			double_0 = num;
			m_hasPosition.mDaOrsvCob(fill);
		}
		return;
	}
	m_hasPosition.mDaOrsvCob(fill);
	double_0 = fill.qty();
}

void TradeDetectorPrivate::onEquity(double equity)
{
	if (m_hasPosition)
	{
		timeSeries_0.Add(portfolio_0.clock().clock().dateTime(), method_3(instrument_0));
	}
}

void TradeDetectorPrivate::method_0(const TradeInfo& tradeInfo)
{
	m_trades.Add(tradeInfo);
	if (delegate7_0 != null)
	{
		delegate7_0(portfolio_0, new EventArgs1(tradeInfo));
	}
}

TradeInfo TradeDetectorPrivate::method_1(const Fill& fill_0, const Fill& fill_1, double double_1)
{
	TradeInfo tradeInfo = new TradeInfo();
	tradeInfo.setInstrument() = fill_0.instrument();
	tradeInfo.setEntryDate() = fill_0.dateTime();
	tradeInfo.setEntryPrice() = fill_0.price();
	tradeInfo.setEntryCost() = fill_0.commission() * double_1 / fill_0.qty();
	tradeInfo.setExitDate() = fill_1.dateTime();
	tradeInfo.setExitPrice() = fill_1.price();
	tradeInfo.setExitCost() = fill_1.commission() * double_1 / fill_1.qty();
	tradeInfo.setQty() = double_1;
	tradeInfo.setIsLong() = method_2(fill_0);
	double max = timeSeries_0.GetMax(tradeInfo.entryDate(), tradeInfo.exitDate());
	double min = timeSeries_0.GetMin(tradeInfo.entryDate(), tradeInfo.exitDate());
	if (tradeInfo.isLong())
	{
		tradeInfo.setMAE() = tradeInfo.qty() * (min - tradeInfo.entryPrice()) * (double)(tradeInfo.isLong() ? 1 : -1) - (tradeInfo.entryCost() + tradeInfo.exitCost());
		tradeInfo.setMFE() = tradeInfo.qty() * (max - tradeInfo.entryPrice()) * (double)(tradeInfo.isLong() ? 1 : -1) - (tradeInfo.entryCost() + tradeInfo.exitCost());
		tradeInfo.setETD() = tradeInfo.MFE() - tradeInfo.pnL();
	}
	else
	{
		tradeInfo.setMAE() = tradeInfo.qty() * (max - tradeInfo.entryPrice()) * (double)(tradeInfo.isLong() ? 1 : -1) - (tradeInfo.entryCost() + tradeInfo.exitCost());
		tradeInfo.setMFE() = tradeInfo.qty() * (min - tradeInfo.entryPrice()) * (double)(tradeInfo.isLong() ? 1 : -1) - (tradeInfo.entryCost() + tradeInfo.exitCost());
		tradeInfo.setETD() = tradeInfo.MFE() - tradeInfo.pnL();
	}
	return tradeInfo;
}

double TradeDetectorPrivate::method_3(const Instrument& instrument_1)
{
	Trade trade = instrument_1.trade();
	if (trade != null)
	{
		return trade.price();
	}
	Bar bar = instrument_1.bar();
	if (bar != null)
	{
		return bar.close();
	}
	return 0.0;
}


// Pubic API 

TradeDetector::TradeDetector(TradeDetectionType type, const Portfolio& portfolio)
	: d_ptr(new TradeDetectorPrivate(type, portfolio))
{
}

TradeDetector::~TradeDetector()
{
}

TradeDetector::TradeDetector (const TradeDetector &other)
	: d_ptr(other.d_ptr)
{
}

TradeDetector& TradeDetector::operator=(const TradeDetector &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool TradeDetector::operator==(const TradeDetector &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QList<TradeInfo> TradeDetector::trades() const
{
	return d_ptr->trades();
}

bool TradeDetector::hasPosition() const
{
	return d_ptr->hasPosition();
}

QDateTime TradeDetector::openDateTime() const
{
	return d_ptr->openDateTime();
}

void TradeDetector::add(const Fill& fill)
{
	d_ptr->add(fill);
}

void TradeDetector::onEquity(double equity)
{
	d_ptr->onEquity(equity);
}

QDebug operator<<(QDebug dbg, const TradeDetector& tradedetector)
{
	return dbg << tradedetector.toString();
}

