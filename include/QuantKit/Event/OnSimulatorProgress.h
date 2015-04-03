#ifndef __QUANTKIT_ONSIMULATORPROGRESS_H__
#define __QUANTKIT_ONSIMULATORPROGRESS_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class OnSimulatorProgressPrivate;

class QUANTKIT_EXPORT OnSimulatorProgress Q_DECL_FINAL : public DataObject
{
public:
	OnSimulatorProgress();
	OnSimulatorProgress(long count, int percent);
	~OnSimulatorProgress();

public:
	long long_0() const;

	int int_0() const;

private:
	QK_DECLARE_PRIVATE(OnSimulatorProgress)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnSimulatorProgress)

#endif // __QUANTKIT_ONSIMULATORPROGRESS_H__
