#include <bits/stdc++.h>
using namespace std;

void display(map<string, int> mp)
{
    if (mp.empty())
    {
        cout << "No Record yet." << endl;
        return;
    }

    for (auto ele : mp)
    {
        cout << ele.first << ": " << ele.second << endl;
    }
}

int main() 
{
    string state = "";
    long population = 0;
    map<string, int> mp;
    int ch;
    string temp_state = "";
    do
    {
        cout << "Menu : \n 1. To enter the state and its population \n 2.To print current record \n 3. To search Population " << endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the state name: ";
            cin >> state;
            cout << "Enter the population: ";
            cin >> population;
            if (mp.find(state) == mp.end())
            {
                mp[state] = population;
                cout << "Record Stored successfully." << endl;
            }
            else
                cout << "Record already present." << endl;
            break;

        case 2:
            cout << "* RECORD *" << endl;
            display(mp);
            break;

        case 3:
            cout << "Enter the desired state name: ";
            cin >> temp_state;
            if (mp.find(temp_state) != mp.end())
            {
                cout << "Population: " << mp[temp_state] << endl;
            }
            else
            {
                cout << "Not found." << endl;
            }
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (ch > 0 && ch < 4);
    return 0;
}
