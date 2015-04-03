#ifndef __QUANTKIT_STOP_H__
#define __QUANTKIT_STOP_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>

#include <QuantKit/StopType.h>
#include <QuantKit/StopMode.h>
#include <QuantKit/StopStatus.h>
#include <QuantKit/PositionSide.h>
#include <QuantKit/BarType.h>
#include <QuantKit/StopFillMode.h>

namespace QuantKit {

class StopPrivate;

class Strategy;
class Position;
class Instrument;
class ObjectTable;
class Bar;
class Trade;
class Bid;
class Ask;

class QUANTKIT_EXPORT Stop
{
public:
	Stop(const Strategy& strategy, const Position& position, const QDateTime& time);
	Stop(const Strategy& strategy, const Position& position, double level, StopType type, StopMode mode);
	~Stop();

	Stop(const Stop &other);
	Stop& operator=(const Stop &other);
	bool operator==(const Stop &other) const;
	inline bool operator!=(const Stop &other) const { return !(this->operator==(other));  }
public:
	Strategy strategy() const;
	Position position() const;
	Instrument instrument() const;
	bool connected() const;
	StopType type() const;
	StopMode mode() const;
	StopStatus status() const;
	double level() const;
	double qty() const;
	PositionSide side() const;
	QDateTime creationTime() const;
	QDateTime completionTime() const;
	bool traceOnQuote() const;
	void setTraceOnQuote(bool value);
	bool traceOnTrade() const;
	void setTraceOnTrade(bool value);
	bool traceOnBar() const;
	void setTraceOnBar(bool value);
	bool traceOnBarOpen() const;
	void setTraceOnBarOpen(bool value);
	bool trailOnOpen() const;
	void setTrailOnOpen(bool value);
	bool trailOnHighLow() const;
	void setTrailOnHighLow(bool value);
	long filterBarSize() const;
	void setFilterBarSize(long value);
	BarType filterBarType() const;
	void setFilterBarType(BarType value);
	StopFillMode fillMode() const;
	void setFillMode(StopFillMode value);
	ObjectTable fields() const;
	void cancel();
	void disconnect();

private:
	QSharedDataPointer<StopPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Stop& stop);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Stop& stop);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Stop)

#endif // __QUANTKIT_STOP_H__
