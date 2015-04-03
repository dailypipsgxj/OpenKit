#include <QuantKit/FundamentalData.h>


namespace QuantKit {

class FundamentalDataPrivate : public QSharedData
{
public:
	unsigned char CashFlow;
	unsigned char PE;
	unsigned char Beta;
	unsigned char ProfitMargin;
	unsigned char ReturnOnEquity;
	unsigned char PriceBook;
	unsigned char DebtEquity;
	unsigned char InterestCoverage;
	unsigned char BookValue;
	unsigned char PriceSales;
	unsigned char DividendPayout;

public:
	FundamentalDataPrivate();
	virtual ~FundamentalDataPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

FundamentalDataPrivate::FundamentalDataPrivate()
{
}

FundamentalDataPrivate::~FundamentalDataPrivate ()
{
}


// Pubic API 

FundamentalData::FundamentalData()
	: d_ptr(new FundamentalDataPrivate)
{
}

FundamentalData::~FundamentalData()
{
}

FundamentalData::FundamentalData (const FundamentalData &other)
	: d_ptr(other.d_ptr)
{
}

FundamentalData& FundamentalData::operator=(const FundamentalData &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool FundamentalData::operator==(const FundamentalData &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const FundamentalData& fundamentaldata)
{
	return dbg << fundamentaldata.toString();
}

