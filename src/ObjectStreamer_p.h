#ifndef __QUANTKIT_OBJECTSTREAMER_PRIVATE_H__
#define __QUANTKIT_OBJECTSTREAMER_PRIVATE_H__

#include <QuantKit/ObjectStreamer.h>

#include <QSharedData>

#include "StreamerManager_p.h"

namespace QuantKit {

class ObjectStreamerPrivate : public QSharedData
{
public:
	unsigned char m_typeId;
	Type m_type;
	unsigned char version;
	StreamerManager m_streamerManager;

public:
	ObjectStreamerPrivate();
	virtual ~ObjectStreamerPrivate();

public:
	unsigned char getTypeId() const;
	void setTypeId(unsigned char value);

	Type getType() const;
	void setType(Type value);

	unsigned char getVersion() const;
	void setVersion(unsigned char value);
	StreamerManager streamerManager() const { return m_streamerManager; }
	virtual unsigned char getVersion(const QVariant& obj) Q_DECL_OVERRIDE { return version; }
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE { return new object(); }
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
};

} // namepsace QuantKit

#endif // __QUANTKIT_OBJECTSTREAMER_PRIVATE_H__
