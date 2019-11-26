# 增加一个可执行的二进制
add_definitions(-std=c++11)

# 添加 ObserverPattern 子目录
add_subdirectory(ObserverPattern)
# 指定生成目标 
add_executable( ObserverPattern ObserverPatternMain.cpp )
# 添加链接库
target_link_libraries(ObserverPattern ObserverPatternFunctions)

# 添加 TrategyPattern 子目录
add_subdirectory(TrategyPattern)
# 指定生成目标 
add_executable( TrategyPattern TrategyPatternMain.cpp )
# 添加链接库
target_link_libraries(TrategyPattern TrategyPatternFunctions)

# 添加 DecoratorPattern 子目录
add_subdirectory(DecoratorPattern)
# 指定生成目标 
add_executable( DecoratorPattern DecoratorPatternMain.cpp )
# 添加链接库
target_link_libraries(DecoratorPattern DecoratorPatternFunctions)

# 添加 FactoryPattern 子目录
add_subdirectory(FactoryPattern)
# 指定生成目标 
add_executable( FactoryPattern FactoryPatternMain.cpp )
# 添加链接库
target_link_libraries(FactoryPattern FactoryPatternFunctions)