/*************************************************************************
	> File Name: 1.cpp
	> Created Time: Wed 20 Sep 2017 03:50:01 AM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int **p;
    int arr[2][3];
    *p = &arr[0][1]; //&arr代表整个数组， *p意思是指向一个整形，
                     //arr 单独做右值的， 就是首元素的首地址

    int (*q)[3];     //而首元素又是一个拥有三个元素的一维数组
    q = arr;         //   二维数组名（单独做右值）等价于 （&一维数组名）
    
    return 0;
}