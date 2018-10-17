#include <iostream>
#include <map>

int main ()
{
	std::map<int,int>* mymap = new std::map<int,int>();
	for (int i=1; i<=5; i++) mymap->emplace(i,1);
	std::map<int,int>::iterator it = mymap->begin();
	int u = 3;
	while(it!=mymap->end()){
		printf("have %i %i\n",it->first,it->second);
		u += it++->second;
	}
	std::cout<<" "<< u << "\n";
	return 0;
}
