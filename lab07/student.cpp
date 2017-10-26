#include <iostream>
#include <string.h>

using namespace std;

class student {
    char *sisiId;//оюутны дугаар(private тэмдэгтийн цуваа хадгалах хаяган хувьсагч)
    double GPA;//голч (private)
public:
    student();//анхдагч байгуулагч: нэр, дугаарт санах ой нөөцөлж хоосон утга онооно, курсэд 1 гэсэн утга онооно.
    student(char[], char[], int);//параметертэй байгуулагч: 3 гишүүн өгөгдөлд параметерээр утга авч онооно
    char *name;//нэр (public тэмдэгтийн цуваа хадгалах хаяган хувьсагч),
    int year;//курс (public)
    //гишүүн өгөгдөл тус бүрийн утгыг буцаах, утга оноох get, set функцууд
    //set
    void set_all(char[], char[], int, double);
    void set_name(char[]);
    void set_sisiId(char[]);
    void set_year(int);
    void set_gpa(double);
    //get
    char* get_name();
    char* get_sisiId();
    int get_year();
    double get_gpa();

    void stdcopy(student &);//хуулагч байгуулагч: өөр объектийг хуулж үүснэ. ингэхдээ хаяган хувьсагч дээр гардаг асуудлыг бодолцох хэрэгтэй

    bool greatThan(student &);//оюутныг курсээр нь харьцуулах (bool greatThan(student &), bool lessThan(student &), bool isEqual(student &))
    bool lessThan(student &);
    bool isEqual(student &);
    bool before(student &);//оюутны нэрийг харьцуулах (bool before(student &), bool after(student &))
    bool after(student &);
    ~student();//устгагч функц: нөөцөлсөн санах ойг устгана.
};
student::student()//анхдагч байгуулагч: нэр, дугаарт санах ой нөөцөлж хоосон утга онооно, курсэд 1 гэсэн утга онооно.
{
    int year = 1;
    double GPA = 0.0;
    char *name="";
    char *id="";
}
student::student(char *n , char *id, int year_){//параметертэй байгуулагч: 3 гишүүн өгөгдөлд параметерээр утга авч онооно
    name = new char(sizeof(n+1));
    sisiId = new char(sizeof(id+1));
    strcpy(name,n);
    strcpy(sisiId,id);
    year = year_;
}

void student::set_all(char *n, char *id, int year_, double gpa_){
    set_name(n);
    set_sisiId(id);
    set_year(year_);
    set_gpa(gpa_);
}
void student::set_name(char *n){
    if(name!=NULL)
        delete []name;
    name = new char(sizeof(n+1));
    strcpy(name,n);
}
void student::set_sisiId(char *id){
    sisiId = new char(sizeof(id+1));
    strcpy(sisiId,id);
}
void student::set_year(int a){
    year = a;
}
void student::set_gpa(double a){
    GPA = a;
}
char* student::get_name(){
    return name;
}
char* student::get_sisiId(){
    return sisiId;
}
int student::get_year(){
    return year;
}
double student::get_gpa(){
    return GPA;
}

void student::stdcopy(student &s){//хуулагч байгуулагч: өөр объектийг хуулж үүснэ. ингэхдээ хаяган хувьсагч дээр гардаг асуудлыг бодолцох хэрэгтэй
    name = new char(sizeof(s.get_name())+1);
    strcpy(name,s.get_name());
    sisiId = new char(sizeof(s.get_sisiId())+1);
    strcpy(sisiId,s.get_sisiId());
    year = s.get_year();
    GPA = s.get_gpa();
}

bool student::greatThan(student &s){
    if(year>s.get_year())
        return true;
    else
        return false;
}
bool student::lessThan(student &s){
    return !greatThan(s);
}
bool student::isEqual(student &s){
    return year==s.get_year();
}
bool student::after(student &s){
    if(strcmp(name,s.get_name())>0)
        return true;
    else
        return false;
}
bool student::before(student &s){
    return !after(s);
}

student::~student(){
    delete []name;
    delete []sisiId;

}
void sort_student_name(student[], int);
void sort_student_year(student[], int);

int main(){
    student s[10] = {//олон оюутан үүсгэж объектон хүснэгтэд хадгал.
        student("A","15b1seas1931",2),
        student("B","14b1seas1931",3),
        student("B","15b1seas1932",2),
        student("E","14b1seas1931",3),
        student("T","13b1seas1931",4),
        student("A","15b1seas1931",1),
        student("B","15b1seas1931",2),
        student("V","13b1seas1931",4),
        student("C","14b1seas1931",3),
        student("W","13b1seas1931",4)
    };

    cout << "#\t" << "Name\t" << "sisiId\t\t" << "year\t" << "GPA" << endl;
    for(int i=0; i<10; i++){
        cout << i << ":\t" << s[i].get_name() << "\t" << s[i].get_sisiId() << "\t" << s[i].get_year() << "\t" << s[i].get_gpa() << endl;
    }
    cout << endl << endl << "\t********** Sort Name **********" << endl;
    sort_student_name(s,10);//хүснэгт дэх объектуудыг нэрээр нь эрэмбэл.
    for(int i=0; i<10; i++){
        cout << i << ":\t" << s[i].get_name() << "\t" << s[i].get_sisiId() << "\t" << s[i].get_year() << "\t" << s[i].get_gpa() << endl;
    }
    cout << endl << endl << "\t********** Sort year **********" << endl;
    sort_student_year(s,10);//хүснэгт дэх объектуудыг курсээр нь эрэмбэл.
    for(int i=0; i<10; i++){
        cout << i << ":\t" << s[i].get_name() << "\t" << s[i].get_sisiId() << "\t" << s[i].get_year() << "\t" << s[i].get_gpa() << endl;
    }
    return 0;
}

void sort_student_name(student s[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(s[i].after(s[j])){
                student temp;
                temp.stdcopy(s[i]);
                s[i].stdcopy(s[j]);
                s[j].stdcopy(temp);
            }
        }
    }
}

void sort_student_year(student s[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(s[i].greatThan(s[j])){
                student temp;
                temp.stdcopy(s[i]);
                s[i].stdcopy(s[j]);
                s[j].stdcopy(temp);
            }
            else if(s[i].isEqual(s[j])){
                if(s[i].after(s[j])){
                    student temp;
                    temp.stdcopy(s[i]);
                    s[i].stdcopy(s[j]);
                    s[j].stdcopy(temp);
                }
            }
        }
    }
}
