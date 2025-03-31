#include <iostream>
using namespace std;

class Linkedlist
{
    struct List
    {
        int data;
        int column;
        List *next;
        List *prev;
        List()
        {
            data = 0;
            column = 0;
            next = NULL;
            prev = NULL;
        }
    };

public:
    List *head = NULL;
    List *travel = NULL;
    void append(int data, int column)
    {
        List *temp = new List;
        temp->data = data;
        temp->next = head;
        temp->column = column;
        if (head == NULL)
        {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            return;
        }
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
    }
    void Traversal()
    {
        List *temp = this->head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
};
class Show : public Linkedlist
{
public:
    Linkedlist list[11];
    void create()
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 7; j++)
            {
                list[i].append(0, j);
            }
        }
    }
    void available()
    {
        for (int i = 1; i < 11; i++)
        {
            list[i].Traversal();
            cout << endl;
        }
    }
    void booking(int cancel)
    {
        int tickets;
        int row;
        int column;
        cout << "Enter number of tickets : ";
        cin >> tickets;
        cout << "Enter row number : ";
        cin >> row;
        cout << "Enter column number : ";
        cin >> column;
        travel = list[row].head;
        while (travel->column != column)
        {
            travel = travel->next;
        }
        for (int i = 0; i < tickets; i++)
        {
            if (travel->data == 0 && cancel == 0)
                travel->data = 1;
            else if (travel->data == 1 && cancel == 1)
                travel->data = 0;
            else if (travel->data == 0 && cancel == 1)
            {
                cout << "These tickets are not booked yet" << endl;
                return;
            }
            else if (travel->data == 1 && cancel == 0)
            {
                cout << "These tickets are already booked" << endl;
                return;
            }
            travel = travel->next;
        }
    }
};
int main()
{
    Show s1;
    s1.create();
    int ch;
    do
    {
        cout << "***** Menu *****" << endl;
        cout << "1. Seats Available" << endl;
        cout << "2. Booking" << endl;
        cout << "3. Cancel Booking " << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your choice " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            s1.available();
            break;
        case 2:
            s1.booking(0);
            s1.available();
            break;
        case 3:
            s1.booking(1);
            s1.available();
            break;
        case 4:
            exit(0);
        default:
            cout << "wrong input" << endl;
        }
    } while (ch < 5);
}