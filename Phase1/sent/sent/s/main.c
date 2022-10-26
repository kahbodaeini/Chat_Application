#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.c"
#include <arpa/inet.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 12345
#define SA struct sockaddr
char bufferemon[1000], cJSON_content[1000], cJSON_type[1000], messages[100000] , token[];
void reg(void);
void lin(void);
void menu2(void);
void createch(void);
void joinch(void);
void lout(void);
void menu3(void);
void sending(void);
void refr(void);
void mem(void);
void leavech(void);

void reza(int x)
{

    if(x == 1)//main menu
    {
        int a;
        printf("1 : Register\n2 : Login\n3 : Exit\n");
        scanf("%d", &a);
        if(a == 1)
            reg();
        if(a == 2)
            lin();
        if(a == 3)
            exit(0);
    }
    }
    reg()//register
    {
        char username[100];
        char password[100];
        char space[3] = ", ";
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
        char gfotoohi[strlen(reg)];
        memset(bufferemon , 0 , sizeof(bufferemon));
        strcpy(gfotoohi, reg);
        //printf("%s",gfotoohi);



        send(client_socket, gfotoohi, sizeof(gfotoohi), 0);
        shutdown(client_socket,SHUT_WR);
        memset(bufferemon , 0 , sizeof(bufferemon));
        recv(client_socket, bufferemon, sizeof(bufferemon), 0);

        cJSON *response = cJSON_Parse(bufferemon);
        cJSON *resp = cJSON_Parse(bufferemon);
            cJSON *type = cJSON_GetObjectItemCaseSensitive(resp, "type");
            cJSON *cont = cJSON_GetObjectItemCaseSensitive(resp, "content");
            char x[100] , y[100];
            strcpy(x , type->valuestring);
            strcpy(y , cont->valuestring);

        if (strcmp("Error", x) == 0)
        {
            printf("%s\n", y);
            reza(1);
        }
        if (strcmp("Successful", type->valuestring) == 0)
        {
            strncpy(token,cont->valuestring,32);
            reza(1);
        }

        shutdown(client_socket,SHUT_RDWR);

    }
    lin()
    {
        char username[100];
        char password[100];
        char space[] = ", ";
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
        char sina[strlen(login)];
        memset(bufferemon , 0 , sizeof(bufferemon));
        strcpy(sina, login);
        send(client_socket, sina, sizeof(sina), 0);
        shutdown(client_socket,SHUT_WR);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, bufferemon, sizeof(bufferemon), 0);
                cJSON *response = cJSON_Parse(bufferemon);
        cJSON *resp = cJSON_Parse(bufferemon);
            cJSON *type = cJSON_GetObjectItemCaseSensitive(resp, "type");
            cJSON *cont = cJSON_GetObjectItemCaseSensitive(resp, "content");
        if((strcmp("Error", type->valuestring) == 0) && (strncmp(cont->valuestring , "The" , 3) == 0) ){
        menu2();
        }
        if (strcmp("Error", type->valuestring) == 0)
        {
            printf("%s\n", cont->valuestring);
            reza(1);
        }
        if (strcmp("AuthToken", type->valuestring) == 0)
        {
                strncpy(token,cont->valuestring,32);
            menu2();
        }

        // Print buffer which contains the server message
        //printf("Server : %s", bufferemon);
        shutdown(client_socket,SHUT_RDWR);

    }
    menu2()
    {
        int b;
        printf("1 : Create Channel\n2 : Join Channel\n3 : Logout\n");
        scanf("%d", &b);
        if(b == 1)
            createch();
        if(b == 2)
            joinch();
        if(b == 3)
            lout();
    }
    createch()
    {
        char channelname[100];
        char space[3] = ", ";
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
        strcat(cch, channelname);
        strcat(cch, space);
        strncat(cch, token,32);
        strcpy(bufferemon, cch);
        send(client_socket, bufferemon, sizeof(bufferemon) - 12, 0);
        shutdown(client_socket,SHUT_WR);
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
            menu2();
        }
        if (strcmp("Successful", cJSON_type) == 0)
        {
            menu3();
        }

        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SHUT_RDWR);
        reza(9);
    }
    joinch()
    {
        char channelname[100];
        char space[3] = ", ";
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
        strncat(jch, token,32);
        strcpy(bufferemon, jch);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        shutdown(client_socket,SHUT_WR);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer

        char w[100] , i[100];
        strcpy(w , type->valuestring);
        strcpy(i , cont->valuestring)
        recv(client_socket, jch, sizeof(jch), 0);
                if (strcmp("Error", w) == 0)
        {
            printf("%s\n", i);
            menu2();
        }
        if (strcmp("Successful", type->valuestring) == 0)
        {
            strncpy(token,cont->valuestring,32);
            menu3();
        }

        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SHUT_RDWR);
        menu3();
    }
    lout()
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
        char lo[39] = "logout ";
        strncat(lo, token,32);
        strcpy(bufferemon, lo);
        send(client_socket, lo, sizeof(lo), 0);
        shutdown(client_socket,SHUT_WR);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, lo, sizeof(lo), 0);
                if (strcmp("Error", type->valuestring) == 0)
        {
            printf("%s\n", cont->valuestring);
            menu2();
        }
        if (strcmp("Successful", type->valuestring) == 0)
        {
            strncpy(token,cont->valuestring,32);
            reza(1);
        }

        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SHUT_RDWR);
        reza(1);
    }
    menu3()
    {
        int c;
        printf("1 : Send Message\n2 : Refresh\n3 : Channel Members\n4 : Leave Channel\n");
        scanf("%d", &c);
        if(c == 1)
            sending();
        if(c == 2)
            refr();
        if(c == 3)
            mem();
        if(c == 4)
            leavech();
    }
    sending()
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
        char space[3] = ", ";
        printf("Enter Your Message\n");
        scanf("%s", msg);
        strcat(snd, msg);
        strcat(snd, space);
        strncat(snd, token,32);
        strcpy(bufferemon, snd);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        shutdown(client_socket,SHUT_WR);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, bufferemon, sizeof(bufferemon), 0);
