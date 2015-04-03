#ifndef __QUANTKIT_SOLUTIONSTATUSSTREAMER_H__
#define __QUANTKIT_SOLUTIONSTATUSSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class SolutionStatusStreamerPrivate;

class QUANTKIT_EXPORT SolutionStatusStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	SolutionStatusStreamer();
	~SolutionStatusStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SolutionStatusStreamer)

#endif // __QUANTKIT_SOLUTIONSTATUSSTREAMER_H__
