#include <iostream>
#include <stdio.h>
using namespace std;
int bit_manipulationmain()
{ 
	int a, b;
	a = 10; b = 20;// a        十进制   二进制
	//a |= b;      // a         10      1010
  //a = a|b      // b         20       10100
                 //|相同位只要一个为1即为1
                 //a|b           30        11110
                 //&相同位的两个数字都为1，则为1；若有一个不为1，则为0。
                 //a&b          0           0   
                 //^相同位不同则为1，相同则为0
                 //a^b          30          11110
                 //把内存中的0和1全部取反。使用not运算时要格外小心，你需要注意整数类型有没有符号。
                 //如果not的对象是无符号整数（不能表示负数），那么得到的值就是它与该类型上界的差，因为无符号类型的数是用00到$FFFF依次表示的。
                 //~a                       101
                 //a<<b 把a转为二进制后左移b位（在后面添b个0）
                 //a>>b 把a转为二进制后右移b位
    int c,d,f,g,h;
    c = a|b;
    d = a&b;
    f = a^b;
    g = a>>b;
    h = a<<b;
	cout <<"a=" << a << " b=" << b << " a|b=" <<c<< std::endl;//30
	cout <<"a=" << a << " b=" << b << " a&b=" <<d<< std::endl;//0
	cout <<"a=" << a << " b=" << b << " a^b=" <<f<< std::endl;//30
	cout <<"a=" << a << " b=" << b << " ~a=" <<~a<< std::endl;//-11
	cout <<"a=" << a << " b=" << b << " a>>b=" <<g<< std::endl;//0
	cout <<"a=" << a << " b=" << b << " a<<b=" <<h<< std::endl;//10485760

	return 0; 
} 
