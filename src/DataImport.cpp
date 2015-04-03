#include <QuantKit/DataImport.h>

#include <QuantKit/Framework.h>

namespace QuantKit {

class DataImportPrivate : public QSharedData
{
public:
	Framework m_framework;

public:
	explicit DataImportPrivate(const Framework& framework);
	virtual ~DataImportPrivate();

public:
	void import(const QString& fileName, const QString& symbol, int type);
	virtual DataImportPrivate* clone() Q_DECL_OVERRIDE { return new DataImportPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataImportPrivate::DataImportPrivate(const Framework& framework)
	: m_framework(framework)
{
}

DataImportPrivate::~DataImportPrivate ()
{
}

void DataImportPrivate::import(const QString& fileName, const QString& symbol, int type)
{
	Console.WriteLine("Starting export: " + fileName + " " + symbol);
	int num = 0;
	int num2 = 0;
	int num3 = 0;
	TextReader textReader = File.OpenText(fileName);
	Instrument instrument = m_framework.instrumentManager().Get(symbol);
	if (instrument == null)
	{
		instrument = new Instrument(InstrumentType.Stock, symbol, "", 148);
		m_framework.instrumentManager().Add(instrument, true);
	}
	int num4 = 0;
	double num5 = -1.0;
	int num6 = -1;
	double num7 = -1.0;
	int num8 = -1;
	textReader.ReadLine();
	while (true)
	{
		string text = textReader.ReadLine();
		if (text == null)
		{
			break;
		}
		string[] array = text.Split(new char[]
		{
			','
		});
		CultureInfo invariantCulture = CultureInfo.InvariantCulture;
		switch (type)
		{
			case 4:
			{
				DateTime dateTime = DateTime.ParseExact(array[0], "yyyy-MM-dd HH:mm:ss.fff", invariantCulture);
				double num9 = double.Parse(array[1], invariantCulture);
				int num10 = int.Parse(array[2]);
				if (num9 > 0.0 && num10 > 0)
				{
					Trade obj = new Trade(dateTime, 1, instrument.id(), num9, num10);
					m_framework.dataManager().Save(instrument, obj, SaveMode.Add);
					num3++;
				}
				break;
			}
			case 5:
			{
				DateTime dateTime2 = DateTime.ParseExact(array[0], "yyyy-MM-dd HH:mm:ss.fff", invariantCulture);
				double num11 = double.Parse(array[1], invariantCulture);
				int num12 = int.Parse(array[2]);
				double num13 = double.Parse(array[3], invariantCulture);
				int num14 = int.Parse(array[4]);
				if (num11 > 0.0 && num12 > 0 && (num5 != num11 || num6 != num12))
				{
					Bid obj2 = new Bid(dateTime2, 1, instrument.id(), num11, num12);
					m_framework.dataManager().Save(instrument, obj2, SaveMode.Add);
					num5 = num11;
					num6 = num12;
					num2++;
				}
				if (num13 > 0.0 && num14 > 0 && (num7 != num13 || num8 != num14))
				{
					Ask obj3 = new Ask(dateTime2, 1, instrument.id(), num13, num14);
					m_framework.dataManager().Save(instrument, obj3, SaveMode.Add);
					num7 = num13;
					num8 = num14;
					num++;
				}
				break;
			}
		}
		if (num4 % 100000 == 0)
		{
			Console.WriteLine(num4);
		}
		num4++;
	}
	Console.WriteLine(string.Concat(new object[]
	{
		"Lines = ",
		num4,
		" bids: ",
		num2,
		" asks: ",
		num,
		" trades: ",
		num3
	}));
	textReader.Close();
}


// Pubic API 

DataImport::DataImport(const Framework& framework)
	: d_ptr(new DataImportPrivate(framework))
{
}

DataImport::~DataImport()
{
}

DataImport::DataImport (const DataImport &other)
	: d_ptr(other.d_ptr)
{
}

DataImport& DataImport::operator=(const DataImport &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataImport::operator==(const DataImport &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void DataImport::import(const QString& fileName, const QString& symbol, int type)
{
	d_ptr->import(fileName, symbol, type);
}

QDebug operator<<(QDebug dbg, const DataImport& dataimport)
{
	return dbg << dataimport.toString();
}

