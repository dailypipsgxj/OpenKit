#include <QuantKit/NetDataFile_.h>

#include <QuantKit/StreamerManager.h>
#include <QuantKit/NetDataSeries.h>
#include "DataObject_p.h"
#include <QuantKit/QuickLZ.h>
#include "DataFile_p.h"

namespace QuantKit {

class NetDataFile_Private : public DataFilePrivate
{
public:
	QString string_2;
	int int_4;
	TcpClient tcpClient_0;
	QByteArray binaryReader_0;
	QByteArray binaryWriter_1;
	QList<Class42> list_1;
	Thread m_thread;
	QuickLZ quickLZ_0;

public:
	NetDataFile_Private(const QString& name, const QString& host, int port, const StreamerManager& streamerManager);
	virtual ~NetDataFile_Private();

public:
	void clear(const NetDataSeries& series);
	virtual void close() Q_DECL_OVERRIDE;
	virtual void delete(const QString& name) Q_DECL_OVERRIDE;
	virtual void flush() Q_DECL_OVERRIDE;
	virtual QVariant get(const QString& name) Q_DECL_OVERRIDE;
	virtual void open(FileMode mode) Q_DECL_OVERRIDE;
	virtual void refresh() Q_DECL_OVERRIDE;
	void refresh(const NetDataSeries& series);
	virtual void write(const QString& name, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual NetDataFile_Private* clone() Q_DECL_OVERRIDE { return new NetDataFile_Private(*this); }
//private:
	void method_8();
};

} // namepsace QuantKit


using namespace QuantKit;

NetDataFile_Private::NetDataFile_Private(const QString& name, const QString& host, int port, StreamerManager streamerManager)
	: DataFilePrivate (name, streamerManager)
	, string_2(host)
	, int_4(port)
	, m_thread(new Thread(new ThreadStart(method_8())))
	, quickLZ_0(new QuickLZ())
{
		m_thread.IsBackground = true;
		m_thread.Start();
}

NetDataFile_Private::~NetDataFile_Private ()
{
}

void NetDataFile_Private::clear(const NetDataSeries& series)
{
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	binaryWriter.Write(15);
	binaryWriter.Write(series.int_1());
	lock (stream_0)
	{
		stream_0.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
	}
}

void NetDataFile_Private::close()
{
	lock (stream_0)
	{
		stream_0.WriteByte(1);
	}
}

void NetDataFile_Private::delete(const QString& name)
{
	if (!m_keys.ContainsKey(name))
	{
		Console.WriteLine("NetDataFile_::Delete There is no such object in the data file : " + name);
		return;
	}
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	binaryWriter.Write(9);
	binaryWriter.Write(name);
	lock (stream_0)
	{
		stream_0.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
	}
	m_keys.Remove(name);
	bool_1 = true;
}

void NetDataFile_Private::flush()
{
	if (bool_1)
	{
		lock (stream_0)
		{
			stream_0.WriteByte(2);
		}
		bool_1 = false;
	}
}

QVariant NetDataFile_Private::get(const QString& name)
{
	if (!m_keys.ContainsKey(name))
	{
		return null;
	}
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	binaryWriter.Write(7);
	binaryWriter.Write(name);
	int num;
	byte b;
	byte b2;
	byte[] array;
	lock (stream_0)
	{
		stream_0.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
		num = binaryReader_0.ReadInt32();
		if (num == -1)
		{
			Console.WriteLine("NetDataFile::Get There is no such object on the server : " + name);
			object result = null;
			return result;
		}
		b = binaryReader_0.ReadByte();
		b2 = binaryReader_0.ReadByte();
		int num2 = binaryReader_0.ReadInt32();
		array = new byte[num2];
		memoryStream = new MemoryStream(array);
		binaryWriter = new BinaryWriter(memoryStream);
		byte[] buffer = new byte[8192];
		int num3 = num2;
		while (num3 != 0)
		{
			int num4;
			if (num3 < 8192)
			{
				num4 = stream_0.Read(buffer, 0, num3);
			}
			else
			{
				num4 = stream_0.Read(buffer, 0, 8192);
			}
			if (num4 == 0)
			{
				break;
			}
			num3 -= num4;
			memoryStream.Write(buffer, 0, num4);
		}
	}
	if (b2 != 0)
	{
		array = quickLZ_0.Decompress(array);
	}
	BinaryReader binaryReader = new BinaryReader(new MemoryStream(array));
	ObjectStreamer objectStreamer = streamerManager_0.idArray()[(int)b];
	byte version = binaryReader.ReadByte();
	object obj = objectStreamer.Read(binaryReader, version);
	if (b == 101)
	{
		return new NetDataSeries(this, num, (DataSeries)obj);
	}
	return obj;
}

void NetDataFile_Private::open(FileMode mode)
{
	if (bool_0)
	{
		Console.WriteLine("DataFile::Open File is already open: " + string_1);
		return;
	}
	if (!OpenFileStream(string_1, mode))
	{
		Console.WriteLine("DataFile::Open File does not exist: " + string_1);
		bool_0 = false;
		return;
	}
	Class51 @class = (Class51)streamerManager_0.Deserialize(binaryReader_0);
	m_keys = @class.dictionary_0();
	foreach (ObjectKey current in m_keys.Values)
	{
		current.method_0(this);
	}
	bool_0 = true;
}

void NetDataFile_Private::refresh()
{
	if (bool_0)
	{
		Class51 @class;
		lock (stream_0)
		{
			binaryWriter_1.Write(3);
			@class = (Class51)streamerManager_0.Deserialize(binaryReader_0);
		}
		m_keys = @class.dictionary_0();
		foreach (ObjectKey current in m_keys.Values)
		{
			current.method_0(this);
		}
	}
}

void NetDataFile_Private::refresh(const NetDataSeries& series)
{
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	binaryWriter.Write(14);
	binaryWriter.Write(series.int_1());
	long num;
	long num2;
	long num3;
	lock (stream_0)
	{
		stream_0.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
		num = binaryReader_0.ReadInt64();
		num2 = binaryReader_0.ReadInt64();
		num3 = binaryReader_0.ReadInt64();
	}
	if (series.count() != num)
	{
		series.setCount() = num;
		Console.WriteLine(string.Concat(new object[]
		{
			"DataSeries was changed on the server, count = ",
			series.count(),
			" ",
			series.name()
		}));
	}
	if (series.dateTime1().Ticks != num2)
	{
		series.setDateTime1() = new DateTime(num2);
		Console.WriteLine(string.Concat(new object[]
		{
			"DataSeries was changed on the server, dateTime1 = ",
			series.dateTime1(),
			" ",
			series.name()
		}));
	}
	if (series.dateTime2().Ticks != num3)
	{
		series.setDateTime2() = new DateTime(num3);
		Console.WriteLine(string.Concat(new object[]
		{
			"DataSeries was changed on the server, dateTime1 = ",
			series.dateTime2(),
			" ",
			series.name()
		}));
	}
}

void NetDataFile_Private::write(const QString& name, const QVariant& obj)
{
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	if (obj.GetType() == typeof(NetDataSeries))
	{
		NetDataSeries netDataSeries = (NetDataSeries)obj;
		netDataSeries.setNetDataFile__0() = this;
		binaryWriter.Write(13);
		binaryWriter.Write(netDataSeries.name());
		lock (stream_0)
		{
			stream_0.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
			netDataSeries.setInt_1() = binaryReader_0.ReadInt32();
			goto IL_E4;
		}
	}
	binaryWriter.Write(8);
	binaryWriter.Write(name);
	streamerManager_0.Serialize(binaryWriter, obj);
	lock (stream_0)
	{
		stream_0.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
	}
	IL_E4:
	if (m_keys.ContainsKey(name))
	{
		m_keys.Remove(name);
	}
	ObjectKey objectKey = new ObjectKey();
	objectKey.setString_1() = name;
	if (obj.GetType() == typeof(NetDataSeries))
	{
		objectKey.setTypeId() = 101;
	}
	else
	{
		ObjectStreamer objectStreamer;
		streamerManager_0.dictionary().TryGetValue(obj.GetType(), out objectStreamer);
		if (objectStreamer != null)
		{
			objectKey.setTypeId() = objectStreamer.typeId();
		}
	}
	m_keys.Add(name, objectKey);
}

void NetDataFile_Private::method_8()
{
	while (true)
	{
		if (list_1.Count != 0)
		{
			MemoryStream memoryStream = new MemoryStream();
			BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
			int count;
			lock (list_1)
			{
				count = list_1.Count;
				foreach (Class42 current in list_1)
				{
					binaryWriter.Write(current.byte_0());
					binaryWriter.Write(current.int_0());
					if (current.byte_0() != 12)
					{
						streamerManager_0.Serialize(binaryWriter, current.dataObject_0());
					}
					if (current.byte_0() != 10)
					{
						binaryWriter.Write(current.long_0());
					}
				}
				list_1.Clear();
			}
			if (count == 1)
			{
				lock (stream_0)
				{
					stream_0.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
					goto IL_1A4;
				}
				goto IL_117;
			}
			goto IL_117;
			IL_1A4:
			bool_1 = true;
			goto IL_0E;
			IL_117:
			byte[] array = quickLZ_0.Compress(memoryStream.GetBuffer());
			MemoryStream memoryStream2 = new MemoryStream();
			BinaryWriter binaryWriter2 = new BinaryWriter(memoryStream2);
			binaryWriter2.Write(16);
			binaryWriter2.Write(count);
			binaryWriter2.Write(array.Length);
			lock (stream_0)
			{
				stream_0.Write(memoryStream2.GetBuffer(), 0, (int)memoryStream2.Length);
				stream_0.Write(array, 0, array.Length);
			}
			goto IL_1A4;
		}
		IL_0E:
		Thread.Sleep(1);
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(NetDataFile_)

NetDataFile_::NetDataFile_(const QString& name, const QString& host, int port, StreamerManager streamerManager)
	: DataFile(*new NetDataFile_Private(name, host, port, streamerManager))
{
}

NetDataFile_::~NetDataFile_()
{
}

void NetDataFile_::clear(const NetDataSeries& series)
{
	Q_D(NetDataFile_);
	d->clear(series);
}

void NetDataFile_::refresh(const NetDataSeries& series)
{
	Q_D(NetDataFile_);
	d->refresh(series);
}


