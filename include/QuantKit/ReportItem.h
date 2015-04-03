#ifndef __QUANTKIT_REPORTITEM_H__
#define __QUANTKIT_REPORTITEM_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class ReportItemPrivate;

class Bid;
class Ask;
class Trade;
class Bar;
class ExecutionReport;

class QUANTKIT_EXPORT ReportItem
{
public:
	ReportItem();
	~ReportItem();

	ReportItem(const ReportItem &other);
	ReportItem& operator=(const ReportItem &other);
	bool operator==(const ReportItem &other) const;
	inline bool operator!=(const ReportItem &other) const { return !(this->operator==(other));  }
public:
	QString name() const;
	QString description() const;

protected:
	ReportItem(ReportItemPrivate& dd);
	QSharedDataPointer<ReportItemPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const ReportItem& reportitem);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ReportItem& reportitem);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ReportItem)

#endif // __QUANTKIT_REPORTITEM_H__
