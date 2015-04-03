#include <QuantKit/DataSeries.h>

#include "DataFile_p.h"
#include "ObjectKey_p.h"
#include "DataObject_p.h"
#include <QuantKit/IdArray.h>
#include "DataSeries_p.h"

using namespace QuantKit;

DataSeriesPrivate::DataSeriesPrivate()
	: long_1(-1L)
	, long_2(-1L)
	, long_3(-1L)
{
}

DataSeriesPrivate::DataSeriesPrivate(const QString& name)
	: m_name(name)
	, long_1(-1L)
	, long_2(-1L)
	, long_3(-1L)
{
}

DataSeriesPrivate::~DataSeriesPrivate ()
{
}

int getInt_0() const
{
	return 0;
}
void setInt_0(int value)
{
}

long getLong_1() const
{
	return 0;
}
void setLong_1(long value)
{
}

long getLong_2() const
{
	return 0;
}
void setLong_2(long value)
{
}

Class44 getClass44_0() const
{
	return null;
}
void setClass44_0(Class44 value)
{
}

long getLong_3() const
{
	return 0;
}
void setLong_3(long value)
{
}

bool getBool_0() const
{
	return false;
}

bool getBool_3() const
{
	return false;
}
void DataSeriesPrivate::add(const DataObject& obj)
{
	if (obj.entryDate().Ticks == 0L)
	{
		Console.WriteLine("DataSeries::Add Error: can not add object with DateTime = 0");
		return;
	}
	if (!bool_1)
	{
		method_2();
	}
	m_count += 1L;
	if (m_count == 1L)
	{
		m_dateTime1 = obj.entryDate();
		m_dateTime2 = obj.entryDate();
	}
	else
	{
		if (obj.entryDate() < m_dateTime2)
		{
			method_5(obj);
			return;
		}
		m_dateTime2 = obj.dateTime();
	}
	if (class44_1.int_4() == class44_1.int_3())
	{
		method_7(class44_1);
		if (!m_cacheObjects && class44_1 != class44_0 && class44_1 != class44_3 && class44_1 != class44_2)
		{
			class44_1.setDataObject_0() = null;
		}
		class44_1 = new Class44(dataFile_0, null, class44_1.long_0(), -1L);
		class44_1.setInt_5() = int_0;
		class44_1.setLong_1() = m_count - 1L;
		class44_1.setLong_2() = m_count - 1L;
		class44_1.setChanged() = true;
		int_0++;
		m_idArray[class44_1.int_5()] = class44_1;
	}
	class44_1.method_2(obj);
	bool_3 = true;
	dataFile_0.setBool_1() = true;
}

void DataSeriesPrivate::clear()
{
	if (m_idArray == null)
	{
		method_3();
	}
	if (long_1 != -1L)
	{
		Class44 @class = method_13(long_1);
		while (true)
		{
			dataFile_0.method_2(@class, false);
			if (@class.long_4() == -1L)
			{
				break;
			}
			@class = method_13(@class.long_4());
		}
	}
	m_count = 0L;
	int_0 = 0;
	m_dateTime1 = new DateTime(0L);
	m_dateTime2 = new DateTime(0L);
	long_1 = -1L;
	long_2 = -1L;
	bool_0 = false;
	bool_1 = false;
	m_idArray = new IdArray<Class44>(4096);
	objectKey_1.setClass45_0() = new Class45(m_idArray);
	class44_0 = null;
	class44_1 = null;
	class44_2 = null;
	class44_3 = null;
	bool_3 = true;
	method_18();
}

