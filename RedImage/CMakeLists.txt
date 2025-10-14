file(GLOB_RECURSE RDIMG_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.*")

add_library(RedImage SHARED ${RDIMG_SOURCES})
target_compile_definitions(RedImage PRIVATE REDCORE_EXPORTS)
target_include_directories(RedImage PRIVATE "../deps/nvtt/src")
target_include_directories(RedImage PRIVATE "../deps/nvtt/extern/poshlib")

target_link_libraries(RedImage PRIVATE ispc_texcomp)
target_link_libraries(RedImage PRIVATE nvtt)