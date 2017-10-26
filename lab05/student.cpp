#include<iostream>
#include<stdlib.h>
#include<string.h>
#define SIZE_OF_ARRAY 4
using namespace std;

class Student//Klass todorhoiloh
{
private:
    string sisiID;
    double GPA;
public:
    string name;
    int year;
    //classin gishuun ugugdul set, get metoduud
    void setSisiId(string id);
    string getSisiId();
    void setName(string n);
    string getName();
    void setGPA(double g);
    double getGPA();
    void setYear(int y);
    int getYear();
    //bool metoduud
    bool yearGreaterThan(Student &person2);//ehnii oruulsan hunii jil iluu baival true butsaana
    bool yearLessThan(Student &person2);//hoerdoh oruulsan hunii jil iluu baival true butsaana
    bool before(Student &person2);//ehnii oruulsan hunii ner iluu baival true butsaana
    bool after(Student &person2);//hoerdoh oruulsan hunii ner iluu baival true butsaana


};
void Student::setSisiId(string id)
{
    sisiID = id;
}
string Student::getSisiId()
{
    return sisiID;
}
void Student::setName(string n)
{
    name = n;
}
string Student::getName()
{
    return name;
}
void Student::setGPA(double g)
{
    GPA = g;
}
double Student::getGPA()
{
    return GPA;
}
void Student::setYear(int y)
{
    year = y;
}
int Student::getYear()
{
    return year;
}
bool Student::yearGreaterThan(Student &person2)
{
    if(year>person2.year) return true;
    else return false;
}
bool Student::yearLessThan(Student &person2)
{
    !yearGreaterThan(person2);
}
bool Student::before(Student &person2)
{
    char *n1 = &name[0u];
    char *n2 = &person2.name[0u];
    if(strcmpi(n1,n2)<0)
    {
        free(n1);
        free(n2);
        return true;
    }
    else
    {
        free(n1);
        free(n2);
        return false;
    }
}
bool Student::after(Student &person2)
{
    return !before(person2);
}

void sortByName(Student a[], int size_);
void sortByYear(Student a[], int size_);
void printall(Student a[], int size_);

int main()
{
    Student computerScience[4];//ob'ektiin husnegt
    int i, y;
    double g;
    string id, n;

    for(i = 0; i < 4; i++)
    {
        cout << endl << i+1 << "student's ID: ";
        cin >> id;
        computerScience[i].setSisiId(id);

        cout << i+1 << "student's Name: ";
        cin >> n;
        computerScience[i].setName(n);

        cout << i+1 << "student's Year: ";
        cin >> y;
        computerScience[i].setYear(y);

        cout << i+1 << "student's GPA: ";
        cin >> g;
        computerScience[i].setGPA(g);

        cout << endl << "Done with " << i+1 << "'s information" << endl;
    }
    printall(computerScience, 4);
    sortByName(computerScience, 4);
    printall(computerScience, 4);


    sortByYear(computerScience, 4);
    printall(computerScience, 4);
}


void sortByName(Student a[], int size_)
{
    int i, j;
    for(i = 0; i < size_-1; i++)
    {
        for(j = 0; j < size_-1; j++)
        {
            if(a[i].before( a[j])) break;
            else if(a[i].after(a[j]))
            {
                string temp = a[i].getName();
                a[i].setName(a[j].getName());
                a[j].setName(temp);
            }
        }
    }
}
void sortByYear(Student a[], int size_)
{
    int i, j;
    for(i = 0; i < size_-1; i++)
    {
        for(j = 0; j < size_-1; j++)
        {
            if(a[i].yearGreaterThan(a[j])) break;
            else if(a[i].yearLessThan(a[j]))
            {
                int temp = a[i].getYear();
                a[i].setYear(a[j].getYear());
                a[j].setYear(temp);
            }
        }
    }
}
void printall(Student a[], int size_)
{
    for(int i=0; i<size_; i++)
    {
        cout << "id: " << a[i].getSisiId() << endl;
        cout << "GPA: " << a[i].getGPA() << endl;
        cout << "name: " << a[i].getName() << endl;
        cout << "year: " << a[i].getYear() << endl;
    }
}
