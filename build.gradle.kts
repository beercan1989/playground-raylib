plugins {
    id("com.android.application") version "8.1.2"
}

repositories {
    mavenLocal()
    mavenCentral()
    google()
}

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(11))
    }
}

android {
    compileSdk = 33
    ndkVersion = "26.0.10792818"
    namespace = "uk.co.baconi.playground.raylib"
    defaultConfig {
        minSdk = 26
        targetSdk = 33
        versionCode = 2
        versionName = "0.0.2"
        externalNativeBuild {
            cmake {
                arguments += listOf("-DPLATFORM=Android")
                targets += listOf("playground_raylib")
            }
        }
        ndk {
            abiFilters += listOf("x86", "x86_64", "arm64-v8a") // Excluding 'armeabi-v7a' as raylib 5.0 fails to compile
        }
    }
    externalNativeBuild {
        cmake {
            path = file("CMakeLists.txt")
        }
    }
}