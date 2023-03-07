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
		friend ComplexNumber operator+(double,const ComplexNumber &);
		friend ComplexNumber operator-(double,const ComplexNumber &);
		friend ComplexNumber operator*(double,const ComplexNumber &);
		friend ComplexNumber operator/(double,const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		friend bool operator==(double,const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(c.real*imag)+(c.imag*real));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber((real*c.real+imag*c.imag)/(pow(c.imag,2)+pow(c.real,2)),(c.real*imag-c.imag*real)/(pow(c.imag,2)+pow(c.real,2)));
}

double ComplexNumber::abs(){
	return (sqrt(pow(real,2)+pow(imag,2)));
}

double ComplexNumber::angle(){
	return atan2(imag,real)*180/M_PI;
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return (real == c.real && imag == c.imag);
}

ComplexNumber operator+(double t,const ComplexNumber &c){
	return ComplexNumber(t+c.real,0+c.imag);
}

ComplexNumber operator-(double t,const ComplexNumber &c){
	return ComplexNumber(t-c.real,0-c.imag);
}

ComplexNumber operator*(double t,const ComplexNumber &c){
	return ComplexNumber(t*c.real-0,0+c.imag*t);
}

ComplexNumber operator/(double t,const ComplexNumber &c){
	return ComplexNumber((t*c.real+0)/(pow(c.imag,2)+pow(c.real,2)),(0-c.imag*t)/(pow(c.imag,2)+pow(c.real,2)));
}

bool operator==(double u, const ComplexNumber &c){
	return (u == c.real && 0 == c.imag);
}

ostream & operator<<(ostream &os,const ComplexNumber &h){
	if (h.real > 0 )
	{
		if (h.imag > 0)
		{
			return os <<h.real<<'+'<<h.imag<<'i';
		}else if (h.imag<0)
		{
			return os <<h.real<<h.imag<<'i';
		}else{
			return os <<h.real;
		}
	}else if (h.real<0)
	{
		if (h.imag > 0)
		{
			return os <<h.real<<'+'<<h.imag<<'i';
		}else if (h.imag<0)
		{
			return os <<h.real<<h.imag<<'i';
		}else{
			return os <<h.real;
		}
	}else{
		if (h.imag > 0)
		{
			return os <<h.imag<<'i';
		}else if (h.imag<0)
		{
			return os <<h.imag<<'i';
		}else{
			return os <<0;
		}
	}
	return os <<h.real<<h.imag<<"i";
}


//Write your code here

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
	cout << (a+b)<<'\n';
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





