#include <iostream>
#include <cmath>

// Definición de la clase Point
class Point {
public:
    // Constructor por omisión
    Point() : x(0), y(0) {}

    // Constructor con parámetros
    Point(int x, int y) : x(x), y(y) {}

    // Métodos para obtener las coordenadas x e y
    int getX() const { return x; }
    int getY() const { return y; }

private:
    // Coordenadas del punto
    int x, y;
};

// Definición de la clase Triangle
class Triangle {
public:
    // Constructor por omisión
    Triangle();

    // Métodos para obtener los vértices
    Point getVertex1() const { return vertex1; }
    Point getVertex2() const { return vertex2; }
    Point getVertex3() const { return vertex3; }

    // Métodos para calcular el perímetro y el área
    double perimeter() const;
    double area() const;

private:
    // Vértices del triángulo
    Point vertex1, vertex2, vertex3;
};

// Implementación del constructor por omisión de la clase Triangle
Triangle::Triangle() : vertex1(0, 0), vertex2(50, 30), vertex3(25, 10) {}

// Implementación del método para calcular el perímetro del triángulo
double Triangle::perimeter() const {
    double side1 = sqrt(pow(vertex2.getX() - vertex1.getX(), 2) + pow(vertex2.getY() - vertex1.getY(), 2));
    double side2 = sqrt(pow(vertex3.getX() - vertex2.getX(), 2) + pow(vertex3.getY() - vertex2.getY(), 2));
    double side3 = sqrt(pow(vertex1.getX() - vertex3.getX(), 2) + pow(vertex1.getY() - vertex3.getY(), 2));

    return side1 + side2 + side3;
}

// Implementación del método para calcular el área del triángulo utilizando la fórmula de Herón
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

    // Mostrar los vértices del triángulo
    std::cout << "Vértice 1: (" << myTriangle.getVertex1().getX() << ", " << myTriangle.getVertex1().getY() << ")\n";
    std::cout << "Vértice 2: (" << myTriangle.getVertex2().getX() << ", " << myTriangle.getVertex2().getY() << ")\n";
    std::cout << "Vértice 3: (" << myTriangle.getVertex3().getX() << ", " << myTriangle.getVertex3().getY() << ")\n";

    // Calcular y mostrar el perímetro y el área del triángulo
    std::cout << "Perímetro: " << myTriangle.perimeter() << std::endl;
    std::cout << "Área: " << myTriangle.area() << std::endl;

    return 0;
}

