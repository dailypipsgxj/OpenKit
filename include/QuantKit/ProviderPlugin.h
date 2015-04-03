#ifndef __QUANTKIT_PROVIDERPLUGIN_H__
#define __QUANTKIT_PROVIDERPLUGIN_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class ProviderPluginPrivate;

class QUANTKIT_EXPORT ProviderPlugin
{
public:
	ProviderPlugin();
	ProviderPlugin(const QString& typeName, bool x64 = false);
	~ProviderPlugin();

	ProviderPlugin(const ProviderPlugin &other);
	ProviderPlugin& operator=(const ProviderPlugin &other);
	bool operator==(const ProviderPlugin &other) const;
	inline bool operator!=(const ProviderPlugin &other) const { return !(this->operator==(other));  }
public:
	QString typeName() const;
	void setTypeName(const QString& value);
	bool x64() const;
	void setX64(bool value);
	QString toString() const;

private:
	QSharedDataPointer<ProviderPluginPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ProviderPlugin& providerplugin);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ProviderPlugin& providerplugin);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderPlugin)

#endif // __QUANTKIT_PROVIDERPLUGIN_H__
