#include <stdio.h>
#include <cmath>

int isqrt (unsigned x) {
	unsigned m,y,b;
	m = 0x40000000;
	y = 0;
	while (m!=0) {
		b = y | m;
		y = y >> 1;
		if (x >= b){
			x = x - b;
			y = y | m;
		}
		m = m >> 2;
	}
	return y;
}

unsigned long solve(unsigned long c){
	return (unsigned long) std::floor(2*sqrt(0.0625 + 0.5 * c)) ;
}
unsigned long solve3(unsigned long c){
	return (unsigned long) std::floor(0.5+2*sqrt(0.0625+0.5*c)) - 1;;
}

int main(){
	//unsigned foo = 139637115;
	unsigned foo = 139687251;
	printf(" Obtained %u %u\n",solve(foo),solve3(foo));
	return 0;
}
