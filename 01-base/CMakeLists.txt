cmake_minimum_required(VERSION 3.10.2)

# vscode 支持不高，如果需要由自动完成功能，要设置一个include目录
# 视频中设置错目录了，所以找不到头文件
include_directories(/usr/local/eosio.cdt/include)

add_subdirectory(base)
add_subdirectory(hello)
add_subdirectory(test)