add_library(search_comp STATIC ${SRC})
target_include_directories(search_comp PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)
