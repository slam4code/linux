//
// Created by shen on 17-4-17.
//

#include <cstddef>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <iostream>
using  namespace std;

int main()
{

    int sockfd;
    struct  sockaddr_in servaddr;
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(8001);
    inet_pton(AF_INET,"115.28.72.50",&servaddr.sin_addr);

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==-1)
    {
        perror("sock()=-1");
        exit(1);
    }

    int count=0;
    char sendline[]="hello world .... ";
    char recvline[1024];


    while (count<1000)
    {

        sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr *)&servaddr,sizeof(servaddr));

        int n=recvfrom(sockfd,recvline,1024,0,NULL,NULL);
        cout<<"[recv]:"<<recvline<<" "<<count<<endl;
        ++count;
    }
    return 0;
}
