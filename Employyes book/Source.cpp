#include "Employee.h"
#include <iostream>

using namespace std;

void displayAllEmployees(const Employee* employees, int count) 
{
    cout << "Employee List:\n";

    for (int i = 0; i < count; ++i) 
    {
        cout << "Last Name: " << employees[i].lastName << ", First Name: " << employees[i].firstName
            << ", Phone: " << employees[i].phoneNumber << ", Salary: " << employees[i].salary << endl;
    }
}

void searchByLastName(const Employee* employees, int count, const string& lastName)
{
    bool found = false;

    for (int i = 0; i < count; ++i)
    {
        if (employees[i].lastName == lastName)
        {
            cout << "Found employee: " << employees[i].firstName << " " << employees[i].lastName
                << ", Phone: " << employees[i].phoneNumber << ", Salary: " << employees[i].salary << endl;
            found = true;
        }
    }

    if (!found) cout << "No employee with last name " << lastName << " found.\n";
}

void searchBySalaryRange(const Employee* employees, int count, double minSalary, double maxSalary) 
{
    bool found = false;

    for (int i = 0; i < count; ++i)
    {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) 
        {
            cout << "Employee: " << employees[i].firstName << " " << employees[i].lastName
                << ", Phone: " << employees[i].phoneNumber << ", Salary: " << employees[i].salary << endl;
            found = true;
        }
    }

    if (!found) cout << "No employees found in the specified salary range.\n";
}

void sortByLastName(Employee* employees, int count) 
{
    for (int i = 0; i < count - 1; ++i) 
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (employees[i].lastName > employees[j].lastName) 
            {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void addEmployee(Employee*& employees, int& count)
{
    Employee* newEmployees = new Employee[count + 1];
    for (int i = 0; i < count; ++i) 
    {
        newEmployees[i] = employees[i];
    }

    cout << "Enter last name: ";
    cin >> newEmployees[count].lastName;
    cout << "Enter first name: ";
    cin >> newEmployees[count].firstName;
    cout << "Enter phone number: ";
    cin >> newEmployees[count].phoneNumber;
    cout << "Enter salary: ";
    cin >> newEmployees[count].salary;

    delete[] employees;
    employees = newEmployees;
    ++count;
}

void deleteEmployee(Employee*& employees, int& count, const string& lastName)
{
    int index = -1;
    for (int i = 0; i < count; ++i)
    {
        if (employees[i].lastName == lastName) 
        {
            index = i;
            break;
        }
    }

    if (index == -1) 
    {
        cout << "No employee with last name " << lastName << " found.\n";
        return;
    }

    if (confirmDeletion()) 
    
    {
        Employee* newEmployees = new Employee[count - 1];

        for (int i = 0, j = 0; i < count; ++i)
        {
            if (i != index)
            {
                newEmployees[j++] = employees[i];
            }
        }

        delete[] employees;
        employees = newEmployees;
        --count;
        cout << "Employee deleted.\n";
    }
}

bool isValidPhoneNumber(const string& phone) 
{
    return phone.size() == 13 && phone[0] == '(' && phone[4] == ')' && phone[8] == ' ';
}

bool confirmDeletion()
{
    char choice;
    cout << "Are you sure you want to delete the employee? (y/n): ";
    cin >> choice;
    return choice == 'y' || choice == 'Y';
}

void freeEmployees(Employee* employees, int count) 
{
    delete[] employees;
}