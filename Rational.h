/*
Header file Rational class which includes header files followed by the class and in the class public and private members and also have declarations of the friend functions in class followed by non-member functions
*/
#ifndef Test
#define Test
#include<iostream>
#include<cstdlib> //To use c standard library functions
#include<cctype>
#include<string> //To use string class

using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::istream;
using std::ostream;
/*
class Name: Rational
Description: This class is implemented for procssing rational numbers
*/
class Rational
{
	/*
	Below are the private members of the class, by default class is private
	*/
	int numerator, denominator;
	void sign_change();
	void simplify_object();
	/*
	Below are the public members of the class which includes constructor, copy constructor, increment and decrement operators, assignmnet operators are few. Friend functions are declared below
	*/
public:
	Rational(int num=0 , int den=1);
	Rational(const Rational &z);
	Rational& operator =(const Rational &z);
	Rational& operator +=(const Rational &z);
	Rational& operator -=(const Rational &z);
	Rational& operator *=(const Rational &z);
	Rational& operator /=(const Rational &z);
	Rational operator ++(void);
	Rational operator ++(int i);
	Rational operator --(void);
	Rational operator --(int i);
	friend Rational operator +(Rational a, Rational b);
	friend Rational operator -(Rational a, Rational b);
	friend Rational operator *(Rational a, Rational b);
	friend Rational operator /(Rational a, Rational b);
	friend bool operator ==(const Rational &a, const Rational &b);
	friend bool operator !=(const Rational &a, const Rational &b);
	friend bool operator <(const Rational &a, const Rational &b);
	friend bool operator <=(const Rational &a, const Rational &b);
	friend bool operator >(const Rational &a, const Rational &b);
	friend bool operator >=(const Rational &a, const Rational &b);
	friend ostream & operator<<(ostream &output, const Rational &a);
	friend istream & operator>>(istream &input, Rational &a);
};
/*
Below are the non-member functions which include few operators and other user defined methods
*/
Rational operator+(Rational a, Rational b);
Rational operator-(Rational a, Rational b);
Rational operator*(Rational a, Rational b);
Rational operator/(Rational a, Rational b);
bool operator ==(const Rational &a, const Rational &b);
bool operator !=(const Rational &a, const Rational &b);
bool operator <(const Rational &a, const Rational &b);
bool operator <=(const Rational &a, const Rational &b);
bool operator >(const Rational &a, const Rational &b);
bool operator >=(const Rational &a, const Rational &b);
ostream & operator<<(ostream &output, const Rational &a);
istream & operator>>(istream &input, Rational &a);
int gcd(int x, int y);

#endif // !1