/*
A c++ program to design and implement a class  for rational numbers
*/

#include "Rational.h" //user defined header file which contains Rational class and few non-member functions
#include<iostream>
#include<cstdlib>
#include <string>
using std::getline;
/*
Name:Rational
Class:Rational
Arguments: int num, int den
Return Type:void
Notes: This is a constructor to the class Rational which will assign values to the numerator and denominator in the Rational class and also generates an Error when 0 is passed as denominator. It also simplifies the rational number if possible
*/
Rational::Rational(int num, int den)
{
	numerator = num;
	denominator = den;
	sign_change(); // function call to private member function sign_change
	if (denominator == 0)
	{
		cerr << "Error: division by zero"<<endl;
	}
	else
	{
		simplify_object(); // function call to private member function simlify_object which will simplify the current instance of rational number
	}
}
/*
Name:Rational
Class: Rational
Arguments: const Rational &z
Return type: none
Notes: This is a copy constructor which takes a constant refernce to an instance of Rational class andassigns its values to the current instance and its return value is null
*/
Rational::Rational(const Rational &z)
{
	numerator = z.numerator;
	denominator = z.denominator;
}
/*
Name: operator=
Class:Rational
Arguments:const Rational &z
Return Type: Rational&
Notes: This is an overloaded assignment operator which takes a constant eference of a Rational class object and stores it inot the current instance and returns the reference to current instance
*/
Rational& Rational :: operator =(const Rational &z)
{
	if (&z == this) // Checks if the current instance is same as the passed object reference
		return *this;
	 numerator = z.numerator;
	 denominator = z.denominator;
	return *this;
}
/*
Name: operator +=
Class: Rational
Arguments: const Rational &z
Return Type: Rational&
Notes: This as an overloaded operator which takes a constant reference of Rational class and adds it to the current instance and returns the the reference of the current instance

*/
Rational& Rational :: operator +=(const Rational &z)
{
	numerator = (numerator*z.denominator)+ (z.numerator*denominator);
	denominator =denominator* z.denominator;
	sign_change(); //function call to sign_change
	simplify_object(); //function call to simplify_object
	return *this;
}
/*
Name: operator -=
Class: Rational
Arguments: const Rational &z
Return Type: Rational&
Notes: This is an overloaded operator which takes a constant reference of Rational class whose valuse will be subtracted from the current instance and the reference to th current instance will be returned.
*/
Rational& Rational :: operator -=(const Rational &z)
{
	numerator = (numerator*z.denominator) - (z.numerator * denominator);
	denominator = denominator* z.denominator;
	sign_change();
	simplify_object();
	return *this;
}
/*
Name: operator *=
Class: Rational
Arguments: const Rational &z
Return Type: Rational&
Notes: This is an overloaded operator which takes a constant reference of a Rational class instance and multiplies it with the current instance and the returns the reference of current instance
*/
Rational& Rational :: operator *=(const Rational &z)
{
	numerator *= z.numerator;
	denominator *= z.denominator;
	sign_change();
	simplify_object();
	return *this;
}
/*
Name: operator /=
Class: Rational
Arguments: const Rational &z
Return Type: Rational&
Notes: This is a overloaded operator which takes a constant reference of a Rational instance and divides it with the current instance and the return the reference of the current instance
*/
Rational& Rational :: operator /=(const Rational &z)
{
	numerator = numerator*z.denominator;
	denominator = denominator*z.numerator;
	sign_change();
	simplify_object();
	return *this;
}
/*
Name: operator ++
Class: Rational
Arguments: void
Return Type: Rational
Notes: It is an overloaded pre increment operator which increments the current instance value by one and returns it
*/
Rational Rational :: operator ++(void)
{//pre increment
	numerator = numerator + denominator;
	sign_change();
	simplify_object();
	return *this;
}
/*
Name: operator ++
Class: Rational
Arguments: int i
Return Type: Rational
Notes: It is an overloaded post increment operator which takes an argument int i which has no prominence and is used just to distinguish this operator from pre increment operator
*/
Rational Rational :: operator ++(int i)
{
	Rational r(*this); //stores the current instance which is returned and not the incremented instance
	numerator=numerator+denominator;
	sign_change();
	simplify_object();
	return r;
}
/*
Name: operator --
Class: Rational
Arguments: void
Return Type: Rational
Notes: It is an overloaded pre decrement operator which takes no argument , it decrements the value of current instance by one and returns the current instance
*/
Rational Rational :: operator --(void)
{
	numerator=numerator-denominator;
	sign_change();
	simplify_object();
	return *this;
}
/*
Name: operator --
Class: Rational
Arguments: int i
Return Type: Rational
Notes: It is an overloaded post decrement operator which takes int i as argument which has no effect on code, it increments the instance but returns the value before incrementing
*/
Rational Rational :: operator --(int i)
{
	Rational r(*this);
	numerator = numerator - denominator;
	sign_change();
	simplify_object();
	return r;
}
/*
Name: operator +
Arguments: Rational a, Rational b
Return Type: Rational
Note: This is an overloaded operator which is a non-member function, it takes two arguments which are two different instances of Rational classand adds them both and returns the sum of them
*/
Rational operator+(Rational a, Rational b)
{
	Rational c;
	c.numerator = (a.numerator*b.denominator) + (b.numerator*a.denominator);
	c.denominator = a.denominator * b.denominator;
	c.sign_change();
	c.simplify_object();
	return c;
}
/*
Name: operator-
Arguments: Rational a, Rational b
Return Type: Rational
Note: This is a overloaded subtrsction operaotr which is a non member of Rational class, it takes two arguments which are two different instances of Rational and subtracts the second one from the first and returns the output 
*/
Rational operator-(Rational a, Rational b)
{
	Rational c;
	c.numerator = (a.numerator*b.denominator) - (b.numerator*a.denominator);
	c.denominator = a.denominator * b.denominator;
	c.sign_change();
	c.simplify_object();
	return c;
}
/*
Name: operator*
Arguments: Rational a, Rational b
Return Type: Rational
Note: This is a overloaded multiplication operator which takes two arguments which are different instances of Rational class and mutplies them and then return the current instance 
*/
Rational operator*(Rational a, Rational b)
{
	Rational c;
	c.numerator = a.numerator * b.numerator;
	c.denominator = a.denominator * b.denominator;
	c.sign_change();
	c.simplify_object();
	return c;
}
/*
Name: operator/
Arguments: Rational a,Rational b
Return Type: Rational
Note: This is an overloaded operator which takes two arguments which are tow different instances of Rational classand divides the first one with second and the resulting output isthe current instance which is returned
*/
Rational operator/(Rational a, Rational b)
{
	Rational c;
	c.numerator = a.numerator * b.denominator;
	c.denominator = a.denominator * b.numerator;
	c.sign_change();
	c.simplify_object();
	return c;
}
/*
Nmae: operator==
Arguments: const Rational &a, cnst Rational &b
Return Type: bool
Note: It is a overloaded equals to operator which takes  two different constant references of Rational class as arguments and equates them , if they are equal then returns true else false
*/
bool operator==(const Rational &a, const Rational &b)
{

	if (a.numerator == b.numerator&&a.denominator == b.denominator)
		return true;
	return false;
}
/*
Name: operator!=
Arguments: const Rational &a, const Rational &b
Return type: bool
Note: It is an overloaded operator which takes two constant instances of Rational class as arguments and returns false if they are equal else return true
*/
bool operator!=(const Rational &a, const Rational &b)
{
	if (a.numerator != b.numerator || a.denominator != b.denominator)
		return true;
	return false;
}
/*
Name: operator<
Arguments: const Rational &a, const Rational &b
Return Type: bool
Note: It is an overloaded operator which takes two constant references as arguments and compare them if the first one is less than the second then true is returned else a false is returned 
*/
bool operator<(const Rational &a, const Rational &b)
{
	if ((a.numerator*b.denominator) < (b.numerator *a.denominator))
		return true;
	return false;
}
/*
Name: operator<=
Arguments: const Rational &a, Rational &b
Return Type: bool
Note: It is a overloaded operator which takes two instances of Rational class and returns true if the first instance is less than on equal to second instance else false
*/
bool operator<=(const Rational &a, const Rational &b)
{
	if ((a.numerator*b.denominator) <= (b.numerator *a.denominator))
		return true;
	return false;
}
/*
Name:operator>
Arguments: const Rational &a, Rational &b
Return Type: bool
Note: It is a operator which takes two instances of Rational class and returns true if first instance is greater than true else false
*/
bool operator>(const Rational &a, const Rational &b)
{
	if ((a.numerator*b.denominator) > (b.numerator *a.denominator))
		return true;
	return false;
}
/*
Name: operator>=
Arguments: const Rational &a, Rational &b
Return Type: bool
Note: It is a overloaded operator which takes two different instances of Rational class and returns true if the first one is greater than or equal to the second instance else false
*/
bool operator>=(const Rational &a, const Rational &b)
{
	if ((a.numerator*b.denominator) >= (b.numerator *a.denominator))
		return true;
	return false;
}
/*
Name: operator<<
Arguments: ostream &output, const Rational &a
Return Type: ostream &
Note: It is a overloaded operator which takes two arguments one is a reference of the output stream which is ostream by type, and a constant reference of a Rational instance and overrides it so that the output is generated the way user desires, in this case numerator divided by denominator and returns the output ostream reference
*/
ostream & operator<<(ostream &output, const Rational &a)
{
	if (a.denominator == 1)
		output << a.numerator;
	else
		output << a.numerator << "/" << a.denominator; //output is overloaded in this way and returned 
	return output;
}
/*
Name: operator>>
Arguments: istream input, Rational &a
Return Type: istream &
Note: It is a overloaded input operator which takes two arguments a reference of input stream of type istream which is input and a reference of a Rational class instance  
*/
istream & operator>>(istream &input, Rational &a)
{
	string str, str1, str2;
	char c = '"';
	getline(cin, str,'\n');
	size_t p = str.find_first_not_of("-1234567890/ \t "); //Here the string is checked for spcial characters which arent supposed to be in the string includeing alphabets that is except the division operator,digits and spaces
	if (p != std::string::npos) //If the special character is found
	{
		cout << "Error: line " <<c<< str<<c<<" contains invalid number"<<endl;
		return input;
	}
	else // If not found
	{
		int z = str.find('/'); // To check if there is a division operator
		if (z<0) //If not found
		{
			int j = atoi(str.c_str()); //string is converted into int
			str1 = str; //String stored into another variable
			for (int i = str1.length() - 1; i >= 0; --i) //all the white spaces are removed
			{
				if (str1[i] == ' ')
					str1.erase(i, 1);
			}
			int k = atoi(str1.c_str()); //str1 contains string with out spaces and is now converted into int
			if (j == k) //If the values of both converted strings is same then the input is valid and thiis loop is executed
			{
				a.numerator = j;
				a.denominator = 1;
				return input;
			}
			else //If they arent equal then the string contains invalid input
			{
				cout << "Error: line " <<c<< str<<c<<" contains invalid number"<<endl;
				return input;
			}

		}
		else //if the string contains division operator
		{
			// Two sub strings are formed one on either side of the division operator
			str1 = str.substr(0, z - 1); 
			str2 = str.substr(z + 1, str.length());
			// Both the sub strings created are converted into integers
			int j = atoi(str1.c_str());
			int h = atoi(str2.c_str());
			// Spaces from both the sub strings are removed
			for (int i = str1.length() - 1; i >= 0; --i)
			{
				if (str1[i] == ' ')
					str1.erase(i, 1);
			}
			for (int i = str2.length() - 1; i >= 0; --i)
			{
				if (str2[i] == ' ')
					str2.erase(i, 1);
			}
			//Now the strings with out spaces are converted into integers
			int k = atoi(str1.c_str());
			int l = atoi(str2.c_str());
			//If the strings formed with out removing spaces and with removing spaces is same then the values are valid and can form a rational number and so the values are assigned to numerator and denominator
			if (j == k&&h == l)
			{
				a.numerator = k;
				a.denominator = l;
				return input;
			}
			else //If the values of converted ints are not same then they contain invalid numbersand so this loop is executed
				cout << "Error: line " <<c<< str<<c<<" contains invalid number"<<endl;
			return input;
		}

	}
	return input;
}
/*
Name: gcd
CLass: None
Argumenets: int x, int y
Return Typpe: int
Note: This is a non member function but has a lot of significance in the program, it takes two arguments which are integers and finds the GCD of those numbers and returns the GCD value, this function is frequently called by simplify function
*/
int gcd(int x, int y)
{
	int k=0;
	if (x == 0) // If numerator is 0
		return y;
	else if (x > y) // When numerator greater than denominator
	{
		for (int i = y; i > 0; --i)
			if (x%i == 0 && y%i == 0)
				return i;
				
	}
	else if (x < y) //When numerator less than denominator
	{
		for (int i = x; i > 0; --i)
			if (x%i == 0 && y%i == 0)
				return i;
	}
	return k;
}
/*
Name: sign_change
Class: Rational
Arguments: None
Return type: void
Note: This is a private member function of Rational class which changes the sign of current instance of numerator depending upon denominator 
*/
void Rational::sign_change()
{
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}
/*
Name: simplify_object
Class: Rational
Arguments: void 
Return Type: void
Note: This is a private member function of Rational class which calls the non-member function gcd and with returned value this method simplifies the current instance of Rational class 
*/
void Rational::simplify_object()
{
	int gcdivisor = gcd(abs(numerator), abs(denominator));
	numerator /= gcdivisor;
	denominator /= gcdivisor;
}
