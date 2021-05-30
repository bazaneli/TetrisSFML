cmake_minimum_required(VERSION 3.20.0)
project(TetrisSFML VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

add_executable(TetrisSFML 
  src/Tetris.cpp 
  src/BoardDwg.cpp 
  src/ScoreDwg.cpp 
  src/TetrisEngine.cpp 
  src/TetrisSettings.cpp
  src/ItemDrawable.cpp 
  src/TetrisAssets.cpp 
  src/TetrisPiece.cpp 
  src/TetrisSoundEngine.cpp
  src/NextPieceDwg.cpp 
  src/TetrisPieceDwg.cpp
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

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})