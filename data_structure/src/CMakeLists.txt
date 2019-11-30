# 增加一个可执行的二进制
add_definitions(-std=c++11)

# 添加 ObserverPattern 子目录
add_subdirectory(array)
# 指定生成目标 
add_executable(array ArrayMain.cpp )
# 添加链接库
target_link_libraries(array ArrayFunctions)

# 添加 ObserverPattern 子目录
add_subdirectory(LinkList)
# 指定生成目标 
add_executable(LinkList LinkListMain.cpp )
# 添加链接库
target_link_libraries(LinkList LinkListFunctions)