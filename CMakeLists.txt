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

# Safe clean: removes object files/outputs, but keeps cache and build trees
add_custom_target(clean-objects
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Removed object files and binaries (cache kept)."
)

# Full wipe: removes *both* debug and release build directories
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E echo "Wiping ALL build directories..."
    COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/build/debug"
    COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_SOURCE_DIR}/build/release"
    COMMENT "Removed ALL build directories (debug + release). Reconfigure required."
)
