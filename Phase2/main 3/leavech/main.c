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


int leavech(char authtoken[],int client_socket){
    char channel[MAX],chname[MAX];
    if((cn=fopen("channelname.txt", "r"))!=NULL){
            fgets(channel, MAX, cn);
            fclose(cn);
    }
    strcpy(chname, channel);
    strcat(channel, ".channel.json");
    char usn[MAX];
    if((at=fopen("authtok.txt", "r"))!=NULL){
        fgets(authtok, 25, at);
        fclose(at);
    }
    if (strncmp(authtok, authtoken, 24)==0) {
        if(dircheck(channel)==0){
            channels=fopen(channel, "r");
            char tmsg[MAX];
            fgets(tmsg, MAX, channels);
            fclose(channels);
            channels=fopen(channel, "w");
            cJSON *curde=cJSON_Parse(tmsg);
    cJSON *messages = NULL;
        cJSON *msg=NULL;
        cJSON *sender=NULL;
        messages= cJSON_GetObjectItem(curde, "messages");
        sender=cJSON_CreateString("server");
        char wtwam[MAX];
            if((un=fopen("username.txt", "r"))!=NULL){

                fgets(usn, MAX, un);
                fclose(un);
        }
        strcpy(wtwam, usn);
        strcat(wtwam, " left ");
        strcat(wtwam, chname);
        strcat(wtwam, ".");
        msg=cJSON_CreateString(wtwam);
        cJSON *eachmsg=cJSON_CreateObject();
        cJSON_AddItemToObject(eachmsg, "sender", sender);
        cJSON_AddItemToObject(eachmsg, "content", msg);
        cJSON_AddItemToArray(messages, eachmsg);
        cJSON *mems = NULL;
            cJSON *mem = NULL;
        mems=cJSON_GetObjectItem(curde, "members");
            int i=0;
            cJSON_ArrayForEach(mem, mems){
                if (strcmp(mem->valuestring,usn)==0) {
                    cJSON_DeleteItemFromArray(mems, i);
                }
                i++;
            }
        char* wtp=cJSON_PrintUnformatted(curde);
        fprintf(channels, "%s",wtp);
        fclose(channels);
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
    }
    else{
        cJSON *content = NULL;
          cJSON *type = NULL;
          cJSON *err = cJSON_CreateObject();
          content = cJSON_CreateString("Wrong AuthToken.");
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
