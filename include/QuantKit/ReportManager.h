#ifndef __QUANTKIT_REPORTMANAGER_H__
#define __QUANTKIT_REPORTMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class ReportManagerPrivate;

class QUANTKIT_EXPORT ReportManager
{
public:
	ReportManager();
	~ReportManager();

	ReportManager(const ReportManager &other);
	ReportManager& operator=(const ReportManager &other);
	bool operator==(const ReportManager &other) const;
	inline bool operator!=(const ReportManager &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<ReportManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ReportManager& reportmanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ReportManager& reportmanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ReportManager)

#endif // __QUANTKIT_REPORTMANAGER_H__
