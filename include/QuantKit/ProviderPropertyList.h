#ifndef __QUANTKIT_PROVIDERPROPERTYLIST_H__
#define __QUANTKIT_PROVIDERPROPERTYLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class ProviderPropertyListPrivate;


class QUANTKIT_EXPORT ProviderPropertyList
{
public:
	ProviderPropertyList();
	~ProviderPropertyList();

	ProviderPropertyList(const ProviderPropertyList &other);
	ProviderPropertyList& operator=(const ProviderPropertyList &other);
	bool operator==(const ProviderPropertyList &other) const;
	inline bool operator!=(const ProviderPropertyList &other) const { return !(this->operator==(other));  }
public:
	QString getStringValue(const QString& name, const QString& defaultValue);
	void setValue(const QString& name, const QString& value);

private:
	QSharedDataPointer<ProviderPropertyListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ProviderPropertyList& providerpropertylist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ProviderPropertyList& providerpropertylist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderPropertyList)

#endif // __QUANTKIT_PROVIDERPROPERTYLIST_H__
