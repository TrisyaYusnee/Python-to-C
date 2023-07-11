#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_address;
    char buffer[1024];

    // Get server IP address and port number from user input
    printf("Enter server IP address: ");
    char ip_address[100];
    scanf("%s", ip_address);

    printf("Enter server port number: ");
    int port_number;
    scanf("%d", &port_number);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket.");
        exit(1);
    }

    // Set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8484);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_addres>

        perror("Error connecting to server.");
        exit(1);
    }

    // Get user input
    printf("Enter message: ");
    scanf("%s", buffer);

    // Send the message to the server
    write(sockfd, buffer, strlen(buffer));

    // Receive the reply from the server
    read(sockfd, buffer, sizeof(buffer));

    // Print the reply
    printf("Response from server: %s\n", buffer);

    close(sockfd);
    return 0;
}
