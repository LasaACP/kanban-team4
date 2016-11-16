#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <cstdlib>

class Complex {
	private:
		double real, imag;

	public:
	/* CONSTRUCTORS */
		Complex();
		Complex(double);
		Complex(double,double);
		Complex(std::string);

	/* READ WRITE */

		void setReal(double a) {
			this->real = a;
		};
		void setImag(double a) {
			this->imag = a;
		};

		double getReal() {
			return this->real;
		};
		double getImag() {
			return this->imag;
		};

	/* OPERATORS */
	
		/* Basic assignment operators */

			void operator=(int);
			void operator=(long int);
			void operator=(float);
			void operator=(double);
			void operator=(const Complex&);

		/* Integer promotion and negation */

			Complex operator+();
			Complex operator-();
		
		/* Basic arithmetic operators */

			Complex operator+(int);
			Complex operator+(long int);
			Complex operator+(float);
			Complex operator+(double);
			Complex operator+(const Complex&);

			Complex operator-(int);
			Complex operator-(long int);
			Complex operator-(float);
			Complex operator-(double);
			Complex operator-(Complex&);
			
			Complex operator*(int);
			Complex operator*(long int);
			Complex operator*(float);
			Complex operator*(double);
			Complex operator*(const Complex&);
			
			Complex operator/(int);
			Complex operator/(long int);
			Complex operator/(float);
			Complex operator/(double);
			Complex operator/(const Complex&);
			
			Complex operator%(int);
			Complex operator%(long int);
			Complex operator%(float);
			Complex operator%(double);
			Complex operator%(const Complex&);

		/* Increment/decrement */

			// prefix
			Complex& operator++();
			// postfix 
			Complex operator++(int);

			// prefix
			Complex& operator--();
			// postfix
			Complex operator--(int);

		/* Comparision */

			bool operator==(int);
			bool operator==(long int);
			bool operator==(float);
			bool operator==(double);
			bool operator==(Complex&);

			bool operator!=(int);
			bool operator!=(long int);
			bool operator!=(float);
			bool operator!=(double);
			bool operator!=(Complex&);

			bool operator>(int);
			bool operator>(long int);
			bool operator>(float);
			bool operator>(double);
			bool operator>(Complex&);

			bool operator<(int);
			bool operator<(long int);
			bool operator<(float);
			bool operator<(double);
			bool operator<(Complex&);

			bool operator>=(int);
			bool operator>=(long int);
			bool operator>=(float);
			bool operator>=(double);
			bool operator>=(Complex&);

			bool operator<=(int);
			bool operator<=(long int);
			bool operator<=(float);
			bool operator<=(double);
			bool operator<=(Complex&);

		/* Logical */

			// N/A

		/* Bitwise */

			Complex operator~();

			Complex operator&(int);
			Complex operator&(long int);
			Complex operator&(float);
			Complex operator&(double);
			Complex operator&(Complex);

			Complex operator|(int);
			Complex operator|(long int);
			Complex operator|(float);
			Complex operator|(double);
			Complex operator|(Complex);

			Complex operator^(int);
			Complex operator^(long int);
			Complex operator^(float);
			Complex operator^(double);
			Complex operator^(Complex);

			Complex operator<<(int);
			Complex operator<<(long int);
			Complex operator<<(float);
			Complex operator<<(double);
			Complex operator<<(Complex);

			Complex operator>>(int);
			Complex operator>>(long int);
			Complex operator>>(float);
			Complex operator>>(double);
			Complex operator>>(Complex);

		/* Compound assignment */

			Complex operator+=(int);
			Complex operator+=(long int);
			Complex operator+=(float);
			Complex operator+=(double);
			Complex operator+=(const Complex&);

			Complex operator-=(int);
			Complex operator-=(long int);
			Complex operator-=(float);
			Complex operator-=(double);
			Complex operator-=(const Complex&);
			
			Complex operator*=(int);
			Complex operator*=(long int);
			Complex operator*=(float);
			Complex operator*=(double);
			Complex operator*=(const Complex&);
			
			Complex operator/=(int);
			Complex operator/=(long int);
			Complex operator/=(float);
			Complex operator/=(double);
			Complex operator/=(const Complex&);
			
			Complex operator%=(int);
			Complex operator%=(long int);
			Complex operator%=(float);
			Complex operator%=(double);
			Complex operator%=(const Complex&);

			Complex operator|=(int);
			Complex operator|=(long int);
			Complex operator|=(float);
			Complex operator|=(double);
			Complex operator|=(Complex);

			Complex operator^=(int);
			Complex operator^=(long int);
			Complex operator^=(float);
			Complex operator^=(double);
			Complex operator^=(Complex);

			Complex operator<<=(int);
			Complex operator<<=(long int);
			Complex operator<<=(float);
			Complex operator<<=(double);
			Complex operator<<=(Complex);

			Complex operator>>=(int);
			Complex operator>>=(long int);
			Complex operator>>=(float);
			Complex operator>>=(double);
			Complex operator>>=(Complex);

		/* Pointer */
			
			Complex& operator[](int);
			Complex& operator[](long int);
			Complex& operator[](float);
			Complex& operator[](double);
			Complex& operator[](Complex);

		/* Other */

			// Complex operator""_c(std::string);
			void* operator new (size_t);
			void* operator new[] (size_t);
			void operator delete(void*);
			void operator delete[](void*);

	/* MATH FUNCTIONS */

		/* Exponents */

			static Complex sqrt(Complex);
			static Complex cbrt(Complex);
			static Complex hypot(Complex);

			Complex pow(int);
			Complex pow(long int);
			Complex pow(float);
			Complex pow(double);
			Complex pow(Complex);
	
			static Complex exp(Complex);
			static Complex exp2(Complex);

			static Complex log(Complex);
			static Complex log10(Complex);
			static Complex log2(Complex);
			static Complex logb(float,Complex);

		/* Trig */
	
			static Complex cos(Complex);
			static Complex sin(Complex);
			static Complex tan(Complex);
			
			static Complex acos(Complex);
			static Complex asin(Complex);
			static Complex atan(Complex);

		/* Hyperbolic */

			static Complex cosh(Complex);
			static Complex sinh(Complex);
			static Complex tanh(Complex);
			
			static Complex acosh(Complex);
			static Complex asinh(Complex);
			static Complex atanh(Complex);

		/* Classification */

			bool isInfinite();
			bool isNaN();

		/* Complex */

			double polarR();
			double polarPhi();

			static Complex rect(double r, double phi);

		/* Constants */

			static double E;
			static double PI;
		
};

#endif
