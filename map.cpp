#include <stdio.h>
#include <map>
class Point
{
   private:
      int x, y;
   public:
      Point(int x, int y): x(x), y(y){};

      bool operator<( const Point& other) const
      {
          if ( x == other.x )
          {
              return y < other.y;
          }

          return x < other.x;
      }
};
int main(){
	std::map<std::unique_ptr<Point>, int> m;
	Point p1(1,2);
	Point p2(2,2);
	Point p3(1,2);

	m.emplace(new std::unique_ptr<Point>(p1),1);
	m.emplace(new std::unique_ptr<Point>(p2),2);
	m.emplace(new std::unique_ptr<Point>(p3),3);

	printf("foo\n");
	// std::cout << "Have " << m[p1] << " " << m[p2] << " " << m[p3] << std::endl;
	// std::cout << "Have " << m[p1] << " " << m[p2] << " " << m[p3] << std::endl;

}
