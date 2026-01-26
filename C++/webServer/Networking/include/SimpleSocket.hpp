#ifndef SIMPLESOCKET_HPP
#define SIMPLESOCKET_HPP
#include <sys/socket.h>   // For socket(), bind(), sockaddr, etc.
#include <netinet/in.h>   // For sockaddr_in, htons(), htonl(), IPPROTO_TCP
#include <arpa/inet.h>    // For inet_pton(), inet_ntop()
#include <unistd.h>       // For close()

class SimpleScoket
{
	private:
		struct sockaddr_in address;
		int sock_fd;
		int connection;
	public:
		SimpleScoket(int domain, int serivce, int protocol, int port, u_long interface);
		~SimpleScoket();
		int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
		virtual int connect_to_network(int sock_fd, struct sockaddr_in address) = 0; // we enforce the derived class to implemen this function
};

#endif
/*
	Application Layer for hadle HTTP request: get and post method 
	use socket(), bind(), listen(), accept() (C/C++) to open TCP ports. 

	when browser connect to the webserver:
	1. boreser: send data ----> over TCP to port 8080
	2. OS accest via TCP
	3. progrem reads req via socket
	4. parse HTTP, generate responce and write back
*/

/* 
	socket is running in the transport layer!
	if (socket(int domain, int type, int protocol) == filedescriptor)
		succeessed
	else
		faild
	domain: ipv4, ipv6
	type: TCP, UDP
	protcol 


	
*/


/*  ----- socket: 
	a network socket lets your program plug into the network to exchange data.
*/