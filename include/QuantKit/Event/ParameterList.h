#ifndef __QUANTKIT_PARAMETERLIST_H__
#define __QUANTKIT_PARAMETERLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QList>
#include <IEnumerator>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class ParameterListPrivate;

class Parameter;

class QUANTKIT_EXPORT ParameterList Q_DECL_FINAL : public DataObject
{
public:
	ParameterList();
	~ParameterList();

public:
	QList<QString> methods() const;
	QString strategyName() const;
	void setStrategyName(const QString& value);
	Parameter item(int index) const;
	void setItem(int index, const Parameter& value);
	void add(const Parameter& parameter);
	void clear();
	int count();
	IEnumerator<Parameter> getEnumerator();
	QList<Parameter> parameters();
	void remove(const Parameter& parameter);

private:
	QK_DECLARE_PRIVATE(ParameterList)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ParameterList)

#endif // __QUANTKIT_PARAMETERLIST_H__
