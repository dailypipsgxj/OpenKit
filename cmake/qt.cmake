set(minimum_required_qt_version "5.3.2")

find_program(QT_QMAKE_EXECUTABLE_FINDQT NAMES qmake qmake5 qmake-qt5
 PATHS "${QT_SEARCH_PATH}/bin" "$ENV{QTDIR}/bin")
set(QT_QMAKE_EXECUTABLE ${QT_QMAKE_EXECUTABLE_FINDQT} CACHE PATH "Qt qmake program.")

exec_program(${QT_QMAKE_EXECUTABLE} ARGS "-query QT_VERSION" OUTPUT_VARIABLE _QT_VERSION)

string(REPLACE "." ";" __QT_VERSION_LIST ${_QT_VERSION})
list(GET __QT_VERSION_LIST 0 _QT_MAJOR_VERSION)

exec_program(${QT_QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_PREFIX" OUTPUT_VARIABLE QT_INSTALL_PREFIX)
set(CMAKE_PREFIX_PATH ${QT_INSTALL_PREFIX} ${CMAKE_PREFIX_PATH})

if(${_QT_VERSION} VERSION_LESS ${minimum_required_qt_version})
  message(FATAL_ERROR "error: requires Qt >= ${minimum_required_qt_version} -- you cannot use Qt ${_QT_VERSION}")
endif()

message(STATUS "Found Qt ${_QT_VERSION} at ${QT_INSTALL_PREFIX}")

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5XmlPatterns REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Script REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5LinguistTools REQUIRED)

find_package(Qt5Help REQUIRED)
find_package(Qt5WebKit REQUIRED)
find_package(Qt5WebKitWidgets REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Svg REQUIRED)
find_package(Qt5Test REQUIRED)

if(APPLE)
  find_package(Qt5MacExtras REQUIRED)
endif()

if(Qt5_POSITION_INDEPENDENT_CODE)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  message(STATUS "Enable Position Independent Code")
endif()

if(NOT QT_LUPDATE_EXECUTABLE)
  find_program(QT_LUPDATE_EXECUTABLE_FINDQT lupdate lupdate5 lupdate-qt5
    PATHS "${QT_SEARCH_PATH}/bin" "$ENV{QTDIR}/bin")
  set(QT_LUPDATE_EXECUTABLE ${QT_LUPDATE_EXECUTABLE_FINDQT} CACHE PATH "Qt lupdate program.")
endif()

if(NOT QT_LCONVERT_EXECUTABLE)
  find_program(QT_LCONVERT_EXECUTABLE_FINDQT lconvert lconvert5 lconver-qt5
   PATHS "${QT_SEARCH_PATH}/bin" "$ENV{QTDIR}/bin")
  set(QT_LCONVERT_EXECUTABLE ${QT_LCONVERT_EXECUTABLE_FINDQT} CACHE PATH "Qt lconvert program.")
endif()

if(NOT QT_XMLPATTERNS_EXECUTABLE)
  find_program(QT_XMLPATTERNS_EXECUTABLE_FINDQT NAMES xmlpatterns
   PATHS "${QT_SEARCH_PATH}/bin" "$ENV{QTDIR}/bin")
  set(QT_XMLPATTERNS_EXECUTABLE ${QT_XMLPATTERNS_EXECUTABLE_FINDQT} CACHE PATH "Qt xmlpatterns program.")
endif(NOT QT_XMLPATTERNS_EXECUTABLE)

#set(CMAKE_AUTOMOC ON)

# set rpath
if (CMAKE_BUILD_TYPE STREQUAL Release)
  add_definitions (-DQT_NO_WARNING_OUTPUT)
  add_definitions (-DQT_NO_DEBUG_OUTPUT)
endif (CMAKE_BUILD_TYPE STREQUAL Release)

if (UNIX AND NOT APPLE)
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,${QT_LIBRARY_DIR}")
endif (UNIX AND NOT APPLE)

#add_definitions (-DQT_NO_CAST_FROM_ASCII)
#add_definitions (-DQT_NO_CAST_TO_ASCII)

