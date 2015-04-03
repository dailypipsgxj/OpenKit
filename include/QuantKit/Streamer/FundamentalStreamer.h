#ifndef __QUANTKIT_FUNDAMENTALSTREAMER_H__
#define __QUANTKIT_FUNDAMENTALSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class FundamentalStreamerPrivate;

class QUANTKIT_EXPORT FundamentalStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	FundamentalStreamer();
	~FundamentalStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FundamentalStreamer)

#endif // __QUANTKIT_FUNDAMENTALSTREAMER_H__
