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

