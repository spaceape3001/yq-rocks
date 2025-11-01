################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_rocks)

add_library(${PROJECT_NAME} SHARED
    rocks.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${ROCKS_API_DIR}
)

target_link_libraries(${PROJECT_NAME} 
PUBLIC 
    yq_core
)

LinkTest(${PROJECT_NAME})
