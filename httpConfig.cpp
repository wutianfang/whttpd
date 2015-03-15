#include "httpConfig.h"
#include <stdio.h>

int HttpConfig::getPort(void) {
	return 8889;
}
int HttpConfig::getBacklog(void) {
	return 50;
}

char * HttpConfig::getRoot(void) {
	return "/home/work/levelup/whttpd/root/";
}
