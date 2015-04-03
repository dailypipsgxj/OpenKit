#ifndef __QUANTKIT_TEXTINFOSTREAMER_H__
#define __QUANTKIT_TEXTINFOSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class TextInfoStreamerPrivate;

class QUANTKIT_EXPORT TextInfoStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	TextInfoStreamer();
	~TextInfoStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TextInfoStreamer)

#endif // __QUANTKIT_TEXTINFOSTREAMER_H__
