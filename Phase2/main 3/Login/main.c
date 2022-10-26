#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include<time.h>
#include "cJSON.c"
#define MAX 80
#define PORT 12345
#define SA struct sockaddr

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
FILE *tok = fopen("tokens.txt" , "w");

//prototypes
void login(char buffer[MAX]);
int checklogin(char b[30] , char c [30]);
void assign_token(void);

void(assign_token(char b[30])){
char token[32];
srand(time(0));
FILE *tok = fopen("tokens.txt" , "w");
fprintf(tok , b);
fprintf(tok , " ");
for(int i = 0 ; i < 32 ; i++){
token[i] = rand() % 10;
}
fprintf(tok , token[32]);
fprintf(tok , '\n');
}

int checklogin(char b[30] , char c[30]){

FILE *user = fopen("usernames.txt" , "r");

while(1){
char c;
char us[30] , ps[30];
c = fgetc(user);
if(c != EOF){
us = fgets(user);
if(strcmp(ch , b) == 0){
ps = fgets(user);
if(strcmp(ps , c) == 0){
fclose(user);
return 1;
}
if(strcmp(ps , c) != 0){
fclose(user);
return 0;
}
}
}
else break;
}
fclose(user);
return -1;
}

void login(char buffer[MAX]){

int n;
char a[30] , b[30] , c[30];

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

sscanf(buffer , "%s%s%s" , a , b ,c);

b[strlen(b) - 1] = '\0';

if(checklogin(b , c) == 0){
assign_token();
y = cJSON_CreateString("AuthToken");
z = cJSON_CreateString(tok[32]);
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
if(checklogin(b , c) == 1){
y = cJSON_CreateString("Error");
z = cJSON_CreateString("Password is wrong");
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
if(checklogin(b , c) == -1){
y = cJSON_CreateString("Error");
z = cJSON_CreateString("The user does not exist");
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
