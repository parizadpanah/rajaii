#include <iostream>
using namespace std;
class  Circle{
private:
    /* data */
    float radius;
public:
    Circle(float r){
        radius=r;
    };
    Circle();
    float getArea(){
        return (2*3.14*radius);
    };
    float getPerimeter(){
        return (radius*radius*3.14);
    };
};

int main(){
    float r;
    cin>>r;
    Circle circle1(r);
    cout<<circle1.getArea()<<'\n'<<circle1.getPerimeter();
    return 0;
}

