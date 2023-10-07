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
    namespace = "uk.co.baconi.playground.raylib"
    defaultConfig {
        minSdk = 26
        targetSdk = 33
        versionCode = 1
        versionName = "0.0.1"
        externalNativeBuild {
            cmake {
                arguments += listOf("-DPLATFORM=Android")
                targets += listOf("playground_raylib")
            }
        }
        ndk {
            abiFilters += listOf("x86", "x86_64")
        }
    }
    externalNativeBuild {
        cmake {
            path = file("CMakeLists.txt")
        }
    }
}