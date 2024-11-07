#include "Employee.h"
#include <iostream>
using namespace std;

int main() 
{
    Employee* employees = nullptr;
    int count = 0;
    bool running = true;

    while (running)
    {
        cout << "\nMenu:\n"
            << "1. Display all employees\n"
            << "2. Search by last name\n"
            << "3. Search by salary range\n"
            << "4. Sort by last name\n"
            << "5. Add employee\n"
            << "6. Delete employee\n"
            << "0. Exit\n"
            << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAllEmployees(employees, count);
            break;

        case 2:
            {
            string lastName;
            cout << "Enter last name to search: ";
            cin >> lastName;
            searchByLastName(employees, count, lastName);
            break;
        }

        case 3:            
            {
            double minSalary, maxSalary;
            cout << "Enter minimum salary: ";
            cin >> minSalary;
            cout << "Enter maximum salary: ";
            cin >> maxSalary;
            searchBySalaryRange(employees, count, minSalary, maxSalary);
            break;
        }

        case 4:
            sortByLastName(employees, count);
            cout << "Employees sorted by last name.\n";
            break;

        case 5:
            addEmployee(employees, count);
            break;

        case 6: 
            {
            string lastName;
            cout << "Enter last name to delete: ";
            cin >> lastName;
            deleteEmployee(employees, count, lastName);
            break;
        }

        case 0:
            running = false;
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    freeEmployees(employees, count);
    return 0;
}