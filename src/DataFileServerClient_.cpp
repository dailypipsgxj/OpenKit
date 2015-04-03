#include <QuantKit/DataFileServerClient_.h>

#include <QuantKit/DataFileManager.h>
#include "DataFile_p.h"
#include <QuantKit/StreamerManager.h>
#include <QuantKit/IdArray.h>
#include "DataSeries_p.h"
#include <QuantKit/QuickLZ.h>

namespace QuantKit {

class DataFileServerClient_Private : public QSharedData
{
public:
	QVariant object_0;
	TcpClient tcpClient_0;
	DataFileManager dataFileManager_0;
	Thread m_thread;
	DataFile dataFile_0;
	StreamerManager streamerManager_0;
	int int_0;
	IdArray<DataSeries> m_idArray;
	QuickLZ quickLZ_0;

public:
	DataFileServerClient_Private(const TcpClient& client, const DataFileManager& fileManager);
	virtual ~DataFileServerClient_Private();

//private:
	void method_0();
};

} // namepsace QuantKit


using namespace QuantKit;

DataFileServerClient_Private::DataFileServerClient_Private(const TcpClient& client, const DataFileManager& fileManager)
	: tcpClient_0(client)
	, dataFileManager_0(fileManager)
	, m_thread(new Thread(new ThreadStart(method_0())))
	, streamerManager_0(new StreamerManager())
	, m_idArray(new IdArray<DataSeries>(1000))
	, quickLZ_0(new QuickLZ())
{
		streamerManager_0.Add(new DataObjectStreamer());
		streamerManager_0.Add(new BidStreamer());
		streamerManager_0.Add(new AskStreamer());
		streamerManager_0.Add(new QuoteStreamer());
		streamerManager_0.Add(new TradeStreamer());
		streamerManager_0.Add(new BarStreamer());
		streamerManager_0.Add(new Level2SnapshotStreamer());
		streamerManager_0.Add(new Level2UpdateStreamer());
		streamerManager_0.Add(new NewsStreamer());
		streamerManager_0.Add(new FundamentalStreamer());
		streamerManager_0.Add(new DataSeriesStreamer());
		streamerManager_0.Add(new ObjectTableStreamer());
		streamerManager_0.Add(new InstrumentStreamer());
		streamerManager_0.Add(new AltIdStreamer());
		streamerManager_0.Add(new LegStreamer());
		streamerManager_0.Add(new ExecutionCommandStreamer());
		streamerManager_0.Add(new ExecutionReportStreamer());
		streamerManager_0.Add(new PositionStreamer());
		streamerManager_0.Add(new PortfolioStreamer());
		streamerManager_0.Add(new DoubleStreamer());
		streamerManager_0.Add(new Int16Streamer());
		streamerManager_0.Add(new Int32Streamer());
		streamerManager_0.Add(new Int64Streamer());
		streamerManager_0.Add(new StringStreamer());
		streamerManager_0.Add(new TimeSeriesItemStreamer());
		m_thread.IsBackground = true;
		m_thread.Start();
}

DataFileServerClient_Private::~DataFileServerClient_Private ()
{
}

