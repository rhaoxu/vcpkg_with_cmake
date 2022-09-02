# DEMO for using vcpkg


## install vcpkg
```bash
git clone https://github.com/Microsoft/vcpkg.git
```

```bash
# windows platform
.\vcpkg\bootstrap-vcpkg.bat
```

### configure vdpkg

add vcpkg.exe to your system path

add the following command to `Edit the system environment` -> `Environment Variables` -> `Edit User Variable`, otherwise you will download 32 bits package

```bash
# variable name
VCPKG_DEFAULT_TRIPLET
# variable value
x64-windows
```


```powershell
vcpkg install boost:x64-windows
vcpkg install folly:x64-windows --head
vcpkg install abseil:x64-windows
vcpkg install fmt:x64-windows
```


### visual studio
add following command for MS build
```
vcpkg integrate install
```

### vs code
open your `workspace settings.json` to configure `CMAKE_TOOLCHAIN_FILE` option

```bash
{
  "cmake.configureSettings": {
    // NOTE: change `C:/Applications/AAA_libs/vcpkg` to your vcpkg path
    "CMAKE_TOOLCHAIN_FILE": "C:/Applications/AAA_libs/vcpkg/scripts/buildsystems/vcpkg.cmake"
  },
}

```

## work with C++ libraries with vcpkg
```cmake
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

```