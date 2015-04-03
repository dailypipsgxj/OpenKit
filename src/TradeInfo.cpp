#include <QuantKit/TradeInfo.h>

#include <QuantKit/Instrument.h>

namespace QuantKit {

class TradeInfoPrivate : public QSharedData
{
public:
	Instrument m_instrument;
	QDateTime m_entryDate;
	QDateTime m_exitDate;
	double m_entryPrice;
	double m_exitPrice;
	double m_qty;
	double m_entryCost;
	double m_exitCost;
	bool m_isLong;
	double m_MAE;
	double m_MFE;
	double m_ETD;

public:
	TradeInfoPrivate();
	virtual ~TradeInfoPrivate();

public:
	Instrument instrument() const { return m_instrument; }
	void setInstrument(const Instrument& value) { m_instrument = value; }
	QDateTime entryDate() const { return m_entryDate; }
	void setEntryDate(const QDateTime& value) { m_entryDate = value; }
	QDateTime exitDate() const { return m_exitDate; }
	void setExitDate(const QDateTime& value) { m_exitDate = value; }
	double entryPrice() const { return m_entryPrice; }
	void setEntryPrice(double value) { m_entryPrice = value; }
	double exitPrice() const { return m_exitPrice; }
	void setExitPrice(double value) { m_exitPrice = value; }
	double qty() const { return m_qty; }
	void setQty(double value) { m_qty = value; }
	double entryCost() const { return m_entryCost; }
	void setEntryCost(double value) { m_entryCost = value; }
	double exitCost() const { return m_exitCost; }
	void setExitCost(double value) { m_exitCost = value; }
	bool isLong() const { return m_isLong; }
	void setIsLong(bool value) { m_isLong = value; }
	double MAE() const { return m_MAE; }
	void setMAE(double value) { m_MAE = value; }
	double MFE() const { return m_MFE; }
	void setMFE(double value) { m_MFE = value; }
	double ETD() const { return m_ETD; }
	void setETD(double value) { m_ETD = value; }
	bool isWinning() const { return pnL() > 0.0; }
	double pnL() const;
	double netPnL() const;
	long length() const
	{
		return (m_exitDate - m_entryDate).Ticks;
	}

	virtual TradeInfoPrivate* clone() Q_DECL_OVERRIDE { return new TradeInfoPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TradeInfoPrivate::TradeInfoPrivate()
{
}

TradeInfoPrivate::~TradeInfoPrivate ()
{
}

double TradeInfoPrivate::pnL() const
{
	double num = (m_instrument.factor() == 0.0) ? 1.0 : m_instrument.factor();
	double num2 = num * m_qty * (m_exitPrice - m_entryPrice) * (double)(m_isLong ? 1 : -1);
	return num2 - (m_entryCost + m_exitCost);
}

double TradeInfoPrivate::netPnL() const
{
	double num = (m_instrument.factor() == 0.0) ? 1.0 : m_instrument.factor();
	return num * m_qty * (m_exitPrice - m_entryPrice) * (double)(m_isLong ? 1 : -1);
}


// Pubic API 

TradeInfo::TradeInfo()
	: d_ptr(new TradeInfoPrivate)
{
}

TradeInfo::~TradeInfo()
{
}

TradeInfo::TradeInfo (const TradeInfo &other)
	: d_ptr(other.d_ptr)
{
}

TradeInfo& TradeInfo::operator=(const TradeInfo &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool TradeInfo::operator==(const TradeInfo &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Instrument TradeInfo::instrument() const
{
	return d_ptr->instrument();
}

void TradeInfo::setInstrument(const Instrument& value)
{
	d_ptr->setInstrument(value);
}

QDateTime TradeInfo::entryDate() const
{
	return d_ptr->entryDate();
}

void TradeInfo::setEntryDate(const QDateTime& value)
{
	d_ptr->setEntryDate(value);
}

QDateTime TradeInfo::exitDate() const
{
	return d_ptr->exitDate();
}

void TradeInfo::setExitDate(const QDateTime& value)
{
	d_ptr->setExitDate(value);
}

double TradeInfo::entryPrice() const
{
	return d_ptr->entryPrice();
}

void TradeInfo::setEntryPrice(double value)
{
	d_ptr->setEntryPrice(value);
}

double TradeInfo::exitPrice() const
{
	return d_ptr->exitPrice();
}

void TradeInfo::setExitPrice(double value)
{
	d_ptr->setExitPrice(value);
}

double TradeInfo::qty() const
{
	return d_ptr->qty();
}

void TradeInfo::setQty(double value)
{
	d_ptr->setQty(value);
}

double TradeInfo::entryCost() const
{
	return d_ptr->entryCost();
}

void TradeInfo::setEntryCost(double value)
{
	d_ptr->setEntryCost(value);
}

double TradeInfo::exitCost() const
{
	return d_ptr->exitCost();
}

void TradeInfo::setExitCost(double value)
{
	d_ptr->setExitCost(value);
}

bool TradeInfo::isLong() const
{
	return d_ptr->isLong();
}

void TradeInfo::setIsLong(bool value)
{
	d_ptr->setIsLong(value);
}

double TradeInfo::MAE() const
{
	return d_ptr->MAE();
}

void TradeInfo::setMAE(double value)
{
	d_ptr->setMAE(value);
}

double TradeInfo::MFE() const
{
	return d_ptr->MFE();
}

void TradeInfo::setMFE(double value)
{
	d_ptr->setMFE(value);
}

double TradeInfo::ETD() const
{
	return d_ptr->ETD();
}

void TradeInfo::setETD(double value)
{
	d_ptr->setETD(value);
}

bool TradeInfo::isWinning() const
{
	return d_ptr->isWinning();
}

double TradeInfo::pnL() const
{
	return d_ptr->pnL();
}

double TradeInfo::netPnL() const
{
	return d_ptr->netPnL();
}

long TradeInfo::length() const
{
	return d_ptr->length();
}

QDebug operator<<(QDebug dbg, const TradeInfo& tradeinfo)
{
	return dbg << tradeinfo.toString();
}

