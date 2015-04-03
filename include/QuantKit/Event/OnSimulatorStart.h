#ifndef __QUANTKIT_ONSIMULATORSTART_H__
#define __QUANTKIT_ONSIMULATORSTART_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class OnSimulatorStartPrivate;

class QUANTKIT_EXPORT OnSimulatorStart Q_DECL_FINAL : public DataObject
{
public:
	OnSimulatorStart();
	OnSimulatorStart(const QDateTime& dateTime1, const QDateTime& dateTime2, long count = 0);
	~OnSimulatorStart();

public:
	QDateTime ymlVcTtugA() const;

private:
	QK_DECLARE_PRIVATE(OnSimulatorStart)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnSimulatorStart)

#endif // __QUANTKIT_ONSIMULATORSTART_H__
