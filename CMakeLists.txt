################################################################################
##
##  YOUR QUILL
##
################################################################################

cmake_minimum_required(VERSION 3.26.0)
project(YQRocks VERSION 0.0.0.3 LANGUAGES CXX)

SET(YOUR_QUILL_ROCKS ${CMAKE_CURRENT_LIST_DIR})
include(local.cmake OPTIONAL)
include(configure.cmake)

if(PROJECT_IS_TOP_LEVEL)
    if(NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/yq-toolbox)
        message(FATAL_ERROR "YQ toolbox must be present! (use a symbolic link or junction)")
    endif()
    if(NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/yq-vulqan)
        message(FATAL_ERROR "YQ vulqan must be present! (use a symbolic link or junction)")
    endif()
    include(yq-toolbox/standard.cmake)
endif()

#   If this fails, means the toolbox wasn't included/used
YQRepo()

