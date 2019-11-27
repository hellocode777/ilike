/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2017年10月14日, 下午2:25
 */

#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
using namespace std;

/*
 * 
 */
int
main(int argc, char** argv)
{
    DIR *m_dirp;//是一个内部结构，用这个内部结构保存当前正在被读取的目录的有关信息, m_dirp = opendir("/home/afcadmin/zs");
    /*
     * struct dirent *readdir(DIR *dp);    
     * void rewinddir(DIR *dp);   
     * int closedir(DIR *dp);   
     * long telldir(DIR *dp);   
     * void seekdir(DIR *dp,long loc);  
     */
    struct dirent *dp;
    int m_iF = access("/home/afcadmin/zs", F_OK);
    if(m_iF == 0)
    {
        printf("目录zs存在\n");
        m_dirp = opendir("/home/afcadmin/zs");
        if(m_dirp != NULL)
        {
            while((dp = readdir(m_dirp)) != NULL)
            {
                if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
                {
                    if(dp->d_type != DT_DIR)//判断这个文件的文件类型是否是目录
                    {
                        printf("目录下的文件有：%s\n", dp->d_name);
                    }
                }
            }
            closedir(m_dirp);
        }
    }
    else
    {
        printf("目录zs不存在\n");
    }
    return 0;
}
/*
 * 最后，总结一下，想要获取某目录下（比如a目下）b文件的详细信息，我们应该怎样做？
 * 首先，我们使用opendir函数打开目录a，返回指向目录a的DIR结构体c。
 * 接着，我们调用readdir( c)函数读取目录a下所有文件（包括目录），返回指向目录a下所有文件的dirent结构体d。
 */

