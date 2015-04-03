#ifndef __QUANTKIT_NEWS_H__
#define __QUANTKIT_NEWS_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class NewsPrivate;

class QUANTKIT_EXPORT News Q_DECL_FINAL : public DataObject
{
public:
	News();
	News(const QDateTime& dateTime, int providerId, int instrumentId, unsigned char urgency, const QString& url, const QString& headline, const QString& text);
	~News();

public:
	int int_0() const;
	void setInt_0(int value);

	int int_1() const;
	void setInt_1(int value);

	unsigned char byte_0() const;
	void setByte_0(unsigned char value);

	QString string_0() const;
	void setString_0(QString value);

	QString string_1() const;
	void setString_1(QString value);

	QString string_2() const;
	void setString_2(QString value);

private:
	QK_DECLARE_PRIVATE(News)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::News)

#endif // __QUANTKIT_NEWS_H__
