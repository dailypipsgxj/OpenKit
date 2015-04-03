#include <QuantKit/Streamer/PortfolioStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class PortfolioStreamerPrivate : public ObjectStreamerPrivate
{
public:
	PortfolioStreamerPrivate();
	virtual ~PortfolioStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE
	{
		return new Portfolio(null, reader.ReadString());
	}

	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual PortfolioStreamerPrivate* clone() Q_DECL_OVERRIDE { return new PortfolioStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioStreamerPrivate::PortfolioStreamerPrivate()
{
		m_typeId = 26;
		m_type = typeof(Portfolio);
}

PortfolioStreamerPrivate::~PortfolioStreamerPrivate ()
{
}

void PortfolioStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Portfolio portfolio = (Portfolio)obj;
	writer.Write(portfolio.name());
}


// Pubic API 

PortfolioStreamer::PortfolioStreamer()
	: ObjectStreamer(*new PortfolioStreamerPrivate)
{
}

PortfolioStreamer::~PortfolioStreamer()
{
}


