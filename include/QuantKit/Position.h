#ifndef __QUANTKIT_POSITION_H__
#define __QUANTKIT_POSITION_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QDateTime>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/PositionSide.h>

namespace QuantKit {

class PositionPrivate;

class Portfolio;
class Instrument;
class Fill;

class QUANTKIT_EXPORT Position
{
public:
	Position();
	Position(const Portfolio& portfolio, const Instrument& instrument);
	~Position();

	Position(const Position &other);
	Position& operator=(const Position &other);
	bool operator==(const Position &other) const;
	inline bool operator!=(const Position &other) const { return !(this->operator==(other));  }
public:
	Portfolio portfolio() const;
	Instrument instrument() const;
	int portfolioId() const;
	int instrumentId() const;
	QList<Fill> fills() const;
	double amount() const;
	double qty() const;
	double qtyBought() const;
	double qtySold() const;
	PositionSide side() const;
	double price() const;
	double value() const;
	double entryPrice() const;
	QDateTime entryDate() const;
	double entryQty() const;
	void add(const Fill& fill);
	QString getSideAsString();
	QString toString() const;

private:
	QSharedDataPointer<PositionPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Position& position);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Position& position);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Position)

#endif // __QUANTKIT_POSITION_H__
