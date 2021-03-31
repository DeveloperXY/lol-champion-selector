# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.7)
project(untitled C)

set(CMAKE_C_STANDARD 11)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib)
set(SDL2_IMAGE_INCLUDE_DIRS C:/libs/SDL_IMG/include)
set(SDL2_IMAGE_LIBRARIES C:/libs/SDL_IMG/lib)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})
link_directories(${SDL2_LIB_DIR} ${SDL2_IMAGE_LIBRARIES})

add_executable(untitled main.c functions.c functions.h defs.h structs.h)
target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)