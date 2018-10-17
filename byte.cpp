#include <stdio.h>
int main(){
	// unsigned int foo = 0x8FFFFFFFU; // max value
	unsigned int foo = 0x81000000U; // first bit
	if( foo & 0x0F000000U){
		printf(" obtained %u\n",foo);
	}
	return 0;
}
