#include <iostream>
#include <vector>

int main ()
{
	std::vector<int> myvector;
	std::vector<int*> myvectorref;
	for (int i=1; i<=5; i++) myvector.push_back(i);
	std::vector<int>::iterator it = myvector.begin()+2;
	while(it < myvector.begin()+4){
		myvectorref.push_back(&(*it++));
	}
	std::cout << "myvector contains:";
	std::vector<int*>::iterator itref = myvectorref.begin();
	while(itref < myvectorref.end()){
	 	std::cout<<" "<<*(*itref++);
	}
	std::cout << "\n";

	myvector[3] = 123;
	std::cout << "myvector contains:";
	itref = myvectorref.begin();
	while(itref < myvectorref.end()){
	 	std::cout<<" "<<*(*itref++);
	}
	std::cout << "\n";


	return 0;
}
