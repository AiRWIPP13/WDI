#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

int main() {
    int tab[100];
    int n;
    int i;
    scanf("%d", &n);
    for (i=0; i<n; i++){
    scanf("%d", &tab[i]);
    }
    char buffer[1024];
    memset(buffer, 0, 1024);
    sprintf(buffer, "%d", tab[0]);
    for (i=1; i<n; i++){
        sprintf(buffer, "%s %d", buffer, tab[i]);
        }
    WSADATA wsadata;
    SOCKET tcpsocket;
    SOCKADDR_IN address;

    WSAStartup(MAKEWORD(2, 2), &wsadata);

    tcpsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(8080);

    int status = connect(tcpsocket, (SOCKADDR*)(&address), sizeof(address));
    if (status == 0) {
        send(tcpsocket, buffer, strlen(buffer),0);
    }
    memset(buffer, 0, 1024);
    recv(tcpsocket, buffer, 1204, 0);
    printf("%s",buffer);
    shutdown(tcpsocket, SD_BOTH);
    closesocket(tcpsocket);
    WSACleanup();

    system("pause");
    return 0;
}
