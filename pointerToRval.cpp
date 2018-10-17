// erasing from map
#include <iostream>
#include <map>

class Point {
public:
	int x,y;
	Point(int x, int y): x(x), y(y) {};
	Point(Point&& p) : x(p.x), y(p.y){};
};

int main ()
{
  std::map<char,Point> mymap;
  std::map<char,Point>::iterator it;

  // insert some values:
  mymap.emplace('a',std::move(Point(1,1)));
  mymap.emplace('b',std::move(Point(20,40)));
  Point* foo = new Point(100,200);
  mymap.emplace('c',std::move(*foo));

  it=mymap.find('b');
  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second.x << " " << it->second.y << '\n';

  return 0;
}

