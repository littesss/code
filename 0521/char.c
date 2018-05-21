/*************************************************************************
	> File Name: char.c
	> Created Time: Mon 21 May 2018 11:02:28 PM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool fun(int value1, int value2)
{
    return (value1 < value2) ? true : false;
}

int main()
{
    int i = 0;
    int j = 0;
    bool flag = true;
    char arr1[12] = {0};
    char arr2[12] = {0};
    
    char tmp1[12] = {0};
    char tmp2[12] = {0};

    int value1 = 0;
    int value2 = 0;

    strcpy(arr1, "03:10:20");
    strcpy(arr2, "03:10:03");

    while(arr1[i] != '\0' || arr2[i] != '\0')
    {
        if(arr1[i] ==  ':' || arr2[i] == ':')
        {
            i++;
        }
        tmp1[j] = arr1[i];
        tmp2[j] = arr2[i];
        j++;
        i++;
    }

    printf("tmp1:[%s]\n", tmp1);
    printf("tmp2:[%s]\n", tmp2);

    value1 = atoi(tmp1);
    value2 = atoi(tmp2);

    printf("value1:[%d]\n", value1);
    printf("value2:[%d]\n", value2);
    flag = fun(value1, value2);
    
    if(flag)
    {
        printf("value1 < value2\n");
    }
    else
    {
        printf("value1 > value2\n");
    }
    return 0;
}
