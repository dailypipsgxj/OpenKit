#include <QuantKit/DataFile.h>

#include "ObjectKey_p.h"
#include <QuantKit/StreamerManager.h>
#include "DataFile_p.h"

using namespace QuantKit;

DataFilePrivate::DataFilePrivate(const QString& name, const StreamerManager& streamerManager)
	: string_0("SmartQuant")
	, byte_0(1)
	, m_compressionMethod(1)
	, m_compressionLevel(1)
	, string_1(name)
	, m_keys(new Dictionary<string, ObjectKey>())
	, streamerManager_0(streamerManager)
	, memoryStream_0(new MemoryStream())
	, binaryWriter_0(new BinaryWriter(memoryStream_0))
{
}

DataFilePrivate::~DataFilePrivate ()
{
}

long getLong_0() const
{
	return 0;
}
void setLong_0(long value)
{
}

long getLong_1() const
{
	return 0;
}
void setLong_1(long value)
{
}

long getACdHfUdLo6() const
{
	return 0;
}
void setACdHfUdLo6(long value)
{
}

long getLong_2() const
{
	return 0;
}
void setLong_2(long value)
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

int getInt_3() const
{
	return 0;
}
void setInt_3(int value)
{
}

Stream getStream_0() const
{
	return null;
}
void setStream_0(Stream value)
{
}

bool getBool_0() const
{
	return false;
}
void setBool_0(bool value)
{
}

bool getBool_1() const
{
	return false;
}
void setBool_1(bool value)
{
}

QString getString_1() const
{
	return null;
}

StreamerManager getStreamerManager_0() const
{
	return null;
}
void DataFilePrivate::close()
{
	if (!bool_0)
	{
		Console.WriteLine("DataFile::Close File is not open: " + string_1);
		return;
	}
	Flush();
	CloseFileStream();
	bool_0 = false;
}

void DataFilePrivate::delete(const QString& name)
{
	ObjectKey objectKey;
	m_keys.TryGetValue(name, out objectKey);
	if (objectKey != null)
	{
		method_2(objectKey, true);
	}
}

void DataFilePrivate::dispose()
{
	Console.WriteLine("DataFile::Dispose");
	method_7(true);
	GC.SuppressFinalize(this);
}

void DataFilePrivate::dump()
{
	if (bool_0)
	{
		Console.WriteLine(string.Concat(new object[]
		{
			"DataFile ",
			string_1,
			" is open in ",
			fileMode_0,
			" mode and contains ",
			m_keys.Values.Count,
			" objects:"
		}));
		foreach (ObjectKey current in m_keys.Values)
		{
			current.Dump();
		}
		Console.WriteLine("Free objects = " + int_3);
		using (List<Class48>.Enumerator enumerator2 = list_0.GetEnumerator())
		{
			while (enumerator2.MoveNext())
			{
				Class48 current2 = enumerator2.Current;
				Console.WriteLine(current2.long_0() + " " + current2.int_0());
			}
			return;
		}
	}
	Console.WriteLine("ObjectFile " + string_1 + " is closed");
}

void DataFilePrivate::flush()
{
	if (bool_1)
	{
		foreach (ObjectKey current in m_keys.Values)
		{
			if (current.typeId() == 101 && current.class45_0() != null)
			{
				DataSeries dataSeries = (DataSeries)current.class45_0();
				if (dataSeries.bool_3())
				{
					dataSeries.method_18();
				}
			}
		}
		method_5();
		method_6();
		method_0();
		stream_0.Flush();
	}
	bool_1 = false;
}

QVariant DataFilePrivate::get(const QString& name)
{
	ObjectKey objectKey;
	m_keys.TryGetValue(name, out objectKey);
	if (objectKey != null)
	{
		return objectKey.GetObject();
	}
	return null;
}

