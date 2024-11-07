#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

struct Employee 
{
    string lastName;
    string firstName;
    string phoneNumber;
    double salary;
};

void displayAllEmployees(const Employee* employees, int count);
void searchByLastName(const Employee* employees, int count, const string& lastName);
void searchBySalaryRange(const Employee* employees, int count, double minSalary, double maxSalary);
void sortByLastName(Employee* employees, int count);
void addEmployee(Employee*& employees, int& count);
void deleteEmployee(Employee*& employees, int& count, const string& lastName);
bool isValidPhoneNumber(const string& phone);
bool confirmDeletion();
void freeEmployees(Employee* employees, int count);

#endif
