#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include "Complex.h"

#define iunit Complex(0,1);

/*                  */
/*   CONSTRUCTORS   */
/*                  */

/* Constructs a zero number */
Complex::Complex() {
	real = 0;
	imag = 0;
}

/* Constructs a real-only Complex number */
Complex::Complex(int A) {
	real = A;
	imag = 0;
}
Complex::Complex(double A) {
	real = A;
	imag = 0;
}

/* Constructs a Complex number from A and B.
 * If polar=false, then it uses standard rectangular form.
 * If polar=true, it uses polar coordinates
 */
Complex::Complex(double A, double B, bool polar=false) {
	if (!polar) {
		real = A;
		imag = B;
	} else {
		real = A*std::cos(B);
		imag = A*std::sin(B);
	}
}

/* Constructs a Complex number from a string
 * Not complete
 * DO NOT USE
 */
Complex::Complex(std::string str) {
	for (int i =0; i < str.length(); i++) {
		if (str.at(i) == ' ') {
			str.erase(i,1);
			i--;
		}
	}
	if (str.find("i") > str.find("+")) { //a+bi
		real = std::atof(str.substr(0, str.find("+")).c_str());
		imag = std::atof(str.substr(str.find("+")+1,str.length()-str.find("+")+1).c_str());
	}
	else if (str.find("i", 0) < str.find("+", 0)) { //bi+a
		imag = std::atof(str.substr(0, str.find("+")).c_str());
		real = std::atof(str.substr(str.find("+")+1,str.length()-str.find("+")+1).c_str());
	}
	else {
		std::cout << "Error 1\n";
	}

}

/*                    */
/*   MISCEALLANEOUS   */
/*                    */

/* Returns a Complex from the radius r and angle phi
 * Similar to polar=true constructor
 */
Complex Complex::rect(double r, double phi) {
	return Complex(r,phi,true);
}

/* Returns the absolute value of the Complex. */
double Complex::abs(Complex c) {
	return std::sqrt(c.getReal()*c.getReal() + c.getImag()*c.getImag());
}
/* Returns the angle of the Complex. */
double Complex::ang(Complex c) {
	double a = c.getReal();
	double b = c.getImag();
	return std::atan2(b,a);
}

/* Returns the absolute value of the Complex. */
double Complex::getR() {
	return Complex::abs(*this);
}
/* Returns the angle of the Complex. */
double Complex::getPhi() {
	return Complex::ang(*this);
}

/*                */
/*   ASSIGNMENT   */
/*                */

Complex& Complex::operator=(int a) {
	this->setReal(a);
	return *this;
}
Complex& Complex::operator=(long int a) {
	this->setReal(a);
	return *this;
}
Complex& Complex::operator=(float a) {
	this->setReal(a);
	return *this;
}
Complex& Complex::operator=(double a) {
	this->setReal(a);
	return *this;
}
Complex& Complex::operator=(Complex& a) {
	this->setReal(a.getReal());
	this->setImag(a.getImag());
	return *this;
}

/*             */
/*   BOOLEAN   */
/*             */

/* Basic comparison operators */
/* Equality */
	bool Complex::operator==(int a) {
		return (getReal()==a && getImag()==0);
	}
	bool Complex::operator==(long int a) {
		return (getReal()==a && getImag()==0);
	}
	bool Complex::operator==(float a) {
		return (getReal()==a && getImag()==0);
	}
	bool Complex::operator==(double a) {
		return (getReal()==a && getImag()==0);
	}
	bool Complex::operator==(Complex& a) {
		return (getReal()==a.getReal() && getImag()==a.getImag());
	}
/* Not equal */
	bool Complex::operator!=(int a) {
		return (getReal()!=a || getImag()!=0);
	}
	bool Complex::operator!=(long int a) {
		return (getReal()!=a || getImag()!=a);
	}
	bool Complex::operator!=(float a) {
		return (getReal()!=a || getImag()!=0);
	}
	bool Complex::operator!=(double a) {
		return (getReal()!=a || getImag()!=0);
	}
	bool Complex::operator!=(Complex& a) {
		return (getReal()!=a.getReal() || getImag()!=a.getImag());
	}