void DataFilePrivate::open(FileMode mode)
{
	if (mode != FileMode.OpenOrCreate && mode != FileMode.Create)
	{
		Console.WriteLine("DataFile::Open Can not open file in " + mode + " mode. DataFile suppports FileMode.OpenOrCreate and FileMode.Create modes.");
		return;
	}
	if (bool_0)
	{
		Console.WriteLine("DataFile::Open File is already open: " + string_1);
		return;
	}
	fileMode_0 = mode;
	if (!OpenFileStream(string_1, mode))
	{
		long_0 = 62L;
		long_1 = 62L;
		aCdHfUdLo6 = 62L;
		long_2 = 62L;
		int_0 = 0;
		int_1 = 0;
		int_2 = 0;
		int_3 = 0;
		bool_1 = true;
		method_0();
	}
	else
	{
		if (!lEqHupgyQs())
		{
			Console.WriteLine("DataFile::Open Error opening file " + string_1);
			return;
		}
		ReadKeys();
		ReadFree();
	}
	bool_0 = true;
}

void DataFilePrivate::refresh()
{
}

void DataFilePrivate::write(const QString& name, const QVariant& obj)
{
	ObjectKey objectKey;
	m_keys.TryGetValue(name, out objectKey);
	if (objectKey != null)
	{
		objectKey.setClass45_0() = obj;
		objectKey.method_0(this);
	}
	else
	{
		objectKey = new ObjectKey(this, name, obj);
		m_keys.Add(name, objectKey);
		int_2++;
	}
	objectKey.setDateTime_0() = DateTime.Now;
	if (objectKey.typeId() == 101)
	{
		((DataSeries)obj).method_0(this, objectKey);
	}
	method_4(objectKey);
}

//protected
bool DataFilePrivate::lEqHupgyQs()
{
	byte[] buffer = new byte[62];
	ReadBuffer(buffer, 0L, 62);
	MemoryStream input = new MemoryStream(buffer);
	BinaryReader binaryReader = new BinaryReader(input);
	string_0 = binaryReader.ReadString();
	if (string_0 != "SmartQuant")
	{
		Console.WriteLine("DataFile::ReadHeader This is not SmartQuant data file!");
		return false;
	}
	byte_0 = binaryReader.ReadByte();
	long_0 = binaryReader.ReadInt64();
	long_1 = binaryReader.ReadInt64();
	aCdHfUdLo6 = binaryReader.ReadInt64();
	long_2 = binaryReader.ReadInt64();
	int_0 = binaryReader.ReadInt32();
	int_1 = binaryReader.ReadInt32();
	int_2 = binaryReader.ReadInt32();
	int_3 = binaryReader.ReadInt32();
	m_compressionMethod = binaryReader.ReadByte();
	m_compressionLevel = binaryReader.ReadByte();
	return true;
}

void DataFilePrivate::method_0()
{
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	binaryWriter.Write(string_0);
	binaryWriter.Write(byte_0);
	binaryWriter.Write(long_0);
	binaryWriter.Write(long_1);
	binaryWriter.Write(aCdHfUdLo6);
	binaryWriter.Write(long_2);
	binaryWriter.Write(int_0);
	binaryWriter.Write(int_1);
	binaryWriter.Write(int_2);
	binaryWriter.Write(int_3);
	binaryWriter.Write(m_compressionMethod);
	binaryWriter.Write(m_compressionLevel);
	WriteBuffer(memoryStream.GetBuffer(), 0L, (int)memoryStream.Length);
}

void DataFilePrivate::method_2(const ObjectKey& objectKey_2, bool bool_3)
{
	objectKey_2.setBool_0() = true;
	WriteBuffer(new byte[]
	{
		1
	}, objectKey_2.long_0() + 5L, 1);
	if (bool_3)
	{
		m_keys.Remove(objectKey_2.string_1());
		int_2--;
	}
	list_0.Add(new Class48(objectKey_2));
	list_0.Sort();
	int_3++;
	bool_1 = true;
}

