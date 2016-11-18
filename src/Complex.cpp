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
	void Complex::operator =(int a) {
		setReal(a);
	}
	void Complex::operator =(long int a) {
		setReal(a);
	}
	void Complex::operator =(float a) {
		setReal(a);
	}
	void Complex::operator =(double a) {
		setReal(a);
	}
	void Complex::operator =(Complex& a) {
		setReal(a.getReal());
		setImag(a.getImag());
	}

//basic arithematic operators

	Complex Complex::operator+(int a) {
		Complex::setReal(getReal()+a);
		return *this;		
	}
	Complex Complex::operator+(long int a) {
		setReal(getReal()+a);
		return *this;
	}
	Complex Complex::operator+(float a) {
		setReal(getReal()+a);
		return *this;		
	}
	Complex Complex::operator+(double a) {
		setReal(getReal()+a);
		return *this;
	}
	Complex Complex::operator+(Complex& a) {
		Complex::setReal(Complex::getReal()+a.getReal());
		Complex::setImag(Complex::getImag()+a.getImag());
		return *this;
	}

//basic comparison operators
	bool Complex::operator==(int a) {
			if(getReal()==a && getImag()==0) {
			return true;
		}
		return false;
	}
	bool Complex::operator==(long int a) {
			if(getReal()==a && getImag()==0) {
			return true;
		}
		return false;
	}
	bool Complex::operator==(float a) {
			if(getReal()==a && getImag()==0) {
			return true;
		}
		return false;
	}
	bool Complex::operator==(double a) {
			if(getReal()==a && getImag()==0) {
			return true;
		}
		return false;
	}
	bool Complex::operator==(Complex& a) {
			if(getReal()==a.getReal() && getImag()==a.getImag()) {
			return true;
		}
		return false;
	}
	//new operator
	bool Complex::operator!=(int a) {
			if(getReal()!=a || getImag()!=0) {
			return true;
		}
		return false;
	}
	bool Complex::operator!=(long int a) {
			if(getReal()!=a || getImag()!=a) {
			return true;
		}
		return false;
	}
	bool Complex::operator!=(float a) {
			if(getReal()!=a || getImag()!=0) {
			return true;
		}
		return false;
	}
	bool Complex::operator!=(double a) {
			if(getReal()!=a || getImag()!=0) {
			return true;
		}
		return false;
	}
	bool Complex::operator!=(Complex& a) {
			if(getReal()!=a.getReal() || getImag()!=a.getImag()) {
			return true;
		}
		return false;
	}
	//new operator
	bool Complex::operator>(int a) {
		if(getReal()>a) {
			return true;
		}
		return false;
	}
	bool Complex::operator>(long int a) {
		if(getReal()>a) {
			return true;
		}
		return false;
	}
	bool Complex::operator>(float a) {
		if(getReal()>a) {
			return true;
		}
		return false;
	}
	bool Complex::operator>(double a) {
		if(getReal()>a) {
			return true;
		}
		return false;
	}
	bool Complex::operator>(Complex& a) {
		if(getReal()>a.getReal()) {
			return true;
		}
		return false;
	}
	//new operator
	bool Complex::operator<(int a) {
		if(getReal()<a) {
			return true;
		}
		return false;
	}
	bool Complex::operator<(long int a) {
		if(getReal()<a) {
			return true;
		}
		return false;
	}
	bool Complex::operator<(float a) {
		if(getReal()<a) {
			return true;
		}
		return false;
	}
	bool Complex::operator<(double a) {
		if(getReal()<a) {
			return true;
		}
		return false;
	}
	bool Complex::operator<(Complex& a) {
		if(getReal()<a.getReal()) {
			return true;
		}
		return false;
	}
	//new operator
	bool Complex::operator>=(int a) {
		if(getReal()>a) { return true; }
		else if(getReal()==a && getImag()==0) {return true;}
		return false;
	}
	bool Complex::operator>=(long int a) {
		if(getReal()>a) { return true; }
		else if(getReal()==a && getImag()==0) {return true;}
		return false;
	}
	bool Complex::operator>=(float a) {
		if(getReal()>a) { return true; }
		else if(getReal()==a && getImag()==0) {return true;}
		return false;
	}
	bool Complex::operator>=(double a) {
		if(getReal()>a) { return true; }
		else if(getReal()==a && getImag()==0) {return true;}
		return false;
	}
	bool Complex::operator>=(Complex& a) {
		if(getReal()>a.getReal()) { return true; }
		else if(getReal()==a.getReal() && getImag()==a.getImag()) {return true;}
		return false;
	}
	//new operator
	bool Complex::operator<=(long int a) {
		if(getReal()<a) { return true; }
		else if(getReal()==a && getImag()==0) {return true;}
		return false;
	}
	bool Complex::operator<=(float a) {
		if(getReal()<a) { return true; }
		else if(getReal()==a && getImag()==0) {return true;}
		return false;
	}
	bool Complex::operator<=(double a) {
		if(getReal()<a) { return true; }
		else if(getReal()==a && getImag()==0) {return true;}
		return false;
	}
	bool Complex::operator<=(Complex& a) {
		if(getReal()<a.getReal()) { return true; }
		else if(getReal()==a.getReal() && getImag()==a.getImag()) {return true;}
		return false;
	}
int main(){}
