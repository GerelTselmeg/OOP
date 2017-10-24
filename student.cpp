#include <iostream>
#include <string.h>

using namespace std;

class student
{
    char* sisiId;//оюутны дугаар(private тэмдэгтийн цуваа хадгалах хаяган хувьсагч)
    double GPA;//голч (private)
public:
    student();//анхдагч байгуулагч: нэр, дугаарт санах ой нөөцөлж хоосон утга онооно, курсэд 1 гэсэн утга онооно.
    student(char *n, char *id, int year_); //параметертэй байгуулагч: 3 гишүүн өгөгдөлд параметерээр утга авч онооно
    char* name;//нэр (public тэмдэгтийн цуваа хадгалах хаяган хувьсагч),
    int year;//курс (public)
    //гишүүн өгөгдөл тус бүрийн утгыг буцаах, утга оноох get, set функцууд
    //set
    void set_name(char[]);
    void set_sisiId(char[]);
    void set_year(int);
    void set_gpa(double);
    //get
    char* get_name();
    char* get_sisiId();
    int get_year();
    double get_gpa();

    void copy_(student &);//хуулагч байгуулагч: өөр объектийг хуулж үүснэ. ингэхдээ хаяган хувьсагч дээр гардаг асуудлыг бодолцох хэрэгтэй

    bool greatThan(student &);//оюутныг курсээр нь харьцуулах (bool greatThan(student &), bool lessThan(student &), bool isEqual(student &))
    bool lessThan(student &);
    bool isEqual(student &);
    bool before(student &);//оюутны нэрийг харьцуулах (bool before(student &), bool after(student &))
    bool after(student &);
    ~student();//устгагч функц: нөөцөлсөн санах ойг устгана.
};
student::student()//анхдагч байгуулагч: нэр, дугаарт санах ой нөөцөлж хоосон утга онооно, курсэд 1 гэсэн утга онооно.
{

    set_name("");
    set_sisiId("");
    set_year(1);
    set_gpa(0);

}
student::student(char *n, char *id, int year_)  //параметертэй байгуулагч: 3 гишүүн өгөгдөлд параметерээр утга авч онооно
{
    name = new char[strlen(n)+1];
    sisiId = new char[strlen(id)+1];
    set_name(n);
    set_sisiId(id);
    set_year(year_);

}
void student::set_name(char *n)
{
    if(name!=NULL)
        delete []name;
    name = new char[strlen(n)+1];
    strcpy(name,n);//strcmp
}
void student::set_sisiId(char *id)
{
    if(sisiId!=NULL)
        delete []sisiId;
    sisiId = new char[strlen(id)+1];
    strcpy(sisiId,id);
}
void student::set_year(int a)
{
    this->year = a;
}
void student::set_gpa(double a)
{
    this->GPA = a;
}
char* student::get_name()
{
    return name;
}
char* student::get_sisiId()
{
    return sisiId;
}
int student::get_year()
{
    return year;
}
double student::get_gpa()
{
    return GPA;
}

void student::copy_(student &s) //хуулагч байгуулагч: өөр объектийг хуулж үүснэ. ингэхдээ хаяган хувьсагч дээр гардаг асуудлыг бодолцох хэрэгтэй
{
    name = new char[strlen(s.get_name()+1)];
    sisiId = new char[strlen(s.get_sisiId()+1)];
    strcpy(name,s.get_name());
    strcpy(sisiId,s.get_sisiId());
    this->year = s.get_year();
    this->GPA = s.get_gpa();
}

bool student::greatThan(student &s)
{
    if(year>s.get_year())
        return true;
    else
        return false;
}
bool student::lessThan(student &s)
{
    return !greatThan(s);
}
bool student::isEqual(student &s)
{
    return year==s.get_year();
}
bool student::after(student &s)
{
    if(strcmp(name,s.get_name())>0)
        return true;
    else
        return false;
}
bool student::before(student &s)
{
    return !after(s);
}

student::~student()
{
    delete []name;
    delete []sisiId;

}
void sort_student_name(student[], int);
void sort_student_year(student[], int);
void printall(student[], int);

int main()
{
    student s[4] =  //олон оюутан үүсгэж объектон хүснэгтэд хадгал.
    {
        student("A","15b1seas1931",1),
        student("B","14b1seas1931",3),
        student("Z","15b1seas1932",2),
        student("C","14b1seas1931",3)
    };

    int n = sizeof(s) / sizeof( s[0] );
    printall(s, n);
    sort_student_name(s, n);
    printall(s, n);
    sort_student_year(s, n);
    printall(s, n);
    return 0;
}
void printall(student s[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << i+1 << ":\t" << s[i].get_name() << "\t" << s[i].get_sisiId() << "\t" << s[i].get_year() << "\t" << s[i].get_gpa() << endl;

    }
    cout << endl << endl << endl;
};
void sort_student_name(student s[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(s[i].after(s[j]))
            {
                student temp;
                temp.copy_(s[i]);
                s[i].copy_(s[j]);
                s[j].copy_(temp);
            }
        }
    }
}

void sort_student_year(student s[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(s[i].greatThan(s[j]))
            {
                student temp;
                temp.copy_(s[i]);
                s[i].copy_(s[j]);
                s[j].copy_(temp);
            }
        }
    }
}
