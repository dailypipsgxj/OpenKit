#ifndef __QUANTKIT_PORTFOLIOSTREAMER_H__
#define __QUANTKIT_PORTFOLIOSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class PortfolioStreamerPrivate;

class QUANTKIT_EXPORT PortfolioStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	PortfolioStreamer();
	~PortfolioStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioStreamer)

#endif // __QUANTKIT_PORTFOLIOSTREAMER_H__
