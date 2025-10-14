file(GLOB_RECURSE ISPCTC_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE ISPCTC_ISPC_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.ispc")

set(ISPC_COMPILER "${CMAKE_CURRENT_SOURCE_DIR}/../ISPC/win/ispc.exe" CACHE FILEPATH "Path to ISPC compiler")

function(compile_ispc INPUT_FILE OUTPUT_LIST)
    get_filename_component(FILE_WE ${INPUT_FILE} NAME_WE)
    set(OUTPUT_OBJ "${CMAKE_CURRENT_BINARY_DIR}/${FILE_WE}.obj")
    set(OUTPUT_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/${FILE_WE}.h")

    add_custom_command(
        OUTPUT ${OUTPUT_OBJ} ${OUTPUT_HEADER}
        COMMAND ${ISPC_COMPILER}
            ${INPUT_FILE}
            --target=sse2
            --arch=x86-64
            -O2
            -o ${OUTPUT_OBJ}
            -h "${OUTPUT_HEADER}"
            --opt=fast-math
        DEPENDS ${INPUT_FILE}
        COMMENT "Compiling ISPC: ${INPUT_FILE}"
        VERBATIM
    )

    set(${OUTPUT_LIST} ${${OUTPUT_LIST}} ${OUTPUT_OBJ} PARENT_SCOPE)
endfunction()

set(ISPC_OBJECTS)
foreach(ISPC_FILE ${ISPCTC_ISPC_SOURCES})
    compile_ispc(${ISPC_FILE} ISPC_OBJECTS)
endforeach()

add_library(ispc_texcomp STATIC ${ISPCTC_SOURCES} ${ISPC_OBJECTS})
target_include_directories(ispc_texcomp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")