ObjectKey DataFilePrivate::method_3(long long_3, int int_4)
{
	byte[] buffer = new byte[int_0];
	ReadBuffer(buffer, long_3, int_4);
	MemoryStream input = new MemoryStream(buffer);
	BinaryReader reader = new BinaryReader(input);
	ObjectKey objectKey = new ObjectKey(this, null, null);
	objectKey.Read(reader, true);
	objectKey.setLong_0() = long_3;
	return objectKey;
}

void DataFilePrivate::method_4(const ObjectKey& objectKey_2)
{
	memoryStream_0.SetLength(0L);
	objectKey_2.Write(binaryWriter_0);
	if (objectKey_2.long_0() != -1L)
	{
		if (memoryStream_0.Length > (long)objectKey_2.int_2())
		{
			method_2(objectKey_2, false);
			objectKey_2.setInt_2() = (int)memoryStream_0.Length;
			Class48 @class;
			if (objectKey_2 == objectKey_1)
			{
				@class = method_1(objectKey_2.int_0() + objectKey_2.int_1() - 17);
			}
			else
			{
				@class = method_1(objectKey_2.int_0() + objectKey_2.int_1());
			}
			if (@class != null)
			{
				objectKey_2.setLong_0() = @class.long_0();
				objectKey_2.setInt_2() = @class.int_0();
				list_0.Remove(@class);
				int_3--;
				if (objectKey_2 == objectKey_1)
				{
					memoryStream_0.SetLength(0L);
					objectKey_2.Write(binaryWriter_0);
				}
			}
			else
			{
				objectKey_2.setLong_0() = long_1;
				long_1 += (long)objectKey_2.int_2();
			}
		}
	}
	else
	{
		objectKey_2.setLong_0() = long_1;
		long_1 += (long)objectKey_2.int_2();
	}
	WriteBuffer(memoryStream_0.GetBuffer(), objectKey_2.long_0(), (int)memoryStream_0.Length);
	objectKey_2.setChanged() = false;
	bool_1 = true;
}

bool DataFilePrivate::openFileStream(const QString& name, FileMode mode)
{
	stream_0 = new FileStream(name, mode);
	return stream_0.Length != 0L;
}

void DataFilePrivate::readBuffer(unsigned char buffer, long position, int length)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		stream_0.Seek(position, SeekOrigin.Begin);
		stream_0.Read(buffer, 0, length);
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void DataFilePrivate::readFree()
{
	if (int_1 == 0)
	{
		return;
	}
	byte[] buffer = new byte[int_1];
	ReadBuffer(buffer, long_2, int_1);
	MemoryStream input = new MemoryStream(buffer);
	BinaryReader reader = new BinaryReader(input);
	ObjectKey objectKey = new ObjectKey(this, null, null);
	objectKey.Read(reader, true);
	objectKey.setLong_0() = long_2;
	list_0 = ((Class49)objectKey.GetObject()).list_0();
	objectKey_1 = objectKey;
}

void DataFilePrivate::readKeys()
{
	if (int_0 == 0)
	{
		return;
	}
	byte[] buffer = new byte[int_0];
	ReadBuffer(buffer, aCdHfUdLo6, int_0);
	MemoryStream input = new MemoryStream(buffer);
	BinaryReader reader = new BinaryReader(input);
	ObjectKey objectKey = new ObjectKey(this, null, null);
	objectKey.Read(reader, true);
	objectKey.setLong_0() = aCdHfUdLo6;
	m_keys = ((Class51)objectKey.GetObject()).dictionary_0();
	foreach (ObjectKey current in m_keys.Values)
	{
		current.method_0(this);
	}
	objectKey_0 = objectKey;
}

void DataFilePrivate::writeBuffer(unsigned char buffer, long position, int length)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		stream_0.Seek(position, SeekOrigin.Begin);
		stream_0.Write(buffer, 0, length);
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

Class48 DataFilePrivate::method_1(int int_4)
{
	foreach (Class48 current in list_0)
	{
		if (current.int_0() >= int_4)
		{
			return current;
		}
	}
	return null;
}