/* Greater */
	bool Complex::operator>(int a) {
		return (Complex::abs(*this)>a);
	}
	bool Complex::operator>(long int a) {
		return (Complex::abs(*this)>a);
	}
	bool Complex::operator>(float a) {
		return (Complex::abs(*this)>a);
	}
	bool Complex::operator>(double a) {
		return (Complex::abs(*this)>a);
	}
	bool Complex::operator>(Complex& a) {
		return (Complex::abs(*this)>Complex::abs(a));
	}
/* Less */
	bool Complex::operator<(int a) {
		return (Complex::abs(*this)<a);
	}
	bool Complex::operator<(long int a) {
		return (Complex::abs(*this)<a);
	}
	bool Complex::operator<(float a) {
		return (Complex::abs(*this)<a);
	}
	bool Complex::operator<(double a) {
		return (Complex::abs(*this)<a);
	}
	bool Complex::operator<(Complex& a) {
		return (Complex::abs(*this)<Complex::abs(a));
	}
/* GEQ */
	bool Complex::operator>=(int a) {
		return (Complex::abs(*this)>=a);
	}
	bool Complex::operator>=(float a) {
		return (Complex::abs(*this)>=a);
	}
	bool Complex::operator>=(double a) {
		return (Complex::abs(*this)>=a);
	}
	bool Complex::operator>=(Complex& a) {
		return (Complex::abs(*this)>=Complex::abs(a));
	}
/* LEQ */
	bool Complex::operator<=(int a) {
		return (Complex::abs(*this)<=a);
	}
	bool Complex::operator<=(float a) {
		return (Complex::abs(*this)<=a);
	}
	bool Complex::operator<=(double a) {
		return (Complex::abs(*this)<=a);
	}
	bool Complex::operator<=(Complex& a) {
		return (Complex::abs(*this)<=Complex::abs(a));
	}

/*                */
/*   ARITHMETIC   */
/*                */

/* Negation */
Complex Complex::operator-() {
	return Complex(-this->getReal(), -this->getImag());
}

/* Addition */
Complex Complex::operator+(int c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() + c);
	return copy;
}
Complex Complex::operator+(long int c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() + c);
	return copy;
}
Complex Complex::operator+(float c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() + c);
	return copy;
}
Complex Complex::operator+(double c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() + c);
	return copy;
}
Complex Complex::operator+(const Complex& c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() + c.getReal());
	copy.setImag(this->getImag() + c.getImag());
	return copy;
}

// Compound assignment
Complex Complex::operator+=(int a) {
	this->setReal(this->getReal()+a);
	return *this;		
}
Complex Complex::operator+=(long int a) {
	this->setReal(this->getReal()+a);
	return *this;
}
Complex Complex::operator+=(float a) {
	this->setReal(this->getReal()+a);
	return *this;		
}
Complex Complex::operator+=(double a) {
	this->setReal(this->getReal()+a);
	return *this;
}
Complex Complex::operator+=(const Complex& a) {
	this->setReal(this->getReal()+a.getReal());
	this->setImag(this->getImag()+a.getImag());
	return *this;
}

/* Subtraction */

Complex Complex::operator-(int c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() - c);
	return copy;
}
Complex Complex::operator-(long int c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() - c);
	return copy;
}
Complex Complex::operator-(float c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() - c);
	return copy;
}
Complex Complex::operator-(double c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() - c);
	return copy;
}
Complex Complex::operator-(const Complex& c) {
	Complex copy(0,0);
	copy.setReal(this->getReal() - c.getReal());
	copy.setImag(this->getImag() - c.getImag());
	return copy;
}

