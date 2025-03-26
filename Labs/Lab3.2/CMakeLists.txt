cmake_minimum_required(VERSION 3.10)
project(Lab3.2 C)

set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Confirm your paths depending on architecture
# set(CURSES_INCLUDE_PATH /usr/local/opt/ncurses/include)
# set(CURSES_LIBRARY_PATH /usr/local/opt/ncurses/lib)

# Uncomment next two lines if you're on Apple Silicon
set(CURSES_INCLUDE_PATH /opt/homebrew/opt/ncurses/include)
set(CURSES_LIBRARY_PATH /opt/homebrew/opt/ncurses/lib)

include_directories(include ${CURSES_INCLUDE_PATH})
link_directories(${CURSES_LIBRARY_PATH})

find_package(Threads REQUIRED)

add_executable(Lab3.2
    src/main.c
    src/functions.c
)

target_link_libraries(Lab3.2 ncurses Threads::Threads)
