#ifndef __QUANTKIT_QUOTE_H__
#define __QUANTKIT_QUOTE_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class QuotePrivate;

class Bid;
class Ask;

class QUANTKIT_EXPORT Quote Q_DECL_FINAL : public DataObject
{
public:
	Quote(const Bid& bid, const Ask& ask);
	Quote(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double bidPrice, int bidSize, double askPrice, int askSize);
	~Quote();

public:
	Bid bid() const;
	Ask ask() const;

private:
	QK_DECLARE_PRIVATE(Quote)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Quote)

#endif // __QUANTKIT_QUOTE_H__
