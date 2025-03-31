#include <iostream>
#include <string>
using namespace std;

class publication
{
public:
    string title;
    float price;
    void getdata()
    {
        try
        {
            cout << "Enter Title: ";
            cin >> title;
            cout << "Enter price: ";
            cin >> price;
            if (price <= 0)
                throw 0;
        }
        catch (int num)
        {
            price = 0;
            cout << "Price cannot be negative" << endl;
        }
    }
};

class book : virtual public publication
{
public:
    int pagecnt = 0;
    void getpage()
    {
        cout << "Enter number of pages: ";
        cin >> pagecnt;
    }
};

class tape : virtual public publication
{
public:
    float time;
    void gettime()
    {
        cout << "Enter playing time: ";
        cin >> time;
    }
};

class display : public tape, public book
{
public:
    void show()
    {
        cout << endl;
        cout << "Title=" << title << endl;
        cout << "Price=" << price << endl;
        cout << "Number of pages=" << pagecnt << endl;
        cout << "Playing time=" << time << endl;
    }
};

int main()
{
    display ob;
    ob.getdata();
    ob.getpage();
    ob.gettime();
    ob.show();
    return 0;
}