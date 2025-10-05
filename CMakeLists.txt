cmake_minimum_required(VERSION 3.20)
project(mage-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/libs/raylib)
# set(SENTINEL_DIR ${CMAKE_SOURCE_DIR}/libs/sentinel)
add_subdirectory(${RAYLIB_DIR})
# add_subdirectory(${SENTINEL_DIR}) # later!

# auto finds cpp files in src dir
file(GLOB_RECURSE ENGINE_SOURCES 
    "src/*.cpp"
)

add_library(mage-engine STATIC ${ENGINE_SOURCES})

target_include_directories(mage-engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# public because games made with mage needd to access sme raylib stuff like vector2 n what not
target_link_libraries(mage-engine PUBLIC raylib) # remember: add sentinel when ac works starts (lol)

# example test
add_executable(basic examples/basic.cpp)
target_link_libraries(basic PRIVATE mage-engine)