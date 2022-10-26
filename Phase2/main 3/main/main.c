#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#define MAX 80
#define PORT 12345
#define SA struct sockaddr
int main(){

scan(buffer);

return 0;
}

void scan(char buffer[MAX]){

sscanf(buffer , "%s%s%s" , a , b , c);

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
