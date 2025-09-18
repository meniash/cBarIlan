cmake_minimum_required(VERSION 3.15)
project(cBarIlan C)

set(CMAKE_C_STANDARD 99)

# Extra warnings always
add_compile_options(-Wall -Wextra -std=c99)

# --- EXERCISE TARGETS ---
file(GLOB EX_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "ex*")

foreach(ex ${EX_DIRS})
    file(GLOB sources "${ex}/*.c")
    if(sources)
        add_executable(${ex} ${sources})
        target_link_libraries(${ex} PRIVATE m)

        # Only define NDEBUG in Release mode
        target_compile_definitions(${ex} PRIVATE
            $<$<CONFIG:Release>:NDEBUG>
        )
    endif()
endforeach()

# --- CLEAN TARGETS ---

add_custom_target(clean-objects
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Removed object files and binaries (cache kept)."
)

file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/build/debug"   _DEBUG_DIR)
file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/build/release" _RELEASE_DIR)
file(TO_CMAKE_PATH "${CMAKE_BINARY_DIR}"               _CUR_DIR)

if(_CUR_DIR STREQUAL _RELEASE_DIR)
  set(_SIBLING_DIR "${_DEBUG_DIR}")
elseif(_CUR_DIR STREQUAL _DEBUG_DIR)
  set(_SIBLING_DIR "${_RELEASE_DIR}")
else()
  set(_SIBLING_DIR "${_RELEASE_DIR}")
endif()

add_custom_target(clean-all
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  COMMAND ${CMAKE_COMMAND} -E echo "Wiping ALL build outputs..."
  COMMAND ${CMAKE_COMMAND} -E remove_directory "${_SIBLING_DIR}" || cmd /c "exit /b 0"
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${_CUR_DIR}/*"
  "rm build/release"
  "rm build/debug"
  COMMENT "Removed sibling build tree (if possible) and emptied current one. Reconfigure required."
)
