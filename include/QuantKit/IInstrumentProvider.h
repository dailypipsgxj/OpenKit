#ifndef __QUANTKIT_IINSTRUMENTPROVIDER_H__
#define __QUANTKIT_IINSTRUMENTPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>

#include <QuantKit/IProvider.h>

namespace QuantKit {

class InstrumentDefinitionRequest;

class QUANTKIT_EXPORT IInstrumentProvider : public IProvider
{
public:
	virtual void cancel(const QString& requestId) = 0;
	virtual void send(const InstrumentDefinitionRequest& request) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IINSTRUMENTPROVIDER_H__
