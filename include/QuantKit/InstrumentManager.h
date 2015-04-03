#ifndef __QUANTKIT_INSTRUMENTMANAGER_H__
#define __QUANTKIT_INSTRUMENTMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class InstrumentManagerPrivate;

class InstrumentList;
class InstrumentServer;
class Framework;
class Instrument;

class QUANTKIT_EXPORT InstrumentManager
{
public:
	InstrumentManager(const Framework& framework, const InstrumentServer& server);
	~InstrumentManager();

	InstrumentManager(const InstrumentManager &other);
	InstrumentManager& operator=(const InstrumentManager &other);
	bool operator==(const InstrumentManager &other) const;
	inline bool operator!=(const InstrumentManager &other) const { return !(this->operator==(other));  }
public:
	InstrumentList instruments() const;
	InstrumentServer server() const;
	Instrument item(const QString& symbol) const;
	void add(const Instrument& instrument, bool save = true);
	void clear();
	bool contains(const QString& symbol);
    void remove(const Instrument& instrument);
    void remove(const QString& symbol);
	void dump();
	Instrument get(const QString& symbol);
	Instrument getById(int id);
	void load();
	void save(const Instrument& instrument);

private:
	QSharedDataPointer<InstrumentManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const InstrumentManager& instrumentmanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentManager& instrumentmanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentManager)

#endif // __QUANTKIT_INSTRUMENTMANAGER_H__
