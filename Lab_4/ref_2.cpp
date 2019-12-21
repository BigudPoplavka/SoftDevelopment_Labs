//REFACTORING PART 2
//РАБОТА С УСЛОВНЫМИ ВЫРАЖЕНИЯМИ
#include <stdio.h>
#include <iostream>

int a;
int b;
int res;

/*ДЕКОМПОЗИЦИЯ УСЛОВНОГО ОПЕРАТОРА -
разбиение одного уловного оператора со сложным условием
на несколько с простыми, или выделение сложного усовия*/

if(a > 0 && a < 10 && b > a)
	return b;

//ПОСЛЕ ДЕКОМПОЗИЦИИ
//a)
if(a > 0 && a < 10)
	if(b > a)
		return b;
//b)
bool Foo()
{
	if(a > 0 && a < 10 && b > a)
		return true;
}

if(Foo())
	return b;
//c)
bool condOne = a > 0 && a < 10;
bool condTwo = b > a;

if(condOne && condTwo)
	return b;


/*-------------------------------------------------------------------*/
/*КОНСОЛИДАЦИЯ УСЛОВНОГО ВЫРАЖЕНИЯ - 
объединение ветвей,дающих одинаковый результат*/
if(a > b)
	return 1;
if(a >= b)
	return 1;
if(a < b)
	return 1;

//ПОСЛЕ КОНСОЛИДАЦИИ
bool condition = a > b || a >= b || a < b;
if(condition) 
	return 1;


/*-------------------------------------------------------------------*/
/*КОНСОЛИДАЦИЯ ДУБЛИРУЮЩИХСЯ УСЛОВНЫХ ФРАГМЕНТОВ -
один и тот же фрагмент кода во всех ветках */
if(a > b)
{
	res = a + b;
	return 1;
}
if(a >= b)
{
	res = a - b;
	return 1;
}
if(a < b)
{
	res = a * b;
	return 1;
}

//ПОСЛЕ КОНСОЛИДАЦИИ
if(a > b)
	res = a + b;
if(a >= b)
	res = a - b;
if(a < b)
	res = a * b;

return 1;


/*-------------------------------------------------------------------*/
/*УДАЛЕНИЕ УПРАВЛЯЮЩЕГО ФЛАГА*/
bool flag;
for(int i = 0; i < 10; i++)
{
	if(a < b) 
		flag = true;
	if(flag == true)
		a = a * b;
	else
		flag = false; 
}

//ПОСЛЕ УДАЛЕНИЯ
for(int i = 0; i < 10; i++)
{
	if(a < b) 
		a = a * b;
	else
		continue;  
}
