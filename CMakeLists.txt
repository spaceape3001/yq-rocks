################################################################################
##
##  YOUR QUILL
##
################################################################################

cmake_minimum_required(VERSION 3.26.0)
project(YQ_Rocks VERSION 0.0.0.3 LANGUAGES CXX)
include(local.cmake OPTIONAL)
include(configure.cmake)

if(PROJECT_IS_TOP_LEVEL)
    if(NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/yq-toolbox)
        message(FATAL_ERROR "YQ toolbox must be present! (use a symbolic link or junction)")
    endif()

    include(yq-toolbox/configure.cmake)
    add_subdirectory(yq-toolbox)

    if(NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/yq-vulqan)
        message(FATAL_ERROR "YQ vulqan must be present! (use a symbolic link or junction)")
    endif()

    include(yq-vulqan/configure.cmake)
    add_subdirectory(yq-vulqan)
else()
    #   We're a sub-project
    if(NOT YOUR_QUILL_TOOLBOX)
        message(FATAL_ERROR "YQ toolbox must be used!")
    endif()
    if(NOT YOUR_QUILL_VULQAN)
        message(FATAL_ERROR "YQ vulqan must be used!")
    endif()
endif()

enable_testing()
add_subdirectory(exe)
