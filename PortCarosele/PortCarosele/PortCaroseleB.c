#include "Header.h"

void print_wsa_error();
int server(SOCKET s);
int main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		print_wsa_error();
		return 1;
	}
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET) {
		print_wsa_error();
		return 1;
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(s, (struct sockaddr*)&addr, sizeof(addr)))
	{
		print_wsa_error();
		closesocket(s);
		return 1;
	}
	server(s);
	return 0;
}
int server(SOCKET s)
{
	if (listen(s, SOMAXCONN) == SOCKET_ERROR)
	{
		print_wsa_error();
		closesocket(s);
		return 1;
	}
	SOCKET clientSocket = accept(s, NULL, NULL);
	if (clientSocket == INVALID_SOCKET)
	{
		print_wsa_error();
		closesocket(s);
		return 1;
	}
	char recvBuffer[BUFFER_SIZE];
		int recivedBytes = recv(clientSocket, recvBuffer, BUFFER_SIZE - 1, 0);
		if (recivedBytes == SOCKET_ERROR)
		{
			print_wsa_error();
			closesocket(clientSocket);
			closesocket(s);
			return 1;
		}
		else if (recivedBytes == 0)
		{
			printf("Client disconnected.\n");
			return 0;
		}
		else
		{
			recvBuffer[recivedBytes] = '\0';
			char* portText = strchr(recvBuffer, '\n');
			if (portText != NULL) {
				*portText = '\0';
				printf("Received: %s\n", recvBuffer);
				int client_local_port = atoi(portText + 1);
				printf("Received client's local port: %d\n", client_local_port);
			} else {
				printf("Received: %s\n", recvBuffer);
			}
		}
	closesocket(clientSocket);
	closesocket(s);
	return 0;
}
void print_wsa_error() {
	int errorCode = WSAGetLastError();
	char* errorMessage = NULL;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR)&errorMessage,
		0,
		NULL
	);
	if (errorMessage) {
		printf("WSA Error %d: %s\n", errorCode, errorMessage);
		LocalFree(errorMessage);
	}
	else {
		printf("WSA Error %d: Unable to retrieve error message.\n", errorCode);
	}

}
