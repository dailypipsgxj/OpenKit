#ifndef __QUANTKIT_OBJECTSTREAMER_H__
#define __QUANTKIT_OBJECTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QByteArray>
#include <QSharedDataPointer>

namespace QuantKit {

class ObjectStreamerPrivate;

class StreamerManager;

class QUANTKIT_EXPORT ObjectStreamer
{
public:
	ObjectStreamer();
	~ObjectStreamer();

	ObjectStreamer(const ObjectStreamer &other);
	ObjectStreamer& operator=(const ObjectStreamer &other);
	bool operator==(const ObjectStreamer &other) const;
	inline bool operator!=(const ObjectStreamer &other) const { return !(this->operator==(other));  }
public:
	unsigned char typeId() const;
	void setTypeId(unsigned char value);

	Type type() const;
	void setType(Type value);

	unsigned char version() const;
	void setVersion(unsigned char value);
	StreamerManager streamerManager() const;
	unsigned char getVersion(const QVariant& obj);
	QVariant read(const QByteArray& reader, unsigned char version);
	void write(const QByteArray& writer, const QVariant& obj);

protected:
	ObjectStreamer(ObjectStreamerPrivate& dd);
	QSharedDataPointer<ObjectStreamerPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const ObjectStreamer& objectstreamer);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const ObjectStreamer& objectstreamer);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ObjectStreamer)

#endif // __QUANTKIT_OBJECTSTREAMER_H__
