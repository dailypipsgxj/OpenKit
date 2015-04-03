#ifndef __QUANTKIT_FILEMANAGER_H__
#define __QUANTKIT_FILEMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <FileStream>
#include <FileMode>
#include <Dictionary>
#include <QSharedDataPointer>

namespace QuantKit {

class FileManagerPrivate;

class QUANTKIT_EXPORT FileManager
{
public:
	explicit FileManager(const QString& path);
	~FileManager();

	FileManager(const FileManager &other);
	FileManager& operator=(const FileManager &other);
	bool operator==(const FileManager &other) const;
	inline bool operator!=(const FileManager &other) const { return !(this->operator==(other));  }
public:
	void close();
	FileStream getFile(const QString& name, FileMode mode = 4);

private:
	QSharedDataPointer<FileManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const FileManager& filemanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const FileManager& filemanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FileManager)

#endif // __QUANTKIT_FILEMANAGER_H__
