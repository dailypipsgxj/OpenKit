#include <QuantKit/Streamer/DataObjectStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class DataObjectStreamerPrivate : public ObjectStreamerPrivate
{
public:
	DataObjectStreamerPrivate();
	virtual ~DataObjectStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE
	{
		writer.Write((obj as DataObject).entryDate().Ticks);
	}

	virtual DataObjectStreamerPrivate* clone() Q_DECL_OVERRIDE { return new DataObjectStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataObjectStreamerPrivate::DataObjectStreamerPrivate()
{
		m_typeId = 0;
		m_type = typeof(DataObject);
}

DataObjectStreamerPrivate::~DataObjectStreamerPrivate ()
{
}

QVariant DataObjectStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	return new DataObject(dateTime);
}


// Pubic API 

DataObjectStreamer::DataObjectStreamer()
	: ObjectStreamer(*new DataObjectStreamerPrivate)
{
}

DataObjectStreamer::~DataObjectStreamer()
{
}


