#include <iostream>
#include <string>
#include <stdlib.h>
#include <Complex.h>

using namespace std;

class Complex
{
	private:
		double a;
		double b;

	public:
		Complex(){//default constructor
			a = 0;
			b = 0;
		}
		Complex(double A, double B){//constructor
			a = A;
			b = B;
		}
		Complex(string str){//constructor
			for (int i =0; i < str.length(); i++){
				if (str.at(i) == ' '){
					str.erase(i,1);
					i--;
				}
			}
			if (str.find("i") > str.find("+")){ //a+bi
				a = atof(str.substr(0, str.find("+")).c_str());
				b = atof(str.substr(str.find("+")+1,str.length()-str.find("+")+1).c_str());
			}
			else if (str.find("i", 0) < str.find("+", 0)){ //bi+a
				b = atof(str.substr(0, str.find("+")).c_str());
				a = atof(str.substr(str.find("+")+1,str.length()-str.find("+")+1).c_str());
			}
			else{
				cout << "Error 1\n";
			}

		}
};
