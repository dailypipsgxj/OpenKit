#ifndef __QUANTKIT_INSTALLATION_H__
#define __QUANTKIT_INSTALLATION_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class InstallationPrivate;

class QUANTKIT_EXPORT Installation
{
public:
	~Installation();

	Installation(const Installation &other);
	Installation& operator=(const Installation &other);
	bool operator==(const Installation &other) const;
	inline bool operator!=(const Installation &other) const { return !(this->operator==(other));  }
public:
	DirectoryInfo applicationDir() const;
	DirectoryInfo dataDir() const;
	DirectoryInfo configDir() const;

private:
	QSharedDataPointer<InstallationPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const Installation& installation);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Installation& installation);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Installation)

#endif // __QUANTKIT_INSTALLATION_H__
