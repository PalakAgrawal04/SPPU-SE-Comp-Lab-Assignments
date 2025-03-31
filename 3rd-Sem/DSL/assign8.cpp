#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    bool likesVanilla;
    bool likesButterscotch;
    Student *next;
    Student(string n, bool lv, bool lb) : name(n), likesVanilla(lv),likesButterscotch(lb), next(nullptr) {}
};
class StudentList
{
public:
    Student *head;
    StudentList() : head(nullptr) {}
    ~StudentList()
    {
        while (head)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addStudent(string name, bool lv, bool lb)
    {
        Student *newStudent = new Student(name, lv, lb);
        newStudent->next = head;
        head = newStudent;
    }
    void studentsWhoLikeBoth()
    {
        cout << "Students who like both vanilla and butterscotch: ";
        Student *currentA = head;
        while (currentA)
        {
            if (currentA->likesVanilla && currentA->likesButterscotch)
            {
                cout << currentA->name << " ";
            }
            currentA = currentA->next;
        }
    }
    void studentsWhoLikeEither()
    {
        cout << "Students who like either vanilla or butterscotch: ";
        Student *currentA = head;
        while (currentA)
        {
            if (currentA->likesVanilla || currentA->likesButterscotch)
            {
                cout << currentA->name << " ";
            }
            currentA = currentA->next;
        }
    }
    void studentsWhoLikeEitherNotBoth()
    {
        cout << "Students who like either vanilla or butterscotch but not both : ";
                   Student *currentA = head;
        while (currentA)
        {
            if ((currentA->likesVanilla || currentA->likesButterscotch) && !(currentA->likesVanilla && currentA->likesButterscotch))
            {
                cout << currentA->name << " ";
            }
            currentA = currentA->next;
        }
    }
    void studentsWhoLikeNeither()
    {
        cout << "Students who like neither vanilla nor butterscotch: ";
        Student *currentA = head;
        while (currentA)
        {
            if (!currentA->likesVanilla && !currentA->likesButterscotch)
            {
                cout << currentA->name << " ";
            }
            currentA = currentA->next;
        }
    }
};
int main()
{
    StudentList setA;
    int numStudentsA;
    cout << "Enter the total number of students: ";
    cin >> numStudentsA;
    for (int i = 0; i < numStudentsA; i++)
    {
        string name;
        bool likesVanilla, likesButterscotch;
        cout << "Enter student " << i + 1 << " name: ";
        cin >> name;
        cout << "Does " << name << " like vanilla ice-cream? (1 for yes,0 for no): ";
        cin >> likesVanilla;
        cout << "Does " << name << " like butterscotch ice-cream? (1 for yes, 0 for no): ";
        cin >> likesButterscotch;
        setA.addStudent(name, likesVanilla, likesButterscotch);
    }
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Students who like both vanilla and butterscotch\n";
        cout << "2. Students who like either vanilla or butterscotch\n";
        cout << "3. Students who like either vanilla or butterscotch butnot both\n ";
        cout << "4. Students who like neither vanilla nor butterscotch\n ";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            setA.studentsWhoLikeBoth();
            break;
        case 2:
            setA.studentsWhoLikeEither();
            break;
        case 3:
            setA.studentsWhoLikeEitherNotBoth();
            break;
        case 4:
            setA.studentsWhoLikeNeither();
            break;
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);
    return 0;
}
