#include <QuantKit/LongTradeCountReportItem.h>

#include "ReportItem_p.h"

namespace QuantKit {

class LongTradeCountReportItemPrivate : public ReportItemPrivate
{
public:
	LongTradeCountReportItemPrivate();
	virtual ~LongTradeCountReportItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

LongTradeCountReportItemPrivate::LongTradeCountReportItemPrivate()
{
}

LongTradeCountReportItemPrivate::~LongTradeCountReportItemPrivate ()
{
}


// Pubic API 

LongTradeCountReportItem::LongTradeCountReportItem()
	: ReportItem(*new LongTradeCountReportItemPrivate)
{
}

LongTradeCountReportItem::~LongTradeCountReportItem()
{
}


