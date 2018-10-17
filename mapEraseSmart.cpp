// erasing from map
#include <iostream>
#include <map>
#include <memory>

class foo {
	int x;
	int* p;
public:
	foo(int x):x(x){ p = new int[x]; for(int i=0;i<x;i++) p[i] = i;};
	~foo(){delete [] p;};
	int get_x(){return x;};
	int get_p(int i){return p[i];};
};

struct Cmp {
    bool operator()(const std::unique_ptr<foo>& lhs, const std::unique_ptr<foo>& rhs) const {
        return lhs.get()->get_x() < rhs.get()->get_x(); 
    }
};

int main ()
{
  std::map<std::unique_ptr<foo>, char, Cmp> mymap;
  std::map<std::unique_ptr<foo>, char, Cmp>::iterator it;

  // insert some values:
  foo* f = new foo(10);
  mymap[std::unique_ptr<foo>(f)] = 'a';
  mymap.emplace(std::unique_ptr<foo>(new foo(20)),'b');

  printf(" Finds %u\n",mymap.find(std::unique_ptr<foo>(new foo(20))) != mymap.end());

  

  // mymap.erase ( --mymap.end() );

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->second << " => " << it->first.get()->get_x() << '\n';

  return 0;
}

