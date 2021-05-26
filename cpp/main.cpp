#include <iostream>
#include <vector>
#include <cmath>


class Figure {
public:
    virtual double get_area()=0;
};

class Circle: public Figure {
    double radius;
    std::pair<double, double> center;
public:
    Circle(double, std::pair<double, double>);
    virtual double get_area() override;

};

class Triangle: public Figure {
    std::pair<double, double> A;
    std::pair<double, double> B;
    std::pair<double, double> C;
public:
    Triangle(std::pair<double, double>, std::pair<double, double>, std::pair<double, double>);
    virtual double get_area() override;
};

class Rectangle: public Figure {
    std::pair<double, double> A;
    std::pair<double, double> B;
    std::pair<double, double> C;
public:
    Rectangle(std::pair<double, double>, std::pair<double, double>, std::pair<double, double>);
    virtual double get_area() override;
};

Circle::Circle(double R, std::pair<double, double> cen) {
    radius = R;
    center = cen;
}

double Circle::get_area() {
    return M_PI * std::pow(radius, 2);
}

Triangle::Triangle(std::pair<double, double> a, std::pair<double, double> b, std::pair<double, double> c) {
    A = a;
    B = b;
    C = c;
}

double Triangle::get_area() {
    double S_par = std::abs((B.first - A.first)*(C.second - A.second) - (B.second - A.second)* (C.first - A.first));
    return 0.5 * S_par;
}

Rectangle::Rectangle(std::pair<double, double> a, std::pair<double, double> b, std::pair<double, double> c) {
    A = a;
    B = b;
    C = c;
}

double Rectangle::get_area() {
    double S = std::abs((B.first - A.first)*(C.second - A.second) - (B.second - A.second)* (C.first - A.first));
    return S;
}

int main() {
    std::cout << "Circle, Triangle or Rectangle" << std::endl;
    std::string type;
    std::cin >> type;

    if (type == "Circle") {
        std::cout << "Radius: ";
        double radius;
        std::cin >> radius;
        std::cout << "Center coordinates: ";
        double x_0;
        double y_0;
        std::cin >> x_0 >> y_0;
        Circle circle = Circle(radius, std::pair<double, double>(x_0, y_0));
        std::cout << "Area: " << circle.get_area() << std::endl;
    }
    else if (type == "Triangle") {
        std::cout << "First point coordinates: ";
        double x_0;
        double y_0;
        std::cin >> x_0 >> y_0;
        std::cout << "Second point coordinates: ";
        double x_1;
        double y_1;
        std::cin >> x_1 >> y_1;
        std::cout << "Third point coordinates: ";
        double x_2;
        double y_2;
        std::cin >> x_2 >> y_2;
        Triangle triangle = Triangle(std::pair<double, double>(x_0, y_0), std::pair<double, double>(x_1, y_1), std::pair<double, double>(x_2, y_2));
        std::cout << "Area: " << triangle.get_area() << std::endl;
    }
    else {
        std::cout << "First point coordinates: ";
        double x_0;
        double y_0;
        std::cin >> x_0 >> y_0;
        std::cout << "Second point coordinates: ";
        double x_1;
        double y_1;
        std::cin >> x_1 >> y_1;
        std::cout << "Third point coordinates: ";
        double x_2;
        double y_2;
        std::cin >> x_2 >> y_2;
        Rectangle rectangle = Rectangle(std::pair<double, double>(x_0, y_0), std::pair<double, double>(x_1, y_1), std::pair<double, double>(x_2, y_2));
        std::cout << "Area: " << rectangle.get_area() << std::endl;
    }
    return 0;
}
