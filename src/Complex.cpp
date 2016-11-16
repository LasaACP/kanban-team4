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


//assignment operators

	Complex:: void operator=(int a) {
		setReal(a);
	}
	Complex:: void operator=(long a,int b) {
		setReal(a);
		setImag(b);
	}
	Complex:: void operator=(float a) {
		setReal(a);
	}
	Complex:: void operator=(double a) {
		setReal(a);
	}
	Complex:: void operator=(const Complex& a) {
		setReal(a.getReal());
		setImag(a.getImag());
	}

//basic arithematic operators

	Complex:: Complex operator+(int a) {
		setReal(getReal+a);	
	}
	Complex:: Complex operator+(long a, int b) {
		setReal(getReal+a);
		setImag(getImag+b);
	}
	Complex:: Complex operator+(float a) {
		setReal(getReal+a);	
	}
	Complex:: Complex operator+(double a) {
		setReal(getReal+a);	
	}
	Complex:: Complex operator+(const Complex& a) {
		setReal(getReal+a.getReal());
		setImag(getImag+a.getImag());
	}

//basic comparison operators
	Complex:: bool operator==(int a) {
			if(getReal()==a && getImag()==0) {
			return true;
		}
		return false;
	}
	Complex:: bool operator==(long a, int b) {
			if(getReal()==a && getImag()==b) {
			return true;
		}
		return false;
	}
	Complex:: bool operator==(float a) {
			if(getReal()==a && getImag()==0) {
			return true;
		}
		return false;
	}
	Complex:: bool operator==(double a) {
			if(getReal()==a && getImag()==0) {
			return true;
		}
		return false;
	}
	Complex:: bool operator==(Complex& a) {
			if(getReal()==a.getReal() && getImag()==a.getImag()) {
			return true;
		}
		return false;
	}

int main(){}
