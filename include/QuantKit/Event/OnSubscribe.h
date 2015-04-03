#ifndef __QUANTKIT_ONSUBSCRIBE_H__
#define __QUANTKIT_ONSUBSCRIBE_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnSubscribePrivate;

class Instrument;
class InstrumentList;

class QUANTKIT_EXPORT OnSubscribe Q_DECL_FINAL : public Event
{
public:
	OnSubscribe();
	explicit OnSubscribe(const QString& symbol);
	explicit OnSubscribe(const InstrumentList& instruments);
	explicit OnSubscribe(const Instrument& instrument);
	OnSubscribe(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	~OnSubscribe();

public:
	QString symbol() const;
	Instrument instrument() const;

private:
	QK_DECLARE_PRIVATE(OnSubscribe)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnSubscribe)

#endif // __QUANTKIT_ONSUBSCRIBE_H__
