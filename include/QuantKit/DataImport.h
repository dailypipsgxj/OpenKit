#ifndef __QUANTKIT_DATAIMPORT_H__
#define __QUANTKIT_DATAIMPORT_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class DataImportPrivate;

class Framework;

class QUANTKIT_EXPORT DataImport
{
public:
	explicit DataImport(const Framework& framework);
	~DataImport();

	DataImport(const DataImport &other);
	DataImport& operator=(const DataImport &other);
	bool operator==(const DataImport &other) const;
	inline bool operator!=(const DataImport &other) const { return !(this->operator==(other));  }
public:
	void import(const QString& fileName, const QString& symbol, int type);

private:
	QSharedDataPointer<DataImportPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataImport& dataimport);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataImport& dataimport);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataImport)

#endif // __QUANTKIT_DATAIMPORT_H__
