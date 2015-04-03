#include <QuantKit/Streamer/FreeKeyListStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class FreeKeyListStreamerPrivate : public ObjectStreamerPrivate
{
public:
	FreeKeyListStreamerPrivate();
	virtual ~FreeKeyListStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual FreeKeyListStreamerPrivate* clone() Q_DECL_OVERRIDE { return new FreeKeyListStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FreeKeyListStreamerPrivate::FreeKeyListStreamerPrivate()
{
		m_typeId = 103;
		m_type = typeof(Class49);
}

FreeKeyListStreamerPrivate::~FreeKeyListStreamerPrivate ()
{
}

QVariant FreeKeyListStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	List<Class48> list = new List<Class48>();
	int num = reader.ReadInt32();
	for (int i = 0; i < num; i++)
	{
		Class48 @class = new Class48();
		@class.mZoBrAexUc(reader, true);
		list.Add(@class);
	}
	return new Class49(list);
}

void FreeKeyListStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Class49 @class = (Class49)obj;
	List<Class48> list_ = @class.list_0();
	writer.Write(list_.Count);
	foreach (Class48 current in list_)
	{
		current.method_0(writer);
	}
}


// Pubic API 

FreeKeyListStreamer::FreeKeyListStreamer()
	: ObjectStreamer(*new FreeKeyListStreamerPrivate)
{
}

FreeKeyListStreamer::~FreeKeyListStreamer()
{
}


