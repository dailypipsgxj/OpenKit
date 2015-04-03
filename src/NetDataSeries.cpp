#include <QuantKit/NetDataSeries.h>

#include <QuantKit/NetDataFile_.h>
#include "DataSeries_p.h"
#include "DataObject_p.h"
#include "DataSeries_p.h"

namespace QuantKit {

class NetDataSeriesPrivate : public DataSeriesPrivate
{
public:
	NetDataFile_ netDataFile__0;
	int int_1;

public:
	explicit NetDataSeriesPrivate(const QString& name) { m_name = name; }
	NetDataSeriesPrivate(const NetDataFile_& file, int id, const DataSeries& series);
	virtual ~NetDataSeriesPrivate();

public:
	NetDataFile_ getNetDataFile__0() const;
	void setNetDataFile__0(NetDataFile_ value);

	int getInt_1() const;
	void setInt_1(int value);
	virtual void add(const DataObject& obj) Q_DECL_OVERRIDE;
	virtual void clear() Q_DECL_OVERRIDE;
	virtual DataObject get(long index) Q_DECL_OVERRIDE;
	virtual DataObject get(const QDateTime& dateTime) Q_DECL_OVERRIDE;
	virtual long getIndex(const QDateTime& dateTime, SearchOption option) Q_DECL_OVERRIDE;
	virtual void refresh() Q_DECL_OVERRIDE;
	virtual void remove(long index) Q_DECL_OVERRIDE;
	virtual void update(long index, const DataObject& obj) Q_DECL_OVERRIDE;
	virtual NetDataSeriesPrivate* clone() Q_DECL_OVERRIDE { return new NetDataSeriesPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

NetDataSeriesPrivate::NetDataSeriesPrivate(const NetDataFile_& file, int id, const DataSeries& series)
	: netDataFile__0(file)
	, int_1(id)
{
		m_name = series.name();
		m_count = series.count();
		m_dateTime1 = series.dateTime1();
		m_dateTime2 = series.dateTime2();
}

NetDataSeriesPrivate::~NetDataSeriesPrivate ()
{
}

NetDataFile_ getNetDataFile__0() const
{
	return null;
}
void setNetDataFile__0(NetDataFile_ value)
{
}

int getInt_1() const
{
	return 0;
}
void setInt_1(int value)
{
}
void NetDataSeriesPrivate::add(const DataObject& obj)
{
	netDataFile__0.method_9(new Class42(10, int_1, obj, 0L));
	m_count += 1L;
	if (obj.entryDate() > m_dateTime2)
	{
		m_dateTime2 = obj.entryDate();
	}
	else
	{
		if (obj.entryDate() < m_dateTime1)
		{
			m_dateTime1 = obj.entryDate();
		}
	}
	class44_0 = null;
}

void NetDataSeriesPrivate::clear()
{
	netDataFile__0.Clear(this);
	m_count = 0L;
	m_dateTime1 = new DateTime(0L);
	m_dateTime2 = new DateTime(0L);
	class44_0 = null;
}

DataObject NetDataSeriesPrivate::get(long index)
{
	if (class44_0 == null || index > class44_0.long_2() || index < class44_0.long_1())
	{
		class44_0 = netDataFile__0.method_10(this, index, true);
	}
	return class44_0.dataObject_0()[(int)checked((IntPtr)unchecked(index - class44_0.long_1()))];
}

DataObject NetDataSeriesPrivate::get(const QDateTime& dateTime)
{
	if (class44_0 == null || dateTime > class44_0.dateTime_2() || dateTime < class44_0.dateTime_1())
	{
		class44_0 = netDataFile__0.method_10(this, dateTime.Ticks, false);
	}
	return class44_0.method_7(dateTime);
}

long NetDataSeriesPrivate::getIndex(const QDateTime& dateTime, SearchOption option)
{
	if (m_count == 0L)
	{
		Console.WriteLine("NetDataSeries::GetIndex Error, data series has no elements " + m_name);
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
	if (class44_0 == null || dateTime > class44_0.dateTime_2() || dateTime < class44_0.dateTime_1())
	{
		class44_0 = netDataFile__0.method_10(this, dateTime.Ticks, false);
	}
	if (class44_0 == null)
	{
		return -1L;
	}
	return class44_0.long_1() + (long)class44_0.method_8(dateTime, option);
}

void NetDataSeriesPrivate::refresh()
{
	netDataFile__0.Refresh(this);
	class44_0 = null;
}

void NetDataSeriesPrivate::remove(long index)
{
	netDataFile__0.method_9(new Class42(12, int_1, null, index));
	class44_0 = null;
}

void NetDataSeriesPrivate::update(long index, const DataObject& obj)
{
	netDataFile__0.method_9(new Class42(11, int_1, obj, index));
	class44_0 = null;
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(NetDataSeries)

NetDataSeries::NetDataSeries(const QString& name)
	: DataSeries(*new NetDataSeriesPrivate(name))
{
}

NetDataSeries::NetDataSeries(const NetDataFile_& file, int id, const DataSeries& series)
	: DataSeries(*new NetDataSeriesPrivate(file, id, series))
{
}

NetDataSeries::~NetDataSeries()
{
}

NetDataFile_ netDataFile__0() const
{
	return d_ptr->
	setNetDataFile__0()
}

void setNetDataFile__0(NetDataFile_ value)
{
	d_ptr->netDataFile__0(value);
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


