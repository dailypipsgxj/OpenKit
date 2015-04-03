#include <QuantKit/DataSeriesNameHelper.h>

#include <QuantKit/Instrument.h>
#include "DataSeries_p.h"
#include <QuantKit/Framework.h>

namespace QuantKit {

class DataSeriesNameHelperPrivate : public QSharedData
{
public:
	virtual ~DataSeriesNameHelperPrivate();

public:
	unsigned char getDataType(const DataSeries& series);
	Instrument getInstrument(const DataSeries& series, const Framework& framework);
	QString getName(const Instrument& instrument, unsigned char type);
	QString getName(const Instrument& instrument, BarType barType, long barSize);
	QString getSymbol(const DataSeries& series)
	{
		return DataSeriesNameHelper.GetSymbol(series.name());
	}

	QString getSymbol(const QString& seriesName);
	bool tryGetBarTypeSize(const DataSeries& series, BarType& barType, const Int64&& barSize);
	virtual DataSeriesNameHelperPrivate* clone() Q_DECL_OVERRIDE { return new DataSeriesNameHelperPrivate(*this); }
//private:
	QString smethod_0(unsigned char byte);
	QString smethod_1(BarType barType, long long);
};

} // namepsace QuantKit


using namespace QuantKit;

DataSeriesNameHelperPrivate::~DataSeriesNameHelperPrivate ()
{
}

unsigned char DataSeriesNameHelperPrivate::getDataType(const DataSeries& series)
{
	string[] array = series.name().Split(new string[]
	{
		"."
	}, StringSplitOptions.None);
	string key;
	switch (key = array[array.Length - 1])
	{
		case "Tick":
			return 1;
		case "Bid":
			return 2;
		case "Ask":
			return 3;
		case "Quote":
			return 5;
		case "Trade":
			return 4;
		case "Bar":
			return 6;
		case "Level2":
			return 7;
		case "News":
			return 23;
		case "Fundamental":
			return 22;
	}
	return 0;
}

Instrument DataSeriesNameHelperPrivate::getInstrument(const DataSeries& series, const Framework& framework)
{
	string[] array = series.name().Split(new string[]
	{
		"."
	}, StringSplitOptions.None);
	int num = (DataSeriesNameHelper.GetDataType(series) == 6) ? 4 : 2;
	return framework.instrumentManager().GetById(int.Parse(array[array.Length - num]));
}

QString DataSeriesNameHelperPrivate::getName(const Instrument& instrument, unsigned char type)
{
	return string.Concat(new object[]
	{
		instrument.symbol(),
		".",
		instrument.id(),
		".",
		DataSeriesNameHelper.smethod_0(type)
	});
}

QString DataSeriesNameHelperPrivate::getName(const Instrument& instrument, BarType barType, long barSize)
{
	return string.Concat(new object[]
	{
		instrument.symbol(),
		".",
		instrument.id(),
		".",
		DataSeriesNameHelper.smethod_1(barType, barSize)
	});
}

QString DataSeriesNameHelperPrivate::getSymbol(const QString& seriesName)
{
	string[] array = seriesName.Split(new string[]
	{
		"."
	}, StringSplitOptions.None);
	if (array.Length == 1)
	{
		return "";
	}
	int num = (array[array.Length - 1] == "Bar") ? 4 : 2;
	return string.Join(".", array, 0, array.Length - num);
}

bool DataSeriesNameHelperPrivate::tryGetBarTypeSize(const DataSeries& series, BarType& barType, long& barSize)
{
	barType = BarType.Time;
	barSize = 0L;
	string[] array = series.name().Split(new string[]
	{
		"."
	}, StringSplitOptions.None);
	return array.Length >= 3 && DataSeriesNameHelper.GetDataType(series) == 6 && Enum.TryParse<BarType>(array[array.Length - 3], out barType) && long.TryParse(array[array.Length - 2], out barSize);
}

QString DataSeriesNameHelperPrivate::smethod_0(unsigned char byte)
{
	switch (@byte)
	{
		case 1:
			return "Tick";
		case 2:
			return "Bid";
		case 3:
			return "Ask";
		case 4:
			return "Trade";
		case 5:
			return "Quote";
		case 6:
			return "Bar";
		case 7:
		case 8:
		case 9:
			return "Level2";
		default:
			switch (@byte)
			{
				case 22:
					return "Fundamental";
				case 23:
					return "News";
				default:
					return string.Empty;
			}
			break;
	}
}

QString DataSeriesNameHelperPrivate::smethod_1(BarType barType, long long)
{
	return string.Concat(new object[]
	{
		barType,
		".",
		@long,
		".Bar"
	});
}


// Pubic API 

DataSeriesNameHelper::~DataSeriesNameHelper()
{
}

DataSeriesNameHelper::DataSeriesNameHelper (const DataSeriesNameHelper &other)
	: d_ptr(other.d_ptr)
{
}

DataSeriesNameHelper& DataSeriesNameHelper::operator=(const DataSeriesNameHelper &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataSeriesNameHelper::operator==(const DataSeriesNameHelper &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

unsigned char DataSeriesNameHelper::getDataType(const DataSeries& series)
{
	return d_ptr->getDataType(series);
}

Instrument DataSeriesNameHelper::getInstrument(const DataSeries& series, const Framework& framework)
{
	return d_ptr->getInstrument(series, framework);
}

QString DataSeriesNameHelper::getName(const Instrument& instrument, unsigned char type)
{
	return d_ptr->getName(instrument, type);
}

QString DataSeriesNameHelper::getName(const Instrument& instrument, BarType barType, long barSize)
{
	return d_ptr->getName(instrument, barType, barSize);
}

QString DataSeriesNameHelper::getSymbol(const DataSeries& series)
{
	return d_ptr->getSymbol(series);
}

QString DataSeriesNameHelper::getSymbol(const QString& seriesName)
{
	return d_ptr->getSymbol(seriesName);
}

bool DataSeriesNameHelper::tryGetBarTypeSize(const DataSeries& series, BarType& barType, long& barSize)
{
	return d_ptr->tryGetBarTypeSize(series, barType, barSize);
}

QDebug operator<<(QDebug dbg, const DataSeriesNameHelper& dataseriesnamehelper)
{
	return dbg << dataseriesnamehelper.toString();
}

