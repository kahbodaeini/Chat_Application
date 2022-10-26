#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#define MAX 80
#define PORT 12345
#define SA struct sockaddr

FILE *usr = fopen("usernames.txt" , "w");

void reg(char buffer[MAX]){
char[30] a;
char[30] b;
char[30] c;

// Function designed for chat between client and server.
void chat_reg(int client_socket)
{
	char buffer[MAX];
	int n;
	while (true) {
		bzero(buffer, sizeof(buffer));

		// Read the message from client and copy it to buffer
		recv(client_socket, buffer, sizeof(buffer), 0);

		// Print buffer which contains the client message
		printf("From client: %s\t To client : ", buffer);
		bzero(buffer, sizeof(buffer));
		n = 0;
		// Copy server message to the buffer
		while ((buffer[n++] = getchar()) != '\n')


int checkusername(char buffer[1000]){
FILE *usr = fopen("usernames.txt" , "r");
while(1){
char c;
char ch[100];
c = fgetc(ch);
if(c != EOF){
ch = fgets()
if(strcmp(buffer , fgets(ch)) == 0) return 0;
}

else break;
}
return 1;
}

if(checkusername(buffer) == 0) {
strcpy(buffer , "the user is already taken");
// Send the buffer to client
		send(client_socket, buffer, sizeof(buffer), 0);
}

if(checkusername(buffer) == 1){

sscanf(buffer , "%s%s%s" , a , b , c);
b[strlen(b) - 1] = '\0';
fprintf(usr, b);
fprintf(usr , " ");
fprintf(usr , c);
fprintf(usr , '\n');
usr = strlen(b) + strlen(c) + 2 + usr;
}
}


		// If the message starts with "exit" then server exits and chat ends
		if (strncmp("exit", buffer, 4) == 0) {
			printf("Server stopping...\n");
			return;
		}
	}


// Driver function
int build_socket()
{
	int server_socket, client_socket;
	struct sockaddr_in server, client;

	// Create and verify socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		printf("Socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");

	// Assign IP and port
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);

	// Bind newly created socket to given IP and verify
	if ((bind(server_socket, (SA*)&server, sizeof(server))) != 0) {
		printf("Socket binding failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully bound..\n");

	// Now server is ready to listen and verify
	if ((listen(server_socket, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");

	// Accept the data packet from client and verify
	socklen_t len = sizeof(client);
	client_socket = accept(server_socket, (SA*)&client, &len);
	if (client_socket < 0) {
		printf("Server accceptance failed...\n");
		exit(0);
	}
	else
		printf("Server acccepted the client..\n");

	// Function for chatting between client and server
	chat-reg(client_socket);

	// Close the socket
	shutdown(server_socket, SHUT_RDWR);
}

}

