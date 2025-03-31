#include<bits/stdc++.h>
using namespace std;

class item
{
    public:
    string name;
    int quant;
    int cost;
    int code;
    bool operator==(const item& i1)
    {
        if(code == i1.code)
            return 1;
        return 0 ;
    }
    bool operator<(const item& i1)
    {
        if(code<i1.code)
            return 1;
        return 0;
    }
};  

vector<item>v;

bool compare(const item &i1, const item &i2)
{
    return i1.code<i2.code;
}

void insert()
{
    item i1;
    cout<<"Enter item name : "<<endl;
    cin>>i1.name;
    cout<<"Enter Item Quantity : "<<endl;
    cin>>i1.quant;
    cout<<"Enter Item Cost : "<<endl;
    cin>>i1.cost;
    cout<<"Enter Item Code : "<<endl;
    cin>>i1.code;
    v.push_back(i1);
}

void print(item &i1)
{
    cout<<"\n Item Name : "<<i1.name;
    cout<<"\n Item Quantity : "<<i1.quant;
    cout<<"\n Item Cost : "<<i1.cost;
    cout<<"\n Item Code : "<<i1.code;
    cout<<"\n";
}

void display()
{
    for_each(v.begin(),v.end(),print);
}

void search()
{
    vector<item>::iterator it;
    item i1;
    cout<<"Enter item code to be searched "<<endl;
    cin>>i1.code;
    it = find(v.begin(),v.end(),i1);
    if(it==v.end())
        cout<<"Not found"<<endl;
    else
    {
        cout<<"Found"<<endl;
        cout<<"Item Name : "<<it->name<<endl;
        cout<<"Item Quantity : "<<it->quant<<endl;
        cout<<"Item Cost : "<<it->cost<<endl;
        cout<<"Item Code : "<<it->code<<endl;
    }
}

int main()
{
    int ch;
    cout<<"Menu : \n 1.Insert Item \n 2.Search Item \n 3.Sort Items \n 4.Display Items "<<endl;
    do
    {
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;  
            case 3:
                sort(v.begin(),v.end(),compare);
                cout<<"\n Sorted on Item code : ";
                display();
                break;
            case 4:
                display();
                break;
            default:
                break;
        }
    }while(ch<5 && ch>0);
    return 0;
}