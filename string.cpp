#include <stdio.h>
#include <string>
int main(){
	const char *s = "Hello, World!";
	std::string str(s);
	char* foo = new char[14]();
	for(int i=0; i<5; i++){
		*(foo+i)="ACGTN0"[i];
	}
	std::string mst(foo);
	printf("%s %s\n",str.c_str(), mst.c_str());
}
