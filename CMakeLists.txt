cmake_minimum_required(VERSION 3.15)
project(cBarIlan C)

set(CMAKE_C_STANDARD 99)

# Helper: each exercise is a folder with main.c
function(add_exercise dir)
    add_executable(${dir} ${dir}/main.c)
endfunction()

# Your exercises
add_exercise(ex1)
add_exercise(ex2)
add_exercise(ex3)
add_exercise(ex4)
add_exercise(ex5)
add_exercise(ex6)

# --- CLEAN TARGETS ---

# safe clean: remove objects/outputs but keep cache
add_custom_target(clean-objects
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Removed object files and binaries (cache kept)."
)

# full wipe: delete entire build dir (you must reconfigure after this)
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_BINARY_DIR}"
    COMMENT "WIPED ${CMAKE_BINARY_DIR}"
)

