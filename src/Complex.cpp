#include <iostream>
#include <string>
#include "Complex.h"

Complex::Complex() {
	real = 0;
	imag = 0;
}
Complex::Complex(double A) {
	real = A;
	imag = 0;
}
Complex::Complex(double A, double B) {
	real = A;
	imag = B;
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

Complex operator-(int a)
{
	this.setReal(this.getReal()-double(a));
	return this;
}
Complex operator-(long int a)
{
	this.setReal(this.getReal()-double(a));
	return this;
}
Complex operator-(float a)
{
	this.setReal(this.getReal()-double(a));
	return this;
}
Complex operator-(double a)
{
	this.setReal(this.getReal()-a);
	return this;
}
Complex operator-(Complex& a)
{
	this.setImag(this.getImag() - a.getImag());
	this.setReal(this.getReal() - a.getReal());
	return this;
}
int main(){}
