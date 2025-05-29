################################################################################
##
##  YOUR QUILL
##
################################################################################

set(ROCKS_API_DIR ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(rocks)

if(Build_Vulkan)
    add_subdirectory(rocksVk)
endif()

