#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
private:

    string Name;
    int Id;
    int Salary;
    string Position;
    float workHours;
    bool workHoursSuccess;

public:
    void setName(string Name);
    string getName();

    void setId(int Id);
    int getId();

    void setSalary(int salary);
    int getSalary();

    void setPosition(string Position);
    string getPosition();

    bool setworkHours(float workHours, bool workHoursSuccess);
    float getworkHours();
    void printall();
};

void Employee::setName(string name)
{
    Name=name;
}

string Employee::getName()
{
    return Name;
}

void Employee::setId(int id)
{
    Id=id;
}

int Employee::getId()
{
    return Id;
}

void Employee::setSalary(int salary)
{
    if(salary < 0)
        Salary = 0;
    else
        Salary = salary;
    if (Position=="Manager")
        Salary *= 1.5;
}

int Employee::getSalary()
{
    return Salary;
}
void Employee::setworkHours(float workHours, bool workHoursSuccess)
{
    if(workHours<0 || workHours>24) workHoursSuccess = 0;
    else workHoursSuccess = 1;
}
float Employee::getworkHours()
{
    return workHoursSuccess;
}
void Employee::setPosition(string position)
{
    Position = position;
}
string Employee::getPosition()
{
    return Position;
}
void Employee::printall()
{
    cout <<  "Name: " <<  Name << endl;
    cout <<  "Id: " <<  Id << endl;
    cout <<  "Salary: " <<  Salary << endl;
    cout <<  "Name: " <<  Position << endl;
    cout <<  "Name: " <<  workHoursSuccess << endl;

}
int main()
{

    Employee a;
    string Name;
    int Id;
    int Salary;
    string Position;
    float workHours;
    bool workHoursSuccess;
    cout << "name, id, salary, position, work hours: ";
    cin >>Name >> Id >> Salary >> Position >> workHours;
    a.setName(Name);
    a.getName();

    a.setId(Id);
    a.getId();

    a.setworkHours(workHours, workHoursSuccess);
    a.getworkHours();

    a.setPosition(Position);
    a.getPosition();

    a.setSalary(Salary);
    a.getSalary();

    a.printall();

    return 0;


    return 0;
}
