#ifndef __QUANTKIT_ONSIMULATORSTOP_H__
#define __QUANTKIT_ONSIMULATORSTOP_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class OnSimulatorStopPrivate;

class QUANTKIT_EXPORT OnSimulatorStop Q_DECL_FINAL : public DataObject
{
public:
	OnSimulatorStop();
	~OnSimulatorStop();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnSimulatorStop)

#endif // __QUANTKIT_ONSIMULATORSTOP_H__
