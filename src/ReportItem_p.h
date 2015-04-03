#ifndef __QUANTKIT_REPORTITEM_PRIVATE_H__
#define __QUANTKIT_REPORTITEM_PRIVATE_H__

#include <QuantKit/ReportItem.h>

#include <QSharedData>

#include "Bid_p.h"
#include "Ask_p.h"
#include "Trade_p.h"
#include "Bar_p.h"
#include "ExecutionReport_p.h"

namespace QuantKit {

class ReportItemPrivate : public QSharedData
{
public:
	int id;
	QString m_name;
	QString m_description;

public:
	ReportItemPrivate();
	virtual ~ReportItemPrivate();

public:
	QString name() const { return m_name; }
	QString description() const { return m_description; }
//protected
	virtual void clear() Q_DECL_OVERRIDE;
	virtual void onAsk(const Ask& Ask) Q_DECL_OVERRIDE;
	virtual void onBar(const Bar& bar) Q_DECL_OVERRIDE;
	virtual void onBid(const Bid& bid) Q_DECL_OVERRIDE;
	virtual void onExecutionReport(const ExecutionReport& report) Q_DECL_OVERRIDE;
	virtual void onTrade(const Trade& trade) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_REPORTITEM_PRIVATE_H__
