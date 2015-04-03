#ifndef __QUANTKIT_HISTORICALDATA_H__
#define __QUANTKIT_HISTORICALDATA_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class HistoricalDataPrivate;

class DataObject;

class QUANTKIT_EXPORT HistoricalData Q_DECL_FINAL : public Event
{
public:
	HistoricalData();
	~HistoricalData();

public:
	QString requestId() const;
	void setRequestId(const QString& value);
	int totalNum() const;
	void setTotalNum(int value);
	DataObject objects() const;
	void setObjects(const DataObject& value);

private:
	QK_DECLARE_PRIVATE(HistoricalData)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::HistoricalData)

#endif // __QUANTKIT_HISTORICALDATA_H__
