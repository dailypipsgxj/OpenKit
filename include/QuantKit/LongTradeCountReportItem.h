#ifndef __QUANTKIT_LONGTRADECOUNTREPORTITEM_H__
#define __QUANTKIT_LONGTRADECOUNTREPORTITEM_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/ReportItem.h>

namespace QuantKit {

class LongTradeCountReportItemPrivate;

class QUANTKIT_EXPORT LongTradeCountReportItem Q_DECL_FINAL : public ReportItem
{
public:
	LongTradeCountReportItem();
	~LongTradeCountReportItem();


private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::LongTradeCountReportItem)

#endif // __QUANTKIT_LONGTRADECOUNTREPORTITEM_H__
