#include <QuantKit/Streamer/ObjectKeyListStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ObjectKeyListStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ObjectKeyListStreamerPrivate();
	virtual ~ObjectKeyListStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual ObjectKeyListStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ObjectKeyListStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ObjectKeyListStreamerPrivate::ObjectKeyListStreamerPrivate()
{
		m_typeId = 102;
		m_type = typeof(Class51);
}

ObjectKeyListStreamerPrivate::~ObjectKeyListStreamerPrivate ()
{
}

QVariant ObjectKeyListStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	Dictionary<string, ObjectKey> dictionary = new Dictionary<string, ObjectKey>();
	int num = reader.ReadInt32();
	for (int i = 0; i < num; i++)
	{
		ObjectKey objectKey = new ObjectKey();
		objectKey.Read(reader, true);
		dictionary.Add(objectKey.string_1(), objectKey);
	}
	return new Class51(dictionary);
}

void ObjectKeyListStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Class51 @class = (Class51)obj;
	Dictionary<string, ObjectKey> dictionary_ = @class.dictionary_0();
	writer.Write(dictionary_.Count);
	foreach (ObjectKey current in dictionary_.Values)
	{
		current.WriteKey(writer);
	}
}


// Pubic API 

ObjectKeyListStreamer::ObjectKeyListStreamer()
	: ObjectStreamer(*new ObjectKeyListStreamerPrivate)
{
}

ObjectKeyListStreamer::~ObjectKeyListStreamer()
{
}


