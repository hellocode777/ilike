//宏定义没有返回值，比较下面两个定义，思考他们的作用。
//函数式宏定义：#define MAX(a,b) ((a)>(b)?(a):(b))
//普通函数    ： MAX(a,b) { return a>b?a:b;}
//宏定义只是字符的简单替换
#define A(a,b,c) ({a=1;b+=1;c=3;a+b+c;}) 
#include <stdio.h> 
#include "Public.h"
int Definemain()
{ 
  int a; 
  int b=1; 
  int c; 
  int d; 
  //d=A(a,b,c); 
  d=({a=1,b+=1;c=3;a+b+c;});
  printf("%d,%d,%d,%d\n",a,b,c,d); 
  return 0; 
}
