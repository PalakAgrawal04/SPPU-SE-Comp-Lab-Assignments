#include <iostream>
#include <string>
using namespace std;

class person
{
private:
    string name, dob, blood, tele, addr, lic;
    static int cnt;

public:
    int cl, div, roll;
    person() // default constructor
    {

        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter DOB : ";
        cin >> dob;
        cout << "Enter blood group :";
        cin >> blood;
    }
    person(int cl, int div, int roll) // parameterized constructor
    {
        cout << "Normal constructor=" << endl;
        cout << "Class=" << cl << endl;
        cout << "Div=" << div << endl;
        cout << "Roll=" << roll << endl;
    }

    person(person &ob) // copy constructor and this pointer
    {
        this->cl = ob.cl;
        this->div = ob.div;
        this->roll = ob.roll;
    }

    static int getCount()
    {
        return cnt;
    }

    void getclass()
    {
        try
        {
            cout << "Enter class :";
            cin >> cl;
            if (cl <= 0)
                throw 0;
            cout << "Enter division :";
            cin >> div;
            if (div <= 0)
                throw 0;
            cout << "Enter roll number : ";
            cin >> roll;
            if (roll <= 0)
                throw 0;
        }
        catch (int num)
        {
            cout << "Invalid input" << endl;
        }
        cnt++;
    }
    void contact()
    {
        cout << "Enter telephone no:";
        cin >> tele;
        cout << "Enter your address:";
        cin >> addr;
        cout << "Enter license number:";
        cin >> lic;
    }
    friend class details; // friend class
};

class details
{
public:
    void show(person &p)
    {
        cout << "From friend class" << endl;
        cout << "Name=" << p.name << endl;
        cout << "Roll number= " << p.roll << endl;
        cout << "DOB=" << p.dob << endl;
    }
    ~details() // destructor
    {
        cout << "Destructor" << endl;
        cout << "Details saved successfully" << endl;
    }
};

int person::cnt= 0;

int main()
{
    // person ob;

    // ob.getclass();
    // ob.contact();
    // person ob2 = ob;
    // cout << "Details from copy constructor " << endl;
    // cout << "Class=" << ob2.cl << endl;
    // cout<<"Total Students : "<<person::getCount();
    // details obj;
    // obj.show(ob);
    // person normal(ob.cl, ob.div, ob.roll);
    // return 0;

    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    person *p = new person[n]; // Using array of person objects

    for (int i = 0; i < n; ++i)
    {
        cout<<"Enter more info of Student "<<i+1<<endl;
        p[i].getclass();
        p[i].contact();
    }

    cout << "Total Students: " << person::getCount() << endl;

    details obj;
    cout<<"Display "<<endl;
    for (int i = 0; i < n; ++i)
    {
        cout<<"Student "<<i+1<<endl;
        obj.show(p[i]);
    }

    delete[] p; // Release memory allocated with new[]

    return 0;
}
