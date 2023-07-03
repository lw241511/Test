// #include<iostream>
// using namespace std;
// class Base1
// {
// public:
//     int base1_1;
//     int base1_2;

//     virtual void base1_fun1() {}
//     virtual void base1_fun2() {}
// };

// class Base2 : public Base1
// {
// public:
//     virtual void base1_func()
//     {
//         cout << "Base2中base1_func()调用" << endl;
//     }
//     int base2_1;
// };
// int main()
// {
//     Base2 b;
//     void (*xp)() = (void(*)()) * (int*)(*((int*)&b) + 8);
//     xp();

//     cout << "aaa";
//     return 0;
// }
// #include <iostream>
 
// using namespace std;
 
// class Base {
// public:
//     int a;
//     virtual void fun1() {cout<<"Base::fun1"<<endl;}
//     virtual void fun2() {cout<<"Base::fun2"<<endl;}
//     virtual void fun3() {cout<<"Base::fun3"<<endl;}
// };
 
// class Derive : public Base{
// public:
//     virtual void fun2() {cout<<"Derive::fun2"<<endl;}
// };
 

// int main () {
//     cout<<"size of Base: "<<sizeof(Base)<<endl;
 
//     typedef void(*Func)(void);
//     Base *b = new Base();
//     b->a = 6;
//     Base *d = new Derive();
//     d->a = 5;
//     cout<<"d->a="<<d->a<<endl<<endl;
//     int m = 6;
//     int* p ;
//     p = &m;
//     //cout<<p<<&(*p)<<endl;

 
//     long* pvptr = (long*)d;
//     long* vptr = (long*)*pvptr;
//     long* ptr = (long*)b;
//     long* tr = (long*)*ptr;
//     Func f1 = (Func)vptr[0];
//     Func f2 = (Func)vptr[1];
//     Func f3 = (Func)vptr[2];
//     Func f7 = (Func)vptr[3];
//     Func f4 = (Func)tr[0];
//     Func f5 = (Func)tr[1];
//     Func f6 = (Func)tr[2];
//     //cout<<&(*d)<<"a"<<&(*b)<<endl;
//     //cout<<pvptr<<"a"<<ptr<<endl;
//     cout<<&vptr[0]<<"a"<<&tr[0]<<endl;//虚函数表地址
//     cout<<&vptr[1]<<"a"<<&tr[1]<<endl;
//     cout<<&vptr[2]<<"a"<<&tr[2]<<endl;
//     cout<<&vptr[3]<<"a"<<endl;
//     cout<<"--------";
//     cout<<vptr[0]<<"a"<<tr[0]<<endl;//虚函数地址
    
//     cout<<vptr[1]<<"a"<<tr[1]<<endl;
    
//     cout<<vptr[2]<<"a"<<tr[2]<<endl;
    
//     //ptr[0]();
//     f7();
//     f2();
//     f3();
//     f4();
//     f5();
//     f6();
    
 
//     return 0;

// }
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef void(*ptr)(void);

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Derive::Func2()" << endl;
	}
private:
	int _d = 2;
};
void PrinVFTable(long* m)
{

	for (size_t i = 0; m[i] != nullptr; ++i)
	{
		printf("vft[%d]:%d", i, &m[i]);//打印地址和函数名
        //cout<<"mmm"<<endl;
        ptr x = (ptr)m[i];
		x();//调用函数，由于是无返回值，无参数，table[i]就是虚表里对应的函数
	}
}
int main()
{
	Derive s1;
    long* vptr = (long*)&s1;
    long* xx = (long*)*vptr;
    Base b;
    long* tr = (long*)&b;
    long* x = (long*)*tr;
    PrinVFTable(x);
    
	PrinVFTable(xx);//虚表的地址在对象的前四个或前八个字节
	return 0;
}