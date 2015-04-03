#include <QuantKit/DataFileServerClient.h>

#include <QuantKit/FileManager.h>

namespace QuantKit {

class DataFileServerClientPrivate : public QSharedData
{
public:
	QVariant object_0;
	TcpClient tcpClient_0;
	FileManager fileManager_0;
	Thread m_thread;

public:
	DataFileServerClientPrivate(const TcpClient& client, const FileManager& fileManager);
	virtual ~DataFileServerClientPrivate();

//private:
	void method_0();
};

} // namepsace QuantKit


using namespace QuantKit;

DataFileServerClientPrivate::DataFileServerClientPrivate(const TcpClient& client, const FileManager& fileManager)
	: tcpClient_0(client)
	, fileManager_0(fileManager)
	, m_thread(new Thread(new ThreadStart(method_0())))
{
		m_thread.IsBackground = true;
		m_thread.Start();
}

DataFileServerClientPrivate::~DataFileServerClientPrivate ()
{
}

void DataFileServerClientPrivate::method_0()
{
	Console.WriteLine(DateTime.Now + " Client thread started");
	NetworkStream stream = tcpClient_0.GetStream();
	BinaryReader binaryReader = new BinaryReader(stream);
	BinaryWriter binaryWriter = new BinaryWriter(stream);
	FileStream fileStream = null;
	string text = "";
	try
	{
		while (true)
		{
			byte b = binaryReader.ReadByte();
			long offset;
			int num;
			switch (b)
			{
				case 0:
				{
					text = binaryReader.ReadString().Trim();
					FileMode fileMode = (FileMode)binaryReader.ReadByte();
					Console.WriteLine(string.Concat(new object[]
					{
						DateTime.Now,
						" Open file ",
						text,
						" in ",
						fileMode,
						" mode"
					}));
					lock (fileManager_0)
					{
						fileStream = fileManager_0.GetFile(text, fileMode);
						binaryWriter.Write(fileStream.Length);
					}
					break;
				}
				case 1:
					goto IL_194;
				case 2:
					Console.WriteLine(DateTime.Now + " Flush file " + text);
					lock (fileStream)
					{
						fileStream.Flush();
						break;
					}
					goto IL_194;
				case 4:
					goto IL_F9;
				case 5:
				{
					offset = binaryReader.ReadInt64();
					num = binaryReader.ReadInt32();
					byte[] buffer = new byte[8192];
					int num2 = num;
					lock (fileStream)
					{
						fileStream.Seek(offset, SeekOrigin.Begin);
						while (num != 0)
						{
							int num3;
							if (num2 < 8192)
							{
								num3 = stream.Read(buffer, 0, num2);
							}
							else
							{
								num3 = stream.Read(buffer, 0, 8192);
							}
							if (num3 == 0)
							{
								break;
							}
							num2 -= num3;
							fileStream.Write(buffer, 0, num3);
						}
						break;
					}
					goto IL_F9;
				}
			}
			IL_254:
			if (b == 1)
			{
				break;
			}
			continue;
			IL_F9:
			offset = binaryReader.ReadInt64();
			num = binaryReader.ReadInt32();
			byte[] buffer2 = new byte[num];
			lock (fileStream)
			{
				fileStream.Seek(offset, SeekOrigin.Begin);
				fileStream.Read(buffer2, 0, num);
			}
			stream.Write(buffer2, 0, num);
			goto IL_254;
			IL_194:
			Console.WriteLine(DateTime.Now + " Close file " + text);
			goto IL_254;
		}
	}
	catch (Exception value)
	{
		Console.WriteLine(DateTime.Now + " ServerClient exception. Connection closed.");
		Console.WriteLine(value);
	}
	finally
	{
		Console.WriteLine(DateTime.Now + " DataFileServerClient::Finally");
		if (fileStream != null)
		{
			lock (fileStream)
			{
				fileStream.Flush();
			}
		}
		tcpClient_0.Close();
	}
}


// Pubic API 

DataFileServerClient::DataFileServerClient(const TcpClient& client, const FileManager& fileManager)
	: d_ptr(new DataFileServerClientPrivate(client, fileManager))
{
}

DataFileServerClient::~DataFileServerClient()
{
}

DataFileServerClient::DataFileServerClient (const DataFileServerClient &other)
	: d_ptr(other.d_ptr)
{
}

DataFileServerClient& DataFileServerClient::operator=(const DataFileServerClient &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataFileServerClient::operator==(const DataFileServerClient &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const DataFileServerClient& datafileserverclient)
{
	return dbg << datafileserverclient.toString();
}

