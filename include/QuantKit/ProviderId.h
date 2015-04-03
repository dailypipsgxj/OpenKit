#ifndef __QUANTKIT_PROVIDERID_H__
#define __QUANTKIT_PROVIDERID_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class ProviderIdPrivate;

class QUANTKIT_EXPORT ProviderId
{
public:
	ProviderId();
	~ProviderId();

	ProviderId(const ProviderId &other);
	ProviderId& operator=(const ProviderId &other);
	bool operator==(const ProviderId &other) const;
	inline bool operator!=(const ProviderId &other) const { return !(this->operator==(other));  }
public:
	void add(const QString& name, unsigned char id);
	unsigned char get(const QString& name);
	void remove(const QString& name);

private:
	QSharedDataPointer<ProviderIdPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const ProviderId& providerid);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ProviderId& providerid);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderId)

#endif // __QUANTKIT_PROVIDERID_H__