void DataSeriesPrivate::dump()
{
	Console.WriteLine("Data series " + m_name);
	Console.WriteLine("Count = " + m_count);
	Console.WriteLine("Position1 = " + long_1);
	Console.WriteLine("Position2 = " + long_2);
	Console.WriteLine("DateTime1 = " + m_dateTime1.Ticks);
	Console.WriteLine("DateTime2 = " + m_dateTime2.Ticks);
	Console.WriteLine("Buffer count = " + int_0);
	Console.WriteLine();
	Console.WriteLine("Keys in cache:");
	Console.WriteLine();
	if (m_idArray != null)
	{
		for (int i = 0; i < int_0; i++)
		{
			if (m_idArray[i] != null)
			{
				Console.WriteLine(m_idArray[i]);
			}
		}
	}
	Console.WriteLine();
	Console.WriteLine("Keys on disk:");
	Console.WriteLine();
	if (long_1 != -1L)
	{
		Class44 @class = method_13(long_1);
		while (true)
		{
			Console.WriteLine(@class);
			if (@class.long_4() == -1L)
			{
				break;
			}
			@class = method_13(@class.long_4());
		}
	}
	Console.WriteLine();
	if (class44_1 != null)
	{
		Console.WriteLine("Write Key : " + bool_3);
	}
	else
	{
		Console.WriteLine("Write Key : null");
	}
	Console.WriteLine();
	Console.WriteLine("End dump");
	Console.WriteLine();
}

DataObject DataSeriesPrivate::get(long index)
{
	if (!bool_0)
	{
		method_1();
	}
	Class44 @class = method_16(index, class44_0);
	if (@class == null)
	{
		return null;
	}
	if (@class != class44_0)
	{
		if (!m_cacheObjects && class44_0 != null && class44_0 != class44_1 && class44_0 != class44_3 && class44_0 != class44_2)
		{
			class44_0.setDataObject_0() = null;
		}
		class44_0 = @class;
	}
	return @class.method_5()[(int)checked((IntPtr)unchecked(index - @class.long_1()))];
}

DataObject DataSeriesPrivate::get(const QDateTime& dateTime)
{
	if (!bool_0)
	{
		method_1();
	}
	if (m_count == 0L || dateTime > m_dateTime2)
	{
		Console.WriteLine("DataSeries::Get dateTime is out of range : " + dateTime);
		return null;
	}
	if (dateTime <= m_dateTime1)
	{
		return Get(0L);
	}
	Class44 @class = method_17(dateTime, class44_0, (DataSeries.Enum1)0);
	if (@class == null)
	{
		return null;
	}
	if (@class != class44_0)
	{
		if (!m_cacheObjects && class44_0 != null && class44_0 != class44_1 && class44_0 != class44_3 && class44_0 != class44_2)
		{
			class44_0.setDataObject_0() = null;
		}
		class44_0 = @class;
	}
	return class44_0.method_7(dateTime);
}

long DataSeriesPrivate::getIndex(const QDateTime& dateTime, SearchOption option)
{
	if (!bool_0)
	{
		method_1();
	}
	if (m_count == 0L)
	{
		Console.WriteLine("DataSeries::GetIndex Error, data series has no elements " + m_name);
		return -1L;
	}
	if (dateTime <= m_dateTime1)
	{
		return 0L;
	}
	if (dateTime >= m_dateTime2)
	{
		return m_count - 1L;
	}
	Class44 @class = method_17(dateTime, class44_0, (DataSeries.Enum1)0);
	if (@class == null)
	{
		return -1L;
	}
	if (@class != class44_0)
	{
		if (!m_cacheObjects && class44_0 != null && class44_0 != class44_1 && class44_0 != class44_3 && class44_0 != class44_2)
		{
			class44_0.setDataObject_0() = null;
		}
		class44_0 = @class;
	}
	return class44_0.long_1() + (long)class44_0.method_8(dateTime, option);
}

void DataSeriesPrivate::refresh()
{
}

