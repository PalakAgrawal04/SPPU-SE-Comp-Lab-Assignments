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

class hashtable {
    Entry ht[10];
    int size = 10;

public:
    hashtable() {
        for (int i = 0; i < 10; i++) {
            ht[i] = Entry();
        }
    }

    void insertwithoutrep(string name, long long phoneNumber) {
        int hkey = int(phoneNumber % size);
        if (ht[hkey].phoneNumber == -1)
            ht[hkey] = Entry(name, phoneNumber);
        else {
            while (ht[hkey].phoneNumber != -1) {
                hkey = (hkey + 1) % size;
            }
            ht[hkey] = Entry(name, phoneNumber);
        }
    }

    void insertwithrep(string name, long long phoneNumber) {
        int hkey = int(phoneNumber % 10);
        if (ht[hkey].phoneNumber == -1)
            ht[hkey] = Entry(name, phoneNumber);
        else {
            if ((ht[hkey].phoneNumber % size) == hkey) {
                while (ht[hkey].phoneNumber != -1) {
                    hkey = (hkey + 1) % size;
                }
                ht[hkey] = Entry(name, phoneNumber);
            } else {
                Entry temp = ht[hkey];
                ht[hkey] = Entry(name, phoneNumber);
                while (ht[hkey].phoneNumber != -1) {
                    hkey = (hkey + 1) % size;
                }
                ht[hkey] = temp;
            }
        }
    }

    void deletewithrep(long long phoneNumber) {
        int hkey = int(phoneNumber % 10);
        if (ht[hkey].phoneNumber == phoneNumber) {
            ht[hkey] = Entry(); // mark as empty
            return;
        } else {
            while (ht[hkey].phoneNumber != phoneNumber && ht[hkey].phoneNumber != -1) {
                hkey = (hkey + 1) % size;
            }
            if (ht[hkey].phoneNumber == phoneNumber)
                ht[hkey] = Entry(); // mark as empty
        }
    }

    void display() {
        cout << "Index  " << "Name" << "    " << "Phone Number" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << "      " << ht[i].name << "    " << ht[i].phoneNumber << endl;
        }
    }

    void search(long long phoneNumber) {
        int comp = 1;
        int index = int(phoneNumber % 10);
        int temp = index;
        while (ht[index].phoneNumber != phoneNumber && ht[index].phoneNumber != -1) {
            comp++;
            if (index != 9) {
                index += 1;
            } else {
                index = 0;
            }
            if (index == temp) {
                cout << "\nElement not found" << endl;
                return;
            }
        }
        if (ht[index].phoneNumber == phoneNumber)
            cout << "Name: " << ht[index].name << ", Phone Number: " << ht[index].phoneNumber << endl;
        else
            cout << "\nElement not found" << endl;
        cout << "Number of comparisons required = " << comp << endl;
    }
};

int main() {
    hashtable h1, h2;
    int flag = 0;
    cout << "1. Insert with replacement" << endl;
    cout << "2. Insert without replacement" << endl;
    cout << "3. Delete with replacement" << endl;
    cout << "4. Comparisons " << endl;
    cout << "5. Exit" << endl;
    cout << "You are allowed to enter up to 10 values" << endl;
    int ch;
    while (ch != 5) {
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch) {
            case 1: {
                int x;
                long long y;
                string name;
                cout << "Enter no.of elements to insert:";
                cin >> x;
                for (int i = 0; i < x; i++) {
                    cout << "Name: ";
                    cin >> name;
                    cout << "Phone Number: ";
                    cin >> y;
                    h1.insertwithrep(name, y);
                }
                cout << "With Replacement" << endl;
                h1.display();
                cout << endl;
                flag = 0;
                break;
            }
            case 2: {
                int x;
                long long y;
                string name;
                cout << "Enter no.of elements to insert:";
                cin >> x;
                for (int i = 0; i < x; i++) {
                    cout << "Name: ";
                    cin >> name;
                    cout << "Phone Number: ";
                    cin >> y;
                    h2.insertwithoutrep(name, y);
                }
                cout << "Without Replacement" << endl;
                h2.display();
                cout << endl;
                flag = 1;
                break;
            }
            case 3: {
                long long x;
                cout << "Enter the phone number to delete with replacement: ";
                cin >> x;
                h1.deletewithrep(x);
                cout << "After Deletion With Replacement" << endl;
                h1.display();
                cout << endl;
                break;
            }
            case 4: {
                long long d;
                cout << "Enter phone number whose comparison is needed: ";
                cin >> d;
                if (flag == 0)
                    h1.search(d);
                else if (flag == 1)
                    h2.search(d);
                else
                    cout << "No. not inserted" << endl;
                break;
            }
            case 5:
                cout << "Program Terminated" << endl;
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}