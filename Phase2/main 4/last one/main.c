#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include "cJSON.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#define MAX 1000
#define PORT 12345

int main(){

char a[30] , b[30] , c[30] , buffer[MAX];

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
		while ((buffer[n++] = getchar()) != '\n') ;
sscanf(buffer , "%s%s%s" , a , b ,c);

if(strcmp(a , "register") == 0) reg(buffer);
if(strcmp(a , "login") == 0) login(buffer);
if(strcmp(a , "create") == 0) cchannel(buffer);
if(strcmp(a , "join") == 0) jchannel(buffer);
if(strcmp(a , "send") == 0) smsg(buffer);
if(strcmp(a , "Refresh") == 0) refresh(buffer);
if(strcmp(a , "channel") == 0) channelm(buffer);
if(strcmp(a , "leave") == 0) lchannel(buffer);
if(strcmp(a , "logout") == 0) logout(buffer);

    }
}

void reg(char buffer[MAX]){

int checkusername(char buffer[1000]);

//cJSON shit
cJSON *x = NULL;
cJSON *y = NULL;
cJSON *z = NULL;
x = cJSON_CreateObject();
cJSON_CreateString(y);
cJSON_CreateString(z);
cJSON_AddItemToObject(x , "type" , y);
cJSON_AddItemToObject(x , "content" , z);


int checkusername(char b[30]){
FILE *user = fopen("usernames.txt" , "r");
while(1){
char c;
char ch[100];
c = fgetc(user);
if(c != EOF){
ch = fgets(user);
if(strcmp(b , ch) == 0 ) {
fclose(user);
return 0;
    }
}
else break;
}
fclose(user);
return 1;
}
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
    main();
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
    main();
	}
}




void login(char buffer[MAX]){

//cJSON shit
cJSON *x = NULL;
cJSON *y = NULL;
cJSON *z = NULL;
x = cJSON_CreateObject();
cJSON_CreateString(y);
cJSON_CreateString(z);
cJSON_AddItemToObject(x , "type" , y);
cJSON_AddItemToObject(x , "content" , z);

int check_login(char buffer[MAX]){
char a[30] , b[30] , c[30];
sscanf(buffer, "%s%s%s", a , b , c);
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

sscanf(buffer , "%s%s%s" , a , b ,c);

b[strlen(b) - 1] = '\0';

if(checklogin(b , c) == 0){

struct us_tk{
char user[30];
char tok[32];
};
us_tk

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



}
