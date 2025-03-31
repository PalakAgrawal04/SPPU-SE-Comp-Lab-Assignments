#include<iostream>
using namespace std;
#define size 10
int n;

template<class T>
void selectionSort(T A[size])
{
    int min;
    T temp;
    for(int i = 0;i<n-1;i++)
    {
        min = i;
        for(int j = i+1;j<n;j++)
        {
            if(A[j]<A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout<<"\nSorted Array : ";
    for(int i = 0;i<n;i++)
        cout<<A[i]<<" ";
}
template<class T>
void insertionSort(T A[size])
{
    int i, j;
    T key;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
    cout<<"\nSorted Array : ";
    for(int i = 0;i<n;i++)
        cout<<A[i]<<" ";
}

int main()
{
    int A[size];
    float B[size];
    int ch;
    cout<<"Enter Your Choice :"<<endl;
    cout<<"1.Int array "<<endl;
    cout<<"2.Float array "<<endl;
    cout<<"3.Exit "<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
            cout<<"Enter total no. of int elements: ";
            cin>>n;
            cout<<"Enter int elements : "<<endl;
            for(int i = 0;i<n;i++)
                cin>>A[i];
            selectionSort(A);
            break;
        case 2:
            cout<<"Enter total no. of float elements: ";
            cin>>n;
            cout<<"Enter float elements : "<<endl;
            for(int i = 0;i<n;i++)
                cin>>B[i];
            insertionSort(B);
            break;
        case 3:
            break;
    }
    return 0;

}