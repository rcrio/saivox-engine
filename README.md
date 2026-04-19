# Saivox Engine
An attempt at making a voxel engine with C++ and OpenGL.

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

## 2. (Whilst in the vcpkg folder)
```bash
vcpkg install glfw3
```

## 3. (Assumes you have vcpkg installed in root)
```bash
cmake -B build -S . \
-DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake \
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

## 4.
```bash
cmake --build build && ./build/saivox-engine
```