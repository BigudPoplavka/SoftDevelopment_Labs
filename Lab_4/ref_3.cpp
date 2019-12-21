//REFACTORING PART 3
//ПОДЪЕМ И СПУСК МЕТОДА И ПОЛЯ
#include <stdio.h>
#include <iostream>

/*ПОДЪЕМ МЕТОДА / ПОЛЯ - одинаковый или схожий в работе метод / поле в классах 
наследниках можно поднять в родительский класс*/
class  A
{
public:
	 A() {}
	~ A() {}
};

class B: public A
{
public:
	int counter_;

	B() {}
	~B() {}

	void Count(int k) { k++; }
}

class C: public A
{
public:
	int counter_;

	C() {}
	~C() {}

	void Count(int k) { k++; } //поднять метод
}

//ПОСЛЕ ПОДНЯТИЯ
class  A
{
public:
	int counter_;

	 A() {}
	~ A() {}

	void Count(int k) { k++; }		//наследники будут иметь метод Count и поле counter
};

class B: public A
{
public:
	B() { Count(counter_); }
	~B() {}
}


/*-------------------------------------------------------------------*/
/*СПУСК МЕТОДА / ПОЛЯ- спустить метод / ПОЛЕ в класс наследник, 
если он используется чаще в наследнике, чем в родителе*/
class  A
{
public:
	 A() {}
	~ A() {}

	void Func() {}
};

class B: public A
{
public:
	bool condition;

	B() { Func(); }
	~B() {}

	void Foo()
	{
		if(condition)	
			Func();
	}
}

//ПОСЛЕ СПУСКА
class  A
{
public:
	 A() {}
	~ A() {}
};


class B: public A
{
public:
	bool condition;

	void Func();
	
	B() { Func(); }
	~B() {}

	void Foo()
	{
		if(condition)	
			Func();
	}
}