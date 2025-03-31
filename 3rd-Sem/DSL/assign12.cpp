#include <iostream>
using namespace std;

template<class T>
class Priority
{
private:
    T data;
    int priority;
    Priority<T> *next;

public:
    Priority(T d, int priority)
    {
        this->data = d;
        this->priority = priority;
        next = NULL;
    }
    //Most Important Line Here Okay Boyy
    template <typename U>
    friend class PrioOp;

    friend operator <=(const Priority<T> &obj1,const Priority<T> &obj2)
    {
        return obj1.priority <= obj2.priority;
    }


    
};

template<class T>
class PrioOp
{
private:
    Priority<T> *head;

public:
    PrioOp()
    {
        head = NULL;
    }

    void addJob(T data, int priority)
    {
        //This also Important
        Priority <T> *temp = new Priority<T>(data, priority);

        // Checking if head is Not Null ((OR)) priority of New Node is less than Existing Priority
        // This condition works for only first Node
        if (!head || *(temp) <= *(head))
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            Priority <T> *start = head;
            while (start->next != NULL && *(start->next) <= *(temp))
            {
                start = start->next;
            }

            temp->next = start->next;
            start->next = temp;
        }
    }

    void displayJob()
    {
        Priority <T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "------>" << temp->priority << " " << endl;
            temp = temp->next;
        }
    }

    void deleteJob()
    {
        if (head == nullptr) {
            throw runtime_error("Priority queue is empty");
        }

        Priority<T>* temp = head;
        head = head->next;
        T data = temp->data;
        delete temp;

        cout<<data<<" deleted."<<endl;
    }
    
};

int main()
{
    PrioOp<int> obj;
    int ch, ch1;
    int data, priority;

    do
    {
        cout << "1-Add Job " << endl;
        cout << "2-Display Job " << endl;
        cout << "3-Delete Job " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the Data you want to Insert " << endl;
            cin >> data;

            cout << "Enter the priority you want to Insert " << endl;
            cin >> priority;
            obj.addJob(data, priority);
            break;

        case 2:
            obj.displayJob();
            break;

        case 3:
            obj.deleteJob();
            break;

        default:                                                                                                                    
            cout << "Enter a Valid Choice " << endl;
            break;
        }
        cout << "Do you want to continue,PRess 1 " << endl;
        cin >> ch1;
    } while (ch1 == 1);

    return 0;
}