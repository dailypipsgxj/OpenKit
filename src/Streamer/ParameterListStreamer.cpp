#include <QuantKit/Streamer/ParameterListStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class ParameterListStreamerPrivate : public ObjectStreamerPrivate
{
public:
	ParameterListStreamerPrivate();
	virtual ~ParameterListStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual ParameterListStreamerPrivate* clone() Q_DECL_OVERRIDE { return new ParameterListStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ParameterListStreamerPrivate::ParameterListStreamerPrivate()
{
		m_typeId = 214;
		m_type = typeof(ParameterList);
}

ParameterListStreamerPrivate::~ParameterListStreamerPrivate ()
{
}

QVariant ParameterListStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	ParameterList parameterList = new ParameterList();
	parameterList.setStrategyName() = reader.ReadString();
	int num = reader.ReadInt32();
	int num2 = reader.ReadInt32();
	for (int i = 0; i < num; i++)
	{
		Parameter parameter = m_streamerManager.Deserialize(reader) as Parameter;
		parameterList.Add(parameter);
	}
	for (int j = 0; j < num2; j++)
	{
		string item = reader.ReadString();
		parameterList.methods().Add(item);
	}
	return parameterList;
}

void ParameterListStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	ParameterList parameterList = (ParameterList)obj;
	int num = 0;
	foreach (Parameter current in parameterList)
	{
		Type type = current.value().GetType();
		if (m_streamerManager.dictionary().ContainsKey(type))
		{
			num++;
		}
	}
	writer.Write(parameterList.strategyName());
	writer.Write(num);
	writer.Write(parameterList.methods().Count);
	foreach (Parameter current2 in parameterList)
	{
		Type type2 = current2.value().GetType();
		if (m_streamerManager.dictionary().ContainsKey(type2))
		{
			m_streamerManager.Serialize(writer, current2);
		}
	}
	foreach (string current3 in parameterList.methods())
	{
		writer.Write(current3);
	}
}


// Pubic API 

ParameterListStreamer::ParameterListStreamer()
	: ObjectStreamer(*new ParameterListStreamerPrivate)
{
}

ParameterListStreamer::~ParameterListStreamer()
{
}


