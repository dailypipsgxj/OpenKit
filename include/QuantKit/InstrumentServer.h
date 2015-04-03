#ifndef __QUANTKIT_INSTRUMENTSERVER_H__
#define __QUANTKIT_INSTRUMENTSERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class InstrumentServerPrivate;

class Framework;
class InstrumentList;
class Instrument;

class QUANTKIT_EXPORT InstrumentServer
{
public:
	explicit InstrumentServer(const Framework& framework);
	~InstrumentServer();

	InstrumentServer(const InstrumentServer &other);
	InstrumentServer& operator=(const InstrumentServer &other);
	bool operator==(const InstrumentServer &other) const;
	inline bool operator!=(const InstrumentServer &other) const { return !(this->operator==(other));  }
public:
	InstrumentList instruments() const;
	void close();
    void remove(const Instrument& instrument);
	void flush();
	InstrumentList load();
	void open();
	void save(const Instrument& instrument);

protected:
	InstrumentServer(InstrumentServerPrivate& dd);
	QSharedDataPointer<InstrumentServerPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const InstrumentServer& instrumentserver);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const InstrumentServer& instrumentserver);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentServer)

#endif // __QUANTKIT_INSTRUMENTSERVER_H__
