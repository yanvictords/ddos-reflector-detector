#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define _PORT 7000
#define _LEN 65536
#define _BLACKLIST_FILE "../blacklist.txt"

struct sockaddr_in proxyServer, server;
_Bool _running;

