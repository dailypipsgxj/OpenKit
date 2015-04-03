#ifndef __QUANTKIT_ONINSTRUMENTDEFINITION_H__
#define __QUANTKIT_ONINSTRUMENTDEFINITION_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnInstrumentDefinitionPrivate;

class InstrumentDefinition;

class QUANTKIT_EXPORT OnInstrumentDefinition Q_DECL_FINAL : public Event
{
public:
	explicit OnInstrumentDefinition(const InstrumentDefinition& definition);
	~OnInstrumentDefinition();

public:
	InstrumentDefinition instrumentDefinition() const;

private:
	QK_DECLARE_PRIVATE(OnInstrumentDefinition)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnInstrumentDefinition)

#endif // __QUANTKIT_ONINSTRUMENTDEFINITION_H__
