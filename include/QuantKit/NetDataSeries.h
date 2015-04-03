#ifndef __QUANTKIT_NETDATASERIES_H__
#define __QUANTKIT_NETDATASERIES_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/DataSeries.h>
#include <QuantKit/SearchOption.h>

namespace QuantKit {

class NetDataSeriesPrivate;

class NetDataFile_;
class DataSeries;
class DataObject;

class QUANTKIT_EXPORT NetDataSeries Q_DECL_FINAL : public DataSeries
{
public:
	explicit NetDataSeries(const QString& name);
	NetDataSeries(const NetDataFile_& file, int id, const DataSeries& series);
	~NetDataSeries();

public:
	NetDataFile_ netDataFile__0() const;
	void setNetDataFile__0(NetDataFile_ value);

	int int_1() const;
	void setInt_1(int value);

private:
	QK_DECLARE_PRIVATE(NetDataSeries)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::NetDataSeries)

#endif // __QUANTKIT_NETDATASERIES_H__
