CMAKE_MINIMUM_REQUIRED( VERSION 3.10 ) #设定使用的cmake的版本
PROJECT( code ) #设定项目或工程名
#SET( CMAKE_CXX_COMPILER "g++") #设定编译器
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread" )

#设定编译后生成的可执行二进制文件所在的目录
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#设定编译后生成的库文件所在的目录
SET( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#并且把该目录设为链接目录
LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib)

#设定头文件所在的目录
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include)

#如果希望进入源代码文件夹仍可以继续使用cmake，则需增加文件夹
ADD_SUBDIRECTORY( ${PROJECT_SOURCE_DIR}/src)


