#ifndef __QUANTKIT_DATETIMESTREAMER_H__
#define __QUANTKIT_DATETIMESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class DateTimeStreamerPrivate;

class QUANTKIT_EXPORT DateTimeStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	DateTimeStreamer();
	~DateTimeStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DateTimeStreamer)

#endif // __QUANTKIT_DATETIMESTREAMER_H__
