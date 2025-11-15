#include<iostream>
using namespace std;

class Employee {
public:
    int id;
    string name;
    float salary;
};

int main() {
    Employee emp1;

    emp1.id = 101;
    emp1.name = "sumit Bhor";
    emp1.salary = 55000.50;

    cout << "employee iD: " << emp1.id << endl;
    cout << "employee name: " << emp1.name << endl;
    cout << "Employee salary: " << emp1.salary << endl;

    return 0;
}