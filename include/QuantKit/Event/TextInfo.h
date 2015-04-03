#ifndef __QUANTKIT_TEXTINFO_H__
#define __QUANTKIT_TEXTINFO_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>
#include <QVariant>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class TextInfoPrivate;

class QUANTKIT_EXPORT TextInfo Q_DECL_FINAL : public DataObject
{
public:
	TextInfo(const QDateTime& dateTime, const QString& content);
	TextInfo(const QDateTime& dateTime, const QVariant& data);
	~TextInfo();

public:
	QString content() const;
	void setContent(const QString& value);

private:
	QK_DECLARE_PRIVATE(TextInfo)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TextInfo)

#endif // __QUANTKIT_TEXTINFO_H__
