#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.c"
#include <sys/socket.h>
#define MAX 80
#define PORT 12345
#define SA struct sockaddr

char bufferemon[1000], cJSON_content[1000], cJSON_type[1000], messages[100000] , token[1000];

int reza(int x)
{
    if(x == 1)//main menu
    {
        int a;
        printf("1 : Register\n2 : Login\n3 : Exit\n");
        scanf("%d", &a);
        if(a == 1)
            reza(2);
        if(a == 2)
            reza(3);
        if(a == 3)
            exit(0);
    }
    if(x == 2)//register
    {
        char username[100];
        char password[100];
        char space[] = ", ";
        char reg[100] = "register ";//age nashod strcat kon


        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");


        printf("Enter Your User Name\n");
        scanf("%s", username);
        printf("Enter Your Password\n");
        scanf("%s", password);
        strcat(reg, username);
        strcat(reg, ", ");
        strcat(reg, password);
        memset(bufferemon , 0 , sizeof(bufferemon));
        strcpy(bufferemon, reg);
        printf("%s",bufferemon);



        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        memset(bufferemon , 0 , sizeof(bufferemon));
        recv(client_socket, bufferemon, sizeof(bufferemon), 0);

        cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        strcat(cJSON_content, cJSON_GetObjectItem(response, "content") -> valuestring);
        cJSON_Delete(response);

        if (strcmp("Error", cJSON_type) == 0)
        {
            printf("%s\n", cJSON_content);
            reza(1);
        }
        if (strcmp("Successful", cJSON_type) == 0)
        {
            reza(1);
        }

        shutdown(client_socket,SD_BOTH);

    }
    if(x == 3)
    {
        char username[100];
        char password[100];
        char space[2] = ", ";
        char login[1000] = "login ";
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        printf("Enter Your User Name\n");
        scanf("%s", username);
        printf("Enter Your Password\n");
        scanf("%s", password);
        strcat(login, username);
        strcat(login, space);
        strcat(login, password);
        memset(bufferemon , 0 , sizeof(bufferemon));
        strcpy(bufferemon, login);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, bufferemon, sizeof(bufferemon), 0);
                cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        strcat(cJSON_content, cJSON_GetObjectItem(response, "content") -> valuestring);
        cJSON_Delete(response);
        strcpy(token , cJSON_content );

        if (strcmp("Error", cJSON_type) == 0)
        {
            printf("%s\n", cJSON_content);
            reza(1);
        }
        if (strcmp("Successful", cJSON_type) == 0)
        {
            reza(5);
        }

        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SD_BOTH);
        //if (!strcmp())
        //    reza(5);
    }
    if(x == 5)
    {
        int b;
        printf("1 : Create Channel\n2 : Join Channel\n3 : Logout\n");
        scanf("%d", &b);
        if(b == 1)
            reza(6);
        if(b == 2)
            reza(7);
        if(b == 3)
            reza(8);
    }
    if(x == 6)
    {
        char channelname[100];
        char token[100];
        char space[2] = ", ";
        char cch[1000] = "create channel ";
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        printf("Enter Your Channel Name\n");
        scanf("%s", channelname);
        printf("Enter Your Token\n");
        scanf("%s", token);
        strcat(cch, channelname);
        strcat(cch, space);
        strcat(cch, token);
        strcpy(bufferemon, cch);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, cch, sizeof(cch), 0);
                cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        strcat(cJSON_content, cJSON_GetObjectItem(response, "content") -> valuestring);
        cJSON_Delete(response);

        if (strcmp("Error", cJSON_type) == 0)
        {
            printf("%s\n", cJSON_content);
            reza(5);
        }
        if (strcmp("Successful", cJSON_type) == 0)
        {
            reza(9);
        }

        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SD_BOTH);
        reza(9);
    }
    if(x == 7)
    {
        char channelname[100];
        char space[2] = ", ";
        char jch[1000] = "join channel ";
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        printf("Enter Your Channel Name\n");
        scanf("%s", channelname);
        strcat(jch, channelname);
        strcat(jch, space);
        strcat(jch, token);
        strcpy(bufferemon, jch);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, jch, sizeof(jch), 0);
                cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        strcat(cJSON_content, cJSON_GetObjectItem(response, "content") -> valuestring);
        cJSON_Delete(response);

        if (strcmp("Error", cJSON_type) == 0)
        {
            printf("%s\n", cJSON_content);
            reza(5);
        }
        if (strcmp("Successful", cJSON_type) == 0)
        {
            reza(9);
        }

        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SD_BOTH);
        reza(9);
    }
    if(x == 8)
    {
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        char lo = "logout ";
        strcat(lo, token);
        strcpy(bufferemon, lo);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, lo, sizeof(lo), 0);
                cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        strcat(cJSON_content, cJSON_GetObjectItem(response, "content") -> valuestring);
        cJSON_Delete(response);

        if (strcmp("Error", cJSON_type) == 0)
        {
            printf("%s\n", cJSON_content);
            reza(5);
        }
        if (strcmp("Successful", cJSON_type) == 0)
        {
            reza(1);
        }

        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SD_BOTH);
        reza(1);
    }
    if(x == 9)
    {
        int c;
        printf("1 : Send Message\n2 : Refresh\n3 : Channel Members\n4 : Leave Channel\n");
        scanf("%d", &c);
        if(c == 1)
            reza(10);
        if(c == 2)
            reza(11);
        if(c == 3)
            reza(12);
        if(c == 4)
            reza(13);
    }
    if(x == 10)
    {
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        char snd = "send ";
        char msg[400];
        char space = ", ";
        printf("Enter Your Message\n");
        scanf("%s", msg);
        strcpy(snd, msg);
        strcpy(snd, space);
        strcpy(snd, token);
        strcpy(bufferemon, snd);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, bufferemon, sizeof(bufferemon)), 0);
cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        strcat(cJSON_content, cJSON_GetObjectItem(response, "content") -> valuestring);
        cJSON_Delete(response);

        if (strcmp("Error", cJSON_type) == 0)
        {
            printf("%s\n", cJSON_content);
            reza(9);
        }
        if (strcmp("Successful", cJSON_type) == 0)
        {
            reza(9);
        }
        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SD_BOTH);
        reza(9);
    }
    if(x == 11)//refresh
    {
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;


        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        char ref[100] = "refresh ";
        strcat(ref, token);
        strcpy(bufferemon, ref);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, bufferemon, sizeof(bufferemon), 0);

	
        cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        cJSON messages = cJSON_GetObjectItem(response, "content");

	if (!strcmp(cJSON_type, "Error"))
	{
		printf("Refresh failed\n");
		reza(9);
	}

        for(int i = 0; i < cJSON_GetArraySize(messages); i++)
        {
            printf("%s : %s \n", cJSON_GetArrayItem(messages, "sender")->valuestring, cJSON_GetArrayItem(messages, "content")->valuestring);
        }
        cJSON_Delete(response);






        // Print buffer which contains the server message
        printf("Server : %s", ref);
        shutdown(client_socket,SD_BOTH);
        reza(9);
    }
    if(x == 12)
    {
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        char chm = "channel members ";
        strcat(chm, token);
        char finalchm [strlen(chm)];
        strcpy(finalchm, chm);
        send(client_socket, finalchm, sizeof(finalchm), 0);
        memset(chm, 0, sizeof(chm));

        // Read the message from server and copy it to buffer
        shutdown(client_socket,SD_SEND);
        recv(client_socket, chm, sizeof(chm), 0);
	
        cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        cJSON mems = cJSON_GetObjectItem(response, "content");
	if (!strcmp(cJSON_type, "Error"))
		printf("Error");


	for (int i = 0; i < cJSON_GetArraySize(mems); i++)
		printf("%s\n", cJSON_GetArrayItem(mems);

	reza(9);
		
	
        // Print buffer which contains the server message
        printf("Server : %s", chm);
        shutdown(client_socket,SD_BOTH);
        reza(9);
    }
    if(x == 13)
    {
        int client_socket, server_socket;
        struct sockaddr_in servaddr, cli;

        // Create and verify socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            printf("Socket creation failed...\n");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");

        // Assign IP and port
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // Connect the client socket to server socket
        if (connect(client_socket, (SA*)&servaddr, sizeof(servaddr)) != 0)
        {
            printf("Connection to the server failed...\n");
            exit(0);
        }
        else
            printf("Successfully connected to the server..\n");
        char le = "leave ";
        strcat(le, token);
        char finalle [strlen(le)];
        strcpy(finalle, le);
        send(client_socket, finalle, sizeof(finalle), 0);
        memset(le, 0, sizeof(le));

        // Read the message from server and copy it to buffer
        shutdown(client_socket,SD_SEND);
        recv(client_socket, le, sizeof(le), 0);

        // Print buffer which contains the server message
        printf("Server : %s", le);
        shutdown(client_socket,SD_BOTH);
        reza(5);
    }
}
int main()
{
    reza(1);
}
