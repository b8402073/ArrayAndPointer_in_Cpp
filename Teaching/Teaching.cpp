#include <cassert>
#include <iostream>
using namespace std;
char ff1() { cout<<"ff1"<<endl; return 'f';}
char ff2() { cout<<"ff2"<<endl; return 'g';}
char ff3(int a,int b) { cout<<"a="<<a<<" b="<<b<<endl; return 'h'; }

//°Ñ¦Òhttp://programming.im.ncnu.edu.tw/Chapter12.htm
//This program is an experiment about learning "array and pointer in C".
//I declare the sample variables one by one.
//And then I use them in some way.
char *A;  
//	A is a pointer to char
char B[3];
//	B is array[3] of char 
char C();
//  C is a function() return char
char *D[3];
//  D is array[3] of pointer to char
char (*E)[3];
//  E is a pointer to array[3] of char
char **F;
//  F is a pointer to a pointer to char
char *G();
//  G is a function return a pointer to char

//char *H()[3];  //function cannot return array; you may get error C2090
//  H is a function return an array[3] of pointer to char

char (*I[3])();
// I is array[] of pointer to function() return char

char (*J())();
// J is a function return a pointer to a function() return char

char (*(*K)[3])(int,int);
// K is a pointer to an array[3] of pointer to a function(int,int) return char

int main()
{
	cout<<"The world of CPL is fine"<<endl;
	char that='C';
	char arr[3];  
	arr[0]='1'; arr[1]='2'; arr[2]='3';

	A= (&that);      //without compiler error

	B[0]=that; B[1]=that; B[2]=that;  //without compiler error

	cout<<C()<<endl; //without compiler error

   
	D[0]=A; D[1]=A; D[2]=A;  //without compiler error

	E= &arr;  //without compiler error

	F= &A;    //without compiler error

	cout << G()<<endl;  //print ABCD
	char* temp=G();
	temp[0]='1';
	cout << G()<<endl;  //print 1BCD  
						//assert that G() return a (char*) variable.
	I[0]= &ff1;
	I[1]= &ff1;
	I[2]= &ff1;			//assert that I is array;
	I[0]();				//assert that we can call I[0]

	I[1]=J();			
	I[1]();				//assert that J() return something we can call

	char (*ex[3])(int,int);
	ex[0]= &ff3;
	ex[1]= &ff3;
	ex[2]= &ff3;
	K=&ex;				//assert that K is a pointer to array;
	(*K)[0](1,2);		//assert that K is about something we can call;
		
	getchar();		
	return 0;
}
char C()
{
	cout<<"I am function C() "<<endl;
	return 'C'; 
}
char* G()
{
	static char inner[5]={'A','B','C','D','\0'};
	return inner;
}
/*
function cannot return array;
We will get error C2090;
char *H()[3]
{
	static char zero='0';
	char *ret[3];
	ret[0]=&zero;
	ret[1]=&zero;
	ret[2]=&zero;
	return ret;
}
*/
char (*J())()
{
	return (&ff2);
}