#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<Windows.h>
#pragma comment(lib, "Ws2_32.lib")
#define BUF 256
#define SIZE 30

DWORD WINAPI sendmsg(LPVOID lp);					//发送信息函数
DWORD WINAPI recvmsg(LPVOID lp);					//接受信息函数
void ErrorHandling(char *message);					//错误处理函数

char name[SIZE]="";
char message[BUF];

int main(int argc, char *argv[]){

	SOCKET sock;
	SOCKADDR_IN servAddr;
	HANDLE threads[2];
	DWORD Id;

	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error.");
	if(argc!=3){
		printf("Usage: %s <IP> <port>\n",argv[0]);
		exit(1);
	}
	
	printf("输入你的名字：");
	scanf("%s", name);
	getchar();								//接收缓冲中的换行符
	
	//创建TCP套接字
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET)
		ErrorHandling("socket() error.");
	//初始化SOCKADDR_IN结构体
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = (atoi(argv[2]));

	//发起连接请求
	if(connect(sock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("connect() error.");
	printf("连接成功\n");
	threads[0] = CreateThread(
		NULL,
		0,
		sendmsg,
		&sock,
		0,
		&Id
		);
	threads[1] = CreateThread(
		NULL,
		0,
		recvmsg,
		&sock,
		0,
		&Id
		);
	WaitForMultipleObjects(2, threads, 1, INFINITE);
	//关闭线程
	CloseHandle(threads[0]);
	CloseHandle(threads[1]);
	printf("Over.Press anykey to end.\n");
	getchar();
	closesocket(sock);
	WSACleanup();
	return 0;
}

DWORD WINAPI sendmsg(LPVOID lp){
	int sock = *((int*)lp);
	int rec;
	char msg[SIZE + BUF];
	while(1){
		fgets(message, BUF, stdin);
		if(!strcmp(message, "q\n")||!strcmp(message, "Q\n")){
			closesocket(sock);
			exit(0);
		}
		sprintf(msg, "[%s]: %s", name, message);
		rec=send(sock, msg, strlen(msg), 0);
	}
	return 0;
}

DWORD WINAPI recvmsg(LPVOID lp){
	int sock = *((int*)lp);
	char msg[SIZE + BUF];
	int strLen;
	while(1){
		strLen = recv(sock, msg, SIZE + BUF - 1, 0);
		if(strLen == -1)
			return -1;
		msg[strLen] = 0;
		fputs(msg, stdout);
	}
	return 0;
}

void ErrorHandling(char *message){
	fputs(message,stderr);
	fputc('\n', stderr);
	exit(1);
}