if (strcmp("Error", type->valuestring) == 0)
        {
            printf("%s\n", cont->valuestring);
            menu3();
        }
        if (strcmp("Successful", type->valuestring) == 0)
        {
            strncpy(token,cont->valuestring,32);
            menu3();
        }
        // Print buffer which contains the server message
        printf("Server : %s", bufferemon);
        shutdown(client_socket,SHUT_RDWR);
        menu3();
    }
    refr()//refresh
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
        strncat(ref, token,32);
        strcpy(bufferemon, ref);
        send(client_socket, bufferemon, sizeof(bufferemon), 0);
        shutdown(client_socket,SHUT_WR);
        memset(bufferemon, 0, sizeof(bufferemon));

        // Read the message from server and copy it to buffer
        recv(client_socket, bufferemon, sizeof(bufferemon), 0);


        cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        cJSON *messages = cJSON_GetObjectItem(response, "content");

    if (!strcmp(cJSON_type, "Error"))
    {
        printf("Refresh failed\n");
    menu3();
    }

        for(int i = 0; i < cJSON_GetArraySize(messages); i++)
        {
            printf("%s : %s \n", cJSON_GetArrayItem(messages, "sender")->valuestring, cJSON_GetArrayItem(messages, "content")->valuestring);
        }
        cJSON_Delete(response);






        // Print buffer which contains the server message
        printf("Server : %s", ref);
        shutdown(client_socket,SHUT_RDWR);
        menu3();
    }
    mem()
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
        strncat(chm, token,32);
        char finalchm [strlen(chm)];
        strcpy(finalchm, chm);
        send(client_socket, finalchm, sizeof(finalchm), 0);
        shutdown(client_socket,SHUT_WR);
        memset(chm, 0, sizeof(chm));

        // Read the message from server and copy it to buffer
        shutdown(client_socket,SHUT_WR);
        recv(client_socket, chm, sizeof(chm), 0);

        cJSON *response = cJSON_Parse(bufferemon);
        memset(cJSON_content, 0, sizeof(cJSON_content));
        memset(cJSON_type, 0, sizeof(cJSON_type));
        strcat(cJSON_type, cJSON_GetObjectItem(response, "type") -> valuestring);
        cJSON* mems = cJSON_GetObjectItem(response, "content");
    if (!strcmp(cJSON_type, "Error"))
        printf("Error");


    for (int i = 0; i < cJSON_GetArraySize(mems); i++)
        printf("%s\n", cJSON_GetArrayItem(mems,i));

    menu3();


        // Print buffer which contains the server message
        printf("Server : %s", chm);
        shutdown(client_socket,SHUT_RDWR);
        menu3();
    }
    leavech()
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
        strncat(le, token,32);
        char finalle [strlen(le)];
        strcpy(finalle, le);
        send(client_socket, finalle, sizeof(finalle), 0);
        shutdown(client_socket,SHUT_WR);
        memset(le, 0, sizeof(le));

        // Read the message from server and copy it to buffer
        shutdown(client_socket,SHUT_WR);
        recv(client_socket, le, sizeof(le), 0);

        // Print buffer which contains the server message
        printf("Server : %s", le);
        shutdown(client_socket,SHUT_RDWR);
        menu2();
    }
    //return 0;

void main()
{
    reza(1);
}
