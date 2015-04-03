#ifndef __QUANTKIT_SHORTTRADECOUNTREPORTITEM_H__
#define __QUANTKIT_SHORTTRADECOUNTREPORTITEM_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/ReportItem.h>

namespace QuantKit {

class ShortTradeCountReportItemPrivate;

class QUANTKIT_EXPORT ShortTradeCountReportItem Q_DECL_FINAL : public ReportItem
{
public:
	ShortTradeCountReportItem();
	~ShortTradeCountReportItem();


private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ShortTradeCountReportItem)

#endif // __QUANTKIT_SHORTTRADECOUNTREPORTITEM_H__
