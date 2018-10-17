#include <stdio.h>
int main(){
	int i = 0;
	i += 1 << 2;
	i += 1 << 3;
	int j = 0;
	j = j | 1 << 2;
	j = j | 1 << 3;
	printf(" Obtained %i %i\n", i, j);
	return 0;
}
