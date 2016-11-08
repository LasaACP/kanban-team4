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
}

#endif
