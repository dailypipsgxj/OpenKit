#ifndef QUANTKIT_GLOBAL_H
#define QUANTKIT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QUANTKIT_LIBRARY)
#  define QUANTKIT_EXPORT Q_DECL_EXPORT
#else
#  define QUANTKIT_EXPORT Q_DECL_IMPORT
#endif

#define QK_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func(); \
    inline const Class##Private* d_func() const ;

#define QK_IMPLEMENTATION_PRIVATE(Class) \
    inline Class##Private* Class::d_func() { return static_cast<Class##Private*>(d_ptr.data()); }\
    inline const Class##Private* Class::d_func() const { return static_cast<const Class##Private* const>(d_ptr.data());}
#endif // QUANTKIT_GLOBAL_H
