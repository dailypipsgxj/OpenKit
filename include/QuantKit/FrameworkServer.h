#ifndef __QUANTKIT_FRAMEWORKSERVER_H__
#define __QUANTKIT_FRAMEWORKSERVER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <Dictionary>
#include <QSharedDataPointer>

namespace QuantKit {

class FrameworkServerPrivate;

class Framework;

class QUANTKIT_EXPORT FrameworkServer
{
public:
	FrameworkServer();
	~FrameworkServer();

	FrameworkServer(const FrameworkServer &other);
	FrameworkServer& operator=(const FrameworkServer &other);
	bool operator==(const FrameworkServer &other) const;
	inline bool operator!=(const FrameworkServer &other) const { return !(this->operator==(other));  }
public:
	Framework framework() const;
	QString connectionString() const;
	void setConnectionString(const QString& value);
	void close();
	void flush();
	void open();

protected:
	FrameworkServer(FrameworkServerPrivate& dd);
	QSharedDataPointer<FrameworkServerPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const FrameworkServer& frameworkserver);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const FrameworkServer& frameworkserver);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FrameworkServer)

#endif // __QUANTKIT_FRAMEWORKSERVER_H__
