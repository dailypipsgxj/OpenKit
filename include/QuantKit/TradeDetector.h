#ifndef __QUANTKIT_TRADEDETECTOR_H__
#define __QUANTKIT_TRADEDETECTOR_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QDateTime>
#include <QSharedDataPointer>

#include <QuantKit/TradeDetectionType.h>

namespace QuantKit {

class TradeDetectorPrivate;

class Portfolio;
class TradeInfo;
class Fill;
class Instrument;
class TimeSeries;

class QUANTKIT_EXPORT TradeDetector
{
public:
	TradeDetector(TradeDetectionType type, const Portfolio& portfolio);
	~TradeDetector();

	TradeDetector(const TradeDetector &other);
	TradeDetector& operator=(const TradeDetector &other);
	bool operator==(const TradeDetector &other) const;
	inline bool operator!=(const TradeDetector &other) const { return !(this->operator==(other));  }
public:
	QList<TradeInfo> trades() const;
	bool hasPosition() const;
	QDateTime openDateTime() const;
	void add(const Fill& fill);
	void onEquity(double equity);

private:
	QSharedDataPointer<TradeDetectorPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const TradeDetector& tradedetector);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const TradeDetector& tradedetector);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TradeDetector)

#endif // __QUANTKIT_TRADEDETECTOR_H__
