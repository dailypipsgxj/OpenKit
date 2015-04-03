#ifndef __QUANTKIT_HISTORICALDATAEND_H__
#define __QUANTKIT_HISTORICALDATAEND_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>
#include <QuantKit/RequestResult.h>

namespace QuantKit {

class HistoricalDataEndPrivate;

class QUANTKIT_EXPORT HistoricalDataEnd Q_DECL_FINAL : public Event
{
public:
	HistoricalDataEnd();
	~HistoricalDataEnd();

public:
	QString requestId() const;
	void setRequestId(const QString& value);
	RequestResult result() const;
	void setResult(RequestResult value);
	QString text() const;
	void setText(const QString& value);

private:
	QK_DECLARE_PRIVATE(HistoricalDataEnd)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::HistoricalDataEnd)

#endif // __QUANTKIT_HISTORICALDATAEND_H__
