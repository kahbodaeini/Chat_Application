#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "cJSON.h"
#define MAX 80
#define PORT 12345
#define SA struct sockaddr

char *buffer[MAX];
//cJSON shit
cJSON *x = NULL;
cJSON *y = NULL;
cJSON *z = NULL;
x = cJSON_CreateObject();
cJSON_CreateString(y);
cJSON_CreateString(z);
cJSON_AddItemToObject(x , "type" , y);
cJSON_AddItemToObject(x , "content" , z);

//files
FILE *user = fopen("usernames.txt" , "w");

//prototypes
void reg(char buffer[MAX]);
int checkusername(char buffer[1000]);

int checkusername(char b[30]){
FILE *user = fopen("usernames.txt" , "r");
while(1){
char c;
char ch[100];
c = fgetc(user);
if(c != EOF){
ch = fgets(user);
if(strcmp(b , ch) == 0 ) return 0;
}
else break;
}
return 1;
}

void reg(char buffer[MAX]){
int n;
char[30] a , b , c;

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


bzero(buffer, sizeof(buffer));

		// Read the message from client and copy it to buffer
		recv(client_socket, buffer, sizeof(buffer), 0);
		// Print buffer which contains the client message
		printf("From client: %s\t To client : ", buffer);
		bzero(buffer, sizeof(buffer));
		n = 0;
		// Copy server message to the buffer
		while ((buffer[n++] = getchar()) != '\n') ;


sscanf(buffer , "%s%s%s" , a , b , c);
b[strlen(b) - 1] = '\0';
if(checkusername(b) == 0){

y = cJSON_CreateString("Error");
z = cJSON_CreateString("The user is already taken");
buffer = cJSON_Print(x);
		// Send the buffer to client
		send(client_socket, buffer, sizeof(buffer), 0);

		// If the message starts with "exit" then server exits and chat ends
		if (strncmp("exit", buffer, 4) == 0) {
			printf("Server stopping...\n");
			return;
	// Close the socket
	shutdown(server_socket, SHUT_RDWR);

    }
}

if(checkusername(b) == 1){
FILE *user = fopen("usernames.txt" , "w");
fprintf(user , b);
fprintf(user , " ");
fprintf(user , c);
fprintf(user , '\n');
user = user + strlen(b) + strlen(c) + 2;
y = cJSON_CreateString("Successful");
buffer = cJSON_Print(x);

		// Send the buffer to client
		send(client_socket, buffer, sizeof(buffer), 0);

		// If the message starts with "exit" then server exits and chat ends
		if (strncmp("exit", buffer, 4) == 0) {
			printf("Server stopping...\n");
			return;
				// Close the socket
	shutdown(server_socket, SHUT_RDWR);

		}
	}
}










