#include "std_lib_facilities.h"

class B1
{
public:
	virtual void vf() const
	{
		cout<<"B1::vf()"<<endl;
	}
	void f() const
	{
		cout<<"B1::f()"<<endl;
	}
	virtual void pvf() = 0;
};

struct D1:B1
{
	void vf()const override
	{
		cout<<"D1::vf"<<endl;
	}
	void f()const
	{
		cout<<"D1::f"<<endl;
	}
};

struct D2:D1
{
	void pvf() override
	{
		cout<<"D2::pvf"<<endl;
	}
};

struct B2
{
	virtual void pvf() = 0;
};

struct D21:B2
{
	string DM="F";
	void pvf() override
	{
		cout<<DM<<endl;
	}
};

struct D22:B2
{
	int DMint = 5;
	void pvf() override
	{
		cout<<DMint<<endl;
	}
};

void f(B2& ref2)
{
	ref2.pvf();
}


int main()
{
/*	B1 b;
	b.vf();
	b.f();
	b.pvf(); 

	D1 d;
	d.vf();
	d.f();

	B1& ref{d};
	ref.vf();
	ref.f(); */

	D2 dd;
	dd.pvf();
	dd.vf();
	dd.f();

	D21 dd1;
	f(dd1);

	D22 dd2;
	f(dd2);




	return 0;
}