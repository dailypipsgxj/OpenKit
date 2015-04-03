#ifndef __QUANTKIT_IEVENTQUEUE_H__
#define __QUANTKIT_IEVENTQUEUE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>

namespace QuantKit {

class Event;

class QUANTKIT_EXPORT IEventQueue
{
public:
	virtual unsigned char id() const = 0;
	virtual unsigned char type() const = 0;
	virtual bool isSynched() const = 0;
	virtual void setIsSynched(bool value) = 0;
	virtual QString name() const = 0;
	virtual unsigned char priority() const = 0;
	virtual long count() const = 0;
	virtual long fullCount() const = 0;
	virtual long emptyCount() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual Event peek() const = 0;
    virtual QDateTime peekDateTime() const = 0;
    virtual void enqueue(const Event& obj) = 0;
    virtual Event dequeue() = 0;
	virtual Event read() = 0;
	virtual void write(const Event& obj) = 0;
    virtual void clear() = 0;
    virtual void resetCounts() = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IEVENTQUEUE_H__
