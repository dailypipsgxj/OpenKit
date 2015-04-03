#include <QuantKit/CommissionProvider.h>

#include <QuantKit/Event/ExecutionReport.h>

namespace QuantKit {

class CommissionProviderPrivate : public QSharedData
{
public:
	CommissionType m_type;
	double m_commission;
	double m_minCommission;

public:
	CommissionProviderPrivate();
	virtual ~CommissionProviderPrivate();

public:
	double commission() const { return m_commission; }
	void setCommission(double value) { m_commission = value; }
	CommissionType type() const { return m_type; }
	void setType(CommissionType value) { m_type = value; }
	double minCommission() const { return m_minCommission; }
	void setMinCommission(double value) { m_minCommission = value; }
	virtual double getCommission(const ExecutionReport& report) Q_DECL_OVERRIDE;
	virtual CommissionProviderPrivate* clone() Q_DECL_OVERRIDE { return new CommissionProviderPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

CommissionProviderPrivate::CommissionProviderPrivate()
{
}

CommissionProviderPrivate::~CommissionProviderPrivate ()
{
}

double CommissionProviderPrivate::getCommission(const ExecutionReport& report)
{
	double num;
	switch (m_type)
	{
		case CommissionType.PerShare:
			num = m_commission * report.lastQty();
			break;
		case CommissionType.Percent:
			num = m_commission * report.lastQty() * report.lastPx();
			break;
		case CommissionType.Absolute:
			num = m_commission;
			break;
		default:
			throw new NotSupportedException("Unknown commission type " + m_type);
	}
	if (num < m_minCommission)
	{
		return m_minCommission;
	}
	return num;
}


// Pubic API 

CommissionProvider::CommissionProvider()
	: d_ptr(new CommissionProviderPrivate)
{
}

CommissionProvider::~CommissionProvider()
{
}

CommissionProvider::CommissionProvider (const CommissionProvider &other)
	: d_ptr(other.d_ptr)
{
}

CommissionProvider& CommissionProvider::operator=(const CommissionProvider &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool CommissionProvider::operator==(const CommissionProvider &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

double CommissionProvider::commission() const
{
	return d_ptr->commission();
}

void CommissionProvider::setCommission(double value)
{
	d_ptr->setCommission(value);
}

CommissionType CommissionProvider::type() const
{
	return d_ptr->type();
}

void CommissionProvider::setType(CommissionType value)
{
	d_ptr->setType(value);
}

double CommissionProvider::minCommission() const
{
	return d_ptr->minCommission();
}

void CommissionProvider::setMinCommission(double value)
{
	d_ptr->setMinCommission(value);
}

double CommissionProvider::getCommission(const ExecutionReport& report)
{
	return d_ptr->getCommission(report);
}

QDebug operator<<(QDebug dbg, const CommissionProvider& commissionprovider)
{
	return dbg << commissionprovider.toString();
}

