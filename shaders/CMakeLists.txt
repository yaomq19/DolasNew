# 定义 HLSL 着色器文件列表
set(HLSL_SHADERS Triangle.hlsl)

# 创建自定义编译目标
add_custom_target(CompileShadersHLSL)

foreach(SHADER ${HLSL_SHADERS})
    get_filename_component(SHADER_NAME ${SHADER} NAME_WE)
    # 调用 fxc 编译命令
    add_custom_command(
        TARGET CompileShadersHLSL
        COMMAND 
        fxc
        /T vs_5_0
        /E VS_Entry
        /D VERTEX_SHADER=1
        /Fo ${CMAKE_BINARY_DIR}/shaders/${SHADER_NAME}.vs.cso
        ${SHADER}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Compiling HLSL: ${SHADER}"
    )

    add_custom_command(
        TARGET CompileShadersHLSL
        COMMAND 
        fxc
        /T ps_5_0
        /E PS_Entry
        /D PIXEL_SHADER=1
        /Fo ${CMAKE_BINARY_DIR}/shaders/${SHADER_NAME}.ps.cso
        ${SHADER}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Compiling HLSL: ${SHADER}"
    )
endforeach()