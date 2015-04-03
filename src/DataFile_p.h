#ifndef __QUANTKIT_DATAFILE_PRIVATE_H__
#define __QUANTKIT_DATAFILE_PRIVATE_H__

#include <QuantKit/DataFile.h>

#include <QSharedData>

#include "ObjectKey_p.h"
#include "StreamerManager_p.h"

namespace QuantKit {

class DataFilePrivate : public QSharedData
{
public:
	QString string_0;
	unsigned char byte_0;
	long long_0;
	long long_1;
	long aCdHfUdLo6;
	long long_2;
	int int_0;
	int int_1;
	int int_2;
	int int_3;
	unsigned char m_compressionMethod;
	unsigned char m_compressionLevel;
	QString string_1;
	Stream stream_0;
	FileMode fileMode_0;
	bool bool_0;
	bool bool_1;
	Dictionary<QString,ObjectKey> m_keys;
	QList<Class48> list_0;
	ObjectKey objectKey_0;
	ObjectKey objectKey_1;
	StreamerManager streamerManager_0;
	bool bool_2;
	MemoryStream memoryStream_0;
	QByteArray binaryWriter_0;

public:
	DataFilePrivate(const QString& name, const StreamerManager& streamerManager);
	virtual ~DataFilePrivate();

public:
	long getLong_0() const;
	void setLong_0(long value);

	long getLong_1() const;
	void setLong_1(long value);

	long getACdHfUdLo6() const;
	void setACdHfUdLo6(long value);

	long getLong_2() const;
	void setLong_2(long value);

	int getInt_0() const;
	void setInt_0(int value);

	int getInt_1() const;
	void setInt_1(int value);

	int getInt_2() const;
	void setInt_2(int value);

	int getInt_3() const;
	void setInt_3(int value);

	Stream getStream_0() const;
	void setStream_0(Stream value);

	bool getBool_0() const;
	void setBool_0(bool value);

	bool getBool_1() const;
	void setBool_1(bool value);
	QString getString_1() const;

	StreamerManager getStreamerManager_0() const;
	Dictionary<QString,ObjectKey> keys() const { return m_keys; }
	unsigned char compressionMethod() const { return m_compressionMethod; }
	void setCompressionMethod(unsigned char value) { m_compressionMethod = value; }
	unsigned char compressionLevel() const { return m_compressionLevel; }
	void setCompressionLevel(unsigned char value) { m_compressionLevel = value; }
	virtual void close() Q_DECL_OVERRIDE;
	virtual void delete(const QString& name) Q_DECL_OVERRIDE;
	void dispose();
	void dump();
	virtual void flush() Q_DECL_OVERRIDE;
	virtual QVariant get(const QString& name) Q_DECL_OVERRIDE;
	virtual void open(FileMode mode) Q_DECL_OVERRIDE;
	virtual void refresh() Q_DECL_OVERRIDE;
	virtual void write(const QString& name, const QVariant& obj) Q_DECL_OVERRIDE;
//protected
	virtual void closeFileStream() Q_DECL_OVERRIDE { stream_0.Close(); }
	virtual void finalize() Q_DECL_OVERRIDE { method_7(false); }
	bool lEqHupgyQs();
	void method_0();
	void method_2(const ObjectKey& objectKey_2, bool bool_3);
	ObjectKey method_3(long long_3, int int_4);
	void method_4(const ObjectKey& objectKey_2);
	virtual bool openFileStream(const QString& name, FileMode mode) Q_DECL_OVERRIDE;
	virtual void readBuffer(const unsigned char& buffer, long position, int length) Q_DECL_OVERRIDE;
	void readFree();
	void readKeys();
	virtual void writeBuffer(const unsigned char& buffer, long position, int length) Q_DECL_OVERRIDE;

//private:
	Class48 method_1(int int_4);
	void method_5();
	void method_6();
	void method_7(bool bool_3);
};

} // namepsace QuantKit

#endif // __QUANTKIT_DATAFILE_PRIVATE_H__
