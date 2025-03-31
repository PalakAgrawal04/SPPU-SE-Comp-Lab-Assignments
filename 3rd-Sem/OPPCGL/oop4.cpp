#include<bits/stdc++.h>
using namespace std;

class Student
{
    string name;
    int r_no;
    public:
    void get()
    {
        cout<<"\n Name : ";
        cin.ignore();
        getline(cin,name);
        cout<<"\n Roll No. : ";
        cin>>r_no;
    }
    void display()
    {
        cout<<"\n Name : "<<name;
        cout<<"\n Roll No. : "<<r_no;
    }
};

int main(){
    Student s[10];
    fstream f;
    int n;

    f.open("student_detail.txt",ios::out);
    cout<<"Enter the no. of students : ";
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cout<<"Enter info of Student "<<i+1<<endl;
        s[i].get();
        f.write((char*)&s[i],sizeof s[i]);
    }
    f.close();

    f.open("student_detail.txt",ios::in);
    cout<<"\n Info is as follow : "<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<"\n Student "<<i+1<<endl;
        f.read((char*)&s[i],sizeof s[i]);
        s[i].display();
    }
    f.close();

    return 0;
}