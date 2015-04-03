#ifndef __QUANTKIT_PRICER_H__
#define __QUANTKIT_PRICER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class PricerPrivate;

class Framework;
class Position;

class QUANTKIT_EXPORT Pricer
{
public:
	explicit Pricer(const Framework& framework);
	~Pricer();

	Pricer(const Pricer &other);
	Pricer& operator=(const Pricer &other);
	bool operator==(const Pricer &other) const;
	inline bool operator!=(const Pricer &other) const { return !(this->operator==(other));  }
public:
	double getPrice(const Position& position);
	double getValue(const Position& position);

private:
	QSharedDataPointer<PricerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Pricer& pricer);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Pricer& pricer);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Pricer)

#endif // __QUANTKIT_PRICER_H__
