cmake_minimum_required(VERSION 3.10.0)
project(NeirCrackLib VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#include_directories(${CMAKE_SOURCE_DIR}/include)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.cpp")

# set(HEADERS
#     include/ValueCrack/gameDataMemory.hpp
#     include/ValueCrack/gameValueCrack.hpp
#     include/ValueCrack/gameValueMemoryOffset.hpp
#     include/neirCrack.hpp
# )

# set(SOURCES 
# src/ValueCrack/gameDataMemory.cpp
# src/ValueCrack/gameValueCrack.cpp
# src/ValueCrack/gameDataMemoryOffset.cpp
# src/neirCrack.cpp
# )

add_library(NeirCrackLib STATIC ${SOURCES} ${HEADERS})

target_link_directories(NeirCrackLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_include_directories(NeirCrackLib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


