#include <iostream>
#include <math.h>
using namespace std;

class Triangle{
public:
    double hypotenuse_c;
    double cat_a;
    double cat_b;
    double angle_A1;
    double angle_A2;
    double angle_A2_tan;
    Triangle(double x, double y,double q,double e, double p, double k):hypotenuse_c(x),cat_a(y),cat_b(q),angle_A1(e),angle_A2(p),angle_A2_tan(k){ } 
    ~Triangle(){} 
    void print(); 
    Triangle operator+(Triangle z) 
    { 
    Triangle w(0,0,0,0,0,0); 
      w.hypotenuse_c = hypotenuse_c+cat_b+cat_a; 
      return w;
    }  
    Triangle operator*(Triangle z) 
    { 
        Triangle w(0,0,0,0,0,0); 
        w.cat_a = 0.5*cat_b*cat_a; 
        w.angle_A1 =cos(angle_A1)/sin(z.angle_A2);
        w.angle_A2 = sin(angle_A2);
        w.cat_b = cos(angle_A1);
        w.angle_A2_tan = tan(angle_A2);
     return w;
    } 
};

int main() {
    cout<<"laboratory work 6"<<endl;
    cout<<"executed NAKONECHNYY ADRIAN"<<endl;
  
    Triangle u(12,6,6,45,45,45),v(0,6,0,45,45,45),z(0,0,0,0,0,0); 
    z=u*v;
    z.print();
    z=u+v;
    z.print();
    return 0; 
} 
void Triangle::print() 
{
printf("%lf %lf %f %f %f %f\n", hypotenuse_c, cat_a, angle_A1, angle_A2, cat_b, angle_A2_tan);
 }