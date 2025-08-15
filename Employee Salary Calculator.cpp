#include<iostream>
using namespace std;

class Employee {
public:
	virtual double calculateSalary() = 0;
};

class FullTimeEmployee : public Employee{
	double salary;
public:
	FullTimeEmployee(double s):salary(s){}
	double calculateSalary()override {
		return salary;
	}
};

class PartTimeEmployee : public Employee {
	double hourlyRate;
	double hoursWorked;
public:
	PartTimeEmployee(double hR, double hW) :hourlyRate(hR), hoursWorked(hW) {}
	double calculateSalary()override {
		return hourlyRate*hoursWorked;
	}
};

int main() {

	Employee* e1 = new PartTimeEmployee(20, 9);
	Employee* e2 = new FullTimeEmployee(320);

	cout << "Part time employee Salary: $"<<e1->calculateSalary()<<endl;
	cout << "Full time employee Salary: $"<<e2->calculateSalary()<<endl;
	return 0;
}