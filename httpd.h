#ifndef _HTTPD_H_
#define _HTTPD_H_

#include <stdio.h>
#include <string.h>
//#include <signal.h>
#include "httpConfig.h"


class Httpd {

public:
	Httpd() {}
	Httpd(HttpConfig * httpConfig);

	int start();
	int stop();
	int initServiceSock(void);

protected:
	HttpConfig * config;
};


#endif // _HTTPD_H_
