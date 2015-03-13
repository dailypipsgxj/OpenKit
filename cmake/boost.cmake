find_package(Boost 1.57 REQUIRED)
 

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()
