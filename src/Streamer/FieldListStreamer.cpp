#include <QuantKit/Streamer/FieldListStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class FieldListStreamerPrivate : public ObjectStreamerPrivate
{
public:
	FieldListStreamerPrivate();
	virtual ~FieldListStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual FieldListStreamerPrivate* clone() Q_DECL_OVERRIDE { return new FieldListStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FieldListStreamerPrivate::FieldListStreamerPrivate()
{
		m_typeId = 19;
		m_type = typeof(FieldList);
}

FieldListStreamerPrivate::~FieldListStreamerPrivate ()
{
}

QVariant FieldListStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	FieldList fieldList = new FieldList();
	int num = reader.ReadInt32();
	for (int i = 0; i < num; i++)
	{
		int id = reader.ReadInt32();
		double value = reader.ReadDouble();
		fieldList.idArray()[id] = value;
	}
	return fieldList;
}

void FieldListStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	FieldList fieldList = obj as FieldList;
	int num = 0;
	for (int i = 0; i < fieldList.idArray().Size; i++)
	{
		if (fieldList.idArray()[i] != 0.0)
		{
			num++;
		}
	}
	writer.Write(num);
	for (int j = 0; j < fieldList.idArray().Size; j++)
	{
		if (fieldList.idArray()[j] != 0.0)
		{
			writer.Write(j);
			writer.Write(fieldList.idArray()[j]);
		}
	}
}


// Pubic API 

FieldListStreamer::FieldListStreamer()
	: ObjectStreamer(*new FieldListStreamerPrivate)
{
}

FieldListStreamer::~FieldListStreamer()
{
}


