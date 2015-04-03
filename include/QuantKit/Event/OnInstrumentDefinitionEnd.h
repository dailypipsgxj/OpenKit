#ifndef __QUANTKIT_ONINSTRUMENTDEFINITIONEND_H__
#define __QUANTKIT_ONINSTRUMENTDEFINITIONEND_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnInstrumentDefinitionEndPrivate;

class InstrumentDefinitionEnd;

class QUANTKIT_EXPORT OnInstrumentDefinitionEnd Q_DECL_FINAL : public Event
{
public:
	explicit OnInstrumentDefinitionEnd(const InstrumentDefinitionEnd& end);
	~OnInstrumentDefinitionEnd();

public:
	InstrumentDefinitionEnd instrumentDefinitionEnd() const;

private:
	QK_DECLARE_PRIVATE(OnInstrumentDefinitionEnd)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnInstrumentDefinitionEnd)

#endif // __QUANTKIT_ONINSTRUMENTDEFINITIONEND_H__
