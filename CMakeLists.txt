cmake_minimum_required(VERSION 3.29)
project(MonkeyTyper)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 11.0.2
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

add_executable(MonkeyTyper main.cpp
        Word.cpp
        WordManager.cpp
        WordManager.h
        Utils.cpp
        Utils.h
        Game.cpp
        Game.h
        WindowManager.cpp
        WindowManager.h
        DifficultyScene.cpp
        DifficultyScene.h
        TypingSpeedTracker.cpp
        TypingSpeedTracker.h
        CustomDifficultyScene.cpp
        CustomDifficultyScene.h
        EndScene.cpp
        EndScene.h
        Star.cpp
        Star.h
        StarField.cpp
        StarField.h
        CustomSettings.cpp
        CustomSettings.h
)

target_link_libraries(MonkeyTyper fmt sfml-graphics)