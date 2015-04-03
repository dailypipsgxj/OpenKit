#ifndef __QUANTKIT_DATAFILEMANAGER_H__
#define __QUANTKIT_DATAFILEMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <FileMode>
#include <Dictionary>
#include <QSharedDataPointer>

namespace QuantKit {

class DataFileManagerPrivate;

class DataFile;
class DataSeries;
class StreamerManager;

class QUANTKIT_EXPORT DataFileManager
{
public:
	explicit DataFileManager(const QString& path);
	~DataFileManager();

	DataFileManager(const DataFileManager &other);
	DataFileManager& operator=(const DataFileManager &other);
	bool operator==(const DataFileManager &other) const;
	inline bool operator!=(const DataFileManager &other) const { return !(this->operator==(other));  }
public:
	void close(const QString& name);
	void close();
	void delete(const QString& fileName, const QString& objectName);
	DataFile getFile(const QString& name, FileMode mode = 4);
	DataSeries getSeries(const QString& fileName, const QString& seriesName);

private:
	QSharedDataPointer<DataFileManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataFileManager& datafilemanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataFileManager& datafilemanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataFileManager)

#endif // __QUANTKIT_DATAFILEMANAGER_H__
