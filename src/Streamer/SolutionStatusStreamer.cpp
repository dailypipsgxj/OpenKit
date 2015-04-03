#include <QuantKit/Streamer/SolutionStatusStreamer.h>

#include "ObjectStreamer_p.h"

namespace QuantKit {

class SolutionStatusStreamerPrivate : public ObjectStreamerPrivate
{
public:
	SolutionStatusStreamerPrivate();
	virtual ~SolutionStatusStreamerPrivate();

public:
	virtual QVariant read(const QByteArray& reader, unsigned char version) Q_DECL_OVERRIDE;
	virtual void write(const QByteArray& writer, const QVariant& obj) Q_DECL_OVERRIDE;
	virtual SolutionStatusStreamerPrivate* clone() Q_DECL_OVERRIDE { return new SolutionStatusStreamerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

SolutionStatusStreamerPrivate::SolutionStatusStreamerPrivate()
{
		m_typeId = 251;
		m_type = typeof(SolutionStatusInfo);
}

SolutionStatusStreamerPrivate::~SolutionStatusStreamerPrivate ()
{
}

QVariant SolutionStatusStreamerPrivate::read(const QByteArray& reader, unsigned char version)
{
	DateTime dateTime = new DateTime(reader.ReadInt64());
	SolutionStatusType type = (SolutionStatusType)reader.ReadByte();
	return new SolutionStatusInfo(dateTime, type)
	{
		Solution = reader.ReadString(),
		Mode = reader.ReadString()
	};
}

void SolutionStatusStreamerPrivate::write(const QByteArray& writer, const QVariant& obj)
{
	SolutionStatusInfo solutionStatusInfo = obj as SolutionStatusInfo;
	writer.Write(solutionStatusInfo.dateTime().Ticks);
	writer.Write((byte)solutionStatusInfo.type());
	writer.Write(solutionStatusInfo.solution());
	writer.Write(solutionStatusInfo.mode());
}


// Pubic API 

SolutionStatusStreamer::SolutionStatusStreamer()
	: ObjectStreamer(*new SolutionStatusStreamerPrivate)
{
}

SolutionStatusStreamer::~SolutionStatusStreamer()
{
}


