#ifndef __QUANTKIT_PROVIDERLIST_H__
#define __QUANTKIT_PROVIDERLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/IProvider.h>

namespace QuantKit {

class ProviderListPrivate;

class IdArray;

class QUANTKIT_EXPORT ProviderList
{
public:
	ProviderList();
	~ProviderList();

	ProviderList(const ProviderList &other);
	ProviderList& operator=(const ProviderList &other);
	bool operator==(const ProviderList &other) const;
	inline bool operator!=(const ProviderList &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	IProvider item(const QString& name) const;
	void add(const IProvider& provider);
	void clear();
	IProvider getById(int id);
	IProvider getByIndex(int index);
	IProvider getByName(const QString& name);
	void remove(const IProvider& provider);

private:
	QSharedDataPointer<ProviderListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ProviderList& providerlist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ProviderList& providerlist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderList)

#endif // __QUANTKIT_PROVIDERLIST_H__
