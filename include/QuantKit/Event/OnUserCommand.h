#ifndef __QUANTKIT_ONUSERCOMMAND_H__
#define __QUANTKIT_ONUSERCOMMAND_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnUserCommandPrivate;

class QUANTKIT_EXPORT OnUserCommand Q_DECL_FINAL : public Event
{
public:
	explicit OnUserCommand(const QString& command);
	~OnUserCommand();

public:
	QString string_0() const;

private:
	QK_DECLARE_PRIVATE(OnUserCommand)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnUserCommand)

#endif // __QUANTKIT_ONUSERCOMMAND_H__
