#include<iostream>
using namespace std;

class Shape {
public:
	virtual double area() = 0;
};

class Rectangle : public Shape {
	double length;
	double width;
public:
	Rectangle(double l, double w) :length(l), width(w) {}
	double area()override {
		return length* width;
	}
};
class Circle : public Shape {
	double radius;
public:
	Circle(double r):radius(r){}
	double area()override {
		return 3.14 * (radius * radius);
	}
};

int main() {
	cout << "______Area Calculator______" << endl << endl;
	
	int choice;
	do {
		cout << "1. Area of Rectangle" << endl;
		cout << "2. Area of Circle" << endl;
		cout << "0. Exit" << endl;
		cout << "Your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			double l, w;
			cout << "Enter Length of rectangle: ";
			cin >> l;
			cout << "Enter width of rectangle: ";
			cin >> w;
			Shape* s1 = new Rectangle(l, w);
			cout << "Area of Rectangle: " << s1->area() << endl<<endl;
			break;
		}

		case 2:
		{
			double r;
			cout << "Enter Radius of Circle: ";
			cin >> r;
			Shape* s2 = new Circle(r);
			cout << "Area of Circle: " << s2->area() << endl << endl;
			break;
		}
		default:
			cout << "Invalid choice. Please try again." << endl<<endl;
		}

	} while (choice != 0);

	return 0;
}