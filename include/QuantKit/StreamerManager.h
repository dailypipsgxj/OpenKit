#ifndef __QUANTKIT_STREAMERMANAGER_H__
#define __QUANTKIT_STREAMERMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QByteArray>
#include <QSharedDataPointer>

namespace QuantKit {

class StreamerManagerPrivate;

class ObjectStreamer;
class Event;
class DataObject;
class IdArray;

class QUANTKIT_EXPORT StreamerManager
{
public:
	StreamerManager();
	~StreamerManager();

	StreamerManager(const StreamerManager &other);
	StreamerManager& operator=(const StreamerManager &other);
	bool operator==(const StreamerManager &other) const;
	inline bool operator!=(const StreamerManager &other) const { return !(this->operator==(other));  }
public:
	IdArray<ObjectStreamer> idArray() const;

	Dictionary<Type,ObjectStreamer> dictionary() const;
	void add(const ObjectStreamer& streamer);
	QVariant deserialize(const QByteArray& reader);
	bool hasStreamer(const QVariant& obj);
	bool hasStreamer(const Type& type);
	bool hasStreamer(int typeId);
	void remove(const ObjectStreamer& streamer);
	void remove(unsigned char typeId);
	void remove(const Type& type);
	void serialize(const QByteArray& writer, const QVariant& obj);
	void serialize(const QByteArray& writer, const Event& e);
	void serialize(const QByteArray& writer, const DataObject& obj);

private:
	QSharedDataPointer<StreamerManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const StreamerManager& streamermanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const StreamerManager& streamermanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StreamerManager)

#endif // __QUANTKIT_STREAMERMANAGER_H__
