################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_rocksVk)

add_library(${PROJECT_NAME} SHARED
    rocksVk.cpp
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        yq_rocks
        yq_tachyon
)

vulqan_library(${PROJECT_NAME})
yq_vklib(${PROJECT_NAME})
LinkTest(${PROJECT_NAME})
