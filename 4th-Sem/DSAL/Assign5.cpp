#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;   
    string value;
    Node* next=NULL;
    Node(int k,string data)
    {
        key=k;
        value=data;
        next=NULL;
    }
};

class HashMap
{
public:
    Node* a[10];
    
    HashMap()
    {
        for(int i=0;i<10;i++) a[i]=NULL;
    }

    void insert(int k, string data)
    {
        int k1=(3*k+5)%10;
        Node*temp=a[k1];   
        if(a[k1]==NULL)
        {
            a[k1]=new Node(k,data);
            return;
        }
        while(temp->next!=NULL) 
        temp=temp->next;
        temp->next=new Node(k,data);
    }

    void deleteKey(int key )
    {
        int k=(3*key+5)%10;
        Node* temp=a[k];
        if(temp->key==key)
        {
            a[k]=temp->next;
            delete temp;
            return;
        }
        while(temp->next->key!=key) temp=temp->next;
        Node* delNode=temp->next;
        temp->next=temp->next->next;
        delete delNode;
    }

    void search(int key)
    {
        int k=(3*key+5)%10;
        Node* temp=a[k];
        while(temp!=NULL && temp->key!=key) temp=temp->next;
        if(temp==NULL)  cout<<"Key not present in the Hash Map"<<endl;
        else  cout<<temp->key<<"->"<<temp->value<<endl;
    }

    void print()
    {
        for(int i=0;i<10;i++)
        {
            Node* temp=a[i];
            cout<<i<<"->"<<"  ";
            while(temp!=NULL)
            {
                cout<<temp->key<<"  "<<temp->value<<"  "<<"-->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    
};

int main()
{
 HashMap obj;
int ch,k;
string val;
 
 do{
    cout<<"1.Insert\n2.Delete\n3.Find\n4.Display"<<endl;
 cin>>ch;
    switch(ch){
        case 1:
        cout<<"enter key"<<endl;
        cin>>k;
        cout<<"enter value"<<endl;
        cin>>val;
        obj.insert(k,val);
        break;
        case 2:
        cout<<"enter key"<<endl;
        cin>>k;
        obj.deleteKey(k);
        obj.print();
        break;
        case 3:
        cout<<"enter key"<<endl;
        cin>>k;
        obj.search(k);
        break;
        case 4:
        obj.print();
        break;
        case 0:
        break;
        default:
        break;
    }
 }while(ch != 0);
 return 0;
}