cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(thread_usleep C)

# Set compilation mode flags
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG -s")

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
add_executable(thread_usleep
    src/main.c
    src/functions.c
)

# Explicitly link libraries (ncurses and pthread)
target_link_libraries(thread_usleep
    ncurses
    Threads::Threads
)