// Compound assignment
Complex Complex::operator-=(int a) {
	this->setReal(this->getReal() - a);
	return *this;
}
Complex Complex::operator-=(long int a) {
	this->setReal(this->getReal() - a);
	return *this;
}
Complex Complex::operator-=(float a) {
	this->setReal(this->getReal() - a);
	return *this;
}
Complex Complex::operator-=(double a) {
	this->setReal(this->getReal() - a);
	return *this;
}
Complex Complex::operator-=(const Complex& a) {
	this->setImag(this->getImag() - a.getImag());
	this->setReal(this->getReal() - a.getReal());
	return *this;
}

/* Multiplication */
Complex Complex::operator*(int c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() * c);
	copy.setImag(copy.getImag() * c);
	return *this;
}
Complex Complex::operator*(long int c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() * c);
	copy.setImag(copy.getImag() * c);
	return *this;
}
Complex Complex::operator*(float c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() * c);
	copy.setImag(copy.getImag() * c);
	return *this;
}
Complex Complex::operator*(double c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() * c);
	copy.setImag(copy.getImag() * c);
	return copy;
}
Complex Complex::operator*(const Complex& c) {
	Complex copy(0,0);
	copy.setReal(this->getReal()*c.getReal() - this->getImag()*c.getImag());
	copy.setImag(this->getImag()*c.getReal() + this->getReal()*c.getImag());
	return copy;
}

// Compound assignment
Complex Complex::operator*=(int c) {
	this->setReal(this->getReal() * c);
	this->setImag(this->getImag() * c);
	return *this;
}
Complex Complex::operator*=(long int c) {
	this->setReal(this->getReal() * c);
	this->setImag(this->getImag() * c);
	return *this;
}
Complex Complex::operator*=(float c) {
	this->setReal(this->getReal() * c);
	this->setImag(this->getImag() * c);
	return *this;
}
Complex Complex::operator*=(double c) {
	this->setReal(this->getReal() * c);
	this->setImag(this->getImag() * c);
	return *this;
}
Complex Complex::operator*=(const Complex& c) {
	Complex copy(0,0);
	copy.setReal(this->getReal()*c.getReal() - this->getImag()*c.getImag());
	copy.setImag(this->getImag()*c.getReal() + this->getReal()*c.getImag());
	*this = copy;
	return *this;
}


/* Division */
Complex Complex::operator/(int c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() / c);
	copy.setImag(copy.getImag() / c);
	return copy;
}
Complex Complex::operator/(long int c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() / c);
	copy.setImag(copy.getImag() / c);
	return copy;
}
Complex Complex::operator/(float c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() / c);
	copy.setImag(copy.getImag() / c);
	return copy;
}
Complex Complex::operator/(double c) {
	Complex copy(0,0);
	copy.setReal(copy.getReal() / c);
	copy.setImag(copy.getImag() / c);
	return copy;
}
Complex Complex::operator/(const Complex& c) {
	Complex copy(0,0);
	double denom = c.getReal()*c.getReal() + c.getImag()*c.getImag();
	copy.setReal((this->getReal()*c.getReal() + this->getImag()*c.getImag())/denom);
	copy.setImag((this->getImag()*c.getReal() - this->getReal()*c.getImag())/denom);
	return copy;
}

// Compound assignment
Complex Complex::operator/=(int c) {
	this->setReal(this->getReal() / c);
	this->setImag(this->getImag() / c);
	return *this;
}
Complex Complex::operator/=(long int c) {
	this->setReal(this->getReal() / c);
	this->setImag(this->getImag() / c);
	return *this;
}
Complex Complex::operator/=(float c) {
	this->setReal(this->getReal() / c);
	this->setImag(this->getImag() / c);
	return *this;
}
Complex Complex::operator/=(double c) {
	this->setReal(this->getReal() / c);
	this->setImag(this->getImag() / c);
	return *this;
}
Complex Complex::operator/=(const Complex& c) {
	Complex copy(0,0);
	copy.setReal((this->getReal()*c.getReal() + this->getImag()*c.getImag())/(this->getImag()*this->getImag() + c.getImag()*c.getImag()));
	copy.setImag((this->getImag()*c.getReal() - this->getReal()*c.getImag())/(this->getImag()*this->getImag() + c.getImag()*c.getImag()));
	*this = copy;
	return *this;
}

