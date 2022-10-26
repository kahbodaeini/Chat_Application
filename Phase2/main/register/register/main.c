#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void scn(char buffer[1000]); //done
void reg(char buffer[1000]); //done
void login(char buffer[1000]);
void cchannel(char buffer[1000]);//done
void jchannel(char buffer[1000]);
void smsg(char buffer[1000]);
void refresh(char buffer[1000]);
void channelm(char buffer[1000]);
void lchannel(char buffer[1000]);
void logout(char buffer[1000]);

int checkusername(char buffer[1000]);
int checklogin(char buffer[1000]);
int checkchannel(char buffer[1000]);

char[100] username;
char[100] channel;


FILE *usr = fopen("usernames.txt" , "w");
FILE *chn = fopen("channels.txt" , "w");

void scn(char buffer[1000]){

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


/*int checkusername(char buffer[1000]){
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
}*/

/*int checklogin(char buffer[1000]){
FILE *chn = fopen("channelnames.txt" , "r");
while(1){
char c;
char ch[100];
c = fgetc(ch);
if(c != EOF){

if(strcmp(buffer , fgets()) == 0)
}
}
}
*/
int checkchannel(char buffer[1000]){

}

void reg(char buffer[1000]){
// b equals username c equals password
int check_value;
char[30] a, b, c;

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


check_value = checkusername(buffer);
if(check_value == 1){
sscanf(buffer , "%s%s%s" , a , b , c);
b[strlen(b) - 1] = '\0';
fprintf(usr, b);
fprintf(usr , " ");
fprintf(usr , c);
fprintf(usr , '\n');
usr = strlen(b) + strlen(c) + 2 + usr;
}
if(check_value == 0){
strcpy(buffer , "The user is already taken");
		// Send the buffer to client
		send(client_socket, buffer, sizeof(buffer), 0);
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
	chat_reg(client_socket);

	// Close the socket
	shutdown(server_socket, SHUT_RDWR);
}
}

void cchannel(char buffer[1000]){
int check_value;
char[30] a, b, c;

// Function designed for chat between client and server.
void chat_cchannel(int client_socket)
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

check_value = checkchannel(buffer);
if(check_value == 1){
sscanf(buffer , "%s%s%s" , a , b , c);
b[strlen(b) - 1] = '\0';
fprintf(chn, b);
fprintf(chn , " ");
fprintf(chn , c);
fprintf(chn , '\n');
chn = chn + strlen(b) + strlen(c) + 2;
}
if(check_value == 0){
strcpy(buffer , "The channel does not exist");
		// Send the buffer to client
		send(client_socket, buffer, sizeof(buffer), 0);
}
		// If the message starts with "exit" then server exits and chat ends
		if (strncmp("exit", buffer, 4) == 0) {
			printf("Server stopping...\n");
			return;
		}
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
	chat(client_socket);

	// Close the socket
	shutdown(server_socket, SHUT_RDWR);
}

}


