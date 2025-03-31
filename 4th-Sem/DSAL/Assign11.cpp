#include <iostream>
#include <fstream>
using namespace std;

class student
{
    int roll_no;
    string name;
    char div;
    string add;
    public:
    student()
    {
        roll_no=0;
        name="";
        div=' ';
        add="";
    }
    student(int r,string n,char d,string a)
    {
        roll_no=r;
        name=n;
        div=d;
        add=a;
    }
    friend fstream &operator<<(fstream &out1,student &s);
    friend fstream &operator>>(fstream &in1,student &s);
    friend ostream &operator<<(ostream &out1,student &s);
    void display(fstream &in,student &s);
    void search(fstream &in,int x,student &s);
    void delete1(fstream &in,int x,student &s,int n);
};

fstream &operator<<(fstream &out1,student &s)
{
    out1<<s.roll_no<<" ";
    out1<<s.name<<" ";
    out1<<s.div<<" ";
    out1<<s.add<<" ";
    out1<<endl;
    return out1;
}

fstream &operator>>(fstream &in1,student &s)
{
    in1>>s.roll_no;
    in1>>s.name;
    in1>>s.div;
    in1>>s.add;
    return in1;
}

ostream &operator<<(ostream &out1,student &s)
{
    out1<<s.roll_no<<" ";
    out1<<s.name<<" ";
    out1<<s.div<<" ";
    out1<<s.add<<" ";
    cout<<endl;
    return out1;
}

void student::display(fstream &in,student &s)
{
    in.open("file1.txt",ios::in);
    while(1)
    {
        in>>s;
        if(in.eof())
        {
            break;
        }
        cout<<s;
    }
    in.close();
}

void student::search(fstream &in,int x,student &s)
{
    in.open("file1.txt",ios::in);
    while(1)
    {
        in>>s;
        if(s.roll_no==x)
        {
            cout<<s;
            break;
        }
        if(in.eof())
        {
            cout<<"Record not found"<<endl;
            return;
        }
    }
    in.close();
}

void student::delete1(fstream &in,int x,student &s,int n)
{
    student arr[n];
    in.open("file1.txt",ios::in);
    for(int i=0;i<n;i++)
    {
        in>>s;
        arr[i]=s;
    }
    in.close();
    in.open("file1.txt",ios::out | ios::trunc);
    for(int i=0;i<n;i++)
    {
        if(arr[i].roll_no==x)
        {
            continue;
        }
        else
        {
            in<<arr[i];
            cout<<arr[i];
        }
    }
    in.close();

}

int main()
{
    student s1;
    int c=1;
    int n;
    fstream myfile;
    while(c>0)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Add record to file"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        if(c==1)
        {
            myfile.open("file1.txt",ios::out);
            cout<<"Enter number of entries:";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                int roll_no;
                string name;
                char div;
                string add;
                cout<<"Enter roll_no:";
                cin>>roll_no;
                cout<<"Enter name:";
                cin>>name;
                cout<<"Enter division:";
                cin>>div;
                cout<<"Enter address:";
                cin>>add;
                student s(roll_no,name,div,add);
                myfile<<s;
            }
            myfile.close();
        }
        else if(c==2)
        {
            s1.display(myfile,s1);
        }
        else if(c==3)
        {
            int x;
            cout<<"Enter the roll no to search:";
            cin>>x;
            s1.search(myfile,x,s1);
        }
        else if(c==4)
        {
            int x;
            cout<<"Enter roll no to delete:";
            cin>>x;
            s1.delete1(myfile,x,s1,n);
        }
    }
    return 0;
}