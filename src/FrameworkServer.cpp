#include <QuantKit/FrameworkServer.h>

#include <QuantKit/Framework.h>
#include "FrameworkServer_p.h"

using namespace QuantKit;

FrameworkServerPrivate::FrameworkServerPrivate()
	: m_dictionary(new Dictionary<string, string>())
{
}

FrameworkServerPrivate::~FrameworkServerPrivate ()
{
}

void FrameworkServerPrivate::setConnectionString(const QString& value)
{
	m_connectionString = value;
	method_0();
}

void FrameworkServerPrivate::close()
{
}

void FrameworkServerPrivate::flush()
{
}

void FrameworkServerPrivate::open()
{
}

//protected
bool FrameworkServerPrivate::getBooleanValue(const QString& key, bool defaultValue)
{
	string stringValue = GetStringValue(key, string.Empty);
	bool result;
	if (!bool.TryParse(stringValue, out result))
	{
		result = defaultValue;
	}
	return result;
}

int FrameworkServerPrivate::getInt32Value(const QString& key, int defaultValue)
{
	string stringValue = GetStringValue(key, string.Empty);
	int result;
	if (!int.TryParse(stringValue, out result))
	{
		result = defaultValue;
	}
	return result;
}

QString FrameworkServerPrivate::getStringValue(const QString& key, const QString& defaultValue)
{
	string result;
	if (!m_dictionary.TryGetValue(key.ToUpper(), out result))
	{
		result = defaultValue;
	}
	return result;
}

void FrameworkServerPrivate::method_0()
{
	m_dictionary.Clear();
	if (m_connectionString != null)
	{
		string[] array = m_connectionString.Split(new char[]
		{
			';'
		}, StringSplitOptions.RemoveEmptyEntries);
		string[] array2 = array;
		for (int i = 0; i < array2.Length; i++)
		{
			string text = array2[i];
			string[] array3 = text.Split(new char[]
			{
				'='
			}, StringSplitOptions.RemoveEmptyEntries);
			if (array3.Length == 2)
			{
				string key = array3[0].Trim().ToUpper();
				string value = array3[1].Trim();
				m_dictionary[key] = value;
			}
		}
	}
}


// Pubic API 

FrameworkServer::FrameworkServer()
	: d_ptr(new FrameworkServerPrivate)
{
}

FrameworkServer::~FrameworkServer()
{
}

FrameworkServer::FrameworkServer (FrameworkServerPrivate &dd)
	: d_ptr(&dd)
{
}

FrameworkServer::FrameworkServer (const FrameworkServer &other)
	: d_ptr(other.d_ptr)
{
}

FrameworkServer& FrameworkServer::operator=(const FrameworkServer &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool FrameworkServer::operator==(const FrameworkServer &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Framework FrameworkServer::framework() const
{
	return d_ptr->framework();
}

QString FrameworkServer::connectionString() const
{
	return d_ptr->connectionString();
}

void FrameworkServer::setConnectionString(const QString& value)
{
	d_ptr->setConnectionString(value);
}

void FrameworkServer::close()
{
	d_ptr->close();
}

void FrameworkServer::flush()
{
	d_ptr->flush();
}

void FrameworkServer::open()
{
	d_ptr->open();
}

QDebug operator<<(QDebug dbg, const FrameworkServer& frameworkserver)
{
	return dbg << frameworkserver.toString();
}

