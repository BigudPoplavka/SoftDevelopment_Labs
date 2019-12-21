//REFACTORING PART 1
//РАБОТА С МЕТОДАМИ
#include <stdio.h>
#include <iostream>
#include <cmath>


/*ПЕРЕМЕЩЕНИЕ МЕТОДА -> Метод используется в другом классе больше, 
чем в собственном. Переместим метод в другой класс*/
class  A
{
public:
	int objects = 0;

	 A() { Count(objects); }
	~ A() {}

	void Count(int& count){ count++; }	//метод можно встроить
};


class B: public A
{
public:
	int obj = 0;

	B(){ Count(obj); }
	~B(){}

	void Create()
	{
		if(...) 
			Count(obj);
		if(...)
			Count(obj);
	}
}



//ПОСЛЕ ПЕРЕМЕЩЕНИЯ МЕТОДА
class  A
{
public:
	int objects = 0;

	 A() { objects++; }
	~ A() {}
};


class B: public A
{
public:
	int obj_count = 0;
	bool condition;

	B(){ Count(obj); }
	~B(){}

	void Count(int& count){ count++; }	//метод можно встроить

	void Create()
	{
		if(condition) 
			Count(obj);
		if(condition)
			Count(obj);
	}
}


/*-------------------------------------------------------------------*/
/*ВСТРАИВАНИЕ И ЗАМЕНА ВРЕМЕННОЙ ПЕРЕМЕННОЙ

/*ВСТРАИВАНИЕ ПЕРЕМЕННОЙ - если переменная хранит
промежуточный результат и нигде не используется, то хранимое значение
или выражение можно встроить*/
bool Foo(B obj)
{
	int B_counter = obj.obj_count;
	return B_counter > 0;
}

//ПОСЛЕ ВСТРАИВАНИЯ 
bool Foo(B obj)
{
	return obj.obj_count > 0;
}


/*ЗАМЕНА ПЕРЕМЕННОЙ - заменить временную переменную с выражением 
на вызов функции, возвращающей это значение (как пример)
*/
double ResFoo(const double k) 
{
  double res = k + pow(k, 2);
  
  	if(res > k) 
  		return res / 2.0;
}

/*ПОСЛЕ ЗАМЕНЫ*/
double ResCalc(const double k)
{
	double res = k + pow(k, 2);
}

double ResFoo()		//ЗА ОДНО И ПЕРЕМЕЩЕНИЕ ПАРАМЕТРА МЕТОДА 
{
	const int p = 20;
    if(ResCalc(k) > p) 
  		return ResCalc(k) / 2;
}


/*-------------------------------------------------------------------*/
/*ДОБАВЛЕНИЕ, УДАЛЕНИЕ И ЗАМЕНА ПАРАМЕТРА МЕТОДА

/*ДОБАВЛЕНИЕ ПАРАМЕТРА - методу не достаточно данных*/
void setDate() {}
void setDate(int date) { int date_ = date; }

/*УДАЛЕНИЕ ПАРАМЕТРА - например, параметр не используется в методе*/
double Func(int a, int b, double c)
{
	return a + b * pow(a, b);
}

/*ПОСЛЕ УДАЛЕНИЯ*/
double Func(int a, int b)
{
	return a + b * pow(a, b);
}


/*-------------------------------------------------------------------*/
/* ВСТРАИВАНИЕ И ВЫДЕЛЕНИЕ МЕТОДА*/
bool Compare(int &a, int &b)	//подлежит встраиванию
{
	if(a == b)
		return true;
}

template<typename T>			//для выделения метода 
T Sub(T a, T b)													  
{																  
	if(a > b)										         	  
	{						  									  
		std::cout << "..." << std::endl;						  
		return a - b;											 
	}										         	          
}										         	              


int main()										         	      
{										         	              
	int a = 5;										         	  
	int b = 10;										         	  
	int res = 0;										          
										         	              
	double c = 3.34;										      
	double d = 5.13;										      
	double sum = 0.0;										      

	
/*ВСТРАИВАНИЕ МЕТОДА -> зачем выделять действие одной очевидной
 строки в отдельный метод? (есил исп. всего несколько раз) */
	Compare(a, b);

	if(a == b) return true;


/*ВЫДЕЛЕНИЕ МЕТОДА -> выделяем и группирум повторяющиеся
 куски кода в отдельный метод Sub*/
	if(a > b)
	{
		std::cout << "..." << std::endl;
		res = a - b;
	}

	if(c > d)
	{
		std::cout << "..." << std::endl;
		res = c - d;
	}

	Sub(a, b);
	Sub(c, d);


	return 0;
}