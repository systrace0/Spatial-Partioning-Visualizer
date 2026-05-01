function(spv_enable_sanitizers target)
    if(MSVC)
        return()
    endif()

    if(NOT SPV_ENABLE_ASAN AND NOT SPV_ENABLE_UBSAN)
        return()
    endif()

    if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(WARNING "[SPV] Sanitizers are only supported in Debug builds (current: ${CMAKE_BUILD_TYPE}). Skipping.")
        return()
    endif()

    if(SPV_ENABLE_ASAN)
        target_compile_options(${target} PRIVATE -fsanitize=address)
        target_link_options(${target} PRIVATE -fsanitize=address)
    endif()

    if(SPV_ENABLE_UBSAN)
        target_compile_options(${target} PRIVATE -fsanitize=undefined)
        target_link_options(${target} PRIVATE -fsanitize=undefined)
    endif()
endfunction()