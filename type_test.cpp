#include<iostream>
#include"type.h"

using namespace std;


class MyClass{
};

void myfunc(){
}

enum E { e1 };


//实例测试
int main(void)
{

	cout<<"int :";
	__check_type<int>();

	cout<<"int& :";
	__check_type<int&>();

	cout<<"char[42] :";
	__check_type<char[42]>();

	cout<<"MyClass :";
	__check_type<MyClass>();

	cout<<"ptr to enum :";
	E* ptr = 0;
	check_type(ptr);

	cout<<"42.0 :";
	check_type(42.0);

	cout<<"myfunc() :";
	check_type(myfunc);

	cout<<"memptr to array :";
	char (MyClass::* memptr)[] = 0;
	check_type(memptr);

	return 0;
}
