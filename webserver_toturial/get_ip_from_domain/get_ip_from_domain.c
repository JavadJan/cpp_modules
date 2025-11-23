#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>      // <-- Required for struct addrinfo
#include <unistd.h>     // for close()

//struct addrinfo {
//    int              ai_flags;
//    int              ai_family;
//    int              ai_socktype;
//    int              ai_protocol;
//    size_t           ai_addrlen;
//    struct sockaddr *ai_addr; // will fill out with getaddrinfo()
//    char            *ai_canonname;
//    struct addrinfo *ai_next;
//};

//Structures for the Connection IP Address and Port
//struct sockaddr_in {
//    sa_family_t    sin_family;
//    in_port_t      sin_port;
//    struct in_addr sin_addr;
//};
//struct in_addr {
//    uint32_t       s_addr; 192.168.1.1
//};


int main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf(stderr, "usage a.out <google.com>");
		return 1;
	}
	struct addrinfo hints;
	struct addrinfo *res;
	struct addrinfo *r;
	int status;
	char buffer[INET6_ADDRSTRLEN];
	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP

	status = getaddrinfo(av[1], "http", &hints, &res);
    if (status != 0) { // error !
        printf("getaddrinfo: %s\n", gai_strerror(status));
        return (2);
    }
	printf("IP adresses for %s:\n", av[1]);

    r = res;
    while (r != NULL) {
        //void *addr; // Pointer to IP address
        if (r->ai_family == AF_INET) { // IPv4
            // we need to cast the address as a sockaddr_in structure to
            // get the IP address, since ai_addr might be either
            // sockaddr_in (IPv4) or sockaddr_in6 (IPv6)
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)r->ai_addr; // uint32_t, it's int
            // Convert the integer into a legible IP address string
            inet_ntop(r->ai_family, &(ipv4->sin_addr), buffer, sizeof buffer);
            printf("IPv4: %s\n", buffer);
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)r->ai_addr;
            inet_ntop(r->ai_family, &(ipv6->sin6_addr), buffer, sizeof buffer);
            printf("IPv6: %s\n", buffer);
        }
        r = r->ai_next; // Next address in getaddrinfo()'s results
    }
    freeaddrinfo(res); // Free memory
    return (0);
}