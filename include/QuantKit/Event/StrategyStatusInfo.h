#ifndef __QUANTKIT_STRATEGYSTATUSINFO_H__
#define __QUANTKIT_STRATEGYSTATUSINFO_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/DataObject.h>
#include <QuantKit/StrategyStatusType.h>

namespace QuantKit {

class StrategyStatusInfoPrivate;

class QUANTKIT_EXPORT StrategyStatusInfo Q_DECL_FINAL : public DataObject
{
public:
	StrategyStatusInfo(const QDateTime& dateTime, StrategyStatusType type);
	~StrategyStatusInfo();

public:
	StrategyStatusType type() const;
	QString solution() const;
	void setSolution(const QString& value);
	QString mode() const;
	void setMode(const QString& value);

private:
	QK_DECLARE_PRIVATE(StrategyStatusInfo)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StrategyStatusInfo)

#endif // __QUANTKIT_STRATEGYSTATUSINFO_H__
