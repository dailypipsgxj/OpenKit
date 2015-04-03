#ifndef __QUANTKIT_INDICATOR_H__
#define __QUANTKIT_INDICATOR_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/TimeSeries.h>
#include <QuantKit/ISeries.h>
#include <QuantKit/BarData.h>
#include <QuantKit/IndexOption.h>

namespace QuantKit {

class IndicatorPrivate;

class QUANTKIT_EXPORT Indicator : public TimeSeries
{
public:
	explicit Indicator(const ISeries& input);
	~Indicator();

public:
	bool calculate() const;
	void setCalculate(bool value);
	ISeries input() const;
	bool autoUpdate() const;
	void setAutoUpdate(bool value);
	void attach();
	void detach();

protected:
	Indicator(IndicatorPrivate& dd);

private:
	QK_DECLARE_PRIVATE(Indicator)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Indicator)

#endif // __QUANTKIT_INDICATOR_H__
