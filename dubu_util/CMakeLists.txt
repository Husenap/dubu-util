set(target_name "dubu_util")

set(src_precompiled
    "src/dubu_util/precompiled.h")

set(src_type
    "src/dubu_util/type/TypeId.cpp"
    "src/dubu_util/type/TypeId.h")

set(src_dubu_util
    "src/dubu_util/dubu_util.h")

set(src_files
    ${src_precompiled}
    ${src_type}
    ${src_dubu_util})

# Project
add_library(${target_name} STATIC ${src_files})
set_target_properties(${target_name} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${target_name}
    compiler_features
    compiler_warnings)

target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_precompile_headers(${target_name} PUBLIC ${src_precompiled})

source_group("src" FILES ${src_dubu_util})
source_group("src/type" FILES ${src_type})
source_group("src/precompiled" FILES ${src_precompiled})
source_group("src/precompiled" REGULAR_EXPRESSION "cmake_pch\.[ch]xx")

set_target_properties(${target_name} PROPERTIES FOLDER ${${PROJECT_NAME}_FOLDER})
