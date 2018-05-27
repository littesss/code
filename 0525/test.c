/*************************************************************************
	> File Name: test.c
	> Created Time: Sun 27 May 2018 11:00:35 PM CST
 ************************************************************************/
#include <stdio.h>

int gSpeedBefore = 0;
int gSpeedAfter = 0;

int main()
{
    int tmp = 0;
    int timeBefore = 0;
    int timeAfter = 0;
    
    for(;;)
    {
       
        while(1)
        {
            printf("please input speed:");
            scanf("%d", &tmp);
            printf("please input timeNow:");
            scanf("%d", &timeAfter);

            gSpeedBefore = gSpeedAfter;
            gSpeedAfter = tmp;
            
            switch (tmp)
            {
                case 1:
                    {
                        printf("this is 1\n");
                        break;
                    }
                case 2:
                    {
                        printf("this is 2\n");
                        break;
                    }
                default:
                    {
                        printf("End \n");
                        return -1;
                    }
            }
        }
    }
    
    return 0;
}