void DataSeriesPrivate::remove(long index)
{
	if (!bool_1)
	{
		method_2();
	}
	Class44 @class = method_16(index, class44_2);
	if (@class == null)
	{
		return;
	}
	if (class44_2 == null)
	{
		class44_2 = @class;
	}
	else
	{
		if (class44_2 != @class)
		{
			if (class44_2.changed())
			{
				method_7(class44_2);
			}
			if (!m_cacheObjects && class44_2 != class44_0 && class44_2 != class44_1 && class44_2 != class44_3)
			{
				class44_2.setDataObject_0() = null;
			}
			class44_2 = @class;
		}
	}
	@class.method_4(index - @class.long_1());
	@class.setLong_2() -= 1L;
	if (class44_0 != null && class44_0.int_5() > @class.int_5())
	{
		class44_0.setLong_1() -= 1L;
		class44_0.setLong_2() -= 1L;
	}
	if (class44_1 != null && class44_1.int_5() > @class.int_5())
	{
		class44_1.setLong_1() -= 1L;
		class44_1.setLong_2() -= 1L;
	}
	if (class44_3 != null && class44_3.int_5() > @class.int_5())
	{
		class44_3.setLong_1() -= 1L;
		class44_3.setLong_2() -= 1L;
	}
	if (@class.int_4() == 0)
	{
		method_12(@class);
		class44_2 = null;
	}
	m_count -= 1L;
	bool_3 = true;
	dataFile_0.setBool_1() = true;
}

void DataSeriesPrivate::update(long index, const DataObject& obj)
{
	DataObject dataObject = Get(index);
	if (dataObject.entryDate() != obj.entryDate())
	{
		Console.WriteLine("DataSeries::Update Can not update object with different datetime");
		return;
	}
	bool changed = class44_0.changed();
	class44_0.method_3((int)(index - class44_0.long_1()), obj);
	if (!changed)
	{
		method_7(class44_0);
	}
	dataFile_0.setBool_1() = true;
}

//protected
void DataSeriesPrivate::method_0(const DataFile& dataFile_1, const ObjectKey& objectKey_2)
{
	dataFile_0 = dataFile_1;
	objectKey_0 = objectKey_2;
	objectKey_2.setByte_1() = 0;
	objectKey_2.setByte_0() = 0;
	if (long_3 == -1L)
	{
		if (int_0 < 4096)
		{
			m_idArray = new IdArray<Class44>(4096);
		}
		else
		{
			m_idArray = new IdArray<Class44>(int_0);
		}
		objectKey_1 = new ObjectKey(dataFile_1, "", new Class45(m_idArray));
	}
}

void DataSeriesPrivate::method_1()
{
	if (bool_0)
	{
		Console.WriteLine("DataSeries::OpenRead already read open");
		return;
	}
	if (m_idArray == null)
	{
		method_3();
	}
	bool_0 = true;
}

Class44 DataSeriesPrivate::method_16(long long_4, Class44 class44_4)
{
	if (long_4 >= 0L && long_4 < m_count)
	{
		if (class44_4 == null)
		{
			class44_4 = class44_0;
		}
		Class44 @class = null;
		if (class44_4 != null)
		{
			if (long_4 >= class44_4.long_1() && long_4 <= class44_4.long_2())
			{
				return class44_4;
			}
			if (long_4 > class44_4.long_2())
			{
				@class = method_15(class44_4);
			}
		}
		if (@class == null)
		{
			@class = method_14();
		}
		while (long_4 < @class.long_1() || long_4 > @class.long_2())
		{
			@class = method_15(@class);
		}
		return @class;
	}
	Console.WriteLine("DataSeries::GetIndex Error: index is out of range : " + long_4);
	return null;
}

