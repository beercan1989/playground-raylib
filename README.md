# Playground Raylib

Playing around with Raylib v4, attempting a single project to support desktop (Windows|Linux), mobile (Android) and
web (HTML).

* https://www.raylib.com
* https://github.com/raysan5/raylib

## Running

Both web hosted version and some pe-built binaries are available via https://beercan.itch.io/playground-raylib

## Building

To compile the example, use one of the following depending on your build target...

If you don't want to use an IDE to build, the same configuration can be used with cmake on the command line, following
this pattern:
```bash
cmake <PLATFORM_SPECIFIC_CONFIGURATION> -B cmake-build-<PLATFORM>
cmake --build cmake-build-<PLATFORM>
```

### Desktop

Using CLion, create a new cmake profile named `Desktop` using the bundled toolchain, 
no other configuration is needed to target your current machines OS.

### Web

Compiling for the web requires the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html):

Using CLion, create a new cmake profile named `Emscripten` using the same toolchain as the desktop, with these cmake options set:

```
-DCMAKE_TOOLCHAIN_FILE=${EMSDK_HOME}\upstream\emscripten\cmake\Modules\Platform\Emscripten.cmake
-DPLATFORM=Web
-DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3"
-DCMAKE_EXECUTABLE_SUFFIX=".html"
```

### Android

Setup your local.properties to tell Gradle where your Android SDK is:
```properties
sdk.dir=C\:\\Android\\Sdk
```

#### Native Library + Application

Using Gradle on the command line, this will build the native library and the Android APK:

```bash
./gradlew assembleDebug
```

To both build and install to an emulator or connect device run:
```bash
./gradlew installDebug
```

#### Just Native Library

Using CLion, this optional only allows for building the native library for the Android project, create a new cmake 
profile named `Android` using the same toolchain as the desktop, with these cmake options set:

```
-DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK_HOME}\build\cmake\android.toolchain.cmake
-DPLATFORM=Android
-DANDROID_ABI=x86
-DANDROID_PLATFORM=android-33
```