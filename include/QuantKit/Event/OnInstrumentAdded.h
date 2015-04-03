#ifndef __QUANTKIT_ONINSTRUMENTADDED_H__
#define __QUANTKIT_ONINSTRUMENTADDED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnInstrumentAddedPrivate;

class Instrument;

class QUANTKIT_EXPORT OnInstrumentAdded Q_DECL_FINAL : public Event
{
public:
	explicit OnInstrumentAdded(const Instrument& instrument);
	~OnInstrumentAdded();

public:
	Instrument instrument() const;

private:
	QK_DECLARE_PRIVATE(OnInstrumentAdded)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnInstrumentAdded)

#endif // __QUANTKIT_ONINSTRUMENTADDED_H__
