#ifndef __QUANTKIT_SOLUTIONSTATUSINFO_H__
#define __QUANTKIT_SOLUTIONSTATUSINFO_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/DataObject.h>
#include <QuantKit/SolutionStatusType.h>

namespace QuantKit {

class SolutionStatusInfoPrivate;

class QUANTKIT_EXPORT SolutionStatusInfo Q_DECL_FINAL : public DataObject
{
public:
	SolutionStatusInfo(const QDateTime& dateTime, SolutionStatusType type);
	~SolutionStatusInfo();

public:
	SolutionStatusType type() const;
	QString solution() const;
	void setSolution(const QString& value);
	QString mode() const;
	void setMode(const QString& value);

private:
	QK_DECLARE_PRIVATE(SolutionStatusInfo)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SolutionStatusInfo)

#endif // __QUANTKIT_SOLUTIONSTATUSINFO_H__
