#include "../essential.h"

//===== PACKAGES
#define _REQUEST 1
#define _RESPONSE -1
#define _UNKNOWN_QUERY_TYPE 0

//===== LIST OF QUERY TYPES BY PROTOCOLS
#define _DNS_REQUEST 0
#define _DNS_RESPONSE 1
#define _NTP_CLIENT 3
#define _NTP_SERVER 4

#define _1BIT 1
#define _2BITS 2
#define _3BITS 3
#define _4BITS 4
#define _8BITS 8

//===== MODULE
#define _MODULE_DECODER "DECODER"


typedef uint16_t byte_2;
typedef uint32_t byte_4;
typedef uint64_t byte_8;
typedef unsigned __int128 byte_16;
struct DNS_HEADER
{
    byte_2 id;
    unsigned char rd:	_1BIT; 
    unsigned char opcode:	_4BITS; 
    unsigned char aa:	_1BIT; 
    unsigned char tc:	_1BIT;
    unsigned char qr:	_1BIT; 
    unsigned char ra:	_1BIT; 
    unsigned char z:	_1BIT; 
    unsigned char rcode:	_4BITS;
    unsigned char cd:	_1BIT; 
    unsigned char ad:	_1BIT; 
    byte_2 qd_count; 
    byte_2 an_count; 
    byte_2 ns_count; 
    byte_2 ar_count; 
};

struct NTP_HEADER
{
    unsigned char li: _2BITS;
    unsigned char vn: _3BITS;
    unsigned char mode: _3BITS;
    unsigned char stratum: _8BITS;
    unsigned char poll: _8BITS;
    unsigned char precision: _8BITS;
    byte_4 root_delay;
    byte_4 root_dispersion;
    byte_4 reference_id;
    byte_8 reference_timestamp;
    byte_8 origin_timestamp;
    byte_8 receive_timestamp;
    byte_8 transmit_timestamp;
    byte_4 extension_field;
    byte_8 key_identifier;
    byte_16 dgst;


};

long long decoder (int protocol,  char * buffer);
int getDnsQueryType(char * buffer);
int getNtpQueryType (char * buffer);
int getSnmpQueryType (char * buffer);
int getSsdpQueryType (char * buffer);
