#ifndef __QUANTKIT_BARFACTORYITEM_H__
#define __QUANTKIT_BARFACTORYITEM_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/BarType.h>
#include <QuantKit/BarInput.h>
#include <QuantKit/ClockType.h>

namespace QuantKit {

class BarFactoryItemPrivate;

class Instrument;
class DataObject;
class BarFactory;
class Bar;

class QUANTKIT_EXPORT BarFactoryItem
{
public:
	BarFactoryItem(const Instrument& instrument, BarType barType, long barSize, BarInput barInput = BarInput::Trade);
	BarFactoryItem(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	~BarFactoryItem();

	BarFactoryItem(const BarFactoryItem &other);
	BarFactoryItem& operator=(const BarFactoryItem &other);
	bool operator==(const BarFactoryItem &other) const;
	inline bool operator!=(const BarFactoryItem &other) const { return !(this->operator==(other));  }
public:
	BarFactory factory() const;
	void setFactory(BarFactory value);
	Instrument instrument() const;

	long barSize() const;

	BarInput barInput() const;

	TimeSpan session1() const;

	TimeSpan session2() const;

	Bar bar() const;
	QString toString() const;

protected:
	BarFactoryItem(BarFactoryItemPrivate& dd);
	QSharedDataPointer<BarFactoryItemPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const BarFactoryItem& barfactoryitem);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BarFactoryItem& barfactoryitem);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarFactoryItem)

#endif // __QUANTKIT_BARFACTORYITEM_H__
