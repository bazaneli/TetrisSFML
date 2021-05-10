cmake_minimum_required(VERSION 3.20.0)
project(TetrisSFML VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

add_executable(TetrisSFML Tetris.cpp 
BoardDwg.cpp ScoreDwg.cpp TetrisEngine.cpp TetrisSettings.cpp
ItemDrawable.cpp TetrisAssets.cpp TetrisPiece.cpp TetrisSoundEngine.cpp
NextPieceDwg.cpp TetrisPieceDwg.cpp
)

target_include_directories(TetrisSFML 
  PRIVATE "${PROJECT_BINARY_DIR}")

#Finally
target_link_libraries(TetrisSFML sfml-system sfml-window sfml-graphics sfml-audio 
    ${SFML_LIBRARIES} 
    ${SFML_DEPENDENCIES}
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)