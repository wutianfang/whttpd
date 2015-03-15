#ifndef _HTTP_CONFIG_H_
#define _HTTP_CONFIG_H_

#include  <stdio.h>

class HttpConfig {
public:
	HttpConfig(int argc, char* argv[]) {
		puts("HttpConfig construct!");
	};

	int getPort(void);
	int getBacklog(void);
	char * getRoot(void);
	
};


#endif // _HTTP_CONFIG_H_
