#include <QuantKit/Streamer/ParameterStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ParameterStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ParameterStreamerPrivate();
	virtual ~ParameterStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual ParameterStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ParameterStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ParameterStreamerPrivate::ParameterStreamerPrivate()
{
		m_typeId = 213;
		m_type = typeof(Parameter);
}

ParameterStreamerPrivate::~ParameterStreamerPrivate ()
{
}

QVariant ParameterStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	string name = reader.ReadString();
	object value = m_streamerManager.Deserialize(reader);
	int num = reader.ReadInt32();
	List<Attribute> list = new List<Attribute>();
	for (int i = 0; i < num; i++)
	{
		Attribute attribute = m_streamerManager.Deserialize(reader) as Attribute;
		if (attribute != null)
		{
			list.Add(attribute);
		}
	}
	return new Parameter(name, value, list.ToArray());
}

void ParameterStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Parameter parameter = (Parameter)obj;
	writer.Write(parameter.name());
	m_streamerManager.Serialize(writer, parameter.value());
	writer.Write(parameter.attributes().Length);
	Attribute[] attributes = parameter.attributes();
	for (int i = 0; i < attributes.Length; i++)
	{
		Attribute obj2 = attributes[i];
		writer.Write(252);
		writer.Write(m_streamerManager.idArray()[252].GetVersion(obj2));
		m_streamerManager.idArray()[252].Write(writer, obj2);
	}
}


// Pubic API 

ParameterStreamer::ParameterStreamer()
	: ObjectStreamer(*new ParameterStreamerPrivate)
{
}

ParameterStreamer::~ParameterStreamer()
{
}


