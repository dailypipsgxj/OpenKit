#ifndef __QUANTKIT_FRAMEWORKSERVER_PRIVATE_H__
#define __QUANTKIT_FRAMEWORKSERVER_PRIVATE_H__

#include <QuantKit/FrameworkServer.h>

#include <QSharedData>

#include "Framework_p.h"

namespace QuantKit {

class FrameworkServerPrivate : public QSharedData
{
public:
	QString m_connectionString;
	Dictionary<QString,QString> m_dictionary;
	Framework m_framework;

public:
	FrameworkServerPrivate();
	virtual ~FrameworkServerPrivate();

public:
	Framework framework() const { return m_framework; }
	QString connectionString() const { return m_connectionString; }
	void setConnectionString(const QString& value);
	virtual void close() Q_DECL_OVERRIDE;
	virtual void flush() Q_DECL_OVERRIDE;
	virtual void open() Q_DECL_OVERRIDE;
//protected
	void setFramework(const Framework& value) { m_framework = value; }
	bool getBooleanValue(const QString& key, bool defaultValue);
	int getInt32Value(const QString& key, int defaultValue);
	QString getStringValue(const QString& key, const QString& defaultValue);

//private:
	void method_0();
};

} // namepsace QuantKit

#endif // __QUANTKIT_FRAMEWORKSERVER_PRIVATE_H__
