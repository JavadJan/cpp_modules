#include "./include/SimpleSocket.hpp"

SimpleScoket::SimpleScoket(int domain, int service, int protocol, int port, u_long interface)
{
	//int domain;  ivp6, ipv4(AF_INET: IPv4)
	//int service;	 TCP(SOCK_STREAM), UDP(SOCK_DGRAM)
	//int protocol;	 HTTP
	//address is similar to string connection in ASP.net and node.js ip/port
	// host to network short == 0 - 2 ^ 16 == 0 - 65536
	address.sin_family = domain;
	address.sin_port = htons(port /* == is int, need to network standard */); //pc host byte order to the standard network byte order.
	address.sin_addr.s_addr = htonl(interface);

	sock_fd = socket(domain, service, protocol);
	connection = connect_to_network(sock_fd, address);
}

SimpleScoket::~SimpleScoket()
{
	
}

/* 
Your Code: address struct
   ↓
sockaddr_in (IP:Port) → OS Socket API (syscall)
   ↓
Kernel TCP/IP Stack
   ↓
Network Interface sends/receives based on this info


when you run socket(domain, service, protocol) you tell the OS:
returns a file descriptor (a number), which you can use to send/receive data through this socket — just like reading/writing a file.

*/