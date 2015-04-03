#ifndef __QUANTKIT_STRINGSTREAMER_H__
#define __QUANTKIT_STRINGSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class StringStreamerPrivate;

class QUANTKIT_EXPORT StringStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	StringStreamer();
	~StringStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StringStreamer)

#endif // __QUANTKIT_STRINGSTREAMER_H__
