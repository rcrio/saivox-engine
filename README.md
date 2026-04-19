# Saivox Engine
An attempt at making a voxel engine with C++ and OpenGL.

# Engine Stack
- OpenGL 3.3
- GLFW
- GLAD
- GLM
- vcpkg (dependency manager)
- CMake

# Prerequisites
- CMake (>= 3.20 recommended)
- Git
- C++ compiler:
* Windows: MSVC (Visual Studio Build Tools) or MinGW
* Linux: GCC or Clang

# Installation guide
## Windows
### Requirements
- Visual Studio Build Tools 2022 (or full Visual Studio)
* Workload: Desktop development with C++
* Includes MSVC, Windows SDK
* Can be found here: https://visualstudio.microsoft.com/visual-cpp-build-tools/

### 1. Clone the Repository
```bash
git clone https://github.com/rcrio/saivox-engine.git
cd saivox-engine
git submodule update --init --recursive
```

### 2. Setup vcpkg
```bash
.\vcpkg\bootstrap-vcpkg.bat
```

### 3. Install Dependencies
```bash
.\vcpkg\vcpkg install glfw3 glm
```

### 4. Configure and build
```bash
# Clear any old cache first
rmdir build -Recurse -Force

# Configure
cmake -B build -S . `
  -G "Visual Studio 18 2026" `
  -A x64 `
  -DCMAKE_TOOLCHAIN_FILE="./vcpkg/scripts/buildsystems/vcpkg.cmake"

# Build
cmake --build build

# Run
.\build\Debug\saivox-engine.exe
```

## Linux
### 1. Clone the Repository
```bash
git clone https://github.com/rcrio/saivox-engine.git
cd saivox-engine
git submodule update --init --recursive
```

### 2. Setup vcpkg
```bash
./vcpkg/bootstrap-vcpkg.sh
```

### 3. Install Dependencies
```bash
./vcpkg/vcpkg install glfw3 glm
```

### 4. Configure and build
```bash
# Clear any old cache first
rm -rf build

# Configure
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake

# Build
cmake --build build

# Run
./build/saivox-engine
```