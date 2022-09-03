# vcpkg tutorial


## install vcpkg
```bash
git clone https://github.com/Microsoft/vcpkg.git
```

```bash
# windows platform
.\vcpkg\bootstrap-vcpkg.bat
```

## configure vcpkg

add vcpkg.exe to your system path

add the following code to `Edit the system environment` -> `Environment Variables` -> `Edit User Variable`, otherwise you will download 32 bits package

```bash
# variable name
VCPKG_DEFAULT_TRIPLET
# variable value
x64-windows
```

#### install famous C++ library

```powershell
vcpkg install boost:x64-windows
vcpkg install folly:x64-windows --head
vcpkg install abseil:x64-windows
vcpkg install fmt:x64-windows
```


## visual studio
add the following command for MS build

```bash
# NOTE: we can use vcpkg library without CMakeLists.txt
vcpkg integrate install
```

## vs code
open your `workspace settings.json` to configure `CMAKE_TOOLCHAIN_FILE` option

```bash
{
  "cmake.configureSettings": {
    // NOTE: change `C:/Applications/AAA_libs/vcpkg` to your vcpkg path
    "CMAKE_TOOLCHAIN_FILE": "C:/Applications/AAA_libs/vcpkg/scripts/buildsystems/vcpkg.cmake"
  },
}

```


add `"${vcpkgRoot}/x64-windows/include"` to `c_cpp_properties.json` -> `configurations` -> `includePath`  for header smart complete

```json
{
    "configurations": [
        {
            "includePath": [
                "${workspaceFolder}/**",
                "${vcpkgRoot}/x64-windows/include"
            ],
            ...
        }
    ],
    "version": 4
}
```


## clion
add the following code to Clion cmake option
```json
-DCMAKE_TOOLCHAIN_FILE=C:\Applications\AAA_libs\vcpkg\scripts\buildsystems\vcpkg.cmake
```

