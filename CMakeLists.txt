cmake_minimum_required(VERSION 3.16)
project(CandyCrush LANGUAGES CXX)

add_subdirectory(BusinessLayer)
add_subdirectory(Presentation)

add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
add_dependencies(main copy_assets)

target_link_libraries(main PRIVATE BusinessLayer)