Class44 DataSeriesPrivate::method_17(const QDateTime& dateTime_2, Class44 class44_4, Enum1 enum1)
{
	if (m_count == 0L || dateTime_2 > m_dateTime2)
	{
		Console.WriteLine("DataSeries::GetKey dateTime is out of range : " + dateTime_2);
		return null;
	}
	if (class44_4 == null)
	{
		class44_4 = class44_0;
	}
	Class44 @class = null;
	Class44 class2 = null;
	if (dateTime_2 <= m_dateTime1)
	{
		return method_14();
	}
	if (class44_4 != null)
	{
		if (dateTime_2 >= class44_4.dateTime_1() && dateTime_2 <= class44_4.dateTime_2())
		{
			return class44_4;
		}
		if (dateTime_2 > class44_4.dateTime_2())
		{
			class2 = class44_4;
			@class = method_15(class2);
		}
	}
	if (@class == null)
	{
		@class = method_14();
	}
	while (enum1 == (DataSeries.Enum1)0 || class2 == null || !(dateTime_2 > class2.dateTime_2()) || !(dateTime_2 < @class.dateTime_1()))
	{
		if (dateTime_2 >= @class.dateTime_1() && dateTime_2 <= @class.dateTime_2())
		{
			return @class;
		}
		class2 = @class;
		@class = method_15(class2);
	}
	if (enum1 == (DataSeries.Enum1)2)
	{
		return @class;
	}
	return class2;
}

void DataSeriesPrivate::method_18()
{
	if (bool_3)
	{
		if (class44_3 != null && class44_3.changed())
		{
			method_7(class44_3);
		}
		if (class44_1 != null && class44_1.changed())
		{
			method_7(class44_1);
		}
		if (class44_2 != null && class44_2.changed())
		{
			method_7(class44_2);
		}
		method_4();
		dataFile_0.method_4(objectKey_0);
		bool_3 = false;
	}
}

void DataSeriesPrivate::method_2()
{
	if (bool_1)
	{
		Console.WriteLine("DataSeries::OpenWrite already write open");
		return;
	}
	if (m_idArray == null)
	{
		method_3();
	}
	if (int_0 != 0 && m_idArray[int_0 - 1] != null)
	{
		class44_1 = m_idArray[int_0 - 1];
		class44_1.method_5();
	}
	else
	{
		if (long_2 != -1L)
		{
			class44_1 = method_13(long_2);
			class44_1.setInt_5() = int_0 - 1;
			class44_1.method_5();
		}
		else
		{
			class44_1 = new Class44(dataFile_0, null, -1L, -1L);
			class44_1.setInt_5() = 0;
			class44_1.setChanged() = true;
			int_0 = 1;
		}
		m_idArray[class44_1.int_5()] = class44_1;
	}
	bool_1 = true;
}

void DataSeriesPrivate::method_10(long long_4, long long_5)
{
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	binaryWriter.Write(long_5);
	dataFile_0.WriteBuffer(memoryStream.GetBuffer(), long_4 + 61L, 8);
}

void DataSeriesPrivate::method_11(long long_4, long long_5)
{
	MemoryStream memoryStream = new MemoryStream();
	BinaryWriter binaryWriter = new BinaryWriter(memoryStream);
	binaryWriter.Write(long_5);
	dataFile_0.WriteBuffer(memoryStream.GetBuffer(), long_4 + 69L, 8);
}

void DataSeriesPrivate::method_12(const Class44& class44_4)
{
	if (class44_4.long_0() == long_2)
	{
		if (class44_4.long_3() != -1L)
		{
			long_2 = class44_4.long_3();
		}
		else
		{
			long_1 = -1L;
			long_2 = -1L;
		}
	}
	dataFile_0.method_2(class44_4, false);
	if (class44_4.long_3() != -1L)
	{
		Class44 @class = m_idArray[class44_4.int_5() - 1];
		if (@class != null)
		{
			@class.setLong_4() = class44_4.long_4();
			if (!@class.changed())
			{
				method_11(class44_4.long_3(), class44_4.long_4());
			}
		}
		else
		{
			method_11(class44_4.long_3(), class44_4.long_4());
		}
	}
	if (class44_4.long_4() != -1L)
	{
		Class44 class2 = m_idArray[class44_4.int_5() + 1];
		if (class2 != null)
		{
			class2.setLong_3() = class44_4.long_3();
			if (!class2.changed())
			{
				method_10(class44_4.long_4(), class44_4.long_3());
			}
		}
		else
		{
			method_10(class44_4.long_4(), class44_4.long_3());
		}
	}
	for (int i = class44_4.int_5(); i < int_0 - 1; i++)
	{
		m_idArray[i] = m_idArray[i + 1];
		if (m_idArray[i] != null)
		{
			m_idArray[i].setInt_5() = i;
		}
	}
	int_0--;
	dataFile_0.method_4(objectKey_0);
}

