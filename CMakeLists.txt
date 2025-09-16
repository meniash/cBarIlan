cmake_minimum_required(VERSION 3.15)
project(cBarIlan C)

set(CMAKE_C_STANDARD 99)

# Common compile flags
set(COMMON_COMPILE_FLAGS -Wall -Wextra -g)

# --- EXERCISE TARGETS ---
# Find all subdirectories starting with "ex"
file(GLOB EX_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "ex*")

foreach(ex ${EX_DIRS})
    file(GLOB sources "${ex}/*.c")
    if(sources) # only if the folder has .c files
        add_executable(${ex} ${sources})
        target_compile_options(${ex} PRIVATE ${COMMON_COMPILE_FLAGS})
        # NOTE: removed RUNTIME_OUTPUT_DIRECTORY so executables stay in build/debug or build/release
    endif()
endforeach()
# Safe clean
add_custom_target(clean-objects
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Removed object files and binaries (cache kept)."
)

# --- CLEAN TARGETS ---

# Decide which folder we're currently building in
file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/build/debug"   _DEBUG_DIR)
file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/build/release" _RELEASE_DIR)
file(TO_CMAKE_PATH "${CMAKE_BINARY_DIR}"               _CUR_DIR)

if(_CUR_DIR STREQUAL _RELEASE_DIR)
  set(_SIBLING_DIR "${_DEBUG_DIR}")
elseif(_CUR_DIR STREQUAL _DEBUG_DIR)
  set(_SIBLING_DIR "${_RELEASE_DIR}")
else()
  # If build dir is something else, just treat both as siblings
  set(_SIBLING_DIR "${_RELEASE_DIR}")
endif()

add_custom_target(clean-all
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  COMMAND ${CMAKE_COMMAND} -E echo "Wiping ALL build outputs..."
  # 1) try to remove the sibling tree completely (ignore errors)
  COMMAND ${CMAKE_COMMAND} -E remove_directory "${_SIBLING_DIR}" || cmd /c "exit /b 0"
  # 2) empty the *current* build tree
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${_CUR_DIR}/*"
  "rm build/release"
  "rm build/debug"
  COMMENT "Removed sibling build tree (if possible) and emptied current one. Reconfigure required."
)




