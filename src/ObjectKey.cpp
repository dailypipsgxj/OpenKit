#include <QuantKit/ObjectKey.h>

#include "DataFile_p.h"
#include "ObjectKey_p.h"

using namespace QuantKit;

ObjectKeyPrivate::ObjectKeyPrivate()
	: string_0("OKey")
	, long_0(-1L)
	, int_0(-1)
	, int_1(-1)
	, int_2(-1)
	, byte_0(1)
	, byte_1(1)
{
}

ObjectKeyPrivate::ObjectKeyPrivate(const DataFile& file, QString name, QVariant obj)
	: class45_0(obj)
	, string_0("OKey")
	, long_0(-1L)
	, int_0(-1)
	, int_1(-1)
	, int_2(-1)
	, byte_0(1)
	, byte_0(file.compressionMethod())
	, byte_1(1)
	, byte_1(file.compressionLevel())
	, string_1(name)
{
		if (file != null)
		{
			method_0(file);
		}
}

ObjectKeyPrivate::~ObjectKeyPrivate ()
{
}

DataFile getDataFile_0() const
{
	return null;
}
void setDataFile_0(DataFile value)
{
}

Class45 getClass45_0() const
{
	return null;
}
void setClass45_0(Class45 value)
{
}

QString getString_0() const
{
	return null;
}
void setString_0(QString value)
{
}

bool getBool_0() const
{
	return false;
}
void setBool_0(bool value)
{
}

QDateTime getDateTime_0() const
{
	return null;
}
void setDateTime_0(QDateTime value)
{
}

long getLong_0() const
{
	return 0;
}
void setLong_0(long value)
{
}

int getInt_0() const
{
	return 0;
}
void setInt_0(int value)
{
}

int getInt_1() const
{
	return 0;
}
void setInt_1(int value)
{
}

int getInt_2() const
{
	return 0;
}
void setInt_2(int value)
{
}

unsigned char getByte_0() const
{
	return 0;
}
void setByte_0(unsigned char value)
{
}

unsigned char getByte_1() const
{
	return 0;
}
void setByte_1(unsigned char value)
{
}

QString getString_1() const
{
	return null;
}
void setString_1(QString value)
{
}

bool getChanged() const
{
	return false;
}
void setChanged(bool value)
{
}
int ObjectKeyPrivate::compareTo(const ObjectKey& other)
{
	if (other == null)
	{
		return 1;
	}
	return int_2.CompareTo(other.int_2());
}

void ObjectKeyPrivate::dump()
{
	if (dataFile_0.streamerManager_0().idArray()[(int)m_typeId] != null)
	{
		Console.WriteLine(string.Concat(new object[]
		{
			string_1,
			" of typeId ",
			m_typeId,
			" (",
			dataFile_0.streamerManager_0().idArray()[(int)m_typeId].type(),
			") position = ",
			long_0
		}));
		return;
	}
	Console.WriteLine(string.Concat(new object[]
	{
		string_1,
		" of typeId ",
		m_typeId,
		" (Unknown streamer, typeId = ",
		m_typeId,
		") position = ",
		long_0
	}));
}

QVariant ObjectKeyPrivate::getObject()
{
	if (class45_0 != null)
	{
		return class45_0;
	}
	if (int_1 == -1)
	{
		return null;
	}
	MemoryStream input = new MemoryStream(method_1(true));
	BinaryReader binaryReader = new BinaryReader(input);
	ObjectStreamer objectStreamer = dataFile_0.streamerManager_0().idArray()[(int)m_typeId];
	byte version = binaryReader.ReadByte();
	class45_0 = objectStreamer.Read(binaryReader, version);
	if (m_typeId == 101)
	{
		((DataSeries)class45_0).method_0(dataFile_0, this);
	}
	return class45_0;
}

//protected
void ObjectKeyPrivate::method_0(const DataFile& dataFile_1)
{
	dataFile_0 = dataFile_1;
	if (class45_0 != null)
	{
		ObjectStreamer objectStreamer;
		dataFile_1.streamerManager_0().dictionary().TryGetValue(class45_0.GetType(), out objectStreamer);
		if (objectStreamer != null)
		{
			m_typeId = objectStreamer.typeId();
			return;
		}
		Console.WriteLine("ObjectKey::Init Can not find streamer for object of type " + class45_0.GetType());
	}
}

unsigned char ObjectKeyPrivate::method_1(bool bool_1)
{
	byte[] array = new byte[int_1];
	dataFile_0.ReadBuffer(array, long_0 + (long)int_0, int_1);
	if (bool_1 && byte_1 != 0)
	{
		QuickLZ quickLZ = new QuickLZ();
		return quickLZ.Decompress(array);
	}
	return array;
}

void ObjectKeyPrivate::read(const QByteArray& reader, bool readLabel)
{
	if (readLabel)
	{
		string_0 = reader.ReadString();
		if (string_0 != "OKey")
		{
			Console.WriteLine("ObjectKey::Read This is not ObjectKey! label = " + string_0);
		}
	}
	bool_0 = reader.ReadBoolean();
	dateTime_0 = new DateTime(reader.ReadInt64());
	long_0 = reader.ReadInt64();
	int_0 = reader.ReadInt32();
	int_1 = reader.ReadInt32();
	int_2 = reader.ReadInt32();
	byte_0 = reader.ReadByte();
	byte_1 = reader.ReadByte();
	m_typeId = reader.ReadByte();
	string_1 = reader.ReadString();
}

