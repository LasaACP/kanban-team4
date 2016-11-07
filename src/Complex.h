#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
	private:
		double real, imaginary;
	public:
		// Basic assignment operators
		// Takes different types of numbers
		void operator=(int);
		void operator=(long int);
		void operator=(float);
		void operator=(double);
		void operator=(const Complex&);
		
		// Basic arithmetic operators
		// Can use different types of numbers
		Complex operator+(int);
		Complex operator+(long int);
		Complex operator+(float);
		Complex operator+(double);
		Complex operator+(const Complex&);
}

#endif
