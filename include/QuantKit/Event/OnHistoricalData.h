#ifndef __QUANTKIT_ONHISTORICALDATA_H__
#define __QUANTKIT_ONHISTORICALDATA_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnHistoricalDataPrivate;

class HistoricalData;

class QUANTKIT_EXPORT OnHistoricalData Q_DECL_FINAL : public Event
{
public:
	explicit OnHistoricalData(const HistoricalData& data);
	~OnHistoricalData();

public:

private:
	QK_DECLARE_PRIVATE(OnHistoricalData)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnHistoricalData)

#endif // __QUANTKIT_ONHISTORICALDATA_H__
