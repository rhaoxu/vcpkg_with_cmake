cmake_minimum_required(VERSION 3.0.0)
project(vcpkg_with_cmake VERSION 0.1.0)

include(CTest)
enable_testing()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Abseil requires C++14
set(CMAKE_CXX_STANDARD 14)


# boost
find_package(boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# abseil
find_package(absl CONFIG REQUIRED)

# fmt
find_package(fmt CONFIG REQUIRED)

# facebook folly
find_package(folly CONFIG REQUIRED)
find_package(gflags CONFIG REQUIRED)

# NOTE: Folly start with captilized F
set(FOLLY_LIBRARIES Folly::folly)
set(FMT_LIBRARIES fmt::fmt)
set(GFLAGS_LIBRARIES gflags::gflags)

add_executable(test_folly_01 test_folly_01.cpp)
target_link_libraries(test_folly_01 PRIVATE ${FMT_LIBRARIES} ${GFLAGS_LIBRARIES} ${FOLLY_LIBRARIES})

add_executable(test_abseil_01 test_abseil_01.cpp)
target_link_libraries(test_abseil_01 PRIVATE absl::strings)

add_executable(test_boost_01 test_boost_01.cpp)

# target_link_libraries(cmake_01 fmt::fmt gflags::gflags Folly::folly)