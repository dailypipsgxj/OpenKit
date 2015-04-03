#ifndef __QUANTKIT_STREAMERPLUGIN_H__
#define __QUANTKIT_STREAMERPLUGIN_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class StreamerPluginPrivate;

class QUANTKIT_EXPORT StreamerPlugin
{
public:
	StreamerPlugin();
	explicit StreamerPlugin(const QString& typeName);
	~StreamerPlugin();

	StreamerPlugin(const StreamerPlugin &other);
	StreamerPlugin& operator=(const StreamerPlugin &other);
	bool operator==(const StreamerPlugin &other) const;
	inline bool operator!=(const StreamerPlugin &other) const { return !(this->operator==(other));  }
public:
	QString typeName() const;
	void setTypeName(const QString& value);
	QString toString() const;

private:
	QSharedDataPointer<StreamerPluginPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const StreamerPlugin& streamerplugin);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const StreamerPlugin& streamerplugin);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StreamerPlugin)

#endif // __QUANTKIT_STREAMERPLUGIN_H__
