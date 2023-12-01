#include <iostream>
#include <cmath>

// Definici�n de la clase Point
class Point {
public:
    // Constructor por omisi�n
    Point() : x(0), y(0) {}

    // Constructor con par�metros
    Point(int x, int y) : x(x), y(y) {}

    // M�todos para obtener las coordenadas x e y
    int getX() const { return x; }
    int getY() const { return y; }

private:
    // Coordenadas del punto
    int x, y;
};

// Definici�n de la clase Triangle
class Triangle {
public:
    // Constructor por omisi�n
    Triangle();

    // M�todos para obtener los v�rtices
    Point getVertex1() const { return vertex1; }
    Point getVertex2() const { return vertex2; }
    Point getVertex3() const { return vertex3; }

    // M�todos para calcular el per�metro y el �rea
    double perimeter() const;
    double area() const;

private:
    // V�rtices del tri�ngulo
    Point vertex1, vertex2, vertex3;
};

// Implementaci�n del constructor por omisi�n de la clase Triangle
Triangle::Triangle() : vertex1(0, 0), vertex2(50, 30), vertex3(25, 10) {}

// Implementaci�n del m�todo para calcular el per�metro del tri�ngulo
double Triangle::perimeter() const {
    double side1 = sqrt(pow(vertex2.getX() - vertex1.getX(), 2) + pow(vertex2.getY() - vertex1.getY(), 2));
    double side2 = sqrt(pow(vertex3.getX() - vertex2.getX(), 2) + pow(vertex3.getY() - vertex2.getY(), 2));
    double side3 = sqrt(pow(vertex1.getX() - vertex3.getX(), 2) + pow(vertex1.getY() - vertex3.getY(), 2));

    return side1 + side2 + side3;
}

// Implementaci�n del m�todo para calcular el �rea del tri�ngulo utilizando la f�rmula de Her�n
double Triangle::area() const {
    double side1 = sqrt(pow(vertex2.getX() - vertex1.getX(), 2) + pow(vertex2.getY() - vertex1.getY(), 2));
    double side2 = sqrt(pow(vertex3.getX() - vertex2.getX(), 2) + pow(vertex3.getY() - vertex2.getY(), 2));
    double side3 = sqrt(pow(vertex1.getX() - vertex3.getX(), 2) + pow(vertex1.getY() - vertex3.getY(), 2));

    double semiperimeter = perimeter() / 2;

    return sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));
}

int main() {
    // Crear un objeto de tipo Triangle
    Triangle myTriangle;

    // Mostrar los v�rtices del tri�ngulo
    std::cout << "V�rtice 1: (" << myTriangle.getVertex1().getX() << ", " << myTriangle.getVertex1().getY() << ")\n";
    std::cout << "V�rtice 2: (" << myTriangle.getVertex2().getX() << ", " << myTriangle.getVertex2().getY() << ")\n";
    std::cout << "V�rtice 3: (" << myTriangle.getVertex3().getX() << ", " << myTriangle.getVertex3().getY() << ")\n";

    // Calcular y mostrar el per�metro y el �rea del tri�ngulo
    std::cout << "Per�metro: " << myTriangle.perimeter() << std::endl;
    std::cout << "�rea: " << myTriangle.area() << std::endl;

    return 0;
}

