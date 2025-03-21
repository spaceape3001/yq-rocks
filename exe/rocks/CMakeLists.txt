################################################################################
##
##  ROCKS!
##
################################################################################

add_executable(rocks
    rocks.cpp
    MainWidget.cpp
    RockApp.cpp
)

target_link_libraries(rocks
    PUBLIC 
        yq_tachyon 
)

