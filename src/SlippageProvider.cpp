#include <QuantKit/SlippageProvider.h>

#include <QuantKit/Event/ExecutionReport.h>

namespace QuantKit {

class SlippageProviderPrivate : public QSharedData
{
public:
	double m_slippage;

public:
	SlippageProviderPrivate();
	virtual ~SlippageProviderPrivate();

public:
	double slippage() const { return m_slippage; }
	void setSlippage(double value) { m_slippage = value; }
	virtual double getPrice(const ExecutionReport& report) Q_DECL_OVERRIDE;
	virtual SlippageProviderPrivate* clone() Q_DECL_OVERRIDE { return new SlippageProviderPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

SlippageProviderPrivate::SlippageProviderPrivate()
{
}

SlippageProviderPrivate::~SlippageProviderPrivate ()
{
}

double SlippageProviderPrivate::getPrice(const ExecutionReport& report)
{
	double num = report.lastPx();
	switch (report.side())
	{
		case OrderSide.Buy:
			num += num * m_slippage;
			break;
		case OrderSide.Sell:
			num -= num * m_slippage;
			break;
	}
	return num;
}


// Pubic API 

SlippageProvider::SlippageProvider()
	: d_ptr(new SlippageProviderPrivate)
{
}

SlippageProvider::~SlippageProvider()
{
}

SlippageProvider::SlippageProvider (const SlippageProvider &other)
	: d_ptr(other.d_ptr)
{
}

SlippageProvider& SlippageProvider::operator=(const SlippageProvider &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool SlippageProvider::operator==(const SlippageProvider &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

double SlippageProvider::slippage() const
{
	return d_ptr->slippage();
}

void SlippageProvider::setSlippage(double value)
{
	d_ptr->setSlippage(value);
}

double SlippageProvider::getPrice(const ExecutionReport& report)
{
	return d_ptr->getPrice(report);
}

QDebug operator<<(QDebug dbg, const SlippageProvider& slippageprovider)
{
	return dbg << slippageprovider.toString();
}

