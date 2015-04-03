#ifndef __QUANTKIT_QTBOOST_H__
#define __QUANTKIT_QTBOOST_H__

#include <boost/functional/hash.hpp>

#include <QString>
#include <QDateTime>
#include <QHash>
#include <QVariant>

inline std::size_t hash_value(const QChar& c)        { return qHash(c); }
inline std::size_t hash_value(const QString& s)      { return qHash(s); }
inline std::size_t hash_value(const QDate& d)        { return qHash(d.toJulianDay()); }
inline std::size_t hash_value(const QTime& t)        { return qHash(t.toString()); }
inline std::size_t hash_value(const QDateTime& dt)   { return qHash(dt.toString()); }
inline std::size_t hash_value(const QVariant& v)     { return qHash(v.toString()); }
template <typename T0, typename T1>
inline std::size_t hash_value(const QPair<T0, T1> & p)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, p.first);
   boost::hash_combine(seed, p.second);
   return seed;
}

#endif // __QUANTKIT_QTBOOST_H__
