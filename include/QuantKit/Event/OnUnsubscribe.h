#ifndef __QUANTKIT_ONUNSUBSCRIBE_H__
#define __QUANTKIT_ONUNSUBSCRIBE_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnUnsubscribePrivate;

class Instrument;
class InstrumentList;

class QUANTKIT_EXPORT OnUnsubscribe Q_DECL_FINAL : public Event
{
public:
	OnUnsubscribe();
	explicit OnUnsubscribe(const QString& symbol);
	explicit OnUnsubscribe(const InstrumentList& instruments);
	explicit OnUnsubscribe(const Instrument& instrument);
	~OnUnsubscribe();

public:
	QString symbol() const;
	Instrument instrument() const;

private:
	QK_DECLARE_PRIVATE(OnUnsubscribe)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnUnsubscribe)

#endif // __QUANTKIT_ONUNSUBSCRIBE_H__
