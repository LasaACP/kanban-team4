#include <iostream>
#include <string>
#include <cmath>
#include "Complex.h"

#define iunit Complex(0,1);

Complex::Complex() {
	real = 0;
	imag = 0;
}
Complex::Complex(int A) {
	real = A;
	imag = 0;
}
Complex::Complex(double A) {
	real = A;
	imag = 0;
}
Complex::Complex(double A, double B, bool polar=false) {
	if (!polar) {
		real = A;
		imag = B;
	} else {
		real = A*std::cos(B);
		imag = A*std::sin(B);
	}
}
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

Complex Complex::rect(double r, double phi) {
	return Complex(r,phi,true);
}

double Complex::abs(Complex c) {
	return std::sqrt(c.getReal()*c.getReal() + c.getImag()*c.getImag());
}
double Complex::ang(Complex c) {
	double a = c.getReal();
	double b = c.getImag();
	return std::atan2(b,a);
}

double Complex::getR(Complex c) {
	return Complex::abs(c);
}
double Complex::getPhi(Complex c) {
	return Complex::ang(c);
}

//multiplication
Complex Complex::operator*(int c){
	setReal(getReal() * c);
	setImag(getImag() * c);
	return *this;
}
Complex Complex::operator*(long int c){
	setReal(getReal() * c);
	setImag(getImag() * c);
	return *this;
}
Complex Complex::operator*(float c){
	setReal(getReal() * c);
	setImag(getImag() * c);
	return *this;
}
Complex Complex::operator*(double c){
	setReal(getReal() * c);
	setImag(getImag() * c);
	return *this;
}
Complex Complex::operator*(Complex& c){
	Complex copy1(this->getReal(), this->getImag()); // copy
	copy1.setReal(getReal() * c.getReal());
	copy1.setImag(getImag() * c.getReal());
	Complex copy2(this->getReal(), this->getImag()); // copy
	copy2.setReal(-1*getImag() * c.getImag());
	copy2.setImag(getReal() * c.getImag());
	setReal(copy1.getReal() + copy2.getReal());
	setImag(copy1.getImag() + copy2.getImag());
	return *this;
}
//division
Complex Complex::operator/(int c){
	setReal(getReal() / c);
	setImag(getImag() / c);
	return *this;
}
Complex Complex::operator/(long int c){
	setReal(getReal() / c);
	setImag(getImag() / c);
	return *this;
}
Complex Complex::operator/(float c){
	setReal(getReal() / c);
	setImag(getImag() / c);
	return *this;
}
Complex Complex::operator/(double c){
	setReal(getReal() / c);
	setImag(getImag() / c);
	return *this;
}
Complex Complex::operator/(Complex& c){
	Complex copy1(this->getReal(), this->getImag()); // copy
	copy1.setReal(getReal() / c.getReal());
	copy1.setImag(getImag() / c.getReal());
	Complex copy2(this->getReal(), this->getImag()); // copy
	copy2.setReal(getImag() / c.getImag());
	copy2.setImag(getReal() / c.getImag());
	setReal(copy1.getReal() + copy2.getReal());
	setImag(copy1.getImag() + copy2.getImag());
	return *this;
}

/*increment and decrement*/

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

double Complex::operator[](int i) {
	if (i == 0) {
		return this->getReal();
	} else if (i == 1) {
		return this->getImag();
	} else {
		return 0;
	}
}

Complex Complex::exp(Complex& c) {
	return (Complex(std::cos(c.getImag()),std::sin(c.getImag())) * std::exp(c.getReal()));
}
/*Complex Complex::sin(Complex& c) {
	return (exp(c * Complex(0,1)) - exp((-c) * Complex(0,1)))/(Complex(0,2));
}
Complex Complex::cos(Complex& c) {
	return (exp(c * Complex(0,1)) + exp((-c) * Complex(0,1)))/(2);
}*/

Complex Complex::operator-() {
	return Complex(-this->getReal(), -this->getImag());
}

int main() { }