void DataFileServerClient_Private::method_0()
{
	Console.WriteLine(DateTime.Now + " Client thread started");
	NetworkStream stream = tcpClient_0.GetStream();
	BinaryReader binaryReader = new BinaryReader(stream);
	BinaryWriter binaryWriter = new BinaryWriter(stream);
	try
	{
		while (true)
		{
			byte b = binaryReader.ReadByte();
			MemoryStream memoryStream;
			BinaryWriter binaryWriter2;
			string text;
			switch (b)
			{
				case 0:
					goto IL_890;
				case 2:
					goto IL_83D;
				case 3:
					lock (dataFile_0)
					{
						Class51 obj2 = new Class51(dataFile_0.keys());
						streamerManager_0.Serialize(binaryWriter, obj2);
						break;
					}
					goto IL_83D;
				case 6:
				{
					int id = binaryReader.ReadInt32();
					bool flag2 = binaryReader.ReadBoolean();
					long num = binaryReader.ReadInt64();
					DataSeries dataSeries = m_idArray[id];
					Class44 @class;
					byte[] array;
					lock (dataFile_0)
					{
						lock (dataSeries)
						{
							if (!dataSeries.bool_0())
							{
								dataSeries.method_1();
							}
							if (flag2)
							{
								@class = dataSeries.method_16(num, null);
							}
							else
							{
								@class = dataSeries.method_17(new DateTime(num), null, (DataSeries.Enum1)0);
							}
							if (@class.changed())
							{
								array = @class.WriteObjectData(true);
							}
							else
							{
								array = @class.method_1(false);
							}
						}
					}
					memoryStream = new MemoryStream();
					binaryWriter2 = new BinaryWriter(memoryStream);
					binaryWriter2.Write(dataSeries.count());
					binaryWriter2.Write(dataSeries.dateTime1().Ticks);
					binaryWriter2.Write(dataSeries.dateTime2().Ticks);
					binaryWriter2.Write(@class.int_4());
					binaryWriter2.Write(@class.long_1());
					binaryWriter2.Write(@class.long_2());
					binaryWriter2.Write(@class.dateTime_1().Ticks);
					binaryWriter2.Write(@class.dateTime_2().Ticks);
					binaryWriter2.Write(@class.byte_1());
					binaryWriter2.Write(array.Length);
					stream.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
					stream.Write(array, 0, array.Length);
					break;
				}
				case 7:
					goto IL_55A;
				case 8:
					goto IL_511;
				case 9:
					goto IL_4D8;
				case 10:
					goto IL_464;
				case 11:
					goto IL_3E6;
				case 12:
				{
					int id2 = binaryReader.ReadInt32();
					long index = binaryReader.ReadInt64();
					DataSeries dataSeries2 = m_idArray[id2];
					lock (dataFile_0)
					{
						lock (dataSeries2)
						{
							dataSeries2.Remove(index);
						}
						break;
					}
					goto IL_3E6;
				}
				case 13:
				{
					text = binaryReader.ReadString();
					DataSeries dataSeries3 = new DataSeries(text);
					lock (dataFile_0)
					{
						lock (dataSeries3)
						{
							dataFile_0.Write(text, dataSeries3);
						}
					}
					int_0++;
					m_idArray[int_0] = dataSeries3;
					binaryWriter.Write(int_0);
					break;
				}
				case 14:
				{
					int id3 = binaryReader.ReadInt32();
					DataSeries dataSeries4 = m_idArray[id3];
					memoryStream = new MemoryStream();
					binaryWriter2 = new BinaryWriter(memoryStream);
					lock (dataSeries4)
					{
						binaryWriter2.Write(dataSeries4.count());
						binaryWriter2.Write(dataSeries4.dateTime1().Ticks);
						binaryWriter2.Write(dataSeries4.dateTime2().Ticks);
					}
					stream.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
					break;
				}
				case 15:
					goto IL_23B;
				case 16:
					lock (stream)
					{
						int num2 = binaryReader.ReadInt32();
						int num3 = binaryReader.ReadInt32();
						byte[] array2 = new byte[num3];
						memoryStream = new MemoryStream(array2);
						binaryWriter2 = new BinaryWriter(memoryStream);
						byte[] buffer = new byte[8192];
						int num4 = num3;
						while (num4 != 0)
						{
							int num5;
							if (num4 < 8192)
							{
								num5 = stream.Read(buffer, 0, num4);
							}
							else
							{
								num5 = stream.Read(buffer, 0, 8192);
							}
							if (num5 == 0)
							{
								break;
							}
							num4 -= num5;
							memoryStream.Write(buffer, 0, num5);
						}
						array2 = quickLZ_0.Decompress(array2);
						memoryStream = new MemoryStream(array2);
						BinaryReader binaryReader2 = new BinaryReader(memoryStream);
						DataObject obj5 = null;
						long index2 = 0L;
						for (int i = 0; i < num2; i++)
						{
							int num6 = (int)binaryReader2.ReadByte();
							int id4 = binaryReader2.ReadInt32();
							if (num6 != 12)
							{
								obj5 = (DataObject)streamerManager_0.Deserialize(binaryReader2);
							}
							if (num6 != 10)
							{
								index2 = binaryReader2.ReadInt64();
							}
							DataSeries dataSeries5 = m_idArray[id4];
							lock (dataFile_0)
							{
								lock (dataSeries5)
								{
									switch (num6)
									{
										case 10:
											dataSeries5.Add(obj5);
											break;
										case 11:
											dataSeries5.Update(index2, obj5);
											break;
										case 12:
											dataSeries5.Remove(index2);
											break;
									}
								}
							}
						}
						break;
					}
					goto IL_23B;
			}
			IL_97D:
			if (b == 1)
			{
				break;
			}
			continue;
			IL_23B:
			int id5 = binaryReader.ReadInt32();
			DataSeries dataSeries6 = m_idArray[id5];
			dataSeries6.Clear();
			goto IL_97D;
			IL_3E6:
			int id6 = binaryReader.ReadInt32();
			long index3 = binaryReader.ReadInt64();
			DataObject obj6 = (DataObject)streamerManager_0.Deserialize(binaryReader);
			DataSeries dataSeries7 = m_idArray[id6];
			lock (dataFile_0)
			{
				lock (dataSeries7)
				{
					dataSeries7.Update(index3, obj6);
				}
				goto IL_97D;
			}
			IL_464:
			int id7 = binaryReader.ReadInt32();
			DataObject obj7 = (DataObject)streamerManager_0.Deserialize(binaryReader);
			DataSeries dataSeries8 = m_idArray[id7];
			lock (dataFile_0)
			{
				lock (dataSeries8)
				{
					dataSeries8.Add(obj7);
				}
				goto IL_97D;
			}
			IL_4D8:
			text = binaryReader.ReadString();
			lock (dataFile_0)
			{
				dataFile_0.Delete(text);
				goto IL_97D;
			}
			IL_511:
			text = binaryReader.ReadString();
			object obj8 = streamerManager_0.Deserialize(binaryReader);
			lock (dataFile_0)
			{
				dataFile_0.Write(text, obj8);
				goto IL_97D;
			}
			IL_55A:
			text = binaryReader.ReadString();
			byte[] array3 = null;
			int num7 = -1;
			ObjectKey objectKey;
			lock (dataFile_0)
			{
				objectKey = dataFile_0.keys()[text];
				if (objectKey != null)
				{
					array3 = objectKey.method_1(false);
					if (objectKey.typeId() == 101)
					{
						num7 = int_0++;
						lock (dataFile_0)
						{
							m_idArray[num7] = (DataSeries)objectKey.GetObject();
							goto IL_5FA;
						}
					}
					num7 = 1;
				}
				IL_5FA:;
			}
			memoryStream = new MemoryStream();
			binaryWriter2 = new BinaryWriter(memoryStream);
			binaryWriter2.Write(num7);
			if (objectKey != null)
			{
				binaryWriter2.Write(objectKey.typeId());
				binaryWriter2.Write(objectKey.byte_1());
				binaryWriter2.Write(array3.Length);
				stream.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
			}
			stream.Write(array3, 0, array3.Length);
			goto IL_97D;
			IL_83D:
			Console.WriteLine(DateTime.Now + " Flush file " + dataFile_0.string_1());
			lock (dataFile_0)
			{
				dataFile_0.Flush();
				goto IL_97D;
			}
			IL_890:
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
			dataFile_0 = dataFileManager_0.GetFile(text, fileMode);
			lock (dataFile_0)
			{
				binaryWriter.Write(dataFile_0.bool_0());
				Class51 obj10 = new Class51(dataFile_0.keys());
				memoryStream = new MemoryStream();
				binaryWriter2 = new BinaryWriter(memoryStream);
				streamerManager_0.Serialize(binaryWriter2, obj10);
			}
			stream.Write(memoryStream.GetBuffer(), 0, (int)memoryStream.Length);
			goto IL_97D;
		}
	}
	catch (Exception value)
	{
		Console.WriteLine(DateTime.Now + " ServerClient exception " + dataFile_0.string_1());
		Console.WriteLine(value);
	}
	finally
	{
		Console.WriteLine(DateTime.Now + " Closing connection for " + dataFile_0.string_1());
		if (dataFile_0 != null)
		{
			lock (dataFile_0)
			{
				dataFile_0.Flush();
			}
		}
		tcpClient_0.Close();
	}
}


// Pubic API 

DataFileServerClient_::DataFileServerClient_(const TcpClient& client, const DataFileManager& fileManager)
	: d_ptr(new DataFileServerClient_Private(client, fileManager))
{
}

DataFileServerClient_::~DataFileServerClient_()
{
}

DataFileServerClient_::DataFileServerClient_ (const DataFileServerClient_ &other)
	: d_ptr(other.d_ptr)
{
}

DataFileServerClient_& DataFileServerClient_::operator=(const DataFileServerClient_ &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataFileServerClient_::operator==(const DataFileServerClient_ &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const DataFileServerClient_& datafileserverclient_)
{
	return dbg << datafileserverclient_.toString();
}

