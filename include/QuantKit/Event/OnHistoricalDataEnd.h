#ifndef __QUANTKIT_ONHISTORICALDATAEND_H__
#define __QUANTKIT_ONHISTORICALDATAEND_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnHistoricalDataEndPrivate;

class HistoricalDataEnd;

class QUANTKIT_EXPORT OnHistoricalDataEnd Q_DECL_FINAL : public Event
{
public:
	explicit OnHistoricalDataEnd(const HistoricalDataEnd& end);
	~OnHistoricalDataEnd();

public:

private:
	QK_DECLARE_PRIVATE(OnHistoricalDataEnd)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnHistoricalDataEnd)

#endif // __QUANTKIT_ONHISTORICALDATAEND_H__
