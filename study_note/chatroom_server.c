#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<windows.h>
#define MAX 256
#define BUF 100
#pragma comment(lib, "Ws2_32.lib")

void ErrorHandling(char *message);					//错误处理函数
DWORD WINAPI msgHandle(LPVOID lp);					//线程执行函数
void sendMsg(char *message, int len);				//消息发送函数
HANDLE event;										//事件内核对象
int sockCount=0;									//统计套接字数量
int socks[MAX];										//管理套接字
HANDLE threads[MAX];								//管理线程

int main(int argc, char *argv[]){

	//线程ID
	DWORD Id;
	SOCKET servSock, clntSock;
	int addrSize, i;
	SOCKADDR_IN servAddr,clntAddr;

	//初始化Ws2_32.lib
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2,2), &wsaData)!=0)
		ErrorHandling("WSAStartup() error.");
	if(argc!=2){
		printf("Usage: %s <port>\n",argv[0]);
		exit(1);
	}
	
	//创建自动重置的、受信的事件内核对象
	event = CreateEvent(NULL, FALSE, TRUE, NULL);
	//创建套接字
	servSock = socket(AF_INET, SOCK_STREAM, 0);
	if(servSock == INVALID_SOCKET)
		ErrorHandling("socket() error.");

	//初始化SOCKADDR_IN结构体
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servAddr.sin_port=htons(atoi(argv[1]));

	//分配IP地址和端口号给套接字
	if(bind(servSock, (SOCKADDR*)&servAddr, sizeof(servAddr))==SOCKET_ERROR)
		ErrorHandling("bind() error.");
	if(listen(servSock, 5)==SOCKET_ERROR)
		ErrorHandling("listen() error.");
	printf("Start to listen.");
	
	addrSize=sizeof(clntAddr);
	while(1){
		printf("等待新连接\n");
		clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &addrSize);
		if(clntSock == INVALID_SOCKET){
			printf("连接失败，重连");
			continue;
		}
		WaitForSingleObject(event, INFINITE);
		threads[sockCount] = CreateThread(
			NULL,				//默认安全属性
			0,					//默认堆栈大小
			msgHandle,			//执行线程的函数
			(void*)&clntSock,	//传给函数的参数
			0,					//指定线程立即运行
			&Id					//返回线程ID
			);
		if(threads == NULL)
			ErrorHandling("Failed to create thread.");
		socks[sockCount++] = clntSock;
		//设置受信
		SetEvent(event);
		printf("接收到一个连接：%s,执行线程ID: %d\r\n", inet_ntoa(clntAddr.sin_addr), Id);
	}
	WaitForMultipleObjects(sockCount, threads, 1, INFINITE);
	for(i=0;i < sockCount; i++)
		CloseHandle(threads[i]);
	closesocket(servSock);
	WSACleanup();
	return 0;
}

void sendMsg(char *message, int len){
	int i;
	//线程一直挂起直到HANDLE句柄所指对象有信号
	WaitForSingleObject(event, INFINITE);
	for(i = 0;i < sockCount; i++)
		send(socks[i], message, len, 0);
	//设置HANDLE句柄对象为发信号状态
	SetEvent(event);
}

//返回类型为DWORD，WINAPI是个宏，是函数调用形式，最终是_stdcall形式
DWORD WINAPI msgHandle(LPVOID lp){
	int clntSock = *((int*)lp);
	int strLen = 0, i;
	char message[BUF];

	while((strLen = recv(clntSock, message, sizeof(message), 0)) != -1){
		sendMsg(message, strLen);
		printf("发送成功\n");
	}
	//显示当前线程唯一标识符
	printf("客户端退出：%d\n", GetCurrentThreadId());
	WaitForSingleObject(event, INFINITE);
	for(i = 0;i < sockCount; i++){
		if(clntSock == socks[i]){
			while(i++ < sockCount - 1)
				socks[i] = socks[i + 1];
			break;
		}
	}
	sockCount--;
	//设置hEvent句柄受信
	SetEvent(event);
	closesocket(clntSock);
	return 0;
}

void ErrorHandling(char *message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
