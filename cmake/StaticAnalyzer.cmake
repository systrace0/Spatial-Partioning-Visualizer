function(spv_enable_clang_tidy target)
    if(NOT SPV_ENABLE_CLANG_TIDY)
        return()
    endif()

    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(NOT CLANG_TIDY_EXE)
        message(STATUS "clang-tidy not found")
        return()
    endif()

    set_target_properties(${target} PROPERTIES
        CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-p=${CMAKE_BINARY_DIR}"
    )
endfunction()