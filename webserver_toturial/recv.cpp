// Example 1: Blocking recv()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
void one(int client)
{
	char buffer[1024];
    int n = recv(client, buffer, sizeof(buffer), 0);
    printf("recv() returned %d bytes: %.*s\n", n, n, buffer);

    close(client);
}

void two(int client)
{
	// Example 3: recv() may return partial data
	char buffer[1024];
	int n = recv(client, buffer, 1024, 0);
	printf("Got %d bytes\n", n);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4242);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    listen(sockfd, 5);

    int client = accept(sockfd, NULL, NULL);
    
	one(client);
	//two(client);
    close(sockfd);
}
