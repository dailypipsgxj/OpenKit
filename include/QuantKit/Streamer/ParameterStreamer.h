#ifndef __QUANTKIT_PARAMETERSTREAMER_H__
#define __QUANTKIT_PARAMETERSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ParameterStreamerPrivate;

class QUANTKIT_EXPORT ParameterStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ParameterStreamer();
	~ParameterStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ParameterStreamer)

#endif // __QUANTKIT_PARAMETERSTREAMER_H__
