#include <QuantKit/FileManager.h>


namespace QuantKit {

class FileManagerPrivate : public QSharedData
{
public:
	QString string_0;
	Dictionary<QString,FileStream> m_dictionary;

public:
	explicit FileManagerPrivate(const QString& path);
	virtual ~FileManagerPrivate();

public:
	void close();
	FileStream getFile(const QString& name, FileMode mode);
	virtual FileManagerPrivate* clone() Q_DECL_OVERRIDE { return new FileManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FileManagerPrivate::FileManagerPrivate(const QString& path)
	: string_0(path)
	, m_dictionary(new Dictionary<string, FileStream>())
{
}

FileManagerPrivate::~FileManagerPrivate ()
{
}

void FileManagerPrivate::close()
{
	foreach (FileStream current in m_dictionary.Values)
	{
		current.Close();
	}
}

FileStream FileManagerPrivate::getFile(const QString& name, FileMode mode)
{
	bool flag = false;
	FileStream result;
	try
	{
		Monitor.Enter(this, ref flag);
		FileStream fileStream;
		m_dictionary.TryGetValue(name, out fileStream);
		if (fileStream == null)
		{
			Console.WriteLine(string.Concat(new object[]
			{
				DateTime.Now,
				" Opening file : ",
				string_0,
				"\\",
				name
			}));
			fileStream = new FileStream(string_0 + "\\" + name, mode);
			m_dictionary.Add(name, fileStream);
		}
		result = fileStream;
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
	return result;
}


// Pubic API 

FileManager::FileManager(const QString& path)
	: d_ptr(new FileManagerPrivate(path))
{
}

FileManager::~FileManager()
{
}

FileManager::FileManager (const FileManager &other)
	: d_ptr(other.d_ptr)
{
}

FileManager& FileManager::operator=(const FileManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool FileManager::operator==(const FileManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void FileManager::close()
{
	d_ptr->close();
}

FileStream FileManager::getFile(const QString& name, FileMode mode)
{
	return d_ptr->getFile(name, mode);
}

QDebug operator<<(QDebug dbg, const FileManager& filemanager)
{
	return dbg << filemanager.toString();
}

