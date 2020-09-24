// Universidade de Brasília
// Author: Yan Victor
// Resume: This server represents any LAN service (UDP)

#include "server.h"
#include "dnsPackage.h"

_Bool ifIsDnsResponse(char * msg) {
	struct DNS_H * dns = (struct DNS_H *) msg;
	return dns->qr == _RESPONSE;
}

int main()
{
	int sck = socket(AF_INET, SOCK_DGRAM, 0);
	char buffer[_LEN];

	printf("================ SERVER - UDP =================\n\n");
	if (sck == -1)
	{
		printf("A problem occurred while creating socket\n");
		exit(1);
	} else {
		printf("UDP socket created successfully!\n");
	}
	
	// Creating server
	server.sin_family = AF_INET; 
	server.sin_port = htons(_PORT); 
	memset(server.sin_zero, 0x0, 8);

	// Trying to open port
	if (bind(sck, (struct sockaddr *) &server, sizeof(server)) == -1) {	
		printf("A problem ocurred while opening port %d!\n", _PORT);
		exit(1);
	} else {
		printf("The port %d was opened successfully!\n", _PORT);
	}

	int ipAddrSz = sizeof(struct sockaddr_in); 

	_running = true;
	while (_running) { 
		memset(buffer, 0x0, _LEN);
		printf("**************************\nWaiting for new requests...\n");

		int bufferSize;
		if((bufferSize = recvfrom(sck, buffer, _LEN, 0, (struct sockaddr*)&client, &ipAddrSz)) > 0) {
			printf("\n=> New request: %s\n\n", buffer);
		
			if (!ifIsDnsResponse(buffer)) {
				char response[_LEN];
				strcpy(response, "Thanks for request!");

				if(sendto(sck, response, strlen(response), 0, (struct sockaddr*)&client, ipAddrSz)) {
					printf("=> Sending message: %s\n\n", response);
				} else {
					printf("Failed to send message!\n");
				}
			} else {
				printf("The package is a DNS response!\n\n");
			}
		}
	}

	close(sck);

	printf("\n\nEnding server...\n");
	return 0;
}
