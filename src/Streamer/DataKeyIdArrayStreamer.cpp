#include <QuantKit/Streamer/DataKeyIdArrayStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class DataKeyIdArrayStreamerPrivate : public ObjectStreamerPrivate
{
public:
	DataKeyIdArrayStreamerPrivate();
	virtual ~DataKeyIdArrayStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual DataKeyIdArrayStreamerPrivate* clone() Q_DECL_OVERRIDE { return new DataKeyIdArrayStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataKeyIdArrayStreamerPrivate::DataKeyIdArrayStreamerPrivate()
{
		m_typeId = 105;
		m_type = typeof(Class45);
}

DataKeyIdArrayStreamerPrivate::~DataKeyIdArrayStreamerPrivate ()
{
}

QVariant DataKeyIdArrayStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	int size = reader.ReadInt32();
	IdArray<Class44> idArray = new IdArray<Class44>(size);
	while (true)
	{
		int num = reader.ReadInt32();
		if (num == -1)
		{
			break;
		}
		Class44 @class = new Class44(null, null, -1L, -1L);
		@class.Read(reader, true);
		idArray.Add(num, @class);
	}
	return new Class45(idArray);
}

void DataKeyIdArrayStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Class45 @class = (Class45)obj;
	IdArray<Class44> idArray_ = @class.idArray_0();
	writer.Write(idArray_.Size);
	for (int i = 0; i < idArray_.Size; i++)
	{
		if (idArray_[i] != null)
		{
			writer.Write(i);
			idArray_[i].WriteKey(writer);
		}
	}
	writer.Write(-1);
}


// Pubic API 

DataKeyIdArrayStreamer::DataKeyIdArrayStreamer()
	: ObjectStreamer(*new DataKeyIdArrayStreamerPrivate)
{
}

DataKeyIdArrayStreamer::~DataKeyIdArrayStreamer()
{
}


