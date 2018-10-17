#include <stdio.h>
constexpr int pop(unsigned x){
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2 ) & 0x33333333);
	x = (x + (x >> 4)) & 0x0F0F0F0F;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return x & 0x0000003F;
}
constexpr int const_ceil_log2(unsigned x) {
	x = x-1;
	x = x | (x>>1);
	x = x | (x>>2);
	x = x | (x>>4);
	x = x | (x>>8);
	x = x | (x>>16);
	return pop(x);
}

int main(){
	int foo = 0;
	int myFoo[] = {0,2,4,5,8,9,10,16,255};
	for(unsigned i=0; i<9; i++){
		printf(" Have %u %i\n",myFoo[i],const_ceil_log2(myFoo[i]));
	}
	return 0;
}
