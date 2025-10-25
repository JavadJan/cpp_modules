#include "../include/server.h"

int	main(void)
{
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_len = sizeof(client_addr);
	char buffer[1024];
	int soc_ser_fd;
	int client_fd;

	//--------------------------#
	//   		create socket   #
	//--------------------------#
	soc_ser_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (!soc_ser_fd)
		printf("failed to creation socket\n");

	//--------------------------#
	//   		fill IP info    #
	//--------------------------#
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080); // port to binary,
										// in network use as binary format
	server_addr.sin_addr.s_addr = INADDR_ANY;
	memset(server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

	//--------------------------#
	//   	make connection     #
	//--------------------------#
	// connect(soc_ser_fd,(struct sockaddr_in *)(&server_addr),sizeof(server_addr)); for cleint
	bind(soc_ser_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	// 3. Listen
	listen(soc_ser_fd, 5);

	// 4. Accept
	client_fd = accept(soc_ser_fd, (struct sockaddr *)&client_addr,
			&client_len);

	// 5. Communicate
	recv(client_fd, buffer, sizeof(buffer), 0);
	printf("[SERVER] Received: %s\n", buffer);

	send(client_fd, "Hello from server!", 18, 0);
	const char *response = "Hello from server!";
	printf("[SERVER] Sent: %s\n", response);

	// 6. Close
	close(client_fd);
	close(soc_ser_fd);
}