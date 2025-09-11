cmake_minimum_required(VERSION 3.15)
project(cBarIlan C)

set(CMAKE_C_STANDARD 99)

# Common compile flags
set(COMMON_COMPILE_FLAGS -Wall -Wextra -g)

# Find all subdirectories starting with "ex"
file(GLOB EX_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "ex*")

foreach(ex ${EX_DIRS})
    file(GLOB sources "${ex}/*.c")
    if(sources) # only if the folder has .c files
        add_executable(${ex} ${sources})
        target_compile_options(${ex} PRIVATE ${COMMON_COMPILE_FLAGS})
    endif()
endforeach()

# --- CLEAN TARGETS ---

# safe clean: remove objects/outputs but keep cache
add_custom_target(clean-objects
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Removed object files and binaries (cache kept)."
)

# full wipe: delete entire build dir (you must reconfigure after this)
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E echo "Wiping build directory: ${CMAKE_BINARY_DIR}"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}   # <--- important: run from source, not build
    COMMENT "WIPED ${CMAKE_BINARY_DIR}"
)

