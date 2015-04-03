#ifndef __QUANTKIT_LEG_H__
#define __QUANTKIT_LEG_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class LegPrivate;

class Framework;
class Instrument;

class QUANTKIT_EXPORT Leg
{
public:
	Leg();
	explicit Leg(const Framework& framework);
	Leg(const Instrument& instrument, double weight = 1);
	~Leg();

	Leg(const Leg &other);
	Leg& operator=(const Leg &other);
	bool operator==(const Leg &other) const;
	inline bool operator!=(const Leg &other) const { return !(this->operator==(other));  }
public:
	Instrument instrument() const;
	void setInstrument(const Instrument& value);
	QString symbol() const;
	void setSymbol(const QString& value);
	double weight() const;
	void setWeight(double value);

private:
	QSharedDataPointer<LegPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Leg& leg);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Leg& leg);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Leg)

#endif // __QUANTKIT_LEG_H__
