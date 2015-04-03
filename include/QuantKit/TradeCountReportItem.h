#ifndef __QUANTKIT_TRADECOUNTREPORTITEM_H__
#define __QUANTKIT_TRADECOUNTREPORTITEM_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/ReportItem.h>

namespace QuantKit {

class TradeCountReportItemPrivate;

class ExecutionReport;

class QUANTKIT_EXPORT TradeCountReportItem Q_DECL_FINAL : public ReportItem
{
public:
	TradeCountReportItem();
	~TradeCountReportItem();


private:
	QK_DECLARE_PRIVATE(TradeCountReportItem)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TradeCountReportItem)

#endif // __QUANTKIT_TRADECOUNTREPORTITEM_H__
