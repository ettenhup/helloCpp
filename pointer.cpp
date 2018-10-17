// compile with clang pointer.cpp -lstdc++
#include <stdio.h>
int main(){
	long foo = 3;
	long* fooP = &foo;
	printf(" foo foo %li %p\n",*fooP,fooP);
	(*fooP)++;
	printf(" foo foo %li %p\n",*fooP,fooP);

	double* t = new double [*fooP];
	double* p = &t[0];
	for(int i=0; i<*fooP; i++){
		*p= static_cast<double>(i);
		printf("myfoop: %f %f\n",t[i],*p);
		p++;
	}
	p = &t[*fooP-1] - 2; 
	printf("one and three: %f %f\n",*p,*(p+2));


	return 0;
}
