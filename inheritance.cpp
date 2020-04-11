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

void test(A* a){
	printf(" a \n");
}
void test(B* a){
	printf(" b \n");
}

void test_test(A* a){
	test(a);
}

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
	test(&a1);
	test(&a2);
	test(&b1);
	test(&b2);
	A* p = &b1;
	test(p);
	test_test(&b1);
	if(typeid(*p) == typeid(A)){
		printf(" p is A\n");
	}
	if(typeid(*p) == typeid(B)){
		printf(" p is B\n");
	}
	return 0;
}

