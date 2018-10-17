// erasing from map
#include <iostream>
#include <map>
#include <memory>

class fooInterface {
public:
	virtual int get_x() const;
	virtual int get_p(int i);
};

class foo : public virtual fooInterface {
	int x;
	int* p;
public:
	foo(int x):x(x){ p = new int[x]; for(int i=0;i<x;i++) p[i] = i;};
	virtual ~foo(){printf("deleting %u\n",x);delete [] p;};
	virtual int get_x() const {return x;};
	virtual int get_p(int i){return p[i];};
};

struct Cmp {
    bool operator()(const foo& lhs, const foo& rhs) const {
        return lhs.get_x() < rhs.get_x(); 
    }
};

int main ()
{
  std::map<foo, char, Cmp> mymap;
  std::map<foo, char, Cmp>::iterator it;

  // insert some values:
  foo* f = new foo(10);
  mymap[std::move(*f)] = 'a';
  mymap.emplace(std::move(*(new foo(20))),'b');

  foo* t = new foo(20);
  printf(" Finds %u\n",mymap.find(*t) != mymap.end());
  delete t;

  

  // mymap.erase ( --mymap.end() );

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->second << " => " << it->first.get_x() << '\n';

  return 0;
}

