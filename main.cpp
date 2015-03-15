#include  <stdio.h>
#include <string.h>
#include <signal.h>
#include "httpConfig.h"
#include "httpd.h"

//using namespace std;

int main(int argc, char* argv[]) {
	puts("Hellow World!");

	HttpConfig * config = new HttpConfig(argc, argv);
	Httpd * httpd = new Httpd(config);
	httpd->start();

	return 0;
}