/* Modulo */

/*Complex Complex::operator%=(int a) {
	this->setReal(this->getReal() % a);
	return *this;
}
Complex Complex::operator%=(long int a) {
	this->setReal(this->getReal() % a);
	return *this;
}
Complex Complex::operator%=(const Complex& a) {
	this->setImag(this->getImag() % a.getImag());
	this->setReal(this->getReal() % a.getReal());
	return *this;
}*/

/* Increment and Decrement */

/// Increment
// prefix
Complex& Complex::operator++(){
	setReal(getReal() +1.0);
	return *this;	
}
// postfix 
Complex Complex::operator++(int){
	Complex copy(this->getReal(), this->getImag()); // copy
    operator++(); // pre-increment
    return copy;   // return old value
}

/// Decrement
// prefix
Complex& Complex::operator--(){
	setReal(getReal() -1.0);
	return *this;
}
// postfix
Complex Complex::operator--(int){
	Complex copy(this->getReal(), this->getImag()); // copy
    operator--(); // pre-increment
    return copy;   // return old value
}

/*                          */
/* MISCEALLANEOUS OPERATORS */
/*                          */

/* Stream insertion */
std::ostream& operator<<(std::ostream &output, const Complex& a) {
	output << a.getReal() << "+" << a.getImag() << "i";
	return output;
}
std::istream& operator>>(std::istream &input, Complex& a) {
	double real, imag;
	input >> real >> imag;
	a.setReal(real);
	a.setImag(imag);
	return input;
}

/* Subscript; Complex[0] and Complex[1] shorthand for .getReal() and .getImag() */
double Complex::operator[](int i) {
	if (i == 0) {
		return this->getReal();
	} else if (i == 1) {
		return this->getImag();
	} else {
		return 0;
	}
}


/*                     */
/*    MATH FUNCTIONS   */
/*                     */

/* Exponential function */

Complex Complex::log(Complex ori){ //natural log
	Complex copy(0,0);
	copy.setReal(std::log(ori.getR()));
	copy.setImag(ori.getPhi());
	return copy;
}
Complex Complex::log10(Complex ori){
	Complex copy(0,0);
	copy.setReal((std::log10(ori.getR())));
	copy.setImag(ori.getPhi()/std::log(10));
	return copy;
}
Complex Complex::log2(Complex ori){
	Complex copy(0,0);
	copy.setReal(std::log(ori.getR())/std::log(2));
	copy.setImag(ori.getPhi()/std::log(2));
	return copy;
}
Complex Complex::logb(float base,Complex ori){
	Complex copy(0,0);
	copy.setReal(std::log(ori.getR())/std::log(base));
	copy.setImag(ori.getPhi()/std::log(base));
	return copy;
}


Complex Complex::exp(Complex& c) {
	return (Complex(std::cos(c.getImag()),std::sin(c.getImag())) * std::exp(c.getReal()));
}

/* Trig functions */
/* DOES NOT WORK  */
/*Complex Complex::sin(Complex& c) {
	return (exp(c * Complex(0,1)) - exp((-c) * Complex(0,1)))/(Complex(0,2));
}
Complex Complex::cos(Complex& c) {
	return (exp(c * Complex(0,1)) + exp((-c) * Complex(0,1)))/(2);
}*/

int main() {
	Complex a(1,0), b(-1,1), c(2,-3), d(1,1);
	std::cout << (c < d) << std::endl;
	std::cout << (b >= d) << std::endl;
}
