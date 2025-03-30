cmake_minimum_required(VERSION 3.10)

add_compile_definitions(UNICODE _UNICODE)

# 获取项目根目录的绝对路径（并替换反斜杠为斜杠，避免转义问题）
get_filename_component(PROJECT_ROOT_DIR "${CMAKE_SOURCE_DIR}" ABSOLUTE)
# 将路径中的反斜杠 (\) 替换为正斜杠 (/)，避免 C++ 字符串转义问题
message(STATUS "MY_VARIABLE = ${PROJECT_ROOT_DIR}")
# 定义宏 PROJECT_ROOT_DIR，值为项目根目录路径
add_definitions(-DPROJECT_ROOT_DIR="${PROJECT_ROOT_DIR}")


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
    d3dcompiler.lib
)

