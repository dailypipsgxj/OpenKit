#ifndef __QUANTKIT_IHISTORICALDATAPROVIDER_H__
#define __QUANTKIT_IHISTORICALDATAPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>

#include <QuantKit/IProvider.h>

namespace QuantKit {

class HistoricalDataRequest;

class QUANTKIT_EXPORT IHistoricalDataProvider : public IProvider
{
public:
	virtual void cancel(const QString& requestId) = 0;
	virtual void send(const HistoricalDataRequest& request) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IHISTORICALDATAPROVIDER_H__
