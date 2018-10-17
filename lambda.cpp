#include <stdio.h>
int main(){
	int foo = 3;

	// capture foo from the surrounding
	auto horst1 = [&foo](int i){ foo++; return foo<i;};
	auto horst2 = [foo](int i)->bool{/*foo++; does not work*/ return foo<i;};
	// 
	// analogous we can specify
	auto horst3 = [&](int i){ foo++; return foo<i;};
	auto horst4 = [=](int i)->bool{/*foo++; does not work*/ return foo<i;};

	printf("%d, %i\n",horst2(3),foo);
	printf("%d, %i\n",horst1(5),foo);
	printf("%d, %i\n",horst4(3),foo); 
	printf("%d, %i\n",horst3(5),foo);

	
	for(int i=0; i<10; i++){
		foo = 9;
		printf("test = %i with foo %i is %d\n",i,foo,horst4(i)); // note that the value of foo is used at the point where the function is declared
	}
	foo = 9;
	for(int i=0; i<10; i++){
		foo = 9;
		printf("test & %i with foo %i is %d\n",i,foo,horst3(i)); // here foo is captured by ref
	}
	

	return 0;
}
