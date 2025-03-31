import re

def generate_cpp_class(className):
    # 转换类名为宏定义格式(如：ShaderResourceManager -> SHADER_RESOURCE_MANAGER)
    macro_name = re.sub(r'(?<!^)(?=[A-Z])', '_', className).upper()
    
    # 生成.h文件内容
    h_content = f"""#ifndef {macro_name}_H
#define {macro_name}_H

class {className}
{{
public:
    {className}();
    ~{className}();
    bool Initialize();
    void Clear();
}};

#endif // {macro_name}_H
"""

    # 生成.cpp文件内容
    cpp_content = f"""#include "{className}.h"

{className}::{className}()
{{
    // Constructor implementation
}}

{className}::~{className}()
{{
    // Destructor implementation
}}

bool {className}::Initialize()
{{
    // Initialization logic
    return true;
}}

void {className}::Clear()
{{
    // Cleanup logic
}}
"""

    # 写入文件
    with open(f"{className}.h", "w") as h_file:
        h_file.write(h_content)
    
    with open(f"{className}.cpp", "w") as cpp_file:
        cpp_file.write(cpp_content)

# 示例使用
if __name__ == "__main__":
    class_name = input("Enter class name: ")
    generate_cpp_class(class_name)
    print(f"Generated {class_name}.h and {class_name}.cpp")
