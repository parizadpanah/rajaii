#include <iostream>
#include <string>
#include <vector>
using namespace  std;
class Teacher
{
private:
    /* data */
    int id;
    static int counter_id;
    string fname;
    string lname;
    string degree_education;
    string status;
public:
    Teacher(string,string,string,string);
    ~Teacher();
    void Print();
};
int Teacher :: counter_id=0;

Teacher::Teacher(string f,string l,string de,string s)
{
    counter_id++;
    id=counter_id;
    fname=f;
    lname=l;
    degree_education=de;
    status=s;
}
void Teacher :: Print() 
{
    cout<<"name and family of the Teacher"<<fname<<" "<<lname;
}


class TrainingCourse
{
private:
    /* data */
    int startTime;
    int periodTime;
    Teacher* teacher;
    int capacity;
public:
    TrainingCourse(int,int,Teacher*,int);
    ~TrainingCourse();
    void Print_t() const;
};

TrainingCourse::TrainingCourse(int st,int pt,Teacher* t,int c)
{
    if(st>6 && st<22)
    {
       startTime=st;
    }
    if(pt>9 && pt <61)
    periodTime=pt;
    teacher=t;
    capacity=c;
}

TrainingCourse::~TrainingCourse()
{
}
void TrainingCourse::Print_t() const
{
    cout<<startTime<<"  "<<periodTime<<"  "<<capacity<<"  "<<teacher -> Print();
}


class AttendanceCourse : public TrainingCourse
{
private:
    /* data */
    int id;
    string building_name;
    int number_class;
public:
    AttendanceCourse (int id, string bn, int nc,string f,string l,string de,string s) : TrainingCourse(f,l,de,s)
    {
        this->id=id;
        building_name=bn;
        number_class=nc;
    }
    ~AttendanceCourse(){

    }
    void Print_a() const
    {
        cout<<id<<"  "<<building_name<<"  "<<number_class<<"  "<<Print_t();
    }
};
class VirtualCourse :public TrainingCourse
{
private:
    /* data */
    int id:
    string address;
    int password;

public:
    VirtualCourse(int id ,string ad,int pas ,string f,string l,string de,string s) : TrainingCourse(f,l,de,s)
    {
        this->id=id;
        address=ad;
        password=pas;
    }
    ~VirtualCourse(){

    }
    void Print_v() const
    {
        cout<<id<<"  "<<address<<"  "<<password<<"  "<<Print_t();
    }
};
//dar in coiiz class teacher rabete Aggregation ba class TrainingCourse darad va calass TrainingCourse parent do class AttendanceCourse va class VirtualCourse ast 

int main(){
    vector<Teacher>teacher{Teacher("pari","hoseini","arshad","rasmi"),Teacher("sima","alavi","lisans","rasmi"),Teacher("mobina","rashidi","lisans","hagotadris")};

}