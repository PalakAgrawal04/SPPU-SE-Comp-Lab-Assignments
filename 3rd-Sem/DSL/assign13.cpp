#include<bits/stdc++.h>
using namespace std; 

class dequeue
{
    static const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int f,r;
    public:
    dequeue()
    {
        f = -1;
        r = -1;
    }

    void enqueFront(int val)
    {
        if((f == 0 && r == MAX_SIZE-1) || (f == r+1))
        {
            cout<<"Deque Full"<<endl;
        }
        else
        {
            if(f == -1)
                f = r = 0;
            else if(f == 0)
                f = MAX_SIZE - 1;
            else
                f-- ;
            arr[f] = val;
            cout<<"Enque at front successfull"<<endl;
        }
    }

    void enqueRear(int val)
    {
        if((f == 0 && r == MAX_SIZE-1) || (f == r+1))
        {
            cout<<"Deque Full"<<endl;
        }
        else
        {
            if(f == -1)
                f = r = 0;
            else if(r == MAX_SIZE-1 )
                r = 0;
            else
                r++ ;
            arr[r] = val;
            cout<<"Enque at rear successfull"<<endl;
        }
    }

    void dequeFront()
    {
        if(f == -1)
        {
            cout<<"Deque Empty"<<endl;
        }
        else
        {
            cout<<"Deque from Front :"<<arr[f]<<endl;
            if(f == r)
                f = r = -1;
            else if(f == MAX_SIZE-1 )
                f = 0;
            else
                f++ ;
        }
    }

    void dequeRear()
    {
        if(f == -1)
        {
            cout<<"Deque Empty"<<endl;
        }
        else
        {
            cout<<"Deque from Rear :"<<arr[r]<<endl;
            if(f == r)
                f = r = -1;
            else if(r == 0)
                r = MAX_SIZE-1;
            else
                r-- ;
        }
    }

    void display()
    {
        if(f == -1)
            cout<<"Deque is empty"<<endl;
        else
        {
            cout<<"Deque elements : ";
            int i = f;
            do{
                cout<<arr[i]<<" ";
                if(i == r)
                    break;
                i = (i+1)%MAX_SIZE;
            }while (i != f);
            cout<<endl;
        }
    }
};

int main()
{
    dequeue dq;
    int ch,ele;
    cout<<"Menu: \n 1.enqueFront \n 2.enqueRear \n 3.dequeFront \n 4.dequeRear"<<endl;
    do
    {
    cout<<"Enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
            cout<<"Enter element :"<<endl;
            cin>>ele;
            dq.enqueFront(ele);
            break;
        case 2:
            cout<<"Enter element :"<<endl;
            cin>>ele;
            dq.enqueRear(ele);
            break;
        case 3:
            dq.dequeFront();
            break;
        case 4:
            dq.dequeRear();
            break;
        default:
            break;
    }
    }while(ch < 5 && ch>0);
    dq.display();
    return 0;
}