Class44 DataSeriesPrivate::method_13(long long_4)
{
	byte[] buffer = new byte[79];
	MemoryStream input = new MemoryStream(buffer);
	BinaryReader reader = new BinaryReader(input);
	dataFile_0.ReadBuffer(buffer, long_4, 77);
	Class44 @class = new Class44(dataFile_0, null, -1L, -1L);
	@class.Read(reader, true);
	@class.setLong_0() = long_4;
	return @class;
}

Class44 DataSeriesPrivate::method_14()
{
	Class44 @class = m_idArray[0];
	if (@class == null)
	{
		@class = method_13(long_1);
		m_idArray[0] = @class;
	}
	@class.setInt_5() = 0;
	@class.setLong_1() = 0L;
	@class.setLong_2() = (long)(@class.int_4() - 1);
	return @class;
}

Class44 DataSeriesPrivate::method_15(const Class44& class44_4)
{
	if (class44_4.int_5() == -1)
	{
		Console.WriteLine("DataSeries::GetNextKey Error: key.number is not set");
	}
	Class44 @class = m_idArray[class44_4.int_5() + 1];
	if (@class == null)
	{
		if (class44_4.long_4() == -1L)
		{
			Console.WriteLine("DataSeries::GetNextKey Error: key.next is not set");
		}
		@class = method_13(class44_4.long_4());
		@class.setInt_5() = class44_4.int_5() + 1;
		m_idArray[@class.int_5()] = @class;
	}
	@class.setLong_1() = class44_4.long_2() + 1L;
	@class.setLong_2() = @class.long_1() + (long)@class.int_4() - 1L;
	return @class;
}

void DataSeriesPrivate::method_3()
{
	objectKey_1 = dataFile_0.method_3(long_3, 38);
	m_idArray = ((Class45)objectKey_1.GetObject()).idArray_0();
	for (int i = 0; i < m_idArray.Size; i++)
	{
		if (m_idArray[i] != null)
		{
			m_idArray[i].setDataFile_0() = dataFile_0;
			m_idArray[i].setInt_5() = i;
		}
	}
}

void DataSeriesPrivate::method_4()
{
	if (objectKey_1 == null)
	{
		objectKey_1 = new ObjectKey(dataFile_0, "", new Class45(m_idArray));
	}
	dataFile_0.method_4(objectKey_1);
	long_3 = objectKey_1.long_0();
}

