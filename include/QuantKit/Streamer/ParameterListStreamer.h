#ifndef __QUANTKIT_PARAMETERLISTSTREAMER_H__
#define __QUANTKIT_PARAMETERLISTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ParameterListStreamerPrivate;

class QUANTKIT_EXPORT ParameterListStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ParameterListStreamer();
	~ParameterListStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ParameterListStreamer)

#endif // __QUANTKIT_PARAMETERLISTSTREAMER_H__
