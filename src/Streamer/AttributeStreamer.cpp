#include <QuantKit/Streamer/AttributeStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class AttributeStreamerPrivate : public ObjectStreamerPrivate
{
public:
	QString string_0;

public:
	AttributeStreamerPrivate();
	virtual ~AttributeStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual AttributeStreamerPrivate* clone() Q_DECL_OVERRIDE { return new AttributeStreamerPrivate(*this); }
//private:
	QString method_0(const QString& string_1);
	ConstructorInfo method_1(const ConstructorInfo& constructorInfo, const Dictionary<QString,QVariant>& properties);
	QVariant method_2(const ConstructorInfo& constructorInfo, const Dictionary<QString,QVariant>& properties);
};

} // namepsace QuantKit


using namespace QuantKit;

AttributeStreamerPrivate::AttributeStreamerPrivate()
	: string_0(text.Trim())
{
		m_typeId = 252;
		m_type = typeof(Attribute);
		Assembly[] assemblies = AppDomain.CurrentDomain.GetAssemblies();
		for (int i = 0; i < assemblies.Length; i++)
		{
			Assembly assembly = assemblies[i];
			if (assembly.GetName().Name == "System")
			{
				string[] array = assembly.FullName.Split(new char[]
				{
					','
				});
				string[] array2 = array;
				for (int j = 0; j < array2.Length; j++)
				{
					string text = array2[j];
					if (text.Contains("PublicKeyToken"))
					{
					}
				}
			}
		}
}

AttributeStreamerPrivate::~AttributeStreamerPrivate ()
{
}

QVariant AttributeStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	string typeName = method_0(reader.ReadString());
	Type type = Type.GetType(typeName);
	int num = reader.ReadInt32();
	Dictionary<string, object> dictionary = new Dictionary<string, object>();
	for (int i = 0; i < num; i++)
	{
		string key = reader.ReadString().ToUpper();
		if (reader.ReadBoolean())
		{
			string value = reader.ReadString();
			string typeName2 = method_0(reader.ReadString());
			Type type2 = Type.GetType(typeName2);
			dictionary[key] = Enum.Parse(type2, value);
		}
		else
		{
			dictionary[key] = m_streamerManager.Deserialize(reader);
		}
	}
	ConstructorInfo[] constructors = type.GetConstructors();
	ConstructorInfo constructorInfo = method_1(constructors, dictionary);
	if (constructorInfo != null)
	{
		object[] args = method_2(constructorInfo, dictionary);
		return Activator.CreateInstance(type, args);
	}
	return null;
}

void AttributeStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	Attribute attribute = (Attribute)obj;
	Type type = attribute.GetType();
	writer.Write(type.AssemblyQualifiedName);
	List<PropertyInfo> list = new List<PropertyInfo>();
	PropertyInfo[] properties = type.GetProperties(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public);
	PropertyInfo[] array = properties;
	for (int i = 0; i < array.Length; i++)
	{
		PropertyInfo propertyInfo = array[i];
		MethodInfo getMethod = propertyInfo.GetGetMethod(false);
		if (getMethod.GetBaseDefinition() == getMethod && propertyInfo.GetValue(attribute) != null && propertyInfo.PropertyType != typeof(Type))
		{
			list.Add(propertyInfo);
		}
	}
	writer.Write(list.Count);
	foreach (PropertyInfo current in list)
	{
		object value = current.GetValue(attribute);
		writer.Write(current.Name);
		writer.Write(value.GetType().IsEnum);
		if (value.GetType().IsEnum)
		{
			writer.Write(value.ToString());
			writer.Write(value.GetType().AssemblyQualifiedName);
		}
		else
		{
			m_streamerManager.Serialize(writer, value);
		}
	}
}

QString AttributeStreamerPrivate::method_0(const QString& string_1)
{
	int length = string_1.IndexOf("PublicKeyToken");
	string_1 = string_1.Substring(0, length) + string_0;
	return string_1;
}

ConstructorInfo AttributeStreamerPrivate::method_1(ConstructorInfo constructorInfo, const Dictionary<QString,QVariant>& properties)
{
	ConstructorInfo result = null;
	int i = 0;
	IL_88:
	while (i < constructorInfo.Length)
	{
		ConstructorInfo constructorInfo2 = constructorInfo[i];
		bool flag = true;
		ParameterInfo[] parameters = constructorInfo2.GetParameters();
		for (int j = 0; j < parameters.Length; j++)
		{
			ParameterInfo parameterInfo = parameters[j];
			if (!properties.ContainsKey(parameterInfo.Name.ToUpper()) || parameterInfo.ParameterType != properties[parameterInfo.Name.ToUpper()].GetType())
			{
				flag = false;
				IL_6D:
				if (flag)
				{
					result = constructorInfo2;
					if (constructorInfo2.GetParameters().Length == properties.Count)
					{
						return result;
					}
				}
				i++;
				goto IL_88;
			}
		}
		goto IL_6D;
	}
	return result;
}

QVariant AttributeStreamerPrivate::method_2(const ConstructorInfo& constructorInfo, const Dictionary<QString,QVariant>& properties)
{
	int num = constructorInfo.GetParameters().Length;
	object[] array = new object[num];
	ParameterInfo[] parameters = constructorInfo.GetParameters();
	for (int i = 0; i < parameters.Length; i++)
	{
		ParameterInfo parameterInfo = parameters[i];
		array[parameterInfo.Position] = properties[parameterInfo.Name.ToUpper()];
	}
	return array;
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(AttributeStreamer)

AttributeStreamer::AttributeStreamer()
	: ObjectStreamer(*new AttributeStreamerPrivate)
{
}

AttributeStreamer::~AttributeStreamer()
{
}