void DataSeriesPrivate::method_5(const DataObject& dataObject)
{
	if (dataObject.entryDate() >= class44_1.dateTime_1() && dataObject.entryDate() <= class44_1.dateTime_2())
	{
		class44_1.method_2(dataObject);
		if (class44_1.int_4() == class44_1.int_3())
		{
			method_7(class44_1);
			class44_1 = new Class44(dataFile_0, null, class44_1.long_0(), -1L);
			class44_1.setInt_5() = int_0;
			class44_1.setLong_1() = m_count;
			class44_1.setLong_2() = m_count;
			class44_1.setChanged() = true;
			int_0++;
			m_idArray[class44_1.int_5()] = class44_1;
		}
		else
		{
			bool_3 = true;
		}
		dataFile_0.setBool_1() = true;
		return;
	}
	Class44 @class = method_17(dataObject.entryDate(), class44_3, (DataSeries.Enum1)1);
	if (class44_3 == null)
	{
		class44_3 = @class;
	}
	else
	{
		if (class44_3 != @class)
		{
			if (class44_3.changed())
			{
				method_7(class44_3);
			}
			if (!m_cacheObjects && class44_3 != class44_0 && class44_3 != class44_1 && class44_3 != class44_2)
			{
				class44_3.setDataObject_0() = null;
			}
			class44_3 = @class;
		}
	}
	class44_3.method_5();
	if (class44_3.int_4() < class44_3.int_3())
	{
		class44_3.method_2(dataObject);
		if (class44_3.int_4() == class44_3.int_3())
		{
			method_7(class44_3);
		}
	}
	else
	{
		@class = new Class44(dataFile_0, null, -1L, -1L);
		int num = class44_3.method_8(dataObject.entryDate(), SearchOption.Next);
		if (num == -1)
		{
			@class.method_2(dataObject);
		}
		else
		{
			for (int i = num; i < class44_3.int_4(); i++)
			{
				@class.method_2(class44_3.dataObject_0()[i]);
				class44_3.dataObject_0()[i] = null;
			}
			class44_3.setInt_4() = num;
			class44_3.setLong_2() = class44_3.long_1() + (long)class44_3.int_4() - 1L;
			if (class44_3.int_4() != 0)
			{
				class44_3.setDateTime_2() = class44_3.dataObject_0()[class44_3.int_4() - 1].entryDate();
			}
			class44_3.method_2(dataObject);
		}
		method_6(@class, class44_3);
	}
	if (class44_0 != null && class44_0.int_5() > class44_3.int_5())
	{
		class44_0.setLong_1() += 1L;
		class44_0.setLong_2() += 1L;
	}
	if (class44_1 != null && class44_1.int_5() > class44_3.int_5())
	{
		class44_1.setLong_1() += 1L;
		class44_1.setLong_2() += 1L;
	}
	if (class44_2 != null && class44_2.int_5() > class44_3.int_5())
	{
		class44_2.setLong_1() += 1L;
		class44_2.setLong_2() += 1L;
	}
	class44_3.setChanged() = true;
	bool_3 = true;
	dataFile_0.setBool_1() = true;
}

void DataSeriesPrivate::method_6(const Class44& class44_4, const Class44& class44_5)
{
	for (int i = int_0; i > class44_5.int_5() + 1; i--)
	{
		m_idArray[i] = m_idArray[i - 1];
		if (m_idArray[i] != null)
		{
			m_idArray[i].setInt_5() = i;
		}
	}
	int_0++;
	class44_4.setInt_5() = class44_5.int_5() + 1;
	m_idArray[class44_4.int_5()] = class44_4;
	class44_4.setLong_3() = class44_5.long_0();
	class44_4.setLong_4() = class44_5.long_4();
	method_7(class44_4);
	dataFile_0.method_4(objectKey_0);
}

void DataSeriesPrivate::method_7(const Class44& class44_4)
{
	long long_ = class44_4.long_0();
	dataFile_0.method_4(class44_4);
	if (class44_4.long_0() != long_)
	{
		Class44 @class = null;
		if (class44_4.int_5() != 0)
		{
			@class = m_idArray[class44_4.int_5() - 1];
		}
		if (@class != null)
		{
			@class.setLong_4() = class44_4.long_0();
			if (!@class.changed())
			{
				method_11(class44_4.long_3(), class44_4.long_0());
			}
		}
		else
		{
			if (class44_4.long_3() != -1L)
			{
				method_11(class44_4.long_3(), class44_4.long_0());
			}
		}
		Class44 class2 = null;
		if (class44_4.int_5() != int_0 - 1)
		{
			class2 = m_idArray[class44_4.int_5() + 1];
		}
		if (class2 != null)
		{
			class2.setLong_3() = class44_4.long_0();
			if (!class2.changed())
			{
				method_10(class44_4.long_4(), class44_4.long_0());
			}
		}
		else
		{
			if (class44_4.long_4() != -1L)
			{
				method_10(class44_4.long_4(), class44_4.long_0());
			}
		}
	}
	if (class44_4 == class44_1)
	{
		if (long_1 == -1L)
		{
			long_1 = class44_1.long_0();
		}
		long_2 = class44_1.long_0();
	}
	dataFile_0.method_4(objectKey_0);
}

