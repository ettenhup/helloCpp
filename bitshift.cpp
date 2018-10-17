#include <stdio.h>
int main(){
	int foo = 0;
	int myFoo[] = {2,3,3,0};
	for(int i=0; i<4; i++){
		foo += myFoo[i] << 2*(4-1-i);
	}
	printf(" Obtained %i\n",foo);
	for(int i=0; i<4; i++){
		printf(" from %u\n", foo >> 2*(4-1-i));
	}
	return 0;
}
