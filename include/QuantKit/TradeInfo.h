#ifndef __QUANTKIT_TRADEINFO_H__
#define __QUANTKIT_TRADEINFO_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QSharedDataPointer>

namespace QuantKit {

class TradeInfoPrivate;

class Instrument;

class QUANTKIT_EXPORT TradeInfo
{
public:
	TradeInfo();
	~TradeInfo();

	TradeInfo(const TradeInfo &other);
	TradeInfo& operator=(const TradeInfo &other);
	bool operator==(const TradeInfo &other) const;
	inline bool operator!=(const TradeInfo &other) const { return !(this->operator==(other));  }
public:
	Instrument instrument() const;
	void setInstrument(const Instrument& value);
	QDateTime entryDate() const;
	void setEntryDate(const QDateTime& value);
	QDateTime exitDate() const;
	void setExitDate(const QDateTime& value);
	double entryPrice() const;
	void setEntryPrice(double value);
	double exitPrice() const;
	void setExitPrice(double value);
	double qty() const;
	void setQty(double value);
	double entryCost() const;
	void setEntryCost(double value);
	double exitCost() const;
	void setExitCost(double value);
	bool isLong() const;
	void setIsLong(bool value);
	double MAE() const;
	void setMAE(double value);
	double MFE() const;
	void setMFE(double value);
	double ETD() const;
	void setETD(double value);
	bool isWinning() const;
	double pnL() const;
	double netPnL() const;
	long length() const;

private:
	QSharedDataPointer<TradeInfoPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const TradeInfo& tradeinfo);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const TradeInfo& tradeinfo);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TradeInfo)

#endif // __QUANTKIT_TRADEINFO_H__
