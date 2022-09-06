#include <iostream>
#define PI 3.1415926

using namespace std;

class Circle
{
private:
    int radius;
    static int count;

public:
    Circle(int radius);
    int getRadius();
    void setRadisu(int radius);
    static int getCount();
    double getPerimeter();
    double getArea();
    void print();
};

int Circle::count = 0;
Circle::Circle(int radius) : radius(radius)
{
    count++;
}
int Circle::getRadius()
{
    return this->radius;
}
void Circle::setRadisu(int radisu)
{
    this->radius = radisu;
}
int Circle::getCount()
{
    return count;
}
double Circle::getPerimeter()
{
    return 2 * PI * this->radius;
}
double Circle::getArea()
{
    return PI * this->radius * this->radius;
}
void Circle::print()
{
    printf("Circle { Area=%-10.2f, Perimeter=%-10.2f, Radius=%-5.d }\n", this->getArea(), this->getPerimeter(), this->radius);
}

int main()
{
    Circle a(1), b(3), c(6), d(10);

    a.print();
    b.print();
    c.print();
    d.print();
    cout << "Circle is: " << Circle::getCount() << endl;
}