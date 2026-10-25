#include "Header.h"
void print_wsa_error();
int client(SOCKET s);
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
	
	client(s);
}


int client(SOCKET s) {
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));  
	addr.sin_family = AF_INET;	
	addr.sin_port = htons(PORT);
	if (inet_pton(AF_INET, "192.168.1.16", &addr.sin_addr) <= 0) {
		printf("Invalid address / Address not supported\n");
		closesocket(s);
		WSACleanup();
		return 1;
	}
	int result = connect(s, (struct sockaddr*)&addr, sizeof(addr));
	if (result == SOCKET_ERROR) {
		print_wsa_error();
		closesocket(s);
		WSACleanup();
		return 1;
	}
	char UserInput[256];
	if (fgets(UserInput, sizeof(UserInput), stdin) == NULL) {
		closesocket(s);
		WSACleanup();
		return 1;
	}
	int len_address = sizeof(addr);
	if (getsockname(s, (struct sockaddr*)&addr,&len_address) == SOCKET_ERROR) {
		printf("getsockname failed. Error Code: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
			
			return 1;
	};
	int localPort = ntohs(addr.sin_port);
	printf("Local port: %d\n",localPort);
	char message[272];
	sprintf_s(message, sizeof(message), "%s%d", UserInput, localPort);
	int sent = send(s, message, (int)strlen(message), 0);
	if (sent == SOCKET_ERROR) {
		print_wsa_error();
		closesocket(s);
		WSACleanup();
		return 1;
	}
	closesocket(s);
	WSACleanup();
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
