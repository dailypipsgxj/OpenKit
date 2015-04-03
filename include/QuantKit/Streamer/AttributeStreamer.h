#ifndef __QUANTKIT_ATTRIBUTESTREAMER_H__
#define __QUANTKIT_ATTRIBUTESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>
#include <QString>
#include <ConstructorInfo>
#include <Dictionary>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class AttributeStreamerPrivate;

class QUANTKIT_EXPORT AttributeStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	AttributeStreamer();
	~AttributeStreamer();

public:

private:
	QK_DECLARE_PRIVATE(AttributeStreamer)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AttributeStreamer)

#endif // __QUANTKIT_ATTRIBUTESTREAMER_H__
