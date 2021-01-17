# 增加一个可执行的二进制
add_definitions(-std=c++11)
add_definitions("-Wall -g")

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

# 添加 ObserverPattern 子目录
add_subdirectory(queue)
# 指定生成目标 
add_executable(queue QueueMain.cpp )
# 添加链接库
target_link_libraries(queue QueueFunctions)

# 添加 ObserverPattern 子目录
add_subdirectory(TestDay)
# 指定生成目标 
add_executable(test_day TestMain.cpp )
# 添加链接库
target_link_libraries(test_day TestFunctions)

# 添加 ObserverPattern 子目录
#add_subdirectory(Reactor)
# 指定生成目标 
#add_executable(test_reactor TestReactor.cpp )
# 添加链接库
#target_link_libraries(test_reactor ReactorFunctions)

# 添加 tcp_client 子目录
add_subdirectory(tcp_client)
# 指定生成目标 
add_executable(tcp_client_test tcp_client_main.cpp )
# 添加链接库
target_link_libraries(tcp_client_test TcpClientFunctions)

# 添加 tcp_server 子目录
add_subdirectory(tcp_server)
# 指定生成目标 
add_executable(tcp_server_test tcp_server_main.cpp )
# 添加链接库
target_link_libraries(tcp_server_test TcpServerFunctions)

# 添加 memory_plan 子目录
add_subdirectory(memory_plan)
# 指定生成目标 
add_executable(memory_plan_main memory_plan_main.cpp )
# 添加链接库
target_link_libraries(memory_plan_main MemoryPlanFunctions)

# 添加 my_easy_server 子目录
add_subdirectory(my_easy_server)
add_subdirectory(support)
# 指定生成目标 
add_executable(my_easy_server_main my_easy_server_main.cpp )
# 添加链接库
target_link_libraries(my_easy_server_main MyEasyServerFunctions reactor)

# 添加 my_easy_server 子目录
# add_subdirectory(support)
# 指定生成目标 
# add_executable(my_easy_server_main my_easy_server_main.cpp )
# 添加链接库
# target_link_libraries(my_easy_server_main reactor)

# 添加 my_easy_client 子目录
add_subdirectory(my_easy_client)
# 指定生成目标 
add_executable(my_easy_client_main my_easy_client_main.cpp )
# 添加链接库
target_link_libraries(my_easy_client_main MyEasyClientFunctions)
