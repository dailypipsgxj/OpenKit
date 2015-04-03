#ifndef __QUANTKIT_IDATAPROVIDER_H__
#define __QUANTKIT_IDATAPROVIDER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>

#include <QuantKit/IProvider.h>

namespace QuantKit {

class Instrument;
class InstrumentList;

class QUANTKIT_EXPORT IDataProvider : public IProvider
{
public:
	virtual void subscribe(const Instrument& instrument) = 0;
	virtual void subscribe(const InstrumentList& instrument) = 0;
	virtual void unsubscribe(const Instrument& instrument) = 0;
	virtual void unsubscribe(const InstrumentList& instrument) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IDATAPROVIDER_H__
