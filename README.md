# Saivox Engine


# Engine Stack
- OpenGL 3.3
- GLFW
- GLAD

# Prerequisites
- vcpkg
- CMake

# Steps
## 1.
```bash
git clone https://github.com/microsoft/vcpkg
cd vcpkg
./bootstrap-vcpkg.sh   # Linux/macOS
.\bootstrap-vcpkg.bat  # Windows
```

## 2.
```bash
vcpkg install glfw3
```

## 3.
```bash
cmake -B build -S . \
-DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake \
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

## 4.

```bash
cmake --build build && ./build/saivox-engine
```