#ifndef __QUANTKIT_BARFACTORY_H__
#define __QUANTKIT_BARFACTORY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QVariant>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/BarType.h>
#include <QuantKit/BarInput.h>
#include <QuantKit/ClockType.h>

namespace QuantKit {

class BarFactoryPrivate;

class Framework;
class BarFactoryItem;
class Instrument;
class InstrumentList;
class DataObject;
class IdArray;

class QUANTKIT_EXPORT BarFactory
{
public:
	explicit BarFactory(const Framework& framework);
	~BarFactory();

	BarFactory(const BarFactory &other);
	BarFactory& operator=(const BarFactory &other);
	bool operator==(const BarFactory &other) const;
	inline bool operator!=(const BarFactory &other) const { return !(this->operator==(other));  }
public:
	Framework framework() const;
	void add(const BarFactoryItem& item);
	void add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput = BarInput::Trade, ClockType type = ClockType::Local);
	void add(const Instrument& instrument, BarType barType, long barSize, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	void add(const QString& symbol, BarType barType, long barSize, BarInput barInput = BarInput::Trade, ClockType type = ClockType::Local);
	void add(const InstrumentList& instruments, BarType barType, long barSize, BarInput barInput = BarInput::Trade, ClockType type = ClockType::Local);
	void add(const QString& symbols, BarType barType, long barSize, BarInput barInput = BarInput::Trade, ClockType type = ClockType::Local);
	void add(const Instrument& instrument, BarType barType, long barSize, const TimeSpan& session1, const TimeSpan& session2);
	void add(const QString& symbol, BarType barType, long barSize, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	void add(const QString& symbol, BarType barType, long barSize, const TimeSpan& session1, const TimeSpan& session2);
	void add(const Instrument& instrument, const TimeSpan& session1, const TimeSpan& session2);
	void add(const QString& symbol, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	void add(const QString& symbol, const TimeSpan& session1, const TimeSpan& session2);

private:
	QSharedDataPointer<BarFactoryPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const BarFactory& barfactory);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BarFactory& barfactory);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarFactory)

#endif // __QUANTKIT_BARFACTORY_H__
