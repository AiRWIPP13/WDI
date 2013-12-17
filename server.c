#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

int main() {
    WSADATA wsadata;
    SOCKET tcpsocket;
    SOCKADDR_IN address;

    WSAStartup(MAKEWORD(2, 2), &wsadata);

    tcpsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(8080);

    bind(tcpsocket, (SOCKADDR*)(&address), sizeof(address));
    listen(tcpsocket, 1);
    tcpsocket = accept(tcpsocket, NULL, NULL);

    char buffer[1024];
    recv(tcpsocket, buffer, 1204, 0);
    int tab[100];
    int n;
    char *token=strtok(buffer," ");
    n=0;
    while (token !=NULL){
    sscanf(token, "%d", &tab[n]);
    n++;
    token=strtok(NULL, " ");
    }
    //max
    int x=0;
    int i;
    for(i=0; i<n; i++){
    if (tab[i]>x){x=tab[i];}}
    printf("%d \n",x);
    sprintf(buffer, "%d",x);
    send(tcpsocket, buffer, strlen(buffer),0);
    shutdown(tcpsocket, SD_BOTH);
    closesocket(tcpsocket);
    WSACleanup();

    return 0;
}
