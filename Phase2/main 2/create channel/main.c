#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#define MAX 80
#define PORT 12345
#define SA struct sockaddr

FILE *chn = fopen("channels.txt" , "w");

void cchannel(char buffer[MAX]){

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
		while ((buffer[n++] = getchar()) != '\n') ;

int check_channel(char buffer{MAX}){

FILE *chn = fopen("channels.txt" , "r");
while(1){
char c;
char ch[100];
c = fgetc(ch);
if(c != EOF){
ch = fgets(chn)
if(strcmp(buffer , ch) == 0) return 0;
chn += strlen(ch);
}

else break;
}
return 1;
}
}
if(check_channel(buffer) == 0) {
strcpy(buffer , "channel does not exist");
// Send the buffer to client
		send(client_socket, buffer, sizeof(buffer), 0);
}

if(check_channel(buffer) == 1){

sscanf(buffer , "%s%s%s" , a , b , c);
b[strlen(b) - 1] = '\0';
fprintf(chn, b);
fprintf(chn , " ");
fprintf(chn , c);
fprintf(chn , '\n');
chn = strlen(b) + strlen(c) + 2 + chn;
}
}


}

