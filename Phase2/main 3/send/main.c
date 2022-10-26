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

void send(char buffer[MAX]){

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



    if((cn=fopen("channelname.txt", "r"))!=NULL){
            fgets(channel, MAX,cn);
            fclose(cn);
    }
    else{
        cJSON *content = NULL;
          cJSON *type = NULL;
          cJSON *err = cJSON_CreateObject();
          content = cJSON_CreateString("You are not in this channel.");
          type= cJSON_CreateString("Error");
          cJSON_AddItemToObject(err, "type", type);
          cJSON_AddItemToObject(err, "content", content);
          char*errors=cJSON_PrintUnformatted(err);
          send(client_socket,errors,strlen(errors),0);
          close(client_socket);
        return 0;
    }
    strcpy(chname, channel);
    strcat(channel, ".channel.json");
    char usn[MAX];
    if((at=fopen("authtok.txt", "r"))!=NULL){
        fgets(authtok, 25, at);
        fclose(users);
    }
    if((un=fopen("username.txt", "r"))!=NULL){
            fgets(usn, MAX, un);
            fclose(un);
    }
    if (strncmp(authtok, authtoken, 24)==0) {
        if(dircheck(channel)==0){
            if((channels=fopen(channel, "r"))!=NULL){
                printf("1");
            fgets(tmsg, MAX, channels);
            fclose(channels);
            }
             if((channels=fopen(channel, "w"))!=NULL){
                 printf("1");
            cJSON *curde=cJSON_Parse(tmsg);
    cJSON *messages = NULL;
        cJSON *msg=NULL;
        cJSON *sender=NULL;
        messages= cJSON_GetObjectItem(curde, "messages");
        sender=cJSON_CreateString(usn);
        msg=cJSON_CreateString(messagets);
        cJSON *eachmsg=cJSON_CreateObject();
        cJSON_AddItemToObject(eachmsg, "sender", sender);
        cJSON_AddItemToObject(eachmsg, "content", msg);
        cJSON_AddItemToArray(messages, eachmsg);
        char* wtp=cJSON_PrintUnformatted(curde);
        fprintf(channels, "%s\n",wtp);
        fclose(channels);
             }
        cJSON *content = NULL;
        cJSON *type = NULL;
        cJSON *err = cJSON_CreateObject();
           content = cJSON_CreateString("");
        type= cJSON_CreateString("Successful");
           cJSON_AddItemToObject(err, "type", type);
        cJSON_AddItemToObject(err, "content", content);
        char*errors=cJSON_PrintUnformatted(err);
        send(client_socket,errors,strlen(errors),0);
        shutdown(client_socket, SHUT_RDWR);
        return 0;
    }
    }
    else{
        cJSON *content = NULL;
          cJSON *type = NULL;
          cJSON *err = cJSON_CreateObject();
          content = cJSON_CreateString("Wrong AuthToken");
          type= cJSON_CreateString("Error");
          cJSON_AddItemToObject(err, "type", type);
          cJSON_AddItemToObject(err, "content", content);
          char*errors=cJSON_PrintUnformatted(err);
          send(client_socket,errors,strlen(errors),0);
          close(client_socket);
        return 0;

    }
    return 0;

}