void DataSeriesPrivate::method_8(const Class44& class44_4, long long_4)
{
	class44_4.setLong_3() = long_4;
	method_10(class44_4.long_0(), long_4);
}

void DataSeriesPrivate::method_9(const Class44& class44_4, long long_4)
{
	class44_4.setLong_4() = long_4;
	method_11(class44_4.long_0(), long_4);
}


// Pubic API 

DataSeries::DataSeries()
	: d_ptr(new DataSeriesPrivate)
{
}

DataSeries::DataSeries(const QString& name)
	: d_ptr(new DataSeriesPrivate(name))
{
}

DataSeries::~DataSeries()
{
}

DataSeries::DataSeries (DataSeriesPrivate &dd)
	: d_ptr(&dd)
{
}

DataSeries::DataSeries (const DataSeries &other)
	: d_ptr(other.d_ptr)
{
}

DataSeries& DataSeries::operator=(const DataSeries &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataSeries::operator==(const DataSeries &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
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

long long_1() const
{
	return d_ptr->
	setLong_1()
}

void setLong_1(long value)
{
	d_ptr->long_1(value);
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

Class44 class44_0() const
{
	return d_ptr->
	setClass44_0()
}

void setClass44_0(Class44 value)
{
	d_ptr->class44_0(value);
}

long long_3() const
{
	return d_ptr->
	setLong_3()
}

void setLong_3(long value)
{
	d_ptr->long_3(value);
}

bool bool_0() const
{
	return d_ptr->
	setBool_0()
}

bool bool_3() const
{
	return d_ptr->
	setBool_3()
}

QString DataSeries::name() const
{
	return d_ptr->name();
}

QString DataSeries::description() const
{
	return d_ptr->description();
}

long DataSeries::count() const
{
	return d_ptr->count();
}

QDateTime DataSeries::dateTime1() const
{
	return d_ptr->dateTime1();
}

QDateTime DataSeries::dateTime2() const
{
	return d_ptr->dateTime2();
}

bool DataSeries::cacheObjects() const
{
	return d_ptr->cacheObjects();
}

void DataSeries::setCacheObjects(bool value)
{
	d_ptr->setCacheObjects(value);
}

DataObject DataSeries::item(long index) const
{
	return d_ptr->item(index);
}

DataObject DataSeries::item(const QDateTime& dateTime) const
{
	return d_ptr->item(dateTime);
}

void DataSeries::add(const DataObject& obj)
{
	d_ptr->add(obj);
}

void DataSeries::clear()
{
	d_ptr->clear();
}

bool DataSeries::contains(const QDateTime& dateTime)
{
	return d_ptr->contains(dateTime);
}

void DataSeries::dump()
{
	d_ptr->dump();
}

DataObject DataSeries::get(long index)
{
	return d_ptr->get(index);
}

DataObject DataSeries::get(const QDateTime& dateTime)
{
	return d_ptr->get(dateTime);
}

long DataSeries::getIndex(const QDateTime& dateTime, SearchOption option)
{
	return d_ptr->getIndex(dateTime, option);
}

void DataSeries::refresh()
{
	d_ptr->refresh();
}

void DataSeries::remove(long index)
{
	d_ptr->remove(index);
}

QString DataSeries::toString() const
{
	return d_ptr->toString();
}

void DataSeries::update(long index, const DataObject& obj)
{
	d_ptr->update(index, obj);
}

QDebug operator<<(QDebug dbg, const DataSeries& dataseries)
{
	return dbg << dataseries.toString();
}

