cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp/include/)

add_library(OpenSLManager
        SHARED
        OpenSLManager.cpp)

add_library(OpenSLAudio
            SHARED
            OpenSLAudio.cpp)


find_library( # Defines the name of the path variable that stores the
              # location of the NDK library.
              log-lib

              # Specifies the name of the NDK library that
              # CMake needs to locate.
              log )

find_library(OpenSLES
        OpenSLES
        )


# Links your native library against one or more other native libraries.
target_link_libraries( # Specifies the target library.
        OpenSLManager

        # Links the log library to the target library.
        android
        OpenSLES
        ${log-lib}

        )

# Links your native library against one or more other native libraries.
target_link_libraries( # Specifies the target library.
                       OpenSLAudio

                       # Links the log library to the target library.
                        OpenSLManager
                       )