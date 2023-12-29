#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Complex {
    
    public:
        double real;
        double img;
        Complex(double r, double i) {
             real =r;
             img =i;
        }
};
Complex  constructComplex(double r, double i) {
    return Complex(r,i);
 }

Complex add(Complex c1 ,Complex c2)  {
    return Complex(c1.real + c2.real, c1.img + c2.img);
}
Complex sub(Complex c1,Complex c2) {
    return Complex(c1.real - c2.real, c1.img - c2.img);
}
Complex mul(Complex c1,Complex c2) {
    return Complex(((c1.real*c2.real)-(c1.img*c2.img)),((c1.real*c2.img)+(c1.img*c2.real)));
}
Complex conjugate(Complex c) {
    return Complex(c.real , -1*c.img);
}
double printPolarForm(Complex c){
    double modulus = sqrt(c.real*c.real + c.img*c.img);
    double phase =(180/3.14)* atan2(c.img,c.real);
    cout<<modulus<<"e^"<<"(i"<<phase<<")";
}
int main(){
    cout << fixed << setprecision(2);
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Complex c = constructComplex(x1, y1);
    Complex c2 = constructComplex(x2, y2);
    Complex c3 = conjugate(c);
    cout << c3.real << ' ' << c3.img << '\n';
    Complex c4 = add(c, c2);
    cout << c4.real << ' ' << c4.img << '\n';
    Complex c5 = sub(c, c2);
    cout << c5.real << ' ' << c5.img << '\n';
    Complex c6 = mul(c, c2);
    cout << c6.real << ' ' << c6.img << '\n';
    printPolarForm(c);
    return 0;
}