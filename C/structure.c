#include<stdio.h>
#include<string.h>

struct employee{
    char name[50];
    int age;
    float salary;
};

int main() {
    struct employee emp[5];
    strcpy(emp[0].name, "sumit bhor");
    emp[0].age = 30;
    emp[0].salary = 55000.50;

    strcpy(emp[1].name, "rahul sharma");
    emp[1].age = 28;
    emp[1].salary = 48000.75;
    
    strcpy(emp[2].name, "anita verma");
    emp[2].age = 32;
    emp[2].salary = 62000.00;
    strcpy(emp[3].name, "sneha patel");
    emp[3].age = 26;    
    emp[3].salary = 45000.25;
    for (int i = 0; i < 5; i++)
    {
        printf("Employee %d Name: %s\n", i+1, emp[i].name);
        printf("Employee %d Age: %d\n", i+1, emp[i].age);
        printf("Employee %d Salary: %.2f\n", i+1, emp[i].salary);
    }
    
    return 0;
}
