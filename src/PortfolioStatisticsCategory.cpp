#include <QuantKit/PortfolioStatisticsCategory.h>


namespace QuantKit {

class PortfolioStatisticsCategoryPrivate : public QSharedData
{
public:
	QString Summary;
	QString Trades;
	QString DailyAnnual;
	QString UpsideDownside;

public:
	PortfolioStatisticsCategoryPrivate();
	virtual ~PortfolioStatisticsCategoryPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioStatisticsCategoryPrivate::PortfolioStatisticsCategoryPrivate()
{
}

PortfolioStatisticsCategoryPrivate::~PortfolioStatisticsCategoryPrivate ()
{
}


// Pubic API 

PortfolioStatisticsCategory::PortfolioStatisticsCategory()
	: d_ptr(new PortfolioStatisticsCategoryPrivate)
{
}

PortfolioStatisticsCategory::~PortfolioStatisticsCategory()
{
}

PortfolioStatisticsCategory::PortfolioStatisticsCategory (const PortfolioStatisticsCategory &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioStatisticsCategory& PortfolioStatisticsCategory::operator=(const PortfolioStatisticsCategory &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioStatisticsCategory::operator==(const PortfolioStatisticsCategory &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const PortfolioStatisticsCategory& portfoliostatisticscategory)
{
	return dbg << portfoliostatisticscategory.toString();
}

