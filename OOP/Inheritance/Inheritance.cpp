
#include"libraries.h"
bool arePointsCollinear(double x1, double y1, double x2, double y2, double x3, double y3) {
    double area = 0.5 * abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
    return (area == 0);
}

bool arePointsOnSameLine(double x1, double y1, double x2, double y2, double x3, double y3) {
    return arePointsCollinear(x1, y1, x2, y2, x3, y3);
}

bool isPointsOnSameLine(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    bool areFirstThreeCollinear = arePointsOnSameLine(x1, y1, x2, y2, x3, y3);
    bool areFirstAndLastCollinear = arePointsOnSameLine(x1, y1, x2, y2, x4, y4);
    return areFirstThreeCollinear && areFirstAndLastCollinear;
}

bool isTrapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
  
    if (!isPointsOnSameLine(x1, y1, x2, y2, x3, y3, x4, y4)) {
        double slope1 = (x2 - x1 != 0) ? (y2 - y1) / (x2 - x1) : INFINITY;
        double slope2 = (x3 - x2 != 0) ? (y3 - y2) / (x3 - x2) : INFINITY;
        double slope3 = (x4 - x3 != 0) ? (y4 - y3) / (x4 - x3) : INFINITY;
        double slope4 = (x1 - x4 != 0) ? (y1 - y4) / (x1 - x4) : INFINITY;

        if (slope1 == slope3 || slope2 == slope4) {
            return true;
        }
        else {
            return false;
        }
    }
    else return false;
}
bool isParallelogram(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    
    if (!isPointsOnSameLine(x1, y1, x2, y2, x3, y3, x4, y4)) {
    double slope1 = (x2 - x1 != 0) ? (y2 - y1) / (x2 - x1) : INFINITY;
    double slope2 = (x3 - x2 != 0) ? (y3 - y2) / (x3 - x2) : INFINITY;
    double slope3 = (x4 - x3 != 0) ? (y4 - y3) / (x4 - x3) : INFINITY;
    double slope4 = (x1 - x4 != 0) ? (y1 - y4) / (x1 - x4) : INFINITY;

   
    if (slope1 == slope3 && slope2 == slope4) {
        return true;
    }
    else if (slope1 == slope2 && slope3 == slope4) {
        return true;
    }
    else if (slope1 == slope4 && slope2 == slope3) {
        return true;
    }
    else {
        return false;
    }
    }
    else return false;
}



bool isRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {

    if (!isParallelogram(x1, y1, x2, y2, x3, y3, x4, y4)) {
        return false;
    }

    
    double diagonal1 = sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));
    double diagonal2 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    if (diagonal1 == diagonal2) {
        return true;
    }
    else {
        return false;
    }

}

bool isSquare(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {

    if (!isRectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
        return false;
    }

    double sideLength = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (sideLength == sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) &&
        sideLength == sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2)) &&
        sideLength == sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2))) {
        return true;
    }
    else {
        return false;
    }
}


Quadrilateral::Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
:x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4)
{}
Quadrilateral::~Quadrilateral(){};
void Quadrilateral::setPoints(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    this->x4 = x4;
    this->y4 = y4;
}

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : Quadrilateral(x1, y1, x2, y2, x3, y3, x4, y4)
{}

Trapezoid::~Trapezoid()
{}

double Trapezoid::getArea() const {
    double base1 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)); 
    double base2 = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2)); 
    double height = fabs(y2 - y1);
    return 0.5 * (base1 + base2) * height; 
}


string Trapezoid::getDescription() const
{
    return "Трапеция";
}


Parallelogram::Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : Quadrilateral(x1, y1, x2, y2, x3, y3, x4, y4)
{}

Parallelogram::~Parallelogram()
{}

double Parallelogram::getArea() const {
    double base = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)); 
    double height = fabs(y2 - y1); 
    return base * height; 
}

string Parallelogram::getDescription() const
{
    return "Параллелограмм";
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : Parallelogram(x1, y1, x2, y2, x3, y3, x4, y4)
{}

Rectangle::~Rectangle()
{}

double Rectangle::getArea() const
{
    return  sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) * sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
}

string Rectangle::getDescription() const
{
    return "Прямоугольник";
}


Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : Rectangle(x1, y1, x2, y2, x3, y3, x4, y4)
{}

Square::~Square()
{}

double Square::getArea() const
{
    return  pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

string Square::getDescription() const
{
    return "Квадрат";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 4;
    Quadrilateral* shapes[size];
   
    double x1, y1, x2, y2, x3, y3, x4, y4;
  
    cout << "Введите координаты трапеции (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    while (1) {
        if (!isTrapezoid(x1, y1, x2, y2, x3, y3, x4, y4)) {
            cout << "Ошибка: введенные координаты не образуют трапецию. Попробуйте еще раз." << endl;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        }
        else break;
    }
    shapes[0] = new Trapezoid(x1, y1, x2, y2, x3, y3, x4, y4);

    cout << "Введите координаты параллелограма (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    while (1) {
    if (!isParallelogram(x1, y1, x2, y2, x3, y3, x4, y4)){
        cout << "Ошибка: введенные координаты не образуют параллелограмм. Попробуйте еще раз." << endl;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    }
    else break;
}
    
    shapes[1] = new Parallelogram(x1, y1, x2, y2, x3, y3, x4, y4);

    cout << "Введите координаты прямоугольника (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        while (1) {
    if (!isRectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "Ошибка: введенные координаты не образуют прямоугольник. Попробуйте еще раз." << endl;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    }
    else break;
    }
    shapes[2] = new class Rectangle(x1, y1, x2, y2, x3, y3, x4, y4);

    cout << "Введите координаты квадрата (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    while (1) {
    if (!isSquare(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "Ошибка: введенные координаты не образуют квадрат. Попробуйте еще раз." << endl;
         cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    }
    else break;
    }
    shapes[3] = new Square(x1, y1, x2, y2, x3, y3, x4, y4);
    double maxArea = 0;
    Quadrilateral* maxShape = nullptr;
    for (int i = 0; i < size; i++) {
        double area = shapes[i]->getArea();
        cout <<shapes[i]->getDescription()<<" - " << shapes[i]->getArea() << endl;
        
        if (area > maxArea) {
            maxArea = area;
            maxShape = shapes[i];
        }
    }

    if (maxShape != nullptr) {
        cout << "Фигура " << maxShape->getDescription() << " имеет наибольшую площадь " << maxArea << endl;


       ofstream outFile("largest_shape.txt");
        outFile << "Фигура: " << maxShape->getDescription() << endl;
        outFile << "Площадь: " << maxArea << endl;
       
        outFile.close();
    }

 
    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }

    return 0;

}
//Введите координаты трапеции(x1 y1 x2 y2 x3 y3 x4 y4) : 0 0 1 4 3 4 8 0
//Введите координаты параллелограма(x1 y1 x2 y2 x3 y3 x4 y4) : 0 0 1 3 6 3 5 0
//Введите координаты прямоугольника(x1 y1 x2 y2 x3 y3 x4 y4) : 0 0 0 3 5 3 5 0
//Введите координаты квадрата(x1 y1 x2 y2 x3 y3 x4 y4) : 0 0 0 3 3 3 3 0
//Трапеция - 20
//Параллелограмм - 15
//Прямоугольник - 15
//Квадрат - 9
//Фигура Трапеция имеет наибольшую площадь 20