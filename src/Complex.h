#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
	private:
		double real, imaginary;
	public:
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
			Complex operator-(const Complex&);
			
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

			Complex sqrt();
			Complex cbrt();
			Complex hypot();

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
	
			Complex cos();
			Complex sin();
			Complex tan();
			
			Complex acos();
			Complex asin();
			Complex atan();

		/* Hyperbolic */

			Complex cosh();
			Complex sinh();
			Complex tanh();
			
			Complex acosh();
			Complex asinh();
			Complex atanh();

		/* Classification */

			bool isInfinite();
			bool isNaN();

		/* Complex */

			double polarR();
			double polarPhi();

			Complex rect(double r, double phi);

		/* Constants */

			static double E;
			static double PI;
		
}

#endif
