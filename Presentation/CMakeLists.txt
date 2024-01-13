cmake_minimum_required(VERSION 3.16)
project(CandyCrush LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Copy assets to build directory
#file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})


include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(main
        src/main.cpp
        src/Game.cpp
        include/Game.h
        include/GameFrame.h
        src/GameFrame.cpp
        include/PageManager.h
        src/PageManager.cpp
        include/Page.h
        include/Observer.h
        include/Observable.h
        include/Widget.h
#        include/Button.h
        include/BackgroundImage.h

        include/pages/welcomePage/WelcomePage.h
        src/pages/welcomePage/WelcomePage.cpp
        include/pages/welcomePage/StartButton.h
        src/pages/welcomePage/StartButton.cpp

        include/pages/levelsPage/LevelsPage.h
        src/pages/levelsPage/LevelsPage.cpp
        include/pages/levelsPage/LevelButton.h
        src/pages/levelsPage/LevelButton.cpp

        include/pages/GameplayPage/GameplayPage.h
        src/pages/GameplayPage/GameplayPage.cpp
        include/pages/gameplayPage/TopBarWidget.h
        src/pages/gameplayPage/TopBarWidget.cpp
        include/pages/GameplayPage/LevelInfoWidget.h
        src/pages/GameplayPage/LevelInfoWidget.cpp
        include/pages/gameplayPage/TopBarWidget.h
        include/pages/gameplayPage/BottomBarWidget.h
        src/pages/gameplayPage/BottomBarWidget.cpp
        include/pages/gameplayPage/ObjectiveWidget.h
        src/pages/gameplayPage/ObjectiveWidget.cpp
        include/pages/gameplayPage/BoardWidget.h
        include/pages/gameplayPage/CandyWidget.h
        src/pages/gameplayPage/BoardWidget.cpp
        src/pages/gameplayPage/CandyWidget.cpp
        src/pages/gameplayPage/pausePopUp/HomeButton.cpp
        src/pages/gameplayPage/pausePopUp/MusicButton.cpp
        src/pages/gameplayPage/pausePopUp/PlayButton.cpp
        src/pages/gameplayPage/pausePopUp/pausePopUp.cpp
        include/pages/gameplayPage/LevelClearedWidget.h
        src/pages/gameplayPage/LevelClearedWidget.cpp
        include/pages/gameplayPage/LevelLostWidget.h
        src/pages/gameplayPage/LevelLostWidget.cpp
        include/MusicPlayer.h
        src/MusicPlayer.cpp
)
include_directories(include)
include_directories(../BusinessLayer/public)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(main PRIVATE sfml-graphics sfml-audio)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET main
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
            VERBATIM)
endif()

install(TARGETS main)
