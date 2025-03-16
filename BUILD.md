# How to build Flipfinity from source on linux?

## Prerequisites
	```sh
	sudo apt install libsdl3-dev cmake ninja-build clang
	```


This guide will walk you through the process of setting up and building Flipfinity from the ground up on your **Windows machine**. Flipfinity is a C project that uses SDL3 and can be built with CMake, LLVM/Clang, and Ninja.

## Prerequisites

Before you start, make sure you have the following software installed:

1.  **CMake**: 
	- Go to https://github.com/Kitware/CMake/releases and install the latest stable build with the tag `cmake-x.y.z-windows-x86_64.msi` .
2.  **LLVM/Clang**: 
	- Go to https://github.com/llvm/llvm-project/releases and install the latest stable build with the tag `LLVM-x.y.z-win64.exe` .
3.  **Ninja**: 
	- Go to https://github.com/ninja-build/ninja/releases and download the latest stable build package with the tag `ninja-win.zip` .
	- Extract the `ninja.exe` to a specific directory on your device. I prefer `C:\opt\ninja\ninja.exe`.
	- Press **WIN + R** and in the pop up box type:
		```sh
		rundll32.exe sysdm.cpl,EditEnvironmentVariables
		```
		then click **OK**.
	- Then in the user variables section look for the `Path` variable and double click on it.
	- At end of the list that has poped up paste the path to the **directory** that your `ninja.exe` binary is in, and then press **OK**. For me that will be `C:\opt\ninja\`.
4. **Windows SDK**:
	Go to https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/ and download and install the latest Windows SDK.
5. **MSVC toolchain**:
	-   Open the Visual Studio Installer ( Install [Visual Studio](https://visualstudio.microsoft.com/) if you dont already have it installed ).
	-   Install the **Desktop development with C++** workload, which includes MSVC and the necessary libraries.
7.  **SDL3**: Go to https://github.com/libsdl-org/SDL/releases and download the latest stable development library with the tag `SDL3-devel-x.y.z-mingw.zip` .

## Cloning the Project

Start by cloning the Flipfinity repository from GitHub. If you don’t have Git installed, you can download it from [Git's official website](https://git-scm.com/); Or you can just download the project's zip archive from [GitHub](https://github.com/IliyaBadri/Flipfinity) directly and skip to the next step.

Run the following command in your terminal or command prompt to clone the project with the Git CLI:
```sh
git clone https://github.com/IliyaBadri/Flipfinity
```

## Adding dependencies
1. Go to the `Flipfinity` directory that you have just cloned
	```sh
	cd Flipfinity
	```
2. Create a new directory called `SDL3`:
	```sh
	mkdir SDL3
	```
3. Create a new directory called `build`:
	```sh
	mkdir build
	```
4. Extract the `SDL3-devel-x.y.z-mingw.zip` archive you downloaded earlier and navigate to `SDL3-devel-x.y.z-mingw.zip\SDL3-x.x.x\x86_64-w64-mingw32\`. There you should see 4 directories named `bin`, `include`, `lib`, `share`. Copy all those directories into `<path_to_the_project>\Flipfinity\SDL3\` directory you have just created earlier.


## Building Flipfinity

### 1. Configure the Build with CMake

1. Navigate to the build directory you have created:

	```sh
	cd build
	```

2. Then, use CMake to configure the build system. This will generate the necessary files for Ninja and Clang:

	```sh
	cmake .. -G Ninja
	```

### 2. Build the Project

1. Once the configuration is complete, you can build the project using Ninja:

	```sh
	ninja
	```
	
	Ninja will compile the project using Clang and will link against SDL3. The build process will generate an executable in the `build` directory.
2. Now you just have to add the SDL3 dll to your build:
	```sh
	cp ../SDL3/bin/SDL3.dll ./
	```

### 3. Run the Game

After the build completes, you can run the game directly from the command line:

```sh
./Flipfinity.exe
```

If everything is set up correctly, Flipfinity should launch!

## Contributing

We welcome contributions! If you'd like to contribute to Flipfinity, feel free to fork the repository and submit a pull request. Please ensure your changes are well-documented and tested.

## License

Flipfinity is licensed under the MIT License. See the LICENSE file for details.

----------

If you encounter any issues or have any questions, feel free to reach out or open an issue in the GitHub repository!

