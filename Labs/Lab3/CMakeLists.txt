cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(Lab3 C)

# Set compilation mode flags
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Define explicit paths for ncurses (Apple Silicon / M1 or M2)
set(CURSES_INCLUDE_PATH /opt/homebrew/opt/ncurses/include)
set(CURSES_LIBRARY_PATH /opt/homebrew/opt/ncurses/lib)

# Include directories
include_directories(
    include
    ${CURSES_INCLUDE_PATH}
)

# Library directories
link_directories(${CURSES_LIBRARY_PATH})

# Find threads library explicitly
find_package(Threads REQUIRED)

# Add executable
add_executable(Lab3
    src/main.c
    src/functions.c
)

# Explicitly link libraries (ncurses and pthread)
target_link_libraries(Lab3
    ncurses
    Threads::Threads
)
