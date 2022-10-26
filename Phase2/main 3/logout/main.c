#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include<time.h>
#include "cJSON.c"
#define MAX 1000
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


void logout(char authtoken[],int client_socket){
    if((at=fopen("authtok.txt", "r"))!=NULL){
        fgets(authtok, 25, at);
        fclose(users);
    }
    if (memcmp(authtok, authtoken, 24)==0) {
        char atok[24];
        if((at=fopen("authtok.txt", "w"))!=NULL){
            for (int i=0; i<24; i++) {
                atok[i]='a';
            }
            fprintf(at, "%s\n",atok);
            fclose(at);
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
