#ifndef __QUANTKIT_REPORT_H__
#define __QUANTKIT_REPORT_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class ReportPrivate;

class ReportItem;

class QUANTKIT_EXPORT Report
{
public:
	Report();
	~Report();

	Report(const Report &other);
	Report& operator=(const Report &other);
	bool operator==(const Report &other) const;
	inline bool operator!=(const Report &other) const { return !(this->operator==(other));  }
public:
	void add(const ReportItem& item);
	void clear();

private:
	QSharedDataPointer<ReportPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Report& report);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Report& report);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Report)

#endif // __QUANTKIT_REPORT_H__
