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

/* Stream insertion */

std::ostream &operator<<(std::ostream &output, const Complex& a) {
	output << a.getReal() << "+" << a.getImag() << "i";
	return output;
}
std::istream &operator>>(std::istream &input, Complex& a) {
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

Complex Complex::operator-() {
	return Complex(-this->getReal(), -this->getImag());
}

int main() {
	Complex a(3,4);
	std::cout << (-a);
}
