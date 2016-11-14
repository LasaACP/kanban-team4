#include <iostream>
#include <string>
#include <Complex.h>

class Complex
{
	private:
		double real;
		double imag;

	public:
		Complex() {//default constructor
			real = 0;
			imag = 0;
		}
		Complex(double A) {
			real = A;
			imag = 0;
		}
		Complex(double A, double B) {//constructor
			real = A;
			imag = B;
		}
		Complex(std::string str) {//constructor
			for (int i =0; i < str.length(); i++){
				if (str.at(i) == ' '){
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
			else{
				std::cout << "Error 1\n";
			}

		}

		double getReal() {
			return this->real;
		}
		double getImag() {
			return this->imag;
		}
		
		void setReal(double a) {
			this->real = a;
		}
		void setImag(double a) {
			this->imag = a;
		}
};
