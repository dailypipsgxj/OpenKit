#ifndef __QUANTKIT_DATAPROCESSOR_H__
#define __QUANTKIT_DATAPROCESSOR_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class DataProcessorPrivate;

class DataObject;

class QUANTKIT_EXPORT DataProcessor
{
public:
	DataProcessor();
	~DataProcessor();

	DataProcessor(const DataProcessor &other);
	DataProcessor& operator=(const DataProcessor &other);
	bool operator==(const DataProcessor &other) const;
	inline bool operator!=(const DataProcessor &other) const { return !(this->operator==(other));  }
public:
	bool emitBar() const;
	void setEmitBar(bool value);
	bool emitBarOpen() const;
	void setEmitBarOpen(bool value);
	bool emitBarOpenTrade() const;
	void setEmitBarOpenTrade(bool value);
	bool emitBarHighTrade() const;
	void setEmitBarHighTrade(bool value);
	bool emitBarLowTrade() const;
	void setEmitBarLowTrade(bool value);
	bool emitBarCloseTrade() const;
	void setEmitBarCloseTrade(bool value);

private:
	QSharedDataPointer<DataProcessorPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataProcessor& dataprocessor);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataProcessor& dataprocessor);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataProcessor)

#endif // __QUANTKIT_DATAPROCESSOR_H__
