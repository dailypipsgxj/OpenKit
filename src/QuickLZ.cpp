#include <QuantKit/QuickLZ.h>


namespace QuantKit {

class QuickLZPrivate : public QSharedData
{
public:
	unsigned char byte_0;
	unsigned char byte_1;

public:
	QuickLZPrivate();
	virtual ~QuickLZPrivate();

public:
	quint32 QLZ_COMPRESSION_LEVEL() const
	{
		return (uint)QuickLZ.qlz_get_setting(0);
	}

	quint32 QLZ_SCRATCH_COMPRESS() const
	{
		return (uint)QuickLZ.qlz_get_setting(1);
	}

	quint32 QLZ_SCRATCH_DECOMPRESS() const
	{
		return (uint)QuickLZ.qlz_get_setting(2);
	}

	quint32 QLZ_VERSION_MAJOR() const
	{
		return (uint)QuickLZ.qlz_get_setting(7);
	}

	quint32 QLZ_VERSION_MINOR() const
	{
		return (uint)QuickLZ.qlz_get_setting(8);
	}

	int QLZ_VERSION_REVISION() const
	{
		return QuickLZ.qlz_get_setting(9);
	}

	quint32 QLZ_STREAMING_BUFFER() const
	{
		return (uint)QuickLZ.qlz_get_setting(3);
	}

	bool QLZ_MEMORY_SAFE() const
	{
		return QuickLZ.qlz_get_setting(6) == 1;
	}

	unsigned char compress(const unsigned char& Source);
	unsigned char decompress(const unsigned char& Source);
	IntPtr qlz_compress(const unsigned char& source, const unsigned char& destination, IntPtr size, const unsigned char& scratch);
	IntPtr qlz_decompress(const unsigned char& source, const unsigned char& destination, const unsigned char& scratch);
	int qlz_get_setting(int setting);
	IntPtr qlz_size_compressed(const unsigned char& source);
	IntPtr qlz_size_decompressed(const unsigned char& source);
	quint32 sizeCompressed(const unsigned char& Source)
	{
		return (uint)((int)QuickLZ.qlz_size_compressed(Source));
	}

	quint32 sizeDecompressed(const unsigned char& Source)
	{
		return (uint)((int)QuickLZ.qlz_size_decompressed(Source));
	}

	virtual QuickLZPrivate* clone() Q_DECL_OVERRIDE { return new QuickLZPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

QuickLZPrivate::QuickLZPrivate()
	: byte_0(new byte[QuickLZ.qlz_get_setting(1)])
	, byte_1(byte_0)
	, byte_1(new byte[QuickLZ.qlz_get_setting(2)])
{
		if (QLZ_STREAMING_BUFFER() == 0u)
		{
			return;
		}
}

QuickLZPrivate::~QuickLZPrivate ()
{
}

unsigned char QuickLZPrivate::compress(unsigned char Source)
{
	byte[] array = new byte[Source.Length + 400];
	uint num = (uint)((int)QuickLZ.qlz_compress(Source, array, (IntPtr)Source.Length, byte_0));
	byte[] array2 = new byte[num];
	Array.Copy(array, array2, (long)((ulong)num));
	return array2;
}

unsigned char QuickLZPrivate::decompress(unsigned char Source)
{
	byte[] array = new byte[(int)QuickLZ.qlz_size_decompressed(Source)];
	(int)QuickLZ.qlz_decompress(Source, array, byte_1);
	return array;
}

IntPtr QuickLZPrivate::qlz_compress(unsigned char source, unsigned char destination, IntPtr size, unsigned char scratch)
{
}

IntPtr QuickLZPrivate::qlz_decompress(unsigned char source, unsigned char destination, unsigned char scratch)
{
}

int QuickLZPrivate::qlz_get_setting(int setting)
{
}

IntPtr QuickLZPrivate::qlz_size_compressed(unsigned char source)
{
}

IntPtr QuickLZPrivate::qlz_size_decompressed(unsigned char source)
{
}


// Pubic API 

QuickLZ::QuickLZ()
	: d_ptr(new QuickLZPrivate)
{
}

QuickLZ::~QuickLZ()
{
}

QuickLZ::QuickLZ (const QuickLZ &other)
	: d_ptr(other.d_ptr)
{
}

QuickLZ& QuickLZ::operator=(const QuickLZ &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool QuickLZ::operator==(const QuickLZ &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

quint32 QuickLZ::QLZ_COMPRESSION_LEVEL() const
{
	return d_ptr->QLZ_COMPRESSION_LEVEL();
}

quint32 QuickLZ::QLZ_SCRATCH_COMPRESS() const
{
	return d_ptr->QLZ_SCRATCH_COMPRESS();
}

quint32 QuickLZ::QLZ_SCRATCH_DECOMPRESS() const
{
	return d_ptr->QLZ_SCRATCH_DECOMPRESS();
}

quint32 QuickLZ::QLZ_VERSION_MAJOR() const
{
	return d_ptr->QLZ_VERSION_MAJOR();
}

quint32 QuickLZ::QLZ_VERSION_MINOR() const
{
	return d_ptr->QLZ_VERSION_MINOR();
}

int QuickLZ::QLZ_VERSION_REVISION() const
{
	return d_ptr->QLZ_VERSION_REVISION();
}

quint32 QuickLZ::QLZ_STREAMING_BUFFER() const
{
	return d_ptr->QLZ_STREAMING_BUFFER();
}

bool QuickLZ::QLZ_MEMORY_SAFE() const
{
	return d_ptr->QLZ_MEMORY_SAFE();
}

unsigned char QuickLZ::compress(unsigned char Source)
{
	return d_ptr->compress(Source);
}

unsigned char QuickLZ::decompress(unsigned char Source)
{
	return d_ptr->decompress(Source);
}

IntPtr QuickLZ::qlz_compress(unsigned char source, unsigned char destination, IntPtr size, unsigned char scratch)
{
	return d_ptr->qlz_compress(source, destination, size, scratch);
}

IntPtr QuickLZ::qlz_decompress(unsigned char source, unsigned char destination, unsigned char scratch)
{
	return d_ptr->qlz_decompress(source, destination, scratch);
}

int QuickLZ::qlz_get_setting(int setting)
{
	return d_ptr->qlz_get_setting(setting);
}

IntPtr QuickLZ::qlz_size_compressed(unsigned char source)
{
	return d_ptr->qlz_size_compressed(source);
}

IntPtr QuickLZ::qlz_size_decompressed(unsigned char source)
{
	return d_ptr->qlz_size_decompressed(source);
}

quint32 QuickLZ::sizeCompressed(unsigned char Source)
{
	return d_ptr->sizeCompressed(Source);
}

quint32 QuickLZ::sizeDecompressed(unsigned char Source)
{
	return d_ptr->sizeDecompressed(Source);
}

QDebug operator<<(QDebug dbg, const QuickLZ& quicklz)
{
	return dbg << quicklz.toString();
}

