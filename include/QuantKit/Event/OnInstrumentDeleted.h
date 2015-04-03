#ifndef __QUANTKIT_ONINSTRUMENTDELETED_H__
#define __QUANTKIT_ONINSTRUMENTDELETED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnInstrumentDeletedPrivate;

class Instrument;

class QUANTKIT_EXPORT OnInstrumentDeleted Q_DECL_FINAL : public Event
{
public:
	explicit OnInstrumentDeleted(const Instrument& instrument);
	~OnInstrumentDeleted();

public:
	Instrument instrument() const;

private:
	QK_DECLARE_PRIVATE(OnInstrumentDeleted)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnInstrumentDeleted)

#endif // __QUANTKIT_ONINSTRUMENTDELETED_H__
