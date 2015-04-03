#ifndef __QUANTKIT_INSTRUMENTLIST_H__
#define __QUANTKIT_INSTRUMENTLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class InstrumentListPrivate;

class Instrument;
class IdArray;

class QUANTKIT_EXPORT InstrumentList
{
public:
	InstrumentList();
	~InstrumentList();

	InstrumentList(const InstrumentList &other);
	InstrumentList& operator=(const InstrumentList &other);
	bool operator==(const InstrumentList &other) const;
	inline bool operator!=(const InstrumentList &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	Instrument item(const QString& symbol) const;
	void add(const Instrument& instrument);
	void clear();
	bool contains(const QString& symbol);
	bool contains(const Instrument& instrument);
	bool contains(int id);
	Instrument get(const QString& symbol);
	Instrument getById(int id);
	Instrument getByIndex(int index);
	void remove(const Instrument& instrument);
	QString toString() const;

private:
	QSharedDataPointer<InstrumentListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentList& instrumentlist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentList& instrumentlist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentList)

#endif // __QUANTKIT_INSTRUMENTLIST_H__
