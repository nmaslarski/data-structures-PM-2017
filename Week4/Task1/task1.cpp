#include <iostream>
#include <string.h>
using namespace std;
class Student{
    private:
        const int static MAX_NAME_SIZE= 20;
        double grade;
        char name[MAX_NAME_SIZE];
        int number;
    public:
        Student();
        void setGrade(double);
        void setName(char*);
        void setNumber(int);
        double getGrade() const;
        char* getName();
        int getNumber() const;
        bool operator>(const Student&) const;
        bool operator<(const Student&) const;
        bool operator==(const Student&) const;
        bool operator!=(const Student&) const;
        void read();
        ~Student();
};
Student::Student()
{  }
void Student::setGrade(double newGrade)
{
    grade = newGrade;
}
void Student::setName(char* newName)
{
    strcpy(name, newName);
}
void Student::setNumber(int newNumber)
{
    number = newNumber;
}
double Student::getGrade() const
{
    return grade;
}
char* Student::getName()
{
    return name;
}
int Student::getNumber() const
{
    return number;
}
bool Student::operator>(const Student& second) const
{
    if(grade>second.grade)
        {
            return true;
        }
    else
        {
            return false;
        }
}
bool Student::operator<(const Student& second) const
{
    if(grade<second.grade)
        {
            return true;
        }
    else
        {
            return false;
        }
}
bool Student::operator==(const Student& second) const
{
    if(grade==second.grade)
        {
            return true;
        }
    else
        {
            return false;
        }
}
bool Student::operator!=(const Student& second) const
{
    if(grade!=second.grade)
        {
            return true;
        }
    else
        {
            return false;
        }
}
void Student::read()
{
    cout<<"Name:"<<endl;
    cin>>name;
    cout<<"Number"<<endl;
    cin>>number;
    cout<<"Grade:"<<endl;
    cin>>grade;
}
Student::~Student() {}
int main()
{
    Student one;
    Student two;
    one.read();
    two.read();
    if(one>two)
    {
        cout<<one.getName()<<endl;
    }
    else
    {
        cout<<two.getName()<<endl;
    }
    return 0;
}
