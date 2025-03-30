cmake_minimum_required(VERSION 3.10)

add_compile_definitions(UNICODE _UNICODE)
if(MSVC)
    add_compile_options(/utf-8)
endif()
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
project(DolasNew CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_DOURCE_DIR}/include/*.h)

add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME}
    PRIVATE   ${CMAKE_CURRENT_SOURCE_DIR}/include  # 仅当前目标使用
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/public   # 依赖此目标的其他目标自动继承
    PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/shared   # 兼具 PRIVATE + INTERFACE
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    d3d11.lib 
    dxgi.lib 
    dxguid.lib  # 关键：添加此库
)