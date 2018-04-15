#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[64] = {0};
	char *ptemp = arr;
	char *subchar = NULL;
	int length = 0;
	char subFirst[64] = {0};
	char cFirstChar = ' ';
	char All[64] = {0};
	char matchfirst[64] = {0};
	char *pmatchfirst = NULL;
	char *pIfend = NULL;
	char *pspacesencond = NULL;
	char matchsencond[64] = {0};
	char *pmatchsencond = NULL;
	char *overchar = NULL;
	char *pspace =  NULL; //第一个空格
	strcpy(arr, "时间：2018 地点: 西安 西安 天气： 晴天");
//	strcpy(arr, "AA: a BB: d d CC: c");
	printf("arr:[%s]\n",arr);
	subchar = strstr(ptemp, "地点:");	
//	subchar = strstr(ptemp, "BB");
	if(subchar)
	{
		printf("subchar:[%s]\n",subchar);
	}
	else
	{
		printf("NULL");
	}
	length = sizeof("西安：");

	subchar += length; //子指针走到第一个西安处
	strncpy(All, arr, (subchar - arr -1));
	printf("1length:[%d]\n",length);
	printf("2subchar:[%s]\n",subchar);
	printf("3All:[%s]\n", All);
	
	pspace = strstr(subchar, " ");
	pspace++ ;
	printf("4pspace:[%s]\n", pspace);
	strncpy(matchfirst ,pspace, (pspace - subchar));
	pmatchfirst = matchfirst;
	printf("5matchfirst:[%s]\n", matchfirst);
	
	printf("6#subchar:[%s]\n",subchar);
	overchar = strstr(subchar, pmatchfirst); //指向str1首次出现的地址
	overchar += strlen(pmatchfirst);
	
	printf("7oooooovervhar:[%s]\n", overchar);
	
	//第二个是否匹配
	pspacesencond = strstr(overchar, " ");
	pspacesencond++ ; //走到天气
	printf("====pspace:[%s]\n", pspacesencond);
	strncpy(matchsencond , overchar, (pspacesencond - overchar- strlen(" ")));
	pmatchsencond = matchsencond;
	printf("sencondchar[64] = [%s]\n",matchsencond);
	printf("matchsencond:[%s]\n", pspacesencond);
    pIfend = strstr(pspacesencond, matchsencond);
	if(pIfend) //第二个没有匹配上，就说明结束了
	{
		printf("sencondchar[64] = [%s]\n",matchsencond);
		printf("psencond:[%s]\n",pmatchsencond);
		printf("only one is over!!!!");
		strcat(All, pspace);
	}
	else
	{
		printf("sencond is NULL is over!!!!");
		strcat(All, overchar);
	}


	printf("oooooovervhar:[%s]\n", overchar);
	printf("End All char:[%s]\n", All);

	
	return 0;
}













/*************************************************************************
	> File Name: a.cpp
	> Created Time: Sun 17 Sep 2017 04:34:24 AM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 9999
#define Seraddr "192.168.0.72"

int main(int argc, char ** argv)
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in addrSer, addrPeer;//
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(PORT);
    addrSer.sin_addr.s_addr = inet_addr(Seraddr);

    socklen_t len = sizeof(struct sockaddr_in);
    int ret = bind(sockfd, (struct sockaddr*)&addrSer, len);//服务端必须填充自己的sockaddr_in,以便对客户端来用
    if(ret == -1)
    {
        perror("bind");
        exit(1);
    }

    char recvbuff[1024];
    char sendbuff[1024];
    struct in_addr addr;
    while(1)
    {
        recvfrom(sockfd, recvbuff, 1024, 0, (struct sockaddr*)&addrPeer, &len);
        addr.s_addr = addrPeer.sin_addr.s_addr; //获取对端地址,前提对端必须绑定地址
        cout << "Cli.addr:" << inet_ntoa(addr) << endl;
        //cout << addr.s_addr << endl;  网络地址
        cout << "Cli:>" << recvbuff << endl;

        cout << "Ser:>";
        cin >> sendbuff;
        sendto(sockfd, sendbuff, 1024, 0, (struct sockaddr*)&addrPeer, len);
    }


    return 0;
}
