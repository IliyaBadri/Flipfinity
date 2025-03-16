# Building Flipfinity from Source on Linux

This guide will help you build Flipfinity from source.

## Prerequisites

### 1. Install Required Packages and Libraries

Run the following command on Ubuntu 22.04+:

```sh
sudo apt install build-essential git make \
  pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev \
  libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
  libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev \
  libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
  libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev \
  clang libpipewire-0.3-dev libwayland-dev libdecor-0-dev liburing-dev
```

**Note:** A more complete guide for installing SDL3 dependencies is available [here](https://github.com/libsdl-org/SDL/blob/main/docs/README-linux.md).

### 2. Build and Install SDL3 from Source

If `libsdl3-dev` is not available in your package manager, you must build and install SDL3 manually:


```sh
git clone https://github.com/libsdl-org/SDL.git SDL3
```
```sh
cd SDL3
```
```sh
mkdir build
```
```sh
cd build
```
```sh
cmake .. -G Ninja -DSDL_STATIC=OFF -DSDL_SHARED=ON
```
```sh
ninja
```
```sh
sudo ninja install
```
To verify the installation:
```sh
pkg-config --modversion sdl3
```

## Clone Flipfinity

Clone the Flipfinity repository:

```sh
git clone https://github.com/IliyaBadri/Flipfinity.git
```

## Build Flipfinity

Navigate to the project directory:

```sh
cd Flipfinity
```

Create and enter the build directory:

```sh
mkdir build
```
```sh
cd build
```

Build the project using CMake and Ninja:

```sh
cmake .. -G Ninja
```
```sh
ninja
```

### Include SDL3 Library

Find the SDL3 library location:

```sh
pkg-config --variable=libdir sdl3
```

For example, if it is located at `/usr/local/lib`, confirm with:

```sh
ls /usr/local/lib/
```

If `libSDL3.so` is listed, copy it to the build directory:

```sh
cp /usr/local/lib/libSDL3.so .
```

## Run Flipfinity

Execute the binary:

```sh
./Flipfinity
```

