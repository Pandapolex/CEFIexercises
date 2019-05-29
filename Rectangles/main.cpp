#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

typedef struct Point{
    float x;
    float y;
}Point_t;

class Rectangle {
private:
    Point_t p0;
    Point_t p1;
    float height;
    float width;
    float centerX;
    float centerY;
public:
    void setP0(Point_t p) {
        this->p0.x = p.x;
        this->p0.y = p.y;
    }
    void setP1(Point_t p) {
        this->p1.x = p.x;
        this->p1.y = p.y;
    }
    Point_t getP0() {
        return this->p0;
    }
    Point_t getP1() {
        return this->p1;
    }

    Rectangle() {
        p0 = {0,0};
        p1 = {0,0};
        height = 0;
        width = 0;
        centerX = 0;
        centerY = 0;
    }
    Rectangle(Point_t p0, Point_t p1) {
        setP0(p0);
        setP1(p1);
        setWidth();
        setHeigth();
        setCenterX();
        setCenterY();
    }
    ~Rectangle() {
        std::cout << "Rectangle terminated!" << std::endl;
    }
    void setWidth () {
        width = this->getP1().x - this->getP0().x;
    }
    void setHeigth () {
        height = this->getP1().y - this->getP0().y;
    }
    float getWidth() {
        return width;
    }
    float getHeight() {
        return height;
    }
    float getArea() {
        return getWidth()*getHeight();
    }
    void setCenterX(){
        centerX = (this->getP1().x - this->getP0().x)/2;
    };
    void setCenterY() {
        centerY = (this->getP1().y - this->getP0().y)/2;
    };
    float getCenterX() {
            return this->centerX;
    };
    float getCenterY() {
            return this->centerY;
    };
};

/*
* @param xa1       left x coordinate   A
* @param ya1       top y coordinate    A
* @param xa2       right x coordinate  A
* @param ya2       bottom y coordinate A
* @param xb1       left x coordinate   B
* @param yb1       top y coordinate    B
* @param xb2       right x coordinate  B
* @param yb2       bottom y coordinate B
* @return          Total area without the extra intersection area.
*/

float mostlyIntersects(float xa1, float ya1, float xa2, float ya2, float xb1, float yb1, float xb2, float yb2) {
    float iLeft = max(xa1, xb1);
    float iRight = min(xa2, xb2);
    float iTop = max(ya1, yb1);
    float iBottom = min(ya2, yb2);

    float si = max((float)0, abs(iRight - iLeft)) * max((float)0, abs(iBottom - iTop));
    float sa = (xa2 - xa1) * (ya2 - ya1);
    float sb = (xb2 - xb1) * (yb2 - yb1);

    cout << "si = " << si << endl;
    cout << "sa = " << sa << endl;
    cout << "sb = " << sb << endl;

    return abs(sa + sb - si);
}

int main() {

    auto rect1= new Rectangle({3,4},{12,10});
    auto rect2= new Rectangle({7,6},{14,15});

    float area = rect1->getArea();

    std::cout << "Area of rectangle 1 is: " << area << std::endl;

    area = rect2->getArea();

    std::cout << "Area of rectangle 2 is: " << area << std::endl;


    if  (abs(rect1->getCenterX() - rect2->getCenterX()) <
        (abs(rect1->getWidth()   + rect2->getWidth()) / 2) &&
        (abs(rect1->getCenterY() - rect2->getCenterY()) <
        (abs(rect1->getHeight()  + rect2->getHeight()) / 2))) {
        cout << "They collides!" << endl;
    } else {
        cout << "They not collides" << endl;
    }

    //area = mostlyIntersects(rect1->getP0().x, rect1->getP1().y, rect1->getP1().x, rect1->getP0().y, rect2->getP0().x, rect2->getP1().y, rect2->getP1().x, rect2->getP0().y);

    cout << "Area totale è " << area << endl;
    rect1->~Rectangle();
    rect2->~Rectangle();

    return 0;
}