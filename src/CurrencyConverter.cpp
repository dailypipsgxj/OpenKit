#include <QuantKit/CurrencyConverter.h>

#include <QuantKit/Framework.h>
#include <QuantKit/DataManager.h>

namespace QuantKit {

class CurrencyConverterPrivate : public QSharedData
{
public:
	Framework m_dataManager;

public:
	explicit CurrencyConverterPrivate(const Framework& framework);
	virtual ~CurrencyConverterPrivate();

public:
	Framework framework() const { return m_dataManager; }
	DataManager dataManager() const
	{
		return m_dataManager.dataManager();
	}

	virtual double convert(double amount, unsigned char fromCurrencyId, unsigned char toCurrencyId) Q_DECL_OVERRIDE { return amount; }
	virtual CurrencyConverterPrivate* clone() Q_DECL_OVERRIDE { return new CurrencyConverterPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

CurrencyConverterPrivate::CurrencyConverterPrivate(const Framework& framework)
	: m_dataManager(framework)
{
}

CurrencyConverterPrivate::~CurrencyConverterPrivate ()
{
}


// Pubic API 

CurrencyConverter::CurrencyConverter(const Framework& framework)
	: d_ptr(new CurrencyConverterPrivate(framework))
{
}

CurrencyConverter::~CurrencyConverter()
{
}

CurrencyConverter::CurrencyConverter (const CurrencyConverter &other)
	: d_ptr(other.d_ptr)
{
}

CurrencyConverter& CurrencyConverter::operator=(const CurrencyConverter &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool CurrencyConverter::operator==(const CurrencyConverter &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Framework CurrencyConverter::framework() const
{
	return d_ptr->framework();
}

DataManager CurrencyConverter::dataManager() const
{
	return d_ptr->dataManager();
}

double CurrencyConverter::convert(double amount, unsigned char fromCurrencyId, unsigned char toCurrencyId)
{
	return d_ptr->convert(amount, fromCurrencyId, toCurrencyId);
}

QDebug operator<<(QDebug dbg, const CurrencyConverter& currencyconverter)
{
	return dbg << currencyconverter.toString();
}

