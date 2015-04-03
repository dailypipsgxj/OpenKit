#ifndef __QUANTKIT_PORTFOLIOSTATISTICSITEM_PRIVATE_H__
#define __QUANTKIT_PORTFOLIOSTATISTICSITEM_PRIVATE_H__

#include <QuantKit/PortfolioStatisticsItem.h>

#include <QSharedData>

#include "TimeSeries_p.h"
#include "Clock_p.h"
#include "Fill_p.h"
#include "Transaction_p.h"
#include "Position_p.h"
#include "TradeInfo_p.h"
#include "Portfolio_p.h"
#include "PortfolioStatistics_p.h"

namespace QuantKit {

class PortfolioStatisticsItemPrivate : public QSharedData
{
public:
	double m_totalValue;
	double m_longValue;
	double m_shortValue;
	TimeSeries m_totalValues;
	TimeSeries m_longValues;
	TimeSeries m_shortValues;
	Portfolio m_clock;
	PortfolioStatistics statistics;

public:
	PortfolioStatisticsItemPrivate();
	virtual ~PortfolioStatisticsItemPrivate();

public:
	PortfolioStatistics getStatistics() const;
	void setStatistics(PortfolioStatistics value);
	virtual int type() const Q_DECL_OVERRIDE { return 0; }
	virtual QString name() const Q_DECL_OVERRIDE { return "Unknown"; }
	virtual QString format() const Q_DECL_OVERRIDE { return "F2"; }
	virtual QString description() const Q_DECL_OVERRIDE { return "Unknown"; }
	virtual QString category() const Q_DECL_OVERRIDE { return "Unknown"; }
	virtual bool show() const Q_DECL_OVERRIDE { return true; }
	double totalValue() const { return m_totalValue; }
	double longValue() const { return m_longValue; }
	double shortValue() const { return m_shortValue; }
	TimeSeries totalValues() const { return m_totalValues; }
	TimeSeries longValues() const { return m_longValues; }
	TimeSeries shortValues() const { return m_shortValues; }
	Clock clock() const
	{
		return m_clock.clock().clock();
	}

	void subscribe(int itemType)
	{
		statistics.method_0(this, itemType);
	}

	void unsubscribe(int itemType)
	{
		statistics.method_1(this, itemType);
	}

//protected
	void emit();
	virtual void onClear() Q_DECL_OVERRIDE;
	virtual void onEquity(double equity) Q_DECL_OVERRIDE;
	virtual void onFill(const Fill& fill) Q_DECL_OVERRIDE;
	virtual void onInit() Q_DECL_OVERRIDE;
	virtual void onPositionChanged(const Position& position) Q_DECL_OVERRIDE;
	virtual void onPositionClosed(const Position& position) Q_DECL_OVERRIDE;
	virtual void onPositionOpened(const Position& position) Q_DECL_OVERRIDE;
	virtual void onRoundTrip(const TradeInfo& trade) Q_DECL_OVERRIDE;
	virtual void onStatistics(const PortfolioStatisticsItem& statistics) Q_DECL_OVERRIDE;
	virtual void onStatistics(const Portfolio& portfolio, const PortfolioStatisticsItem& statistics) Q_DECL_OVERRIDE;
	virtual void onTransaction(const Transaction& transaction) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_PORTFOLIOSTATISTICSITEM_PRIVATE_H__
