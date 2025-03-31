#include <iostream>
#include <string>
using namespace std;

class Entry {
public:
    string name;
    long long phoneNumber;

    Entry() {
        name = "";
        phoneNumber = -1;
    }

    Entry(string _name, long long _phoneNumber) {
        name = _name;
        phoneNumber = _phoneNumber;
    }
};

class hash{
    Entry ht[10];
    int size = 10;
    public:
    hash(){
        for(int i=0;i<size;i++)
            ht[i]=Entry();
    }
    void insertwithout(string name,long long phoneNumber){
        int hkey = phoneNumber%size;
        if(ht[hkey].phoneNumber == -1)
            ht[hkey] = Entry(name,phoneNumber);
        else{
            while(ht[hkey].phoneNumber != -1)
            {
                hkey = (hkey + 1) % size;
            }
            ht[hkey] = Entry(name,phoneNumber);
        }
    }

    void insertwithrep(string name, long long phoneNumber)
    {
        int hkey = phoneNumber%size;
        if(ht[hkey].phoneNumber == -1)
            ht[hkey] = Entry(name,phoneNumber);
        else{
            if((ht[hkey].phoneNumber )%10 == hkey)
            {
                while(ht[hkey].phoneNumber != -1)
                hkey = (hkey + 1) % size;
                ht[hkey] = Entry(name,phoneNumber);
            }
            else{
                Entry temp = ht[hkey];
                ht[hkey] = Entry(name, phoneNumber);

            while(ht[hkey].phoneNumber != -1)
            {
                hkey = (hkey + 1) % size;
            }
            ht[hkey] = temp;
            }
            
        }
    }
    void deletehash(long long phoneNumber){
        int hkey = phoneNumber%size;
        if(ht[hkey].phoneNumber == phoneNumber)
            {
                ht[hkey]= Entry();
                return;
            }
        else{
            while(ht[hkey].phoneNumber != phoneNumber && ht[hkey].phoneNumber != -1)
                hkey = (hkey+1)%10;
            if (ht[hkey].phoneNumber == phoneNumber)
            {
                ht[hkey]= Entry();
            }
        }
    }
     void display() {
        cout << "Index  " << "Name" << "    " << "Phone Number" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << "      " << ht[i].name << "    " << ht[i].phoneNumber << endl;
        }
    }
    void search(long long phoneNumber){
        int hkey = phoneNumber%size;    
        int comp = 1;
        int temp = hkey;
        while(ht[hkey].phoneNumber!=phoneNumber && ht[hkey].phoneNumber != -1)
        {
            comp++;
            if(hkey!=9)
                hkey++;
            else
                hkey=0;
            if (hkey == temp) {
                cout << "\nElement not found" << endl;
                return;
            }
        }
        if(ht[hkey].phoneNumber == phoneNumber){
            cout << "Name: " << ht[hkey].name << ", Phone Number: " << ht[hkey].phoneNumber << endl;
        }
        else
            {cout << "\nElement not found" << endl;}
        cout << "Number of comparisons required = " << comp << endl;
}
};