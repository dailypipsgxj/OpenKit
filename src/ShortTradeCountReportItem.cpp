#include <QuantKit/ShortTradeCountReportItem.h>

#include "ReportItem_p.h"

namespace QuantKit {

class ShortTradeCountReportItemPrivate : public ReportItemPrivate
{
public:
	ShortTradeCountReportItemPrivate();
	virtual ~ShortTradeCountReportItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

ShortTradeCountReportItemPrivate::ShortTradeCountReportItemPrivate()
{
}

ShortTradeCountReportItemPrivate::~ShortTradeCountReportItemPrivate ()
{
}


// Pubic API 

ShortTradeCountReportItem::ShortTradeCountReportItem()
	: ReportItem(*new ShortTradeCountReportItemPrivate)
{
}

ShortTradeCountReportItem::~ShortTradeCountReportItem()
{
}


