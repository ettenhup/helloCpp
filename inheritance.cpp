// erasing from map
#include <iostream>

class A {
	int x;
public:
	A(int x): x(x){};;
	virtual int get_x(){ return x; };
	void test(A& b){
		std::cout << "have " << get_x() << " " << b.get_x() << std::endl;
	}

};

class B : public A {
public:
	B(int x) : A(x){};

	int get_x(){
		return 5;
	}
};

int main ()
{
	A a1(3);
	A a2(4);
	B b1(7);
	B b2(8);
	a1.test(a2);
	a2.test(a1);
	b1.test(a1);
	a1.test(b1);
	b1.test(b2);
	b2.test(b1);
	return 0;
}

