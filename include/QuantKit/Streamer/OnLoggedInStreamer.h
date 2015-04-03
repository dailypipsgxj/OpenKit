#ifndef __QUANTKIT_ONLOGGEDINSTREAMER_H__
#define __QUANTKIT_ONLOGGEDINSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class OnLoggedInStreamerPrivate;

class QUANTKIT_EXPORT OnLoggedInStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	OnLoggedInStreamer();
	~OnLoggedInStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnLoggedInStreamer)

#endif // __QUANTKIT_ONLOGGEDINSTREAMER_H__