void DataFilePrivate::method_5()
{
	if (objectKey_0 != null)
	{
		method_2(objectKey_0, false);
	}
	objectKey_0 = new ObjectKey(this, "ObjectKeys", new Class51(m_keys));
	objectKey_0.setByte_1() = 0;
	method_4(objectKey_0);
	aCdHfUdLo6 = objectKey_0.long_0();
	int_0 = objectKey_0.int_0() + objectKey_0.int_1();
}

void DataFilePrivate::method_6()
{
	if (objectKey_1 != null)
	{
		method_2(objectKey_1, false);
	}
	objectKey_1 = new ObjectKey(this, "FreeKeys", new Class49(list_0));
	objectKey_1.setByte_1() = 0;
	method_4(objectKey_1);
	long_2 = objectKey_1.long_0();
	int_1 = objectKey_1.int_0() + objectKey_1.int_1();
}

void DataFilePrivate::method_7(bool bool_3)
{
	if (!bool_2)
	{
		if (bool_3)
		{
			Close();
		}
		bool_2 = true;
	}
}


// Pubic API 

DataFile::DataFile(const QString& name, const StreamerManager& streamerManager)
	: d_ptr(new DataFilePrivate(name, streamerManager))
{
}

DataFile::~DataFile()
{
}

DataFile::DataFile (DataFilePrivate &dd)
	: d_ptr(&dd)
{
}

DataFile::DataFile (const DataFile &other)
	: d_ptr(other.d_ptr)
{
}

DataFile& DataFile::operator=(const DataFile &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataFile::operator==(const DataFile &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
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

long long_1() const
{
	return d_ptr->
	setLong_1()
}

void setLong_1(long value)
{
	d_ptr->long_1(value);
}

long aCdHfUdLo6() const
{
	return d_ptr->
	setACdHfUdLo6()
}

void setACdHfUdLo6(long value)
{
	d_ptr->aCdHfUdLo6(value);
}

long long_2() const
{
	return d_ptr->
	setLong_2()
}

void setLong_2(long value)
{
	d_ptr->long_2(value);
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

int int_3() const
{
	return d_ptr->
	setInt_3()
}

void setInt_3(int value)
{
	d_ptr->int_3(value);
}

Stream stream_0() const
{
	return d_ptr->
	setStream_0()
}

void setStream_0(Stream value)
{
	d_ptr->stream_0(value);
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

bool bool_1() const
{
	return d_ptr->
	setBool_1()
}

void setBool_1(bool value)
{
	d_ptr->bool_1(value);
}

QString string_1() const
{
	return d_ptr->
	setString_1()
}

StreamerManager streamerManager_0() const
{
	return d_ptr->
	setStreamerManager_0()
}

Dictionary<QString,ObjectKey> DataFile::keys() const
{
	return d_ptr->keys();
}

unsigned char DataFile::compressionMethod() const
{
	return d_ptr->compressionMethod();
}

void DataFile::setCompressionMethod(unsigned char value)
{
	d_ptr->setCompressionMethod(value);
}

unsigned char DataFile::compressionLevel() const
{
	return d_ptr->compressionLevel();
}

void DataFile::setCompressionLevel(unsigned char value)
{
	d_ptr->setCompressionLevel(value);
}

void DataFile::close()
{
	d_ptr->close();
}

void DataFile::delete(const QString& name)
{
	d_ptr->delete(name);
}

void DataFile::dispose()
{
	d_ptr->dispose();
}

void DataFile::dump()
{
	d_ptr->dump();
}

void DataFile::flush()
{
	d_ptr->flush();
}

QVariant DataFile::get(const QString& name)
{
	return d_ptr->get(name);
}

void DataFile::open(FileMode mode)
{
	d_ptr->open(mode);
}

void DataFile::refresh()
{
	d_ptr->refresh();
}

void DataFile::write(const QString& name, const QVariant& obj)
{
	d_ptr->write(name, obj);
}

QDebug operator<<(QDebug dbg, const DataFile& datafile)
{
	return dbg << datafile.toString();
}

