#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Shape {
public:
	virtual void print() const = 0;
	virtual float getTotalArea() const = 0;
};

class Point {
	const int x, y;
public:
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	int getX() const {
		return x;
	}
	int getY() const{
		return y;
	}
};

class Rectangle : public Shape {
	const Point bottomLeft, topLeft, bottomRight, topRight;
public:
	Rectangle(Point _bottomLeft, Point _topLeft, Point _bottomRight, Point _topRight):
		bottomLeft(_bottomLeft), topLeft(_topLeft), bottomRight(_bottomRight), topRight(_topRight) {}
	void print() const {
		cout << "Rectangle: ";
		cout << "(" << bottomLeft.getX() << ',' << bottomLeft.getY() << ")";
		cout << "(" << topLeft.getX() << ',' << topLeft.getY() << ")";
		cout << "(" << bottomRight.getX() << ',' << bottomRight.getY() << ")";
		cout << "(" << topRight.getX() << ',' << topRight.getY() << ")" << endl;
	}
	float getTotalArea() const {
		float temp, temp1, temp2;
		int x1, y1, x2, y2, x3, y3, x4, y4;
		x1 = bottomLeft.getX(); y1 = bottomLeft.getY();
		x2 = topLeft.getX(); y2 = topLeft.getY();
		x3 = bottomRight.getX(); y3 = bottomRight.getY();
		x4 = topRight.getX(); y4 = topRight.getY();

		temp1 = (float)fabs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) / 2;
		temp2 = (float)fabs((x2 - x1)*(y4 - y1) - (x4 - x1)*(y2 - y1)) / 2;
		temp = temp1 + temp2;

		return temp;
	}
};

class Triangle : public Shape {
	Point bottomLeft, bottomRight, top;
public:
	Triangle(Point _bottomLeft, Point _bottomRight, Point _top):
		bottomLeft(_bottomLeft), bottomRight(_bottomRight), top(_top) {}
	void print() const {
		cout << "Triangle: ";
		cout << "(" << bottomLeft.getX() << ',' << bottomLeft.getY() << ")";
		cout << "(" << bottomRight.getX() << ',' << bottomRight.getY() << ")";
		cout << "(" << top.getX() << ',' << top.getY() << ")" << endl;
	}
	float getTotalArea() const {
		float temp;
		int x1, y1, x2, y2, x3, y3;
		x1 = bottomLeft.getX(); y1 = bottomLeft.getY();
		x2 = bottomRight.getX(); y2 = bottomRight.getY();
		x3 = top.getX(); y3 = top.getY();

		temp = (float)fabs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) / 2;
		return temp;
	}
};

class ShapeList : public Shape {
	vector <Shape*> polygon;
public:
	ShapeList(){}
	void addShape(Shape* _polygon) { polygon.push_back(_polygon); }
	void print() const {
		for (int i = 0; i < polygon.size(); i++) {
			polygon[i]->print();
		}
	}
	float getTotalArea() const {
		float sum = 0;
		for (int i = 0; i < polygon.size(); i++) {
			sum += polygon[i]->getTotalArea();
		}
		return sum;
	}
};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);
	Shape* r = new Rectangle(p1, p2, p3, p4);
	Shape* t = new Triangle(p1, p2, p3);
	ShapeList list;
	list.addShape(r);
	list.addShape(t);
	list.print();
	cout << list.getTotalArea() << endl;
}
