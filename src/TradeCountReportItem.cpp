#include <QuantKit/TradeCountReportItem.h>

#include <QuantKit/Event/ExecutionReport.h>
#include "ReportItem_p.h"

namespace QuantKit {

class TradeCountReportItemPrivate : public ReportItemPrivate
{
public:
	int int_0;

public:
	TradeCountReportItemPrivate();
	virtual ~TradeCountReportItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

TradeCountReportItemPrivate::TradeCountReportItemPrivate()
{
		m_name = "Trade count";
		m_description = "Number of all trades (long + short)";
}

TradeCountReportItemPrivate::~TradeCountReportItemPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(TradeCountReportItem)

TradeCountReportItem::TradeCountReportItem()
	: ReportItem(*new TradeCountReportItemPrivate)
{
}

TradeCountReportItem::~TradeCountReportItem()
{
}


