################################################################################
##
##  ROCKS!
##
################################################################################

add_executable(rocks
    rocks.cpp
    MainWidget.cpp
    MainScene.cpp
    RockApp.cpp
)

target_link_libraries(rocks
    PUBLIC 
        yq_assetvk
        yq_tachyon 
        yq_rocksVk
)