void ObjectKeyPrivate::write(const QByteArray& writer)
{
	byte[] array = WriteObjectData(true);
	int_0 = 37 + string_1.Length + 1;
	int_1 = array.Length;
	if (int_2 == -1)
	{
		int_2 = int_0 + int_1;
	}
	writer.Write(string_0);
	writer.Write(bool_0);
	writer.Write(dateTime_0.Ticks);
	writer.Write(long_0);
	writer.Write(int_0);
	writer.Write(int_1);
	writer.Write(int_2);
	writer.Write(byte_0);
	writer.Write(byte_1);
	writer.Write(m_typeId);
	writer.Write(string_1);
	writer.Write(array, 0, array.Length);
}

void ObjectKeyPrivate::writeKey(const QByteArray& writer)
{
	writer.Write(string_0);
	writer.Write(bool_0);
	writer.Write(dateTime_0.Ticks);
	writer.Write(long_0);
	writer.Write(int_0);
	writer.Write(int_1);
	writer.Write(int_2);
	writer.Write(byte_0);
	writer.Write(byte_1);
	writer.Write(m_typeId);
	writer.Write(string_1);
}

unsigned char ObjectKeyPrivate::writeObjectData(bool compress)
{
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	Type type = class45_0.GetType();
	ObjectStreamer objectStreamer = dataFile_0.streamerManager_0().dictionary()[type];
	binaryWriter.Write(objectStreamer.GetVersion(class45_0));
	objectStreamer.Write(binaryWriter, class45_0);
	byte[] array = memoryStream.ToArray();
	if (compress && byte_1 != 0)
	{
		QuickLZ quickLZ = new QuickLZ();
		return quickLZ.Compress(array);
	}
	return array;
}


// Pubic API 

ObjectKey::ObjectKey()
	: d_ptr(new ObjectKeyPrivate)
{
}

ObjectKey::ObjectKey(const DataFile& file, QString name, QVariant obj)
	: d_ptr(new ObjectKeyPrivate(file, name, obj))
{
}

ObjectKey::~ObjectKey()
{
}

ObjectKey::ObjectKey (ObjectKeyPrivate &dd)
	: d_ptr(&dd)
{
}

ObjectKey::ObjectKey (const ObjectKey &other)
	: d_ptr(other.d_ptr)
{
}

ObjectKey& ObjectKey::operator=(const ObjectKey &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ObjectKey::operator==(const ObjectKey &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

DataFile dataFile_0() const
{
	return d_ptr->
	setDataFile_0()
}

void setDataFile_0(DataFile value)
{
	d_ptr->dataFile_0(value);
}

Class45 class45_0() const
{
	return d_ptr->
	setClass45_0()
}

void setClass45_0(Class45 value)
{
	d_ptr->class45_0(value);
}

QString string_0() const
{
	return d_ptr->
	setString_0()
}

void setString_0(QString value)
{
	d_ptr->string_0(value);
}

bool bool_0() const
{
	return d_ptr->
	setBool_0()
}

void setBool_0(bool value)
{
	d_ptr->bool_0(value);
}

QDateTime dateTime_0() const
{
	return d_ptr->
	setDateTime_0()
}

void setDateTime_0(QDateTime value)
{
	d_ptr->dateTime_0(value);
}

long long_0() const
{
	return d_ptr->
	setLong_0()
}

void setLong_0(long value)
{
	d_ptr->long_0(value);
}

int int_0() const
{
	return d_ptr->
	setInt_0()
}

void setInt_0(int value)
{
	d_ptr->int_0(value);
}

int int_1() const
{
	return d_ptr->
	setInt_1()
}

void setInt_1(int value)
{
	d_ptr->int_1(value);
}

int int_2() const
{
	return d_ptr->
	setInt_2()
}

void setInt_2(int value)
{
	d_ptr->int_2(value);
}

unsigned char byte_0() const
{
	return d_ptr->
	setByte_0()
}

void setByte_0(unsigned char value)
{
	d_ptr->byte_0(value);
}

unsigned char byte_1() const
{
	return d_ptr->
	setByte_1()
}

void setByte_1(unsigned char value)
{
	d_ptr->byte_1(value);
}

QString string_1() const
{
	return d_ptr->
	setString_1()
}

void setString_1(QString value)
{
	d_ptr->string_1(value);
}

bool changed() const
{
	return d_ptr->
	setChanged()
}

void setChanged(bool value)
{
	d_ptr->changed(value);
}

unsigned char ObjectKey::typeId() const
{
	return d_ptr->typeId();
}

int ObjectKey::compareTo(const ObjectKey& other)
{
	return d_ptr->compareTo(other);
}

void ObjectKey::dump()
{
	d_ptr->dump();
}

QVariant ObjectKey::getObject()
{
	return d_ptr->getObject();
}

QDebug operator<<(QDebug dbg, const ObjectKey& objectkey)
{
	return dbg << objectkey.toString();
}

