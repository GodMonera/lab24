#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber operator+(double s,const ComplexNumber &c){

	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}

ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}

ComplexNumber operator/(double s,const ComplexNumber &c){
	return ComplexNumber((s*c.real)/(pow(c.real,2) + pow(c.imag,2)) ,(s*(-c.imag))/(pow(c.real,2) + pow(c.imag,2)));
}

bool operator==(double s,const ComplexNumber &c){
	if(s == c.real && c.imag == 0){
		return true;
	}else{
		return false;
	}
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real - imag*c.imag,real*c.imag + imag*c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber((c.real*real + c.imag*imag)/(pow(c.real,2) + pow(c.imag,2)) ,(c.real*imag - c.imag*real)/(pow(c.real,2) + pow(c.imag,2)));
}

bool ComplexNumber::operator==(const ComplexNumber &c1){
	if(real == c1.real && imag == c1.imag){
		return true;
	}else{
		return false;
	}
}

double ComplexNumber::abs(){

	return sqrt(pow(real,2) + pow(imag,2));
}

double ComplexNumber::angle(){
if(real < 0 && imag > 0) { return  180 + atan(imag/real)*180/3.14159; }else
if(real < 0 && imag < 0) { return  atan(imag/real)*180/3.14159 - 180; }
else { return atan(imag/real)*180/3.14159; }
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
	if(c.imag > 0 && c.real) { return os<< c.real << "+" << c.imag << "i";	}else
	if(c.imag == 0 && c.real == 0){ return os<< 0; }else
	if(c.real == 0){ return os<< c.imag << "i"; }else
    if(c.imag == 0){ return os<< c.real; } else
	{	return os<< c.real << "-" << -c.imag << "i"; }
}


int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





